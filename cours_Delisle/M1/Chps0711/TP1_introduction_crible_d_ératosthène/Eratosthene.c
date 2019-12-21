/*
	Crible d'Eratosthene
	Pierre Delisle
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b)  ((a)<(b)?(a):(b))

int main (int argc, char *argv[]) {
	int n;				/* Dernier nombre premier a verifier (2..n)*/
	int taille;			/* Taille du tableau de nombres premiers a verifier */
	int *marques;		/* Tableau permettant de marquer les nombres verifies */
	int indexMarques;	/* Index du nb premier courant dans le tableau "marques" */
	int premierCourant;/* Nombre premier courant */
	int compte;			/* Compteur de nombres premiers */
	int indDebut;		/* Indicateur de debut de marquage*/
	int i;
	
	if (argc != 2) {  /* Verifie que un seul argument a ete fourni */
		printf ("Usage : %s n\n", argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);

	taille = n - 1;

	marques = (int *) malloc (sizeof(int) * taille);
	for (i = 0; i < taille; i++)
		marques[i] = 0;

	indexMarques = 0;
	premierCourant = 2;
	do {
		indDebut = premierCourant * premierCourant - 2; 	/* Indice du 1er nombre a marquer (k2)*/
		for (i = indDebut; i < taille; i+= premierCourant) /* Pour tous les multiples du nb premier, */
			marques[i] = 1;											/* on marque le nombre*/

		while (marques[++indexMarques]);  		/* On trouve l'indice de la prochaine case non marquee */
			premierCourant = indexMarques + 2;  /* ce qui donne le nb premier du prochain tour */

	} while (premierCourant * premierCourant <= n);  /* On arrete si son carre est > que n*/

	compte = 0;
	for (i = 0; i < taille; i++)
		if (!marques[i])
			compte++;

	printf("Il y a %d nombres premiers plus petits ou egaux a %d\n", compte, n);
	printf("Ces nombres sont : ");
	for (i = 0; i < taille; i++)
		if (!marques[i])
			printf("%d ", i+2);
	printf("\n");

	free (marques);
   return 0;
}
