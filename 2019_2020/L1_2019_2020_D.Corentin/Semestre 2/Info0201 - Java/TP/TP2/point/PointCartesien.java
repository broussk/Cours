package fr.corentin.tp.TP2.point;

import fr.corentin.tp.TP2.point.IPoint;

/**
  * Classe PointCartesien qui implémente l'interface IPoint
  * @author DUPONT Corentin et LACROIX Owen
  * @version 30/01/2020
  */

public class PointCartesien implements IPoint {

  /**
    * Attributs caracterisant le PointCartesien
    */
  private String nom;
  private double x;
  private double y;

  /**
    * Constructeur par initialisation
    * @param nom qui est le nom du point
    * @param x abscisse du point
    * @param y ordonnée du point
    */
  public PointCartesien(String nom, double x, double y){
    this.nom = nom;
    this.x = x;
    this.y = y;
  }

  /**
    * Constructeur par défaut
    */
  public PointCartesien(){
    this("DEFAUT", 1, 1);
  }

  /**
    * Constructeur par copie
    * @param ref qui est le PointPolaire copie
    */
  public PointCartesien(PointCartesien ref){
    this.nom = ref.nom;
    this.x = ref.x;
    this.y = ref.y;
  }

  /**
    * Modifie le nom du point
    * @param n le nouveau nom du point
    */
  public void setNom(String n){
    nom = n;
  }

  /**
    * Modifie l'abscisse du point
    * @param x la nouvelle abscisse du point
    */
  public void setX(double x){
    this.x = x;
  }

  /**
    * Modifie l'ordonnee du point
    * @param y la nouvelle abscisse du point
    */
  public void setY(double y){
    this.y = y;
  }

  /**
    * Recupere le nom du point
    * @return le nom du point
    */
  public String getNom(){
    return nom;
  }

  /**
    * Recupere l'abscisse du point
    * @return l'abscisse du point
    */
  public double getX(){
    return x;
  }

  /**
    * Recupere l'ordonnee du point
    * @return l'ordonnee du point
    */
  public double getY(){
    return y;
  }

  /**
    * Recupere l'angle en l'abscisse et la distance a l'origine du point
    * @return l'angle en question
    */
  public double getAngle(){
    return Math.acos(this.x/this.distanceALOrigine());
  }

  /**
    * Calcule la distance entre l'origine et le point
    * @return la distance entre l'origine et le point
    */
  public double distanceALOrigine(){
    return Math.sqrt(x*x + y*y);
  }

  /**
    * Effectue une translation sur le point suivant le vecteur (dx,dy)
    * @param dx coordonnee x du vecteur
    * @param dy coordonnee y du vecteur
    */
  public void translation(double dx, double dy){
    this.x += dx;
    this.y += dy;
  }

  /**
    * Chaine de caracteres qui decrie le point
    * @return la description du point
    */
  public String toString(){
    return nom + "(" + x + "," + y + ")";
  }

  /**
    * Permet d'afficher le point a l'ecran
    */
  public void afficher(){
    System.out.println(this);
  }
}
