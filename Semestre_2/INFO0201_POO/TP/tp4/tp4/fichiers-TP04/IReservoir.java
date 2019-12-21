/**
 * L'interface <b>IReservoir</b> est impl&eacute;ment&eacute;e par la classe
 * <b>Reservoir</b>
 * @author Cyril Rabat
 * @version 10/02/2019
 */
public interface IReservoir {

    /**
     * Retourne la capacit&eacute; du r&eacute;servoir
     * @return la capacit&eacute;
     */
    public double getCapacite();

    /**
     * Retourne le contenu du r&eacute;servoir
     * @return le contenu
     */
    public double getContenu();

    /**
     * Remplit le r&eacute;servoir d'une certaine quantit&eacute;
     * @param quantite la quantit&eacute; &agrave; remplir
     */
    public void remplir(double quantite);

    /**
     * Vide le r&eacute;servoir d'une certaine quantit&eacute;
     * @param quantite la quantit&eacute; &agrave; vider
     */
    public void vider(double quantite);

    /**
     * Affiche le r&eacute;servoir &agrave; l'&eacute;cran
     */
    public void afficher();

    /**
     * Retourne un r&eacute;servoir sous forme de chaine de caract&egrave;res
     * @return une chaine de caract&egrave;res
     */
    public String toString();

}
