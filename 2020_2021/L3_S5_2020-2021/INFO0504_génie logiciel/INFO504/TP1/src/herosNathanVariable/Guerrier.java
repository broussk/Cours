package herosNathanVariable;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Guerrier extends Heros{
	
	private final static String TYPE = "Guerrier";
	private final static int PV=100;
	private final static int PM=50;
	private final static int XP=0;
	private final static int LVL=1;
	private final static int FORCE=lireCarac(1);
	private final static int INTELLIGENCE=lireCarac(2);
	private final static int DEXTERITE=lireCarac(3);

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
	
	private static int lireCarac(int caseLine){
		String line = new File("src/herosNathanVariable/caracteristiques.txt").getAbsolutePath().replace("\\", "/");
	    //BufferedReader in = new BufferedReader(new FileReader("C:/Users/tonne/Desktop/L3-TP/INFO504/TP1/src/herosNathanVariable/caracteristiques.txt"));
		BufferedReader buffReader = null;
		try {
			buffReader = new BufferedReader(new FileReader(line));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("buffReader = new BufferedReader(new FileReader(line)); echec");
		}

		try {
			while ((line = buffReader.readLine()) != null)
			{
				//System.out.println (line + "\n");
				String lines[] = line.replace(';', ' ').split(" ");
				for(int i=0; i<lines.length; i++) {
					//System.out.println(lines[i]);
					if(lines[i].equalsIgnoreCase("guerrier")) {
						return (Character.getNumericValue(lines[caseLine].charAt(0)));
					}
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("while ((line = buffReader.readLine()) != null) echec");
		}
		try {
			buffReader.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("buffReader.close() echec");
		}
		return 0;
	}
}
