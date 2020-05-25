/**
 * Classe <b>PointCartesien</b> impl&eacute;ment&eacute;e par l'iterface <b>IPoint</b>	
 * @author Nathan Tonnelle
 * @version 31/01/2019
 */
public class PointCartesien implements IPoint{
	private double x; 
	private double y;
	private double distance;
	
	//constructeur par initialisation
	public PointCartesien(double x, double y){
		this.x=x;
		this.y=y;
	}
	
	//constructeur par défaut
	public PointCartesien(){
		x=1;
		y=1;
	}
	
	//constructeur par copie
	public PointCartesien(PointCartesien ref){
		this.x=ref.x;
		this.y=ref.y;
	}
	
	//getters
	public double getX(){return this.x;}
	public double getY(){return this.y;}
	
	//setters
	public void setX(double x){this.x=x;}
	public void setY(double y){this.y=y;}
	
	//méthodes
	/**
	 * cr&eacute;ation d'une chaine de caractere de description de l'objet
	 * @return String de description de l'objet
	 */
	public String toString(){
		return ("x: "+this.x+" y: "+y+" distance : "+this.distanceALOrigine());
	}
	/**
	 * affiche la description de l'objet
	 */
	public void afficher(){
		System.out.println(toString());
	}
	/**
	 * @return la distance entre l'origine et le point
	 */
	public double distanceALOrigine(){
		distance=Math.sqrt(this.x*this.x+this.y*this.y);
		return distance;
	};
 
    /**
     * Effectue une translation sur le point suivant le vecteur (dx,dy)
     * @param dx coordonn&eacute;e x du vecteur
     * @param dy coordonn&eacute;e y du vecteur
     */
    public void translation(double dx, double dy){
    	this.x+=dx;
    	this.y+=dy;
    };
}
