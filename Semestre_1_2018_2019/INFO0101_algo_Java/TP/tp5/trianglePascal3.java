import java.util.Scanner;
import java.lang.Math;

public class trianglePascal3 {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		long taille;
		System.out.print("Entrez la taille du triangle de Pascal : ");
		taille=sc.nextLong();
		afficherTriangle(taille);
        System.out.println("suite de Fibonacci de "+taille+" termes :");
        Fibonacci(taille);
    }

    public static long coeffBinomial(long n, long p){
    	long resultat;
    	resultat=factorielle(n)/(factorielle(p)*factorielle(n-p));
		return resultat;    
    }

    public static long factorielle(long nb){
    	long resultat=1;
    	for (int i=1; i<=nb;i++){
    		resultat=resultat*i;
    	}
    	return resultat;
    }

    public static long nbDigits(long nb){
    	long cpt=0, reste;
		for (int i=0; nb>0; i++) {
			reste=nb%10;
    		nb=(nb-reste)/10;
    		cpt++;
    	}
		return cpt;
    }

    public static long coeffMaximum (long nLigne){
    	long max=0;
		if (nLigne>0) {
			for (int j=0; j<nLigne; j++) {
				if (max<coeffBinomial(nLigne,j)) {
					max=coeffBinomial(nLigne,j);
				}
			}
		}
		return max;
    }

    public static void afficherEspace (long n){
    	for (int i=1; i<=n; i++) {
    		System.out.print(" ");
    	}
    }

    public static void afficherValeur (long nb, long nbDigits){
    	long nbDigitsNb, n;
    	afficherEspace(nbDigits-nbDigits(nb));
    	System.out.print(nb);
    }

    public static void afficherLigne(long ligne, long nbDigits){
		ligne=ligne-1;
		if (ligne>0) {
			for (int j=0; j<ligne; j++) {
				if (coeffBinomial(ligne,j)!=0) {
					afficherValeur(coeffBinomial(ligne,j),nbDigits);
					System.out.print(" ");
				}	
			}
			afficherValeur(1,nbDigits);
			System.out.println();
		}
    }

    public static void afficherTriangle(long ligne){
    	long nbDigits=nbDigits(coeffMaximum(ligne));

    	afficherEspace((ligne-1)*nbDigits);
    	afficherValeur(1,nbDigits);
    	System.out.println();

    	for (int i=2; i<=ligne; i++) {
    		afficherEspace((ligne-i)*nbDigits);
    		afficherLigne(i,nbDigits);
    	}
    }

    public static long ligneMax(long seuil){
        long nLigne=2;
        while(coeffMaximum(nLigne)<seuil){
            nLigne++;
        }
        return nLigne;
    }

    public static long puissance2(long ligneN){
        long somme=0;
        for (int j=0; j<ligneN; j++) {
            if (coeffBinomial(ligneN,j)!=0) {
                somme=somme+coeffBinomial(ligneN,j);
            }   
        }
        return somme;
    }

    public static long sommeCoefficient(long lignes){
        long sommeCoefficient=3;
        for (int i=2; i<lignes; i++) {
            sommeCoefficient=sommeCoefficient+puissance2(i);
        }
        return sommeCoefficient;
    }

    public static long lapin (long mois){
        long nbLapinsAv=0, nbLapins=1, nbLapinsAp=0;
        if (mois==0) {
            return nbLapinsAv;
        }
        else{
            if (mois==1) {
                return nbLapins;
            }
            else{
                for (int i=2; i<=mois; i++) {
                    nbLapinsAp=nbLapinsAv+nbLapins;
                    nbLapinsAv=nbLapins;
                    nbLapins=nbLapinsAp;
                }
                return nbLapins;
            }
        }
    }

    public static void Fibonacci(long n){
        for (int i=0; i<=n; i++) {
            System.out.print(lapin(i)+", ");
        }
    }
}