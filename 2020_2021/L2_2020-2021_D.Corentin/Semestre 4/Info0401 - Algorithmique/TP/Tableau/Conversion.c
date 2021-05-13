#include <stdio.h>


int main() {
    int tab[16] = {0}, val, i;

    //Initialisation de la valeur à convertir
    do{
        printf("Entrez une valeur: ");
        scanf("%d", &val);
    } while (val < 0);


    //Conversion binaire
    for(i=0;val>0;i++){
        tab[i]=val%2;
        val=val/2;
    }

    //Affichage du tableau contenant le chiffre convertit en binaire
    for (i = i-1; i>=0; i--) {
        printf("[%d] | ", tab[i]);
    }
}