#include <iostream>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <cstdio>

// using namespace std;
#define log(...) printf(__VA_ARGS__)

// Q1
class A {
protected:
    int ac, *ad = nullptr;
public:
    // Q5
    A(int x, int y) : ac(x), ad( new int(y) ) { log("Ax"); }
    A() : ac{}, ad( new int{} ) { log("Ad"); }
    ~A() { delete ad; log("~A"); }
    // Q6
    A(const A& x) : ac(x.ac), ad( new int(*x.ad) ) { log("Acc"); }
    A(A &&x) : ac(x.ac), ad(x.ad) { x.ad = nullptr; log("Acd"); }
    // Q7
    A& operator=(const A &x) {
        if (this != &x) {
            ac = x.ac;
            delete ad;
            ad = new int(*x.ad);
        }
        log("A=c");
        return *this;
    }
    A& operator=(A &&x) {
        ac = x.ac; // copie de la valeur
        // std::swap(ac,x.ac); // préférable car échange les champs => cohérence de l'objet temporaire après swap
        std::swap(ad,x.ad); // ad libéré lors de la destruction du temporaire
        log("A=d");
        return *this;
    }
};

// Q2: la seule chose qui eut être déplacé est la propriété d'un pointeur
// pointant sur une zone de mémoire externe (le plus souvent privée) à la classe.
// Une valeur dans la mémoire peut seulement être copiée d'un endroit à un
// autre.

// Q3: un champ déplaçable est un champ issu d'une classe dont au moins une partie
// des champs peut être déplacé (par transfert de propriété). A priori, toute classe
// qui contient un pointeur (directement ou indirectement) devrait être déplaçable.
// Inversement, une classe qui ne contient aucun pointeur (directement ou indirectement)
// n'est pas déplaçable.

// Q8: les champs auraient tous été copiés en utilisant le constructeur/l'assignation
// par copie champs à champs.


//
class B : public A {
protected:
    int bc, *bd = nullptr;
public:
    // Q9
    B(int x, int y, const A& z) :
        A(z),  bc(x), bd( new int(y) ) { log("Bxc"); }
    B(int x, int y, A&& z) :
        A(std::move(z)),  bc(x), bd( new int(y) ) { log("Bxd"); }
    B(int x) : B(x,x,A(x,x)) { log("Bu"); }
    B() : A(), bc{}, bd( new int{} ) { log("Bd"); }
    ~B() { delete bd; log("~B"); }
    // Q10
    B(const B &b) : A(b), bc(b.bc), bd( new int(*b.bd) ) { log("Bcc"); }
    B(B &&b) : A(std::move(b)), bc(b.bc), bd( b.bd ) {
        b.bd = nullptr;
        log("Bcd");
    }
    // Q11
    B& operator=(const B &b) {
        if (this != &b) {
            A::operator=(b); // copie de la partie A de l'objet
            bc = b.bc;
            delete bd;
            bd = new int(*b.bd);
        }
        log("B=c");
        return *this;
    }
    B& operator=(B &&b) {
        A::operator=(std::move(b)); // déplacement partie A de l'objet
        bc = b.bc; // copie valeur
        // std::swap(bc,b.bc); // préférable car échange les champs => cohérence de l'objet temporaire après swap
        std::swap(bd,b.bd); // bd libéré lors de la destruction du temporaire
        log("B=d");
        return *this;
    }
};


// version 1, avec initialisation par défaut
class C {
protected:
    size_t  size;
    B       *array = nullptr;
public:
    // Q12
    C() : size(0), array(nullptr) { log("Cd"); }
    C(size_t n) :
            size(n),
            array( new B[n] ) {
        log("Cn");
    }
    // Q13
    C(const std::initializer_list<B> &list) :
            size( list.size() ),
            array( new B[size] ) {  // Tous les B initialisés par défaut!
        size_t i=0;
        for(const B &x : list) array[i++] = x;
        log("Cic");
    }
    ~C() {
        delete [] array;
        log("~C");
    }
    // Q14
    C(const C& c) :
            size(c.size),
            array( new B[size] ) { // Tous les B initialisés par défaut!
        for(size_t i=0;i<size;++i) array[i] = c.array[i];
        log("Ccc");
    }
    C(C&& c) : size(c.size), array(c.array) {
        c.size=0;
        c.array=nullptr;
        log("Ccd");
    }
    // Q15
    friend void swap(C& c1, C& c2) {
        std::swap(c1.size,c2.size);
        std::swap(c1.array,c2.array);
    }
    C& operator=(const C &c) {
        if (this != &c) {
            C  tmp(c);
            swap(tmp,*this);
        }
        log("C=c");
        return *this;
    }
    C& operator=(C &&c) {
        swap(c,*this);
        log("C=d");
        return *this;
    }
};


// version 2: version optimisée de la classe C sans copie inutile.
class D {
protected:
    size_t  size;
    B       *array = nullptr;
public:
    // Q12
    D() : size(0), array(nullptr) { log("Dd"); }
    D(size_t n) :
        size(n),
        array( reinterpret_cast<B*>(::operator new(size * sizeof(B))) ) {
        for(size_t i=0;i<n;++i) new( array + i ) B();
        // car new B[n] ne doit pas être libéré avec ::operator delete
        log("Dn");
    }
    // Q13
    D(const std::initializer_list<B> &list) :
        size( list.size() ),
        array( reinterpret_cast<B*>(::operator new(size * sizeof(B)))  ) {
        size_t i=0;
        for(const B &x : list) {
            new( array + i ) B(x);
            ++i;
        }
        log("Dic");
    }
    ~D() {
        // delete [] array;
        for(size_t i=0; i<size; ++i) array[i].~B();
        ::operator delete( array );
        log("~D");
    }
    // Q14
    D(const D& c) :
        size(c.size),
        array( reinterpret_cast<B*>(::operator new(size * sizeof(B))) ) {
        for(size_t i=0;i<size;++i)
            new( array + i ) B( c.array[i] );
        log("Ccc");
    }
    D(D&& c) : size(c.size), array(c.array) {
        c.size=0;
        c.array=nullptr;
        log("Dcd");
    }
    // Q15
    friend void swap(D& c1, D& c2) {
        std::swap(c1.size,c2.size);
        std::swap(c1.array,c2.array);
    }
    D& operator=(D c) { // idiome copy and swap
        swap(c,*this);
        log("D=c");
        return *this;
    }
};


A fun(int x) { return A(x,2*x); }

int main() {
    // Q4
    A a, a2(fun(4));
    a = fun(3);
    //
    B b;
    C c(5);
    C c2({ B(1), B(2), B(3) });
    c = std::move(c2);
    // c2 déplacé => contenu inconnu, possiblement incohérent, d'où l'intéret du swap
    D d(5), d3;
    D d2({ B(1), B(2), B(3) });
    d = std::move(d2);
    // d2 déplacé => contenu inconnu, possiblement incohérent, d'où l'intéret du swap
}
