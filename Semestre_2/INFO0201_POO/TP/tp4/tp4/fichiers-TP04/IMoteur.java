/**
 * L'interface <b>IMoteur</b> est impl&eacute;ment&eacute;e par la classe
 *   <b>Moteur</b>
 * @author Cyril Rabat
 * @version 10/02/2019
 */
public interface IMoteur {

    /**
     * Retourne la carburation du moteur
     * @return la carburation
     */
    public String getCarburation();

    /**
     * Retourne la consommation du moteur
     * @return la consommation
     */
    public double getConsommation();

    /**
     * Affiche le moteur &agrave; l'&eacute;cran
     */
    public void afficher();

    /**
     * Retourne un moteur sous forme de chaine de caract&egrave;res
     * @return une chaine de caract&egrave;res
     */
    public String toString();

}

