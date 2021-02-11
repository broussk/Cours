import java.util.Scanner;

class Facturation {

	public static void main(String[] args) {

		int nbBouteilleErable;
		int nbBouteilleBleuets;
		float fraisTransport;
    	Scanner clavier = new Scanner(System.in);
    	boolean retry = false;
    	int tryagain;
    	while(retry == false){
	    	do{
	    		System.out.println("Veuillez saisir le nombre de bouteille de sirop d'erable :");
	    		nbBouteilleErable = clavier.nextInt();
	    	}while(saisirNbSiropErable(nbBouteilleErable) == false);

	    	do{
	    		System.out.println("Veuillez saisir le nombre de bouteille de sirop de bleuet sauvage :");
	    		nbBouteilleBleuets = clavier.nextInt();
	    	}while(saisirNbSiropBleuets(nbBouteilleBleuets) == false);

	    	afficherFacture(calculerFraisTransport(nbBouteilleErable,nbBouteilleBleuets),nbBouteilleBleuets,nbBouteilleErable);
	    	System.out.println("Voulez-vous refaire une commande ? 1 - Oui ou 2 - Non");
	    	tryagain = clavier.nextInt();
	    	if(tryagain == 2){
	    		retry = true;
	    	}
    	}
	}
 
    public static boolean saisirNbSiropErable(int a) {

    	boolean estValide = false;
    	if(a % 3 == 0){
    		estValide = true;
    	} else {
    		System.out.println("Vous devez oligatoirement commander par lot de 3 ou ne pas en prendre.");
    	}
    	return estValide;
	}

	public static boolean saisirNbSiropBleuets(int a) {

		boolean estValide = false;
		if(a >= 0){
			estValide = true;
		} else {
			System.out.println("Saisie invalide, veuillez recommencer :");
		}
		return estValide;
	}

	public static float calculerFraisTransport(int cruchons, int bouteilles) {

		//Frais Transport Cruchons
		float fraisCruchons = 0;

		if(cruchons >= 3 && cruchons <= 11){
			fraisCruchons = cruchons * 1.5f;
		} else if(cruchons >= 12 && cruchons <= 24){
			fraisCruchons = cruchons;
		}

		//Frais Transport Bouteilles
		float fraisBouteilles;

		fraisBouteilles = bouteilles * 0.5f;

		//Frais Transport Total

		float fraisTotal;

		return fraisTotal = fraisBouteilles + fraisCruchons;
	}

	public static void afficherFacture(float fraisTransport, int nbSiropBleuets, int nbSiropErable){

		float prixSiropErable = nbSiropErable * 28;
		float prixSiropBleuets = nbSiropBleuets * 12;
		float prixTotal = prixSiropErable + prixSiropBleuets + fraisTransport;
		System.out.println(" \nFacture :\n"+nbSiropErable+" sirop d'erable : "+prixSiropErable+" Euros\n"+nbSiropBleuets+" sirop bleuets : "+prixSiropBleuets+" Euros\nFrais de transport : "+fraisTransport+" Euros\n-----------------\nTotal : "+prixTotal);
	}
}