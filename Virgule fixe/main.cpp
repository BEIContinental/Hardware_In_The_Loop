/* Source code to test the FixedPoint class.
 * Designed by Nicolas Berling
 * January 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

#include "fixedPoint.hpp"

int main(int argc, char *argv[]) {
    FixedPoint fixed_point;
    
    uint16_t val_u16;
    int16_t val_s16;
    float val;
    
    val_u16 = 0;
    val_s16 = 0;
    val = 0;
    
    printf("\n\n\nBienvenue dans ce programme permettant de tester la classe FixedPoint !!!\n");
    printf("Les arguments sont dans l'ordre la valeur flottante à transmettre, sa borne maximale et sa borne minimale (également flottantes).\n\n\n");
    
    if ((argc <= 3) || (argc > 4)) {
        printf("Vous avez entré %d arguments, alors que le programme en attend 3.\n", argc-1);
        printf("Fermeture...\n\n\n");
        return 0;
    }
    else {
        //printf("atof(argv[4]) = %f\n", atof(argv[4]));
        if (atof(argv[3]) >= 0) {
            val_u16 = fixed_point.to_can_u16(atof(argv[1]), atof(argv[2]), atof(argv[3]));
            printf("Le flottant converti en non signé 16 bits et envoyé sur le bus est : %" PRIu16 "\n", val_u16);
            val = fixed_point.from_can_u16(val_u16, atof(argv[2]), atof(argv[3]));
            printf("Le non signé 16 bits reçu sur le bus et converti en flottant est : %f\n\n\n", val);
        }
        else {
            val_s16 = fixed_point.to_can_s16(atof(argv[1]), atof(argv[2]), atof(argv[3]));
            printf("Le flottant converti en signé 16 bits et envoyé sur le bus est : %" PRId16 "\n", val_s16);
            val = fixed_point.from_can_s16(val_s16, atof(argv[2]), atof(argv[3]));
            printf("Le signé 16 bits reçu sur le bus et converti en flottant est : %f\n\n\n", val);
        }
    }
    
    printf("Bon courage pour la suite ! ;)\n");
    printf("Fermeture...\n\n\n");
    return 1;
}
