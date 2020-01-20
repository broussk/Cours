#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

double max,a,b=0;

printf("Entrez la valeur 1 et 2:\n");
scanf("%lf %lf", &a , &b);
max = a>b? a:b;
printf("Max est %lf\n", max );


    return 0;
}
