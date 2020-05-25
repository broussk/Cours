#include "complex.h"
#include <stdlib.h>

int main(void){
  // complex n1,n2,res;
  // n1 = lecture_complex();
  // printf("n1= ");
  // affichage_complex(n1);

  // n2 = lecture_complex();
  // printf("n2= ");
  // affichage_complex(n2);

  // res = addition_C(n1,n2);
  // printf("La somme de n1 et n2 est : ");
  // affichage_complex(res);

  // complex test;
  // saisir(&test);
  // affichage_complex(test);
  // ajout(&test,n1);
  // affichage_complex(test);
  // printf("\n=!= produit_C entre n1 et n2 : ");
  // complex tmp = produit_C(n1,n2);
  // affichage_complex(tmp);
  // printf("\n=!= Produit entre n1 et n2 : ");
  // produit(&n1,n2);
  // affichage_complex(n1);
  // printf("\n=!= Conjugué de n1 : ");
  // complex conjN1 = Conjugue_C(n1);
  // affichage_complex(conjN1);
  // complex quoN1N2 = Quotient_C(n1,n2);
  // printf("Quotient entre n1 et n2 : ");
  // affichage_complex(quoN1N2);
  // printf("Module de n1 : %f",Module_C(n1));
  // printf("Argument de n1 : %f", Argument_C(n1));
  // complex test2;
  // saisir(&test2);
  // complex racinesTest2 = Rac2C(test2);
  // printf("Les racines de votre complexe sont : +/-[");
  // affichage_complex(racinesTest2);
  // printf("]\n");

  complex *tabComplex;
  double *tabArgs, *tabModules;
  int n=0;
  printf("Entrez le nombre de complexes que vous souhaitez : ");
  scanf("%d",&n);
  tabComplex = malloc(sizeof(complex)*n);
  tabArgs = malloc(sizeof(double)*n);
  tabModules = malloc(sizeof(double)*n);
  for(int i=0 ; i<n ; i++){
    printf("Entrez le complexe n°%d : ",(i+1));
    saisir(&tabComplex[i]);
  }
  for(int i=0 ; i<n ; i++){
    tabArgs[i] = Argument_C(tabComplex[i]);
    tabModules[i] = Module_C(tabComplex[i]);
  }
  printf("\n==!== Votre tableau de complexes ==!==\n");
  for(int i=0 ; i<n ; i++){
    printf("[%d] ",(i+1));
    affichage_complex(tabComplex[i]);
    printf("\tSon module : %f\n",tabModules[i]);
    printf("\tSon argument : %f\n",tabArgs[i]);
  }
  return 0;
}
