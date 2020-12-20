package herosNathan;

public class Magicien extends Heros{

	private final static String TYPE = "Magicien";
	private final static int PV=100;
	private final static int PM=150;
	private final static int XP=0;
	private final static int LVL=1;
	private final static int FORCE=1;
	private final static int INTELLIGENCE=5;
	private final static int DEXTERITE=3;
	
	public Magicien(String nom) {
		super(nom, TYPE, PV, PM, XP, LVL, FORCE, INTELLIGENCE, DEXTERITE);
	}
	
	public void ajouterExperience(int experience) {
		super.ajouterExperience(experience);
		if(this.getExperience() %10 == 0) this.ajouterNiveau();
	}
	
	public void ajouterNiveau() {
		super.ajouterNiveau();
		this.setForce(this.getForce() + 1);
		this.setDexterite(this.getDexterite() + 2);
		this.setIntelligence(this.getIntelligence() + 3);
	}
	
	public String toString() {
		return super.toString();
	}

}
