#include <stdio.h>

int first_rep_dec(int a) {
    while (a > 10){
        a /= 10;
    }
    return a;
}

int main(void){
    int a = 685;
    printf("Le premier chiffre de %d est %d", a,  first_rep_dec(a));
    return 0;
}