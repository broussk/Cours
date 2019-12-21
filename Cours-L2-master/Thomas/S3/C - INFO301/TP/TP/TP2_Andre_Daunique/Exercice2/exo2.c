#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

int nombre = 0;
printf("Entrez un nombre :\n" );
scanf("%d", &nombre );
printf("C'est un nombre %s\n", nombre%2?"impair":"pair");

    return 0;
}
