#include <stdio.h>
#include <math.h>
void main(){
int tot,h,m,s;
tot=70;
h=tot/3600;
tot=tot%3600;
m=tot/60;
s=tot%60;

printf("%dH:%dM:%dS\n",h,m,s);

}