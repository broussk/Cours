package fr.corentin.tp.TP7.etoilecraft;

/**
 * Classe Flammeur qui hérite de AUniteTerran
 * @author DUPONT Corentin
 * @version 20/03/2020
 */

public class Flammeur extends AUniteTerran {

    /**
     * Constructeur par défaut
     */
    public Flammeur() {
        super(85.0, 4.0, 40.0, 0.0);
    }


    /**
     * Constructeur par initialisation
     *@param pdv point de vie
     *@param pda point d'armure
     *@param pts puissance tir sol
     */
    public Flammeur(double pdv, double pda, double pts) {
        super(pdv, pda, pts, 0);
    }


    /**
     * Indique si l'unité est volante ou non
     * @return vrai si l'unité est volante
     */
    public boolean estVolante() {
        return false;
    }


    /**
     * Retourne une chaîne de caractéres décrivant un flammeur
     * @return la chaîne de caractéres
     */
    public String toString() {
        return "Flammeur : " + super.toString();
    }


}
