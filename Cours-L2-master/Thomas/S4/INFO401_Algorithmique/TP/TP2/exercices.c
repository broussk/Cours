#include <stdio.h>
#include <string.h>
#include "exercices.h"

//Suite de fibonacci
void ex1b(){
  //Fibonacci avec la formule
  //initialisation des paramètre initiaux d'une suite de Fibonacci
    /*entier long tableau F alloué 90
    F[0]<-0
    F[1]<-1
    pour i allat de 2 à 90 faire
    F[i]<-F[i-1]+F[i-2]
    i++
    Fin Pour
    Fin*/
  long long F[90];
  F[0] = 0;
  F[1] = 1;
  //
  for(int i=2; i<90 ; i++){
    F[i] = F[i-1] + F[i-2];
  }

  printf("Valeurs suite de Fibonacci sur 90 valeurs (formule) : \n");
  for(int i=0 ; i<90 ; i++){
    printf("[%d]\t%lld\n",i,F[i]);
  }
}
//Suite de Fibonacci avec 3 variables
/*entier long tableau F alloué 90
initialisation
x<-0
y<-1
z<-x+y
F[0]<-x
F[1]<-y

Pour i allant de 2 à 90 faire
F[i]<-z
y<-z
z<-x+y
Fin pour
afficher( Valeurs Fibo avec 3 variables)
pour i allant de 0 à 90 faire
afficher(F[i])
Fin
*/
void ex1c(){
  long long F[90];
  long long x=0, y=1, z=x+y;
  F[0] = x;
  F[1] = y;
  for(int i=2 ; i<90 ; i++){
    F[i] = z;
    x = y;
    y = z;
    z = x+y;
  }

  printf("\nValeurs suite de Fibonacci sur 90 valeurs (3variables) : \n");
  for(int i=0 ; i<90 ; i++){
    printf("[%d]\t%lld\n",i,F[i]);
  }
}
//Normalisation d'un tableau d'int
/*
allocation d'un tableau réel t avec pour valeur {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}
x<-0
pour i allant de 0 à 25
t[i]<- t[i]-1
Fin Pour
pour i allant de 0 à 25 faire
Si t[i]>max alors
max<-t[i]
Fin si
Fin Pour
Afficher max
Pour i allant de 0à 25 faire
t[i]<-t[i]/max
Fin Pour
Fin
*/
void ex3(){
  double t[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
  int max = 0;
  //Normalisation échelle [0;1]
  for(int i=0 ; i<25 ; i++){
    t[i] -= 1;
  }
  //Recherche du max;
  for(int i=0 ; i<25 ; i++){
    if(t[i]>max){
      max = t[i];
    }
  }
  printf("%d\n",max);
  for(int i=0 ; i<25 ; i++){
    t[i] /= max;
  }
  //Affichage tableau normalisé échelle 0;1
  printf("Tableau normalise a echelle [0;1]\n\n");
  for(int i=0 ; i<25 ; i++){
    printf("[%d]\t %f\n",i,t[i]);
  }
}
//conversion (10)->(2)
/*
initialisation
entier dec<-0 , i<-0 , t allouer (40) ,j<-0
afficher*/
void ex4(){
  int dec=0,i=0,t[40],j=0;;
  printf("Entrez la valeur decimale : ");
  scanf("%d",&dec);
  if(dec==0){
    printf("0");
  }
  else{
    while(dec>0){
      t[i]=dec%2;
      dec=dec/2;
      i++;
    }
    for(j=(i-1);j>=0;j--){
      printf("%d",t[j]);}
  }
}
//Recherche d'un nombre parfait
void ex5(){
  int nb=0,s=0;

  printf("Test du nombre parfait\n\nEntrez un nombre a tester : ");
  scanf("%d",&nb);
  for(int i=1 ; i<=(nb/2) ; i++){
    if((nb%i)==0){
      s+=i;
    }
  }
  if(s==nb){
    printf("Nombre parfait !");
  }
  else{
    printf("Ce nombre n'est pas parfait...");
  }
}
//fusion de tableaux triés
void ex2(){
  int t1[5] = {1,2,5,6,8}, t2[5] = {2,3,5,7,9}, t3[10] = {0}, i=0,j=0,k=0;

  for(k=0 ; k<10 ; k++){
    if(t1[i]<t2[j]){
      t3[k] = t1[i];
      i++;
    }
    else{
      t3[k] = t2[j];
      j++;
    }
  }
  for(i=0 ; i<5 ; i++){
    printf("t1[%d]\t%d\tt2[%d]\t%d\n",i,t1[i],i,t2[i]);
  }
  printf("\n");
  for(i=0 ; i<10 ; i++){
    printf("t3[%d]\t%d\n",i,t3[i]);
  }
}
