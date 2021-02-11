#include <stdio.h>
int main()
{

   int a;
   printf("Entrez un numero de mois : \n");
   scanf("%d",&a);

    switch (a) {
        case 1: printf("Janvier, 31 jours.\n");
            break;
        case 2: printf("Fevrier, 28 ou 29 jours.\n");
            break;
        case 3: printf("Mars, 31 jours.\n");
            break;
        case 4: printf("Avril, 30 jours.\n");
            break;
        case 5: printf("Mai, 31 jours.\n");
            break;
        case 6: printf("Juin, 30 jours.\n");
            break;
        case 7: printf("Juillet, 31 jours.\n");
            break;
        case 8: printf("Aout, 31 jours.\n");
            break;
        case 9: printf("Septembre, 30 jours.\n");
            break;
        case 10: printf("Octobre, 31 jours.\n");
            break;
        case 11: printf("Novembre, 30 jours.\n");
            break;
        case 12: printf("Decembre, 31 jours.\n");
            break;
        default: printf("Mois inconnu !\n");
    }


    return 0;
}