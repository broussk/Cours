#include <stdio.h>

int main() {
    int taille, i, j, k;
    //Initialisation de taille
    printf("Entrez la taille des tableaux:\n");
    scanf("%d", &taille);
    //Initialisation de T1 et T2
    int T1[taille], T2[taille], T3[taille*2];
    printf("Entrez les valeurs de T1:\n");
    for(i=0; i<taille; i++){
        scanf("%d", &T1[i]);
    }
    printf("Entrez les valeurs de T2:\n");
    for(i=0; i<taille; i++){
        scanf("%d", &T2[i]);
    }
    //Affichage de T1 et T2
    for(i=0; i<taille; i++){
        printf("%d, ", T1[i]);
    }
    printf("\n");
    for(i=0; i<taille; i++){
        printf("%d, ", T2[i]);
    }
    printf("\n");
    //Initialisation de T3
    i=0;
    j=0;
    k=0;
    while(i<=taille && j<=taille && k<=(taille*2)){
        if(T1[i]<T2[j]){
            T3[k]=T1[i];
            if(i<taille){
                i++;
            }
        }
        else{
            T3[k]=T2[j];
            if(j<taille){
                j++;
            }

        }
        k++;
    }
    //Affichage de T3
    for(i=0; i<taille*2; i++){
        printf("%d, ", T3[i]);
    }
    return 0;
}