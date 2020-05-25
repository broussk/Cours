#include "fct2.h"
#include "fcts.h"

void fct2(char txt[]){
    char c;
    int dec;
    int i,j;
    dec=lire_dec();
    c=txt[0];
    j=0;
    for (i = 0; i <3; i++)
    {
        txt[j]=txt[(j+dec)%4];
        j=(j+dec)%4;
    }
    txt[j]=c;
    return;
}