#include <cstdlib>
#include <iostream>

using namespace std;

#include "stdlib.h"
#include "arbre.h"
#include <time.h>

#define MAX 10
#define TAILLE_MAX 50
/*
				##########################################
				##										##
				##    Arbres binaires de recherche		##
				##										##
				##########################################


	Auteur: Laderivier 

	Date: 27/12/06 12:01

*/

void sleep( float sec)
{
	clock_t start, end;
	start = end = clock();
	if( start != -1 )
		while( (end-start)/(float)CLOCKS_PER_SEC < sec )
			end = clock();
}

int main()
{
	cout<<endl<<endl;
	cout<<" Arbre binaire de recherche : "<<endl;
	cout<<" ----------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t created by : laderivier"<<endl;
	cout<<endl<<endl<<endl;
    Arbre a = Arbre();
    int i, x;
    srand( time(NULL) );
    for(i=0; i<TAILLE_MAX; i++){
        x = rand()% MAX;
        a.insertion( x );
    }
    
    cout<<endl<<endl;
    cout<<" a = "<<a<<endl;
    cout<<endl;
    cout<<" racine : "<<a.etiquette()<<endl;
    cout<<" hauteur : "<<a.hauteur()<<endl;
    cout<<" cardinal: "<<a.cardinal()<<endl;
	cout<<endl;
    a.affiche_arbre();
  
    Noeud *pere;
    do{
        cout<<endl;
		cout<<" quel element voulez vous supprimer ? ('-1' pour quitter) :";
		cin>>x;
        cout<<endl<<endl;
        if( x != -1) {
			pere = a.recherche_pere(x);
			cout << " pere      :  " << pere->etiquette() << endl;
			cout << " pere->fg  :  " << pere->etiquette_fg() << endl;
			cout << " pere->fd  :  " << pere->etiquette_fd() << endl;
			cout << endl;
			cout << "\tsupprime(" << x << ") : ";
			a.supprime(x);
			cout << endl << endl;
			cout << " a = " << a << endl;
			cout << endl << endl;
			cout << " racine : " << a.etiquette() << endl;
			cout << " hauteur : " << a.hauteur() << endl;
			cout << " cardinal: " << a.cardinal() << endl;
			cout << endl;
			a.affiche_arbre();
		}
	}
    while( x != -1 ); 

    cout<<endl<<endl;
    a.videArbre();
    cout<<" a = "<<a<<endl;
    cout<<endl<<endl;

//    sleep( 1. );	// petite pause avt de quitter :p 
    return EXIT_SUCCESS;
}
