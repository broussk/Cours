#include "etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisir(etudiant * e){
    
    int i;
    char tab[100];
    char tab2[100];
    float notes[10];
    float somme;

    somme = 0;

    printf("Nom: ");
    scanf("%s",tab);

    e->nom = malloc(sizeof(char) * (strlen(tab) + 1));
    strcpy(e->nom, tab);

    printf("Prenom: ");
    scanf("%s",tab2);
    e->prenom = malloc(sizeof(char) * (strlen(tab2) + 1));
    strcpy(e->prenom, tab2);

    
    for (i=0; i<10; i++){
        do{
        printf("Note %d:", i + 1);
        scanf("%f", &(e->Notes[i]));
        somme += e->Notes[i];
        } while (e->Notes[i] < 0 || e->Notes[i] > 20); 
    }

    e->moyenne = (somme/10);
    

    printf("Numero etudiant: ");
    scanf("%d",&(e->num_etud));

    printf("Age: ");
    scanf("%d",&(e->age_etud));

    
    printf("\n");

}


void affichage_etudiant(etudiant e){
    printf("- Nom: %s\n- Prenom: %s\n- Numero: %d\n- Age: %d\n -Moyenne: %.2f", e.nom, e.prenom, e.num_etud, e.age_etud, e.moyenne);
}
