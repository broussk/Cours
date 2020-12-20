#ifndef __CELLULE__H__
#define __CELLULE__H__

//Structure Cellule

typedef struct cellule{
    int sommetGraphe;
    struct cellule *predecesseur;
    struct cellule *successeur;
}Cellule;

// Prototypes

void initCellule(Cellule *c, int sommetGraphe);


#endif // !__CELLULE__H__
