#include "complex.h"

complex lecture_complex(){
    complex tmp;

    printf("Donner la partie réelle : ");
    scanf("%f",&tmp.reel);
    printf("donner la partie imaginaire : ");
    scanf("%f",&tmp.imag);
    return (tmp);
}

void affichage_complex(complex c){
    printf("%.2f + %.2fi\n",c.reel,c.imag);
}

complex addition_c(complex c1, complex c2){
    complex tmp;

    tmp.reel = c1.reel + c2.reel;
    tmp.imag = c1.imag + c2.imag;

    return (tmp);
}

void saisir(complex *pc){
    
}

void ajout(complex *pc1, complex *pc2){

}

complex produit_c(complex c1, complex c2){

}

void produit(complex *pc1, complex c2){

}

complex Conjugue_c(complex c){

}

complex Quotient_c(complex c1, complex c2){

}

double Module_c(complex c){

}

double Argument_c(complex c){

}

complex Rac2c(complex z){

}