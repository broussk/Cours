#include <stdlib.h>
#include <stdio.h>

int main(){
  char test[] = "test";
  int i = 0;
  do{
    printf("%c\t",test[i]);
    i++;
  }
  while(test[i]!=0);
  printf("\n");
  return 0;
}
