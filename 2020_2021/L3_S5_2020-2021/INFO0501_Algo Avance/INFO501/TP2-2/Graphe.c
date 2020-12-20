/*
 * TONNELLE Nathan
 * 25-09-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste.h"
#include "Cellule.h"
#include "Graphe.h"

#define MAX 100

//initialise le Graphe avec un fichier en paramètre
// si fichier inexistant, s'arrête
void initialiser_graphe(Graphe *g, char* nomFichier){
  FILE* f = NULL;
  char chaine[MAX] = "";
  int sommet, value, oriente, j;
  char char_sommet[MAX];

  f = fopen(nomFichier, "r+");
  if(f == NULL){
    printf("[ERREUR] Impossible d'ouvrir le fichier.");
    return;
  }

  //récupération nb sommets
  fscanf(f, "%s", chaine);
  fscanf(f, "%d", &sommet);

  //récupération orienté
  fscanf(f, "%s", chaine);
  fscanf(f, "%d", &oriente);

  //récupération value
  fscanf(f, "%s", chaine);
  fscanf(f, "%d", &value);

  //récupération "DEBUT_DEF_ARETES"
  fscanf(f, "%s", chaine);
  fscanf(f, "%s", chaine);

  g->l_adj = malloc(sizeof(Liste)*sommet); //alloc Liste / nb sommet

  g->m_adj = malloc(sizeof(int*)*sommet); //alloc matrice carrée
  
  for(int i=0; i<sommet; i++){
    g->m_adj[i] = malloc(sizeof(int)*sommet);
  }

  for(int i=0 ; i<sommet ; ++i){
    initialiser_liste(&g->l_adj[i]);
  }

  if(oriente != 0){
    while(strcmp(chaine, "FIN_DEF_ARETES") != 0){
      Cellule *c = malloc(sizeof(Cellule));
      fscanf(f, "%s", char_sommet);
      initCellule(c, atoi(char_sommet));
      j = atoi(chaine);
      inserer(&g->l_adj[j], c);
      fscanf(f, "%s", chaine);
    }
  }
  else{
    while(strcmp(chaine, "FIN_DEF_ARETES") != 0){
      Cellule *c = malloc(sizeof(Cellule));
      Cellule *c2 = malloc(sizeof(Cellule));
      fscanf(f, "%s", char_sommet);
      initCellule(c, atoi(char_sommet));
      j = atoi(chaine);
      inserer(&g->l_adj[j], c);
      initCellule(c2, atoi(chaine));
      j = atoi(char_sommet);
      inserer(&g->l_adj[j], c2);
      fscanf(f, "%s", chaine);
    }
  }

  g->nbSommet = sommet;
  g->oriente = oriente;
  g->value = value;
  fclose(f);

  //Remplissage de la matrice
  for(int i=0; i<sommet ; i++){
    for(int j=0; j<sommet; j++){
      if(rechercher(&g->l_adj[i], j)){
        g->m_adj[i][j] = 1;
      }
      else{
        g->m_adj[i][j] = 0;
      }
    }
  }
}

//affiche le Graphe
void afficher_graphe(Graphe *g){
  printf("Nombre de sommets : %d\n", g->nbSommet);

  if(g->oriente == 0) {printf("Non oriente\n");}
  else {printf("Oriente\n");}

  if(g->value == 0) {printf("Non value\n");}
  else {printf("Value\n");}

  //Listes d'adjacence
  printf("\nListe d'adjacences : \n");
  for(int i=0; i<g->nbSommet; i++){ 
    printf("%d -->", i);
    afficher_liste(&g->l_adj[i]);
  }

  //Matrice d'adjacence
  printf("\nMatrice d'adjacences : \n");
  for(int i=0; i<g->nbSommet; i++){
    for(int j=0; j<g->nbSommet; j++){
      printf(" %d", g->m_adj[i][j]);
    }
    printf("\n");
  }
}

//détruit le Graphe
void detruire_graphe(Graphe *g){
  printf("\n\nDestruction du Graphe !\n");
  for(int i=0; i<g->nbSommet; i++){
    detruire_liste(&g->l_adj[i]);
    free(g->m_adj[i]);
  }

  free(g->m_adj);
  g->nbSommet = 0;
  g->oriente = 0;
  g->value = 0;
}
