#include <stdio.h>

int main(int argc, char **argv){
    int a=5,b;
    char ca = 'A';
    short s = 1;
    long l = 52555;
    unsigned int ui = 5;
    unsigned long ul = 52989;
    float f = 5.684;
    double d = 58.6;
    long double ldouble = 85594.54;
    char cc = 'C';
    char cs = 'S';


    b = 7;
    printf("%d , %d\n",a,b);
    printf("\n");
    printf("La valeur de a est égale à %d \n",a);
    printf("a = %d et b = %d\n",a,b);
    printf("ld = %LF\n",ldouble);
    printf("l = %ld\n",l);
    printf("ui = %d\n",ui);
    printf("ul = %lu\n",ul);
    printf("f = %f\n",f);
    printf("caractère c en décimal = %d ; > caractère : %c\n",ca,ca);
    printf("En inversant %c%c%c, on trouve %c%c%c\n\n",cc,ca,cs,cs,ca,cc);
    return 0;
}
