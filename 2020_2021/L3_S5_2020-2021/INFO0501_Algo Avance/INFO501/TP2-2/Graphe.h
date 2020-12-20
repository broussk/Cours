/*
 * TONNELLE Nathan
 * 25-09-2020
*/

#ifndef GRAPHE_H
#define GRAPHE_H
#include "Liste.h"

typedef struct Graphe Graphe;
struct Graphe{
  	int nbSommet;
	int oriente;    //0=non oriente 1=oriente
	int value;      //0=non value   1=value
	Liste* l_adj;
	int** m_adj;
};

void initialiser_graphe(Graphe *g, char* nomFichier);
void afficher_graphe(Graphe *g);
void detruire_graphe(Graphe *g);

#endif //GRAPHE_H