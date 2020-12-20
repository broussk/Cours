#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

void initCellule(Cellule *c, int val){
    c->predecesseur = NULL;
    c->sommetGraphe = val;
    c->successeur = NULL;
}