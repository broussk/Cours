package mediatheque1;

import org.json.JSONObject;

/**
 * Classe représentant un auteur de livre.
 * @author Cyril Rabat
 */
public class Auteur{

    private String nom;
    private String dateNaissance;
   
    /**
     * Crée un auteur avec un nom et une date de naissance.
     * @param nom le nom
     * @param dateNaissance la date de naissance
     */
    public Auteur(String nom, String dateNaissance) {
        this.nom = nom;
        this.dateNaissance = dateNaissance;
    }
    
    /**
     * Retourne le nom.
     * @return le nom
     */
    public String getNom() {
        return nom;
    }
    
    /**
     * Retourne la date de naissance.
     * @return la date de naissance
     */
    public String getDateNaissance() {
        return dateNaissance;
    }
    
    /**
     * Convertit l'auteur en chaîne de caractères.
     * @return une chaîne de caractères
     */
    public String toString() {
        return nom + ", " + dateNaissance;
    }

    /**
     * Construit un objet JSon
     * @return un JSONObject de Auteur
     */
    public JSONObject toJSON() {
    	return new JSONObject(this);
    }

}