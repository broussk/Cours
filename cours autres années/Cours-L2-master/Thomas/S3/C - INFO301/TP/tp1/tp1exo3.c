#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){


  int nb = 0, nbAnnees = 0, nbMois = 0, nbJours = 0;
  printf("Entrez le nombre de jours : ");
  scanf("%d",&nb);
  if(nb > 0){
    if(nb>=365){
      nbAnnees = nb/365;
      nbMois = (nb%365)/30;
      nbJours = (nb%365)%30;
    }
    else if(nb>=30){
      nbMois = nb/30;
      nbJours = (nb%30)%30;
    }
    else{
      nbJours = nb;
    }
  }
  printf("Nombre de jours entré : %d\nNombre d'années : %d\nNombre de mois : %d\nNombre de jours : %d\n",nb,nbAnnees,nbMois,nbJours);

  // int nb = 0, nbAnnees = 0, nbSemaines = 0, nbJours = 0;
  // printf("Entrez le nombre de jours : ");
  // scanf("%d",&nb);
  // if(nb > 0){
  //   if(nb>=365){
  //     nbAnnees = nb/365;
  //     nbSemaines = (nb%365)/7;
  //     nbJours = (nb%365)%7;
  //   }
  //   else if(nb>=7){
  //     nbSemaines = nb/7;
  //     nbJours = (nb%7)%7;
  //   }
  //   else{
  //     nbJours = nb;
  //   }
  // }
  // printf("Nombre de jours entré : %d\nNombre d'années : %d\nNombre de semaines : %d\nNombre de jours : %d\n",nb,nbAnnees,nbSemaines,nbJours);

  // //Calcule aire / perimetre d'un cercle
  // int rayonCercle = 5;
  // double aireCercle = M_PI*(rayonCercle*rayonCercle);
  // double periCercle = 2*M_PI*rayonCercle;
  // // printf("PI = %f\n",M_PI);
  // printf("Le périmètre d'un cercle de rayon %d est %f ; son aire est %f\n",rayonCercle,periCercle,aireCercle);
  // int a,b;

  // calcule quotient / reste division de deux nombres entiers
  // printf("Entrez a : ");
  // scanf("%d",&a);
  // printf("Entrez b : ");
  // scanf("%d",&b);
  // // printf("a : %d ; b : %d\n",a,b);
  // double resAqB = (double)a/(double)b; // solution de cast pour corriger la division entière
  // double resAmodB = a%b;
  // printf("a(%d)/b(%d) = %lf ; a(%d)%%(%d) = %lf\n\n",a,b,resAqB,a,b,resAmodB);

  // // calcule variance / moyenne de 3 nombres entiers
  // int e1 = 1, e2 = 2, e3 = 3;
  // double moye1e2e3 = (e1 + e2 + e3) / 3;
  // double vare1e2e3 = (pow(e1-moye1e2e3,2) + pow(e2-moye1e2e3,2) + pow(e3-moye1e2e3,2))/3;
  // printf("Moyenne de %d, %d et %d = %lf\nVariance : %lf\n",e1,e2,e3,moye1e2e3,vare1e2e3);
  return 0;
}
