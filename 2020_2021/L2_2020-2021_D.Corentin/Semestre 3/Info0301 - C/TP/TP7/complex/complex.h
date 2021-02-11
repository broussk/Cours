#ifndef COMPLEX_H
#define COMPLEX_H
#include <stdio.h>

typedef struct complex{
    float reel;
    float imag;
} complex;


complex lecture_complex();

void affichage_complex(complex);

complex addition_C(complex, complex);

void saisir(complex *pc);

void ajout(complex *pc1, complex c2);

complex produit_C (complex c1, complex c2);

void produit(complex *pc1, complex c2);

complex Conjugue_C(complex c);

complex Quotient_C(complex c1, complex c2);

double Module_C(complex c);

double Argument_C(complex c);

complex Rac2C(complex z);

#endif /* COMPLEX_H */