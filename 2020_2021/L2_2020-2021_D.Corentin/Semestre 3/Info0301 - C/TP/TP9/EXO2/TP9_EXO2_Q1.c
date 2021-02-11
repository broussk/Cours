#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


void readFile(){
    FILE * file;
    int age = 0, cp = 0;
    char nom[MAX], prenom[MAX], rue[MAX], ville[MAX];

    file = fopen("personne.txt", "r");

    fscanf(file, "%s %s %d %s %d %s", nom, prenom, &age, rue, &cp, ville);

    printf("%s %s %d %s %d %s", nom, prenom, age, rue, cp, ville);

    fclose(file);
}


int main() {
    readFile();
    return 0;
}