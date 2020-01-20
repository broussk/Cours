#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

int a,b,c=0;
printf("Entrez la valeur 1 :\n" );
scanf("%d", &a);
rewind(stdin);
printf("Entrez la valeur 2 :\n" );
scanf("%d", &b );
rewind(stdin);
printf("Entrez la valeur 3 :\n" );
scanf("%d", &c );
rewind(stdin);

int t = ((a+b+ abs(a-b)))/2;
int max = ((t+c + abs(t-c)))/2;

printf("Le max est %d\n", max );

    return 0;
}
