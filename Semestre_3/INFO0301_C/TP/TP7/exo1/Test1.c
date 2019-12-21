#include "complex.h"

int main(){
    complex n1, n2, res;

    n1 = lecture_complex();
    printf("n1= ");
    affichage_complex(n1);
    n2 = lecture_complex();
    printf("n2= ");
    affichage_complex(n2);
    res = addition_c(n1,n2);
    printf("La somme de n1 et n2 est égale à : ");
    affichage_complex(res);

    return 0;
}