import java.util.Scanner;

class TrianglePascal2 {

  public static void main(String[] args) {

	Scanner clavier = new Scanner(System.in);


	System.out.println("Saisissez le nombre de ligne a afficher:");
	int n;
	n = clavier.nextInt();
	System.out.println();

	System.out.println("Le nombre de digits de "+n+" est: "+ nbDigits(n));

	System.out.println("Le plus grand coefficient binomial de la ligne "+n+" est: "+ coeffMaximum(n));

	afficherLigne(n);
	System.out.println();

	afficherTriangle(n, nbDigits(n));

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

	public static int nbDigits (int z) {
		int o;
		o = 0;
		while (z!=0)
		{
			z = z/10;
			o = o + 1;
		}
		return(o);
	}

	public static int coeffMaximum  (int n) {
		int i;
		int y;
		y = 1;
		int max;
		max = 0;
		for(i=0 ; i<n+1 ; i++)
		{
			y = CoeffBinomial(n,i);
			if (y > max)
			{
				max = y;
			}
		}
		return	max;
	}

	public static void afficherEspace (int n){
		int i;
		for (i=0 ; i<n ;i++)
		{
		System.out.print(" ");
		}
	}

	public static void afficherValeur (int n, int nbDigits){
		int val;
		val = n/nbDigits;
		int i;

	for (i = 0 ; i<val; i++){
		System.out.println("");
	}
	}


	public static void afficherLigne (int c) {
		int i;
		int y;
		y = 1;
		for(i=0 ; i<c+1 ; i++){
			y = CoeffBinomial(c,i);
			System.out.print(y + " ");
			}
		System.out.println(" ");
	}

	public static void afficherTriangle (int x, int nbDigits){
		int i;
		int n = x;

		for(i=0;i<x+1;i++) {
			afficherEspace((n - i)*nbDigits);
			afficherLigne (i);
			}
	}

}
