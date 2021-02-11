package fr.corentin.tp.TP9.personne;

/**
 * Classe représentant un étudiant.
 * @author DUPONT Corentin
 * @version 03/03/2020
 */

public class Etudiant extends Personne implements Cloneable {

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
        this.numeroEtudiant = numero;
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
        boolean ok = false;
        if (p.getClass() == getClass()){
            Etudiant ref = (Etudiant)p;
            ok = (getNom() == ref.getNom()) && (getPrenom() == ref.getPrenom() && numeroEtudiant == ref.numeroEtudiant);
        }
        return ok;
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