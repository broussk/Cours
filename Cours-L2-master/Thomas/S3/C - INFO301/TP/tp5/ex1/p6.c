#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TAILLE 50

int main(){
  char ch1[TAILLE]="";
  char ch2[TAILLE]="";
  int i =0,j=0,ok=-1,memoire=0;
  printf("Entrez une première chaîne : ");
  scanf("%s",ch1);
  printf("Entrez un mot : ");
  scanf("%s",ch2);
  while(ch1[i]!=0){
    if(ch1[i]==ch2[j]){
      memoire = i;
      while((ch1[i]==ch2[j])&&(ch1[i]!='\0')&&(ch2[j]!='\0')){
        ok=1;
        i++;
        j++;
      }
        ok=memoire;
    }
    else{
      i++;
    }
  }
  if(memoire>=0){
    printf("Le mot %s se trouve à la lettre %d du mot %s.\n",ch2,memoire+1,ch1);
  }
  else{
    printf("Le mot %s ne se trouve pas dans %s",ch2,ch1);
  }
  return 0;
}
