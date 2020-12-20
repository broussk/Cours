/*
 * TONNELLE Nathan
 * 06-11-2020
 * 13-11-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "cellule.h"

#define MAX 27

//initialise la liste en paramètre à NULL
void initialiser_liste(Liste *l){
    l->tete = NULL;
    l->precedant = NULL;
    l->taille = 0;
}

//initialise la liste en avec le fichier en paramètre
void initialiser_liste_fichier(Liste *l, char* nomFichier){
    initialiser_liste(l);
    FILE* f = NULL;
    char chaine[MAX] = "";
    char chaine_sommet[MAX];

    f = fopen(nomFichier, "r+");
    if(f == NULL){
        printf("[ERREUR] Impossible d'ouvrir le fichier.");
        return;
    }

    //récupération des mots
    fscanf(f, "%s", chaine);

    while(strcmp(chaine, "FIN_FICHIER") != 0){
        if(strlen(chaine) < MAX){
            Cellule *c = malloc(sizeof(Cellule));
            initCellule(c, chaine);
            inserer(l, c);
            l->taille = l->taille + 1; 
        }
        fscanf(f, "%s", chaine);
    }
    fclose(f);
}

//supprime définitivement la liste
/*void detruire_liste(Liste *l){
    while(l->tete!=NULL){
        supprimer(l,l->tete);
    }
    printf("Liste supprimee !\n");
    //if(l!=NULL) free(l);
}*/

//inser une cellule dans le haut de la liste
void inserer(Liste *l, Cellule *c){
    if(l->taille == 0){
        c->successeur = l->tete;
        if(l->tete != NULL){
            l->tete->precedant = c;
        }
        l->tete = c;
        c->precedant = NULL;
        l->taille = l->taille + 1;
        printf("\tPremiere insertion dans la liste avec le mot : %s.\n", c->chaine);
    }
    else{
        /*Cellule* rechercheCellule = malloc(sizeof(Cellule));
        rechercheCellule = rechercher(l, c->chaine);
        if(strcmp(rechercheCellule->chaine, l->tete->chaine) == 0){
            c->successeur = l->tete;
            if(l->tete != NULL){
                l->tete->precedant = c;
            }
            l->tete = c;
            c->precedant = NULL;
            l->taille = l->taille + 1;
        }*/


        //if(strcmp(rechercher(l, c->chaine)->chaine, l->tete->chaine) == 0){
            //printf("\naffichage de la tête : %s\n", l->tete->chaine);
            c->successeur = l->tete;
            if(l->tete != NULL){
                l->tete->precedant = c;
            }
            l->tete = c;
            c->precedant = NULL;
            l->taille = l->taille + 1;
            //Cellule *celluleRecherche = malloc(sizeof(Cellule));
            //celluleRecherche = rechercher(l, c->chaine);
            /*
    printf("\nrecherche d'insertion : \tretour Recherche : %s\t\tchaine de tete : %s\n", celluleRecherche->chaine, l->tete->chaine);
    printf("Résultat comparaison : recherche d'insertion et tete : %d\n", strcmp(celluleRecherche->chaine, l->tete->chaine));
    printf("insertion de (nouvelle tete): %s\n", l->tete->chaine);
        }
        else{
            printf("Le mot : %s est déjà dans la liste.\n", c->chaine);
        }*/
    }
    printf("Liste : \t");
    afficher_liste(l);
}

//affiche la liste
void afficher_liste(Liste *l){
    Cellule *c = malloc(sizeof(Cellule));
    if(l->tete!=NULL){
        c = l->tete;
        while(c!=NULL){
            printf(" %s" ,c->chaine);
            c = c->successeur;
        }
    }
    else{
        printf("Erreur ! La liste que vous essayez d'afficher est vide\n");
    }
    printf("\n");
}

//recherche une chaine dans une liste 
//retourne soit un pointeur sur la cellule qui contient la chaine, soit NULL
Cellule* rechercher(Liste *l, char chaine[27]){
    Cellule *c = malloc(sizeof(Cellule));
    int numeroCellule = -1;
    

    if(l->tete != NULL){
        c = l->tete;
        numeroCellule = 0;
        while ((c != NULL) && (strcmp(c->chaine, chaine))) //&& numeroCellule != l->taille)
        {
            printf("\n\tCellule recherchée : %s ; \n\tCellule de tête : %s\n", chaine, c->chaine);
            numeroCellule = numeroCellule + 1;
            c = c->successeur;
        }
        numeroCellule = numeroCellule + 1;
    }
    else{
        char chaineNULL[] = "null";
        Cellule *cNULL = malloc(sizeof(Cellule));
        initCellule(cNULL, chaineNULL);
    }
    printf("numéro de la cellule de la recherche : %d\n", numeroCellule);
    return c;
}

//Supprime une cellule dans une liste si elle existe
void supprimer(Liste *l, char chaine[27]){
    Cellule *cell = malloc(sizeof(Cellule));
    cell = rechercher(l, chaine);
    if(cell == NULL){
        char chaineNULL[] = "null";
        Cellule *cNULL = malloc(sizeof(Cellule));
        initCellule(cNULL, chaineNULL);
        cell = cNULL;
    }
    printf("\nChaine a supprimer : \t%s\n", chaine);
    printf("\nChaine trouvée : \t%s\n", cell->chaine);

    if(strcmp(cell->chaine, chaine) == 0){
        cell->precedant->successeur = cell->successeur;
        cell->successeur->precedant = cell->precedant;
        cell->precedant = NULL;
        cell->successeur = NULL;
        l->taille = l->taille - 1;
        printf("Cellule supprimee\n");
    }
    else
    {
        printf("Le mot \"%s\" n'est pas dans la liste.\n", chaine);
    }
}