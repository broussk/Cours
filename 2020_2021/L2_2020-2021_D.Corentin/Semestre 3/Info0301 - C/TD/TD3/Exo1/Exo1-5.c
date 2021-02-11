#include <stdio.h>
#define max 10

int main(){

    int tab[max];
    int i,nb,occ;

    occ=0;

    printf("Entrez %d valeur(s): \n", max);

    for (i=0; i<max; i++){
        scanf("%d", &tab[i]);
    }

    printf("Tableau:\n");

    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    printf("\nQuel occurence voulez vous trouver ?\n");
    scanf("%d",&nb);

    for (i=0; i<max; i++){
        if(tab[i]==nb){
            occ++;
        }
    }

    printf("%d est apparu %d fois.\n", nb ,occ);

    return 0;
}
