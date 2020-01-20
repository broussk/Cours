#include <cstdlib>
#include <iostream>

using namespace std;

#include "stdlib.h"
#include "Arbre.h"
int main() {
    Arbre A = new Arbre();
    int x, i;
    if ((i != 1)) {
        cout << "Appuyer sur une touche si Vous voulez créer un arbre / -1 pour quitter" << endl;
        cin >> x;

        cout << "veuillez entrez la couleur de la racine" <<endl ;
        cout << "Rouge=1 /Noir =0" << endl;
        cin >> x;
        if (x == 1 || x == 0) {
            if (x == 1) {
                Noeud N = new Noeud(i, 1);
                A.noeuds = N;
            } else {
                Noeud N = new Noeud(i, 0);
                A.noeuds = N;
            }
        } else {
            break;
        }

    }
    do {
        cout << "Appuyer sur une touche si vous voulez continuer / -1 pour quitter" << endl;
        cin >> x;
        cout << "pour fg 0 / pour fd 1" << endl;
        cin >> x;
        if (x == 0) {
            cout << "veuillez entrez la couleur du noeud" << endl;
            cout << "Rouge=1 /Noir =0" << endl;
            cin >> x;
            if (x == 1 || x == 0) {
                if (x == 1) {
                    Noeud N = new Noeud(i, 1);
                    A.noeuds->fils_gauche() = N;
                } else {
                    Noeud N = new Noeud(i, 0);
                    A.noeuds->fils_gauche() = N;

                }
            }

            }else{
                cout << "veuillez entrez la couleur du noeud" << endl;
                cout << "Rouge=1 /Noir =0" << endl;
                cin >> x;
                if (x == 1 || x == 0) {
                    if (x == 1) {
                        Noeud N = new Noeud(i, 1);
                        A.noeuds->fils_droit() = N;
                    } else {
                        Noeud N = new Noeud(i, 0);
                        A.noeuds->fils_droit() = N;

                    }
                }

            }

    }while(x==false);
}
