#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"

void init_sommet(Sommet *s){
    s->c = BLANC;
    s->id = 0;
    s->distance = 0;
     s->pere = malloc(sizeof(Sommet));
    
}

void afficher_sommet(Sommet *s){
    printf("%d ",s->id);
}