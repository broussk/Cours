#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Sommet.h"

int main(){
    File *fil = malloc(sizeof(File));
    Sommet *som0 = malloc(sizeof(Sommet));
    Sommet *som1 = malloc(sizeof(Sommet));
    Sommet *som2 = malloc(sizeof(Sommet));  

    printf("\nDébut programme ...\n");
    initialiserFile(fil);
    initialiserSommet(som0);
    som0->id = 1;
    initialiserSommet(som1);
    som1->id = 2;
    initialiserSommet(som2);
    som2->id = 3;
    printf("Fin initialisation File et Sommet som0 : %d ;  som1 : %d ; som2 : %d ...\n", som0->id, som1->id, som2->id);

    printf("\nDébut affichage Sommet...\n");
    afficherSommet(som0);
    afficherSommet(som1);
    afficherSommet(som2);
    printf("\nFin affichage ...\n");

    printf("\nRegardons si la File est vide : %d (0 : vide ; 1 : non vide)\n", fileVide(fil));
    printf("\nRegardons si la File est pleine : %d (0 : plein ; 1 : non pleine)\n", filePleine(fil));
    printf("\nAffichage longeur de la file : %d \n", tailleFile(fil));

    printf("\nDébut enfile dans File ...\n");
    enfiler(fil, som0);
    printf("\tsommet 0 enfilé ...\n");
    enfiler(fil, som1);
    printf("\tsommet 1 enfilé ...\n");
    enfiler(fil, som2);
    printf("\tsommet 2 enfilé ...\n");
    printf("Fin enfilement dans File ...\n");

    printf("\nRegardons si la File est vide : %d (0 : vide ; 1 : non vide)\n", fileVide(fil));
    printf("\nRegardons si la File est pleine : %d (0 : plein ; 1 : non pleine)\n", filePleine(fil));
    printf("\nAffichage longeur de la file : %d \n", tailleFile(fil));

    printf("\nAffichage de la File : \n");
    afficherFile(fil);
    printf("\nFin de l'affichage de la File ...\n");

    return 0;
}
