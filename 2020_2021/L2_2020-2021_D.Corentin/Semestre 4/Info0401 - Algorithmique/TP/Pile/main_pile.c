#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/**
 * Méthode permettant de calculer Ackermann
 * @param n val 1
 * @param m val 2
 * @return Ackermann(va1, val2)
 */
int ack(int m, int n){
    Pile *p = create();
    push(p, m);
    push(p, n);

    while (isEmpty(p) == 0){
        n = top(p);
        pop(p);
        if(isEmpty(p) == 0){
            m = top(p);
            pop(p);
        } else {
            return n;
        }
        if(m==0){
            push(p, n + 1);
        } else if(n==0){
            push(p, m - 1);
            push(p, 1);
        } else {
            push(p, m - 1);
            push(p, m);
            push(p, n - 1);
        }
    }
    return top(p);
}



int main(){


    printf("--Ackermann--\n" );
    printf("A(2,1) = %d\n", ack(2,1));

//
    Pile* p = create();
    Pile* p2 = create();

    push(p2, 1);
    push(p2, 2);
    push(p2, 3);

    int quit = 1, choice, val;

    do{
        printf( "\n---------------------------------------------------"
                "\nMenu:\n"
                "1- Emplier\n"
                "2- Depiler\n"
                "3- Afficher la taile\n"
                "4- Afficher la pile\n"
                "5- Trouver un element\n"
                "6- Sommet\n"
                "7- Est-ce que la pile est vide ?\n"
                "8- Egalité de deux pile\n"
                "9- Rechercher et restaurer\n"
                "10- Vider la pile\n"
                "11- Quitter\n"
                "---------------------------------------------------\n");
        do {
            printf("\nChoix : ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 11);


        switch (choice) {

            case 1:
                printf("--Empiler--\n");
                printf("Entrez une valeur : \n");
                scanf("%d", &val);
                printf("Pile avant : \n");
                show(p);
                push(p, val);
                printf("Pile apres : \n");
                show(p);
                break;
            case 2:
                printf("--Depiler--\n");
                printf("Pile avant : \n");
                show(p);
                pop(p);
                printf("Pile apres : \n");
                show(p);
                break;
            case 3:
                printf("--Taille--\n");
                printf("Pile : \n");
                show(p);
                printf("Taille : %d", size(p));
                break;
            case 4:
                printf("--Affichage--\n");
                printf("Pile : \n");
                show(p);
                break;
            case 5:
                printf("--Trouver un element--\n");
                printf("Entrez une valeur : \n");
                scanf("%d", &val);
                printf("Pile : \n");
                show(p);
                int res = contain(p, val);
                if(res == 1) printf("%d est present dans la pile\n", val);
                else printf("%d n'est pas present dans la pile\n", val);
                break;
            case 6:
                printf("--Sommet--\n");
                printf("Pile : \n");
                show(p);
                printf("Sommet : %d\n", top(p));
                break;
            case 7:
                printf("--Vide ?--\n");
                printf("Pile : \n");
                show(p);
                int res2 = isEmpty(p);
                if(res2 == 1) printf("La pile est vide\n");
                else printf("La pile n'est pas vide\n");
                break;
            case 8:
                printf("--Egalite--\n");
                printf("Pile 1 : \n");
                show(p);
                printf("Pile 2 : \n");
                show(p2);
                int eq = equals(p, p2);
                if(eq == 1) printf("Les deux piles sont egale\n");
                else printf("Les deux piles ne sont pas egale\n");
                break;
            case 9:
                printf("--Rechercher et restaurer--\n");
                printf("Entrez une valeur : \n");
                scanf("%d", &val);
                printf("Pile avant : \n");
                show(p);
                searchAndRestore(p, val);
                printf("Pile apres : \n");
                show(p);
                break;

            case 10:
                printf("-Vider--\n");
                printf("Pile avant : \n");
                show(p);
                clear(p);
                printf("Pile apres : \n");
                show(p);
            case 11: quit = 0;
                break;
        }
    } while (quit);


    return 0;
}


