#ifndef _ARBRE_H_
#define _ARBRE_H_

#include "noeud.h"

#define VIDE ((Noeud *)0)

//      ######################
//      ##                  ##
//      ##      ARBRE :     ##
//      ##                  ##
//      ######################

// NB : aucun doublon !!!

class Arbre{

    Noeud *racine;

public:

    Arbre();
    Arbre(Noeud *n);
    void videArbre();
    bool vide();
    int hauteur();
    int cardinal();
    int etiquette();
    void insertion(int nb);
    bool appartient(int nb);
    Noeud *recherche(int nb);
    Noeud *recherche_pere(int nb);
    int max();
    int min();
    void supprime(int nb);

    void affiche_arbre();           // fonctionne uniquement sur Windows...
    void affiche_arbre_1();         // ancienne version
    friend ostream& operator<<(ostream& o, Arbre a);

};

#endif
