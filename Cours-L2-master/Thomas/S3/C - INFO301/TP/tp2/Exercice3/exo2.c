#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

int a = 0;
printf("Entrez la valeur 1 :\n" );
scanf("%d", &a);
rewind(stdin);

if ((a%3==0) && (a%5 == 0)){
  printf("Divisible par 3 et 5\n");
}else{
  printf("Non Divisible par 3 ou 5\n" );
}
    return 0;
}
