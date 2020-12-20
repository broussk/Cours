package mediatheque2;

import org.json.JSONObject;

/**
 * Classe représentant un film.
 * @author Cyril Rabat
 */
public class Film extends Document {
    
    private Personne realisateur;
    private double duree;
    
    /**
     * Crée un film.
     * @param titre le titre
     * @param realisateur le réalisateur
     * @param duree la durée du film
     */
    public Film(String titre, Personne realisateur, double duree) {
        super(titre);
        this.realisateur = realisateur;
        this.duree = duree;
    }

    /**
     * Retourne le réalisateur.
     * @return le réalisateur
     */
    public Personne getRealisateur() {
        return realisateur;
    }

    /**
     * Retourne la durée.
     * @return la durée
     */
    public double getDuree() {
        return duree;
    }
    
    /**
     * Convertit le film en chaîne de caractères.
     * @return une chaîne de caractères
     */
    public String toString() {
        return super.toString() + " (" + realisateur + ", " + duree + ")";
    }

    /**
     * Construit un objet JSon
     * @return un JSONObject de Film
     */
    public JSONObject toJSON() {
    	return new JSONObject(this);
    }
    
}