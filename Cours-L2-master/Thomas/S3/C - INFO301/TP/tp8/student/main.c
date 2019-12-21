#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  student *tabStudents;
  char *listChoice="abcdef";
  char choice;
  int nbStuds=0,n=0;
  student s;

  do{
    n = sizeof(tabStudents);
    printf("Nombres d'étudiants : %d\n",nbStuds);
    menu();
    scanf("%c",&choice);
    clean_stdin();
    switch(choice){
      case 'a': // Saisir nb étudiants
        nbStuds = nbStudents();
      break;
      case 'b': // Saisir données étudiants
      if(nbStuds<=0){
        printf("\n\tLe système ne connait pas le nombre d'étudiants.\n\n");
        break;
      }
        tabStudents = malloc(sizeof(student)*nbStuds);
        enterDataStudents(tabStudents,nbStuds);
      break;
      case 'c': // Afficher contenu tableau trié / nom
        printf("Tableau avant tri : \n");
        showTabStudent(nbStuds,tabStudents);
        qsort(&tabStudents,nbStuds-1,sizeof(student),cmpstring);
        printf("\nTableau après tri : \n");
        showTabStudent(nbStuds,tabStudents);
      break;
      case 'd': // Afficher données Major

      break;
      case 'e': // Afficher liste étudiants w/ moy >= 10

      break;
      case 'f': // Afficher contenu tableau trié / moy

      break;
      default:
        printf("\nMerci d'avoir utilisé notre logiciel !\nÀ bientôt\n");
      break;
    }
  }while(strchr(listChoice,choice)!=NULL);
  return 0;
}
