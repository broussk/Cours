/*
 * TONNELLE Nathan
 * 09-10-2020
 * 16-10-2020
*/

#include "cellule.h"
#include "arete.h"

void initArete(arete *art, cellule *cellDebut, int poidsParam){
    art->sommetCelluleOrigine = cellDebut;
    art->sommetCelluleExtremite = cellDebut->successeur;
    art->poids = poidsParam;
}

//récupère la liste des aretes dans le graphe à partir des listes d'adjacences et les remets dans le tableau arts passé en param
void aretesGrapheListeAdjacence(int *arts, graphe *g){
    g->l_adj;
}
//récupère la liste des aretes dans le graphe à partir de la matrice d'adjacences et les remets dans le tableau arts passé en param
void aretesGrapheMatriceAdjacence(int *arts, graphe *g){
    g->m_adj;
    for(int i=0; i<g->nbSommet; i++){
        for(int j=0; j<g->nbSommet; j++){
            arts[i] = g->m_adj[i][j];
        }    
    }
}

//tri par insertion
void triInsertion(arete **tab, int sizeOfTab){
}