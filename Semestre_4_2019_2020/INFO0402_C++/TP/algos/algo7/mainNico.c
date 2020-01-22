#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c,i,taille;
    printf("entrer valeure entière positive");
    scanf("%d",&taille);

    printf("0 "); 

    if(taille >= 1){
        printf("1 "); //affichage si taille 1 ou plus
    }

    if(taille >= 2){
        printf("1 "); // affichage si taile 2 ou plus
    }

    // initialisation des variables

    a=0;
    b=1;
    c=1;


    // boucle pour le calcul de la suite de fibonacci
    if(taille >= 3){
        for(i=2;i<taille;i++){
            a=b;
            b=c; // decalage des valeurs
            c=a+b; // calcul fibonacci
            printf("%d ",c);
        }
    }

    printf("\n");

    return 0;
}