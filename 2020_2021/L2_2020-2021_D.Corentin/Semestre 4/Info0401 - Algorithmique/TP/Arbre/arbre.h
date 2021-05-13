#ifndef TP_ARBRE_H
#define TP_ARBRE_H

enum colors{NONE = -1, NOIR = 0, ROUGE = 1};

typedef struct Node{
    int value;
    int color;
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(int val, enum colors color);
void insert(Node *tree, int value, enum colors color);
Node* leftRotation(Node* tree);
Node* rightRotation(Node* tree);
Node *getNode(Node *tree, int val);
Node *findLCA(Node *tree, int n1, int n2);
int isLCA(Node *tree, Node *nodeLCA, int n1, int n2);
int countBlackHeight(Node* tree);
int isRN(Node* tree);
int minimum(Node* tree , int mini);
int countNodes(Node *tree);
int equals(Node *tree, Node *tree2);
int maximum(Node* tree, int max);
int contains(Node* tree, int value);
int height(Node* tree);
void formatTree(Node *tree, int level, int levelMax);
void sufixe(Node *tree);
void infixe(Node *tree);
void postfixe(Node *tree);
void delete(Node *tree);

#endif //TP_ARBRE_H
