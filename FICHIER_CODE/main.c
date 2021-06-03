#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "cesar.h"
#include "cesar.c"

int main() {
    
    char msg[100];
    char cpt[100];
    char dpt[100];

    printf("Quel message voulez-vous crypter ?\n");
    fgets(msg, 100, stdin);

    cesarEnc(msg, 3, cpt);

    printf("Le message crypté vaut : %s\n", cpt);

    cesarDec(cpt, 3, dpt);

    printf("Le message decrypté vaut : %s\n", dpt);


}