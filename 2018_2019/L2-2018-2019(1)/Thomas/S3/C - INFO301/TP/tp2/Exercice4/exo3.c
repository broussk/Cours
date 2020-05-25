#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

  //Exo 3 On ne peut pas mettre le nombre de jours dans le mois de fevrier il nous faut l'anne ( bisextille ou non)
  int valeur = 0;

  do{
  printf("Quel est votre valeur ?\n" );
  scanf("%d", &valeur );
}while( valeur > 21 || valeur < 1);

  switch (valeur) {
    case 1:
    printf("Mois de janvier , 31 jours\n");
    break;
    case 2:
    printf("Mois de fevrier \n");
    break;
    case 3:
    printf("Mois de mars , 31 jours\n");
    break;
    case 4:
    printf("Mois d'avril , 30 jours\n");
    break;
    case 5:
    printf("Mois de mai , 31 jours\n");
    break;
    case 6:
    printf("Mois de juin , 30 jours\n");
    break;
    case 7:
    printf("Mois de juillet , 31 jours\n");
    break;
    case 8:
    printf("Mois d'aout , 31 jours\n");
    break;
    case 9:
    printf("Mois de septembre , 30 jours\n");
    break;
    case 10:
    printf("Mois d'octobre , 31 jours\n");
    break;
    case 11:
    printf("Mois de novembre , 30 jours\n");
    break;
    case 12:
    printf("Mois de decembre , 31 jours\n");
    break;
  }

return 0;

}
