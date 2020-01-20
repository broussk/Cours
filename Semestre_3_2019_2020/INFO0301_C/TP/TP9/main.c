#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fichier1, *fichier2;
    char c;
    int compteur=0;

    printf("COPIE EN COURS ...\n");

    fichier1 = fopen("fichier_source.txt","r");
    fichier2 = fopen("fichier_destination.txt","w");

    if (fichier1 == NULL){
        printf("Erreur d'ouverture du fichier!");
        exit(1);
    }

    while ((c=(char)getc(fichier1))!=EOF)putc(c,fichier2);
    while(fgetc(fichier1)!=EOF){
        compteur+=1;
    }

    fclose(fichier1);
    fclose(fichier2);
    printf("C'EST FINI !\n");
    printf("Nombre de caractères : %d",compteur);

    return 0;
}