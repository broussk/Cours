package astronomie;

/**
 * Interface decrivant le fonctionnement d'un satellite
 * @author Cyril Rabat
 * @version 23/03/2011
 */
public interface ISatellite {

    /**
     * Retourne l'astre de reference
     * @return l'astre de reference
     */
    public AAstre getAstreReference();

    /**
     * Retourne la distance par rapport a l'astre de reference
     * @return la distance par rapport a l'astre de reference
     */
    public double getDistance();

    /**
     * Retourne la vitesse de revolution autour de l'astre de reference
     * @return la vitesse de revolution
     */
    public double getVitesseRevolution();

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Lune, satellite de Terre, planete autour de Soleil
     * @return une chaine de caracteres
     */
    public String toString();
}
