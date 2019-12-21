#include <stdio.h>
#include <limits.h>

int main()
{
    printf("le nombre de bits pour representer le type CHAR = %d\n",CHAR_BIT);
    printf("la valeur minimale pour une variable de type SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("la valeur maximale pour une variable de type SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("la valeur maximale pour une variable de type UNSIGNED CHAR = %d\n",UCHAR_MAX);
    printf("la valeur minimale pour une variable de type SHORT INT =%d\n",SHRT_MIN);
    printf("la valeur maximale pour une variable de type SHORT INT =%d\n", SHRT_MAX);
    printf("la valeur minimale pour une variable de type INT = %d\n",INT_MIN);
    printf("la valeur maximale pour une variable de type INT =%d\n", INT_MAX);
    printf("la valeur minimale pour une variable de type CHAR =%d\n",CHAR_MIN);
    printf("la valeur maximale pour une variable de type CHAR =%d\n",CHAR_MAX);
    printf("la valeur minimale pour une variable de type LONG = %ld\n",LONG_MIN);
    printf("la valeur maximale pour une variable de type LONG = %ld\n", LONG_MAX);
    printf("la valeur minimale pour une variable de type LLONG =%lld\n",LLONG_MIN);
    printf("la valeur maximale pour une variable de type LLONG =%lld\n",LLONG_MAX);
    return 0;
}
