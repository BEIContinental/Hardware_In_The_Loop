/*************************************************
****************  changeBitrate   ****************
*************************************************/

#include "changeBitrate.h"
#include <stdio.h>

#include <getopt.h>
#include <fcntl.h>

#include "can.h"
#include "sja1000_ioctl.h"

#define do_div(a,b) a = (a) / (b)

static void print_usage(char* cmd)
{
       printf("Usage: %s [options] [<CAN-Device-Name>]\n"
              "\tOptions:\n"
              "\t-b <bitrate> : bit-rate in bits/sec\n"
              "\t-s <samp_pt> : sample-point in one-tenth of a percent\n"
              "\t               or 0 for CIA recommended sample points\n"
              "\t-c <clock>   : real CAN system clock in Hz\n"
              "\t-h           : help\n",
              cmd);

       exit(1);
}

uint8_t btr0, btr1;

struct can_bittime {
       uint32_t brp;
       uint8_t prop_seg;
       uint8_t phase_seg1;
       uint8_t phase_seg2;
       uint8_t sjw;
       uint32_t tq;
       uint32_t error;
       int sampl_pt;
};

struct can_bittiming_const {
       char name[32];
       int prop_seg_min;
       int prop_seg_max;
       int tseg1_min;
       int tseg1_max;
       int tseg2_min;
       int tseg2_max;
       int sjw_max;
       int brp_min;
       int brp_max;
       int brp_inc;
       void (*printf_btr)(struct can_bittime *bt, int hdr);
};

static void printf_btr_sja1000(struct can_bittime *bt, int hdr)
{
       if (hdr) {
               printf("BTR0 BTR1");
       } else {
               btr0 = ((bt->brp - 1) & 0x3f) | (((bt->sjw - 1) & 0x3) << 6);
               btr1 = ((bt->prop_seg + bt->phase_seg1 - 1) & 0xf) |
                       (((bt->phase_seg2 - 1) & 0x7) << 4);
               printf("0x%02x 0x%02x", btr0, btr1);
       }
}

struct can_bittiming_const can_calc_consts[] = {
       {
               "sja1000",
               /* Note: only prop_seg + bt->phase_seg1 matters */
               .tseg1_min = 1,
               .tseg1_max = 16,
               .tseg2_min = 1,
               .tseg2_max = 8,
               .sjw_max = 4,
               .brp_min = 1,
               .brp_max = 64,
               .brp_inc = 1,
               .printf_btr = printf_btr_sja1000,
       },
};

static long common_bitrates[] = {1000000};

char can_devices[2][10] = {"/dev/canA","/dev/canB"};

#define CAN_CALC_MAX_ERROR 50 /* in one-tenth of a percent */

static int can_update_spt(const struct can_bittiming_const *btc,
			  int sampl_pt, int tseg, int *tseg1, int *tseg2)
{
	*tseg2 = tseg + 1 - (sampl_pt * (tseg + 1)) / 1000;
	if (*tseg2 < btc->tseg2_min)
		*tseg2 = btc->tseg2_min;
	if (*tseg2 > btc->tseg2_max)
		*tseg2 = btc->tseg2_max;
	*tseg1 = tseg - *tseg2;
	if (*tseg1 > btc->tseg1_max) {
		*tseg1 = btc->tseg1_max;
		*tseg2 = tseg - *tseg1;
	}
	return 1000 * (tseg + 1 - *tseg2) / (tseg + 1);
}

int can_calc_bittiming(struct can_bittime *bt, long bitrate, int sampl_pt, long clock, const struct can_bittiming_const *btc)
{
	long rate, best_rate = 0;
	long best_error = 1000000000, error = 0;
	int best_tseg = 0, best_brp = 0, brp = 0;
	int tsegall, tseg = 0, tseg1 = 0, tseg2 = 0;
	int spt_error = 1000, spt = 0;
	uint64_t v64;

	if (sampl_pt ==0 )
	{
		if (bitrate > 800000)
			sampl_pt = 750;
		else if (bitrate > 500000)
			sampl_pt = 800;
		else
			sampl_pt = 875;
	}

	/* tseg even = round down, odd = round up */
	for (tseg = (btc->tseg1_max + btc->tseg2_max) * 2 + 1;
	     tseg >= (btc->tseg1_min + btc->tseg2_min) * 2; tseg--) {
		tsegall = 1 + tseg / 2;
		/* Compute all possible tseg choices (tseg=tseg1+tseg2) */
		brp = clock / (tsegall * bitrate) + tseg % 2;
		/* chose brp step which is possible in system */
		brp = (brp / btc->brp_inc) * btc->brp_inc;
		if ((brp < btc->brp_min) || (brp > btc->brp_max))
			continue;
		rate = clock / (brp * tsegall);
		error = bitrate - rate;
		/* tseg brp biterror */
		if (error < 0)
			error = -error;
		if (error > best_error)
			continue;
		best_error = error;
		if (error == 0) {
			spt = can_update_spt(btc, sampl_pt, tseg / 2,
					     &tseg1, &tseg2);
			error = sampl_pt - spt;
			if (error < 0)
				error = -error;
			if (error > spt_error)
				continue;
			spt_error = error;
		}
		best_tseg = tseg / 2;
		best_brp = brp;
		best_rate = rate;
		if (error == 0)
			break;
	}

	if (best_error) {
		/* Error in one-tenth of a percent */
		error = (best_error * 1000) / bitrate;
		if (error > CAN_CALC_MAX_ERROR) {
			printf("bitrate error %ld.%ld%% too high\n", error / 10, error % 10);
			return -1;
		} else {
			printf("bitrate error %ld.%ld%%\n", error / 10, error % 10);
		}
	}

	/* real sample point */
	bt->sampl_pt = can_update_spt(btc, sampl_pt, best_tseg,
					  &tseg1, &tseg2);

	v64 = (uint64_t)best_brp * 1000000000UL;
	do_div(v64, clock);
	bt->tq = (int)v64;
	bt->prop_seg = tseg1 / 2;
	bt->phase_seg1 = tseg1 - bt->prop_seg;
	bt->phase_seg2 = tseg2;
	bt->sjw = 1;
	bt->brp = best_brp;
	/* real bit-rate */
	bitrate = clock / (bt->brp * (tseg1 + tseg2 + 1));

	return 0;
}

int print_bit_timing(const struct can_bittiming_const *btc,
                     long bitrate, int sampl_pt, long ref_clk, int quiet)
{
       struct can_bittime bt;

       memset(&bt, 0, sizeof(bt));

       if (!quiet) {
               printf("Bit timing parameters for %s using %ldHz\n",
                      btc->name, ref_clk);
               printf("Bitrate TQ[ns] PrS PhS1 PhS2 SJW BRP SampP Error ");
               btc->printf_btr(&bt, 1);
               printf("\n");
       }

       if (can_calc_bittiming(&bt, bitrate, sampl_pt, ref_clk, btc)) {
               printf("%7ld ***bitrate not possible***\n", bitrate);
               return -1;
       }

       printf("%7ld %6d %3d %4d %4d %3d %3d %2d.%d%% %4.1f%% ",
              bitrate, bt.tq, bt.prop_seg, bt.phase_seg1,
              bt.phase_seg2, bt.sjw, bt.brp,
              bt.sampl_pt / 10, bt.sampl_pt % 10,
              (double)100 * bt.error / bitrate);
       btc->printf_btr(&bt, 0);
       printf("\n");
       return 0;
}

int changeBitrate(int argc, char *argv[])
{
	long bitrate = 0;
	long ref_clk = 8000000;
	int sampl_pt = 0;
	const struct can_bittiming_const *btc = NULL;
	struct can_btr btr;
        short appRetVal, appWRetVal;
        char *appDeviceName = NULL,name[15];
        int appDevHandle;
	int i, opt, ret = 0;
	
	
	 while ((opt = getopt(argc, argv, "b:c:hps:")) != -1) {
               switch (opt) {
               case 'b':
                       bitrate = atoi(optarg);
                       break;

               case 'c':
                       ref_clk = atoi(optarg);
                       break;

               case 's':
                       sampl_pt = atoi(optarg);
                       break;
	       case 'h':
		       print_usage(argv[0]);
		       break;
               default:
                       print_usage(argv[0]);
                       break;
               }
       }

       if (argc > optind + 1)
               print_usage(argv[0]);

       if (argc == optind + 1)
               appDeviceName = argv[optind];

	if (sampl_pt && (sampl_pt >= 1000 || sampl_pt < 100))
               print_usage(argv[0]);

        btc = &can_calc_consts[0];

	if (bitrate) {
		ret = print_bit_timing(btc, bitrate, sampl_pt, ref_clk, 0);
	} else {
		ret = print_bit_timing(btc, common_bitrates[0], sampl_pt, ref_clk, 0);
	}

	if(ret != -1) {
		btr.BTR0 = btr0;
	        btr.BTR1 = btr1;

		if (appDeviceName) {
			sprintf(name,"/dev/%s",appDeviceName);
	        	appDevHandle = open(name , O_RDWR);
	        	if(appDevHandle < 0) {
        	        	printf("Device Open Error (%s) Opening (%d)\n", name, appDevHandle);
	        	} else {
	        	        printf("Device Opened (%s)\n", name, appDevHandle);
                		appWRetVal = ioctl(appDevHandle, SJA1000_IOCBTR, (unsigned long)&btr);
		        }
        		appRetVal = close(appDevHandle);
		        if(appRetVal == 0) {
        		        printf("Device Closed\n", appRetVal);
	        	} else {
        	        	printf("Device Close Error - %d\n", appRetVal);
		        }
		} else {
			for(i = 0; i < 2; i++) {

			        appDevHandle = open(can_devices[i] , O_RDWR);
        			if(appDevHandle < 0) {
                			printf("Device Open Error (%s) Opening (%d)\n", can_devices[i], appDevHandle);
			        } else {
        			        printf("Device Opened (%s)\n", can_devices[i], appDevHandle);
                			appWRetVal = ioctl(appDevHandle, SJA1000_IOCBTR, (unsigned long)&btr);
		        	}
	        		appRetVal = close(appDevHandle);
		        	if(appRetVal == 0) {
                			printf("Device Closed\n", appRetVal);
	        		} else {
		                	printf("Device Close Error - %d\n", appRetVal);
	        		}
			}
		}
	}

	return 0;
}
