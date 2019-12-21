#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

int a,b,c=0;
printf("Entrez la longueur numéro 1 : \n");
scanf("%d",&a);
printf("Entrez la longueur numéro 2 : \n");
scanf("%d",&b);
printf("Entrez la longueur numéro 3 : \n");
scanf("%d",&c);

if ( (a==b) && (a==c) && (c==b)){
  printf("Triangle équilatéral\n" );
}else if ((a==b) || (a==c) || (c==b)){
  printf("Triangle isocèle\n");
} else {
  printf("Triangle scalène\n");
}
    return 0;
}
