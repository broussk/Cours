#include "student.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 25

void clean_stdin(void){
  int c;
  do{
    c = getchar();
  }while (c != '\n' && c != EOF);
}

void menu(){
  printf("==!== MENU ==!==\n\na) Saisir le nombres d'étudiants.\nb) Saisir les données des étudiants.\nc) Afficher le contenu du tableau trié selon le nom.\nd) Afficher les données du Major.\ne) Afficher la liste des étudiants ayant une moyenne supérieure ou égale à dix.\nf) Afficher le contenu du tableau trié selon la moyenne.\nAutre) EXIT\n\n==!== ==== ==!==\n");
}

void showTabStudent(int size, student*tab){
  for(int i=0 ; i<size ; i++){
    printf("%d",i);
    printf("\n*** Nom : %s\n*** Numéro étudiant : %d\n*** Âge : %d\n*** Moyenne : %.2f\n",tab[i].nam,tab[i].num_stu,tab[i].age_stu,tab[i].moy);
  }
}

int nbStudents(){
  int nb=0;
  do{
    printf("Entrez le nombre d'étudiants souhaité : ");
    scanf("%d",&nb);
    clean_stdin();
  }while(nb<=0);
  return nb;
}

void enterDataStudents(student *tab,int n){
  char *name;
  for(int i=0 ; i<n ; i++){
    // printf("\t[Saisie des données de l'étudiant n°%d]\n",(i+1));
    tab[i].nam = malloc(MAX);
    printf("\tEntrez le nom de l'étudiant : ");
    scanf("%s",tab[i].nam);
    clean_stdin();
    printf("\tEntrez son numéro étudiant : ");
    scanf("%d",&tab[i].num_stu);
    clean_stdin();
    printf("\tEntre l'âge de l'étudiant : ");
    scanf("%d",&tab[i].age_stu);
    clean_stdin();
    printf("\tEntrez la moyenne de l'étudiant : ");
    scanf("%f",&tab[i].moy);
    clean_stdin();
  }
}

int cmpstring(const void *p1, const void *p2)
{
  return strcmp(* (char * const *) p1.nam, * (char * const *) p2.nam);
}
