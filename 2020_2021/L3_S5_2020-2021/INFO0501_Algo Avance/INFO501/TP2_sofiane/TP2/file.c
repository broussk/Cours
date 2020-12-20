#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "sommet.h"
#include "graphe.h"
#include "limits.h"
#include "cellule.h"
#define TAILLE 10

// procédure qui va initialiser une file vide de cpacité maximale fixe en allouant la mémoire nécessaire

void initialiser_file(File *f){
    f->sommets = malloc(sizeof(Sommet)*TAILLE);
    f->tete = NULL;
    f->queue = NULL;
    f->nb_elements = 0;
}

// procédure qui va retourner vrai si la file est vide faux sinon

bool file_vide(File *f){
    if(f->tete == NULL && f->queue == NULL){
        return true;
    }else{
        return false;
    }
}

int file_premier(File *f){
    if(file_vide(f)){
        exit(1);
    }
    return f->tete->value;
}

// procédure qui va renvoyer la taille de la file

int file_taille(File *f){
    return f->nb_elements;
}

// procédure qui va afficher la file

void afficher_file(File *f){

    if(file_vide(f)){
        printf("Rien a afficher, la file est vide.\n");
        return;
    }

    File *temp = f->tete;

    while(temp != NULL){
        printf("[%d] ",temp->value);
        temp = temp->suivant;
    }
    printf("\n");
}

// procédure qui va ajouter un élement en queue de file

void enfiler(File *f,Sommet *s){

    File *element = malloc(sizeof(*element));
    if(element == NULL){
        fprintf(stderr,"Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->value = s->id;
    element->suivant = NULL;
    if(file_vide(f)){
        f->tete = element;
        f->queue = element;
    }else{
        f->queue->suivant = element;
        f->queue = element;
    }

    f->nb_elements++;
}

// procédure qui va enlever l'element en tête de file s'il en existe et retourne sa valeur

Sommet* defiler(File *f){
    
    if(file_vide(f)){
        printf("Rien a retirer, la liste est deja vide.\n");
        return 0;
    }

    Sommet *temp = f->sommets;

    if(f->tete == f->queue){
        f->tete = NULL;
        f->queue = NULL;
    }else{
        f->tete = f->tete->suivant;
    }
    free(temp);
    f->nb_elements--;
    return temp;
}

// procédure qui va detruire une file passé en paramètre en libérant ses ressources mémoire

void detruire_file(File *f){
    if(file_vide(f)){
        printf("Rien a nettoyer, la File est deja vide");
        return;
    }
    while(!file_vide(f)){
        defiler(f);
    }
}

// procédure qui va retourner vrai si la file est pleine faux sinon

bool file_pleine(File *f){
   int cpt = 0;
  while(f!=NULL){
      f++;
      cpt++;
  }
  if(cpt==TAILLE){return true;}
  else{return false;}
}


void ParcoursLargeur(Graph* g,Sommet* s){
    
    File *f = malloc(sizeof(File));
    initialiser_file(f);
    Sommet *u = malloc(sizeof(Sommet));
    Sommet *v = malloc(sizeof(Sommet));
    for(int i = 0; i < g->nb_vertices;i++){
        init_sommet(u);
        init_sommet(v);
    }
    for(int i = 0; i < g->nb_vertices; i++){
        u->c = BLANC;
        u->pere = NULL;
        u->distance = INT_MAX;
    };
    s->c = GRIS;
    s->distance = 0;
    s->pere = NULL;
    f = NULL;
    enfiler(f,s);
    while(!file_vide(f)){
        u = defiler(f);
        liste *w;
        for(w = g->liste_adjacence; w != NULL;w++){
            printf("%d",s->id);
            if(s->c == BLANC){
                s->c = GRIS;
                s->distance = u->distance + 1;
                s->pere = u;
                enfiler(f,s);  
            }
        }
        u->c = NOIR;
    }
}

void parcours_profondeur_recursif(Graph *g){
    Sommet *u = malloc(sizeof(Sommet));
    for(int i = 0; i < g->nb_vertices; i++){
        u->c = BLANC;
        u->pere = NULL;
    }
    int date = 0;
    for(int i = 0; i < g->nb_vertices; i++){
        if(u->c == BLANC){
            visiter_pp(g,u,date);
        }
    }
}

    void visiter_pp(Graph *g, Sommet *s,int date){
    date = date + 1;
    s->c = GRIS;
    s->debut = date;
    Sommet *v = malloc(sizeof(Sommet));
    liste *w;
    for(w = g->liste_adjacence; w!= NULL; w++){
        if(v->c == BLANC){
            v->pere = s;
            visiter_pp(g,v,date);
        }
        s->c = NOIR;
        date = date + 1;
        s->fin = date;
    }
    
}    

void afficher_chemin(Graph *g,Sommet *s,Sommet *v){ 
    // Premier cas a gérer : Le sommet s = sommet v
    if(s == v){
        afficher_sommet(s);
    }
    //Deuxième cas à gérer : Le sommet v n'a pas de pere
    else{
        if(v->pere == NULL){
            printf("Attention, il n'existe aucun chemin allant de S a V");
        }else{
            afficher_chemin(g,s,v->pere);
            afficher_sommet(v);
        }
    }
}

void afficher_parcours_profondeur(Graph* g,Sommet *s){
    for (int i = 0; i < g->nb_vertices; i++){
        if(s->pere==NULL){
            printf("Sommet : %d, date debut :%d , date fin :%d , pere :-1 \n",s->id,s->debut,s->fin);
        }
        else{
            printf("Sommet : %d, date debut :%d , date fin :%d , pere :%d \n",s->id,s->debut,s->fin,s->pere->id);
        }
    }
}




