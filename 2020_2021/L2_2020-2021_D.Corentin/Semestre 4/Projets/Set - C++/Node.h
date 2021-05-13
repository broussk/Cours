#ifndef PROJET_CPP_NODE_H
#define PROJET_CPP_NODE_H

/**
 * Class Node
 * @authors Corentin Dupont & Owen Lacroix
 * @version 23/03/2021
 */
template <class T>
class Node {

private:

       /**
        * Attributs d'un noeud
        */
        T value;
        Node *parent;
        Node *left;
        Node *right;

public:

    /**
     * Constructeur par défaut
     */
    Node() : value(nullptr), parent(nullptr), left(nullptr), right(nullptr) {}

    /**
     * Constructeur par initialisation (1)
     * @param value la valeur du noeud
     */
    Node(T value) : value(value), parent(nullptr), left(nullptr), right(nullptr) {}

    /**
     * Constructeur par initialisation (2)
     * @param value la valeur du noeud
     * @param parent le noeud père
     */
    Node(T value, Node *parent) : value(value), parent(parent), left(nullptr), right(nullptr) {}

    /**
     * Constructeur par initialisation (3)
     * @param value la valeur du noeud
     * @param parent le noeud père
     * @param left le noeud fils gauche
     * @param right le noeud fils droit
     */
    Node(T value, Node *parent, Node *left, Node *right) : value(value), parent(parent), left(left), right(right) {}


    /**
     * Constructeur par copie
     * @param node le noeud à copier
    */
    explicit Node(const Node* node) : value(node->value), parent(node->parent), right(new Node(node->value, this)), left(new Node(node->value, this)) {}

    /**
     * Déconstruteur
     */
    ~Node() {
        if(left != nullptr) {
            left ->~Node<T>();
            delete left;
        }
        if(right != nullptr) {
            right ->~Node<T>();
            delete right;
        }
    }

    /**
     * Insertion d'un noeud
     * @param value la valeur du noeud à insérer
     */
    void insert(const T& value) {
        if (value < this->value && this->left != nullptr)
            this->left->insert(value);
        else if (value < this->value && this->left == nullptr)
            this->left = new Node<T>(value);
        else if (value > this->value && this->right != nullptr)
            this->right->insert(value);
        else if (value > this->value && this->right == nullptr)
            this->right = new Node<T>(value);
    }

    /**
     * Fonction statique permettant de remonter au noeud précédent celui passé en paramètre
     */
    static Node* goNextUpNode(Node* &current) {
        Node* last = current;
        current = current->parent;
        return last;
    }

    /**
    * Fonction statique permettant de descendre au noeud suivant gauche de celui passé en paramètre
    */
    static Node* goNextLeftNode(Node* &current) {
        Node* last = current;
        current = current->left;
        return last;
    }

    /**
     * Fonction statique permettant de descendre au noeud suivant droit de celui passé en paramètre
     */
    static Node* goNextRightNode(Node* &current) {
        Node* last = current;
        current = current->right;
        return last;
    }

    /*
     * Fonction statique permettant de savoir si un node existe après celui courant(current)
     */
    static bool hasNext(Node<T>* &current, Node<T>* &last) {
        bool res = false;
        //Si current est null on ne fait rien et return false
        if (current == nullptr) {
            return res;
        }
        //Vient du Haut
        if (last == current->parent) {
            if (current->left == nullptr) {
                res = true;
                if (current->right == nullptr) {
                    //Si rien à droite on remonte
                    last = goNextUpNode(current);
                } else {
                    //Sinon on descend
                    last = goNextRightNode(current);
                }
            } else {
                last = goNextLeftNode(current);
            }
            //Vient de Gauche
        } else if (last == current->left) {
            res = true;
            if (current->right == nullptr) {
                //Si rien à droite on remonte
                last = goNextUpNode(current);
            } else {
                //Sinon on descend
                last = goNextRightNode(current);
            }
            //Vient de Droite
        } else if (last == current->right) {
            //On remonte
            last = goNextUpNode(current);
        } else {
            throw;
        }
        return res;
    }



    /**
     * Fonction permettant de récupérer la référence de la valeur du noeud
     * @return T& la valeur
     */
     T& getValue() {
        return value;
    }

    /**
     * Fonction permettant de modifier de la valeur du noeud
     * @param value la nouvelle valeur
     */
     void setValue(T value) {
        this->value = value;
    }

    /**
     * Fonction permettant de récupérer le noeud parent
     * @return Node
     */
     Node* getParent() {
        return parent;
    }

    /**
     * Fonction permettant de modifier noeud parent
     * @param parent le nouveau noeud parent
     */
     void setParent(Node *parent) {
        this->parent = parent;
    }

    /**
     * Fonction permettant de récupérer le fils gauche du noeud
     * @return Node
     */
     Node* getLeft() {
        return left;
    }

    /**
     * Fonction permettant de modifier le fils gauche du noeud
     * @param left le nouveau fils gauche
     */
     void setLeft(Node *left) {
        this->left = left;
    }

    /**
     * Fonction permettant de récupérer le fils droit du noeud
     * @return Node
     */
     Node* getRight() {
        return right;
    }

    /**
     * Fonction permettant de modifier le fils droit du noeud
     * @param right le nouveau fils droit
     */
     void setRight(Node *right) {
        this->right = right;
    }

};

#endif //PROJET_CPP_NODE_H
