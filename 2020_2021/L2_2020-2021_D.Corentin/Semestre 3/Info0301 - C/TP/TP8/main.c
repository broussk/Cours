#include "fct1.h"
#include "fcts.h"

int main(){
  int choix;
  char texte[6];
  choix = choix_menu();
  lire_data(texte);
  switch (choix){
    case 1:
      fct1(texte);
      break;
    case 2:
      fct2(texte);
      break;
    default:
      break;
  }

  print_data(texte);
  return 0;
}