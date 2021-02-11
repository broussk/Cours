package fr.corentin.tp.TP8.astronomie;

import java.util.Vector;

/**
 * Classe AAstre
 * @author DUPONT Corentin
 * @version 25/03/2020
 */

public abstract class AAstre implements IAstre{

    /**
     * Attribut(s) de la classe
     */
  	private String nom;
  	private double masse;
  	private double diametre;
  	private double vitessederotation;
  	private Vector<Satellite> vsat = new Vector<Satellite>();

    /**
     * Constructeur par défaut
     */
  	public AAstre (){
      this("Defaut", 0, 0, 0);
  	}

    /**
     * Constructeur par initilaisation
     * @param nom le nom de l'étoile
     * @param masse la masse de l'étoile
     * @param diam le diamétre de l'étoile
     * @param vRot la vitesse de rotation de l'étoile
     */
    public AAstre (String nom, double masse, double diam, double vRot) {
       if(nom != null && !(nom.equals(""))) {
         this.nom = nom;
       } else {
         System.out.println("Nom invalide ! Un nom par défaut a ete attribuer");
         this.nom = "Defaut";
       }
       if(!(masse < 0)) {
	        this.masse = masse;
       } else {
         System.out.println("Masse invalide ! Une masse par défaut a ete attribuer");
         this.masse = 0;
       }

       if(!(diam < 0)) {
	        this.diametre = diam;
       } else {
         System.out.println("Diametre invalide ! Un diamtetre par défaut a ete attribuer");
        this.diametre = 0;
       }

       if(!(vRot < 0)) {
         this.vitessederotation = vRot;
       } else {
         System.out.println("Vitesse de rotation invalide ! Une vitesse de rotation par défaut a ete attribuer");
        this.vitessederotation = 0;
       }
  	}

    /**
     * Retourne le nom de l'astre
     * @return le nom de l'astre
     */
    public String getNom(){
        return nom;
    }

    /**
     * Retourne la masse de l'astre
     * @return masse
     */
    public double getMasse(){
          return masse;
    }

    /**
     * Retourne le diametre de l'astre
     * @return diametre
     */
    public double getDiametre(){
        return diametre;
    }

    /**
     * Retourne la vitesse de rotation
     * @return vitessederotation
     */
    public double getVitesseRotation(){
        return vitessederotation;
    }

    /**
     * Retourne le nombre de satellites
     * @return le nombre de satellites
     */
    public int getNombreSatellites(){
        return vsat.size();
    }

    /**
     * Retourne le satellite numero n de l'astre
     * @param n le numero du satellite
     * @return le satellite numero n ou null en cas d'erreur
     */
    public Satellite getSatellite(int n){
        return vsat.get(n);
    }

    /**
     * Ajoute un nouveau satellite
     * @param s le nouveau satellite
     */
    public void ajouterSatellite(Satellite s){
        if(s != null){
          vsat.add(s);
        } else {
          System.out.println("Vous ne pouvez pas ajouter de satellite null");
        }

    }

    /**
     * Retourne une chaîne de caractéres décrivant un astre
     * @return la chaîne de caractéres
     */
    public String toString(){
        return "\t Nom = "+ nom +". \t Masse = " + masse + ".\t  Diametre = "+ diametre + ". \t Rotation = "+ vitessederotation +".";
    }

    /**
     * Affiche à l'écran toutes les informations sur l'astre
     * Exemple d'affichage :
     * Nom      = Soleil
     * Masse    = 1989100x10^24 kg
     * Diametre = 1392000 km
     * Rotation = 576.0 j
     */
    public void afficher(){
        System.out.println(this);
    }

}
