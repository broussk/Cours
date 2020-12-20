#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "sommet.h"

int main(){
    
    Pile *p = malloc(sizeof(Pile)); 
    
    p = initialiser_pile();
    
    if(pile_vide(p)){
        printf("La pile est vide");
    }else{
        printf("La pile a des elements");
    }

    Sommet *s = malloc(sizeof(Sommet));
    Sommet *u = malloc(sizeof(Sommet));
    Sommet *v = malloc(sizeof(Sommet));
    init_sommet(s);
    init_sommet(u);
    init_sommet(v);
    s->id = 7;
    u->id = 41;
    v->id = 102;

    p = empiler(p,s);
    p = empiler(p,u);
    p = empiler(p,v);

    printf("\n");

    afficher_pile(p);
    printf("\n");
    printf("Sommet actuel : %d\n", sommet(p));

    if(pile_pleine(p)){
        printf("La pile est pleine\n");
    }else{
        printf("La pile n'est pas pleine\n");
    }

    p = depiler(p);

    afficher_pile(p);

    if(pile_vide(p)){
        printf("\nLa pile est vide");
    }else{
        printf("\nLa pile a des elements");
    }
    p = detruire_pile(p);
    if(pile_vide(p)){
        printf("\nLa pile est vide");
    }else{
        printf("\nLa pile a des elements");
    }
    
    return 0;
}