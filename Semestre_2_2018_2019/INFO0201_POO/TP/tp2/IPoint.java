/**
 * Interface <b>IPoint</b> qui doit &ecirc;tre impl&eacute;ment&eacute;e 
 * par les classes <b>PointCartesien</b> et <b>PointPolaire</b>
 * @author Cyril Rabat
 * @version 12/01/2010
 */

public interface IPoint {

    /**
     * Calcule la distance entre l'origine et le point
     * @return la distance entre l'origine et le point
     */
    public double distanceALOrigine();

    /**
     * Effectue une translation sur le point suivant le vecteur (dx,dy)
     * @param dx coordonn&eacute;e x du vecteur
     * @param dy coordonn&eacute;e y du vecteur
     */
    public void translation(double dx, double dy);

    /**
     * Permet d'afficher le point &agrave; l'&eacute;cran
     */
    public void afficher();

}
