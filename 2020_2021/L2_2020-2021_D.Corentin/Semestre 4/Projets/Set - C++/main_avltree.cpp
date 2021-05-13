#include "Node.h"
#include "AVLTree.h"

using namespace std;


int main(){

    AVLTree<int> *root = new AVLTree<int>();

    root->insert(5);
    root->insert(9);
    root->insert(2);
    root->insert(3);
    root->insert(4);
    root->insert(9);
    root->insert(6);
    root->insert(54);
    root->insert(6);


    cout << "-------------Arbre---------------" << endl;
    root->print();


    cout << "Parcours inorder" << endl;
    root->inorder();
    cout << "\n";

    if(root->isBalanced()){
        cout << "=> Je suis en equilibre" << endl;
    } else {
        cout << "=> Je ne suis pas en equilibre" << endl;
    }








}