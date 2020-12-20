package mediatheque2;

import java.util.HashMap;

/**
 * Classe représentant une médiathèque.
 * @author Cyril Rabat
 */
public class Mediatheque {
    
    private static int compteur = 0;
    
    private HashMap<Integer,Document> documents;
    
    /**
     * Crée une médiathèque.
     */
    public Mediatheque() {
        documents = new HashMap<Integer,Document>();
    }
    
    /**
     * Ajoute un document à la médiathèque et retourne son identifiant.
     * @param d le document à ajouter
     * @return l'identifiant du document ajouté
     */
    public int ajouterDocument(Document d) {
        documents.put(compteur, d);
        return compteur++;
    }
    
    /** 
     * Retourne le ième document.
     * @param i l'indice du document
     * @return le document (ou null)
     */
    public Document getDocument(int i) {
        Document resultat = null;
        
        if(documents.containsKey(i)) {
            resultat = documents.get(i);
        }
        
        return resultat;
    }
        
}