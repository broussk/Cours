//
// Created by Nurglitsh on 22/05/2019.
//

#ifndef TP_ARBREHUF_H
#define TP_ARBREHUF_H
#include "noeud.hpp"
#include "Noeud.cpp"

struct ArbreHuf {
    {
        short branche0;
        short branche1;
    };


    struct arbre_data
    {
        unsigned long frequence;
        short index_suivant;
    };


    struct dictionnaire
    {
        unsigned char taille;
        char code[CODE_MAX_LEN];
    };


};


#endif //TP_ARBREHUF_H
