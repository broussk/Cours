#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

long int nb = 0;

printf("Entrez une valeur\n" );
scanf("%ld", &nb );
printf("La valeur absolue est %ld \n", (nb<0)?-nb:nb);


    return 0;
}
