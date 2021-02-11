package fr.corentin.tp.TP8.astronomie;

/**
 * Classe Satellite qui hérite de AAstre et implémente ISatellite
 * @author DUPONT Corentin
 * @version 25/03/2020
 */

public class Satellite extends AAstre implements ISatellite {

    /**
     * Attribut(s) de la classe
     */
    protected AAstre astreReference;
    private double vitesseRevolution;
    private double distanceAstreRef;

    /**
     * Constructeur par défaut
     */
    public Satellite(){
      super();
    }

    /**
     * Constructeur par initilaisation
     * @param nom le nom du satellite
     * @param masse la masse du satellite
     * @param diam le diamétre du satellite
     * @param vRot la vitesse de rotation du satellite
     * @param astreReference l'astre de référencde du satellite
     * @param vitesseRevolution la vitesse de révoluton du satellite
     * @param distanceAstreRef la distance entre le satellite et de son astre de référence
     */
    public Satellite (String nom, double masse, double diam, double vRot, AAstre astreReference, double vitesseRevolution, double distanceAstreRef){
        super(nom,masse,diam,vRot);
        if(astreReference != null){
            this.astreReference = astreReference;
        } else {
            System.out.println("Astre de reference invalide ! Un Astre par défaut a ete attribuer");
            this.astreReference = new Etoile();
        }
        if (!(distanceAstreRef < 0)){
            this.distanceAstreRef = distanceAstreRef;
        } else {
          System.out.println("Distance invalide ! Une distance par défaut a ete attribuer");
          this.distanceAstreRef = 0;
        }
        if (!(vitesseRevolution < 0)){
            this.vitesseRevolution = vitesseRevolution;
        } else {
          System.out.println("Vitesse de révolution invalide ! Une vitesse de révolution par défaut a ete attribuer");
          this.vitesseRevolution = 0;
        }
    }

    /**
     * Retourne la référence d'un AAstre
     * @return astreReference
     */
    public AAstre getAstreReference(){
        return astreReference;
    }

    /**
     * Retourne la distance
     * @return distanceAstreRef
     */
    public double getDistance(){
        return distanceAstreRef;
    }

    /**
     * Retourne la vitesse de révolution
     * @return vitesseRevolution
     */
    public double getVitesseRevolution(){
        return vitesseRevolution;
    }

    /**
     * Retourne une chaîne de caractéres décrivant un satellite
     * @return la chaîne de caractéres
     */
    public String toString(){
        return getNom() + ", satellite de " + astreReference.toString();
    }
}
