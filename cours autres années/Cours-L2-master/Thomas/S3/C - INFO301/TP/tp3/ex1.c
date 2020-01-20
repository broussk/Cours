//Exercice 1 : question 1 -> la différence entre les deux codes et que le deuxième a une saisie "sécurisée" et aura un affichage correct des caractères entrés et voulus. Le %*c signifie que ce qui correspond au %c sera ignoré. C'est l'anti %c en quelque sorte.

#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 13;
  float x = 46.8;
  printf("a = %d\n",a);
  printf("x = %.1f\n",x);
  return 0;
}
