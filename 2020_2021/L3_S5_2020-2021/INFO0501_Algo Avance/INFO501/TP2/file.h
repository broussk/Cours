/*
 * TONNELLE Nathan
 * 02-10-2020
*/

#ifndef FILE_H
#define FILE_H
#include "sommet.h"

typedef struct file file;
struct file{
  sommet *sommet;
  int *tete;
  int *queue;
};

//initialise une file vide de capacité maximale fixe
void initialiserFile(file *); 
//détruit une file, libère ses ressources mémoires
void detruireFile(file*); 
//retourne  0 si vide (vrai)
//          1 si non vide (faux)
int fileVide(file*); 
//retourne  0 si pleine (vrai)
//          1 sinon (faux)
int filePleine(file*); 
//ajoute un sommet en queue de file
void enfiler(file*, sommet*); 
//enlève le sommet en tête de file s'il en existe et retourne sa valeur
sommet* defiler(file*); 

#endif //FILE_H