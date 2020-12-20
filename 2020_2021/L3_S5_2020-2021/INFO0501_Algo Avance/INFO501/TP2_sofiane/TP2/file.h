#ifndef __FILE__H__
#define __FILE__H__
#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"
#include "graphe.h"
#include <stdbool.h>

// Definition de la structure File

typedef struct File File;
struct File{
  Sommet *sommets;
  struct File *tete;
  struct File *queue;
  int value;
  int nb_elements;
  struct File *suivant;
};


// Prototypes

void initialiser_file(File *f);

void detruire_file(File *f);

int file_premier(File *f);

bool file_vide(File *f);

bool file_pleine(File *f);

void enfiler(File *f,Sommet *s);

Sommet* defiler(File *f);

void afficher_file(File *f);

int file_taille(File *f);

void ParcoursLargeur(Graph* g,Sommet* s);

void afficher_chemin(Graph *g,Sommet *s,Sommet *v);

void parcours_profondeur_recursif(Graph *g);

void visiter_pp(Graph *g, Sommet *s, int date);

void afficher_parcours_profondeur(Graph* g,Sommet *s);


#endif // !__FILE__H__