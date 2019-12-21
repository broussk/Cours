#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

int x,y=0;
printf("Entrez x : \n");
scanf("%d",&x);
printf("Entrez y : \n");
scanf("%d",&y);

if (x>0 && y>0){
  printf("Cadran 1\n" );
}else if(x<0 && y>0){
  printf("Cadran 2\n" );
}else if(x<0 && y<0){
  printf("Cadran 3\n" );
}else {
  printf("Cadran 4\n" );
}
    return 0;
}
