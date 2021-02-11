#include <stdio.h>
int main()
{

   char a;
   printf("Quelle est la bonne façon de déclarer une variable entière en langage C :\na.  Entier x;\nb.  Int x;\nc.  integer x;\nd.  int x;\ne.  Long x;\nChoisissez la lettre de réponse: ");
   scanf("%c",&a);

    switch (a) {
        case 'd': printf("Choix correct!\n");
            break;
        default: printf("Choix incorrect!\n");
    }


    return 0;
}