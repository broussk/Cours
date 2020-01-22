#include <stdio.h>

int main() {
    int taille, i=0, max;
    //Initialisation de taille
    printf("Entrez la taille du tableau:\n");
    scanf("%d", &taille);
    //Initialisation des tableaux
    int T1[taille], T2[taille];
    printf("Entrez les valeurs du tableau:\n");
    while(i<taille){
        scanf("%d", &T1[i]);
        i++;
    }
    //Affichage de T1
    i=0;
    while(i<taille){
        printf("%d \n", T1[i]);
        i++;
    }
    //Recherche du max
    max=T1[0];
    for(i=1; i<taille; i++){
        if(max<T1[i]){
            max=T1[i];
        }
    }
    //Normalisation
    printf("%d \n", max);
    for(i=0; i<taille; i++){
        T2[i] = T1[i]/max;
    }
    //Affichage de T2
    for(i=0; i<taille; i++){
        printf("%d \n", T2[i]);
    }
    return 0;
}