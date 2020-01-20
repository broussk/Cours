#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[])
{

int a=0;

printf("Entrez une valeur positive et inférieur à 70\n");
scanf("%d",&a);

if (a<0 || a>70){
  printf("Erreur ! \n" );
}

    return 0;
}
