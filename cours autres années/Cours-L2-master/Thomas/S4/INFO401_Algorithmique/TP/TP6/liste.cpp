//
// Created by Nurglitsh on 11/03/2019.
//
#include <stdio.h>
using namespace std;
#include "liste.h"
int main(){
    liste *l=new liste();
    l->AfficherListe();
    l->AjouterFinListe(5);
    l->AfficherListe();
    cout<<l->tete->val;
}