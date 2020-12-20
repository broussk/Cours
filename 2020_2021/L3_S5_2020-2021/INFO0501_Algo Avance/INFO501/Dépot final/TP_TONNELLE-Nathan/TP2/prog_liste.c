/*
 * TONNELLE Nathan
 * 11-09-2020
 * 25-09-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "Cellule.h"
#include "Liste.h"
#include "Graphe.h"

//main test pour graphes
int main(int argc, char *argv[]){
  Graphe *g = malloc(sizeof(Graphe));
  printf("\ninitialisation du Graphe ...\n");
  initialiser_graphe(g,argv[1]);
  printf("\ninitialisation du Graphe ... terminé \n");

  printf("\nafficher Graphe : \n");
  afficher_graphe(g);
  printf("\nfin de l'affichage du Graphe\n");

  printf("\ndétruction Graphe ...\n");
  detruire_graphe(g);
  printf("\nfin de la destruction du Graphe...\n");
  printf("\nVérification de la destruction : \n");
  afficher_graphe(g);
  printf("\nFIN\n");
  return 0;
}

//main test pour listes & cellules
/*
int main(){
    //initialisation de la Liste
    Liste testListe;
    initialiser_liste(&testListe);
    Cellule *testCell = malloc(sizeof(Cellule));
    Cellule *testCell1 = malloc(sizeof(Cellule));
    Cellule *testCell2 = malloc(sizeof(Cellule));
    Cellule *testCell3 = malloc(sizeof(Cellule));
    Cellule *testCell4 = malloc(sizeof(Cellule));
    Cellule *testCell5 = malloc(sizeof(Cellule));
    
    printf("initialisation des variables ....... terminé \n\n");

    //création et insertion des cellules
    initCellule(testCell,0);
    inserer(&testListe,testCell);
    initCellule(testCell1,3);
    inserer(&testListe,testCell1);
    initCellule(testCell2,6);
    inserer(&testListe,testCell2);
    initCellule(testCell3,9);
    inserer(&testListe,testCell3);
    initCellule(testCell4,12);
    inserer(&testListe,testCell4);
    initCellule(testCell5,15);
    inserer(&testListe,testCell5);

    //afficher Liste :
    printf("afficher Liste : \n");
    afficher_liste(&testListe);
    printf("fin de l'affichage de la Liste \n\n");

    //rechercher un sommet
    printf("\ndébut de la recherche \n");
    printf(" valeur recherchée : 9, \n valeur trouvée : %d\n", rechercher(&testListe, 9)->sommet);
    printf("fin de la recherche \n\n");

    //supprimer une Cellule
    printf("\nDébut de la suppression de Cellule \n");
    printf(" Liste de départ : \n");
    afficher_liste(&testListe);
    printf(" on retire la Cellule avec le sommet : 15\n");
    supprimer(&testListe, rechercher(&testListe, 15));
    printf("\n Vérification de la suppression :\n");
    afficher_liste(&testListe);
    printf("fin de la suppression de Cellule \n\n");

    //supprimer la Liste
    printf("\nDébut de la suppression de la Liste \n");
    afficher_liste(&testListe);
    detruire_liste(&testListe);
    afficher_liste(&testListe);
    printf("fin de la suppression de la Liste \n\n");

  return 0;
}
*/