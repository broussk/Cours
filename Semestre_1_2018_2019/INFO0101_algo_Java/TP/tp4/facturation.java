import java.util.Scanner;
import java.lang.Math;

public class facturation {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int nbCruchonErableXC, nbCruchonErableM, nbCruchonErableC, nbSiropBleuets, rep=1;
		double prixTransport=0, prixSiropErableXC=0, prixSiropErableM=0, prixSiropErableC=0, prixSiropBleuets=0;
		double prixTotal=0;
		String sirop;

		while(rep==1){
				//fonction saisirNbSiropErable
			System.out.println("Quels types de sirop d'erable voullez-vous? extra-clair, medium, clair ou rien (tapez 0 dans tout):");
			nbCruchonErableXC=saisirNbSiropErable(sirop="extra-clair");
			nbCruchonErableM=saisirNbSiropErable(sirop="medium");
			nbCruchonErableC=saisirNbSiropErable(sirop="clair");
	   		
	    		//fonction saisirNbSiropBleuets
	    	System.out.print("Combien de bouteilles de sirop de Bleuts voulez-vous ? : ");
	    	nbSiropBleuets=saisirNbSiropBleuets();
	    
				//fonction calculFraisTransport et afficherFacture
			System.out.println("Votre facture est de            : "+afficherFacture(nbCruchonErableXC, nbCruchonErableM, nbCruchonErableC,nbSiropBleuets,prixTransport,prixTransport)+" euros.");
			System.out.println("voulez-vous faire une autre commande? :");
			System.out.println("tapez 1 pour oui. tapez 0 pour non.");
			rep=sc.nextInt();
		}
    }

    public static int saisirNbSiropErable(String sirop){
    	Scanner sc = new Scanner(System.in);
    	int nbCruchonErableXC, nbCruchonErableM, nbCruchonErableC;

    	if (sirop=="extra-clair") {
    		System.out.print("Combien de cruchons de sirop d'erable extra-clair voulez-vous ? : ");
    		nbCruchonErableXC=sc.nextInt();
			while((nbCruchonErableXC%3)!=0 || nbCruchonErableXC<0){
				System.out.println("Vous avez tape une valeur fausse, veuillez recommencer, les cruchons se vendent par 3.");		
				System.out.print("Combien de cruchons de sirop d'erable extra-clair voulez-vous ? : ");
	   			nbCruchonErableXC=sc.nextInt();
	   		}
	   		return nbCruchonErableXC;
    	}
    	if (sirop=="medium") {
    		System.out.print("Combien de cruchons de sirop d'erable medium voulez-vous ? : ");
    		nbCruchonErableM=sc.nextInt();
			while((nbCruchonErableM%3)!=0 || nbCruchonErableM<0){
				System.out.println("Vous avez tape une valeur fausse, veuillez recommencer, les cruchons se vendent par 3.");		
				System.out.print("Combien de cruchons de sirop d'erable medium voulez-vous ? : ");
	   			nbCruchonErableM=sc.nextInt();
	   		}
	   		return nbCruchonErableM;
    	}
    	if (sirop=="clair"){
    		System.out.print("Combien de cruchons de sirop d'erable clair voulez-vous ? : ");
			nbCruchonErableC=sc.nextInt();
			while((nbCruchonErableC%3)!=0 || nbCruchonErableC<0){
				System.out.println("Vous avez tape une valeur fausse, veuillez recommencer, les cruchons se vendent par 3.");		
				System.out.print("Combien de cruchons de sirop d'erable clair voulez-vous ? : ");
	   			nbCruchonErableC=sc.nextInt();
	   		}
	   		return nbCruchonErableC;
    	}
    	return 0;
    }

    public static int saisirNbSiropBleuets(){
		Scanner sc = new Scanner(System.in);
    	int nbSiropBleuets;
    	nbSiropBleuets=sc.nextInt();
    	while(nbSiropBleuets<0){
			System.out.println("Vous avez tapé une valeur fausse, veuillez recommencer");		
    		System.out.print("Combien de bouteilles de sirop d'erable voulez-vous ? : ");
    		nbSiropBleuets=sc.nextInt();
    	}
    	return nbSiropBleuets;
    }

    public static double calculerFraisTransport(int nbCruchonErableXC, int nbCruchonErableM, int nbCruchonErableC, int nbSiropBleuets){
    	double prixTransport;
    	if (nbCruchonErableXC>=3 && nbCruchonErableXC<=11) {
			prixTransport=nbCruchonErableXC*1.5;
		}
		else{
			if (nbCruchonErableXC>=12 && nbCruchonErableXC<=24) {
				prixTransport=nbCruchonErableXC*1;
			}
			else{
				prixTransport=0;
			}
		}
		if (nbCruchonErableM>=3 && nbCruchonErableM<=11) {
			prixTransport=prixTransport+nbCruchonErableM*1.5;
		}
		else{
			if (nbCruchonErableM>=12 && nbCruchonErableM<=24) {
				prixTransport=prixTransport+nbCruchonErableM*1;
			}
			else{
				prixTransport=0;
			}
		}
		if (nbCruchonErableC>=3 && nbCruchonErableC<=11) {
			prixTransport=prixTransport+nbCruchonErableC*1.5;
		}
		else{
			if (nbCruchonErableC>=12 && nbCruchonErableC<=24) {
				prixTransport=prixTransport+nbCruchonErableC*1;
			}
			else{
				prixTransport=0;
			}
		}

		if (nbSiropBleuets>0) {
			prixTransport=prixTransport+nbSiropBleuets*0.5;
		}
		return prixTransport;
    }

    public static double afficherFacture(int nbCruchonErableXC, int nbCruchonErableM, int nbCruchonErableC ,int nbSiropBleuets, double prixTransport,double prixTotal){
    	double prixSiropErableXC, prixSiropErableM, prixSiropErableC, prixSiropBleuets;

		prixSiropErableXC=nbCruchonErableXC*28;
		prixSiropErableM=nbCruchonErableM*21.4;
		prixSiropErableC=nbCruchonErableC*23.5;
		prixSiropBleuets=nbSiropBleuets*12;
		prixTransport=calculerFraisTransport(nbCruchonErableXC, nbCruchonErableM, nbCruchonErableC, nbSiropBleuets);
		prixTotal=prixSiropErableXC+prixSiropErableM+prixSiropErableC+prixSiropBleuets+prixTransport;

		System.out.println("Prix cruchons d'erable extra-clair : "+prixSiropErableXC+" euros.");
		System.out.println("Prix cruchons d'erable medium      : "+prixSiropErableM+" euros.");
		System.out.println("Prix cruchons d'erable clair       : "+prixSiropErableC+" euros.");
		System.out.println("Prix bouteilles de Bleuets         : "+prixSiropBleuets+" euros.");
		System.out.println("Frais de transport                 : "+prixTransport+" euros.");
		return prixTotal;
    }
}