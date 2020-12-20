/*
 * TONNELLE Nathan
 * 02-10-2020
 * 06-10-2020
 * 07-10-2020
*/

#ifndef FILE_H
#define FILE_H
#include "Sommet.h"

typedef struct File File;
struct File{
  Sommet *sommet;
  Sommet *tete;
  Sommet *queue;
  int value;
  int longueur;
  Sommet *suivant;
};

//initialise une File vide de capacité maximale fixe
void initialiserFile(File *); 
//détruit une File, libère ses ressources mémoires
void detruireFile(File*); 
//retourne  0 si vide      1 si non vide
int fileVide(File*); 
//retourne  0 si pleine    1 si non pleine
int filePleine(File*); 
//ajoute un Sommet en queue de File
void enfiler(File*, Sommet*); 
//enlève le Sommet en tête de File s'il en existe et retourne sa valeur
Sommet* defiler(File*); 
//affiche la file
void afficherFile(File*);
//retourne la taille de la file
int tailleFile(File*);

#endif //FILE_H