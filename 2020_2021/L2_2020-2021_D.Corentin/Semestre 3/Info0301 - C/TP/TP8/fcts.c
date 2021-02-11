#include "fcts.h"
#include <stdio.h>
#include <string.h>

int main(){
    return 1;
}

int choix_menu(){
	int ok;
	int choix;
	ok = 0;
	while (!ok){
		printf("Choix (1 ou 2):\n");
		scanf("%d", &choix);
		ok = ((choix == 1) || (choix == 2));
	}
	return choix;
}

void lire_data(char txt[]){
	printf("Saisir une chaine de 5 caractères exactement: \n ") ;
    scanf("%s", txt);
}


void print_data(char txt[]){
	printf("Voici le résultat : ");
	printf("%s\n", txt);
}

int lire_dec(){
	int dec;
	printf("Donner un entier :\n");
	scanf("%d", &dec);
	dec = dec % 4;
	return dec;
}