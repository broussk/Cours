#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "exercices.h"

#define NMAX 100
#define TEN 10

void ex1(){
  char *CH = "test";
  int *P=CH;
  for(int i=0 ; i!=EOF ; i++){
    P++;
  }
  int n = P-*CH;
  printf("Longueur : %d",n);
}
void ex2(){
  int A[NMAX]={0}, B[NMAX]={0}, *PA, *PB, N=0, M=0;
  srand(time(NULL));

  printf("Entrez N : ");
  scanf("%d",&N);
  do{
    if(M>NMAX-N){
      printf("Depassement de tableau\n");
    }
    printf("Entrez M : ");
    scanf("%d",&M);
  }while(M>NMAX-N);
  for(int i=0 ; i<N ; i++){
    A[i] = rand()%51;
  }
  for(int i=0 ; i<M ; i++){
    B[i] = rand()%51;
  }
  printf("Tableau A : \n");
  for(int i=0 ; i<N; i++){
    printf("%d.[%d]\n",(i+1),A[i]);
  }
  printf("Tableau B : \n");
  for(int i=0 ; i<M ; i++){
    printf("%d.[%d]\n",(i+1),B[i]);
  }
  for(int i=0 ; i<M ; i++){
    *(A+N+i) = *(B+i);
  }
  printf("Tableau A + B : \n");
  for(int i=0 ; i<N+M ; i++){
    printf("%d.[%d]\n",(i+1),A[i]);
  }
}
void ex3(){
  srand(time(NULL));
  int A[TEN]={0}, x=rand()%10, *P1=A, *P2=A, i=0, j=0;
  for(int i=0 ; i<TEN ; i++){
    A[i] = rand()%10;
  }
  printf("x = %d\nTableau A : \n",x);
  for(int i=0 ; i<TEN ; i++){
    printf("[%d] | ",A[i]);
  }

  for(int i=0 ; i<TEN ; i++){
    *P1=*P2;
    if(*P2!=x){
      P1++;
    }
    P2++;
  }
  printf("\nTableau A sans %d : \n",x);
  for(int i=0 ; i<(P1-A) ; i++){
    printf("[%d] | ",A[i]);
  }
}

