

#ifndef TP_ARBRERN_H
#define TP_ARBRERN_H
#include "noeud.hpp"
#include "Noeud.cpp"

class ArbreRN {
    Struct Arbre {
            Noeud *noeuds
            int *prec;
            int hauteurN;
            int hauteur;
            int i=0;
    }

    Arbre(Noeud *n,int couleur){
        *prec= null;
        *racine=NoeudArbre[i];
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
        }else if(A.noeuds->fils_gauche()== null && A.noeuds->fils_droit()== nullptr ||A.noeuds->fils_droit()== null && A.noeuds->fils_gauche()== nullptr){
            return false;
        }else if(A.noeuds->estRouge(A.noeuds)==false){
            hauteur++;
            if(A.noeuds->fils_droit()!= nullptr || A.noeuds->fils_gauche()=!null){
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


};


#endif //TP_ARBRERN_H
