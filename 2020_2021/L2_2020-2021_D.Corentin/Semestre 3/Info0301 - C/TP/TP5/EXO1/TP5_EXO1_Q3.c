#include<stdio.h>
#include<stdlib.h>

int main(){
    int *vec1, *vec2, *somme, *soustraction,*produit;
    long produit_scalaire;
    int size_vector, i;

    do{
        printf("Saisir la longueur du vecteur:\n");
        scanf("%d",&size_vector);
    }while(size_vector < 0);

    produit_scalaire = 0;

    vec1 = malloc(size_vector * (sizeof(int)));
    vec2 = malloc(size_vector * (sizeof(int)));
    somme = malloc(size_vector * (sizeof(int)));
    soustraction = malloc(size_vector * (sizeof(int)));
    produit = malloc(size_vector * (sizeof(int)));

    printf("Vecteur 1:\n");
    for(i=0; i < size_vector; i++){
        scanf("%d",(vec1 + i));
    }
    printf("Vecteur 2:\n");
    for(i=0; i < size_vector; i++){
        scanf("%d",(vec2 + i));
    }

  //Opérations


    printf("Somme :\n");
    for(i=0; i < size_vector; i++){
        *(somme+i) = *(vec1 + i) + *(vec2 + i);
        printf("[%d]: %d\n", i, *(somme+i));
    }


    printf("\nSoustraction :\n");
    for(i=0; i < size_vector; i++){
        *(soustraction + i) = *(vec1 + i) - *(vec2 + i);
        printf("[%d]: %d\n", i, *(soustraction + i));
    }


    printf("\nProduit :\n");
    for(i=0; i < size_vector; i++){
        *(produit + i) = vec1[i] * vec2[i];
        printf("[%d]: %d\n", i, *(produit + i));
    }



    for(i=0; i < size_vector; i++){
        produit_scalaire += (long)(vec1[i] * vec2[i]);
    }
    printf("\nProduit scalaire: %ld \n", produit_scalaire);


    free(vec1);
    free(vec2);
    free(somme);
    free(soustraction);
    free(produit);

    return(0);
}