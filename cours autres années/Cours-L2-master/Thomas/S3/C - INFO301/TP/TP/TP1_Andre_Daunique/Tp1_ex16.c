 #include <stdio.h>
#include <stdlib.h>
 void main(){
     int somme = 0;
  printf("Entrez la somme svp : \n");
  scanf("%d", &somme);
  int reste = 0;

  int billet_100 , billet_50 , billet_20 , billet_10 , billet_5 , billet_2 , billet_1 = 0;

    billet_100 = somme / 100;
    reste = somme%100;
    billet_50 = reste/50;
    reste = reste%50;
    billet_20 = reste/20;
    reste = reste%20;
    billet_10 = reste/10;
    reste = reste%10;
    billet_5 = reste/5;
    reste = reste%5;
    billet_2 = reste/2;
    reste = reste%2;
    billet_1 = reste;


    printf("%d billet(s) de 100€,%d billet(s) de 50€,%d billet(s) de 20€,%d billet(s) de 10€,%d billet(s) de 5€,%d billet(s) de 2€,%d billet(s) de 1€\n",billet_100 , billet_50 , billet_20 , billet_10 , billet_5 , billet_2 , billet_1 );
 }