public class Toutou{
	private String nom;
	private int puces;
	
	//constructeur par initialisation
	public Toutou(String n, int p){
		nom=n;
		if(nom.equals("")||nom==null) throw new IllegalArgumentException("Le nom du toutou est null");
		puces=p;
		if(puces<0) throw new IllegalArgumentException("Le nombre de puces est negatif");
	}
	//constructeur par défaut
	public Toutou(){
		nom="Chien";
		puces=0;
	}
	//getters
	public String getNom(){return this.nom;}
	public int getPuces(){return this.puces;}
	//setters
	public void setPuces(int p){
		this.puces =p;
		if(this.puces<0) throw new IllegalArgumentException("Le nombre de puces est negatif");
	}
	/**
	 *revoie une chaine de caractere decrivant le toutou
	 *@return String decrivant le toutou
	 */
	//méthodes
	public String toString(){
		return ("Le chien "+this.nom+" a "+this.puces+" puces.");
	}
	/**
	 *test si un toutou est egal a un autre
	 *@param ref - toutou de reference
	 *@return true si les deux toutou sont egaux sinon, @return false
	 */
	public boolean egalA(Toutou ref){
		boolean rep=false;
		if(this.nom.equals(ref.nom)){
			if(this.puces==ref.puces){
				rep=true;
			}
		}
		return rep;
	}
}
