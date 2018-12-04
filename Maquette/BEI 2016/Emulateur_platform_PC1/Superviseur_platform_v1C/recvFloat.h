#ifndef RECVDATA_H
#define RECVDATA_H
#include <string>
#include <errno.h>
#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <getopt.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "can.h"
#include "sja1000_ioctl.h"



using namespace std;

static void sigterm(int signo);
float recvFloat(int identificateur,char *port);

#endif
