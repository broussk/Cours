#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * Methode permettant de créer une liste chainée
 * @return une liste chainée
 */
List* create(){
    List *list = malloc(sizeof(*list));
    Cell *cell = malloc(sizeof(*cell));
    //On vérifie que la liste ou la cellule n'est pas NULL
    if (list == NULL || cell == NULL) {
        printf("Memory allocation problem of the list or cell !");
        exit(1);
    }
    //On initialise la première cellule de la liste
    cell->value = -1;
    cell->next = NULL;
    list->first = cell;

    return list;
}

/**
 * Methode permettant d'inserer un élément à la fin d'une liste chainée
 * @param list la liste
 * @param val la valeur à ajouter
 */
void insert(List *list, int val) {
    Cell *new = malloc(sizeof(*new));
    //On vérifie que la liste ou la nouvelle cellule n'est pas NULL
    if (list == NULL || new == NULL) {
        printf("List cannot be NULL or/and Memory allocation problem of the new cell !");
        exit(1);
    }
    //Si la taille de la liste est égale à 1 et que la valuer de la première cellule est -1 alors on remplace -1 par la valeur à ajouter
    if(list->first->value == -1 && size(list) == 1) list->first->value = val;
    else {
        //Sion on ajoute la valeur à la fin de la liste
        new->value = val;
        new->next = NULL;

        Cell* current = list->first;
        while(current->next != NULL) current = current->next;

        current->next = new;
    }
}

/**
 * Methode permettant d'inserer un élément à un rang précis d'une liste chainée
 * @param list la liste
 * @param key le rang
 * @param val la valeur à ajouter
 */
void insertElementByKey(List *list, int key, int val) {
    //On vérifie que la liste n'est pas NULL
    if (list == NULL) {
        printf("\nList cannot be NULL !");
        exit(1);
    }
    //On vérifie que le rang ne dépasse pas la taille de la liste ou que le rang ne soit pas négatif
    if (key > size(list) || key < 0) {
        printf("\nIndex overflow: %d", key);
        return;
    }
    //On vérifie le est agales à la taille de la liste on appelle la méthode pour inserer à la fin de la liste
    if (key == size(list)) insert(list, val);
    else{
        //Sinon on ajoute à la valuer au rang demandé
        Cell *new = malloc(sizeof(*new));
        //On vérifie que la nouvelle cellule n'est pas NULL
        if (new == NULL) {
            printf("Memory allocation problem of the new cell !");
            exit(1);
        }
        new->value = val;
        Cell *current = list->first;
        for(int i = 2; i <= key - 1; i++){
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

/**
 * Methode permettant de supprimer un élément à un rang précis d'une liste chainée
 * @param list la liste
 * @param key le rang
 * @param val la valeur à supprimer
 */
void deleteElementByKey(List *list, int key) {
    int i;

    Cell *del, *prev;

    //On vérifie que la liste n'est pas NULL
    if (list == NULL) {
        printf("List cannot be NULL !");
        exit(1);
    }
    //On vérifie que le rang ne dépasse pas la taille de la liste ou que le rang ne soit pas négatif
    if (key > size(list) || key < 0) {
        printf("\nIndex overflow: %d", key);
        exit(1);
    }

    //On position la cellule précédente et à supprimer au début de la liste
    del = list->first;
    prev = list->first;

    //On supprime l'élément au rang demandé
    for(i=2; i<=key; i++){
        prev = del;
        del = del->next;

        if(del == NULL)
            break;
    }
    if(del != NULL){
        if(del == list->first)
            list->first = list->first->next;

        prev->next = del->next;
        del->next = NULL;
        free(del);
    }
}

/**
 * Methode permettant de chercher si une valeur est présente dans une liste chainée
 * @param list la liste
 * @param val la valeur à chercher
 * @return 1 ou 0
 */
int find(List *list, int val){
    //On vérifie que la liste n'est pas NULL
    if (list == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }
    //On parcourt la liste tant que la cellule courante n'est pas null
    //Si la valeur de la cellule courante est égale à la valeur recherchée on retourne 1 sinon 0
    Cell *current = list->first;
    while (current != NULL){
        if(current->value == val) return 1;
        current = current->next;
    }
    return 0;
}

/**
 * Methode permettant de concaténer deux listes
 * @param l1 la première liste
 * @param l2 la deuxième liste
 */
void concatenation(List *l1, List *l2){

    //On vérifie que les listes ne sont pas NULL
    if (l1 == NULL || l2 == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }

    //On se positionne au début de la première liste puis on la parcourt jusqu'à arriver à la dernière cellule puis on lui ajoute la seconde liste
    Cell *lastL1 = l1->first;
    while (lastL1 != NULL){
        if(lastL1->next != NULL) lastL1 = lastL1->next;
        else break;
    }
    lastL1->next = l2->first;
}

/**
 * Methode permettant de calculer la taille d'une liste chainée
 * @param list la liste
 * @return la taille de la liste
 */
int size(List* list){
    int size = 0;
    //On vérifie que la liste n'est pas NULL
    if (list == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }
    //On parcourt la liste tant que la cellule courante n'est pas null on incrémente la variable size de 1
    Cell *current = list->first;
    while (current != NULL){
        size++;
        current = current->next;
    }
    return size;
}

/**
 * Methode permettant d'incrémenter de 1 une liste chainée binaire
 * @param list la liste binaire
 * @return la nouvelle liste binaire incrémentée de 1
 */
List *incrementListBinary(List* list){
    int bin[128], i = 0, value = 0, temp, decimalValue, pow, last_digit, bit = 0;
    List *listFinal = create();

    //On vérifie bien qu'aucune list n'est NULL
    if (list == NULL || listFinal == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }

    //On parcourt la liste pour vérifier si il s'agit bien d'une liste binaire
    Cell *current = list->first;
    while (current != NULL){
        if(current->value != 0 && current->value!= 1){
            printf("This is not a binary chained list. \n");
            exit(0);
        }
        current = current->next;
    }

    //On se remet au début de la liste puis on la parcourt pour créer un seul entier avec toutes les cellules de la liste
    current = list->first;
    while (current != NULL){
        value *= 10;
        value += current->value;
        current = current->next;
        i++;
    }

    temp = value;
    decimalValue = 0;
    pow = 1;

    //Convertit le nombre binaire initiale en décimale
    while (temp) {
        last_digit = temp % 10;
        temp = temp / 10;
        decimalValue += last_digit * pow;
        pow = pow * 2;
    }

    //On incrémente la valeur décimale de 1
    decimalValue++;

    //On re convertit la nouvelle valeur decimale en binaire
    for(i = 0; decimalValue > 0; i++){
        bin[i] = decimalValue % 2;
        decimalValue = decimalValue / 2;
        bit++;
    }

    //Insertion du nouveau nombre binaire dans la nouvelle liste
    for (i = bit - 1; i >= 0; i--){
        insert(listFinal, bin[i]);
    }

    return listFinal;
}

/**
 * Methode permettant de décrémenter de 1 une liste chainée binaire
 * @param list la liste binaire
 * @return la nouvelle binaire decrémentée de 1
 */
List *decrementListBinary(List* list){
    int bin[128], i = 0, value = 0, temp, decimalValue, pow, last_digit, bit = 0;
    List *listFinal = create();

    //On vérifie bien qu'aucune list n'est NULL
    if (list == NULL || listFinal == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }

    //On parcourt la liste pour vérifier si il s'agit bien d'une liste binaire
    Cell *current = list->first;
    while (current != NULL){
        if(current->value != 0 && current->value!= 1){
            printf("This is not a binary chained list. \n");
            exit(0);
        }
        current = current->next;
    }

    //On se remet au début de la liste puis on la parcourt pour créer un seul entier avec toutes les cellules de la liste
    current = list->first;
    while (current != NULL){
        value *= 10;
        value += current->value;
        current = current->next;
        i++;
    }

    temp = value;
    decimalValue = 0;
    pow = 1;

    //Convertit le nombre binaire initiale en décimale
    while (temp) {
        last_digit = temp % 10;
        temp = temp / 10;
        decimalValue += last_digit * pow;
        pow = pow * 2;
    }

    //On decrement la valeur décimale de 1
    decimalValue--;

    //convertit la nouvelle valeur decimale en binaire
    for(i = 0; decimalValue > 0; i++){
        bin[i] = decimalValue % 2;
        decimalValue = decimalValue / 2;
        bit++;
    }

    //Insertion du nouveau nombre binaire dans la nouvelle liste
    for (i = bit - 1; i >= 0; i--){
        insert(listFinal, bin[i]);
    }

    return listFinal;
}

/**
 * Methode permettant de fusionner deux listes
 * @param l1 la première liste
 * @param l2 la seconde liste
 * @return la liste fusionnée
 */
List *fusion(List *l1, List *l2){
    List *l3 = create();

    //On vérifie bien qu'aucune list n'est NULL
    if (l1 == NULL || l2 == NULL || l3== NULL ){
        printf("List cannot be NULL !");
        exit(1);
    }

    int i, aIndex,  bIndex;
    int fullLength = size(l1) + size(l2);
    //On se place au début des deux listes puis on les fusionnes
    Cell *p1 = l1->first;
    Cell *p2 = l2->first;

    for (i = 0, aIndex = 0, bIndex = 0; i < fullLength; i++) {
        if (aIndex >= size(l1) ){
            insert(l3, p2->value);
            p2 = p2->next;
            bIndex ++;
        } else if (bIndex >= size(l2)){
            insert(l3, p1->value);
            p1 = p1->next;
            aIndex ++;
        } else if (p1->value > p2->value) {
            insert(l3, p2->value);
            p2 = p2->next;
            bIndex++;
        } else {
            insert(l3, p1->value);
            p1 = p1->next;
            aIndex++;
        }
    }
    return l3;
}

/**
 * Methode permettant d'afficher le contenu d'une liste
 * @param list la liste
 */
void show(List *list){
    //On vérifie que la liste n'est pas NULL
    if (list == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }
    //On vérifie que la taille de la liste n'est pas egale à 0
    if(size(list) == 0){
        printf("List is empty\n");
        return;
    }
    //On parcourt la liste pour chaque cellule on affiche son contenu
    Cell *current = list->first;
    while (current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * Methode permettant de supprimer une liste
 * @param list la liste
 */
void delete(List *list){
    //On vérifie que la liste n'est pas NULL
    if (list == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }
    //On parcourt la liste pour chaque cellule on la de-alloue
    while(list->first != NULL){
        Cell *del = list->first;
        list->first = list->first->next;
        free(del);
    }
    //On de-alloue la liste
    free(list);
    printf("The list has been deleted !");
}

/**
 * Methode permettant de trier une liste dans l'ordre croissant
 * @param list la liste
 */
void sort(List *list){
    int stop;
    Cell *current, *temp = NULL;

    //On vérifie que la liste n'est pas NULL
    if (list == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }

    //Tant que stop n'est pas à 1 on continue de parcourir la liste et de la trier
    do{
        stop = 0;
        current = list->first;
        while (current->next != temp){
            if(current->value > current->next->value){
                int tmp = current->value;
                current->value = current->next->value;
                current->next->value = tmp;
                stop = 1;
            }
            current = current->next;
        }
        temp = current;
    } while (stop);
}

/**
 * Methode permettant de vérifier si deux liste sont égales
 * @param l1 la première liste
 * @param l2 la seconde liste
 */
int equals(List *l1, List *l2){
    //On vérifie que la liste n'est pas NULL
    if (l1 == NULL || l2 == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }
    //Tant que la cellule courante n'est pas null, on verifie si sa valeur est contenu dans la seconde liste
    Cell *currentL1 = l1->first;
    while (currentL1 != NULL){
        if(find(l2, currentL1->value) == 0) return 0;
        currentL1 = currentL1->next;
    }
    return 1;
}


/**
 * Methode permettant de vérifier si une liste est extrailte
 * @param l1 liste originale
 * @param l2 la liste à extraire
 */
int isExtract(List *l1, List *l2){
    if (l1 == NULL || l2 == NULL){
        printf("List cannot be NULL !");
        exit(1);
    }

    if(size(l2) > size(l1)){
        printf("The second list extracted cannot be larger than the original list");
        exit(0);
    }
    if (size(l2) > size(l1)) equals(l1, l2);

    int cpt = 0;
    int result = 0;

    Cell *firstElmtL1 = l1->first;
    Cell *firstElmtL2 = l2->first;

    while (firstElmtL1 != NULL){
        if(firstElmtL2!= NULL){
            if(firstElmtL2->value == firstElmtL1->value){
                firstElmtL2 = firstElmtL2->next;
                cpt++;
            } else {
                cpt = 0;
                firstElmtL2 = l2->first;
            }
        }
        if(cpt == size(l2)){
            result = 1;
            break;
        }
        firstElmtL1 = firstElmtL1->next;
    }

    return result;
}