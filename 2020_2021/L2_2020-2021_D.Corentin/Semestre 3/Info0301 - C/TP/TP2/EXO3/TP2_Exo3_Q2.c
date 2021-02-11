#include <stdio.h>
int main()
{
    
    double a, b;

    printf("Entrez des coordonées (x, y): \n");
    scanf("(%lf, %lf)", &a, &b);


    if(a<0 && b<0){
        printf("Quadrant III (-,-)\n");
    } else if (a>0 && b>0){
        printf("Quadrant I (+,+)\n");
    } else if (a<0 && b>0) {
        printf("Quadrant IV (-,+)\n");
    } else {
        printf("Quadrant II(+,-)\n");
    }


    return 0;
}