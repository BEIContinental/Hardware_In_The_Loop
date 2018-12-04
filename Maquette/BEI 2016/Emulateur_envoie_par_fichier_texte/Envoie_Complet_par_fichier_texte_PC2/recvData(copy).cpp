#include "recvData.h"
#include <string>
using namespace std;

extern int optind, opterr, optopt;

static int	s = -1;
static int	running = 1;
/*/
enum {
	VERSION_OPTION = CHAR_MAX + 1,
	FILTER_OPTION,
};
/*/
static void sigterm(int signo) {
	running = 0;
}

#define BUF_SIZ	(255)



	FILE *out = stdout;
	char *optout_recv = NULL;
	char *ptr;
	char buf[BUF_SIZ];
	int n = 0, err;
	int nbytes, i_recv, dlc;
	int opt, optdaemon = 0;
	uint32_t id, mask;
	
	short appRetVal;
        int appWRetVal;
        char appDeviceName[15]="/dev/canA" ,filename[32];     
//        char appDeviceName[15],filename[32];
        int appDevHandle;
        unsigned long data[10];
	int fileflag = 0;
        FILE *RX;

	unsigned long fcount = 1;

        struct can_frame *frame;

//        sprintf(appDeviceName,"/dev/%s",argv[1]);





float *recvData(string Filename) {

	
	signal(SIGPIPE, SIG_IGN);

	struct option		long_options[] = {
		{ "help", no_argument, 0, 'h' },
		{ 0, 0, 0, 0},
	};

	if (optdaemon)
		daemon(1, 0);
	else {
		signal(SIGTERM, sigterm);
		signal(SIGHUP, sigterm);
	}
	
	//if (optout_recv) {
	optout_recv=optarg;
	if (optout_recv==optarg) {
		fileflag = 1;
        	sprintf(filename, "%ld%s", fcount, optout_recv);
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
						sprintf(filename, "%ld%s", fcount, optout_recv);
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
							i_recv=1;
							dlc = data[i_recv++];
							while(i_recv <= dlc + 1) {
								fputc(data[i_recv++],RX);
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
					i_recv=0;
					if (data[i_recv] & CAN_EFF_FLAG)
						printf("<0x%08x> ", data[i_recv++] & CAN_EFF_MASK);
					else
						printf("<0x%03x> ", data[i_recv++] & CAN_SFF_MASK);
					dlc = data[i_recv++];
					printf("[%d] ", dlc);
					while(i_recv <= dlc + 1) {
						printf("%02x ", data[i_recv++]);
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

	return 0;
}



