/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "cellule.h"

//initialise la liste en paramètre à NULL
void initialiser_liste(liste *l){
  l->tete = NULL;
}

//supprime définitivement la liste
void detruire_liste(liste *l){
  while(l->tete!=NULL){
    supprimer(l,l->tete);
  }
  printf("Liste supprimee !\n");
  //if(l!=NULL) free(l);
}

//inser une cellule dans le haut de la liste
void inserer(liste *l, cellule *c){
  c->successeur = l->tete;
  if(l->tete != NULL){
    l->tete->precedant = c;
  }
  l->tete = c;
  c->precedant = NULL;
}

//affiche la liste
void afficher_liste(liste *l){
  cellule *c = malloc(sizeof(cellule));
  if(l->tete!=NULL){
    c = l->tete;
    while(c!=NULL){
      printf(" %d" ,c->sommet);
      c = c->successeur;
    }
  }
  else{
    printf("Erreur ! La liste que vous essayez d'afficher est vide\n");
  }
  printf("\n");
}

//recherche un sommet dans une liste 
//retourne soit un pointeur sur la cellule qui contient le sommet, soit NULL
cellule* rechercher(liste *l, int id_s){
  cellule *c = malloc(sizeof(cellule));
  if(l->tete!=NULL){
    c = l->tete;
    while((c != NULL) && (c->sommet != id_s)){
      c = c->successeur;
    }
  }
  return c;
}

//Supprime une cellule dans une liste si elle existe
void supprimer(liste *l, cellule *c){
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

