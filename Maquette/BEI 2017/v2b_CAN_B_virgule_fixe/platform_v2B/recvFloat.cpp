/*************************************************
*******************   recvFloat   ****************
*************************************************/
/*/
Fontionnement de recv float

Ouvre le port canA ou canB (argument en entrée de la fonction)
Rentre dans la boucle while(running)
Attend que quelqu'un parle le bus can
Dès qu'une trame est recu sauvegarde la trame dans data avec ioctl
Convertie la trame en float
Renvoie le float


-Attention cout renvoie une avec tronquée du float
le float vaut avec cout : 1.23457e+07
Le float vaut avec printf : 12345678.000000
L'utilisation de printf est recommandée

/*/

#include "recvFloat.h"
#include <string>
using namespace std;

extern int optind, opterr, optopt;

static int	s = -1;
static int	running = 1;

static void sigterm(int signo) {
	running = 0;
}

uint16_t recvFloat(int identificateur,char *port){
//float recvFloat(char *port){




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
        char appDeviceName_recv[5];     
        int appDevHandle_recv;
        unsigned long data[10];
	int fileflag = 0;
        FILE *RX;

	unsigned long fcount_recv = 1;

        struct can_frame *frame_recv;





        sprintf(appDeviceName_recv,"/dev/%s",port);
        //printf("appDeviceName_recv : %s\n",appDeviceName_recv);
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
	


	appDevHandle_recv = open(appDeviceName_recv , O_RDWR);
        if(appDevHandle_recv < 0) {
       	        printf("Device Open Error (%s)\n", appDeviceName_recv, appDevHandle_recv);
		exit (0);
        } else {
        	printf("Device Opened (%s) par recvFloat\n", appDeviceName_recv, appDevHandle_recv);

/*************************************************
*********  Recupération des données   ************
*************************************************/								
running = 1;
		while (running) {
	              	appWRetVal_recv = ioctl(appDevHandle_recv, SJA1000_IOCRECV, (unsigned long) data);
			if(appWRetVal_recv != 0)
			{
				if(data[0]==identificateur)
				{
		                        //Permet d'écrire dans la console ce qui est dans la trame recue
					i_recv=0;
					if (data[i_recv] & CAN_EFF_FLAG){
						printf("<0x%08x> ", data[i_recv++] & CAN_EFF_MASK);
		                        }
					else
		                                { 
						printf("<0x%03x> ", data[i_recv++] & CAN_SFF_MASK);
		                                }
		                        //(unsigned long) DATA_RECV = data[i_recv]
					dlc_recv = data[i_recv++];
					printf("[%d] ", dlc_recv);
		                        running=0;
					while(i_recv <= dlc_recv + 1) {
						printf("%02x ", data[i_recv++]);
					}
					if (data[0] & CAN_RTR_FLAG)
						printf("remote request");
					printf("\n");
				
                                running=0;
				}
				else{printf("L'dentificateur ne correspond pas à la trame recue\n");
				//while(1){}
				}
			}
		}
	}
		
	/*/for (int indice = 0 ; indice<10 ; indice++){
       // printf("<0x%03x> ", data[indice] & CAN_EFF_MASK);
        cout << "data[indice] = " << data[indice] << endl ;
        }/*/
        appRetVal_recv = close(appDevHandle_recv);
        if(appRetVal_recv == 0) {
                printf("Device Closed par recvFloat\n", appRetVal_recv);
        } else {
                printf("Device Close Error - %d\n", appRetVal_recv);
        }


/*************************************************
*********  Conversion ASCII float     ************
*************************************************/

        int taille=dlc_recv;
        int i[taille-1];


        char b[taille];

        for (int ind=0 ; ind<taille ; ind++)
        {
        i[ind]=data[ind+2]; //valeur en ascii
        b[ind]=(char)i[ind];//valeur du caractere
        }
        b[taille]='\0'; //caractère qui indique la fin de la chaine
        char chaine[taille];

        sprintf(chaine,"%s",b);
	cout << "l'identificateur est : " << data[0] << endl;
        cout << "la chaine vaut : " << chaine << endl;

        uint16_t nombre = (uint16_t) atoi(chaine);

   //     cout << "le float vaut avec cout : " << nombre << endl;
    //    printf("Le float vaut avec printf : %f\n",nombre);
	return nombre;
}
