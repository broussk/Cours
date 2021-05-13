#ifndef TP_HUFFMAN_H
#define TP_HUFFMAN_H

typedef struct Node{
    char symbole;
    struct Node *pere;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Data{
    char symbole;
    int poids;
} Data;


typedef struct Forest{
    struct Node *tree;
    int poids;
} Forest;


Data* initData(const char *symboles, const int *poids, int size);
Forest* initForest(Data *data, Node *tree, int size);
void showData(Data *data, int size);
Node* pere(Node* left, Node* right);
int findIndice(Forest *forest, int i, int j);
void huffman(Forest *forest, Node *tree);

#endif //TP_HUFFMAN_H
