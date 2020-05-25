#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

  char a[]="bonjour";
  int i=0;

for (i = 0; i < sizeof (a) - 1; i++) {
  printf("\t%c\n", a[i]);
}

return 0;

}
