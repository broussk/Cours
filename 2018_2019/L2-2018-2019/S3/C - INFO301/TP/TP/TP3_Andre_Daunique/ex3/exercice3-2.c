#include <stdio.h>

void main()
{
    float f;
    float celsius;

    printf("Donnez votre valeur de degre celsius à converir en farheneit \n");
    scanf("%f",&celsius);
    f = celsius * 9.0/5.0 + 32.0;
    printf("%.1f degre celsius = %.1f degre farheneit",celsius,f);
}