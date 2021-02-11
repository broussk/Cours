package fr.corentin.tp.TP8.astronomie;

/**
 * Classe Planete qui hérite de Satellite et implémente IPlanete
 * @author DUPONT Corentin
 * @version 25/03/2020
 */

public class Planete extends Satellite implements IPlanete{

    /**
     * Attribut(s) de la classe
     */
    private String typePlanete;


    /**
     * Constructeur par défaut
     */
    public Planete(){
      super();
    }

    /**
     * Constructeur par initilaisation
     * @param nom le nom de la planéte
     * @param masse la masse de la planéte
     * @param diam le diamétre de la planéte
     * @param vRot la vitesse de rotation de la planéte
     * @param astreReference l'astre de référencde de la planéte
     * @param vitesseRevolution la vitesse de révoluton de la planéte
     * @param distanceAstreRef la distance entre la planéte et de son astre de référence
     * @param typePlanete le type de la planéte
     */
    public Planete(String nom, double masse, double diam, double vRot, AAstre astreReference, double vitesseRevolution, double distanceAstreRef, String typePlanete){
        super(nom,masse,diam,vRot,astreReference,vitesseRevolution,distanceAstreRef);
        if(typePlanete != null && !(typePlanete.equals(""))){
          this.typePlanete = typePlanete;
        } else {
          System.out.println("Type de planete invalide ! Un type par défaut a ete attribuer");
          this.typePlanete = "Gazeuse";
        }
    }

    /**
     * Retourne le type de la planéte
     * @return typePlanete
     */
    public String getType(){
        return typePlanete;
    }

    /**
     * Retourne une chaîne de caractéres décrivant une planéte
     * @return la chaîne de caractéres
     */
    public String toString(){
        return getNom() + ", planete autour de " + astreReference.getNom();
    }

}
