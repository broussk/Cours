#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"

int main(void){
    
    int nb;
    etudiant* tab = NULL;
    etudiant e;

    do { 
      printf("Combien d\'étudiant voulais vous stocker ?");
      scanf("%d", &nb);

    } while (nb < 0);

    tab = (etudiant *) malloc(nb * sizeof(etudiant));
    if(tab == NULL) exit(0);

    saisir(&e);
    affichage_etudiant(e);

    free(tab);
    return 0;
}