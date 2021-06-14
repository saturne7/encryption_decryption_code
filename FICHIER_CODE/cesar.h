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
*  Nom du fichier : cesar.h                                                   *
*                                                                             *
******************************************************************************/
#include <stddef.h>

void crypt(char * message, int key, char * messageCode);
void decrypt(char * messageCode, int key, char * messageOriginel);
int verifierMessage(char * message);

// void convertirAccent(wchar_t * message, char * messageSansAccent); (Ne fonctionne pas)

