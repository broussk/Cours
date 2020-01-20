#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TAILLE 50

int main(){
  char chaine[TAILLE]="";
  int i=0;
  printf("Entrez chaîne : ");
  scanf("%s",chaine);
  while(chaine[i]!='\0'){
    if((chaine[i]<65 && chaine[i]>90)||(chaine[i]<97 && chaine[i]>122)){
      while(chaine[i]!='\0'){
        
      }
    }
    i++;
  }
  printf("Voici la chaine corrigée : %s",chaine);
  return 0;
}
