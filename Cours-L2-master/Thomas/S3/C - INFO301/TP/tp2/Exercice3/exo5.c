#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
int annee=0;

printf("Entrez une année : \n");
scanf("%d",&annee);

if ((annee%4 == 0) && (annee%100 != 0)){
  printf("Année bisextille\n");
} else {
  printf("Année non bisextille\n");
}

    return 0;
}
