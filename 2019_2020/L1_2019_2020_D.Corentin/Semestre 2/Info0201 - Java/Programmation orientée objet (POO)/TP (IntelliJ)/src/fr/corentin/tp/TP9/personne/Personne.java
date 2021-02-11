package fr.corentin.tp.TP9.personne;

/**
 * Classe représentant une personne.
 * @author DUPONT Corentin
 * @version 03/03/2020
 */

public class Personne implements Cloneable{

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
        this.nom = nom;
        this.prenom = prenom;
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
        boolean ok = false;
        if (p.getClass() == getClass()){
            Personne ref = (Personne)p;
            ok = (nom == ref.nom) && (prenom == ref.prenom);
        }
        return ok;
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