import java.util.Scanner;

class Somme{
	
	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);
		System.out.print("Valeur 1 : ");
		int val1 = clavier.nextInt();
		System.out.print("Valeur 2 : ");
		int val2 = clavier.nextInt();
		int res = val1+val2;
		System.out.print("La somme de " + val1 + " + " + val2 + " = " + res);
	}
	
	
}


