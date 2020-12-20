package Voiture;

import Moteur.CARBURATION;
import Moteur.Moteur;

public class TestVoiture {

	public static void main(String[] args) {
		Moteur m0 = new Moteur(CARBURATION.ESSENCE, 100);
		Moteur m1 = new Moteur(CARBURATION.DIESEL, 50);
		Moteur m2 = new Moteur(CARBURATION.GPL, 25);
		Moteur m3 = new Moteur(CARBURATION.HYBRIDE, 150);
		Moteur m4 = new Moteur(m1);
		Moteur[] moteurs = new Moteur[] {m0, m1, m2, m3, m4};
		
		Modele mod0 = new Modele("C1");
		Modele mod1 = new Modele("Megane");
		Modele mod2 = new Modele("C3");
		Modele mod3 = new Modele("C3 Picaso");
		Modele mod4 = new Modele("Turbo");
		Modele[] modeles = new Modele[] {mod0, mod1, mod2, mod3, mod4};
		
		Option opt0 = new Option("radio digitale", true);
		Option opt1 = new Option("caméra de recul", true);
		Option opt2 = new Option("tablette tactile à l'avant", true);
		Option opt3 = new Option("assistance au maintien de voie", true);
		Option opt4 = new Option("avertissement de collision", true);
		Option opt5 = new Option("air bags avant", true);
		Option opt6 = new Option("air bags latéraux", true);
		Option opt7 = new Option("vitres electriques", true);
		Option opt8 = new Option("toit ouvrant", true);
		Option opt9 = new Option("alarme intégrée", true);
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
		Voiture[] voitures = new Voiture[] {v0, v1, v2, v3, v4, v5};		
		
		//toString des objets
		System.out.println("\nMoteurs : ");
		for(int i = 0; i < moteurs.length; i++) {
			System.out.println("m" + i + " : " + moteurs[i].toString());
		}
		System.out.println("\nModeles : ");
		for(int i = 0; i < modeles.length; i++) {
			System.out.println("mod" + i + " : " + modeles[i].toString());
		}
		System.out.println("\nOptions : ");
		for(int i = 0; i < options1.length; i++) {
			System.out.println("opt" + i + " : " + options1[i].toString());
		}
		System.out.println("\nVoitures : ");
		for(int i = 0; i < voitures.length; i++) {
			System.out.println("v" + i + " : " + voitures[i].toString());
		}
		
		v0.setCouleur(COULEUR.VIOLET);
		System.out.println("v0 : " + v0.toString());
		
	}

}
