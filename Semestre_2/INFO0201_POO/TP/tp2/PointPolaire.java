/**
 * Classe <b>PointPolaire</b> impl&eacute;ment&eacute;e par l'iterface <b>IPoint</b>	
 * @author Nathan Tonnelle
 * @version 31/01/2019
 */
public class PointPolaire implements IPoint{
	private double x;
	private double y;
	private double angle;
	private double distance;
	
	//constructeurs par initialisation
	public PointPolaire(double x, double y){
		this.x=x;
		this.y=y;
	}
	
	//constructeurs par défaut
	public PointPolaire(){
		x=1;
		y=1;
	}
	
	//constructeurs par copie
	public PointPolaire(PointPolaire ref){
		this.x=ref.x;
		this.y=ref.y;
	}
	
	//getters
	public double getX(){return this.x;}
	public double getY(){return this.y;}
	public double getAngle(){return this.angle;}
	public double getDistance(){return this.distance;}
	
	//setters
	public void setX(double x){this.x=x;}
	public void setY(double y){this.y=y;}
	
	//méthodes
	/**
	 * cr&eacute;ation d'une chaine de caractere de description de l'objet
	 * @return String de description de l'objet
	 */
	public String toString(){
		return ("x: "+this.x+" y: "+this.y+" angle : "+this.angle()+" distance : "+this.distanceALOrigine());
	}
	/**
	 * affiche la description de l'objet
	 */
	public void afficher(){
		System.out.println(toString());
	}
	/**
	 * calcule l'angle entre l'axe des abscisses et le vecteur du point partant du point O
	 * @return le r&eacute;sultat du calcul de l'angle
	 */
	public double angle(){
		return 2*Math.atan(this.y/(x+this.distanceALOrigine()));
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
