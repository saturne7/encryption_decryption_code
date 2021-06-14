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
*  Nom du fichier : cesar.c                                                   *
*                                                                             *
******************************************************************************/

#include "cesar.h"
#include <string.h>
#include <wchar.h>
#include <stddef.h>

/* Tentative sur les accents de 'e'
 wchar_t eAccent[] = {130, 131, 132, 133} ;
 void convertirAccent(wchar_t * message, char* messageSansAccent){
    for(int i = 0; message[i] != '\0'; i++){
        for(int k = 0; k < sizeof(eAccent); k++){
            if(strcpm(message[i], eAccent[k]) == 0){
                messageSansAccent[i] = 'e';
            }
        }
    }
}*/

// Fonction qui permet de crypter, à l'aide d'une clef, un message donné pour le stocker dans un nouveau tableau.
// Exemple pour les lettres :
// Cette fonction transforme les caractères de la table ASCII en chiffres pour pouvoir manipuler les 26 lettres (en majuscules et minuscules)
// On applique la clef de chiffrement et on enlève la valeur de 'a' dans la table ASCII modulo 26 pour ne pas sortir de l'alphabet
// Cette dernière re-transforme les chiffres en code ASCII pour pouvoir stocker le nouveau caractère

// Cas d'erreur n°1: Lorsque l'on met un seul caractère la fonction d'affichage main affiche de nouveaux caractères qui apparaissent sur un nouvelle ligne
// Cas d'erreur n°2: Lorsque l'on crypte un message, il se peut que quelque fois le message d'erreur "Segmentation fault (core dumped)" apparaisse mais crypte quand même le message
void crypt(char * message, int key, char * messageCode){ 
    int position;
    for(int i = 0; message[i] != '\n'; i++){       
        if((message[i] >= 'a') && (message[i] <= 'z')){
            position = (message[i] - 97 + key) % 26;   // Retrait de la valeur de 'a' dans la table ASCII pour pouvoir manipuler les 26 lettres de l'alphabet plus facilement
        if(position < 0) position += 26;
            messageCode[i] = 97 + position;   // On ajoute la valeur de 'a' retiré précédement pour retourner au format ASCII et donc pouvoir récupérer les caractères   
        }
        else if((message[i] >= 'A') && (message[i] <= 'Z')){
                position = (message[i] - 65 + key) % 26;  // Retrait de la valeur de 'A' dans la table ASCII pour pouvoir manipuler les 26 lettres de l'alphabet plus facilement
            if(position < 0) position += 26;
                messageCode[i] = 65 + position;    // On ajoute la valeur de 'A' retiré précédement pour retourner au format ASCII et donc pouvoir récupérer les caractères
        }else if(message[i] >= ' ' && message[i] <= '@'){
                position = (message[i] - 32 + key) % 33; // Retrait de la valeur de ' ' dans la table ASCII
            if(position < 0) position += 33;
                messageCode[i] = 32 + position; // On ajoute la valeur de ' ' retiré précédement pour retourner au format ASCII et donc pouvoir récupérer les caractères 
        } 
        else if(message[i] >= '[' && message[i] <= '`'){
                position = (message[i] - 91 + key) % 6; // Retrait de la valeur de '[' dans la table ASCII
            if(position < 0) position += 6;    
                messageCode[i] = 91 + position; // On ajoute la valeur de '[' retiré précédement pour retourner au format ASCII et donc pouvoir récupérer les caractères  
        }
        else if(message[i] >= '{' && message[i] <= '~'){
                position = (message[i] - 123 + key) % 4; // Retrait de la valeur de '{' dans la table ASCII
            if(position < 0) position += 123;    
                messageCode[i] = 123 + position; // On ajoute la valeur de '{' retiré précédement pour retourner au format ASCII et donc pouvoir récupérer les caractères     
        }    
    }
}

// Fonction contraire à crypt qui permet de décrypter un message donné.
// Cette dernière utilise la même méthode que pour crypt mais la clef devient négative
void decrypt(char * messageCode, int key, char * messageOriginel){
    crypt(messageCode, -key, messageOriginel);
}

// Fonction qui permet de vérifier si le message contient des caractères spéciaux (ponctuation, accents, etc...)
// Elle accepte tout les caractères de la table ASCII

int verifierMessage(char * message){
    int verif = 0;
    for(int i = 0; message[i] != '\0'; i++){
        if( ((message[i] >= 'a') && (message[i] <= 'z')) || (( message[i] >= 'A') && (message[i] <= 'Z')) || (message[i] >= ' ' && message[i] <= '@') || (message[i] >= '[' && message[i] <= '`') || (message[i] >= '{' && message[i] <= '~') || message[i] == '\n'){
            verif += 0;
        } else {
            verif += 1;
        }
    }
    return verif;
}