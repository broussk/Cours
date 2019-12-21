#include "complex.h"

complex lecture_complex(){
    complex tmp;
    printf("Donner la pertie réelle : ");
    saisir(&tmp.reel);
    //scanf("%f", &tmp.reel);
    printf("Donner la partie imaginaire : ");
    saisir(&tmp.imag);
    //scanf("%f",&tmp.imag);
    return (tmp);
}

void affichage_complex(complex c){
    printf("%.2f + %.2f \n",c.reel,c.imag);
}

complex addition_C(complex c1, complex c2){
    complex tmp;

    tmp.reel = c1.reel + c2.reel;
    tmp.imag = c1.imag + c2.imag;
    return (tmp);
}

void saisir(complex *pc){
    scanf("%f",&pc);
}

void ajout(complex *pc1, complex c2){
    complex tmp=*pc1;
    tmp.reel+=c2.reel;
    tmp.imag+=c2.imag;
    *pc1=tmp;
}

complex produit_C(complex c1, complex c2){
    complex tmp;
    tmp.reel=(c1.reel*c2.reel)-(c1.imag*c2.imag);
    tmp.imag=(c1.reel*c2.imag)+(c2.reel*c1.imag);
    return tmp;
}

void produit(complex *pc1, complex c2){
    complex tmp=*pc1;
    tmp.reel=(tmp.reel*c2.reel)-(tmp.imag*c2.imag);
    tmp.imag=(tmp.reel*c2.imag)+(c2.reel*tmp.imag);
    *pc1=tmp;
}

complex Conjugue_C(complex c){
    c.imag*=-1;
    return c;
}

complex Quotient_C(complex c1, complex c2){
    complex tmp,prod;
    prod=produit_C(c1,Conjugue_C(c2));
    tmp.reel=prod.reel/(c2.reel*c2.reel+c2.imag*c2.imag);
    tmp.imag=prod.imag/(c2.reel*c2.reel+c2.imag*c2.imag);
    return tmp;
}

double Module_C(complex c){
    double res;
    res = sqrt((c.reel*c.reel+c.imag*c.imag));
    return res;
}

double Argument_C(complex c){
    double cos, sin, arg;
    cos=c.reel/Module_C(c);
    sin=c.imag/Module_C(c);
    if (cos==1 && sin==0){
        arg=0;
    }
    else if (cos==(sqrt(3)/2) && sin==1/2)
    {
        arg=1/6;
    }
    else if (cos==(sqrt(2)/2) && sin==(sqrt(2)/2))
    {
        arg=1/4;
    }
    else if (cos==1/2 && sin==(sqrt(3)/2))
    {
        arg=1/3;
    }
    else if (cos==0 && sin==1)
    {
        arg=1/2;
    }
    else if (cos==-(1/2) && sin==(sqrt(3)/2))
    {
        arg=2/3;
    }
    else if (cos==-(sqrt(2)/2) && sin==(sqrt(2)/2))
    {
        arg=3/4;
    }
    else if (cos==-(sqrt(3)/2) && sin==1/2)
    {
        arg=5/6;
    }
    else if (cos==-1 && sin==0)
    {
        arg=1;
    }
    else if (cos==-(sqrt(3)/2) && sin==-(1/2))
    {
        arg=-1/6;
    }
    else if (cos==-(sqrt(2)/2) && sin==-(sqrt(2)/2))
    {
        arg=-1/4;
    }
    else if (cos==-(1/2) && sin==-(sqrt(3)/2))
    {
        arg=1/3;
    }
    else if (cos==0 && sin==-1)
    {
        arg=-1/2;
    }
    else if (cos==-(1/2) && sin==-(sqrt(3)/2))
    {
        arg=-2/3;
    }
    else if (cos==-(sqrt(2)/2) && sin==-(sqrt(2)/2))
    {
        arg=-3/4;
    }
    else if (cos==-(sqrt(3)/2) && sin==-(1/2))
    {
        arg=-5/6;
    }
    return arg;
}

complex Rac2C(complex z){
    /* calcul la racine tel que r2=z;*/
}