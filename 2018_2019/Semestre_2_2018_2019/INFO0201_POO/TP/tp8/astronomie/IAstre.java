package astronomie;

/**
 * Interface decrivant le fonctionnement d'un astre
 * @author Cyril Rabat
 * @version 23/03/2011
 */
public interface IAstre {

    /**
     * Retourne le nom de l'astre
     * @return le nom de l'astre
     */
    public String getNom();

    /**
     * Retourne la masse de l'astre
     * @return la masse de l'astre
     */
    public double getMasse();

    /**
     * Retourne le diametre de l'astre
     * @return le diametre de l'astre
     */
    public double getDiametre();

    /**
     * Retourne la vitesse de rotation
     * @return la vitesse de rotation
     */
    public double getVitesseRotation();

    /**
     * Retourne le nombre de satellites
     * @return le nombre de satellites
     */
    public int getNombreSatellites();

    /**
     * Retourne le satellite numero n de l'astre
     * @param n le numero du satellite
     * @return le satellite numero n ou null en cas d'erreur
     */
    public Satellite getSatellite(int n);

    /**
     * Ajoute un nouveau satellite
     * @param s le nouveau satellite
     */
    public void ajouterSatellite(Satellite s);

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Soleil
     * @return une chaine de caracteres
     */
    public String toString();

    /**
     * Affiche a l'ecran toutes les informations sur l'astre
     * Exemple d'affichage :
     * Nom      = Soleil
     * Masse    = 1989100x10^24 kg
     * Diametre = 1392000 km
     * Rotation = 576.0 j
     */
    public void afficher();
}
