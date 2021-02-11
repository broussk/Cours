#include <stdio.h>

int main(){

    int a, b;
    printf("Entrez deux nombres: \n");
    scanf("%d %d", &a, &b);
    printf("Qutient: %d & Reste: %f", (int) (a/b), (double) (a%b));


    return 0;

}