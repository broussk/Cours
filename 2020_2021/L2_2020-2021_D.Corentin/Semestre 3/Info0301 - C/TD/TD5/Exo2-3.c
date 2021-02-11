#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (){
    float ** tab=NULL;
    int i, j, nbpoints;
    float som_x=0, som_y=0, som_xy=0, som_xx=0, som_yy=0,corr;

    /* Saisie du nombre de points */
    do{
        printf("Entrez le nombre de points :");
        scanf("%d", &nbpoints);
    } while (nbpoints<3);


    /*.Allocation dynamique du tableau de points*/
    tab = (float**) malloc(nbpoints * sizeof(float *));
    if (tab == NULL) exit(0);

    for (i = 0; i < nbpoints; ++i){
        tab[i] = (float*) malloc(2 * sizeof(float));
        if (tab[i] == NULL){
            exit(0);
        }
    }

    /* Saisie des coordonnées des points et calcul des sommes */
    for (i=0; i < nbpoints; i++) {
        printf("Donnez les coordonnees x y du point num %d :",i);
        scanf("%f %f",&tab[i][0],&tab[i][1] );
        som_x +=tab[i][0];
        som_y +=tab[i][1];
        som_xx +=tab[i][0]*tab[i][0];
        som_yy +=tab[i][1]*tab[i][1];
        som_xy +=tab[i][0]*tab[i][1];
    }


    /* Affichage du tableau de points */
    for (i = 0; i < nbpoints; ++i) {
        printf("(%f,%f)\n", tab[i][0],tab[i][1]);
    }


    /* Calcul de la correlation et affichage */
    // .... à compléter

    corr = (som_xy - (som_x * som_y)) / (sqrt(nbpoints * ((som_xx) - (som_x * som_x))) * (nbpoints * ((som_yy) - (som_y * som_y))));
    printf("Le coefficent de correlation est: %.2lf", corr);


    /* Libération de l'espace mémoire */
    for (i = 0; i < nbpoints; ++i) {
        free(tab[i]);
        tab[i]=NULL;
    }
    free(tab);
    tab=NULL;
    return 0;
}