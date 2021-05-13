#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"

#define SIZE 6

int main(){
    char symboles[SIZE] = {'A', 'F', 'G','N', 'O', 'P'};
    int poids [SIZE] = {10, 8, 3, 25, 32, 7};

    Data *data = initData(symboles, poids, SIZE);

    printf("Tableau des donnees: \n");
    showData(data, SIZE);
}