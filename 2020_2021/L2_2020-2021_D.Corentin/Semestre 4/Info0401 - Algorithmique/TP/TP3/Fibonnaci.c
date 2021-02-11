#include <stdio.h>

#define MAX 100

int main(){
    int F[MAX], i, size;
    do{
        printf("Entre une taille <%d:\n", MAX);
        scanf("%d", &size);
    } while (size < 0 || size > MAX);

    F[0] = 0;
    printf("f(0) = %d \n", F[0]);
    F[1] = 1;
    printf("f(1) = %d \n", F[1]);

    for(i = 2; i < size; i++){
        F[i] = F[i-1] + F[i-2];
        printf("f(%d) = %d \n", i, F[i]);
    }

}