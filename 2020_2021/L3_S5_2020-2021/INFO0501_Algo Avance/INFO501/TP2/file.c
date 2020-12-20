/*
 * TONNELLE Nathan
 * 02-10-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"
#include "file.h"
#define TAILLE 20 //nombre d'arêtes 

//initialise une file vide de capacité maximale fixe
void initialiserFile(file *fil){
    fil = malloc(sizeof(sommet)*TAILLE);
    fil->tete = NULL;
    fil->queue = NULL;
}

//détruit une file, libère ses ressources mémoires
void detruireFile(file* fil){
    free(fil);
}

//retourne  0 si vide (vrai)
//          1 si non vide (faux)
int fileVide(file* fil){
    if(fil == NULL) return 0;
    else return 1;
}

//retourne  0 si pleine (vrai)
//          1 sinon (faux)
int filePleine(file* fil){
    int cpt = 0;
    while(fil != NULL){
        fil ++;
        cpt ++;
    }
    if(cpt == TAILLE) return 0;
    else return 1;
}

//ajoute un sommet en queue de file
void enfiler(file* fil, sommet*som){
    sommet *sommetDefile = fil->sommet;
    if(filePleine(fil)==0){
        printf("file pleine, impossible d'ajouter");
        return;
    }
    if(fileVide(fil)==1){
        while(fil->sommet==NULL){
            fil->sommet->pere = sommetDefile->pere;
        }
        fil->sommet = som;
    }else{
        fil->sommet = som;
    }
}

//enlève le sommet en tête de file s'il en existe et retourne sa valeur
sommet* defiler(file* fil){
    //int nb;
    if (fileVide(fil)) exit(EXIT_FAILURE);

    //vérification s'il y a un sommet à défiler
    if (fil->sommet != NULL)
    {
      sommet *elementDefile = fil->sommet;
      fil->sommet->pere = elementDefile->pere;
      return elementDefile;
      free(elementDefile);
    }
    else return NULL;
}