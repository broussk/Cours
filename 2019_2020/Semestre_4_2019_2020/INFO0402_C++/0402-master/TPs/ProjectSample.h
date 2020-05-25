#pragma once
#include <stack>
#include <string>
#include <iostream>

// arbre binaire non équilibré
template <typename T> class BasicSet {
private:
    // structure interne
    struct Node {
        Node    *left, *right;
        T       value;
        Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
        /// teste si le noeud courant est une feuille
        bool isLeaf() { return (left == nullptr) && (right == nullptr); }
        /// insertion (à gauche si plus petit, à droite si plus grand); sans équilibrage
        void Insert(const T& v) {
            Node *tmp = this;
            while (1) {
                if (v < tmp->value) {
                    if (tmp->left == nullptr) { tmp->left = new Node(v); break; }
                    else tmp = tmp->left;
                }
                else if (v > tmp->value) {
                    if (tmp->right == nullptr) { tmp->right = new Node(v); break; }
                    else tmp = tmp->right;
                }
                else break; // déjà présent
            }
        }
        /// dump brut de l'arbre avec décalage pour visualisation de sa structure
        void dump(size_t depth=0) {
            const int tab = 3;
            std::cout << std::string(depth*tab,' ') << value << "\n"; //  << value << "\n";
            if (isLeaf()) return;
            ++depth;
            if (left != nullptr) left->dump(depth);
            else std::cout << std::string(depth*tab,' ') << "(null)\n";
            if (right != nullptr) right->dump(depth);
            else std::cout << std::string(depth*tab,' ') << "(null)\n";
        }
        /// affichage récursif standard de l'arbre
        void view() {
            if (left != nullptr) left->view();
            std::cout << value << " ";
            if (right != nullptr) right->view();
        }
    };
    /// pointeur vers la structure interne
    Node *root;
public:
    /// classe publique iterator
    class iterator {
    private:
        std::stack<Node*>   stack;  /// pile pour stockage de la position courante dans l'arbre
        /// inutile s'il y a un pointeur vers le parent
    public:
        /// constructeurs
        iterator() : stack() {}
        iterator(const iterator &s) : stack(s.stack) {}
        /// itération vers l'élément suivant
        iterator& operator++() {
            Node *cur = stack.top();
            // si on peut aller à droite, on y va et complètement à gauche
            if (cur->right != nullptr) {
                cur = cur->right;
                stack.push(cur);
                while (cur->left != nullptr) {
                    cur = cur->left;
                    stack.push(cur);
                }
                return *this;
            }
            // sinon, on remonte jusqu'à ce que l'on vienne de la gauche
            while (true) {
                stack.pop();
                if (stack.empty()) return *this;
                Node *up = stack.top();
                if (up->left == cur) return *this;
                cur = up;
            }
        }
        /// déréférencement
        const T& operator*() const { return stack.top()->value; }
        T& operator*() { return stack.top()->value; }
        /// comparaison de deux itérateurs = comparaison des piles
        friend bool operator!=(const iterator &it1, const iterator &it2) { return it1.stack != it2.stack; }
        friend class BasicSet;
    };
    /// itérateur vers le premier élément de l'arbre
    iterator begin() {
        iterator   it;
        if (root == nullptr) return it;
        Node *cur = root;
        it.stack.push(cur);
        while (cur->left != nullptr) {
            cur = cur->left;
            it.stack.push(cur);
        }
        return it;
    }
    /// itérateur vers le dernier élément (parcours fini = pile vide)
    iterator end() { return iterator(); }

    /// construction par défaut
    BasicSet() : root(nullptr) {};

    /// insertion d'un élément dans l'arbre
    void Insert(int v) {
        if (root == nullptr) root = new Node(v);
        else root->Insert(v);
    }

    /// pour la démo: remplissage automatique avec des valeurs aléatoires
    void RandomFill(const size_t n, const size_t vmax=1000) {
        srand(time(nullptr) );
        for (size_t i=0; i<n; ++i) Insert( rand()%vmax );
    }
    /// affichage des valeurs de l'arbre
    inline void view() { if (root!=nullptr) root->view(); std::cout << std::endl; }
    /// dump de la structure de l'arbre
    inline void dump() { if (root!=nullptr) root->dump(0); }
};
