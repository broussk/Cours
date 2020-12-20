/*
 * TONNELLE Nathan
 * 25-09-2020
 * 02-10-2020
*/

#include <stdlib.h>
#include <stdio.h>
#include "Sommet.h"

void initialiserSommet(Sommet *s){
  s->pere = malloc(sizeof(Sommet));
  s->distance = 0;
  s->couleur = BLANC;
  s->id = 0;
}

void afficherSommet(Sommet *s){
  printf("%d ", s->id);
}