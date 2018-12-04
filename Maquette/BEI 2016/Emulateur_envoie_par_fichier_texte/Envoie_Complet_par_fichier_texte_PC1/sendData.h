#ifndef SENDDATA_H
#define SENDDATA_H
#include <string>
#include <iostream>	//Pour afficher les messages (cout)
#include <fstream>		//Pour la lecture des fichier en C++
#include <getopt.h>
#include <libgen.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "can.h"
#include "sja1000_ioctl.h"
using namespace std;

float *sendData(string FileName);

#endif
