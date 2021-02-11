package fr.corentin.tp.TP10.personne;

import java.io.Serializable;

/**
 * Classe représentant une personne.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class Personne implements Cloneable, Serializable {

    /**
     * Attribut(s) de classe
     */
    private String nom;
    private String prenom;

    /**
     * Constructeur par initialisation.
     * @param nom le nom de la personne
     * @param prenom le prénom de la personne
     */
    public Personne(String nom, String prenom) {
      if(nom!= null || !nom.equals("")){
        this.nom = nom;
      } else {
        System.out.println("Nom invalide. Un nom par défaut a été attribué.");
        this.prenom = "DUPONT";
      }

      if(prenom!= null || !prenom.equals("")){
        this.prenom = prenom;
      } else {
         System.out.println("Prenom invalide. Un prenom par défaut a été attribué.");
         this.prenom = "Corentin";
      }
    }

    /**
     * Constructeur par copie
     * @param p objet qui sera copié
     */
    public Personne(Personne p){
        this(p.getNom(),p.getPrenom());
    }

    /**
     * Retourne le nom de la personne.
     * @return le nom de la personne
     */
    public String getNom() {
        return nom;
    }

    /**
     * Retourne le prénom de la personne.
     * @return le prénom de la personne
     */
    public String getPrenom() {
        return prenom;
    }

    /**
     * Permeet de comparer un objet à celui de Personne
     * @return true si ce sont les mêmes
     */
    public boolean equals(Object p){
        if (p.getClass() == getClass()){
            Personne ref = (Personne)p;
            return  (nom == ref.nom) && (prenom == ref.prenom);
        }
        return false;
    }

    /**
     * Permet de clone un objet de type Personne
     * @return l'objet cloné
     */
    public Personne clone(){
        Personne ref = null;
        try{
            ref = (Personne)super.clone();
            ref.nom = nom;
            ref.prenom = prenom;
        }
        catch (CloneNotSupportedException e){
            e.printStackTrace(System.err);
        }
        return ref;
    }

    /**
     * Retourne une chaîne de caractéres décrivant une personne
     * @return la chaîne de caractéres
     */
    public String toString(){
        return nom + " " + prenom;
    }
}
