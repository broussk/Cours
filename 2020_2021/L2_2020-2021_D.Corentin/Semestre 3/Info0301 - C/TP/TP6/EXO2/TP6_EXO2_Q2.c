#include <stdio.h>

#define FALSE (1==0)
#define TRUE  (1==1)

int verif(int a, int b, int c){
    int cpt = 0;
    if (a == b){
        cpt++;
    } else if ( a == c){
        cpt++;
    } else if ( b == c){
        cpt++;
    }

    return cpt == 2 ? TRUE : FALSE;
}

int main(void){
    int a = 10, b = 10, c = 10;
    printf("Est ce que 2 variable sont identique ? %d", verif(a, b, c));
    return 0;
}