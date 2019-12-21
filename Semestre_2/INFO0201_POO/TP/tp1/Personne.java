public class Personne{
	private String nom;
	private String prenom;
	private String civilite;
	private int age;
	private double poids;
	private int taille;
	
	//constructeur par initialisation
	public Personne(String n, String p, String c, int a, double po,int t){
		nom=n;
		prenom=p;
		civilite=c;
		if(a>=0&&a<150)age=a; else age=0;
		if(po>0)poids=po; else poids=1;
		if(t>0&&t<300)taille=t; else taille=1;
	}
	//constructeur par défaut
	public Personne(){
		nom="";
		prenom="";
		civilite="";
		age=0;
		poids=0;
		taille=0;
	}
	
	//getters
	public String getNom(){return nom;}
	public String getPrenom(){return prenom;}
	public String getCivilite(){return civilite;}
	public int getAge(){return age;}
	public double getPoids(){return poids;}
	public int getTaille(){return taille;}
	
	//setters
	//public void setNom(String nom){this.nom=nom;}
	//public void setPrenom(String prenom){this.prenom=prenom;}
	public void setCivilite(String civilite){this.civilite=civilite;}
	public void setAge(int age){this.age=age;}
	public void setPoids(double poids){this.poids=poids;}
	public void setTaille(int taille){this.taille=taille;}

	//méthodes
	/**
	 * regarde comment ecrire la taille et enleve la centaine
	 * créer une chaine de caractere pour la description de l'objet
	 * ajoute la centaine enlevee avant la creation de la chaine 
	 * @return une chaine de caracteres
	 */
	public String toString(){
		String rep="", tailles="";

		if (this.taille<100) {
			tailles="ans, 0m";
		}
		else{
			if (this.taille>200) {
				tailles="ans, 2m";
				this.taille-=200;
			}
			else{
				tailles="ans, 1m";
				this.taille-=100;
			}
		}

		if (this.civilite.equals("monsieur")) {
			rep=("M. "+this.prenom+" "+this.nom.toUpperCase()+" : "+this.age+tailles+this.taille+", "+this.poids+"kg.");
		}
		else{
			if (this.civilite.equals("madame")) {
				rep=("Mme. "+this.prenom+" "+this.nom.toUpperCase()+" : "+this.age+tailles+this.taille+", "+this.poids+"kg.");
			}
			else{
				if (this.civilite.equals("mademoiselle")) {
					rep=("Mlle. "+this.prenom+" "+this.nom.toUpperCase()+" : "+this.age+tailles+this.taille+", "+this.poids+"kg.");
				}
				else{
					rep=("Mauvaise civilite !");
				}
			}
		}

		if (tailles.equals("ans, 2m")) {
			this.taille+=200;
		}
		else{
			if (tailles.equals("ans, 1m")) {
				this.taille+=100;
			}
		}
		return rep;
	}

	/**
	 * affiche une chaine de caractere
	 */
	public void afficher(){System.out.println(toString());}

	/**
	 * calcul l'IMC d'une personne
	 * @return resultat du cacul de l'IMC
	 */
	public double IMC(){
		double imc, tail=this.taille, poids=this.poids;
		tail=tail/100;
		imc=poids/(tail*tail);
		imc=(double) Math.round(imc * 100) / 100;
		return imc;
	}

	/**
	 * interprete les resultats de l'IMC en fonction de celui-ci
	 * @param imc - imc d'une personne
	 * @return une chaine de caracteres
	 */
	public String interpreterIMC(double imc){
		String interIMC="";
		if (imc<16.5) {
			interIMC="denutrition";
		}
		else{
			if (imc>=16.5 && imc <18.5) {
				interIMC="maigreur";
			}
			else{
				if (imc>=18.5 && imc<25) {
					interIMC="corpulance normale";
				}
				else{
					if (imc>=25 && imc<30) {
						interIMC="surpoids";
					}
					else{
						if (imc>=30 && imc<35) {
							interIMC="obesite moderee";
						}
						else{
							if (imc>=35 && imc<40) {
								interIMC="obesite severe";
							}
							else{
								interIMC="obesite morbide";
							}
						}
					}
				}
			}
		}
		return interIMC;
	}
}