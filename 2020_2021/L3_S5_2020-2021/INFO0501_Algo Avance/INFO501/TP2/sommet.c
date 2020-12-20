/*
 * TONNELLE Nathan
 * 25-09-2020
 * 02-10-2020
*/

#include <stdlib.h>
#include <stdio.h>
#include "sommet.h"

void initialiserSommet(sommet *s){
  s->pere = malloc(sizeof(sommet));
  s->distance = 0;
  s->couleur = BLANC;
  s->id = 0;
}

void afficherSommet(sommet *s){
  printf("%d ", s->id);
}