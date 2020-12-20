#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "sommet.h"


int main(){
    file *fil = malloc(sizeof(file));
    sommet *som0 = malloc(sizeof(sommet));
    sommet *som1 = malloc(sizeof(sommet));
    sommet *som2 = malloc(sizeof(sommet));  

    printf("\nDébut programme ...\n");
    initialiserFile(fil);
    initialiserSommet(som0);
    initialiserSommet(som1);
    initialiserSommet(som2);
    printf("Fin initialisation file et sommet 0 1 2...\n");

    printf("\nDébut affichage sommet...\n");
    afficherSommet(som0);
    afficherSommet(som1);
    afficherSommet(som2);
    printf("\nFin affichage ...\n");

    printf("\nRegardons si la file est vide : %d (0 : vide ; 1 : non vide)\n", fileVide(fil));
    printf("\nRegardons si la file est pleine : %d (0 : plein ; 1 : non pleine)\n", filePleine(fil));

    printf("\nDébut enfile dans file ...\n");
    enfiler(fil, som0);
    printf("\tsommet 0 enfilé ...\n");
    enfiler(fil, som1);
    printf("\tsommet 1 enfilé ...\n");
    enfiler(fil, som2);
    printf("\tsommet 2 enfilé ...\n");
    printf("Fin enfilement dans file ...\n");


    return 0;
}
