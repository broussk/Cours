/**
 * L'interface <b>IVoiture</b> doit &ecirc;tre impl&eacute;ment&eacute;e par les
 * classes <b>VoitureSurface</b> et <b>VoitureProfonde</b>.
 * @author Cyril Rabat
 * @version 10/02/2019
 */
package transport;
public interface IVoiture {

    /**
     * Fait avancer la voiture de la distance sp&eacute;cifi&eacute;e en
     * param&egrave;tre et retourne le nombre de kilom&egrave;tres qui ont
     * &eacute;t&eacute; effectivement parcourus
     * @param distance la distance &agrave; parcourir
     * @return le nombre de kilom&egrave;tres parcourus
     */
    public double avancer(double distance);

    /**
     * Fait le plein du r&eacute;servoir de la voiture
     * @return la quantit&eacute; ajout&eacute;e dans le r&eacute;servoir
     */
    public double faireLePlein();

    /**
     * Retourne le contenu du r&eacute;servoir de la voiture
     * @return le contenu du r&eacute;servoir
     */
    public double getContenuReservoir();

}
