#ifndef __GRAPHE__H__
#define __GRAPHE__H__
#include "cellule.h"
#include "liste.h"
#include "sommet.h"

/* Definition d'un graphe */

typedef struct GraphElement{
    int oriente;
    int nb_vertices; /* nombre de sommets */
    int value;
    liste *liste_adjacence;
    int **matrice_adjacence;
    Sommet * l_sommet;
}Graph;

/* Prototypes */

void initialiser_graphe(Graph *g, char *nom_fichier);

void afficher_graphe(Graph* g);

void detruire_graphe(Graph *g);
    




#endif // !__GRAPHE__H__