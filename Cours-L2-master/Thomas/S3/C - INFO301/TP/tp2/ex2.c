#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void viderBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
  int a,b=0;

  // long int val=0;
  // printf("Entrez une valeur longue > ");
  // scanf("%ld",&val);
  // printf("Valeur absolue de %ld : %ld\n",val, (val < 0) ? -val:val);

  // printf("Entrez une valeur > ");
  // scanf("%d",&a);
  // printf("C'est un nombre %s\n",(a%2) ? "impair" : "pair");

  // printf("Entrez la valeur 1 et 2 séparées par un espace > ");
  // scanf("%d %d",&a,&b);
  // printf("Le max de %d et %d est %d\n",a,b,(a>b)? a : b);
}
