package nathan.constructeur.Voiture.moteur;

public class testMoteur {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Moteur m1 = new Moteur(Carburation.DIESEL, 15);
		Moteur m2 = new Moteur(Carburation.ESSENCE, 20);
		Moteur m3 = new Moteur(Carburation.ESSENCE, 20);
		Moteur m4 = new Moteur(Carburation.ESSENCE, 10);
		Moteur m11 = new Moteur(m1);
		
		System.out.println("m1 : \n " + m1.toString());
		System.out.println("m2 : \n " + m2.toString());
		System.out.println("m11 : \n " + m11.toString());
		System.out.println("m3 : \n " + m3.toString());
		System.out.println("m4 : \n " + m4.toString());
	}

}
