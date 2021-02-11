#include <stdio.h>
int main()
{

   int a;
   printf("Entrez un chiffre : \n");
   scanf("%d",&a);

    switch (a) {
        case 0: printf("0 => zero\n");
            break;
        case 1: printf("1 => un\n");
            break;
        case 2: printf("2 => deux\n");
            break;
        case 3: printf("3 => trois\n");
            break;
        case 4: printf("4 => quatre\n");
            break;
        case 5: printf("5 => cinq\n");
            break;
        case 6: printf("6 => six\n");
            break;
        case 7: printf("7 => sept\n");
            break;
        case 8: printf("8 => huit\n");
            break;
        case 9: printf("9 => neuf\n");
            break;
        default: printf("Chiffre inconnu !\n");
    }


    return 0;
}