import java.util.Scanner;
import java.lang.Math;

public class trianglePascal {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int ligne,n;

		System.out.print("entrez un entier pour le nombre de lignes du triangle de Pascal : ");
		ligne=sc.nextInt();
		System.out.print("entrez la ligne du triangle de Pascal que vous voulez afficher avant le triangle : ");
		n=sc.nextInt();
		
		System.out.println("Vous avez afficher la ligne "+afficherLigne(n, ligne));
		System.out.print("De ce triangle a "+afficherTriangle(ligne)+" lignes");
    }

    public static int afficherTriangle(int ligne){
    	for (int i=0; i<ligne; i++) {
				if (i==0) {
					System.out.print("1");
				}
				if (i>0) {
					for (int j=0; j<ligne; j++) {
						if (coeffBinomial(i,j)!=0) {
							System.out.print(coeffBinomial(i,j)+" ");
						}
						else {
							System.out.print(" ");
						}
					}
				}
				System.out.println();
		}
		return ligne;
    }

    public static int afficherLigne(int n, int ligne){
    	for (int i=0; i<ligne && i<=n-1; i++) {
			if (i==n-1) {
				if (i>0) {
					for (int j=0; j<ligne; j++) {
						if (coeffBinomial(i,j)!=0) {
							System.out.print(coeffBinomial(i,j)+" ");
						}
						else {
							System.out.print(" ");
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