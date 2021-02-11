package fr.corentin.tp.TP7.etoilecraft;

/**
 * Classe Cuirasse qui hérite de AUniteTerran
 * @author DUPONT Corentin
 * @version 20/03/2020
 */

public class Cuirasse extends AUniteTerran {

    /**
     * Constructeur par défaut
     */
    public Cuirasse() {
        super(100.0, 20.0, 55.0, 35.0);
    }


    /**
     * Constructeur par initialisation
     * @param pdv point de vie
     * @param pda point d'armure
     * @param pta puissance tir air
     * @param pts puissance tir sol
     */
    public Cuirasse(double pdv, double pda, double pta, double pts) {
        super(pdv, pda, pta, pts);
    }


    /**
     * Indique si l'unité est volante ou non
     * @return vrai si l'unité est volante
     */
    public boolean estVolante() {
        return true;
    }


    /**
     * Retourne une chaîne de caractéres décrivant un cuirasse
     * @return la chaîne de caractéres
     */
    public String toString() {
        return "Cuirasse : " + super.toString();
    }

}
