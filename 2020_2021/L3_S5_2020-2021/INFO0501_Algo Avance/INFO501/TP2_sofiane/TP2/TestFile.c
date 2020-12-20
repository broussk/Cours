#include <stdio.h>
#include <stdio.h>
#include "file.h"
#include "sommet.h"

int main(void){
    

    File *f = malloc(sizeof(Sommet));

    Sommet *s1 = malloc(sizeof(Sommet));
    Sommet *s2 = malloc(sizeof(Sommet));
    init_sommet(s1);
    s1->id = 0;
    init_sommet(s2);
    s2->id = 7;

    initialiser_file(f);

   if(file_vide(f)){
       printf("File vide");
   }else{
       printf("File non vide");
   }

   printf("\n");

   printf("Taille de la file : %d\n",file_taille(f));

   afficher_file(f);

   enfiler(f,s1);
   enfiler(f,s2);

   afficher_file(f);

   if(file_pleine(f)){
       printf("File pleine");
   }else{
       printf("File non pleine");
   }

   printf("\n");

   defiler(f);

   afficher_file(f);

   detruire_file(f);

   afficher_file(f);
   

  Graph *g = malloc(sizeof(Graph));
  
  initialiser_graphe(g,"graphe2.txt");

  afficher_graphe(g);
  detruire_graphe(g);
  //ParcoursLargeur(g,s1);
  parcours_profondeur_recursif(g);
  
  afficher_chemin(g,s1,s2);
  //visiter_pp(g,s1);
  afficher_parcours_profondeur(g,s1);

    return 0;
}