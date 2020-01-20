import java.util.Scanner;
import java.lang.Math;

public class facturation {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int nbCruchonErable, nbSiropBleuets;
		double prixTransport=0, prixSiropErable=0, prixSiropBleuets=0;
		double prixTotal=0;

			//fonction saisirNbSiropErable
		System.out.print("Combien de cruchons de sirop d'erable voulez-vous ? : ");
		nbCruchonErable=saisirNbSiropErable();
   		

    		//fonction saisirNbSiropBleuets
    	System.out.print("Combien de bouteilles de sirop de Bleuts voulez-vous ? : ");
    	nbSiropBleuets=saisirNbSiropBleuets();
    
			//fonction calculFraisTransport et afficherFacture
		System.out.print("Votre facture est de            : "+afficherFacture(nbCruchonErable,nbSiropBleuets,prixTransport,prixTransport)+" euros.");
    }

    public static int saisirNbSiropErable(){
    	Scanner sc = new Scanner(System.in);
    	int nbCruchonErable;
    	nbCruchonErable=sc.nextInt();
		while((nbCruchonErable%3)!=0 || nbCruchonErable<0){
			System.out.println("Vous avez tape une valeur fausse, veuillez recommencer, les cruchons se vendent par 3.");		
			System.out.print("Combien de cruchons de sirop d'erable voulez-vous ? : ");
   			nbCruchonErable=sc.nextInt();
   		}
   		return nbCruchonErable;
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

    public static double calculerFraisTransport(int nbCruchonErable, int nbSiropBleuets){
    	double prixTransport;
    	if (nbCruchonErable>=3 && nbCruchonErable<=11) {
			prixTransport=nbCruchonErable*1.5;
		}
		else{
			if (nbCruchonErable>=12 && nbCruchonErable<=24) {
				prixTransport=nbCruchonErable*1;
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

    public static double afficherFacture(int nbCruchonErable,int nbSiropBleuets,double prixTransport,double prixTotal){
    	double prixSiropErable, prixSiropBleuets;

		prixSiropErable=nbCruchonErable*28;
		prixSiropBleuets=nbSiropBleuets*12;
		prixTransport=calculerFraisTransport(nbCruchonErable, nbSiropBleuets);
		prixTotal=prixSiropErable+prixSiropBleuets+prixTransport;

		System.out.println("Prix cruchons d'erable          : "+prixSiropErable+" euros.");
		System.out.println("Prix bouteilles de Bleuets      : "+prixSiropBleuets+" euros.");
		System.out.println("Frais de transport              : "+prixTransport+" euros.");
		return prixTotal;
    }
}