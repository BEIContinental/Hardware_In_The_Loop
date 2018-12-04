
// SJA1000 Application for receiving CAN Frames

#include <errno.h>
#include <getopt.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <fcntl.h>


#include "can.h"
#include "sja1000_ioctl.h"

#include <sys/uio.h>

extern int optind, opterr, optopt;

static int	s = -1;
static int	running = 1;

enum {
	VERSION_OPTION = CHAR_MAX + 1,
	FILTER_OPTION,
};

static void print_usage(char *prg)
{
        fprintf(stderr, "Usage: %s [<can-interface>] [Options]\n"
		"Options:\n"
		" -o <filename>\t\t"    "Output filename\n"
		" -h, --help\t\t"		"this help\n",
		prg);
}

static void sigterm(int signo)
{
	running = 0;
}

#define BUF_SIZ	(255)

int main(int argc, char **argv)
{
	FILE *out = stdout;
	char *optout = NULL;
	char *ptr;
	char buf[BUF_SIZ];
	int n = 0, err;
	int nbytes, i, dlc;
	int opt, optdaemon = 0;
	uint32_t id, mask;
	
	short appRetVal;
        int appWRetVal;
        char appDeviceName[15],filename[32];
        int appDevHandle;
        unsigned long data[10];
	int fileflag = 0;
        FILE *RX;
	unsigned long fcount = 1;

        struct can_frame *frame;

        sprintf(appDeviceName,"/dev/%s",argv[1]);

	
	signal(SIGPIPE, SIG_IGN);

	struct option		long_options[] = {
		{ "help", no_argument, 0, 'h' },
		{ 0, 0, 0, 0},
	};

	while ((opt = getopt_long(argc, argv, "f:t:p:o:d", long_options, NULL)) != -1) {
		switch (opt) {
		case 'd':
			optdaemon++;
			break;

		case 'h':
			print_usage(basename(argv[0]));
			exit(0);

		case 'o':
			optout = optarg;
			break;

		default:
			fprintf(stderr, "Unknown option %c\n", opt);
			break;
		}
	}

	if (optdaemon)
		daemon(1, 0);
	else {
		signal(SIGTERM, sigterm);
		signal(SIGHUP, sigterm);
	}

	if (optout) {
		fileflag = 1;
        	sprintf(filename, "%ld%s", fcount, optout);
		RX = fopen(filename, "w");
		if (!RX) {
			perror("fopen	");
			exit (EXIT_FAILURE);
		} else {
                	fclose(RX);
		}
	}

	appDevHandle = open(appDeviceName , O_RDWR);
        if(appDevHandle < 0) {
       	        printf("Device Open Error (%s)\n", appDeviceName, appDevHandle);
		exit (0);
        } else {
        	printf("Device Opened (%s)\n", appDeviceName, appDevHandle);
									
		if(fileflag)
		{
			while (running) {
				appWRetVal = ioctl(appDevHandle, SJA1000_IOCRECV, (unsigned long) data);
                        	if(appWRetVal != 0)
                        	{
					if(data[1] == 0x9) {
						printf("%ld Files Received\n", fcount++);
						sprintf(filename, "%ld%s", fcount, optout);
						RX = fopen(filename, "w");
						if (!RX) {
							perror("fopen	");
							exit (EXIT_FAILURE);
						} else {
				                	fclose(RX);
						}
					} else {
					
						RX = fopen(filename, "a");
						if (!RX) {
							perror("fopen	");
							exit (EXIT_FAILURE);
						} else {
							i=1;
							dlc = data[i++];
							while(i <= dlc + 1) {
								fputc(data[i++],RX);
							}
						}
                				fclose(RX);
					}
				}
			}
		} else {
			while (running) {
		              	appWRetVal = ioctl(appDevHandle, SJA1000_IOCRECV, (unsigned long) data);
				if(appWRetVal != 0)
				{
					i=0;
					if (data[i] & CAN_EFF_FLAG)
						printf("<0x%08x> ", data[i++] & CAN_EFF_MASK);
					else
						printf("<0x%03x> ", data[i++] & CAN_SFF_MASK);
					dlc = data[i++];
					printf("[%d] ", dlc);
					while(i <= dlc + 1) {
						printf("%02x ", data[i++]);
					}
					if (data[0] & CAN_RTR_FLAG)
						printf("remote request");
					printf("\n");
				}
			}
		}
		
	}

        appRetVal = close(appDevHandle);
        if(appRetVal == 0) {
                printf("Device Closed\n", appRetVal);
        } else {
                printf("Device Close Error - %d\n", appRetVal);
        }

	exit (EXIT_SUCCESS);
}
