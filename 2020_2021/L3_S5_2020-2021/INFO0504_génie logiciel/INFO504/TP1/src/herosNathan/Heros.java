package herosNathan;

public abstract class Heros {
		
	protected String nom;
	protected String type;
	protected int pointsDeVie;
	protected int pointsDeMagie;
	protected int experience;
	protected int niveau;
	protected int force;
	protected int intelligence;
	protected int dexterite;
	
	public Heros(String nom, String type, int pointsDeVie, int pointsDeMagie, int experience, int niveau, int force, int intelligence,
			int dexterite) {
		this.nom = nom;
		this.type = type;
		this.pointsDeVie = pointsDeVie;
		this.pointsDeMagie = pointsDeMagie;
		this.experience = experience;
		this.niveau = niveau;
		this.force = force;
		this.intelligence = intelligence;
		this.dexterite = dexterite;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}
	
	public String getType() {
		return type;
	}

	public int getPointsDeVie() {
		return pointsDeVie;
	}

	public void setPointsDeVie(int pointsDeVie) {
		this.pointsDeVie = pointsDeVie;
	}
	
	public void ajouterPointsDeVie(int montant) {
		this.pointsDeVie += montant;
	}
	
	public void soustrairePointsDeVie(int montant) {
		this.pointsDeVie -= montant;
	}

	public int getPointsDeMagie() {
		return pointsDeMagie;
	}

	public void setPointsDeMagie(int pointsDeMagie) {
		this.pointsDeMagie = pointsDeMagie;
	}

	public int getExperience() {
		return experience;
	}

	public void ajouterExperience(int experience) {
		this.experience += experience;
		if(this.experience %10 == 0) this.experience = 0;
	}

	public int getNiveau() {
		return niveau;
	}

	public void ajouterNiveau() {
		this.niveau++;
	}

	public int getForce() {
		return force;
	}

	public void setForce(int force) {
		this.force = force;
	}

	public int getIntelligence() {
		return intelligence;
	}

	public void setIntelligence(int magie) {
		this.intelligence = magie;
	}

	public int getDexterite() {
		return dexterite;
	}

	public void setDexterite(int dexterite) {
		this.dexterite = dexterite;
	}
	
	public String toString() {
		return ("nom : " + this.nom + ", " + this.type +" \n vie : " + this.pointsDeVie + "\n magie : " + this.pointsDeMagie + "\n Lvl : " + this.niveau + "\n exp : " + this.experience + "\n force : " + this.force + "\n intelligence : " + this.intelligence + "\n dexterité : " + this.dexterite);
	}

}
