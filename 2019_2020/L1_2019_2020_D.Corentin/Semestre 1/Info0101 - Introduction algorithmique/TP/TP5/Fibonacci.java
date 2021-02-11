import java.util.Scanner;

class Fibonacci {

  public static void main(String[] args) {

	Scanner clavier = new Scanner(System.in);


	System.out.println ("Saisissez une ligne du Triangle de Pascal, pour calculer la somme de ses coefficients binomiaux");
	int w;
	w = clavier.nextInt();

	System.out.println("La Somme des Coefficients Binomiaux de la ligne "+w+" est "+ puissance2(w));
	System.out.println ();

	System.out.println("La Somme des Coefficients Binomiaux des "+w+" premieres lignes est "+ sommeCoefficient(w));
	System.out.println ();

	System.out.println ("Saisissez le nombre de mois d'elevage de lapin");
	int z = clavier.nextInt();
	System.out.println(lapin(z));

	System.out.print("La suite de Fibonacci est: ");
	Fibonacci (z);
	System.out.println ();


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


	public static double puissance2 (int n){
		double puissance2 = Math.pow(2,n);
		return puissance2;
	}

	public static double sommeCoefficient (int n){
		int i;
		double total = 0;
		for (i=0; i<=n; i++){
			total = total + puissance2(i);
		}
		return total;
	}

	public static int lapin (int z){
		int depart = 0;
		int depart1 = 1;
		int total = 0;
		int i;

		for (i=1; i<z; i++){
			total = depart1 + depart;
			depart = depart1;
			depart1 = total;
		}
		return depart1;
	}

	public static void Fibonacci (int z){
		int i;
		for (i=1; i<=z; i++){
			System.out.print(lapin(i)+" ");
		}
	}

}
