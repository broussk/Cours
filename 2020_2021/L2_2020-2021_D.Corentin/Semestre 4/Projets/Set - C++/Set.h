#ifndef PROJET_CPP_SET_H
#define PROJET_CPP_SET_H
#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>
#include "Node.h"

template<class T,class Compare = std::less<T>> class Set {
private:

    Node<T> *root;

public:
    // ne pas toucher
    static T dummy;  // pour renvoyer une lvalue lorsque demandé

    // prototype
    Set() : root(nullptr) {};

//    explicit Set(const Compare& comp) {}; // pas de sens si Compare non template

//    template<class InputIt> Set(InputIt first, InputIt last, const Compare& comp = Compare()) {}; // pas de sens si Compare non template

    // Constructeur par copie
    Set(const Set& set) {
        if (set.root != nullptr) {
            this->root = new Node<T>(set.root);
        }
    }

    // Constructeur par déplacement
    Set(Set&& set) {
        if (set.root != nullptr) {
            this->root = new Node<T>(set.root);
            set.root = nullptr;
        }
    }

//    Set(std::initializer_list<T> init, const Compare& comp = Compare()) {}; // pas de sens si Compare non template

    // Destructeur
    ~Set() {
       if(root != nullptr) delete(root);
    }

    // Opérateur =
    Set& operator=(const Set& set) {
        if (this != &set) {
            delete root;
            root = new Node<T>(set.root);
        }
        return *this;
    }


    Set& operator=(Set&& set) {
        if (this != &set) std::swap(root, set.root);
        return *this;
    }


//    Set& operator=(std::initializer_list<T> ilist ) {
//        return *this;
//    }

    // Permet de savoir si le set est vide ou non
    bool empty() const {
        return root == nullptr;
    }

    // Permet de récupérer la taille du set courant
    size_t size() const {
        int nb = 0;
        // On vérifie que le set n'est pas vide pour éviter des erreurs et des opérations inutiles
        if(!empty()) {
            // On boucle sur tout le set grâce aux itérators
            for(auto it=begin(); it != end(); ++it) {
                nb++;
            }
        }
        return nb;
    }

    // Permet de récupérer le nombre de node du set courant qui ont leur valeur équivalente à celle passée en paramètres
    size_t count( const T& value ) const {
        int nb = 0;
        // On vérifie que le set contient la valeur au moins une fois pour éviter des opérations inutiles
        if (contains(value)) {
            // On boucle sur tout le set grâce aux itérators
            for(auto it=begin(); it != end(); ++it) {
                // On vérifie que la valeur de l'itérateur courant correspond
                if (*it == value) {
                    nb++;
                }
            }
        }
        return nb;
    }

    // Permet de savoir si la valeur passée en paramètres est présente dans le set courant
    bool contains( const T& value ) const {
        bool res = false;
        // On vérifie que le set n'est pas vide pour éviter des erreurs et des opérations inutiles
        if (!empty()) {
            // On boucle sur tout le set grâce aux itérators
            for(auto it=begin(); it != end(); ++it) {
                // On vérifie que la valeur de l'itérateur courant correspond
                if (*it == value) {
                    res = true;
                    break;
                }
            }
        }
        return res;
    }

    // Permet de vider un set de tout contenu
    void clear() {
        // On vérifie que le set n'est pas vide pour éviter des erreurs
        if (!empty()) {
            // On boucle sur tout le set grâce aux itérators
            for(auto it=begin(); it != end(); ++it) {
                delete(it);
            }
        }
    }

    void swap(Set& set) {
        std::swap(root, set.root);
    }



    //Opérateur ==
    friend bool operator==(const Set& lhs, const Set& rhs) {
        return (lhs.size() == rhs.size());
    }

    //'!=' c'est l'inverse de '=='
    friend bool operator!=(const Set& lhs, const Set& rhs) {
        return !(operator==(lhs, rhs));
    }

    //'<' c'est l'inverse de '>='
    friend bool operator< (const Set& lhs, const Set& rhs) {
        return !(operator>=(lhs, rhs));
    }

    //'>' c'est l'inverse de '<='
    friend bool operator> (const Set& lhs, const Set& rhs) {
        return !(operator<=(lhs, rhs));
    }

    //'<=" c'est soit '==' OU '<'
    friend bool operator<=(const Set& lhs, const Set& rhs) {
        return (operator==(lhs, rhs)) || (operator<(lhs, rhs));
    }

    //'>=' c'est soit '==' OU '>'
    friend bool operator>=(const Set& lhs, const Set& rhs ) {
        return (operator==(lhs, rhs)) || (operator>(lhs, rhs));
    }


    // Itérateur classique
    class iterator {
    private:
        Node<T>* current;
        Node<T>* last;
    public:
        //Constructeur par défaut
        explicit iterator() : current(nullptr), last(nullptr) {}

        //Constructeur par initialisation
        iterator(Node<T>* current, Node<T>* last) : current(current), last(last) {};

        //Constructeur par copie
        iterator(const iterator& it) : current(it.current), last(it.last) {}

        // Operators
        iterator& operator++() {
            if (current != nullptr) {
                if(Node<T>::hasNext(current, last)) {
                }
            }
            return *this;
        }

        iterator operator++(int) {
            iterator clone(*this);
            if (current != nullptr) {
                ++this;
            }
            return clone;
        }

        bool operator==(iterator it) const {
            return (this->current == it.current && this->last == it.last);
        }

        bool operator!=(iterator it) const {
            return !(operator==(it));
        }

        T& operator*() const {
            // Renvoi la valeur du dernier itérateur
            return last->getValue();
        }

        //// birectionnel
        iterator& operator--() {
            if (current != nullptr) {
                Node<T>::goNextUpNode(current);
            }
            return *this;
        }

        Node<T> getCurrent() {
            return current;
        }

        Node<T> getLast() {
            return last;
        }
    };

    iterator begin() { return ++iterator(root, nullptr); }
    iterator end() { return iterator(nullptr, root); }

    // iterateur constant
    class const_iterator {
    private:
        Node<T>* current;
        Node<T>* last;

    public:
        // Constructeur par défaut
        explicit const_iterator() : current(nullptr), last(nullptr) {}

        // Constructeur par initialisation
        const_iterator(Node<T>* current, Node<T>* last) : current(current), last(last) {};

        // Constructeurs par copie
        const_iterator(const const_iterator& it) : current(it.current), last(it.last) {}
        const_iterator(const iterator& it) : current(it.getCurrent()), last(it.getLast()) {}

        const_iterator& operator++() {
            if (current != nullptr) {
                if(Node<T>::hasNext(current, last)) {
                }
            }
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator clone(*this);
            if (current != nullptr) {
            }
            return clone;
        }

        bool operator==(const_iterator it) const {
            return (this->current == it.current && this->last == it.last);
        }

        bool operator!=(const_iterator it) const {
            return !(operator==(it));
        }

        const T& operator*() const {
            return last->getValue();
        }

        //// birectionnel
        const_iterator& operator--() {
            if (current != nullptr) {
                Node<T>::goNextUpNode(current);
            }
            return *this;
        }

        const_iterator operator--(int) const {
            const_iterator clone(this);
            if (current != nullptr) {
                Node<T>::goNextUpNode(current);
            }
            return clone;
        }
    };

    const_iterator cbegin() { return ++const_iterator(root, nullptr); }

    const_iterator cend() { return const_iterator(nullptr, root); }

    const_iterator begin() const { return ++const_iterator(root, nullptr); }

    const_iterator end() const { return const_iterator(nullptr, root); }


    // méthodes avec itérateur
    std::pair<iterator,bool> insert( const T& value ) {
        if (root == nullptr) {
            root = new Node<T>(value);
        } else {
            root->insert(value);
        }
        return std::make_pair(iterator(),false);
    }


//    std::pair<iterator,bool> insert(T&& value ) { return std::make_pair(iterator(), false); }
//    template< class InputIt > void insert( InputIt first, InputIt last ) {}
//    void insert( std::initializer_list<T> ilist ) {}
//
//    template< class... Args > std::pair<iterator,bool> emplace( Args&&... args ) { return std::make_pair(iterator(),false); }
//
//    iterator erase( const_iterator pos ) { return iterator(); }
//    void erase( const_iterator first, const_iterator last ) {}
//    size_t erase( const T& value ) { return 0; }

    iterator find( const T& value ) {
        iterator res;
        for(auto it=begin(); it != end(); ++it) {
            if (*it == value) {
                res = iterator(it);
            }
        }
        return res;
    }

//    std::pair<iterator,iterator> equal_range( const T& value ) const { return std::make_pair(iterator(), iterator()); }
//    iterator lower_bound( const T& value ) const  { return iterator(); }
//    iterator upper_bound( const T& value ) const  { return iterator(); }


};

//template< class Key, class Compare> void swap(Set<Key,Compare>& lhs, Set<Key,Compare>& rhs ) {};

// afin de pouvoir renvoyer une référence vers un entier dans le code à remplacer
//template <class Key,class Compare> Key Set<Key,Compare>::dummy;
#endif //PROJET_CPP_SET_H
