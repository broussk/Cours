/*
 * TONNELLE Nathan
 * 16-10-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "tas.h"
#include "arete.h"

//initialise un tas max a partir d'un tableau de sorte à ce que ces éléments soient structurés sous forme de tas max
tas* initialiser_tas(arete **t, int size){
    tas *tasInt = malloc(sizeof (tas)*size);
    //int i=0;
    for (int j=0; j<size/2; j++){
        tasInt->parent = t[j/2];
        tasInt->gauche = t[2*j];
        tasInt->droite = t[2*j+1];
    }
    return tasInt;
}


//entasse l’élément d’indice i afin de rétablir la propriété de tas ;
void entasser_max(tas *tasIn,int n){
    arete *gauche = malloc(sizeof(arete));
    arete *droite = malloc(sizeof(arete));
    arete *temp = malloc(sizeof(arete));
    int max = n;
    gauche = tasIn[n].gauche;
    droite = tasIn[n].droite;
    if (tasIn->gauche > gauche){
        max = gauche->poids;
    }
    if (tasIn->droite > droite){
        max = droite->poids;
    }
    if (max != n){
        temp = tasIn[n].parent;
        tasIn[n] = tasIn[max];
        tasIn[max].parent = temp;
        entasser_max(tasIn, max);
    }
}


//détruit un tas en libérant les ressources mémoires
void detruire_tas(tas *tasIn, int size){
    printf("\n\nDestruction du tas ...\n");
    for(int i=size/2; i>=0; i--){
        free(tasIn[i].gauche);
        free(tasIn[i].droite);
    }
    free(tasIn);
}


//trie le tableau d'arêtes
void tri(tas *tasIn, int n){
	if (n <= 1) return;
	for (int i = n/2; i>=0;i--){
		entasser_max(tasIn,i);
	}
}


//affiche le tas
void afficher_tas(tas *tasIn){
    for(int i=0; i<12; i++){
        printf("%d", tasIn[i].parent->poids);
        printf("%d", tasIn[i].gauche->poids);
        printf("%d", tasIn[i].droite->poids);
    }
}