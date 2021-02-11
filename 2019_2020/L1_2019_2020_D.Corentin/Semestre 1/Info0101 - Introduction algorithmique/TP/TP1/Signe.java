import java.util.Scanner;

class Signe{
	
	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);
		System.out.print("Entre une valuer : ");
		int a = clavier.nextInt();
		
		if (a<0){
			System.out.println("L'entier est negatif");
		}
		if (a>0){
			System.out.println("L'entier est positif");
		}
		if (a==0){
			System.out.println("Vous avez saisie 0");
		}
	}
	
	
}


