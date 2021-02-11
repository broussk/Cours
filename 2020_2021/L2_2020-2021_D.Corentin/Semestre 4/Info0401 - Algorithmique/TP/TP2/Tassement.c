#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(){
    int A[MAX]={0}, x, *P1, *P2, i;

    srand(time(NULL));
    x = rand()%10;
    P1 = A;
    P2 = A;

    for(i=0 ; i<MAX ; i++) *(A+i) = rand()%10;

    printf("\nx: %d\n", x);

    printf("\nTableau: \n");
    for( i=0 ; i<MAX ; i++){
        printf("[%d] | ", *(A+i));
    }

    for(i=0 ; i<MAX ; i++){
        *P1=*P2;
        if(*P2!=x)P1++;
        P2++;
    }

    printf("\nTableau sans %d : \n",x);
    for(i=0 ; i<(P1-A) ; i++) printf("[%d] | ", *(A+i));

    return 0;
}