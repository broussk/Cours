package Usines;

import Moteur.CARBURATION;
import Moteur.Moteur;
import Voiture.COULEUR;
import Voiture.Modele;
import Voiture.Option;
import Voiture.Voiture;

public class TestUsine {

	public static void main(String[] args) {
		Moteur m0 = new Moteur(CARBURATION.ESSENCE, 100);
		Moteur m1 = new Moteur(CARBURATION.DIESEL, 50);
		Moteur m2 = new Moteur(CARBURATION.GPL, 25);
		Moteur m3 = new Moteur(CARBURATION.HYBRIDE, 150);
		Moteur m4 = new Moteur(m1);
		//Moteur[] moteurs = new Moteur[] {m0, m1, m2, m3, m4};
		
		Modele mod0 = new Modele("C1");
		Modele mod1 = new Modele("Megane");
		Modele mod2 = new Modele("C3");
		Modele mod3 = new Modele("C3 Picaso");
		Modele mod4 = new Modele("Turbo");
		//Modele[] modeles = new Modele[] {mod0, mod1, mod2, mod3, mod4};
		
		Option opt0 = new Option("radio digitale", true);
		Option opt1 = new Option("camera de recul", true);
		Option opt2 = new Option("tablette tactile a l'avant", true);
		Option opt3 = new Option("assistance au maintien de voie", true);
		Option opt4 = new Option("avertissement de collision", true);
		Option opt5 = new Option("air bags avant", true);
		Option opt6 = new Option("air bags lateraux", true);
		Option opt7 = new Option("vitres electriques", true);
		Option opt8 = new Option("toit ouvrant", true);
		Option opt9 = new Option("alarme integree", true);
		Option[] options1 = new Option[] {opt0,opt1,opt2,opt3,opt4,opt5,opt6,opt7,opt8,opt9};
		Option[] options2 = new Option[] {opt0,opt2,opt4,opt6,opt8};
		Option[] options3 = new Option[] {opt1,opt3,opt5,opt7,opt9};
		Option[] options4 = new Option[] {opt0,opt1,opt2,opt5,opt7,opt8,opt9};
		Option[] options5 = new Option[] {opt0,opt1,opt5,opt6,opt7,opt9};
		
		Voiture v0 = new Voiture(mod0, COULEUR.BLANC, m1, options2);
		Voiture v1 = new Voiture(mod1, COULEUR.BLEU_NUIT, m2, options3);
		Voiture v2 = new Voiture(mod2, COULEUR.JAUNE, m0, options4);
		Voiture v3 = new Voiture(mod3, COULEUR.NOIR, m4, options1);
		Voiture v4 = new Voiture(mod4, COULEUR.ROSE, m3, options5);
		Voiture v5 = new Voiture(v1);
		v5.setCouleur(COULEUR.VIOLET);
		//Voiture[] voitures = new Voiture[] {v0, v1, v2, v3, v4, v5};
		
		Place p1 = new Place('A', 1, v0);
		Place p2 = new Place('A', 2, v1);
		Place p3 = new Place('A', 3);
		Place p4 = new Place('A', 4);
		Place p5 = new Place('A', 5);
		Place p6 = new Place('B', 1, v2);
		Place p7 = new Place('B', 2);
		Place p8 = new Place('B', 3);
		Place p9 = new Place('B', 4);
		Place p10 = new Place('B', 5);
		Place p11 = new Place('C', 1, v3);
		Place p12 = new Place('C', 2);
		Place p13 = new Place('C', 3);
		Place p14 = new Place('C', 4);
		Place p15 = new Place('C', 5);
		Place p16 = new Place('D', 1, v4);
		Place p17 = new Place('D', 2);
		Place p18 = new Place('D', 3);
		Place p19 = new Place('D', 4);
		Place p20 = new Place('D', 5, v5);
		Place[] placesRangeeA = new Place[] {p1, p2, p3, p4, p5};
		Place[] placesRangeeB = new Place[] {p6, p7, p8, p9, p10};
		Place[] placesRangeeC = new Place[] {p11, p12, p13, p14, p15};
		Place[] placesRangeeD = new Place[] {p16, p17, p18, p19, p20};
		Place[] placesRangeeE = new Place[] {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
		Place[] placesRangeeF = new Place[] {p11, p12, p13, p14, p15, p16, p17, p18, p19, p20};

		Parking park0 = new Parking(placesRangeeA);
		Parking park1 = new Parking(placesRangeeB);
		Parking park2 = new Parking(placesRangeeC);
		Parking park3 = new Parking(placesRangeeD);
		Parking park4 = new Parking(placesRangeeE);
		Parking park5 = new Parking(placesRangeeF);
		Parking[] parkings0 = new Parking[] {park0, park2, park4};
		Parking[] parkings1 = new Parking[] {park1, park3, park5};
		
		Usine usine0 = new Usine("Papa Ours", park0);
		Usine usine1 = new Usine("Macroute", park1);
		Usine usine2 = new Usine("Telemac", park2);
		Usine usine3 = new Usine("Chat", park3);
		Usine usine4 = new Usine("Chocolatine", park4);
		Usine usine5 = new Usine("Raclette", park5);
		Usine usine6 = new Usine("banane", parkings0);
		Usine usine7 = new Usine("Lion", parkings1);
		//Usine[] usines0 = new Usine[] {usine0, usine2, usine4, usine6};
		//Usine[] usines1 = new Usine[] {usine1, usine3, usine5, usine7};
		
		System.out.println(usine0.toString());
		System.out.println(usine1.toString());
		System.out.println(usine2.toString());
		System.out.println(usine3.toString());
		System.out.println(usine4.toString());
		System.out.println(usine5.toString());
		System.out.println(usine6.toString());
		System.out.println(usine7.toString());
		
		usine0.setNom("Banana");
		System.out.println(usine0.toString());
		
		usine0.setParkings(parkings0);
		System.out.println(usine0.toString());
	}

}
