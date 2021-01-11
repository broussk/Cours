#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SPIN			1000000

int compteur = 0;

int main(int argc, char *argv[]) {
	int i, diffTemps;
	time_t temps1, temps2;

	temps1 = time(NULL);
	for (i = 0; i < SPIN; i++)
		compteur++;
	temps2 = time(NULL);
	diffTemps = (int) temps2 - (int) temps1;
	printf("Valeur finale du compteur : %d\n", compteur);
	printf("Temps : %d secondes\n", diffTemps);

	return 0;
}
