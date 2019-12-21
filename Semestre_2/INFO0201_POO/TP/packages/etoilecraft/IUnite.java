package etoilecraft;

/**
 * Interface IUnite indiquant les actions de toutes les unites
 * @version 16/03/2011
 * @author Cyril Rabat
 */
public interface IUnite {

    /**
     * Retourne le nombre de points de vie de l'unite
     * @return le nombre de points de vie
     */
    public double getPointsDeVie();

    /**
     * Retourne les points d'armure de l'unite
     * @return les points d'armure
     */
    public double getPointsArmure();

    /**
     * Retourne la puissance de tir au sol de l'unite
     * @return la puissance de tir au sol
     */
    public double getPuissanceTirSol();

    /**
     * Retourne la puissance de tir en l'air de l'unite
     * @return la puissance de tir en l'air
     */
    public double getPuissanceTirAir();

    /**
     * Subit une attaque d'un ennemi
     * @param degats les degats infliges
     * @return vrai si l'unite est tuee, faux sinon
     */
    public boolean subirAttaque(double degats);

    /**
     * Indique si l'unite est volante ou non
     * @return vrai si l'unite est volante
     */
    public boolean estVolante();

    /**
     * Attaque une unite
     * @param u l'unite a attaquer
     * @return true si l'unite attaquee est tuee
     */
    public boolean attaquer(IUnite u);

}