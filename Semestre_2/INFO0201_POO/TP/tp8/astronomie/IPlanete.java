package astronomie;

/**
 * Interface decrivant le fonctionnement d'une planete
 * @author Cyril Rabat
 * @version 23/03/2011
 */
public interface IPlanete {

    /**
     * Retourne le type de la planete : tellurique ou gazeuse
     * @return le type de la planete
     */
    public String getType();

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Terre, planete autour de Soleil
     * @return une chaine de caracteres
     */
    public String toString();
}
