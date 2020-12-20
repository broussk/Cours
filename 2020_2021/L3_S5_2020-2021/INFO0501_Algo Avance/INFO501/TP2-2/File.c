/*
 * TONNELLE Nathan
 * 02-10-2020
 * 06-10-2020
 * 07-10-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "Sommet.h"
#include "File.h"
#define TAILLE 20 //nombre d'arêtes 

//initialise une File vide de capacité maximale fixe
void initialiserFile(File *fil){
    fil = malloc(sizeof(Sommet)*TAILLE);
    fil->tete = NULL;
    fil->queue = NULL;
    fil->longueur = 0;
}

//retourne la taille de la file
int tailleFile(File *fil){
    return fil->longueur;
}

//détruit une File, libère ses ressources mémoires
void detruireFile(File* fil){
    fil->tete = NULL;
    fil->queue = NULL;
    fil->sommet = NULL;
    free(fil);
}

//retourne  0 si vide (vrai)
//          1 si non vide (faux)
int fileVide(File* fil){
    if(fil->tete == NULL && fil->queue == NULL && fil->sommet == NULL) return 0;
    else return 1;
}

//retourne  0 si pleine (vrai)
//          1 sinon (faux)
int filePleine(File* fil){
    int cpt = 0;
    while(fil->sommet != NULL){
        fil ++;
        cpt ++;
    }
    if(cpt == TAILLE) return 0;
    else return 1;
}

//ajoute un Sommet en queue de File
void enfiler(File* fil, Sommet* som){
    //Sommet *sommetDefile = fil->sommet;
    if(filePleine(fil) == 0){
        printf("File pleine, impossible d'ajouter");
        return;
    }
    if(fileVide(fil) == 1){
        while(fil->sommet==NULL){
            fil->suivant = som;
            //fil->suivant->queue = fil->sommet;
            fil->sommet->pere = fil->suivant;
            fil->queue = fil->sommet;
            fil->sommet = fil->suivant;
            fil->suivant = NULL;
            //fil->sommet->pere = sommetDefile->pere;
        }
        fil->sommet = som;
        fil->longueur ++;
        printf("enfilement du sommet dans la file (non vide)\n");
    }else{
        fil->sommet = som;
        fil->longueur ++;
        printf("enfilement du sommet dans la file (vide)\n");
    }
}

//enlève le sommet en tête de File s'il en existe et retourne sa valeur
Sommet* defiler(File* fil){
    //int nb;
    if (fileVide(fil)) exit(EXIT_FAILURE);

    //vérification s'il y a un Sommet à défiler
    if (fil->sommet != NULL)
    {
      Sommet *elementDefile = fil->sommet;
      fil->sommet->pere = elementDefile->pere;
      return elementDefile;
      free(elementDefile);
    }
    else return NULL;
}

//affiche la file, si la file est vide : affiche un message
void afficherFile(File* fil){
    if(fileVide(fil) == 0) printf("\nLa file est vide.\n");
    else{
        File* filParcours = fil;
        Sommet *tmp = filParcours->sommet;
        while(tmp->pere != NULL){
            printf("(%d) ", tmp->id);
            tmp = tmp->pere;
        }
        printf("\n");
    }
}