#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
/**
 * Méthode permettant de créer une pile
 * @return une pile
 */
Pile* create(){
    Pile *pile = malloc(sizeof(*pile));
    pile->first = NULL;
    return pile;
}

/**
 * Méthode permettant d'empiler une valeur dans une pile
 * @param pile la pile
 * @param value la valeur
 */
void push(Pile* pile, int value){
    Cell *cell = malloc(sizeof(*cell));

    //On verifie que la pile et la nouvelle cellule n'est pas NULL
    if(pile == NULL || cell == NULL) exit(1);

    //On empile la valeur
    cell->value = value;
    cell->next = pile->first;
    pile->first = cell;
}

/**
 * Méthode permettant de dépiler une pile
 * @param pile la pile
 */
int pop(Pile* pile){
    //On verifie que la pile n'est pas NULL
    if (pile == NULL) exit(1);
    int val = 0;

    //On dépile la première valuer de la liste
    Cell *cellToUnstack = pile->first;
    val = pile->first->value;
    pile->first = cellToUnstack->next;
    free(cellToUnstack);

    return val;
}

/**
 * Méthode permettant de retourner le sommet d'une pile
 * @param pile la pile
 * @return le sommet de la pile
 */
int top(Pile* pile){
    return pile == NULL ? -1 : pile->first->value;
}

/**
 * Méthode permettant de vérifier si une pile est vide
 * @param pile la pile
 * @return 0 ou 1
 */
int isEmpty(Pile* pile){
    return pile->first == NULL ? 1 : 0;
}

/**
 * Méthode permettant de retourner la taille d'une pile
 * @param pile la pile
 * @return la taille de la pile
 */
int size(Pile* pile){
    int size = 0;
    //On verifie que la pile n'est pas NULL
    if (pile == NULL) exit(1);

    //Tant que la cellule courante n'est pas null on increment la variable size de 1
    Cell *current = pile->first;
    while (current != NULL){
        size++;
        current = current->next;
    }
    return size;
}

/**
 * Méthode permettant de vider une pile
 * @param pile la pile
 */
void clear(Pile* pile){
    //On verifie que la pile n'est pas NULL
    if(pile == NULL) exit(1);
    //Tant que la cellule courante n'est pas null on dépile la pile
    while(pile->first != NULL){
        pop(pile);
    }
}

/**
 * Méthode permettant d'afficher une pile
 * @param pile la pile
 */
void show(Pile* pile){
    //On verifie que la pile n'est pas NULL
    if (pile == NULL) exit(1);
    //Tant que la cellule courante n'est pas null on affiche son contenu
    Cell *current = pile->first;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}

/**
 * Méthode permettant de vérifier si une valeur est contenue dans la pile
 * @param pile la pile
 * @param value la valeur recherchée
 * @return 0 ou 1
 */
int contain(Pile *pile , int value){
    //On verifie que la pile n'est pas NULL
    if (pile == NULL) exit(1);
    //Tant que la cellule courante n'est pas null on verifie si sa valeur est égale à la valeur recherché
    Cell *current = pile->first;
    while (current != NULL){
        if(current->value == value) return 1;
        current = current->next;
    }
    return 0;
}

/**
 * Méthode permettant de vérifier si deux piles sont égales
 * @param p1 la première pile
 * @param p2 la seconde pile
 * @return 0 ou 1
 */
int equals(Pile *p1, Pile *p2){
    //On verifie que les deux piles ne sont pas NULL
    if (p1 == NULL || p2 == NULL) exit(1);
    //On verifie que les deux piles ont la même taille
    if(size(p1) != size(p2)){
        printf("The size of the two stacks are not equal. \n");
        return 0;
    }
    //Tant que la cellule courante de la pile 1 n'est pas null on verifie si sa valeur est contenu dans la deuxième pile
    Cell *p1_value = p1->first;
    if(p1_value == NULL) exit(1);
    while (p1_value != NULL){
        if (!contain(p2, p1_value->value)) return 0;
        p1_value = p1_value->next;
    }
    return 1;
}

/**
 * Méthode permettant de restaurer une pile sans une valeur donnée
 * @param pile la pile
 * @param value la valeur
 */
void searchAndRestore(Pile *pile, int value){
    //On verifie que la pile n'est pas null
    if(pile == NULL) exit(1);
    Pile *finalPile = create();
    Cell *val = pile->first;
    //On verifie que la nouvelle pile n'est pas null
    if(finalPile == NULL) exit(1);

    //Tant que la cellule courante n'est pas null on verifie si sa valeur n'est pas égale à la valeur donnée, si c'est le cas on empile la valeur dans la nouvelle pile
    while (val != NULL){
        if(val->value != value) push(finalPile, val->value);
        val = val->next;
    }
    *pile = *finalPile;
}