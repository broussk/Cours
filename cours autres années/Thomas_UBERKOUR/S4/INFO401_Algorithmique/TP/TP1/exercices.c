#include <stdio.h>
#include <string.h>
#include "exercices.h"

int isPalindrome(char *c){
  int size = strlen(c);
  int retour=0;
  for(int i=0 ; i<size/2 ; i++){
    if(c[i]==c[size-i-1]){
      retour=1;
    }
    else{
      retour=0;
    }
  }
  return retour;
}
void compteur(int tab[], int n){
  int count=0, max=0, top=0;
  for(int i=1 ; i<8 ; i++){
    for(int j=0 ; j<n ; j++){
      if(i==tab[j]){
        count++;
      }
    }
    printf("%d %d %d\n",max,i,count);
    if(count>max){
      max = count;
      top = i;
    }
    count = 0;
  }
  printf("%d",top);
}
void ex1(){
  char *c1 = "ELLE";
  char *c2 = "LAVAL";
  char *c3 = "TAMER";

  printf("%s palindrome ? ",c1);
  if(isPalindrome(c1)==1){
    printf("Oui\n");
  }
  else{
    printf("Non\n");
  }
  printf("%s palindrome ? ",c2);
  if(isPalindrome(c2)==1){
    printf("Oui\n");
  }
  else{
    printf("Non\n");
  }
  printf("%s palindrome ? ",c3);
  if(isPalindrome(c3)==1){
    printf("Oui\n");
  }
  else{
    printf("Non\n");
  }
}
void ex2(){
  int t[26] = {1,1,2,2,3,3,3,3,3,4,4,5,5,5,5,5,5,5,5,5,5,6,7,7,7,7};
  int t2[33] = {3,1,1,5,5,5,1,1,6,6,1,5,5,3,3,3,7,7,7,7,2,2,1,1,6,5,7,3,3,4,4,1,4};
  compteur(t,26);
  printf("\n\n");
  compteur(t2,33);
}
void ex3(){
  int t[11] = {-2,1,3,6,-15,10,11,-4,6,5,9};
  int i,j,k,deb,fin,max=0,count=0;
  for(i=0;i<11;i++){
    if(t[i]>0){
      j=i;
      k=i;
      while((count+t[k]>0) && (k<11)){
        count+=t[k];
        k++;
      }
      if(count>max){
        max=count;
        deb=j+1;
        fin=k;
      }
      count=0;
    }
  }
  printf("%d %d %d\n",max,deb,fin);
}
void ex4(){
  int m1[3][3] = {{1,2,3},{4,5,6},{7,8,9}}
  int m2[3][3] = {{2,2,2},{2,2,2},{2,2,2}}
  int m3[3][3];
  for(int i=0 ; i<3 ; i++){
    for(int j=0 ; j<3 ; j++){
      m[i][j] = m1[i][j]*m2[i][j]+m1[i+1][j]*m2[i][j+1]
    }
  }
}
