#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    printf("Entrez les coordonnees cartesiennes du point A:\n");
    printf("x=");
    scanf("%f",&x);
    printf("y=");
    scanf("%f",&y);
    if(x>0){
        if(y>0){
            printf("Le point se trouve dans le cote +,+; quadrant 1");
        }
        else{
            printf("Le point se trouve dans le cote +,-; quadrant 4");
        }
    }
    else{
        if(y>0){
            printf("Le point se trouve dans le cote -,+; quadrant 2");
        }
        else{
            printf("Le point se trouve dans le cote -,-; quadrant 3");
        }
    }
    return 0;
}
