package fr.corentin.tp.TP8.astronomie;

/**
 * Classe Etoile qui hérite de AAstre et implémente IEtoile
 * @author DUPONT Corentin
 * @version 25/03/2020
 */

public class Etoile extends AAstre implements IEtoile{

    /**
     * Attribut(s) de de la classe
     */
    private double age;

    /**
     * Constructeur par défaut
     */
    public Etoile(){
      super();
    }

    /**
     * Constructeur par initilaisation
     * @param nom le nom de l'étoile
     * @param masse la masse de l'étoile
     * @param diam le diamétre de l'étoile
     * @param vRot la vitesse de rotation de l'étoile
     * @param age l'âge de l'étoile
     */
    public Etoile (String nom, double masse, double diam, double vRot, double age){
        super(nom,masse,diam,vRot);

        if(!(age < 0)){
          this.age = age;
        } else {
          System.out.println("Age de l'etoile invalide ! Un age par défaut a ete attribuer");
          this.age = 0;
        }
    }

    /**
     * Retourne l'âge de l'etoile
     * @return age
     */
    public double getAge(){
        return age;
    }

    /**
     * Retourne une chaîne de caractéres décrivant une étoile
     * @return la chaîne de caractéres
     */
    public String toString(){
        return super.getNom().toString() + ", etoile";
    }
}
