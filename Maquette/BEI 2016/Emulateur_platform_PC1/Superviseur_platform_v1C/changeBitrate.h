#ifndef CHANGE_BITRATE
#define CHANGE_BITRATE

#include "changeBitrate.h"
#include <stdio.h>

#include <getopt.h>
#include <fcntl.h>

#include "can.h"
#include "sja1000_ioctl.h"

static void print_usage(char* cmd);

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

static void printf_btr_sja1000(struct can_bittime *bt, int hdr);

static int can_update_spt(const struct can_bittiming_const *btc,
			  int sampl_pt, int tseg, int *tseg1, int *tseg2);

int can_calc_bittiming(struct can_bittime *bt, long bitrate, int sampl_pt, long clock, const struct can_bittiming_const *btc);

int print_bit_timing(const struct can_bittiming_const *btc, long bitrate, int sampl_pt, long ref_clk, int quiet);
int changeBitrate(int argc, char *argv[]);

#endif
