#ifndef NOEUD_H
#define NOEUD_H
using namespace std;

#include <iostream>
#include <ostream>

class Noeud{
protected:
  int n; //étiquette du noeud
  int couleur;
  Noeud *fg;
  Noeud *fd;
public:
  //Constructeurs
  Noeud();                                                                      //Constructeur par défaut
  Noeud(int nb,int couleur);

  //Destructeur                                                                 //Constructeur par init
  Noeud *videSousArbre();

  //Test
  bool noeud_vide();
  bool est_fils(Noeud *pere);
  bool est_pere(Noeud *fils);
  bool appartient(int nb);

  //Infos
  Noeud *fils_gauche();
  Noeud *fils_droit();
  int etiquette();                                                              //Retourne -1 si le noeud est vide
  int etiquette_fg();
  int etiquette_fd();
  int hauteur();
  int cardinal();
  int max();
  int min();

  //Opérations
  int etiquette(Noeud *pere, int nb);
  void insertion(int nb);
  Noeud *recherche(int nb);
  Noeud *recherche(int *t, int taille);
  Noeud *recherche_max();
  Noeud *recherche_pere(int nb);
  void supprime(int nb);
  void supprime_racine();

  //Affichage
  void affichage_sous_arbre();
  void affichage_sous_arbre_1();

  friend ostream& operator<<(ostream& o, Noeud n);

  //estRouge
    bool estRouge(Noeud n);
};

#endif /*NOEUD_H*/
