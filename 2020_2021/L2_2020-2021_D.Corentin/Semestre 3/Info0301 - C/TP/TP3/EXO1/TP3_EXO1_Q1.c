#include <stdio.h>
#include <limits.h>
int main() {
    printf("Le nombre de bits pour representer le type CHAR = %d\n", CHAR_BIT);
    printf("La valeur minimale pour une variable de type SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("La valeur maximale pour une variable de type SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("La valeur maximale pour une variable de type UNSIGNED CHAR = %d\n", UCHAR_MAX);
    printf("La valeur minimale pour une variable de type SHORT INT = %d\n", SHRT_MIN);
    printf("La valeur maximale pour une variable de type SHORT INT = %d\n", SHRT_MAX);
    printf("La valeur minimale pour une variable de type INT = %d\n", INT_MIN);
    printf("La valeur maximale pour une variable de type INT = %d\n", INT_MAX);
    printf("La valeur minimale pour une variable de type CHAR = %d\n", CHAR_MIN);
    printf("La valeur maximale pour une variable de type CHAR = %d\n", CHAR_MAX);
    printf("La valeur minimale pour une variable de type LONG = %ld\n", LONG_MIN);
    printf("La valeur maximale pour une variable de type LONG = %ld\n", LONG_MAX);


    //Add
    printf("La valeur minimale pour une variable de type SIGNED SHORT = %hd\n", SHRT_MIN);
    printf("La valeur maximale pour une variable de type SIGNED SHORT = %hd\n", SHRT_MAX);
    printf("La valeur minimale pour une variable de type LONG LONG = %lld\n", LLONG_MIN);
    printf("La valeur maximiale pour une variable de type LONG LONG = %lld\n", LLONG_MAX);

    printf("La valeur maximiale pour une variable de type UNSIGNED SHORT = %hu\n", USHRT_MAX);
    printf("La valeur maximiale pour une variable de type UNSIGNED INT = %u\n", UINT_MAX);
    printf("La valeur maximiale pour une variable de type UNSIGNED LONG = %lu\n", ULONG_MAX);
    printf("La valeur maximiale pour une variable de type UNSIGNED LONG LONG = %llu\n", ULLONG_MAX);


    return(0);
}