public class DistributeurCafe implements IDistributeur{
	private int dosettes;
	private int maxDosette;
	private double capacite;
	private double cagnotte;
	private static double prixCafeCourt=0.20;
	private static double prixCafeLong=0.50;
	
	//constructeur par initialisation
	public DistributeurCafe(int maxDosette, double capacite){
		this.maxDosette=maxDosette;
		dosettes=maxDosette;
		this.capacite=capacite;
		this.cagnotte=0;
	}
	//constructeur par defaut
	public DistributeurCafe(){
		maxDosette=10;
		dosettes=10;
		capacite=2;
		cagnotte=0;
	}
	//constructeur par copie
	public DistributeurCafe(DistributeurCafe ref){
		this.maxDosette=ref.maxDosette;
		this.dosettes=ref.dosettes;
		this.capacite=ref.capacite;
		this.cagnotte=ref.cagnotte;
	}
	//getters
	public int getDosettes(){return dosettes;}
	public int getMaxDosette(){return maxDosette;}
	public double getCapacite(){return capacite;}
	public double getCagnotte(){return cagnotte;}
	public static double getPrixCafeCourt(){return prixCafeCourt;}
	public static double getPrixCafeLong(){return prixCafeLong;}
	//setters
	public static void setPrixCafeCourt(double prix){prixCafeCourt=prix;}
	public static void setPrixCafeLong(double prix){prixCafeLong=prix;}
	//methodes
	/**
	 *affiche une chaine de caractere decrivant le machine
	 */
	public void afficher(){
		System.out.println(this.toString());
	}
	/**
	 *retourne une chaine de caractere decrivant une machine
	 *@return chaine de caratere decrivant une machine
	 */
	 public String toString(){
	 	return ("La machine a une capacite de "+this.maxDosette+" dosettes, a "+this.dosettes+" dosettes en stock, avec une capacite de "+this.capacite+" L d'eau, et a "+this.cagnotte+" euros dans la cagnotte.");
	 }
	/**
     * Permet de boire un caf&eacute; court.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
	 public double boireCafeCourt(double montant){
	 	double reste=montant;
	 	if(this.capacite>=0.10 && this.dosettes>=1){
		 	this.capacite-=0.10;
		 	this.dosettes--;
		 	this.cagnotte+=prixCafeCourt;
		 	reste=montant-prixCafeCourt;
		}
	 	return reste;
	 }
	/**
     * Permet de boire un caf&eacute; long.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
     public double boireCafeLong(double montant){
     	double reste=montant;
	 	if(this.capacite>=0.25 && this.dosettes>=1){
		 	this.capacite-=0.25;
		 	this.dosettes--;
		 	this.cagnotte+=prixCafeLong;
		 	reste=montant-prixCafeLong;
		}
	 	return reste;
     }
     /**
      *Change le prix des cafes
      *@param augmentation en pourcentage
      */
      public static void augmenter(double augmentation){
      	prixCafeCourt=(1+augmentation)*prixCafeCourt;
      	prixCafeLong=(1+augmentation)*prixCafeLong;
      }
     /**
      * Rempli le reservoir du distributeur courant
      * @param quantite la quantit&eacute; d'eau &agrave; ajouter
      */
     public void remplirReservoir(double quantite){
     	this.capacite+=quantite;
     }
     /**
     * Ajoute des dosettes dans le distributeur.
     * @param nbDosettes le nombre de dosettes &agrave; ajouter
     */
    public void ajouterDosettes(int nbDosettes){
    	if (this.dosettes+nbDosettes>this.maxDosette) {
    		this.dosettes=this.maxDosette;
    	}
    	else{
    		this.dosettes+=nbDosettes;
    	}
    }
}
