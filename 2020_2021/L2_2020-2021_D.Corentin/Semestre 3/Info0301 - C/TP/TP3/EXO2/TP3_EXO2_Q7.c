#include<stdio.h>

int main (void){
    int i, j, h, num;

    num = 1;

    printf("Entrez le nombre de table à afficher: \n");
    scanf("%d", &h);

    for (i = 1; i<=h; i++){
        for (j = 1; j<=h; j++){
            if(j<=i){
                printf("%d ", num++);
            }
        }
        printf("\n");
    }
    
    return 0;
}
