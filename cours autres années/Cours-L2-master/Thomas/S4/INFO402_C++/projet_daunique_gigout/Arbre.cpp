using namespace std;
// includes standards
#include <iostream>
#include <ostream>
#include <initializer_list>
#include <cassert>

// includes perso
#include "arbre.hpp"


//Constructeur
    //par défault
Arbre::Arbre(){
  racine = nullptr;
}
    //Avec un noeud (arbre déjà creer) et l'on identifie le noeuds comme racine
//A vérifier
Arbre::Arbre(Noeud *n){
  racine = n;
}
    //Avec initialisation de la taille
//A faire
Arbre::Arbre(size_t taille){

}
    //Par copie
//A vérifier
Arbre::Arbre(const Arbre& a){
  cout << "Constructeur par copie." << endl;
  racine = a.racine;
}
    //Par déplacement
//A vérifier
Arbre::Arbre(Arbre&& a){
    cout << "Constructeur par déplacement." << endl;
  racine = a.racine;
}
    //Par liste
//A vérifier
Arbre::Arbre(const initializer_list<Noeud> &liste){
  racine = new Noeud[liste.size()];
  int i=0;
  for(const Noeud& l:liste){
    racine[i++]=l;
  }
}

    //par Range
//A vérifier
Arbre(Iterator* a.debut(),Iterator* a.fin()){
    for(Arbre::iterator i=a.debut() ; i!=a.fin() ; i++){
    insertion(&a.debut);
    }
}
//Assignation
    //Par copie
Arbre& operator=(const Arbre& a){
  if(this!=a){
    for(Arbre::iterator i=a.begin() ; i!=a.end() ; i++){
      racine[i] = a.racine[i];
    }
  }
  return *this;
}

//insertion
  //à tester
void Arbre::insertion(int nb){
  if(vide()){
    racine=new Noeud(nb);
  }else{
    return(racine->appartient(nb));
  }
}
//Test si VIDE
  //à tester
bool Arbre::vide() {
    if(racine == nullptr){
       return true;
     }else return false;
}
//Test Pour Set si un nombre appartient déjà au tableau
  //à tester
bool Arbre::appartient(int nb){
    if(vide()){
        return false;
      }else return( racine->appartient(nb) );
}
////////////////////////////////////////////////////////////////////////////////
