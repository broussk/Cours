#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "cellule.h"
#include "liste.h"
#include "graphe.h"

#define TAILLE 100

void initialiser_graphe(Graph *g, char *nom_fichier){
    FILE *fichier;
    char chaine[TAILLE] = "";
    int sommet;
    int value;
    int oriente;
    int j;
    char char_sommet[TAILLE]="";

    fichier = fopen(nom_fichier, "r");
    if(fichier == NULL){
        printf("Impossible d'ouvrir le fichier");
        exit(EXIT_FAILURE);
    }
    // Récupération du nombre de sommet
    fscanf(fichier , "%s",chaine);
    fscanf(fichier,"%d",&sommet);
    // Récupération orienté
    fscanf(fichier , "%s",chaine);
    fscanf(fichier,"%d",&oriente);
    //Récupération value
    fscanf(fichier , "%s",chaine);
    fscanf(fichier,"%d",&value);
    // Récupération "DEBUT_DEF_ARETES"
    fscanf(fichier, "%s",chaine);
    fscanf(fichier,"%s",chaine);

    // allocation dynamique de la liste d'adjacence
    g->liste_adjacence = malloc(sizeof(liste) *sommet);

    // allocation dynamique de la matrice d'adjacence
    g->matrice_adjacence = malloc(sizeof(int*)*sommet);

    for(int i = 0; i < sommet; i++){
        initialiser_liste(&g->liste_adjacence[i]);
    }

    for(int i = 0; i < sommet; i++){
        g->matrice_adjacence[i] = malloc(sizeof(int)*sommet);
    }

    if(oriente!=0){
        while(strcmp(chaine,"FIN_DEF_ARETES")!=0){
            Cellule *c = malloc(sizeof(Cellule));
            fscanf(fichier,"%s",char_sommet);
            initCellule(c,atoi(char_sommet));
            j=atoi(chaine);
            inserer(&g->liste_adjacence[j],c);
            fscanf(fichier,"%s",chaine);
        }
    }else{
        while(strcmp(chaine,"finDefAretes")!=0){
            Cellule *c = malloc(sizeof(Cellule));
            Cellule *d = malloc(sizeof(Cellule));
            fscanf(fichier,"%s",char_sommet);
            initCellule(c,atoi(char_sommet));
            j=atoi(chaine);
            inserer(&g->liste_adjacence[j],c);
            initCellule(d,atoi(chaine));
            j=atoi(char_sommet);
            inserer(&g->liste_adjacence[j],d);
            fscanf(fichier,"%s",chaine);
        }
    }

    g->nb_vertices = sommet;
    g->oriente=oriente;
    g->value=value;
    fclose(fichier);

    // Maintenant on remplit la matrice d'adjacence

    for(int i = 0; i < sommet; i++){
        for(int j = 0; j < sommet; j++){
            if(rechercher(&g->liste_adjacence[i],j)){
                g->matrice_adjacence[i][j] = 1;
            }
            else{
                g->matrice_adjacence[i][j] = 0;
            }
        }
    }  
}

void afficher_graphe(Graph* g){
     
    printf("Nombre de sommets : %d\n", g->nb_vertices); 
    if (g->oriente==0)
       {
           printf("Non oriente\n");
       }
    else{
        printf("Oriente\n");
    } 
    if (g->value==0)
       {
           printf("Non Value\n");
       }
    else{
        printf("Value\n");
    }     
    printf("\n Liste d'adjacences : \n");
    for (int i = 0; i < g->nb_vertices; i++)
    {   printf("%d--->",i );
        afficher_liste(&g->liste_adjacence[i]);
    }

    printf("\n Matrice d'adjacences \n");
    for(int i = 0; i < g->nb_vertices; i++){
        for(int j = 0; j < g->nb_vertices; j++){
            printf(" %d ",g->matrice_adjacence[i][j]);
        }
        printf("\n");   
    }
}

void detruire_graphe(Graph *g){
    printf("\n\nDestruction du graphe !\n");
    for(int i=0 ; i<(g->nb_vertices) ; i++){
        free(g->matrice_adjacence[i]);
    }
    free(g->matrice_adjacence);
    g->nb_vertices = 0;
    g->oriente = 0;
    g->value = 0;
}
