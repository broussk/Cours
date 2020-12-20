package mediatheque1;

import java.util.HashMap;

/**
 * Classe représentant une médiathèque.
 * @author Cyril Rabat
 */
public class Mediatheque {
    
    private static int compteur = 0;
    
    private HashMap<Integer,Livre> livres;
    
    /**
     * Crée une médiathèque.
     */
    public Mediatheque() {
        livres = new HashMap<Integer,Livre>();
    }
    
    /**
     * Ajoute un livre à la médiathèque et retourne son identifiant.
     * @param l le livre à ajouter
     * @return l'identifiant du livre ajouté
     */
    public int ajouterLivre(Livre l) {
        livres.put(compteur, l);
        return compteur++;
    }
    
    /** 
     * Retourne le ième livre.
     * @param i l'indice du livre
     * @return le livre (ou null)
     */
    public Livre getLivre(int i) {
        Livre resultat = null;
        
        if(livres.containsKey(i)) {
            resultat = livres.get(i);
        }
        
        return resultat;
    }
        
}