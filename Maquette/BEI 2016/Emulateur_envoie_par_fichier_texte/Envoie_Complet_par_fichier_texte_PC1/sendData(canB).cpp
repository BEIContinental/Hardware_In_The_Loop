/*/#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <getopt.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
/*/
//#include "can.h"
//#include "sja1000_ioctl.h"

#include "sendData.h"
#include <string.h>

using namespace std;

extern int optind, opterr, optopt;

	struct can_frame frame = {
		//can_id = 1,
	};
	int loopcount = 1, infinite = 0;
	int s, opt, ret, i, dlc = 0, rtr = 0, extended = 0;
	int verbose = 0,pattern = 0;

	short appRetVal, appWRetVal;
        //char appDeviceName[15];
	char appDeviceName[15]="/dev/canB";
	char *optout = NULL;
	//char *optout = TRUE;
	FILE *TX;
        int appDevHandle;
	char ch;
	int count = 0, id = 1;
	unsigned long fcount = 1;

void handler_fin (int unused);

  struct can_btr btr;
  struct sigaction sa_fin;		//Declaration pour terminaison (ctrl-C)
  pid_t pid;

float *sendData(string FileName) {
 appDevHandle = open(appDeviceName , O_RDWR);
        if(appDevHandle < 0) {
                printf("Device Open Error (%s)\n", appDeviceName, appDevHandle);
		exit(0);
        } else {
                printf("Device Opened (%s)\n", appDeviceName, appDevHandle);
		//if (optout) {
		if (1==1) {
			while (infinite || loopcount--) {
				//TX = fopen(optout, "r");
				TX = fopen(FileName.c_str(), "r");
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

