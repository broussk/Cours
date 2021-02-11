package fr.corentin.tp.TP7.etoilecraft;

/**
 * Classe AUniteTerran qui implémente l'interface IUnite
 * @author DUPONT Corentin
 * @version 20/03/2020
 */

public abstract class AUniteTerran implements IUnite{

    private double pointsdeVie;
    private double pointsArmure;
    private double puissanceTirSol;
    private double puissanceTirAir;

    /**
     * Constructeur par défaut
     */
    public AUniteTerran() {
        this(100.00, 100.00, 15.00, 20.00 );
    }

    /**
     * Constructeur par initialisation
     * @param pdv point de vie
     * @param pda point d'armure
     * @param pts puissance tir sol
     * @param pta puissance tir air
     */
    public AUniteTerran(double pdv, double pda, double pts, double pta) {
        this.pointsdeVie = pdv;
        this.pointsArmure = pda;
        this.puissanceTirSol = pts;
        this.puissanceTirAir = pta;
    }


    /**
     * Retourne le nombre de points de vie de l'unité
     * @return pointsdeVie
     */
    public double getPointsDeVie() {
        return pointsdeVie;
    }


    /**
     * Retourne les points d'armure de l'unité
     * @return pointsArmure
     */
    public double getPointsArmure() {
        return pointsArmure;
    }


    /**
     * Retourne la puissance de tir au sol de l'unité
     * @return puissanceTirSol
     */
    public double getPuissanceTirSol() {
        return puissanceTirSol;
    }


    /**
     * Retourne la puissance de tir en l'air de l'unité
     * @return puissanceTirAir
     */
    public double getPuissanceTirAir() {
        return puissanceTirAir;
    }


    /**
     * Subit une attaque d'un ennemi
     * @param degats les dégats infligés
     * @return mort
     */
    public boolean subirAttaque(double degats) {
      boolean mort = false;
      pointsdeVie -= degats / pointsArmure;
       if (pointsdeVie <= 0){
         mort = true;
       }
     return mort;
    }


    /**
     * Indique si l'unité est volante ou non
     */
    public abstract boolean estVolante();


    /**
     * Attaque une unité
     * @param ref l'unité à attaquer
     * @return true si l'unité attaquée est tuée
     */
    public boolean attaquer(IUnite ref) {
      boolean mort = false;
      double degats;
        if (ref.estVolante() == true){
          degats = 0 + (Math.random() * ((puissanceTirAir - 0) + 1));
        }
        else {
          degats = 0 + (Math.random() * ((puissanceTirSol - 0) + 1));
        }
      return ref.subirAttaque(degats);
    }


    /**
     * Retourne une chaîne de caractéres décrivant une unité
     * @return la chaîne de caractéres
     */
    public String toString() {
        return " \n Vie : " + pointsdeVie + " \n Points Armure : " + pointsArmure + " \n Puissance Tir Sol : " + puissanceTirSol + " \n Puissance Tir Air : " + puissanceTirAir;
    }


    /**
     * Affiche la description de l'unité
     */
    public void afficher() {
        System.out.println(this);
    }

}
