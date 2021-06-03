#include "cesar.h"

void cesarEnc(const char * message, short key, char * nvmessage){
    unsigned int i = 0;
    short rang;
    while( message[i] != '\0') {
        if( ( message[i] >= 'a') && (message[i] <= 'z') ){
            rang = (message[i] - 'a' + key) % 26;
            if( rang < 0) rang += 26;
            nvmessage[i] = 'a' + rang;
        }
        else if(( message[i] >= 'A') && (message[i] <= 'Z')){
            rang = (message[i] - 'A' + key) % 26;
            if( rang < 0) rang += 26;
            nvmessage[i] = 'A' + rang;
        }
        else {
            nvmessage[i] = message[i];
        }
        i++;
    }
    nvmessage[i] = '\0';
}

void cesarDec(const char * nvmessage, short key, char * plaintext){
    cesarEnc(nvmessage, -key, plaintext);
}
