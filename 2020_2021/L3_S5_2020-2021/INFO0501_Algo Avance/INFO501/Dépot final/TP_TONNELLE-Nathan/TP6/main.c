/*
 * TONNELLE Nathan
 * 06-11-2020
 * 13-11-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "liste.h"

/*//  main pour les fichiers
int main(int argc, char *argv[]){
    //liste
    Liste listeMots;
    initialiser_liste_fichier(&listeMots, argv[1]);

    //affichage de la liste
    printf("Affichage de la liste : \n");
    afficher_liste(&listeMots);
    printf("\n taille liste : %d\n", listeMots.taille);

    return 0;
}
*/

//  test mots perso
int main(int argc, char *argv[]){

    //chaines de caractères
    char chaine1[] = "Bonjour";
    char chaine2[] = "Salut";
    char chaine3[] = "Hey";
    char chaine4[] = "Yop";
    char chaine5[] = "Salutation";
    char chaine6[] = "Hey";

    //liste
    Liste listeMots;
    initialiser_liste(&listeMots);

    //cellules
    Cellule *c1 = malloc(sizeof(Cellule));
    Cellule *c2 = malloc(sizeof(Cellule));
    Cellule *c3 = malloc(sizeof(Cellule));
    Cellule *c4 = malloc(sizeof(Cellule));
    Cellule *c5 = malloc(sizeof(Cellule));
    Cellule *c6 = malloc(sizeof(Cellule));

        //initialisation des cellules
    initCellule(c1, chaine1);
    initCellule(c2, chaine2);
    initCellule(c3, chaine3);
    initCellule(c4, chaine4);
    initCellule(c5, chaine5);
    initCellule(c6, chaine6);

    printf("initialisation des variables ... Terminé\n");

    //insertion des chaines dans la liste
    inserer(&listeMots, c1);
    inserer(&listeMots, c2);
    inserer(&listeMots, c3);
    inserer(&listeMots, c4);
    inserer(&listeMots, c5);
    printf("\ninsertion des chaines ... Terminé\n");

    printf("\nAffichage des chaines :");
    printf("\n\t %s", chaine1);
    printf("\n\t %s", chaine2);
    printf("\n\t %s", chaine3);
    printf("\n\t %s", chaine4);
    printf("\n\t %s \n", chaine5);

    //affichage de la liste
    printf("\nAffichage de la liste : \ttaille : %d\n\t", listeMots.taille);
    afficher_liste(&listeMots);

    //recherche d'un mot dans la liste
    char chaineRecherche[] = "Bonjour";
    printf("\nRecherche du mot : \"%s\" dans la liste : \t %s\n", chaineRecherche, rechercher(&listeMots, chaineRecherche)->chaine);

    //supprimer dans la liste
    char chaineSupprimee[] = "Prout";
    printf("\nSuprimer le mot : \"%s\" de la liste\n", chaineSupprimee);
    supprimer(&listeMots, chaineSupprimee);
    printf("\nAffichage de la liste : \ttaille : %d\n\t", listeMots.taille);
    afficher_liste(&listeMots);


    printf("\nInsertion d'un mot déjà compris dans la liste : %s\n", chaine6);
    inserer(&listeMots, c6);

    return 0;
}