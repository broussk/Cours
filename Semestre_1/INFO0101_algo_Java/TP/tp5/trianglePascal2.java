import java.util.Scanner;
import java.lang.Math;

public class trianglePascal2 {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		long ligne, n, nbDigits;

		System.out.print("entrez un entier pour le nombre de lignes du triangle de Pascal : ");
		ligne=sc.nextInt();
		System.out.print("entrez la ligne du triangle de Pascal que vous voulez afficher avant le triangle : ");
		n=sc.nextInt();
		
		System.out.println("Le nombre de Digits de ce triangle est : "+(coeffMaximum(ligne)+1));

		System.out.println("Vous avez afficher la ligne "+afficherLigne(n, ligne, (coeffMaximum(ligne)+1)));
		System.out.println("De ce triangle a "+afficherTriangle(ligne, (coeffMaximum(ligne)+1))+" lignes");
    }

    public static String afficherValeur(long nb, long digits){
    	String nbD=""+nb;
    	if (nbDigits(nb)<digits) {
    		nbD=afficherEspace(digits- (nbDigits(nb)-1))+nb;
    	}
    	return nbD;
    }

    public static String afficherEspace(long n){
    	String espaces="";
    	for (int i=1; i<n; i++) {
    		espaces=espaces+" ";
    	}
    	return espaces;
    }

    public static long coeffMaximum(long ligne){
    	long max=-99999;
    	for (int i=0; i<ligne; i++) {
			for (int j=0; j<ligne; j++) {
				if (coeffBinomial(i,j)>max) {
					max=coeffBinomial(i,j);
				}
			}
		}
		max=nbDigits(max);
		return max;
    }

    public static long nbDigits(long nbMax){
    	long cpt=0, reste, max=-999999999 ;
		for (int i=0; nbMax>0; i++) {
			reste=nbMax%10;
    		nbMax=(nbMax-reste)/10;
    		cpt++;
    	}
		return cpt;
    }

    public static long afficherTriangle(long ligne, long nbDigits){
    	for (int i=0;i<ligne+1 ;i++ ) {
    		//nbDigits=((ligne-1)-i)*nbDigits;
    		afficherLigne(i, ligne, nbDigits);
    	}
		return ligne;
    }

    public static long afficherLigne(long n, long ligne, long nbDigits){
    	for (int i=0; i<=ligne-1; i++) {
			if (i==n-1) {		
			nbDigits=((ligne-1)-i)*nbDigits;	
				if (i==0) {
					System.out.print(afficherValeur(1,nbDigits));
				}
				if (i>0) {
					for (int j=0; j<=ligne-1; j++) {
						if (coeffBinomial(i,j)!=0) {
							System.out.print(afficherValeur(coeffBinomial(i,j),nbDigits));
						}
						else {
							System.out.print("");
						}
					}
				}
				System.out.println();
			}
		}
		return n;
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
}