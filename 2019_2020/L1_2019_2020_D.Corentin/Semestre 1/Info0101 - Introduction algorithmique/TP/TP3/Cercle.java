import java.util.Scanner;
public class Cercle{
	static Scanner clavier = new Scanner(System.in);
	public static void main(String[] args){
		System.out.println("Entrer le rayon du cercle : ");
		double r = clavier.nextDouble();
		
		while (r < 0 ){
			System.out.println("ERREUR le rayon du cercle ne peut pas etre negatif. Reentrer une valeur pour le rayon : ");
			r = clavier.nextDouble();
		}
		
		double p = 2*Math.PI*r;
		System.out.println("Le perimetre du cercle est : " + p);
		
		
		
	}
	
}