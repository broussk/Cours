#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"


Data* initData(const char *symboles, const int *poids, int size){
    Data* data = malloc(size * sizeof(Data));
    int i;
    for(i = 0; i < size; i++){
        data[i].symbole = symboles[i];
        data[i].poids = poids[i];
    }
    return data;
}


Forest* initForest(Data *data, Node* tree, int size){
    Forest *forest = malloc(size * sizeof(Forest)) ;
    for(int i=0; i<size; i++){
        forest[i].tree = malloc(sizeof(Node));
        tree = forest[i].tree;
        tree->pere = NULL;
        tree->left=NULL;
        tree->right=NULL;
        tree->symbole = data[i].symbole;
        forest[i].poids = data[i].poids;
    }
    return forest;
}

Node* pere(Node* left, Node* right){
    Node *racine = malloc(sizeof(Node));
    racine->pere = NULL;
    racine->left = left;
    racine->right = right;
    left->pere = racine;
    right->pere = racine;

    return  racine;
}

int findIndice(Forest *forest, int i, int j){
    return 0;
}


void huffman(Forest *forest, Node *tree){
    int i, j;
    int n = sizeof(*forest);
    while(n > 1){
        findIndice(forest, i, j);
        tree = pere(forest[i].tree, forest[j].tree);
        forest[i].poids =  forest[i].poids + forest[j].poids;
        forest[j].poids =forest[n].poids;
        forest[j].tree =forest[n].tree;
        forest[i].tree = tree;
        n--;
    }
}


void showData(Data *data, int size){
    for(int i = 0; i < size; i++){
        printf("| %c |",data[i].symbole);
    }
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("| %d |", data[i].poids);
    }
    printf("\n");
}