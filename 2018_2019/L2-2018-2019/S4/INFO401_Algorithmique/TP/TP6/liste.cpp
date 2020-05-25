//
// Created by Nurglitsh on 11/03/2019.
//
#include <stdio.h>
using namespace std;
#include "liste.h"
int main(){
    liste *l=new liste();
    liste *l1= new liste();
    l1->AjouterFinListe(10);
    l->AfficherListe();
    l->AjouterFinListe(5);
    l->AfficherListe();
    FusionListe(*l1);
    cout<<l->tete->val;
}