package fr.corentin.tp.TP9.personne;

/**
 * Classe représentant un vacataire.
 * @author DUPONT Corentin
 * @version 03/03/2020
 */

public class Vacataire extends Enseignant implements Cloneable {

    /**
     * Attribut(s) de classe
     */
    private String entreprise;

    /**
     * Constructeur par copie
     * @param nom nom du vacataire
     * @param prenom prenom du vacataire
     * @param salaire salaire du vacataire
     * @param entreprise entreprise ou travaille le vacataire
     */
    public Vacataire(String nom, String prenom, double salaire, String entreprise) {
        super(nom, prenom,salaire);
        this.entreprise = entreprise;
    }

    /**
     * Constructeur par copie
     * @param p objet qui sera copié
     */
    public Vacataire(Vacataire p){
        this(p.getNom(),p.getPrenom(),p.getSalaire(),p.getEntreprise());
    }

    /**
     * Retourne l'entreprise du vacataire
     * @return l'entreprise
     */
    public String getEntreprise() {
        return entreprise;
    }

    /**
     * Permeet de comparer un objet à celui du Vacataire
     * @return true si ce sont les mêmes
     */
    public boolean equals(Object p){
        boolean ok = false;
        if (p.getClass() == getClass()){
            Vacataire ref = (Vacataire) p;
            ok = (getNom() == ref.getNom() && getPrenom() == ref.getPrenom() && getSalaire() == ref.getSalaire() && entreprise == ref.entreprise);
        }
        return ok;
    }

    /**
     * Permet de clone un objet de type Vacataire
     * @return l'objet cloné
     */
    public Vacataire clone(){
        Vacataire ref = null;
        ref = (Vacataire)super.clone();
        ref.entreprise = entreprise;
        return ref;
    }

    /**
     * Retourne une chaîne de caractéres décrivant un vacataire
     * @return la chaîne de caractéres
     */
    public String toString(){
        return "Vacataire " + getNom() + " " + getPrenom() +", salaire " + getSalaire() +" euros, dans l'entreprise " + entreprise;
    }

}
