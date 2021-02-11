#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * fichier1, * fichier2;
    char c, c2;
    int nb = 0;
    char line[100];

    printf("COPIE EN COURS ...\n");
    fichier1 = fopen("fichier_source.txt", "r");
    fichier2 = fopen("fichier_destination.txt", "w");

    if (fichier1 == NULL) {
        printf(" Erreur d'ouverture du fichier!");
        exit(1);
    } 
    

    while ((c = (char) getc(fichier1)) != EOF){
        nb++;
        putc(c, fichier2);
    }


    fclose(fichier1);
    fclose(fichier2);
    printf("C'EST FINI !\n");

    printf("\nNombre de caractères du fichier texte: %d", nb);
    return 0;
}