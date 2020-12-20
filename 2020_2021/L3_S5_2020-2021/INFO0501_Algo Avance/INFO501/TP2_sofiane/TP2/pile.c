#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "stdbool.h"
#define TAILLE 10

// initialise une pile vide de capacité maximale fixe en allouant la mémoire necessaire
Pile *initialiser_pile(void){
	return NULL;
}
// retourne vrai si la pile est vide, faux sinon
bool pile_vide(Pile *p){
	if(p == NULL){
		return true;
	}else{
		return false;
	}
}
// ajoute un élément au sommet de la pile 
Pile *empiler(Pile *p, Sommet *s){
	Pile *element;

	element = malloc(sizeof(*element));

	if(element == NULL){
		fprintf(stderr," Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = s->id;
	element->suivant = p;

	return element;
}
// détruit une pile en libérant ses ressources mémoire ;
Pile *detruire_pile(Pile *p){
	while(!pile_vide(p)){
		p = depiler(p);
	}
	return initialiser_pile();
}
// affiche le contenu de la pile
void afficher_pile(Pile *p){
	if(pile_vide(p)){
		printf("Rien a afficher, la Pile est vide");
		return;
	}

	while(!pile_vide(p)){
		printf("[%d] ", p->value);
		p = p->suivant;
	}
}
// enlève l'élément au sommet de la pile s'il en existe un et retourne sa valeur
Pile *depiler(Pile *p){
	Pile *element;
	
	if(pile_vide(p)){
		return initialiser_pile();
	}
	element = p->suivant;
	free(p);

	return element;
}
//  retourne la valeur de l’élément au sommet de la pile sans le dépiler
int sommet(Pile *p){
	if(pile_vide(p)){
		printf("Aucun sommet, la Pile est vide.\n");
		return 0;
	}

	return p->value;
}
// retourne la taille de la pile
int taille_pile(Pile *p){
	int taille = 0;
	while(!pile_vide(p)){
		taille++;
		p = p->suivant;
	}

	return taille;
}
// retourne vrai si la pile est pleine, faux sinon
bool pile_pleine(Pile *p){
	if(sommet(p) == taille_pile(p)){
		return true;
	}else{
		return false;
	}
}