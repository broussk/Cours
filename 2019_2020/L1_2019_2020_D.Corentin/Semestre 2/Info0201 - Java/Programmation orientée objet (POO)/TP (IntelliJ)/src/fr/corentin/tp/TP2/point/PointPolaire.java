package fr.corentin.tp.TP2.point;

/**
  * Classe PointPolaire qui implémente l'interface IPoint.
  * @author DUPONT Corentin et LACROIX Owen
  * @version 03/02/2020
  */

public class PointPolaire implements IPoint {

  /**
    * Attributs caracterisant le PointPolaire
    */
  private String nom;
  private double dist;
  private double angle;

  /**
    * Constructeur par initialisation
    * @param nom qui est le nom du point
    * @param dist distance du point
    * @param angle angle du point
    */
  public PointPolaire(String nom, double dist, double angle){
    this.nom = nom;
    this.dist = dist;
    this.angle = angle;
  }

  /**
    * Constructeur par défaut
    */
  public PointPolaire(){
    this("DEFAUT", 2, 90);
  }

  /**
    * Constructeur par copie
    * @param ref qui est le PointPolaire copie
    */
  public PointPolaire(PointPolaire ref){
    this.nom = ref.nom;
    this.dist = ref.dist;
    this.angle = ref.angle;
  }

  /**
    * Modifie le nom du point
    * @param n le nouveau nom du point
    */
  public void setNom(String n){
    nom = n;
  }

  /**
    * Modifie la distance du point
    * @param dist la nouvelle distance du point
    */
  public void setX(double dist){
    this.dist= dist;
  }

  /**
    * Modifie l'angle du point
    * @param angle le nouvelle angle du point
    */
  public void setY(double angle){
    this.angle = angle;
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
    return dist*Math.cos(angle);
  }

  /**
    * Recupere l'ordonnee du point
    * @return l'ordonnee du point
    */
  public double getY(){
    return dist*Math.sin(angle);
  }

  /**
    * Recupere l'angle en l'abscisse et la distance a l'origine du point
    * @return l'angle en question
    */
  public double getAngle(){
    return Math.acos(this.getX()/this.distanceALOrigine());
  }

  /**
    * Calcule la distance entre l'origine et le point
    * @return la distance entre l'origine et le point
    */
  public double distanceALOrigine(){
    return Math.sqrt(getX()*getX() + getY()*getY());
  }

  /**
    * Effectue une translation sur le point suivant le vecteur (dx,dy)
    * @param dx coordonnee x du vecteur
    * @param dy coordonnee y du vecteur
    */
    public void translation(double dx, double dy){
        double tempx = dx + getX();
        double tempy = dy + getY();
        this.dist = Math.sqrt(tempx*tempx + tempy*tempy);
        this.angle = Math.acos(tempx/dist);
      }

  /**
    * Chaine de caracteres qui decrie le point
    * @return la description du point
    */
  public String toString(){
    return nom + "(" + getX() + "," + getY() + ")";
  }

  /**
    * Permet d'afficher le point a l'ecran
    */
  public void afficher(){
    System.out.println(this);
  }
}
