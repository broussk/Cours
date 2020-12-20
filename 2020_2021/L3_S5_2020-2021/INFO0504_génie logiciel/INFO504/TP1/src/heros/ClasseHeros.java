package heros;

public class ClasseHeros {

	private String nom;
	private String type; 
	private int pointsDeVie;
	private int pointsDeMagie;
	private int experience;
	private int niveau;
	private int force;
	private int magie;
	private int dexterite;

	public ClasseHeros(String nom, String type, int pointsDeVie, int pointsDeMagie, int experience, int niveau,
			int force, int magie, int dexterite) {
		this.nom = nom;
		this.type = type;
		this.pointsDeVie = pointsDeVie;
		this.pointsDeMagie = pointsDeMagie;
		this.experience = experience;
		this.niveau = niveau;
		this.force = force;
		this.magie = magie;
		this.dexterite = dexterite;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(char nom) {
		this.nom = Character.toString(nom);
	}

	public String getType() {
		return type;
	}

	public int getPointsDeVie() {
		return pointsDeVie;
	}

	public int getPointsDeMagie() {
		return pointsDeMagie;
	}

	public int getExperience() {
		return experience;
	}

	public int getForce() {
		return force;
	}

	public int getMagie() {
		return magie;
	}

	public int getDexterite() {
		return dexterite;
	}
	
	public void ajouterPointsDeVie(int montant) {
		this.pointsDeVie += montant;
	}
	
	public void soustrairePointsDeVie(int montant) {
		this.pointsDeVie -=montant;
	}
	
	public void ajouterExperience(int montant) {
		this.experience += montant;
	}
	
	public void ajouterUnNiveau() {
		this.niveau++;
	}
	
	public String toString() {
		return (this.nom + " de type " + this.type + " :\n vie : " + this.pointsDeVie + "\n magie : " + this.pointsDeMagie + "\n Lvl : " + this.niveau + "\n exp : " + this.experience + "\n force : " + this.force + "\n magie : " + this.magie + "\n dexterité : " + this.dexterite);
	}
}
