#include <stdio.h>
#include <string.h>
#include "floyd.cpp"
#include "floyd.h"
int main(){
        int x;
        printf("affichage Floyd\n");
        x=floyd();
        printf("affichage Floyd recu");
        x=floydrecur();
        return 0;
};

