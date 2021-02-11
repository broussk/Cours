#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    float **tab = NULL;
    float somme = 0;
    int nbL, nbC, i, j;

    do {
        printf("Entrez le nombre de ligne:");
        scanf("%d", &nbL);
    } while (nbL <= 0);

    do {
        printf("Entrez le nombre de colonnes:");
        scanf("%d", &nbC);
    } while (nbC <= 0);


    tab = (float**) malloc(nbL * sizeof(float*));

    if(tab == NULL) exit(0);

    for (i=0;i<nbL;i++){
        tab[i] = (float*) malloc(nbC * sizeof(float));
        if(tab == NULL) exit(0);
    }


    for (i=0; i<nbL; i++){
        for (j=0; j<nbC; j++){
            printf("tab[%d][%d]:", i, j);
            scanf("%f", &tab[i][j]);
            somme += tab[i][j] * tab[i][j];
        }
        printf("\n");
    }

    printf("Affichage de la matrice:\n");
    for (i=0; i<nbL; i++){
        for (j=0; j<nbC; j++){
            printf("%.2f ", tab[i][j]);
        }
        printf("\n");
    }

    printf("La norme de la matrice est: %.2lf", sqrt(somme));


    for (i=0;i<nbL;i++){
        free(tab[i]);
    }
    free(tab);
    tab = NULL;
    return 0;
}
