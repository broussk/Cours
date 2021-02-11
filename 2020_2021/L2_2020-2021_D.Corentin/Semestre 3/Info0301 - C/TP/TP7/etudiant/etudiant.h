#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <stdio.h>

typedef struct etudiant {
    char *nom;
    char *prenom;
    int num_etud;
    int age_etud;
    float Notes[10];
    float moyenne;
}etudiant;

void saisir(etudiant *);
void affichage_etudiant(etudiant);

#endif  /* ETUDIANT_H */
