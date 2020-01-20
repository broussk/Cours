#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int saisie=0;
  char c[5];

  do{
    printf("Entrez un entier positif de 5 chiffres : ");
    scanf("%d",&saisie);
  }while((saisie<10000)||(saisie>99999));
  sprintf(c,"%d\n",saisie);
  printf("%s",c);

  return 0;
}
