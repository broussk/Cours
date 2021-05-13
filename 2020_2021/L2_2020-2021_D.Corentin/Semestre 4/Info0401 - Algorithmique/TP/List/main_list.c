#include <stdio.h>
#include "list.h"


int main(){



    List *l1 = create();
    List *l2 = create();

    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 3);
    insert(l1, 4);
    insert(l1, 5);
    insert(l1, 6);

    insert(l2, 2);
    insert(l2, 3);
    insert(l2, 4);



//
//
//    show(l1);
//    show(l2);
//
    if(isExtract(l1, l2)) printf("est extraite");
    else printf("n'est pas extraite");
//
//    List *list = create(), *list2 = createNode();
//
//
//    insert(list2, 2);
//    insert(list2, 3);
//    insert(list2, 4);
//
//    int quit = 1, choice, val, position;
//
//    printf( "-------------------Liste chainee par Corentin---------------------");
//
//    do{
//        printf( "\n---------------------------------------------------"
//                "\nMenu:\n"
//               "1- Insertion\n"
//               "2- Insertion a un rang quelconque\n"
//               "3- Afficher la taile\n"
//               "4- Afficher la liste\n"
//               "5- Trouver un element\n"
//               "6- Incrementer une liste binaire\n"
//               "7- Decrementer une liste binaire\n"
//               "8- Suppression a un rang quelconque\n"
//               "9- Fusion\n"
//               "10- Supprimer la liste (cela a pour effet de fermer le programme)\n"
//               "11- Trier une liste\n"
//               "12- Test d'egalite de deux listes\n"
//               "13- Concatenation de deux listes\n"
//               "14- Une liste est-elle extraite\n"
//               "15- Quitter\n"
//               "---------------------------------------------------\n");
//        do {
//            printf("\nChoix : ");
//            scanf("%d", &choice);
//        } while (choice < 1 || choice > 15);
//
//
//        switch (choice) {
//
//            case 1:
//                printf("--Insertion --\n");
//                printf("Entrez une valeur : \n");
//                scanf("%d", &val);
//                show(list);
//                insert(list, val);
//                show(list);
//                break;
//            case 2:
//                printf("--Insertion a un rang--\n");
//                printf("Entrez une valeur : \n");
//                scanf("%d", &val);
//                printf("Entrez un rang : \n");
//                scanf("%d", &position);
//                show(list);
//                printf("%d insere au rang %d: \n", val, position);
//                insertElementByKey(list, position, val);
//                show(list);
//                break;
//            case 3:
//                printf("--Taille de la liste--\n");
//                show(list);
//                printf("Taille de la liste : %d \n", size(list));
//                break;
//            case 4:
//                printf("--Affichage--\n");
//                show(list);
//                break;
//            case 5:
//                printf("--Trouver un element--\n");
//                printf("Entrez une valeur : \n");
//                scanf("%d", &val);
//                show(list);
//                int res = find(list, val);
//                if(res == 1) printf("%d est present dans la liste\n", val);
//                else printf("%d n'est pas present dans la liste\n", val);
//                break;
//            case 6:
//                printf("--Incrementation liste binaire--\n");
//                show(list);
//                show(incrementListBinary(list));
//                break;
//            case 7:
//                printf("--Decrementation liste binaire--\n");
//                show(list);
//                show(decrementListBinary(list));
//                break;
//            case 8:
//                printf("--Supression a un rang--\n");
//                printf("Entrez un rang : \n");
//                scanf("%d", &position);
//                printf("Element supprimer au rang %d : \n", position);
//                show(list);
//                deleteElementByKey(list, position);
//                show(list);
//                break;
//            case 9:
//                printf("--Fusion de deux liste--\n");
//                printf("Liste 1 : \n");
//                show(list);
//                printf("Liste 2 : \n");
//                show(list2);
//                printf("Liste fusionne : \n");
//                show(fusion(list, list2));
//                break;
//
//            case 10:
//                printf("--Suppresion d'une liste--\n");
//                delete(list);
//                break;
//
//            case 11:
//                printf("--Trie--\n");
//                printf("Liste non triee : \n");
//                show(list);
//                sort(list);
//                printf("Liste triee : \n");
//                show(list);
//                break;
//            case 12:
//                printf("--Egale--\n");
//                printf("Liste 1 : \n");
//                show(list);
//                printf("Liste 2 : \n");
//                show(list2);
//                int eq = equals(list, list2);
//                if(eq == 1) printf("Les deux listes sont egale\n");
//                else printf("Les deux listes ne sont pas egale\n");
//                break;
//
//            case 13:
//                printf("--Concatenation--\n");
//                printf("Liste 1 : \n");
//                show(list);
//                printf("Liste 2 : \n");
//                show(list2);
//                concatenation(list, list2);
//                show(list);
//            case 14:
//                printf("--Concatenation--\n");
//                printf("Liste 1 : \n");
//                show(list);
//                printf("Liste 2 : \n");
//                show(list2);
//                if (isExtract(list, list2)) printf("Liste 2 est extraite de liste 1");
//                else printf("Liste 2 n'est pas extraite de liste 1");
//                break;
//            case 15: quit = 0;
//        }
//    } while (quit);

    return 0;
}
