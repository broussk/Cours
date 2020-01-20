#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  
double val1,val2 = 0;
char car;
printf("Entrez un calcul de ce type : Val1 + Val2\n");
scanf("%lf %c %lf",&val1 , &car , &val2 );
printf("val 1 : %lf\n", val1 );
printf("val 2 : %lf\n", val2 );
printf("car : %c\n", car );

if(car == '+')
{
  printf("%lf %c %lf = %lf\n" , val1 , car ,val2 , val1+val2);
}else if(car == '*'){
  printf("%lf %c %lf = %lf\n" , val1 , car ,val2 , val1*val2);
}else if (car == '-'){
  printf("%lf %c %lf = %lf\n" , val1 , car ,val2 , val1-val2);
}


    return 0;
}
