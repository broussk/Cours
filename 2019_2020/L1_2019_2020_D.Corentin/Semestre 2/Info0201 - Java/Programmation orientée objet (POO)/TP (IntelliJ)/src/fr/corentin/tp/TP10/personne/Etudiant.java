package fr.corentin.tp.TP10.personne;

import java.io.Serializable;

/**
 * Classe représentant un étudiant.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class Etudiant extends Personne implements Cloneable, Serializable {

    /**
     * Attribut(s) de classe
     */
    private int numeroEtudiant;

    /**
     * Constructeur par initialisation.
     * @param nom le nom de l'étudiant
     * @param prenom le prénom de l'étudiant
     * @param numero le numéro d'étudiant
     */
    public Etudiant(String nom, String prenom, int numero) {
        super(nom, prenom);
        if(!(numero < 0)){
          this.numeroEtudiant = numero;
        } else {
          System.out.println("Numéro étudiant invalide. Un numéro étudiant par défaut a été attribué.");
          this.numeroEtudiant = 00000000;
        }

    }

    /**
     * Constructeur par copie
     * @param p objet qui sera copié
     */
    public Etudiant(Etudiant p){
        this(p.getNom(),p.getPrenom(),p.getNumeroEtudiant());
    }

    /**
     * Retourne le numéro d'étudiant de l'étudiant.
     * @return le numéro d'étudiant
     */
    public int getNumeroEtudiant() {
        return numeroEtudiant;
    }

    /**
     * Permeet de comparer un objet à celui de l'Etudiant
     * @return true si ce sont les mêmes
     */
    public boolean equals(Object p){
        if (p.getClass() == getClass()){
            Etudiant ref = (Etudiant)p;
            return (getNom() == ref.getNom()) && (getPrenom() == ref.getPrenom() && numeroEtudiant == ref.numeroEtudiant);
        }
        return false;
    }

    /**
     * Permet de clone un objet de type Vactaire
     * @return l'objet cloné
     */
    public Etudiant clone(){
        Etudiant ref = null;
        ref = (Etudiant)super.clone();
        ref.numeroEtudiant = numeroEtudiant;
        return ref;
    }

    /**
     * Permet de clone un objet de type Vacataire
     * @return l'objet cloné
     */
    public String toString(){
        return "Etudiant " + super.toString() + ", numero " + numeroEtudiant;
    }

}
