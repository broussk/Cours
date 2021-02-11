#include "complex.h"
#include <stdio.h>
#include <math.h>

complex lecture_complex(){
    complex tmp;
    printf("Donner la partie reelle: ");
    scanf("%f",&tmp.reel);
    printf("Donner la partie imaginaire: ");
    scanf("%f",&tmp.imag);
    printf("\n");
    return (tmp);
}

void affichage_complex(complex c){
    printf("%.2f + %.2fi\n", c.reel, c.imag);
}

complex addition_C(complex c1, complex c2){
    complex tmp;
    tmp.reel = c1.reel + c2.reel;
    tmp.imag = c1.imag + c2.imag;
    return (tmp);
}

double Module_C(complex c){
   return sqrtf((c.reel * c.reel) + (c.imag * c.imag));
}

double Argument_C(complex c){
 return atanf(c.imag / c.reel);
}