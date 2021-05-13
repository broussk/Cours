#ifndef H_LIST
#define H_LIST


typedef struct Cell{
    int value;
    struct Cell *next;
} Cell;

typedef struct List{
    Cell *first;
} List;

List* create();
void insert(List* list, int val);
void insertElementByKey(List* list, int key, int val);
int find(List *list, int val);
void concatenation(List *l1, List *l2);
List *incrementListBinary(List* list);
List *decrementListBinary(List* list);
List *fusion(List *l1, List *l2);
void show(List* list);
int size(List* list);
int equals(List *l1, List *l2);
int isExtract(List *l1, List *l2);
void sort(List* list);
void deleteElementByKey(List *list, int key);
void delete(List* List);

#endif
