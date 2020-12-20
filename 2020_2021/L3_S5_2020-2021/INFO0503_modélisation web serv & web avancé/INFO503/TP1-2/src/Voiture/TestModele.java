package Voiture;

public class TestModele {

	public static void main(String[] args) {
		Modele mod1 = new Modele("C1");
		Modele mod2 = new Modele("Megane");
		Modele mod3 = new Modele("C3");
		Modele mod4 = new Modele("C3 Picaso");
		Modele mod5 = new Modele("Turbo");
		Modele[] modeles = new Modele[] {mod1, mod2, mod3, mod4, mod5};
		
		System.out.println("\nModeles : ");
		for(int i = 0; i < 5; i++) {
			System.out.println("opt" + i + " : " + modeles[i].getModele());
		}
		System.out.println("\nModeles : ");
		for(int i = 0; i < 5; i++) {
			System.out.println("opt" + i + " : " + modeles[i].toString());
		}

	}

}
