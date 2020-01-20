#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

double a,b,c = 0.0;

printf("Entrez les 3 valeurs séparé par une virgule\n" );
scanf("%lf,%lf,%lf",&a,&b,&c );
printf(" a = %lf \n", a );
printf(" b = %lf \n", b );
printf(" c = %lf \n", c );


printf("La somme est %lf\n", a+b+c);

    return 0;
}
