#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{

int a,b,c=0;
int delta=0;
int racine_delta=0;
int x1,x2,x0=0;
printf("Entrez a : \n");
scanf("%d",&a);
printf("Entrez b : \n");
scanf("%d",&b);
printf("Entrez c : \n");
scanf("%d",&c);

delta=b*b-(4*a*c);
racine_delta = sqrt(delta);
if(delta > 0){
  x1=(-b + racine_delta) / (2*a);
  x2=(-b - racine_delta) / (2*a);
  printf("x1 = %d et x2= %d\n",x1,x2);
}else if (delta == 0) {
  x0=(-b)/(2*a);
  printf("x0 = %d\n",x0);
}else {
  printf("Valeur de delta = %d , donc impossible avec un delta negatif\n", delta );
}

    return 0;
}
