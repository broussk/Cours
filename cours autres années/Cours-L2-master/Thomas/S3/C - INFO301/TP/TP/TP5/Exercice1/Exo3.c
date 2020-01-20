#include <stdlib.h>
#include <stdio.h>

int main(){
    int kek[5];
    int val;

  do {
       printf("Entrez un nombre de 5 chiffres : ");
      fflush(stdin);
      scanf("%d",&val);

  }while(99999<val||val<10000);
    char st [30];

    sprintf(st,"%d",val);
    printf("res:%s",st);

    return 0;
  }
