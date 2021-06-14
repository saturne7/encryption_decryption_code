/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet :  3                                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : BARRIERES Mathieu                                            *
*                                                                             *
*  Nom-prénom2 : DEVIENNE-OUSMER Julien                                       *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                   *
*                                                                             *
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "cesar.h"
#include <wchar.h>
#include <stddef.h>

#define taille 100
#define key 3

// Les élément mis en commentaire correspondent à notre tentative de convertir les accents

int main() {
    
    // wchar_t msgOrig[taille];
    char msg[taille];
    char msgCrypt[taille];
    char msgDecrypt[taille];

    // Création et ouverture du fichier de sauvegarde des données 
    FILE *fichier = fopen ("fichiersauvegarde.txt", "a");

    printf("Quel message voulez-vous crypter ?\n");
    fprintf(fichier, "Quel message voulez-vous crypter ?\n");

    fgets(msg, taille, stdin);
    fprintf(fichier,"%s\n",msg);
    //fgetws(msgOrig, taille, stdin);
    printf("\n");

    //convertirAccent(msgOrig,msg);

    if (verifierMessage(msg) == 0) {
        crypt(msg, key, msgCrypt);
        printf("Le message crypté vaut : %s\n", msgCrypt);
        fprintf(fichier, "Le message crypté vaut : %s\n", msgCrypt);
       
        decrypt(msgCrypt, key, msgDecrypt);
        printf("Le message decrypté vaut : %s\n", msgDecrypt);
        fprintf(fichier, "Le message décrypté vaut : %s\n", msgDecrypt);
        
    }else{        
        printf("Ce message contient un ou plusieurs caractère(s) spécial(aux) que nous ne pouvons pas chiffrer.\n");
        fprintf(fichier, "Ce message contient un ou plusieurs caractère(s) spécial(aux) que nous ne pouvons pas chiffrer.\n");
        fprintf(fichier,"\n");
    }

    // Fermeture du fichier d'enregistrement
    fclose(fichier);
}