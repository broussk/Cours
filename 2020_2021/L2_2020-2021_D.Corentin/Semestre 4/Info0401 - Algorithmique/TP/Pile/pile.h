#ifndef H_PILE
#define H_PILE

typedef struct Cell{
    int value;
    struct Cell *next;
} Cell;

typedef struct Pile{
    Cell *first;
} Pile;

Pile* create();
void push(Pile *pile, int value);
int pop(Pile *pile);
void show(Pile *pile);
int top(Pile *pile);
int isEmpty(Pile *pile);
int size(Pile* pile);
int contain(Pile *pile, int value);
int equals(Pile *p1, Pile *p2);
void clear(Pile* pile);
void searchAndRestore(Pile *pile, int value);
#endif
