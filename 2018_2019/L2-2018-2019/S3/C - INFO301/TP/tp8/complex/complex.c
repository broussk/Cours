#include "complex.h"
#include <math.h>
complex lecture_complex(){
  complex tmp;

  printf("Donner la partie réelle : ");
  scanf("%f",&tmp.reel);
  printf("Donner la partie imaginaire : ");
  scanf("%f",&tmp.imag);
  return (tmp);
}

void affichage_complex(complex c){
  if(c.imag<0){
    printf("%f%fi\n",c.reel,c.imag);
  }
  else{
    printf("%f+%fi\n",c.reel,c.imag);
  }
}

complex addition_C(complex c1, complex c2){
  complex tmp;
  tmp.reel = c1.reel + c2.reel;
  tmp.imag = c1.imag + c2.imag;

  return (tmp);
}
void saisir(complex *pc){
  printf("\nEntrez la partie réelle : ");
  scanf("%f",&pc->reel);
  printf("Entrez la partie imaginaire : ");
  scanf("%f",&pc->imag);
  // affichage_complex(*pc);
}
void ajout(complex *pc1, complex c2){
  pc1->reel += c2.reel;
  pc1->imag += c2.imag;
}
complex produit_C(complex c1, complex c2){
  //(a+ib)(c+id) = (ac-bd)+i(ad+bc)
  complex tmp;
  tmp.reel = ((c1.reel*c2.reel)-(c1.imag*c2.imag));
  tmp.imag = ((c1.reel*c2.imag)+(c1.imag*c2.reel));
  return tmp;
}
void produit(complex *pc1, complex c2){
  float tmp1 = (pc1->reel*c2.reel)-(pc1->imag*c2.imag);
  float tmp2 = (pc1->reel*c2.imag)+(pc1->imag*c2.reel);
  pc1->reel = tmp1;
  pc1->imag = tmp2;
}
complex Conjugue_C(complex c){
  complex con;
  con.reel = c.reel;
  con.imag = -(c.imag);
  return con;
}
complex Quotient_C(complex c1, complex c2){
  complex tmp;
  complex num = produit_C(c1,Conjugue_C(c2));
  complex denom = produit_C(c2,Conjugue_C(c2));
  tmp.reel = num.reel/denom.reel;
  tmp.imag = num.imag/denom.reel;
  return tmp;
}
double Module_C(complex c){
  return sqrt(pow(c.reel,2)+pow(c.imag,2));
}
double Argument_C(complex c){
  return atan(c.imag/c.reel);
}
complex Rac2C(complex z){
  complex res;
  float a= z.reel, b= z.imag, m=0, x=0, y=0;
  m= Module_C(z);
  x= sqrt((m+a)/2);
  y= sqrt((m-a)/2);
  if(b<0){
    y = -y;
  }
  res.reel= x;
  res.imag= y;
  return res;
}
