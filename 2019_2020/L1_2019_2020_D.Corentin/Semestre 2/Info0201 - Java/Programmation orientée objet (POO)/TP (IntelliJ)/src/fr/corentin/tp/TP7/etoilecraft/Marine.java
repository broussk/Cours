package fr.corentin.tp.TP7.etoilecraft;

/**
 * Classe Marine qui hérite de AUniteTerran
 * @author DUPONT Corentin
 * @version 20/03/2020
 */

public class Marine extends AUniteTerran {

    /**
     * Constructeur par défaut
     */
    public Marine() {
        super(75.0, 3.0, 25.0, 0.0);
    }


    /**
     * Constructeur par initialisation
     * @param pdv point de vie
     * @param pda point d'armure
     * @param pts puissance tir sol
     */
    public Marine(double pdv, double pda, double pts) {
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
     * Retourne une chaîne de caractéres décrivant une marine
     * @return la chaîne de caractéres
     */
    public String toString() {
        return "Marine : " + super.toString();
    }

}
