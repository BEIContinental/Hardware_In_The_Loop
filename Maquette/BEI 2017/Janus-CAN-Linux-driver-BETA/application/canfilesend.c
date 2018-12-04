
// SJA1000 CAN Application for sending CAN Frames

#include <getopt.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include <sys/uio.h>

#include <fcntl.h>

#include "can.h"
#include "sja1000_ioctl.h"


extern int optind, opterr, optopt;

static void print_usage(char *prg)
{
	fprintf(stderr,
		"Usage: %s [<can-interface>] [Options] <can-msg>\n"
		"<can-msg> can consist of up to 8 bytes given as a space separated list\n"
		"Options:\n"
		" -i, --identifier=ID	CAN Identifier (default = 1)\n"
		" -r  --rtr		send remote request\n"
		" -e  --extended	send extended frame\n"
		" -l			send message infinite times\n"
		"     --loop=COUNT	send message COUNT times\n"
		" -p  --pattern		send message data in incremental pattern\n"
		" -o <filename>\t\t"    "Input filename\n"
		" -v, --verbose		be verbose\n"
		" -h, --help		this help\n",
		prg);
}

int main(int argc, char **argv)
{
	struct can_frame frame = {
		.can_id = 1,
	};
	int loopcount = 1, infinite = 0;
	int s, opt, ret, i, dlc = 0, rtr = 0, extended = 0;
	int verbose = 0,pattern = 0;

	short appRetVal, appWRetVal;
        char appDeviceName[15];
	char *optout = NULL;
	FILE *TX;
        int appDevHandle;
	char ch;
	int count = 0, id = 1;
	unsigned long fcount = 1;

	struct option long_options[] = {
		{ "help",	no_argument,		0, 'h' },
		{ "identifier",	required_argument,	0, 'i' },
		{ "rtr",	no_argument,		0, 'r' },
		{ "extended",	no_argument,		0, 'e' },
		{ "pattern",	no_argument,		0, 'p'},
		{ "verbose",	no_argument,		0, 'v'},
		{ "loop",	required_argument,	0, 'l'},
		{ 0,		0,			0, 0 },
	};

	sprintf(appDeviceName,"/dev/%s",argv[1]);
	while ((opt = getopt_long(argc, argv, "hf:t:p:vio:lre", long_options, NULL)) != -1) {
		switch (opt) {
		case 'h':
			print_usage(basename(argv[0]));
			exit(0);

		case 'v':
			verbose = 1;
			break;

		case 'l':
			if (optarg)
				loopcount = strtoul(optarg, NULL, 0);
			else
				infinite = 1;
			break;
		case 'i':
			frame.can_id = strtoul(optarg, NULL, 0);
			break;

		case 'r':
			rtr = 1;
			break;

		case 'p':
			pattern = 1;
			break;

		case 'e':
			extended = 1;
			break;
		
		case 'o':
                        optout = optarg;
                        break;

		default:
			fprintf(stderr, "Unknown option %c\n", opt);
			break;
		}
	}

	if (optind == argc) {
		print_usage(basename(argv[0]));
		exit(0);
	}

	
	if (optout) {
        }
	else {
		for (i = optind + 1; i < argc; i++) {
		frame.data[dlc] = strtoul(argv[i], NULL, 0);
		dlc++;
		if (dlc == 8)
			break;
		}
		frame.can_dlc = dlc;

		if (extended) {
			frame.can_id &= CAN_EFF_MASK;
			frame.can_id |= CAN_EFF_FLAG;
		} else {
			frame.can_id &= CAN_SFF_MASK;
		}

		if (rtr)
			frame.can_id |= CAN_RTR_FLAG;
	}

	if (verbose) {
		printf("id: %d ", frame.can_id);
		printf("dlc: %d\n", frame.can_dlc);
		for (i = 0; i < frame.can_dlc; i++)
			printf("0x%02x ", frame.data[i]);
		printf("\n");
	}


        appDevHandle = open(appDeviceName , O_RDWR);
        if(appDevHandle < 0) {
                printf("Device Open Error (%s)\n", appDeviceName, appDevHandle);
		exit(0);
        } else {
                printf("Device Opened (%s)\n", appDeviceName, appDevHandle);
		if (optout) {
			while (infinite || loopcount--) {
				TX = fopen(optout, "r");
        	        	if (!TX) {
                	        	perror("fopen");
	                	        exit (EXIT_FAILURE);
	        	        } else {
					while ((ch = fgetc(TX)) != EOF) {
		        		        frame.data[count++] = ch;
	                			if(count == 8) {
							frame.can_id = id++;
							frame.can_dlc = count;
        		        	       	appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
	        	        		count = 0;
			        	        }
						usleep(2000);
	        			}
				        if(count != 0)
        				{
						frame.can_id = id++;
        	                        	frame.can_dlc = count;
		                		appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
	        	        		count = 0;
       					}		
					usleep(2000);
					printf("%ld File Transmited\n",fcount++);
					frame.can_id = 0x0;
	                               	frame.can_dlc = 0x9;
					for (i = 0; i < 8; i++) {
					frame.data[i] = 0x0;
					}
	                		appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
		
				}
				fclose(TX);
			}
		} else {
			while (infinite || loopcount--) {
				if(pattern) {
					for (i = 0; i < frame.can_dlc; i++)
						frame.data[i] = frame.data[i] + 1;
	                		appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
				} else {
                			appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
				}
				if (frame.can_id & CAN_EFF_FLAG)
					printf("<0x%08x> ", frame.can_id & CAN_EFF_MASK);
				else
					printf("<0x%03x> ", frame.can_id & CAN_SFF_MASK);
				dlc = frame.can_dlc;
				printf("[%d] ", dlc);
				for (i = 0; i < frame.can_dlc; i++) {
					printf("%02x ", frame.data[i]);
				}
				if (frame.can_id & CAN_RTR_FLAG)
					printf("remote request");
				printf("\n");
				usleep(2000);
			}
		}
	}
        appRetVal = close(appDevHandle);
        if(appRetVal == 0) {
                printf("Device Closed\n", appRetVal);
        } else {
                printf("Device Close Error\n", appRetVal);
        }

	return 0;
}
