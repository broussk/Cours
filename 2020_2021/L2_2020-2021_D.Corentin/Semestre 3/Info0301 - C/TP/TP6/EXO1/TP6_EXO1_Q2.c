#include <stdio.h>

int carre (int x){
    return x*x;
}

int main(void){
    int a, b, c;
    c = 0;
    b = 0;
    if (a > b)
        c = 0;
    else
        b = 0;

    printf("Le carre de 2 est: %d", carre(2));
    return 0;
}