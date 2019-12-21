package astronomie;
public class Satellite extends AAstre implements ISatellite{
	private AAstre astre;
	private double distance;
	private double vitesseRevolution;
	
	//constructeurs
	public Satellite(String n, double m, double d, double vR, AAstre ast, double dis, double viR){
		super(n, m, d, vR);
		astre=ast;
		distance=dis;
		vitesseRevolution=viR;
	}
	
	//methodes
	/**
     * Retourne l'astre de reference
     * @return l'astre de reference
     */
    public AAstre getAstreReference(){return astre;}

    /**
     * Retourne la distance par rapport a l'astre de reference
     * @return la distance par rapport a l'astre de reference
     */
    public double getDistance(){return distance;}

    /**
     * Retourne la vitesse de revolution autour de l'astre de reference
     * @return la vitesse de revolution
     */
    public double getVitesseRevolution(){return vitesseRevolution;}

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Lune, satellite de Terre, planete autour de Soleil
     * @return une chaine de caracteres
     */
    public String toString(){
    	return (this.getNom()+", satellite de "+this.Planete.toString());
    }
}
