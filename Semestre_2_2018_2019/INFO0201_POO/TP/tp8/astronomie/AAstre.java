package astronomie;
import java.util.Vector;
public abstract class AAstre implements IAstre{
	private String nom;
	private double masse;
	private double diametre;
	private double vitesseRotation;
	private int nombreSatellites;
	private Vector<Satellite> satellites;
	
	//constructeur par initialisation
	public AAstre(String n, double m, double d, double vR){
		satellites = new Vector<Satellite>();
		nom=n;
		masse=m;
		diametre=d;
		vitesseRotation=vR;
	}
	/*public AAstre(){
		satellites = new Vector<Satellite>();
		nom="Soleil";
		masse=1989100x10^24;
		diametre=1392000;
		vitesseRotation =576.0;
	}*/
	
	//methodes
	/**
     * Retourne le nom de l'astre
     * @return le nom de l'astre
     */
    public String getNom(){return nom;}

    /**
     * Retourne la masse de l'astre
     * @return la masse de l'astre
     */
    public double getMasse(){return masse;}

    /**
     * Retourne le diametre de l'astre
     * @return le diametre de l'astre
     */
    public double getDiametre(){return diametre;}

    /**
     * Retourne la vitesse de rotation
     * @return la vitesse de rotation
     */
    public double getVitesseRotation(){return vitesseRotation;}

    /**
     * Retourne le nombre de satellites
     * @return le nombre de satellites
     */
    public int getNombreSatellites(){return nombreSatellites;}

    /**
     * Retourne le satellite numero n de l'astre
     * @param n le numero du satellite
     * @return le satellite numero n ou null en cas d'erreur
     */
    public Satellite getSatellite(int n){return satellites.get(n);}

    /**
     * Ajoute un nouveau satellite
     * @param s le nouveau satellite
     */
    public void ajouterSatellite(Satellite s){
    	nombreSatellites++;
    	satellites.add(s);
    }

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Soleil
     * @return une chaine de caracteres
     */
    public String toString(){
    	return ("Nom      = "+nom);
    }

    /**
     * Affiche a l'ecran toutes les informations sur l'astre
     * Exemple d'affichage :
     * Nom      = Soleil
     * Masse    = 1989100x10^24 kg
     * Diametre = 1392000 km
     * Rotation = 576.0 j
     */
    public void afficher(){
    	System.out.println(this.toString());
    	System.out.println("Masse     = "+masse+" kg \n Diametre = "+diametre+" km \n Rotation = "+vitesseRotation+" j");
    }
}
