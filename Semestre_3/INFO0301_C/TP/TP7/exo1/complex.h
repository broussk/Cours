#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct complex
{
    float reel;
    float imag;
} complex;

complex lecture_complex();
void affichage_complex(complex);
complex addition_c(complex, complex);

void saisir(complex *pc);
void ajout(complex *pc1, complex *pc2);
complex produit_c(complex c1, complex c2);
void produit(complex *pc1, complex c2);
complex Conjugue_c(complex c);
complex Quotient_c(complex c1, complex c2);
double Module_c(complex c);
double Argument_c(complex c);
complex Rac2c(complex z);

#endif /*COMPLEX_H */