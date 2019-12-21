#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include "utils.h"

#define MAX 50

void ex1p1(){
  int test = 97, cpt=1, res=0, tmp=test, nbZero=0, nbUn=0;
  do{
    tmp = tmp/2;
    cpt++;
  }while((tmp/2)!=0);

  char *binaire = malloc(sizeof(char)*cpt);
  for(int i=cpt ; i>0 ; i--){
    if((test%2)==0){
      binaire[i] = '0';
      nbZero++;
    }
    else{
      binaire[i] = '1';
      nbUn++;
    }
    test = test/2;
  }
  for(int i=1 ; i<=cpt ; i++){
    printf("%c",binaire[i]);
  }
  printf("\nLongueur de la chaine : %d\nNombre de zéro : %d\nNombre de un : %d\n",cpt,nbZero,nbUn);
}

void ex1p2(){
  int length=0;
  do{
    printf("Entrez une longueur de tableau : ");
    scanf("%d",&length);
  }while(length<=0);
  int* tab1 = malloc(sizeof(int)*length);
  int* tab2 = malloc(sizeof(int)*length);
  for(int i=0 ; i<length ; i++){
    printf("Entrez la valeur pour la %dième case du tableau 1 : ",(i+1));
    scanf("%d",&tab1[i]);
    printf("Entrez la valeur pour la %dième case du tableau 2 : ",(i+1));
    scanf("%d",&tab2[i]);
  }
  showTabInt(tab1,length);
  showTabInt(tab2,length);

}
