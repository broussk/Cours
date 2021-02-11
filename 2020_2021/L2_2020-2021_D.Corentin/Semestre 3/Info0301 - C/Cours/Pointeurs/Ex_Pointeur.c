#include <stdio.h>
#include <stdlib.h>

int main(){

  int a = 34;
  int * pa=NULL;

  printf("La valeur de a = %d \n",a);
  printf("L'adresse de a = %p \n",&a);

  pa = &a;

  printf("La valeur de pa = %p \n",pa);
  printf("L'adresse de pa = %p \n",&pa);
  printf("La valeur de la case pointée par  pa = %d \n",*pa);

  return 0;
}
