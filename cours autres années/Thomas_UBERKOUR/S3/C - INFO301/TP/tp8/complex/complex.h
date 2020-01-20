#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

struct complex{
  float reel;
  float imag;
};
typedef struct complex complex;

complex lecture_complex();
void affichage_complex(complex);
complex addition_C(complex,complex);
void saisir(complex*);
void ajout(complex*,complex);
complex produit_C(complex,complex);
void produit(complex*, complex);
complex Conjugue_C(complex);
complex Quotient_C(complex,complex);
double Module_C(complex);
double Argument_C(complex);
complex Rac2C(complex);//Calcule la racine tel que r2=z

#endif /*COMPLEX_H*/
