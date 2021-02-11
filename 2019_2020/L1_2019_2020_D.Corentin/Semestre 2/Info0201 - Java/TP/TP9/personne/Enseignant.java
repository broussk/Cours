package fr.corentin.tp.TP9.personne;

/**
 * Classe représentant un enseignant.
 * @author DUPONT Corentin
 * @version 03/03/2020
 */

public class  Enseignant extends Personne implements Cloneable {

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
        this.salaire = salaire;
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
        boolean ok = false;
        if (p.getClass() == getClass()){
            Enseignant ref = (Enseignant)p;
            ok = (getNom() == ref.getNom()) && (getPrenom() == ref.getPrenom() && salaire == ref.salaire);
        }
        return ok;
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