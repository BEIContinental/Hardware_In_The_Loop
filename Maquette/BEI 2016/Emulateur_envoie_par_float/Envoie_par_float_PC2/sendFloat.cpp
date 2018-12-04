/*************************************************
*******************   Send Float   ****************
*************************************************/

//permet d'envoyer 1 trame sur le canA
//recupere un float 
//attention le float doit avoir au maximum 8 caractères (sinon modifié la fonction pour envoyer plusieurs trames).
//le transforme en char
//envoie


#include "sendFloat.h"
#include <string.h>

using namespace std;

extern int optind, opterr, optopt;



float *sendFloat(float nombre) {



	struct can_frame frame = {
		//can_id = 1,
	};
	int loopcount = 1, infinite = 0;
	int s, opt, ret, i, dlc = 0, rtr = 0, extended = 0;
	int verbose = 0,pattern = 0;

	short appRetVal, appWRetVal;
        //char appDeviceName[15];
	char appDeviceName[15]="/dev/canA";
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



	
/***************************************************
************   Conversion float ascii     **********
****************************************************/
		ostringstream os;
		os << nombre;
		string st=os.str();
		char CHAINE[st.size()];
                sprintf(CHAINE , "%f",nombre);

//cout << "Size = " << s.size() <<endl;



/*/for (int i1=0 ; i1<s.size() ; i1++){
int x = CHAINE[i1];

cout << "The character '" << CHAINE[i1] << "' has an ASCII code of " << std::hex << x << endl;
}/*/




/*****************************************************************************
************   Mise en mémoire dans data  **********
*****************************************************************************/

/*/
		for (int i2=0 ; i2<s.size() ; i2+=2){
		int x1 = CHAINE[i2];
		int x2 = CHAINE[i2+1];

		ostringstream os2;
		os2 << std::hex << x1 << std::hex << x2;
		string caracteres_s = os2.str();
		char const *caracteres_c=caracteres_s.c_str();
		cout << "caracteres_c = " << caracteres_c << endl;
		frame.data[dlc] = strtoul(caracteres_c, NULL, 0);
		cout << "frame.data[dlc] = " << frame.data[dlc] << endl;
		dlc++;
		if (dlc == 8)
			break;

}/*/

		for (int i2=0 ; i2<st.size() ; i2++){
			int x1 = CHAINE[i2];
			//int x2 =CHAINE[i2+1];

			ostringstream os2;
			os2 << x1;
			//os2 << std::hex << CHAINE[i2] << CHAINE[i2+1];
			string caracteres_s = os2.str();
			char const *caracteres_c=caracteres_s.c_str();
			cout << "caracteres_c = " << caracteres_c << endl;
			frame.data[dlc] = strtoul(caracteres_c, NULL, 0);
			cout << "frame.data[dlc] = " << frame.data[dlc] << endl;
			dlc++;
			cout << "dlc = " << dlc << endl;
			if (dlc == 8)
				break;

		}
		frame.can_dlc = dlc;
		frame.can_id=1;
/***************************************************
************   Ouverture du port can      **********
****************************************************/
 appDevHandle = open(appDeviceName , O_RDWR);
        if(appDevHandle < 0) {
                printf("Device Open Error (%s)\n", appDeviceName, appDevHandle);
		exit(0);
        } else {
                printf("Device Opened (%s)\n", appDeviceName, appDevHandle);


/***************************************************
************   Envoie direct des données  **********
****************************************************/

		while (infinite || loopcount--) {
			if(pattern) {
				for (i = 0; i < frame.can_dlc; i++)
					frame.data[i] = frame.data[i] + 1;
                		appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
			} else {

        			appWRetVal = ioctl(appDevHandle, SJA1000_IOCTRANS, (unsigned long)&frame);
			}
			if (frame.can_id & CAN_EFF_FLAG) {
				printf("<0x%08x> ", frame.can_id & CAN_EFF_MASK);

			}
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
        appRetVal = close(appDevHandle);
        if(appRetVal == 0) {
                printf("Device Closed\n", appRetVal);
        } else {
                printf("Device Close Error\n", appRetVal);
        }

	return 0;
}

