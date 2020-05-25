public class VoitureProfonde implements IVoiture{
	private Personne personne;
	private Moteur moteur;
	private Reservoir reservoir;
	
	//contructeur par initialisation
	public VoitureProfonde(Moteur m, Reservoir r){	
		this.moteur= new Moteur(m);
		this.reservoir= new Reservoir(r);
	}
	//constructeur par copie
	public VoitureProfonde(VoitureProfonde v){
		/*this.moteur=new Moteur(v.moteur);
		this.reservoir=new Reservoir(v.reservoir);*/
		moteur = new Moteur(v.getMoteur().getCarburation(),v.getMoteur().getConsommation());
		reservoir = new Reservoir(v.getReservoir().getCapacite());
	}
	
	//getters
	public Personne getPersonne(){return personne;}
	public Moteur getMoteur(){return moteur;}
	public Reservoir getReservoir(){return reservoir;}
	
	//méthode
	/**
	 * verifie que la personne est majeure
	 * si ce n'est pas le cas, le conducteur n'est pas ajoute
	 * @param p - la personne susceptible d'etre le conducteur
	 */
	public void setConducteur(Personne p){
		if(p.getAge()<18){
			System.out.println("Cette personne n'est pas un conducteur possible.");
		}
		else{
			this.personne=p;
		}
	}
	/**
	 * retourne description d'une voiture surface sous forme de chaine de caracteres
	 * @return une chaine de caracteres
	 */
	public String toString(){
		return ("La voiture est conduite par "+ this.getPersonne()+" le moteur : "+this.getMoteur()+" le reservoir : "+this.getReservoir());
	}
	/**
	 * affiche une chaine de caractere
	 */
	public void afficher(){
		System.out.println(this.toString());
	}
	/**
	 * fait avancer la voiture de la distance specifiee en parametre et retourne le nomde kilometres qui ont ete parcourus
	 * @param distance - la distance a parcourir
	 * @return le nombre de kilometres parcourus
	 */
	public double avancer(double distance){
		double nbKmParcourus=0;
		if(this.reservoir.getContenu()>=(this.moteur.getConsommation()*distance)){
			this.reservoir.vider(this.moteur.getConsommation()*distance);
			nbKmParcourus=distance;
		}
		else{
			nbKmParcourus=this.reservoir.getContenu()*this.moteur.getConsommation();
			this.reservoir.vider(this.reservoir.getContenu());
		}
		return nbKmParcourus;
	}
	/**
	 * refait le plein du reservoir de la voiture
	 * @return la quantite ajoutee dans le reservoir
	 */
	public double faireLePlein(){
		double quantite=this.reservoir.getContenu()+(this.reservoir.getCapacite()-this.reservoir.getContenu());
		this.reservoir.remplir(quantite);
		return quantite;
	}
	/**
	 * retourne le contenu du reservoir de la voiture
	 * @return le contenu du reservoir
	 */
	public double getContenuReservoir(){
		return this.reservoir.getContenu();
	}
}
