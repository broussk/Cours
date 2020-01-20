#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int val= 0;
int res = -1;
int tab[9] = {1,2,3,4,5,6,7,8,9};
printf("Veuillez entrer un entier a rechercher \n");
scanf("%d",&val);

int trouve = 0;  //vaut faux tant que la valeur "val" n'aura pas été trouvée
int id;  //indice de début
int ifin;  //indice de fin
int im;  //indice de "milieu"

id = 0;  //intervalle de recherche compris entre 0...
ifin = 8;  //...et nbVal

while(trouve == 0 && ((ifin - id) > 1)){

  im = (id + ifin)/2;  //on détermine l'indice de milieu
  trouve = (tab[im] == val);  //on regarde si la valeur recherchée est à cet indice

  if(tab[im] > val) ifin = im;  //si la valeur qui est à la case "im" est supérieure à la valeur recherchée, l'indice de fin "ifin" << devient >> l'indice de milieu, ainsi l'intervalle de recherche est restreint lors du prochain tour de boucle
  else id = im;  //sinon l'indice de début << devient >> l'indice de milieu et l'intervalle est de la même façon restreint
}

if(tab[id] == val){
  res = id; //si on a trouvé la bonne valeur, on retourne l'indice
}

printf("La valeur %d se trouve en position %d \n", val , res );
  
  return 0;

}

