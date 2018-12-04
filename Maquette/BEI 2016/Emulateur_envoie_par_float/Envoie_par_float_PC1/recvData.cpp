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
	int nbytes, i_recv, dlc_recv;
	int opt_recv, optdaemon = 0;
	uint32_t id_recv, mask;
	
	short appRetVal_recv;
        int appWRetVal_recv;
        char appDeviceName_recv[15]="/dev/canA" ,filename[32];     
//        char appDeviceName_recv[15],filename[32];
        int appDevHandle_recv;
        unsigned long data[10];
	int fileflag = 0;
        FILE *RX;

	unsigned long fcount_recv = 1;

        struct can_frame *frame_recv;

//        sprintf(appDeviceName_recv,"/dev/%s",argv[1]);





//float *recvData(string Filename) {
float *recvData(string filename_input){
	
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
	//optout_recv=filename_input;
	if (1==1) {
		fileflag = 1;
        	sprintf(filename, "%s", filename_input.c_str());
		RX = fopen(filename, "w");
		if (!RX) {
			perror("fopen	");
			exit (EXIT_FAILURE);
		} else {
                	fclose(RX);
		}
	}

	appDevHandle_recv = open(appDeviceName_recv , O_RDWR);
        if(appDevHandle_recv < 0) {
       	        printf("Device Open Error (%s)\n", appDeviceName_recv, appDevHandle_recv);
		exit (0);
        } else {
        	printf("Device Opened (%s)\n", appDeviceName_recv, appDevHandle_recv);
									
		if(fileflag)
		{
			while (running) {
				appWRetVal_recv = ioctl(appDevHandle_recv, SJA1000_IOCRECV, (unsigned long) data);
                        	if(appWRetVal_recv != 0)
                        	{
					if(data[1] == 0x9) {
						printf("%ld Files Received\n", fcount_recv++);
						//sprintf(filename, "%ld%s", fcount_recv, filename_input.c_str());
						RX = fopen(filename, "w");
						if (!RX) {
							perror("fopen	");
							exit (EXIT_FAILURE);
						} else {
				                	fclose(RX);
						//	running=0;
						}
					} else {
					
						RX = fopen(filename, "a");
						if (!RX) {
							perror("fopen	");
							exit (EXIT_FAILURE);
						} else {
							i_recv=1;
							dlc_recv = data[i_recv++];
							while(i_recv <= dlc_recv + 1) {
								fputc(data[i_recv++],RX);
							}
						}
                				fclose(RX);
						running=0;
					}
				}
			}
		} else {
			while (running) {
		              	appWRetVal_recv = ioctl(appDevHandle_recv, SJA1000_IOCRECV, (unsigned long) data);
				if(appWRetVal_recv != 0)
				{
					i_recv=0;
					if (data[i_recv] & CAN_EFF_FLAG)
						printf("<0x%08x> ", data[i_recv++] & CAN_EFF_MASK);
					else
						printf("<0x%03x> ", data[i_recv++] & CAN_SFF_MASK);
					dlc_recv = data[i_recv++];
					printf("[%d] ", dlc_recv);
					while(i_recv <= dlc_recv + 1) {
						printf("%02x ", data[i_recv++]);
					}
					if (data[0] & CAN_RTR_FLAG)
						printf("remote request");
					printf("\n");
				}
			}
		}
		
	}

        appRetVal_recv = close(appDevHandle_recv);
        if(appRetVal_recv == 0) {
                printf("Device Closed\n", appRetVal_recv);
        } else {
                printf("Device Close Error - %d\n", appRetVal_recv);
        }

//	exit (EXIT_SUCCESS);

	return 0;
}
