package fr.corentin.tp.TP10.personne;

import java.io.Serializable;

/**
 * Classe représentant un enseignant.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class  Enseignant extends Personne implements Cloneable, Serializable {

    /**
     * Attribut(s) de classe
     */
    private double salaire;

    /**
     * Constructeur par initialisation.
     * @param nom le nom de l'enseignant
     * @param prenom le prénom de l'enseignant
     * @param salaire le salaire de l'enseignant
     */
    public Enseignant(String nom, String prenom, double salaire) {
        super(nom, prenom);
        if(!(salaire < 0)){
          this.salaire = salaire;
        } else {
          System.out.println("Salaire invalide. Un salaire par défaut a été attribué.");
          this.salaire = 1500;
        }

    }

    /**
     * Constructeur par copie
     * @param p objet qui sera copié
     */
    public Enseignant(Enseignant p){
        this(p.getNom(), p.getPrenom(),p.getSalaire());
    }

    /**
     * Retourne le salaire de l'enseignant
     * @return le salaire de l'enseignant
     */
    public double getSalaire() {
        return salaire;
    }

    /**
     * Permeet de comparer un objet à celui de l'enseignant
     * @return true si ce sont les mêmes
     */
    public boolean equals(Object p){
        if (p.getClass() == getClass()){
            Enseignant ref = (Enseignant)p;
            return (getNom() == ref.getNom()) && (getPrenom() == ref.getPrenom() && salaire == ref.salaire);
        }
        return false;
    }

    /**
     * Permet de clone un objet de type Enseignant
     * @return l'objet cloné
     */
    public Enseignant clone(){
        Enseignant ref = null;
        ref = (Enseignant)super.clone();
        ref.salaire = salaire;
        return ref;
    }

    /**
     * Retourne une chaîne de caractéres décrivant un enseignant
     * @return la chaîne de caractéres
     */
    public String toString(){
        return "Enseignant " + super.toString() + ", salaire " + salaire +" euros";
    }
}
