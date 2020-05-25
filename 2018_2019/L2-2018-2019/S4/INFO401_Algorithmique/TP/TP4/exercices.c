#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "exercices.h"

#define NMAX 100
#define TEN 10
#define MAT 3

//Ecrire un algo qui calcule le complément d'image binaire
void ex1(){
  int A[MAT][MAT] = {{0,0,1},{1,0,0},{1,0,1}};
  int B[MAT][MAT];
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      if(A[i][j]==0){
        B[i][j] = 1;
      }
      else{
        B[i][j] = 0;
      }
    }
  }
  printf("A : \n");
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      printf("[%d] ",A[i][j]);
    }
    printf("\n");
  }
  printf("B : \n");
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      printf("[%d] ",B[i][j]);
    }
    printf("\n");
  }
}
//Calcul du maximum de 2 images binaires
void ex2(){
  int A[MAT][MAT] = {{0,0,1},{1,0,0},{1,0,1}}, B[MAT][MAT] = {{0,1,1},{0,0,0},{0,1,1}}, C[MAT][MAT];

  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      if(A[i][j]==0 && B[i][j]==0){
        C[i][j] = 0;
      }
      else{
        C[i][j] = 1;
      }
    }
  }
  printf("A : \n");
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      printf("[%d] ",A[i][j]);
    }
    printf("\n");
  }
  printf("B : \n");
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      printf("[%d] ",B[i][j]);
    }
    printf("\n");
  }
  printf("C : \n");
  for(int i=0 ; i<MAT ; i++){
    for(int j=0 ; j<MAT ; j++){
      printf("[%d] ",C[i][j]);
    }
    printf("\n");
  }
}
//Ecrire les algo récursifs
int factoriel(int n){
  if(n==0){
    return 1;
  }
  return n*factoriel(n-1);
}
int fibo(int n){
  if(n>=2){
    return fibo(n-1)+fibo(n-2);
  }
  else{
    return 1;
  }
}
int acker(int n, int m){
  if(n==0){
    return m+1;
  }
  else if(m==0){
    return acker(n-1,1);
  }
  else{
    return acker(n-1,acker(n,m-1));
  }
}
//Recherche d'un élément X dans un tableau déjà trié
int ex4(){
  int t[TEN] = {1,2,3,4,5,6,7,8,9,10};
  srand(time(NULL));
  int x = rand()%15, i=0, id=0,im,iend=TEN,trouve=0,retour;
  printf("x : %d\n",x);
  while(trouve!=1 && ((iend-id)>1)){
    im = (id+iend)/2;
    if(t[im] == x){
      trouve =1;
    }
    if(t[im]>x){
      iend = im;
    }
    else{
      id = im;
    }
    if(t[id]==x){
      retour = id+1;
    }
    else{
      retour = 0;
    }
  }
  return retour;
}
