/*
 * TONNELLE Nathan
 * 11-09-2020
 * 25-09-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "liste.h"
#include "graphe.h"

//main test pour graphes
int main(int argc, char *argv[]){
  graphe *g = malloc(sizeof(graphe));
  printf("\ninitialisation du graphe ...\n");
  initialiser_graphe(g,argv[1]);
  printf("\ninitialisation du graphe ... terminé \n");

  printf("\nafficher graphe : \n");
  afficher_graphe(g);
  printf("\nfin de l'affichage du graphe\n");

  printf("\ndétruction graphe ...\n");
  detruire_graphe(g);
  printf("\nfin de la destruction du graphe...\n");
  printf("\nVérification de la destruction : \n");
  afficher_graphe(g);
  printf("\nFIN\n");
  return 0;
}

//main test pour listes & cellules
/*
int main(){
    //initialisation de la liste
    liste testListe;
    initialiser_liste(&testListe);
    cellule *testCell = malloc(sizeof(cellule));
    cellule *testCell1 = malloc(sizeof(cellule));
    cellule *testCell2 = malloc(sizeof(cellule));
    cellule *testCell3 = malloc(sizeof(cellule));
    cellule *testCell4 = malloc(sizeof(cellule));
    cellule *testCell5 = malloc(sizeof(cellule));
    
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

    //afficher liste :
    printf("afficher liste : \n");
    afficher_liste(&testListe);
    printf("fin de l'affichage de la liste \n\n");

    //rechercher un sommet
    printf("\ndébut de la recherche \n");
    printf(" valeur recherchée : 9, \n valeur trouvée : %d\n", rechercher(&testListe, 9)->sommet);
    printf("fin de la recherche \n\n");

    //supprimer une cellule
    printf("\nDébut de la suppression de cellule \n");
    printf(" Liste de départ : \n");
    afficher_liste(&testListe);
    printf(" on retire la cellule avec le sommet : 15\n");
    supprimer(&testListe, rechercher(&testListe, 15));
    printf("\n Vérification de la suppression :\n");
    afficher_liste(&testListe);
    printf("fin de la suppression de cellule \n\n");

    //supprimer la liste
    printf("\nDébut de la suppression de la liste \n");
    afficher_liste(&testListe);
    detruire_liste(&testListe);
    afficher_liste(&testListe);
    printf("fin de la suppression de la liste \n\n");

  return 0;
}
*/