





#include <iostream>
using namespace std;

#include "noeud.hpp"

//Constructeurs
Noeud::Noeud(){
  n = -1;
  fg = NULL;
  fd = NULL;
}
Noeud::Noeud(int nb,int couleur){
  v = nb;
  this.couleur=couleur;
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
bool *Noeud::estRouge(Noeud n){
  if(n.couleur==1){
    return(true);
  }else{
    return false
  }
}
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
        if(fg->max())
      }
    }
  }
}
