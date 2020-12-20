package mediatheque1;

/**
 * Classe représentant un livre.
 * @author Cyril Rabat
 */
public class Livre {
    
    private String titre;
    private Auteur auteur;
    
    /**
     * Crée un livre.
     * @param titre le titre
     * @param auteur l'auteur
     */
    public Livre(String titre, Auteur auteur) {
        this.titre = titre;
        this.auteur = auteur;
    }
    
    /**
     * Retourne le titre.
     * @return le titre
     */
    public String getTitre() {
        return titre;
    }
    
    /**
     * Retourne l'auteur.
     * @return l'auteur
     */
    public Auteur getAuteur() {
        return auteur;
    }
    
    /**
     * Convertit le livre en chaîne de caractères.
     * @return une chaîne de caractères
     */
    public String toString() {
        return titre + " (" + auteur + ")";
    }
    
}