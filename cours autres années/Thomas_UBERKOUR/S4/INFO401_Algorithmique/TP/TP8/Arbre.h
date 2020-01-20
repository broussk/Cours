//
// Created by Nurglitsh on 25/03/2019.
//
#include "noeud.hpp"
#include <iostream>
#include <ostream>
#ifndef S4_ARBRE_H
#define S4_ARBRE_H


class Arbre {
private:
    Noeud *racine;
    int *prec;
    int hauteurN;
    int hauteur;
    int i=0;
public:
    Arbre(int n ,int couleur){
        *racine=new Noeud(n,couleur);
        hauteurN=0;
        hauteur=0;
        i++;
    }
    void RotationD(Arbre A){
        Noeud *temp;
        temp=A.noeuds->fils_gauche();
        A.noeuds->fils_gauche()=A.noeuds->fils_droit();
        A.noeuds->fils_droit()=temp->fils_gauche();
        temp->fils_gauche()=A.noeuds;
    }
    void RotationG(Arbre A){
        Noeud *temp;
        temp=A.noeuds->fils_droit();
        A.noeuds->fils_droit()=A.noeuds->fils_gauche();
        A.noeuds->fils_gauche()=temp->fils_droit();
        temp->fils_droit()=A.noeuds;
    }



    bool Reconnaissance(Arbre A){
        hauteurN=1;
        if (estRouge(A.noeuds)){
            if(estRouge(A.noeuds->fils_droit())||estRouge(A.noeuds->fils_gauche())){
                return false;
            }
        }else if(A.noeuds->fils_gauche()== nullptr && A.noeuds->fils_droit()== nullptr ||A.noeuds->fils_droit()== nullptr && A.noeuds->fils_gauche()== nullptr){
            return false;
        }else if(A.noeuds->estRouge(A.noeuds)==false){
            hauteur++;
            if(A.noeuds->fils_droit()!= nullptr || A.noeuds->fils_gauche()=!nullptr){
                if(hauteurN==-1){
                    hauteurN=hauteur;
                    return true;
                }
            }
        }
        if(hauteurN!=hauteur){
            return false;
        }
        Reconnaissance(A.noeuds->fils_gauche());
        Reconnaissance(A.noeuds->fils_droit());
    }
};


#endif //S4_ARBRE_H
