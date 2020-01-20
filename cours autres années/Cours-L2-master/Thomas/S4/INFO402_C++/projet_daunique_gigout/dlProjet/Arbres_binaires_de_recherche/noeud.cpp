#include <iostream>
using namespace std;

//#include "stdio.h"

#include "noeud.h"

// ###########################################################################
// ###########################################################################

//                          I) Constructeurs :

// ###########################################################################
// ###########################################################################


Noeud::Noeud()
{
    v = -1;
    fg = VIDE;
    fd = VIDE;
}

Noeud::Noeud(int nb)
{
    v = nb;
    fg = VIDE;
    fd = VIDE;
}

// ###########################################################################
// ###########################################################################

//                          II) Destructeur :

// ###########################################################################
// ###########################################################################

Noeud *Noeud::videSousArbre()
{
    if( this != VIDE){
        Noeud *tmp = this;
        if(fg != VIDE) fg->videSousArbre();
        if(fd != VIDE) fd->videSousArbre();
        delete this;
    }
    return VIDE;
}

// ###########################################################################
// ###########################################################################

//                          III) tests :

// ###########################################################################
// ###########################################################################

bool Noeud::noeud_vide()
{
    // NB : 'this' pointeur sur le Noeud m�me
    if( this == VIDE ) return true;
    else return false;
}

bool Noeud::est_fils(Noeud *pere)
{
    if( pere->fd != this && pere->fg != this)
        return false;
    else
        return true;
}

bool Noeud::est_pere(Noeud *fils)
{
    if( fd != fils && fg != fils)
        return false;
    else
        return true;
}

bool Noeud::appartient(int nb)
{
    if( etiquette() == nb)
        return true;
    else
        if( !fg->noeud_vide() )
            return (false || fg->appartient(nb));
        else
            if( !fd->noeud_vide() )
                return ( false || fd->appartient(nb));
            else    // fg et fd == VIDE
                return false;
}

// ###########################################################################
// ###########################################################################

//                  IV )  informations sur le sous-arbre :

// ###########################################################################
// ###########################################################################

int Noeud::etiquette()
{
    // le test est une 's�curit�' pour �viter la lecture d'un noeud vide ...
    if( noeud_vide() ){
        cerr<<endl<<"n.etiquette(): noeud 'vide'"<<endl;
        return -1;
    }
    else
        return v;
}

int Noeud::etiquette_fg()
{
    if( noeud_vide() ){
        cerr<<endl<<"n.etiquette_fg(): noeud vide"<<endl;
        return -1;
    }
    else{
        // s�curit� pour �viter la lecture d'un noeud vide ...
        if( fg->noeud_vide() ){
            cerr<<endl<<"n.etiquette_fg(): pas de fils gauche"<<endl;
            return -1;
        }
        else
        return ( fg->etiquette() );
    }
}

int Noeud::etiquette_fd()
{
    if( noeud_vide() ){
        cerr<<endl<<"n.etiquette_fd(): noeud vide"<<endl;
        return -1;
    }
    else{
        if( fd->noeud_vide() ){
            cerr<<endl<<" n.etiquette_fd(): pas de fils droit"<<endl;
            return -1;
        }
        else
            return ( fd->etiquette() );
    }
}

int Noeud::hauteur()
{
    if( fg->noeud_vide() &&  fd->noeud_vide() )
        return 1;
    else
        if( fg->noeud_vide() )
            return ( fd->hauteur() + 1 );
        else
            if( fd->noeud_vide() )
                return ( fg->hauteur() + 1 );
            else{                           // fg et fd != VIDE
                int hg = fg->hauteur();
                int hd = fd->hauteur();
                if( hg > hd )
                    return hg + 1;
                else
                    return hd + 1;
            }
}

int Noeud::cardinal()
{
	if( noeud_vide() )
		return 0;
	else
		return (1 + fg->cardinal() + fd->cardinal() );
}

int Noeud::max()
{
    if( fd->noeud_vide() )
        return v;
    else{
        Noeud *tmp = fd;
        while(tmp->fd != VIDE) tmp = tmp->fd;
        return tmp->v;
    }
}

int Noeud::min()
{
    if( fg->noeud_vide() )
        return v;
    else{
        Noeud *tmp = fg;
        while(tmp->fg != VIDE) tmp = tmp->fg;
        return tmp->v;
    }
}

// ###########################################################################
// ###########################################################################

//                  V ) Op�rations sur les sous-arbres :

// ###########################################################################
// ###########################################################################


Noeud *Noeud::fils_gauche()
{
    return fg;
}

Noeud *Noeud::fils_droit()
{
    return fd;
}

// sorry ... c'est un peu lourd :-/  :

int Noeud::etiquette(Noeud *pere, int nb)
{
    // Rq : on ne peut pas autoriser une modification quelconque
    // de l'arbre, il faut faire attention � ce que l'arbre restent
    // un arbre binaire de recherche.
    // ( Rappel : v == etiquette() )
    if( noeud_vide() )     // this != VIDE ...
        cerr<<endl<<"n.etiquette(): noeud 'vide'"<<endl;
    else
        if( pere->noeud_vide() )                // noeud == racine :
            if( fg->noeud_vide() )
                if( fd->noeud_vide() )
                        v = nb;
                else                            // fg == VIDE && fd != VIDE
                    if( nb < fd->min() )
                        v = nb;
                    else{
                            cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
                            cerr<<"non permise, fd->min() >= nb"<<endl;
                    }
            else                                // fg != VIDE
                if( fg->max() < nb )
                    if( fd->noeud_vide() )
                        v = nb;
                    else                        // fd != VIDE
                        if( nb < fd->min() )
                            v = nb;
                        else{
                            cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
                            cerr<<"non permise, fd->min() >= nb"<<endl;
                        }
                else{
                    cerr<<endl<<"n.etiquette("<<nb<<") :";
                    cerr<<" modification non permise, fg->max() >= nb"<<endl;
                }
        else    // pere non vide
            if( est_fils(pere) )
                if( pere->fg == this )
                    if( fg->max() < nb && nb < pere->etiquette() )
                        if( fd->noeud_vide() )
                            v = nb;
                        else                        // fd != VIDE
                            if( nb < fd->min())
                                v = nb;
                            else{
                                cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
                                cerr<<"non permise, fd->min() >= nb"<<endl;
                            }
                    else{
                        cerr<<endl<<"n.etiquette("<<nb<<") :";
                        cerr<<" modification non permise, fg->max() >= nb";
                        cerr<<" ou nb >= pere->etiquette() "<<endl;
                    }
                else
                    if( pere->fd == this )
                        if( fd->min() > nb && nb > pere->etiquette() )
                            if( fg->noeud_vide() )
                                v = nb;
                            else                        // fd != VIDE
                                if( nb > fg->max() )
                                    v = nb;
                                else{
                                    cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
                                    cerr<<"non permise, fg->max() <= nb"<<endl;
                                }
                        else{
                            cerr<<endl<<"n.etiquette("<<nb<<") :";
                            cerr<<" modification non permise, fg->max() >= nb";
                            cerr<<" ou nb >= pere->etiquette() "<<endl;
                        }

            else{
                cerr<<endl<<"n.etiquette("<<nb<<") :";
                cerr<<" modification non permise, pere->fils() != n"<<endl;
            }
    return v;
}

void Noeud::insertion(int nb)
{
    if( nb != etiquette() )
        if( nb < v )
            if( fg->noeud_vide() )
                fg = new Noeud(nb);
            else
                fg->insertion(nb);
        else
            if( fd->noeud_vide() )
                fd = new Noeud(nb);
            else
                fd->insertion(nb);
}

Noeud *Noeud::recherche(int nb)
{
    if( etiquette() == nb)
        return this;
    else
        if( !fg->noeud_vide() )
            return( fg->recherche(nb) );
        else
            if( !fd->noeud_vide() )
                return ( fd->recherche(nb) );
            else                // fg et fd == VIDE
                return VIDE;
}

Noeud *Noeud::recherche(int *t, int taille)
{
    Noeud *tmp = this;
    if( !noeud_vide() && taille <= hauteur() ){
        bool b = true;
        for(int i=0; i<taille && b; i++){
            if( t[i] == -1 )
                tmp = tmp->fg;
            else
                if( t[i] == 1 )
                    tmp = tmp->fd;
                else
                    b = false;
            if(tmp == VIDE)     // tmp est une feuille
                b = false;
        }
    }
    return tmp;
}


Noeud *Noeud::recherche_max()
{
    if( noeud_vide() )
        return VIDE;
    else
        if( fd->noeud_vide() )
            return this;
        else{
            Noeud *tmp = fd;
            while(tmp->fd != VIDE) tmp = tmp->fd;
            return tmp;
        }
}

Noeud *Noeud::recherche_pere(int nb)
{
    if(nb < v)
        if(fg != VIDE)
            if( fg->v == nb )
                return this;
            else
                return ( fg->recherche_pere(nb) );
        else
            return VIDE;
    else
        if( fd != VIDE)
            if(fd->v == nb )
                return this;
            else
                return ( fd->recherche_pere(nb) );
        else
            return VIDE;
}


void Noeud::supprime(int nb)
{
    // on sait que nb != v car cette situation est g�r� par le noeud pr�c�dent
    // qui pointe sur ce noeud. (et n'ayant pas le Noeud "p�re" qui pointe
    // sur le noeud m�me, on ne pourra pas modifi� son fils ...)

    // Rappel : noeud->etiquette() == noeud->v

    Noeud *tmp;
    Noeud *pere_tmp;

    if( nb < etiquette() )
        if( fg->noeud_vide() ){
            cerr<<endl<<"n.suppresssion: "<<nb;
            cerr<<" n'appartient pas a l'arbre"<<endl;
        }
        else{
            if( nb == fg->etiquette() )
                if( (fg->fg)->noeud_vide()&& (fg->fd)->noeud_vide() ){
                    delete fg;
                    fg = VIDE;
                }
                else    // fg a au moin un descendant :
                    if( (fg->fg)->noeud_vide() ){
                        tmp = fg;
                        fg = fg->fd;
                        delete tmp;
                    }
                    else    // fg->fg existe :
                        if( (fg->fd)->noeud_vide() ){
                            tmp = fg;
                            fg = fg->fd;
                            delete tmp;
                        }
                        else{ // fg a exactement 2 descendants :
                            tmp = fg->fg;
                            pere_tmp = fg;
                            // tmp == max dans fg->fg
                            while(tmp->fd != VIDE){
                                pere_tmp = tmp;
                                tmp = tmp->fd;
                            }
                            if( tmp == fg->fg){
                                fg->v  = (fg->fg)->v;
                                fg->fg = (fg->fg)->fg;
                                delete tmp;
                            }
                            else{
                                fg->v = tmp->v;
                                pere_tmp->fd = tmp->fg;
                                delete tmp;
                            }
                        }
            else
                fg->supprime(nb);
        }
    else  // nb > v  (�galit� impossible par hypoth�se)
        if( fd->noeud_vide() ){
            cerr<<endl<<"n.suppresssion: "<<nb;
            cerr<<" n'apprtient pas a l'arbre binaire"<<endl;
        }
        else{
			       if( nb == fd->etiquette() )
                if( (fd->fg)->noeud_vide() && (fd->fd)->noeud_vide() ){
                    delete fd;
                    fd = VIDE;
                }
                else            // fd a au moin un descendant :
                    if( (fd->fg)->noeud_vide() ){
                        tmp = fd;
                        fd = fd->fd;
                        delete tmp;
                    }
                    else        // fg->fg existe :
                        if( (fd->fd)->noeud_vide() ){
                            tmp = fd;
                            fd = fd->fg;
                            delete tmp;
                        }
                        else{   // fd a exactement 2 descendants :
                            tmp = fd->fg;
                            pere_tmp = fd;
                            // tmp == max dans fg->fg
                            while( tmp->fd != VIDE ){
                                pere_tmp = tmp;
                                tmp = tmp->fd;
                            }
                            if( tmp == fd->fg){
                                fd->v  = (fd->fg)->v;
                                fd->fg = (fd->fg)->fg;
                                delete tmp;
                            }
                            else{
                                fd->v = tmp->v;
                                pere_tmp->fd = tmp->fg;
                                delete tmp;
                            }
                        }
            else
                fd->supprime(nb);
        }
}

void Noeud::supprime_racine()
{
    int m = -1;
    Noeud *tmp;
    if( !fg->noeud_vide() ){
        m = fg->max();
        if( m == fg->v){
            tmp = fg->fg;
            supprime(m);
            fg = tmp;
        }
        else
            supprime(m);
        etiquette(VIDE, m);
    }
    else{
        if( !fd->noeud_vide() ){
            m = fd->min();
            if( m == fd->v){
                tmp = fd->fd;
                supprime(m);
                fd = tmp;
            }
            else
                supprime(m);
            etiquette(VIDE, m);
        }
    }
}

// ###########################################################################
// ###########################################################################

//                          VI) Affichage :

// ###########################################################################
// ###########################################################################

void Noeud::affiche_sous_arbre_1()
{
    int h = hauteur()-1, i, j;
    int *t = new int[h]; for(i=0; i<h; i++) t[i] = 1;
    Noeud *tmp;
    i = h-1;
    bool test = true;
    while( i >= 0 ){
        tmp = recherche(t, h);

        // affichage du noeud :
        if( test && !tmp->noeud_vide() ){
            for(j=0; t[j] == -1 || t[j] == 1; j++) cout<<"\t";
            if( tmp->fg == VIDE ) cout<<"|";
            cout<<tmp->etiquette();
            if( tmp->fd == VIDE ) cout<<"|";
            cout<<endl;
        }

        // noeud suivant :
        switch(t[i]){
            case 1:
                t[i] = 0;
                test = true;
                break;
            case 0:
                t[i] = -1;
                for(j=i+1; j<h; j++) t[j] = 1;
                i = h-1;
                test = true;
                break;
            case -1:
                i--;
                test = false;
                break;
            default:
                cerr<<" ? "<<endl;
        }
    }

}

void Noeud::affiche_sous_arbre()
{
    int h = hauteur()-1, i, j;
    int *t = new int[h+1]; for(i=0; i<h; i++) t[i] = 1;
    t[h] = 0;   // s�curit� pour �viter de sortir du tableau.
    Noeud *tmp;
    i = h-1;
    bool test = true;
    while( i >= 0 ){
        tmp = recherche(t, h);

        // affichage du noeud :
        if( test && !tmp->noeud_vide() ){
            for(j=0; t[j] == -1 || t[j] == 1; j++){
                if( t[j+1] == 0 || j == h-1)
                    if( t[j] == -1 )
                        printf("        %c", 192);
                    else
                         printf("        %c", 218);
                else
                    if( t[j]*t[j+1] == -1)
                        printf("        %c", 179);
                    else
                        printf("         ");
            }
            printf("%6d", tmp->etiquette());
            if( tmp->fg != VIDE && tmp->fd != VIDE)
                printf(" %c%c", 196, 180);
            else
                if( tmp->fg != VIDE )
                    printf(" %c%c", 196, 191);
                else
                    if( tmp->fd != VIDE )
                        printf(" %c%c", 196, 217);
            cout<<endl;
        }

        // noeud suivant :
        switch(t[i]){
            case 1:
                t[i] = 0;
                test = true;
                break;
            case 0:
                t[i] = -1;
                for(j=i+1; j<h; j++) t[j] = 1;
                i = h-1;
                test = true;
                break;
            case -1:
                i--;
                test = false;
                break;
            default:
                cerr<<" ? "<<endl;
        }
    }

}

ostream& operator<<(ostream& o, Noeud n)
{
    if( !n.fg->noeud_vide() )   o<<*(n.fg); // else o<<".";
    if( !n.noeud_vide()     )   o<<" "<<n.etiquette();
    if( !n.fd->noeud_vide() )   o<<*(n.fd); // else o<<" .";
    return o;
}
