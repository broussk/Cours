#include <stdio.h>
#include <math.h>
void main(){
double x1 = 1 ;
double y1 = 1 ;
double x2 = 2 ;
double y2 = 2 ;
double kek;
double verif;
kek=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
kek=sqrt(kek);
verif=sqrt(2);
printf("%lf\n",kek);
printf("%lf",verif);
}