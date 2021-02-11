#include <stdio.h>

int main(){

    double distance, essence, conso;
    printf("Entrez la distance parcouru et la quantite d'esence utilisee: \n");
    scanf("%lf %lf", &distance, &essence);

    conso = (essence * 100) / distance;
    printf("Consomation moyenne : %.2lf L/100km\n", conso);

    return 0;
}