//
// Created by Nurglitsh on 11/03/2019.
//
#include <iostream>
using namespace std;
#ifndef TP6_LISTE_H
#define TP6_LISTE_H

class Cellule{
public:
    int val;
    Cellule *suiv;

    Cellule(){
        val=0;
        suiv= nullptr;
    }
    Cellule(int valeur,Cellule* suivant){
        val=valeur;
        suiv=suivant;
    }
};


class liste {
public:
    liste *l=(liste*)malloc(sizeof(liste));
    Cellule *tete;
    Cellule *queue;

    liste(){
        tete= nullptr;
        queue= nullptr;
    }

    void AfficherListe(){
        cout<<"test";
        if (l->tete== nullptr){
            cout<<"liste vide";
        }
        while(tete->suiv!= nullptr){
            cout<<"kek"<<tete->val;
            tete->suiv;
        }

    }
    void AjouterFinListe(int n){
        Cellule *c=new Cellule();
        c->val=n;
        c->suiv=queue;
        queue=c;
    }
    void FusionListe(liste *l2){
        liste *l3=new liste();
        while(this->tete&&l2->tete!= nullptr){
            if(this->tete->val<l2->tete->val){
                l3->AjouterFinListe(this->tete->val);
                this->tete=this->tete->suiv;
            }else{
                l3->AjouterFinListe(l2->tete->val);
                l2->tete =l2->tete->suiv;
            }

        }
        if(l2->tete== nullptr){
                l3->AjouterFinListe(this->tete->val);
                this->tete=this->tete->suiv;
        }
        else{
            l3->AjouterFinListe(l2->tete->val);
            l2->tete =l2->tete->suiv;
        }

    }
};


#endif //TP6_LISTE_H
