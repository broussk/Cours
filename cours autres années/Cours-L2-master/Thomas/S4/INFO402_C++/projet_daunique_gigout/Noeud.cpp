#include <iostream>
#include <ostream>
#include <initializer_list>
#include <cassert>
using namespace std;

#include "noeud.hpp"

//Constructeurs
Noeud::Noeud(){
  n = -1;
  fg = NULL;
  fd = NULL;
}
Noeud::Noeud(int nb){
  n = nb;
  fg = NULL;
  fd = NULL;
}
//Destructeur
Noeud *Noeud::videSousArbre(){
  if(this!=NULL){
    Noeud *tmp = this;
    if(fg!=NULL) fg->videSousArbre();
    if(fd!=NULL) fd->videSousArbre();
    delete this;
  }
  return NULL;
}
//Tests
bool Noeud::noeud_vide(){
  if(this==NULL){
    return true;
  }
  else{
    return false;
  }
}
bool Noeud::est_fils(Noeud *pere){
  if((pere->fd!=this) && (pere->fg!=this)){
    return false;
  }
  else{
    return true;
  }
}
bool Noeud::est_pere(Noeud *fils){
  if((fd!=fils)&&(fg!=fils)){
    return false;
  }
  else{
    return true;
  }
}
bool Noeud::appartient(int nb){
  if(etiquette()==nb){
    return true;
  }
  else{
    if(!fg->noeud_vide()){
      return (false || fg->appartient(nb));
    }
    else{
      if(!fd->noeud_vide()){
        return (false || fd->appartient(nb));
      }
      else{          // fg et fd == VIDE
        return false;
      }
    }
  }
}
//Infos
int Noeud::etiquette(){
  if(noeud_vide()){ //sécurité pour ne pas lire un noeud vide
    cerr<<endl<<"n.etiquette(): noeud 'vide'"<<endl;
    return -1;
  }
  else{
    return n;
  }
}
int Noeud::etiquette_fg(){
  if(noeud_vide()){
    cerr<<endl<<"n.etiquette_fg(): noeud vide"<<endl;
    return -1;
  }
  else{
    if(noeud_vide()){
      cerr<<endl<<"n.etiquette_fg(): pas de fils gauche"<<endl;
      return -1;
    }
    else{
      return(fg->etiquette());
    }
  }
}
int Noeud::etiquette_fd(){
  if(noeud_vide()){
    cerr<<endl<<"n.etiquette_fd(): noeud vide"<<endl;
    return -1;
  }
  else{
    if(noeud_vide()){
      cerr<<endl<<"n.etiquette_fd(): pas de fils droit"<<endl;
      return -1;
    }
    else{
      return(fd->etiquette());
    }
  }
}
int Noeud::hauteur(){
  if(fg->noeud_vide() && fd->noeud_vide()){
    return 1;
  }
  else{
    if(fg->noeud_vide()){
      return (fd->hauteur()+1);
    }
    else{
      if(fd->noeud_vide()){
        return (fg->hauteur()+1);
      }
      else{
        int hg = fg->hauteur();
        int hd = fd->hauteur();
        if(hg>hd){
          return hg+1;
        }
        else{
          return hd+1;
        }
      }
    }
  }
}
int Noeud::cardinal(){
  if(noeud_vide()){
    return 0;
  }
  else{
    return (1+fg->cardinal() + fd->cardinal());
  }
}
int Noeud::max(){
  if(fd->noeud_vide()){
    return n;
  }
  else{
    Noeud *tmp = fd;
    while(tmp->fd!=NULL){
      tmp = tmp->fd;
    }
    return tmp->n;
  }
}
int Noeud::min(){
  if(fg->noeud_vide()){
    return n;
  }
  else{
    Noeud *tmp = fg;
    while(tmp->fg!=NULL){
      tmp = tmp->fg;
    }
    return tmp->n;
  }
}
//Opérations
Noeud *Noeud::fils_gauche(){
  return fg;
}
Noeud *Noeud::fils_droit(){
  return fd;
}
int Noeud::etiquette(Noeud *pere, int nb){
  if(noeud_vide()){
    cerr<<endl<<"n.etiquette(): noeud 'vide'"<<endl;
  }
  else{
    if(pere->noeud_vide()){
      if(fg->noeud_vide()){
        if(fd->noeud_vide()){
          n = nb;
        }
        else{
          if(nb<fd->min()){
            n = nb;
          }
          else{
            cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
            cerr<<"non permise, fd->min() >= nb"<<endl;
          }
        }
      }
      else{
        if(fg->max()<nb){
          if(fd->noeud_vide()){
            n = nb;
          }
          else{
            if(nb<fd->min()){
              n = nb;
            }
            else{
              cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
              cerr<<"non permise, fd->min() >= nb"<<endl;
            }
          }
        }
        else{
          cerr<<endl<<"n.etiquette("<<nb<<") :";
          cerr<<"modification non permise, fg->max() >= nb"<<endl;
        }
      }
    }
    if(est_fils(pere)){
      if(pere->fg==this){
        if(fg->max()<nb && nb<pere->etiquette()){
          if(fd->noeud_vide()){
            n = nb;
          }
          else{
            if(nb < fd->min()){
              n = nb;
            }
            else{
              cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
              cerr<<"non permise, fd->min() >= nb"<<endl;
            }
          }
        }
        else{
          cerr<<endl<<"n.etiquette("<<nb<<") : ";
          cerr<<" modification non permise, fg->max() >= nb";
          cerr<<" ou nb >= pere->etiquette() "<<endl;
        }
      }
      else{
        if(pere->fd==this){
          if((fd->min() > nb)&&(nb > pere->etiquette())){
            if(fg->noeud_vide()){
              n = nb;
            }
            else{
              if(nb > fg->max()){
                n = nb;
              }
              else{
                cerr<<endl<<"n.etiquette("<<nb<<") : modification ";
                cerr<<"non permise, fg->max() <= nb"<<endl;
              }
            }
          }
          else{
            cerr<<endl<<"n.etiquette("<<nb<<") :";
            cerr<<" modification non permise, fg->max() >= nb";
            cerr<<" ou nb >= pere->etiquette() "<<endl;
          }
        }
      }
    }
    cerr<<endl<<"n.etiquette("<<nb<<") :";
    cerr<<"modification non permise, pere->fils() != n"<<endl;
  }
  return n;
}
void Noeud::insertion(int nb){
  if(nb!=etiquette()){
    if(nb < n){
      if(fg->noeud_vide()){
        fg = new Noeud(nb);
      }
      else{
        fg->insertion(nb);
      }
    }
    else{
      if(fd->noeud_vide()){
        fd = new Noeud(nb);
      }
      else{
        fd->insertion(nb);
      }
    }
  }
}
Noeud *Noeud::recherche(int nb){
  if(etiquette()==nb){
    return this;
  }
  else{
    if(!fg->noeud_vide()){
      return(fg->recherche(nb));
    }
    else{
      if(!fd->noeud_vide()){
        return(fd->recherche(nb));
      }
      else{ // fg & fd vides
        return NULL;
      }
    }
  }
}
Noeud *Noeud::recherche(int *t, int taille){
  Noeud *tmp = this;
  if((!noeud_vide()) && (taille<=hauteur())){
    bool b = true;
    for(int i=0 ; i<taille && b; i++){
      if(t[i]==-1){
        tmp = tmp->fg;
      }
      else{
        if(t[i]==1){
          tmp = tmp->fd;
        }
        else{
          b = false;
        }
      }
      if(tmp == NULL){ // tmp est une feuille
        b = false;
      }
    }
  }
  return tmp;
}
Noeud *Noeud::recherche_max(){
  if(noeud_vide()){
    return NULL;
  }
  else{
    if(fd->noeud_vide()){
      return this;
    }
    else{
      Noeud *tmp = fd;
      while(tmp->fd != NULL){
        tmp = tmp->fd;
      }
      return tmp;
    }
  }
}
Noeud *Noeud::recherche_pere(int nb){
  if(nb < n){
    if(fg != NULL){
      if(fg->n == nb){
        return this;
      }
      else{
        return(fg->recherche_pere(nb));
      }
    }
    else{
      return NULL;
    }
  }
  else{
    if(fd != NULL){
      if(fd->n == nb){
        return this;
      }
      else{
        return(fd->recherche_pere(nb));
      }
    }
    else{
      return NULL;
    }
  }
}
void Noeud::supprime(int nb){
  //On sait que nb != n car cette situation est gérée par le noeud précédent qui pointe sur ce noeud. (et n'ayant pas le Noeud "père" qui pointe sur le noeud même, ono ne pourra pas modifier son fils...)
  //Rappel : noeud->etiquette() == noeud->n

  Npeud *tmp;
  Noeud *pere_tmp;

  if(nb < etiquette()){
    if(fg->noeud_vide()){
      cerr<<endl<<"n.suppression: "<<nb;
      cerr<<" n'appartient pas a l'arbre"<<endl;
    }
    else{
      if(nb == fg->etiquette()){
        if(((fg->fg)->noeud_vide()) && ((fg->fd)->noeud_vide())){
          delete fg;
          fg = NULL;
        }
        else{
          if(fg->fg)->noeud_vide()){
            tmp = fg;
            fg = fg->fd;
            delete tmp;
          }
          else{
            tmp = fg->fg;
            pere_tmp = fg;
            while(tmp->fd != NULL){
              pere_tmp = tmp;
              tmp = tmp->fd;
            }
            if(tmp == fg->fg){
              fg->n = (fg->fg)->n;
              fg->fg = (fg->fg)->fg;
              delete tmp;
            }
            else{
              fg->n = tmp->n;
              pere_tmp->fd = tmp->fg;
              delete tmp;
            }
          }
        }
      }
      else{
        fg->supprime(nb);
      }
    }
  }
  else{ // nb > n (egalite impossible par hypothese)
    if(fd->noeud_vide()){
      cerr<<endl<<"n.suppression: "<<nb;
      cerr<<" n'appartient pas a l'arbre binaire"<<endl;
    }
    else{
      if(nb == fd->etiquette()){
        if(((fd->fg)->noeud_vide()) && ((fd->fg)->noeud_vide())){
          delete fd;
          fd = NULL;
        }
        else{ // fd a au moins un descendant
          if(fd->fg)->noeud_vide()){
            tmp = fd;
            fd = fd->fd;
            delete tmp;
          }
          else{ // fg->fg existe
            if(fd->fd)->noeud_vide()){
              tmp = fd;
              fd = fd->fg;
              delete tmp;
            }
            else{ // fd a exactement 2 descendants
              tmp = fd->fg;
              pere_tmp = fd;
              //tmp == max dans fg->fg
              while(tmp->fd != NULL){
                pere_tmp = tmp
                tmp = tmp->fd;
              }
              if(tmp == fd->fg){
                fd->n = (fd->fg)->n;
                fd->fg = (fd->fg)->fg;
                delete tmp;
              }
              else{
                fd->n = tmp->n;
                pere_tmp->fd = tmp->fg;
                delete tmp;
              }
            }
          }
        }
      }
      else{
        fd->supprime(nb);
      }
    }
  }
}
void Noeud::supprime_racine(){
  int m = -1;
  Noeud *tmp;
  if(!fg->noeud_vide()){
    m = fg->max();
    if(m == fg->n){
      tmp = fg->fg;
      supprime(m);
      fg = tmp;
    }
    else{
      supprime(m);
    }
    etiquette(VIDE, m);
  }
  else{
    if(!fd->noeud_vide()){
      m = fd->min();
      if(m == fd->n){
        tmp = fd->fd;
        supprime(m);
        fd = tmp;
      }
      else{
        supprime(m);
      }
      etiquette(VIDE, m);
    }
  }
}
//affichage
void Noeud::affiche_sous_arbre_1(){
  int h = hauteur()-1, i, j;
  int *t = new int[h];
  for(i=0 ; i<h ; i++){
    t[i] = 1;
  }
  Noeud *tmp;
  i = h-1;
  bool test = true;
  while(i>=0){
    tmp = recherche(t,h);
    //affichage du noeud
    if(test && !tmp->noeud_vide()){
      for(j=0 ; t[j] == -1 || t[j] == 1 ; j++){
        cout <<"\t";
      }
      if(tmp->fg == NULL) cout <<"|";
      cout<<tmp->etiquette();
      if(tmp->fd == NULL) cout <<"|";
      cout<<endl;
    }
    //noeud suivant
    switch(t[i]){
      case 1:
        t[i] = 0;
        test = true;
      break;
      case 0:
        t[i] = -1;
        for(j=i+1; j<h; j++){
          t[j] = 1;
        }
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
void Noeud::affiche_sous_arbre(){
  int h = hauteur()-1, i, j;
  int *t = new int[h+1];
  for(i=0 ; i<h ; i++){
    t[i] = 1;
  }
  t[h] = 0; // securite pour eviter de sortir du tableau
  Noeud *tmp;
  i = h-1;
  bool test = true;
  while(i >= 0){
    tmp = recherche(t,h);

    //affichage du noeud
    if(test && !temp->noeud_vide()){
      for(j=0 ; t[j] == -1 || t[j] == 1 ; j++){
        if(t[j+1] == 0 || j == h-1){
          if(t[j] == -1){
            printf("        %c", 192);
          }
          else{
            printf("        %c", 218);
          }
        }
        else{
          if(t[j]*t[j+1] == -1){
            printf("        %c", 179);
          }
          else{
            printf("         ");
          }
        }
      }
      printf("%6d", tmp->etiquette());
      if(tmp->fg != NULL && tmp->fd != NULL){
        printf(" %c%c", 196, 180);
      }
      else{
        if(tmp->fg != NULL){
          printf(" %c%c", 196, 191);
        }
        else{
          if(tmp->fd != NULL){
            printf(" %c%c", 196, 217);
          }
        }
      }
      cout<<endl;
    }
    //noeud suivant
    switch(t[i]){
      case 1:
        t[i] = 0;
        test = true;
      break;
      case 0:
        t[i] = -1;
        for(j=i+1 ; j<h ; j++){
          t[j] = 1;
        }
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
ostream& operator<<(ostream& o, Noeud n){
  if(!n.fg->noeud_vide()){
    o<<*(n.fg);
  }
  if(!n.noeud_vide()){
    o<<" "<<n.etiquette();
  }
  if(!n.fd->noeud_vide()){
    o<<*(n.fd);
  }
}
