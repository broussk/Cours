#ifndef __LISTE__H__
#define __LISTE__H__
#include "cellule.h"

/* Structure représentant un élément de la liste */

typedef struct element{
    int val;
    struct element *precedent;
    struct element *suivant;
}element;

/* Stucture d'accés à la liste */

typedef struct liste{
    size_t length;
    element *premier;
    element *dernier;
    struct Cellule *tete;
}liste;

/* Prototypes des fonctions */

/* Initialisation de la liste */

void initialiser_liste(liste *l);

/* Libère les ressources mémoire d'une liste */

void detruire_liste(liste *l);

/* Ajout d'une cellule en début de liste */

void inserer(liste *l,Cellule *c);

/* Affichage d'une liste à l'écran */

void afficher_liste(liste *l);

/* Recherche un sommet dans une liste */

Cellule *rechercher(liste *l,int k);

/* Supprime une cellule de la liste */

liste  *supprimer(liste *l,Cellule *c);

#endif // !__LISTE__H__
