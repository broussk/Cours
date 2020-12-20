package Moteur;

public class TestMoteur {

	public static void main(String[] args) {
		Moteur m1 = new Moteur(CARBURATION.ESSENCE, 100);
		Moteur m2 = new Moteur(CARBURATION.DIESEL, 50);
		Moteur m3 = new Moteur(CARBURATION.GPL, 25);
		Moteur m4 = new Moteur(CARBURATION.HYBRIDE, 150);
		Moteur m11 = new Moteur(m1);
		Moteur[] moteurs = new Moteur[] {m1, m2, m3, m4, m11};
		
		System.out.print("\nMoteur : id : \n\t ");
		for(int i = 0; i < 5; i++) {
			System.out.print("m" + i + " : " + moteurs[i].getIdMoteur() + "\t ");
		}
		System.out.print("\nMoteur : puissance : \n\t ");
		for(int i = 0; i < 5; i++) {
			System.out.print("m" + i + " : " + moteurs[i].getPuissance() + "\t ");
		}
		System.out.print("\nMoteur : carburation : \n\t ");
		for(int i = 0; i < 5; i++) {
			System.out.print("m" + i + " : " + moteurs[i].getCarburation() + "\t ");
		}
		System.out.println("\n\nMoteurs : ");
		for(int i = 0; i < 5; i++) {
			System.out.println(" m" + i + " : " + moteurs[i].toString());
		}
	}

}
