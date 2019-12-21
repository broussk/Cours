public class Senseo implements IDistributeur{
	private int dosettesS;
	private int maxDosetteS;
	private double capaciteS;
	private double cagnotteS;
	private static double prixCafeCourtS=0.20;
	private static double prixCafeLongS=0.50;
	
	//constructeur par initialisation
	public Senseo(int maxDosette, double capacite){
		this.maxDosetteS=maxDosette;
		dosettesS=maxDosette;
		this.capaciteS=capacite;
		this.cagnotteS=0;
	}
	//constructeur par defaut
	public Senseo(){
		maxDosetteS=1;
		dosettesS=1;
		capaciteS=1;
		cagnotteS=0;
	}
	//constructeur par copie
	public Senseo(Senseo ref){
		this.maxDosetteS=ref.maxDosetteS;
		this.dosettesS=ref.dosettesS;
		this.capaciteS=ref.capaciteS;
		this.cagnotteS=ref.cagnotteS;
	}
	//getters
	public int getDosettes(){return dosettesS;}
	public int getMaxDosette(){return maxDosetteS;}
	public double getCapacite(){return capaciteS;}
	public double getCagnotte(){return cagnotteS;}
	public static double getPrixCafeCourt(){return prixCafeCourtS;}
	public static double getPrixCafeLong(){return prixCafeLongS;}
	//setters
	public static void setPrixCafeCourt(double prix){prixCafeCourtS=prix;}
	public static void setPrixCafeLong(double prix){prixCafeLongS=prix;}
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
	 	return ("La machine a une capacite de "+this.maxDosetteS+" dosettes, a "+this.dosettesS+" dosettes en stock, avec une capacite de "+this.capaciteS+" L d'eau, et a "+this.cagnotteS+" euros dans la cagnotte.");
	 }
	/**
     * Permet de boire un caf&eacute; court.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
	 public double boireCafeCourt(double montant){
	 	if(this.capaciteS>=0.10 && this.dosettesS>=1){
		 	this.capaciteS-=0.10;
		 	this.dosettesS--;
		}
	 	return montant;
	 }
	/**
     * Permet de boire un caf&eacute; long.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
     public double boireCafeLong(double montant){
	 	if(this.capaciteS>=0.25 && this.dosettesS>=1){
		 	this.capaciteS-=0.25;
		 	this.dosettesS--;
		}
	 	return montant;
     }
     /**
      *Change le prix des cafes
      *@param augmentation en pourcentage
      */
      public static void augmenter(double augmentation){
      	prixCafeCourtS=(1+augmentation)*prixCafeCourtS;
      	prixCafeLongS=(1+augmentation)*prixCafeLongS;
      }
     /**
      * Rempli le reservoir du distributeur courant
      * @param quantite la quantit&eacute; d'eau &agrave; ajouter
      */
     public void remplirReservoir(double quantite){
     	this.capaciteS+=quantite;
     }
     /**
     * Ajoute des dosettes dans le distributeur.
     * @param nbDosettes le nombre de dosettes &agrave; ajouter
     */
    public void ajouterDosettes(int nbDosettes){
    	if (this.dosettesS+nbDosettes>this.maxDosetteS) {
    		this.dosettesS=this.maxDosetteS;
    	}
    	else{
    		this.dosettesS+=nbDosettes;
    	}
    }
}

