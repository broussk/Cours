#include <stdio.h>
#include <math.h>
void main(){
    int taille,i;
    double res;
    int* vec1= NULL;
    int* vec2= NULL;
    

    //Initialisation de la taille des tableaux
    printf("Entrez la taille des tableaux :");
    scanf("%d",&taille);

    //Initialisation des tableaux
    vec1 = malloc(taille * sizeof(int));
    vec2 = malloc(taille * sizeof(int));

    //Remplissage des tableaux
    for(i=0;i<taille;i++){
        printf("vec1[%d] = ",i);
        scanf("%d",&vec1[i]);
    }

    for(i=0;i<taille;i++){
        printf("vec2[%d] = ",i);
        scanf("%d",&vec2[i]);
    }

    free(vec1);
    free(vec2);

}