#include <stdio.h>
int main()
{
    int h, i ,j;
    printf("Entrez une hauteur: \n");
    scanf("%d",&h);

    while (h>=10){
        printf("Erreur la hauteur doit etre inferieur à 10: \n");
        scanf("%d",&h);
    }

    for (i = 1; i<=h; i++){
        for (j = 1; j<=h; j++){
            if(j<=i){
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}