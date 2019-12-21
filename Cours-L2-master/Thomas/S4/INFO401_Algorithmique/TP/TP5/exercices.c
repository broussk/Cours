#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "exercices.h"
#define T 5
#define TCOLOR 9
#define FAST 20
#define V 6

void ex1(){
  int tab[T] = {10,4,22,25,3};
  tri_bulles(tab,T);
  for(int i=0 ; i<T ; i++){
    printf("[%d].%d ",i,tab[i]);
  }
}
void ex2(){
//Bleu = 1 | Blanc = 2 | Rouge = 3
  int tab[TCOLOR] = {1,3,2,2,3,1,2,3,1};
  int i=1,j=1,k=TCOLOR,temp;
//Affichage avant
  for(int x=0 ; x<TCOLOR ; x++){
    printf("%d ",tab[x]);
  }
  printf("\n");
//Tri
  while(j<=k){
    if(tab[j]==2){
      j++;
    }
    else if(tab[j]==1){
      temp = tab[i];
      tab[i] = tab[j];
      tab[j] = temp;
      i++; j++;
    }
    else{
      temp = tab[j];
      tab[j] = tab[k];
      tab[k] = temp;
      k--;
    }
  }
//Affichage après
  for(int x=0 ; x<TCOLOR ; x++){
    printf("%d ",tab[x]);
  }
}
void ex3(){
  int tab[20] = {2,11,10,16,4,3,7,18,19,1,14,13,8,20,17,12,5,9,15,6};
  FastSort(tab,FAST);
  for(int i=0 ; i<FAST ; i++){
    printf("%d ",tab[i]);
  }
}
void ex4(){
  //Algo calcul vecteur OTD matrice
  int mat[V][V] = {{0,1,0,0,0,0},{0,0,1,1,0,0},{0,0,0,0,1,0},{0,0,1,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0}};
  int vm[V]={0}, vp[V]={0};
  int i,j,k;
  for(i=0 ; i<V ; i++){
    for(j=0 ; j<V ; j++){
      if(mat[i][j]==1){
        vp[i]++; vm[j]++;
      }
    }
  }

  printf("Matrice : \n");
  for(int x=0 ; x<V ; x++){
    for(int y=0 ; y<V ; y++){
      printf("%d ",mat[x][y]);
    }
    printf("\n");
  }
  printf("\nVecteur plus \n");
  for(int x=0 ; x<V ; x++){
    printf("%d ",vp[x]);
  }
  printf("\nVecteur moins \n");
  for(int x=0 ; x<V ; x++){
    printf("%d ",vm[x]);
  }

  //Algo tri topologique matrice
  void Tritopo(int *tableau, int taille){
      i=0;
  for(j=0;j<taille;j++){
    if(V[j]==0){
      V[j]--;
      L[i]=j+1;
      i++;
    }
    for(k=0;k<6;k++){
      if(G[j][k]==1){
        V[k]--;
      }
    }
  }

  for(i=0;i<5;i++){
    printf("L[%d]=%d\n",i,L[i]);
  }

}

  printf("\nVecteur moins apres : \n");
  for(int x=0 ; x<V ; x++){
    printf("%d ",vm[x]);
  }
}

//Tri rapide
void FastSort(int *tableau, int taille) {
  int mur, courant, pivot, tmp;
  if (taille < 2) return;
// On prend comme pivot l element le plus a droite
    pivot = tableau[taille - 1];
    mur  = courant = 0;
    while (courant<taille) {
      if (tableau[courant] <= pivot) {
        if (mur != courant) {
          tmp=tableau[courant];
          tableau[courant]=tableau[mur];
          tableau[mur]=tmp;
        }
        mur ++;
      }
      courant ++;
    }
  FastSort(tableau, mur - 1);
  FastSort(tableau + mur - 1, taille - mur + 1);
}

//Tri à bulles
void tri_bulles(int tab[],int taille){
  int temp,tabOrdered=0;
  while(!tabOrdered){
      tabOrdered = 1;
      for(int i=0 ; i<taille-1 ; i++){
        if(tab[i]>tab[i+1]){
          temp = tab[i];
          tab[i] = tab[i+1];
          tab[i+1] = temp;
          tabOrdered = 0;
        }
      }
      taille--;
  }
}

//Tri Hollandais
