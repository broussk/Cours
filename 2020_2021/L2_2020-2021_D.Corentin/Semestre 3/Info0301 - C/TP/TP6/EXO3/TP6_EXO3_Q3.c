#include <stdio.h>

void inc (int *nb) {
    *nb = *nb + 5;
}


int main(){
    int a = 10, b = 20, c = 30;
    printf("Avant incrementation: a= %d, b= %d, c= %d\n", a, b, c);
    inc(&a);
    inc(&b);
    inc(&c);
    printf("Apres incrementation: a= %d, b= %d, c= %d", a, b, c);

    return 0;
}