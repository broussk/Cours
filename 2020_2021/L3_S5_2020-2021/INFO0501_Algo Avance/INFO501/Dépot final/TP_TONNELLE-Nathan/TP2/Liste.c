/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"
#include "Cellule.h"

//initialise la Liste en paramètre à NULL
void initialiser_liste(Liste *l){
  l->tete = NULL;
}

//supprime définitivement la Liste
void detruire_liste(Liste *l){
  while(l->tete!=NULL){
    supprimer(l,l->tete);
  }
  printf("Liste supprimee !\n");
  //if(l!=NULL) free(l);
}

//inser une Cellule dans le haut de la Liste
void inserer(Liste *l, Cellule *c){
  c->successeur = l->tete;
  if(l->tete != NULL){
    l->tete->precedant = c;
  }
  l->tete = c;
  c->precedant = NULL;
}

//affiche la Liste
void afficher_liste(Liste *l){
  Cellule *c = malloc(sizeof(Cellule));
  if(l->tete!=NULL){
    c = l->tete;
    while(c!=NULL){
      printf(" %d" ,c->sommet);
      c = c->successeur;
    }
  }
  else{
    printf("Erreur ! La Liste que vous essayez d'afficher est vide\n");
  }
  printf("\n");
}

//recherche un sommet dans une Liste 
//retourne soit un pointeur sur la Cellule qui contient le sommet, soit NULL
Cellule* rechercher(Liste *l, int id_s){
  Cellule *c = malloc(sizeof(Cellule));
  if(l->tete!=NULL){
    c = l->tete;
    while((c != NULL) && (c->sommet != id_s)){
      c = c->successeur;
    }
  }
  return c;
}

//Supprime une Cellule dans une Liste si elle existe
void supprimer(Liste *l, Cellule *c){
  if(l->tete != NULL){
    if(rechercher(l,c->sommet)){
      if(c->precedant != NULL){
        c->precedant->successeur = c->successeur;
      }
      else{
        l->tete = c->successeur;
      }
      if(c->successeur != NULL){
        c->successeur->precedant = c->precedant;
      }
    }
  }
  printf("Cellule supprimee\n");
}

