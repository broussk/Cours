#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  char ch1[50]="";
  char ch2[50]="";
  printf("Entrez une première chaîne : ");
  scanf("%s",ch1);
  printf("Entrez une deuxième chaîne : ");
  scanf("%s",ch2);
  if(ch1[0]<ch2[0]){
    printf("%s\n%s\n",ch1,ch2);
  }
  else{
    printf("%s\n%s\n",ch2,ch1);
  }
  return 0;
}
