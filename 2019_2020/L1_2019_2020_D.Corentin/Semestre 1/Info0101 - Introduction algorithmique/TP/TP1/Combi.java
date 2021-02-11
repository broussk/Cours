import java.util.Scanner;
import java.util.Random;
class Combi{
	
	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);
		
	    int combi = 100 + (int)(Math.random() * ((999 - 100) + 1));
	    System.out.println("Le codes est : " + combi);
		
		 int a = combi %10;
		 combi = combi / 10;
		
		
		 int b = combi %10;
		 combi = combi / 10;	  
		
		//System.out.println(combi + " et " + b + " et " + a );
		
		System.out.print("Entrer le premier chiffre du code : ");
		int c1 = clavier.nextInt();
		System.out.print("Entrer le deuxieme chiffre du code : ");
		int c2 = clavier.nextInt();
		System.out.print("Entrer le troisieme chiffre du code : ");
		int c3 = clavier.nextInt();
		
		if (c1 == combi && c2 == b && c3 == a ){
			System.out.print("Vous avez peter la banque");
		} else {
			System.out.print("LA POLICE ARRIVE !! ");
		}
} 
}
