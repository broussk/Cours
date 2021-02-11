#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Pile* create(){
    Pile *pile = malloc(sizeof(*pile));
    pile->first = NULL;
    return pile;
}

void push(Pile* pile, int value){
    Cell *cell = malloc(sizeof(*cell));
    if(pile == NULL || cell == NULL) exit(EXIT_FAILURE);
    cell->value = value;
    cell->next = pile->first;
    pile->first = cell;
}

int pop(Pile* pile){
    if (pile == NULL) exit(EXIT_FAILURE);
    int val = 0;
    Cell *cellToUnstack = pile->first;
    if(cellToUnstack == NULL) exit(EXIT_FAILURE);

    val = pile->first->value;
    pile->first = cellToUnstack->next;
    free(cellToUnstack);

    return val;
}

int top(Pile* pile){
    return pile == NULL ? -1 : pile->first->value;
}

int isEmpty(Pile* pile){
    return pile->first == NULL ? 1 : 0;
}

int size(Pile* pile){
    int cpt = 0;
    Cell *current = pile->first;
    if (pile == NULL || current == NULL) exit(EXIT_FAILURE);
    while (current != NULL){
        cpt++;
        current = current->next;
    }
    return cpt;
}

void clear(Pile* pile){
    if(pile == NULL) exit(EXIT_FAILURE);
    while(pile->first != NULL){
        pop(pile);
    }
}

void show(Pile* pile){
    if (pile == NULL) exit(EXIT_FAILURE);
    Cell *current = pile->first;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}


int contain(Pile *pile , int value){
    if (pile == NULL) exit(EXIT_FAILURE);
    Cell *current = pile->first;
    while (current != NULL){
        if(current->value == value) return 1;
        current = current->next;
    }
    return 0;
}


int equals(Pile *p1, Pile *p2){
    if (p1 == NULL || p2 == NULL) exit(EXIT_FAILURE);
    if(size(p1) != size(p2)) exit(EXIT_FAILURE);
    Cell *p1_value = p1->first;
    if(p1_value == NULL) exit(EXIT_FAILURE);
    while (p1_value != NULL){
        if (!contain(p2, p1_value->value)) return 0;
        p1_value = p1_value->next;
    }
    return 1;
}