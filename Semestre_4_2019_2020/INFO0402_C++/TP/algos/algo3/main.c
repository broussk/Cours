#include <stdio.h>

int main() {
    int taille, i=0, j=0;
    //Initialisation de taille
    printf("Entrez la taille de la matrice:\n");
    scanf("%d", &taille);
    //Initialisation des matrices 1 et 2
    int M1[taille][taille], M2[taille][taille], M3[taille][taille];
    printf("Entrez les valeurs de la matrice 1:\n");
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            scanf("%d", &M1[i][j]);
        }
    }
    printf("Entrez les valeurs de la matrice 2:\n");
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            scanf("%d", &M2[i][j]);
        }
    }
    //Initialisation de M3
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            if(M1[i][j]==1 && M2[i][j]==1){
                M3[i][j]=1;
            }
            else{
                M3[i][j]=0;
            }
        }
    }
    //Affichage M3
    for(i=0; i<taille; i++){
        for(j=0; j<taille; j++){
            printf("%d ", M3[i][j]);
        }
        printf("\n");
    }
    return 0;
}