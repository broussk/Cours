#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

char c;
char d;
printf("Merci de saisir un premier caractère :" );
scanf("%c", &c );
rewind(stdin); // permet de supprimer le retour chariot
printf("Le caractere saisi est '%c' et son code ascii est %d\n",c,(int)c);
printf("Merci de saisir un deuxieme caractère :" );
scanf("%c", &d );
printf("Le caractere saisi est '%c' et son code ascii est %d\n",d,(int)d);


    return 0;
}
