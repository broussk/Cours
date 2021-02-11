#include <stdio.h>
int main()
{
    float conso,prix;
    printf("Donnez votre consommation éléctrique ");
    scanf("%f",&conso);
    if ( conso <=50)
    {prix = conso*0.5;
        printf("%.2f euros ht ",prix);
    }
    else if (conso >50 && conso <=150)
    { prix=(50*0.50)+(conso-50)*0.75;
        printf("%.2f euros ht",prix);
    }
    else if (conso >150 && conso <=250)
    {
        prix=(50*0.50)+(100*0.75) + (conso-150)*1.20;
        printf("%.2f euros ht",prix);
    }
    else
    {
        prix=(50*0.50)+(100*0.75 )+ (150*1.20)+(conso-250)*1.50;
        printf("%.2f euros ht",prix);
    }
    printf("\n%.2f euros ttc",prix*1.20);
}