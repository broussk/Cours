Exemple de bibliothèque : arbres binaires de recherche ( abr )--------------------------------------------------------------
Url     : http://codes-sources.commentcamarche.net/source/11023-exemple-de-bibliotheque-arbres-binaires-de-recherche-abrAuteur  : FlashRaptoRDate    : 28/08/2013
Licence :
=========

Ce document intitulé « Exemple de bibliothèque : arbres binaires de recherche ( abr ) » issu de CommentCaMarche
(codes-sources.commentcamarche.net) est mis à disposition sous les termes de
la licence Creative Commons. Vous pouvez copier, modifier des copies de cette
source, dans les conditions fixées par la licence, tant que cette note
apparaît clairement.

Description :
=============

Une biblioth&egrave;que Arbres.h qui contient la d&eacute;finition du type arbre
 binaire de recherche, et des fonctions qui vont avec.
<br />
<br />Interressa
nt pour ceux qui veulent apprendre les structures et les pointeurs.
<br />
<br
 />( c'est mon premier &quot;projet&quot; en C )
<br /><a name='source-exemple'
></a><h2> Source / Exemple : </h2>
<br /><pre class='code' data-mode='basic'>

#include &lt;stdio.h&gt;

struct Noeud
{
    int valeur ;
    struct Noeud
* gauche ;
    struct Noeud* droit ;
};

typedef struct Noeud TNoeud; 
type
def struct Noeud* TArbre; 

//************************************************
**************

TArbre NouvelArbreVide( void )
{
    return NULL;
}

//**
************************************************************
// Toutes les fonc
tions sont basées sur la récursivité, parfaite
// ment adaptée aux arbres binai
res.
//**************************************************************

void A
jouter( TArbre* arbre , int val )
{
    if( *arbre == NULL )
    {

<ul>   
     <li>arbre = ( TArbre )malloc( sizeof( TNoeud ) );</li></ul>
        (*arbr
e)-&gt;valeur = val ;
        (*arbre)-&gt;gauche = NULL ;
        (*arbre)-&g
t;droit = NULL ;
    }
    else
    {
        if( val &lt; (*arbre)-&gt;vale
ur )
        {
                Ajouter( &amp;(*arbre)-&gt;gauche , val ) ;
  
      }
        else
        {
                Ajouter( &amp;(*arbre)-&gt;dro
it , val ) ;
        }
    }
}

//*****************************************
*********************

void Afficher( TArbre arbre )
{
    if( arbre != NULL
 )
    {
        Afficher( arbre-&gt;gauche ) ;
        printf( &quot;%d &quo
t; , arbre-&gt;valeur ) ;
        Afficher( arbre-&gt;droit ) ;
    }
}

//
**************************************************************

int NombreElem
ents( TArbre arbre )
{
    if( arbre == NULL )
    {
        return (0) ;
 
   }
    else
    {
        return( 1 + NombreElements( arbre-&gt;gauche ) + 
NombreElements( arbre-&gt;droit ) ) ;
    }
}

//***************************
***********************************

int Hauteur( TArbre arbre )
{
    if( a
rbre == NULL )
    {
        return (0);
    }
    else
    {
    
      
  int h1,h2 ;
        
        h1 = Hauteur( arbre-&gt;gauche ) ;
        h2 
= Hauteur( arbre-&gt;droit ) ;
        
        if( h1 &lt; h2 )
        {
 
               return( 1 + h2 ) ;
        }
        else
        {
         
       return( 1 + h1 ) ;
        }
    }
}

//****************************
***********************************

int Somme( TArbre arbre )
{
    if( arb
re == NULL )
    {
        return (0) ;
    }
    else
    {
        retur
n ( arbre-&gt;valeur + Somme( arbre-&gt;droit ) + Somme( arbre-&gt;gauche ) ) ;

    }
}
</pre>
