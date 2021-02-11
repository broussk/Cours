#include <stdio.h>

int main(){

    int dayInit, years, week, days;
    printf("Entrez un nombre de jours: \n");
    scanf("%d=", &dayInit);

    years = (int) (dayInit / 365);
    week =  (int) ((dayInit % 365) / 7 );
    days = (int) ((dayInit % 365) % 7);

    printf("%d jours : %d annees, %d semaines et %d jours\n", dayInit, years, week, days);

    return 0;
}