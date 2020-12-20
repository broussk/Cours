import Moteur.CARBURATION;
import Moteur.Moteur;
//import Usines.Parking;
//import Usines.Place;
//import Usines.Usine;
import Voiture.COULEUR;
import Voiture.Modele;
import Voiture.Option;
import Voiture.Voiture;
//import constructeurAuto.Catalogue;
//import constructeurAuto.Constructeur;
//import constructeurAuto.Stock;

public class TestAllProject {

	public static void main(String[] args) {
		Moteur m0 = new Moteur(CARBURATION.ESSENCE, 100);
		Moteur m1 = new Moteur(CARBURATION.DIESEL, 50);
		Moteur m2 = new Moteur(CARBURATION.GPL, 25);
		Moteur m3 = new Moteur(CARBURATION.HYBRIDE, 150);
		Moteur m4 = new Moteur(m1);
		//Moteur[] moteurALL = new Moteur[] {m0, m1, m2, m3, m4};
		
		Modele mod0 = new Modele("C1");
		Modele mod1 = new Modele("Megane");
		Modele mod2 = new Modele("C3");
		Modele mod3 = new Modele("C3 Picaso");
		Modele mod4 = new Modele("Turbo");
		//Modele[] modeleALL = new Modele[] {mod0, mod1, mod2, mod3, mod4};
		
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
		//Option[] optionsALL = new Option[] {opt0,opt1,opt2,opt3,opt4,opt5,opt6,opt7,opt8,opt9};
		
		Voiture v0 = new Voiture(mod0, COULEUR.BLANC, m1, options2);
		Voiture v1 = new Voiture(mod1, COULEUR.BLEU_NUIT, m2, options3);
		Voiture v2 = new Voiture(mod2, COULEUR.JAUNE, m0, options4);
		Voiture v3 = new Voiture(mod3, COULEUR.NOIR, m4, options1);
		Voiture v4 = new Voiture(mod4, COULEUR.ROSE, m3, options5);
		Voiture v5 = new Voiture(v1);
		v5.setCouleur(COULEUR.VIOLET);
		Voiture[] voituresALL = new Voiture[] {v0, v1, v2, v3, v4, v5};
		
		//Place p1 = new Place('A', 1, v0);
		//Place p2 = new Place('A', 2, v1);
		//Place p3 = new Place('A', 3);
		//Place p4 = new Place('A', 4);
		//Place p5 = new Place('A', 5);
		//Place p6 = new Place('B', 1, v2);
		//Place p7 = new Place('B', 2);
		//Place p8 = new Place('B', 3);
		//Place p9 = new Place('B', 4);
		//Place p10 = new Place('B', 5);
		//Place p11 = new Place('C', 1, v3);
		//Place p12 = new Place('C', 2);
		//Place p13 = new Place('C', 3);
		//Place p14 = new Place('C', 4);
		//Place p15 = new Place('C', 5);
		//Place p16 = new Place('D', 1, v4);
		//Place p17 = new Place('D', 2);
		//Place p18 = new Place('D', 3);
		//Place p19 = new Place('D', 4);
		//Place p20 = new Place('D', 5, v5);
		//Place[] placesRangeeA = new Place[] {p1, p2, p3, p4, p5};
		//Place[] placesRangeeB = new Place[] {p6, p7, p8, p9, p10};
		//Place[] placesRangeeC = new Place[] {p11, p12, p13, p14, p15};
		//Place[] placesRangeeD = new Place[] {p16, p17, p18, p19, p20};
		//Place[] placesRangeeE = new Place[] {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
		//Place[] placesRangeeF = new Place[] {p11, p12, p13, p14, p15, p16, p17, p18, p19, p20};
		//Place[] placesALL = new Place[] {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20};

		//Parking park0 = new Parking(placesRangeeA);
		//Parking park1 = new Parking(placesRangeeB);
		//Parking park2 = new Parking(placesRangeeC);
		//Parking park3 = new Parking(placesRangeeD);
		//Parking park4 = new Parking(placesRangeeE);
		//Parking park5 = new Parking(placesRangeeF);
		//Parking[] parkings0 = new Parking[] {park0, park2, park4};
		//Parking[] parkings1 = new Parking[] {park1, park3, park5};
		//Parking[] parkingsALL = new Parking[] {park0, park1, park2, park3, park4, park5};
		
		//Usine usine0 = new Usine("Papa Ours", park0);
		//Usine usine1 = new Usine("Macroute", park1);
		//Usine usine2 = new Usine("Telemac", park2);
		//Usine usine3 = new Usine("Chat", park3);
		//Usine usine4 = new Usine("Chocolatine", park4);
		//Usine usine5 = new Usine("Raclette", park5);
		//Usine usine6 = new Usine("banane", parkings0);
		//Usine usine7 = new Usine("Lion", parkings1);
		//Usine[] usines0 = new Usine[] {usine0, usine2, usine4, usine6};
		//Usine[] usines1 = new Usine[] {usine1, usine3, usine5, usine7};
		//Usine[] usinesALL = new Usine[] {usine0, usine1, usine2, usine3, usine4, usine5, usine6, usine7};

		//Stock stock0 = new Stock(usine0);
		//Stock stock1 = new Stock(usine1);
		//Stock stock2 = new Stock(usine2);
		//Stock stock3 = new Stock(usine3);
		//Stock stock4 = new Stock(usine4);
		//Stock stock5 = new Stock(usine5);
		//Stock stock6 = new Stock(usine6);
		//Stock stock7 = new Stock(usine7);
		//Stock[] stocks0 = new Stock[] {stock0, stock2, stock4, stock6};
		//Stock[] stocks1 = new Stock[] {stock1, stock3, stock5, stock7};
		//Stock[] stocksALL = new Stock[] {stock0, stock1, stock2, stock3, stock4, stock5, stock6, stock7};

		//Constructeur constructeur0 = new Constructeur("T-shirt", usine0, stock0);
		//Constructeur constructeur1 = new Constructeur("Dauphin", usine1, stocks0);
		//Constructeur constructeur2 = new Constructeur("Cendrillon", usines0, stock1);
		//Constructeur constructeur3 = new Constructeur("Boulangier", usinesALL, stocksALL);
		//Constructeur[] constructeurs0 = new Constructeur[] {constructeur0, constructeur2};
		//Constructeur[] constructeurs1 = new Constructeur[] {constructeur1, constructeur3};
		//Constructeur[] constructeurALL = new Constructeur[] {constructeur0, constructeur1, constructeur2, constructeur3};
		
		//Catalogue catalogue0 = new Catalogue(constructeur1, voituresALL);
		//Catalogue catalogue1 = new Catalogue(constructeur0);
		//Catalogue catalogueALL = new Catalogue(constructeurALL, voituresALL);

		//Concessionnaire concessionnaire0 = new Concessionnaire(catalogueALL);
		//Concessionnaire concessionnaire1 = new Concessionnaire("ToutVoitureTout", catalogueALL);
		//Concessionnaire concessionnaire2 = new Concessionnaire("Voitures Passes Partout", catalogue1);

		Commande commande0 = new Commande();
		Commande commande1 = new Commande(v0);
		Commande commande2 = new Commande(voituresALL);
		
		//System.out.println(commande1.toString());
		commande0.addVoitureCommande(v5);
		commande2.addVoitureCommande(voituresALL);
		
		commande1.setVoituresCommande(voituresALL);
		System.out.println(commande1.toString());
		
	}

}
