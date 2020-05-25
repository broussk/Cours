#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
char a[]="bonjour";
char b[]="Halo";
int i =0;
int res = 1;
for (i = 0; i < strlen(a); i++) {
  if (*a+i != *b+i){
    res = 0;
  }
}

if(res ==0){
  printf("Chaine non identiques\n" );
}else {
  printf("Chaine identiques\n" );
}
  
  return 0;

}