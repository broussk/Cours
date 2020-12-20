/*
 * TONNELLE Nathan
 * 25-09-2020
*/

#ifndef GRAPHE_H
#define GRAPHE_H
#include "liste.h"

typedef struct graphe graphe;
struct graphe{
  	int nbSommet;
	int oriente;    //0=non oriente 1=oriente
	int value;      //0=non value   1=value
	liste* l_adj;
	int** m_adj;
};

void initialiser_graphe(graphe *g, char* nomFichier);
void afficher_graphe(graphe *g);
void detruire_graphe(graphe *g);

#endif //GRAPHE_H