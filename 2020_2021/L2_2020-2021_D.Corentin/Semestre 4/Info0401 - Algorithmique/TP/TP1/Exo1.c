#include <stdio.h>

int main() {
    int A = 1;
    int B = 2;
    int C = 3;
    int *P1 = NULL, *P2 = NULL;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    P1=&A;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    P2=&C;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    *P1=(*P2)++;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    P1=P2;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    P2=&B;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    *P1-=*P2;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    ++*P2;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    *P1*=*P2;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    A=++*P2**P1;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    P1=&A;
    printf("A= %d, B= %d, C= %d\n", A, B, C);
    *P2=*P1/=*P2;
    printf("A= %d, B= %d, C= %d\n", A, B, C);

    return 0;
}
