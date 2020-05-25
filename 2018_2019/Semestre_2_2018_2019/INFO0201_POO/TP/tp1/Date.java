public class Date{
	private int jour;
	private int mois;
	private int annee;

	//contructeur par initialisation
	public Date(int j, int m, int a){
		if(j>=1&&j<=31)jour=j; else this.corrige();
		if(m>=1&&m<=12)mois=m; else this.corrige();
		if(a>=1)annee=a; else annee=1;
	}
	//constructeur par défaut
	public Date(){
		jour=01;
		mois=01;
		annee=01;	
	}

	//getters
	public int getJour(){return jour;}
	public int getMois(){return mois;}
	public int getAnnee(){return annee;}
	
	//setters
	public void setJour(int jour){this.jour=jour;}
	public void setMois(int mois){this.mois=mois;}
	public void setAnnee(int annee){this.annee=annee;}

	//méthodes
	/**
	 * retourne la date en chaine de caracteres
	 * @return chaine de caractere
	 */
	public String toString(){
		String chaine="";
		if(this.jour<10){
			if(this.mois<10) chaine=("0"+jour+"/0"+mois+"/"+annee);
			else chaine=("0"+jour+"/"+mois+"/"+annee);
		}
		else chaine=(jour+"/"+mois+"/"+annee);
		return chaine;
	}

	/**
	 * affiche une chaine de caractere
	 */
	public void afficher(){
		if(this.estValide()){System.out.println(toString());}
		else{corrige();System.out.println(toString());}
	}

	/**
	 * regarde si l'annee est bissextile ou non
	 * @return boolean si l'annee est bissextile ou non
	 */
	public boolean estBissextile(){
		boolean rep=false;
		if(this.annee%4==0){
			if(this.annee%100!=0){
				rep=true;
			}
		}
		return rep;
	}

	/**
	 * regarde combien il y a de jours dans le mois
	 * @return le nombre de jours dans le mois
	 */
	public int compteJours(){
		int nbJours=31;
		switch(this.mois){
			case 1: nbJours=31;
			break;
			case 2: if(this.estBissextile()){nbJours=29;}else{nbJours=28;}
			break;
			case 3: nbJours=31;
			break;
			case 4: nbJours=30;
			break;
			case 5: nbJours=31;
			break;
			case 6: nbJours=30;
			break;
			case 7: nbJours=31;
			break;
			case 8: nbJours=31;
			break;
			case 9: nbJours=30;
			break;
			case 10: nbJours=31;
			break;
			case 11: nbJours=30;
			break;
			case 12: nbJours=31;
			break;
		}
		return nbJours;
	}

	/**
	 * regarde si la date est valide ou non
	 * @return un boolean si la date est valide ou pas
	 */
	public boolean estValide(){
		boolean valide=false;
		if(this.jour<=this.compteJours()&&this.mois<=12){valide=true;}
		return valide;
	}

	/**
	 * corrige le nombre de jours et de mois si ils sont faux
	 */
	private void corrige(){
		if(this.mois>12){this.mois=1;}
		if(this.jour>compteJours()){this.jour=1;}
	}
}
