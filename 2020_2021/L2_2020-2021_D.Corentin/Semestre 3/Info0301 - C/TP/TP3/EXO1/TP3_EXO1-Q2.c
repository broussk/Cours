#include <stdio.h>
#include <float.h>

int main() {
    printf("La valeur minimale pour une variable de type FLOAT = %f\n", FLT_MIN);
    printf("La valeur maximale pour une variable de type FLOAT = %f\n", FLT_MAX);
    printf("La valeur minimale pour une variable de type DOUBLE = %lf\n", DBL_MIN);
    printf("La valeur maximale pour une variable de type DOUBLE = %lf\n", DBL_MAX);
    printf("La valeur minimale pour une variable de type LONG DOUBLE = %LG\n", LDBL_MIN);
    printf("La valeur maximale pour une variable de type LONG DOUBLE = %LG\n", LDBL_MAX);
    return(0);
}