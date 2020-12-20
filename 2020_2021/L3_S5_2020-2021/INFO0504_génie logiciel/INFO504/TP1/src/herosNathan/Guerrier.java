package herosNathan;

public class Guerrier extends Heros{
	
	private final static String TYPE = "Guerrier";
	private final static int PV=100;
	private final static int PM=50;
	private final static int XP=0;
	private final static int LVL=1;
	private final static int FORCE=5;
	private final static int INTELLIGENCE=1;
	private final static int DEXTERITE=3;

	public Guerrier(String nom) {
		super(nom, TYPE, PV, PM, XP, LVL, FORCE, INTELLIGENCE, DEXTERITE);
	}
	
	public void ajouterExperience(int experience) {
		super.ajouterExperience(experience);
		if(this.getExperience() %10 == 0) this.ajouterNiveau();
	}
	
	public void ajouterNiveau() {
		super.ajouterNiveau();
		this.setForce(this.getForce() + 3);
		this.setDexterite(this.getDexterite() + 2);
		this.setIntelligence(this.getIntelligence() + 1);
	}
	
	public String toString() {
		return super.toString();
	}
}
