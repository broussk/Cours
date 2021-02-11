import java.util.Scanner;
import java.util.Random;


class TrianglePascal {

  public static void main(String[] args) {

	Scanner clavier = new Scanner(System.in);


	System.out.println("Saisissez le nombre de ligne a afficher:");
	int n;
	n = clavier.nextInt();
	System.out.println();

	afficherTriangle (n);
	}


	public static int Factorielle (int a) {
		int fact = 1;
		for (int i=1; i<=a; i++)
		{
			fact = fact*i;
		}
		return fact;
	}

	public static int CoeffBinomial (int n, int p) {
		int cb;
		int k;
		k = n-p;
		cb = Factorielle(n)/(Factorielle(p)*Factorielle(k));
		return cb;
	}

	public static void afficherLigne (int c) {
		int i;
		int y;
		y = 1;
		for(i=0 ; i<c+1 ; i++){
			y = CoeffBinomial(c,i);
			System.out.print(y + " ");
			}
		System.out.println (" ");
	}

	public static void afficherTriangle (int x){
		int i;
		for(i=0;i<x+1;i++) {
			afficherLigne (i);
		}
	}
}
