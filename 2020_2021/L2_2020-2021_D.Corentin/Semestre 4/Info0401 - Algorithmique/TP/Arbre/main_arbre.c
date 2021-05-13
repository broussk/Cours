#include <stdio.h>
#include "arbre.h"


int main(){

    printf("\n------------ARBRE R&N-----------\n");

    Node *rn = createNode(7, NOIR);

    insert(rn, 3, ROUGE);
    insert(rn, 11, ROUGE);
    insert(rn, 2, NOIR);
    insert(rn, 5, NOIR);
    insert(rn, 9, NOIR);
    insert(rn, 13, NOIR);
    insert(rn, 17, ROUGE);


    printf("\n----------Pacours et affichage de l'arbre------------\n");

    formatTree(rn, 0, height(rn));
    printf("\nPacours sufixe : \n");
    sufixe(rn);
    printf("\nPacours infixe : \n");
    infixe(rn);
    printf("\nPacours postfixe : \n");
    postfixe(rn);

    printf("\n-------------------------------\n");

    printf("Est-il un arbre R&N ? %s\n", isRN(rn) ? "Oui" : "Non");
    printf("Minimum : %d \n", minimum(rn, rn->value));
    printf("Maximum : %d \n", maximum(rn, rn->value));
    printf("Nombre de noeud : %d \n", countNodes(rn));
    printf("Hauteur : %d \n", height(rn));
    printf("Hauteur noir : %d \n", countBlackHeight(rn));
    printf("5 est-il present dans l'arbre ? %s \n", contains(rn, 5) ? "Oui" : "Non");
    printf("99 est-il present dans l'arbre ? %s \n", contains(rn, 99) ? "Oui" : "Non");


    printf("\n => Insertion d'un noeud (14, NOIR) <= \n\n");
    insert(rn, 14, NOIR);

    printf("\n----------Pacours et affichage du nouvelle arbre------------\n");

    formatTree(rn, 0, height(rn));
    printf("\nPacours sufixe : \n");
    sufixe(rn);
    printf("\nPacours infixe : \n");
    infixe(rn);
    printf("\nPacours postfixe : \n");
    postfixe(rn);

    printf("\n-------------------------------\n");


    printf("Est-il un arbre R&N ? %s\n", isRN(rn) ? "Oui" : "Non");
    printf("Minimum : %d \n", minimum(rn, rn->value));
    printf("Maximum : %d \n", maximum(rn, rn->value));
    printf("Nombre de noeud : %d \n", countNodes(rn));
    printf("Hauteur : %d \n", height(rn));
    printf("Hauteur noir : %d \n", countBlackHeight(rn));
    printf("14 est-il present dans l'arbre ? %s \n", contains(rn, 14) ? "Oui" : "Non");
    printf("8 est-il present dans l'arbre ? %s \n", contains(rn, 8) ? "Oui" : "Non");


    printf("\n-----------Rotaion droite depuis la racine-----------\n");
    Node *rr = rightRotation(rn);

    printf("\nPacours sufixe : \n");
    sufixe(rr);
    printf("\nPacours infixe : \n");
    infixe(rr);
    printf("\nPacours postfixe : \n");
    postfixe(rr);



//    printf("\n-----------Rotaion gauche depuis la racine-----------\n");
//    Node *lr = leftRotation(rn);
//
//    printf("\nPacours sufixe : \n");
//    sufixe(lr);
//    printf("\nPacours infixe : \n");
//    infixe(lr);
//    printf("\nPacours postfixe : \n");
//    postfixe(lr);


    delete(rn);

    printf("\n------------ARBRE CLASSIQUE-----------\n");

    Node *tree = createNode(40, NONE);
    insert(tree, 20, NONE);
    insert(tree, 10, NONE);
    insert(tree, 30, NONE);
    insert(tree, 60, NONE);
    insert(tree, 50, NONE);
    insert(tree, 70, NONE);
    insert(tree, 5, NONE);
    insert(tree, 45, NONE);
    insert(tree, 55, NONE);

    formatTree(tree, 0, height(tree));
    printf("\nPacours sufixe : \n");
    sufixe(tree);
    printf("\nPacours infixe : \n");
    infixe(tree);
    printf("\nPacours postfixe : \n");
    postfixe(tree);


    Node *lca = findLCA(tree, 5, 30);
    printf("Ancetre commun de %d et %d est : %d\n", 5, 30, lca->value);

    printf("%d est-il ancetre commun de 5 et 30 ? %s\n", lca->value, isLCA(tree, lca, 5, 30) ? "Oui": "Non");


    delete(tree);


    return 0;
}
