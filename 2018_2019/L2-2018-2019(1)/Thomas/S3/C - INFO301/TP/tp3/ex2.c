#include <stdio.h>
#include <limits.h>
#include <float.h>
void afficherVarEntier();
void afficherVarFloat();
int tronquer();

int main(){
  //afficherVarEntier();
  //afficherVarFloat();
  int valide = tronquer();
  if(valide==0){
    printf("ALL GOOD !\n");
  }
  else if(valide==-1){
    printf("ERREUR !\n");
  }
  else{
    printf("Rien ne s'est passé\n");
  }
  return 0;
}

void afficherVarEntier(){
  printf("Le nombre de bits pour représenter le type CHAR %d\n", CHAR_BIT);
  printf("La valeur minimale pour une variable de type SIGNED CHAR %d\n", SCHAR_MIN);
  printf("La valeur maximale pour une variable de type SIGNED CHAR %d\n", SCHAR_MAX);
  printf("La valeur maximale pour une variable de type UNSIGNED CHAR %d\n", UCHAR_MAX);
  printf("La valeur minimale pour une variable de type SHORT %d\n", SHRT_MIN);
  printf("La valeur maximale pour une variable de type SHORT %d\n", SHRT_MAX);
  printf("La valeur minimale pour une variable de type INT %d\n", INT_MIN);
  printf("La valeur maximale pour une variable de type INT %d\n", INT_MAX);
  printf("La valeur minimale pour une variable de type CHAR %d\n", CHAR_MIN);
  printf("La valeur maximale pour une variable de type CHAR %d\n", CHAR_MAX);
  printf("La valeur minimale pour une variable de type LONG %ld\n", LONG_MIN);
  printf("La valeur maximale pour une variable de type LONG %ld\n\n", LONG_MAX);
  printf("Le nombre maximum de bits dans un caractère multi-bits %d\n", MB_LEN_MAX);
  printf("La valeur minimale pour une variable de type SIGNED LONG LONG %lld\n",LLONG_MIN);
  printf("La valeur maximale pour une variable de type SIGNED LONG LONG %lld\n",LLONG_MAX);
}

void afficherVarFloat(){
  printf("Le nombre minimum d'un type FLOAT %f\n", FLT_MIN);
  printf("Le nombre maximum d'un type FLOAT %f\n", FLT_MAX);
  printf("Le nombre minimum d'un type DOUBLE %f\n", DBL_MAX);
  printf("Le nombre maximum d'un type DOUBLE %f\n", DBL_MAX);
  printf("Le nombre minimum et positive d'un type FLOAT %f\n", FLT_TRUE_MIN);
  printf("Le nombre minimum et positive d'un type DOUBLE %f\n", DBL_TRUE_MIN);
}

int tronquer(){
  int ok = 1;
  double x = 9999999999999999999999999999999999999999999999.9999999;
  while(ok==1){
    if((long)(x)>LONG_MAX){
      printf("Erreur, x au dessus du max de long\n");
      ok = -1;
    }
    else{
      printf("Le double %f tronqué en long devient %ld\n", x, (long)x);
      ok = 0;
    }
  }
  return ok;
}
