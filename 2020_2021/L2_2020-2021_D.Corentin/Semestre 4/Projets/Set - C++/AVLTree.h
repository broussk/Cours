#include<iostream>
#include "Node.h"

#ifndef SET_AVLTREE_H
#define SET_AVLTREE_H

using namespace std;

/**
 * Class AVLTree
 * @authors Corentin Dupont & Owen Lacroix
 * @version 23/03/2021
 */
template <class T>
class AVLTree {

private:

    /**
     * Attribut d'un arbre
     */
    Node<T> *root; //la racine

    /**
     * Fonction permettant de récupèrer la hauteur de l'arbre
     * @param tree l'arbre
     * @return la hauteur de l'arbre
     */
    int getHeight(Node<T> *tree){
        int height = 0;
        /* si l'arbre est nullptr alors la hauteur est de 0 */
        if(tree != nullptr){
            /* calcule récursivement la hauteur du sous arbre de gauche */
            int hl = getHeight(tree->getLeft()) ? getHeight(tree->getLeft()) : 0;
            /* calcule récursivement la hauteur du sous arbre de droit */
            int hr = getHeight(tree->getRight()) ? getHeight(tree->getRight()) : 0;
            /*  hauteur = la plus grande hauteur entre hl et hr +1 */
            height = std::max(hl, hr) + 1;
        }

        return height;
    }

    /**
     * Fonction permettant de récupèrer le coefficient l'équilibre de l'arbre
     * @param tree l'arbre
     * @return le coefficient d'équilibre de l'arbre
     */
    int getBalance(Node<T> *tree){
        /* le coefficient d'équilibre est la différence de la hauteur du sous arbre gauche et sous arbre droit */
        return getHeight(tree->getLeft()) - getHeight(tree->getRight());
    }

    /**
     * Fonction permettant de réaliser une double rotation droite sur un noeud
     * @param node le noeud
     * @return le noeud après la double rotation droite
     */
    Node<T> *doubleRightRotation(Node<T> *node){
        /* noeud temporaire qui sera le nouveau noeud (celui qui a eu la double rotation droite) */
        Node<T> *tmp;
        /* sous noeud droit de l'ancien noeud affecté à tmp */
        tmp = node->getRight();
        /* sous noeud gauche de tmp assigné au sous noeud droit de l'ancien noeud */
        node->setRight(tmp->getLeft());
        /* ancien noeud modifié est affecté au sous noeud gauche de tmp => nouveau noeud équilibré */
        tmp->setLeft(node);

        return tmp;
    }

    /**
     * Fonction permettant de réaliser une double rotation gauche sur un noeud
     * @param node le noeud
     * @return le noeud après la double rotation gauche
     */
    Node<T> *doubleLeftRotation(Node<T> *node){
        /* noeud temporaire qui sera le nouveau noeud (celui qui a eu la double rotation gauche) */
        Node<T> *tmp;
        /* sous gauche droit de l'ancien noeud affecté à tmp */
        tmp = node->getLeft();
        /* sous noeud droit de tmp assigné au sous noeud gauche de l'ancien noeud */
        node->setLeft(tmp->getRight());
        /* ancien noeud modifié est affecté au sous noeud droit de tmp => nouveau noeud équilibré */
        tmp->setRight(node);

        return tmp;
    }


    /**
     * Fonction permettant de réaliser une rotation gauche-droite sur un noeud
     * @param node le noeud
     * @return le noeud après la double rotation gauche-droite
     */
    Node<T> *leftRightRotation(Node<T> *node){
        /* noeud temporaire qui sera le nouveau noeud (celui qui a eu la rotation gauche-droite) */
        Node<T> *tmp;
        /* sous noeud gauche de l'ancien noeud affecté à tmp */
        tmp = node->getLeft();
        /* on applique une double rotation droite à tmp puis on l'affecte au sous noeud gauche de l'ancien noeud */
        node->setLeft(doubleRightRotation(tmp));

        /* on applique une double rotation gauche sur l'ancien noeud modifié => nouveau noeud équilibré */
        return doubleLeftRotation(node);
    }

    /**
     * Fonction permettant de réaliser une rotation droite-gauche sur un noeud
     * @param node le noeud
     * @return le noeud après la double rotation droite-gauche
     */
    Node<T> *rightLeftRotation(Node<T> *node){
        /* noeud temporaire qui sera le nouveau noeud (celui qui a eu la rotation droite-gauche ) */
        Node<T> *tmp;
        /* sous noeud droit de l'ancien noeud affecté à tmp */
        tmp = node->getRight();
        /* on applique une double rotation gauche à tmp puis on l'affecte au sous noeud droit de l'ancien noeud */
        node->setRight(doubleLeftRotation(tmp));

        /* on applique une double rotation droite sur l'ancien noeud modifié => nouveau noeud équilibré */
        return doubleRightRotation(node);
    }

    /**
     * Fonction permettant d'équilibrer un arbre
     * @param tree l'arbre à équilibrer
     * @return l'arbre équilibré
     */
    Node<T> *balance(Node<T> *tree){
        /* on récupère le coefficient d'équilbre de l'arbre */
        int balance = getBalance(tree);

        /* le sous arbre gauche est supérieur au sous arbre droit */
        if(balance > 1){
            /* le sous arbre gauche du sous arbre gauche est supérieur au sous arbre droit du sous arbre gauche */
            if(getBalance(tree->getLeft()) > 0)
                /* on applique à l'arbre une double rotation gauche */
                tree = doubleLeftRotation(tree);
            else
                /* on applique à l'arbre une rotation gauche-droite */
                tree = leftRightRotation(tree);

        }
        /* le du sous arbre droit est supérieur au sous arbre gauche */
        else if (balance < -1){
            /* le sous arbre gauche du sous arbre droit est supérieur au sous arbre droit du sous arbre droit */
            if(getBalance(tree->getRight()) > 0)
                /* on applique à l'arbre une rotation droite-gauche */
                tree = rightLeftRotation(tree);
            else
                /* on applique à l'arbre une double rotation droite */
                tree = doubleRightRotation(tree);
        }

        return tree;
    }

    /**
     * Fonction permettant d'inserer un nouveau noeud dans l'arbre
     * @param tree l'arbre
     * @param value la valeur du noeud à ajouter
     * @return l'arbre équilibré avec le nouveau noeud ajouté
     */
    Node<T> *insertNode(Node<T> *tree, const T& value) {
        /* l'arbre est vide */
        if(tree == nullptr)
            /* on crée un nouveau celui de la racine de l'arbre */
            tree = new Node<T>(value);
        /* valeur à insérer inferieur à la valeur racine */
        else if (value < tree->getValue())
            /* noeud inséré récursivement dans les sous noeuds gauche */
            tree->setLeft(insertNode(tree->getLeft(), value));
        /* valeur à insérer supérieure à la valeur racine */
        else if (value > tree->getValue())
            /* noeud inséré récursivement dans les sous noeuds droit */
            tree->setRight(insertNode(tree->getRight(), value));
        else
            /* si value == tree->value on ignore l'insertion */
            cout<<" La valeur \""<< value <<"\" est deja presente dans l'arbre. Son insertion sera ignoree."<<endl;

        /* on ajuste l'équilibre de l'arbre */
        tree = balance(tree);

        return tree;
    }

    /**
     * Fonction permettant de parcourir l'arbre en preorder
     * @param tree l'arbre à parcourir
     */
    void preorder(Node<T> *tree){
        /* si nullptr on effectue pas le parcourt */
        if(tree != nullptr){
            /* affiche la valeur du noeud */
            cout << tree->getValue() << endl;
            /* on parcourt récursivement en "preorder" jusqu'au sous noeud gauche */
            preorder(tree->getLeft());
            /* on parcourt récursivement en "preorder" jusqu'au sous noeud droit */
            preorder(tree->getRight());
        }
    }

    /**
     * Fonction permettant de parcourir l'arbre en inorder
     * @param tree l'arbre à parcourir
     */
    void inorder(Node<T> *tree){
        /* si nullptr on effectue pas le parcourt */
        if(tree != nullptr){
            /* on parcourt récursivement en "inorder" jusqu'au sous noeud gauche */
            inorder(tree->getLeft());
            /* affiche la valeur du noeud */
            cout << tree->getValue() << endl;
            /* on parcourt récursivement en "inorder" jusqu'au sous noeud droit */
            inorder(tree->getRight());
        }
    }

    /**
     * Fonction permettant de parcourir l'arbre en postorder
     * @param tree l'arbre à parcourir
     */
    void postorder(Node<T> *tree){
        /* si nullptr on effectue pas le parcourt */
        if(tree != nullptr){
            /* on parcourt récursivement en "postorder" jusqu'au sous noeud gauche */
            postorder(tree->getLeft());
            /* on parcourt récursivement en "postorder" jusqu'au sous noeud droit */
            postorder(tree->getRight());
            /* affiche la valeur du noeud */
            cout << tree->getValue() << endl;
        }
    }

    /**
     * Fonction permettant permettant d'afficher l'arbre graphiquement
     * @param tree l'arbre à afficher
     * @param minHeight la hauteur minimum de l'arbre = 0
     * @param maxHeight la hauteur de l'arbre
     */
    void printTree(Node<T> *tree, int minHeight, int maxHeight){
        if(tree != nullptr){
            printTree(tree->getRight(), minHeight + 1, maxHeight);
            for(int i = 0; i < minHeight; i++){
                std::cout << "    ";
            }
            std::cout << tree->getValue() << std::endl;
            printTree(tree->getLeft(), minHeight + 1, maxHeight);
        } else{
            if(minHeight < maxHeight){
                printTree(nullptr, minHeight + 1, maxHeight);
                for(int i = 0; i < minHeight; i++){
                    std::cout << "    " ;
                }
                std::cout << "..\n" << std::endl;
                printTree(nullptr, minHeight + 1, maxHeight);
            }
        }
    }

public:

    /**
     * Constructeur par défaut
     */
    AVLTree() : root(nullptr) {};

    /**
     * Constructeur par défaut
     */
    AVLTree(const AVLTree<T> &copy) : root(copy) {};

    /**
     * Déconstructeur
     */
    ~AVLTree(){
        if (root != nullptr) delete root;
    }

    /**
     * Fonction permettant de récupèrer la racine de l'arbre
     * @return l'arbre
     */
    Node<T> *getRoot() {return root;}

    /**
     * Fonction permettant de modifier la racine de l'arbre
     * @param root le nouvelle racine
     */
    void setRoot(Node<T> *root) {this->root = root;}


    /**
     * Fonction permettant d'inserer une valeur dans l'arbre
     * @param value la valeur à inserer
     */
    void insert(const T& value){
        root = insertNode(root, value);
    }

    /**
     * Fonction permettant de savoir si un arbre est équilibré
     * @return vrai / faux
     */
    bool isBalanced(){
        return getBalance(root) != -1;
    }

    /**
     * Fonction permettant de savoir si un arbre est vide
     * @return vrai / faux
     */
    bool isEmpty(){
        return root == nullptr;
    }

    /**
     * Fonction permettant de parcourir l'arbre en preorder
     */
    void preorder(){
        preorder(root);
    }

    /**
     * Fonction permettant de parcourir l'arbre en inorder
     */
    void inorder(){
        inorder(root);
    }

    /**
     * Fonction permettant de parcourir l'arbre en postorder
     */
    void postorder(){
        postorder(root);
    }

    /**
     * Fonction permettant d'afficher l'arbre graphiquement
     */
    void print(){
        printTree(root, 0, getHeight(root));
    }
};


#endif //SET_AVLTREE_H
