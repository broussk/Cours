#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "cellule.h"

/* Initialisation de la liste */

void initialiser_liste(liste *l){
    l->premier = NULL;
    l->dernier = NULL;
    
}

/* Libère les ressources mémoire d'une liste */

void detruire_liste(liste *l){
    element *tmp;
    element *pelement = l->premier;
    while(pelement){
        tmp = pelement;
        pelement = pelement->suivant;
        free(tmp);
    }
    l->premier = NULL;
    l->dernier = NULL;
}

/* Ajout d'une cellule en début de liste */

void inserer(liste *l,Cellule *c){
    element *nouveau = malloc(sizeof(element));
    if(!nouveau){
        exit(EXIT_FAILURE);
    }
    nouveau->val =c->sommetGraphe;
    nouveau->suivant = l->premier;
    nouveau->precedent = NULL;
    if(l->premier){
        l->premier->precedent = nouveau;
    }else{
        l->dernier = nouveau;
    }
    l->premier = nouveau;
}

/* Affichage d'une liste à l'écran */

void afficher_liste(liste *l){
    element *pelement = l->premier;
    while(pelement){
        printf("%d\t",pelement->val);
        pelement = pelement->suivant;
    }
    printf("\n");
}

/* Recherche un sommet dans une liste */

Cellule *rechercher(liste *l,int k){
    Cellule *c = malloc(sizeof(Cellule));
    if(l != NULL){
        struct element *p_temp = l->premier;
        int found = 0;
        while(p_temp != NULL && !found){
            if(p_temp->val == k){
                initCellule(c,k);
                found = 1;
            }
            else{
                p_temp = p_temp->suivant;
            }
        }
        if(found == 0){
            c = NULL;
        }

    }
    return c;
}

/* Supprime une cellule de la liste */

liste *supprimer(liste *l,Cellule *c){
    if(l != NULL){
        struct element *p_temp = l->premier;
        while(p_temp != NULL ){
            if(p_temp->val == c->sommetGraphe){
                struct element *p_del = p_temp;
                p_temp = p_temp->suivant;
                if(p_del->suivant == NULL){    
                    l->dernier = p_del->precedent;
                    l->dernier->suivant = NULL;
                }
                else if(p_del->precedent == NULL){
                    l->premier = p_del->suivant;
                    l->premier->precedent = NULL;
                }
                else{
                    p_del->suivant->precedent = p_del->precedent;
                    p_del->precedent->suivant = p_del->suivant;
                }
                free(p_del);
                l->length--;
            }
            else{
             p_temp = p_temp->suivant;
            }
        }
    }
    return l;
}




