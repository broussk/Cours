package astronomie;
public class Planete extends Satellite implements IPlanete{
	private Etoile etoile;
	
	//constructeur
	public Planete(String n, double m, double d, double vR, Etoile e, double dis, double viR){
		super(n, m, d, vR, e, d, viR);
		etoile=e;
	}
	//methodes
	/**
     * Retourne le type de la planete : tellurique ou gazeuse
     * @return le type de la planete
     */
    public String getType(){}

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Terre, planete autour de Soleil
     * @return une chaine de caracteres
     */
    public String toString(){
    	return (this.getNom()+", planete autour de "+etoile.getNom());
    }
}
