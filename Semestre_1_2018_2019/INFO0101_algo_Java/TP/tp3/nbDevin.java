import java.util.Scanner;
import java.lang.Math;

public class nbDevin {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		double sol, nb, min, max, cpt, m, minc, maxc;

		System.out.println("Choisissez les bornes (les bornes doivent etre positives) :");
		System.out.print("minimum (doit etre a 0 ou 1): ");
		minc=sc.nextDouble();
		System.out.print("maximum : ");
		maxc=sc.nextDouble();

		sol=Math.random()*maxc-minc+1;
		sol=(int)sol;
		cpt=maxc-minc;

		System.out.println("Vous avez " + (cpt+1) + " essaies ! ");

		do {
			System.out.print("Saisissez un entier positif : ");
			nb=sc.nextDouble();

			System.out.println(sol);
			
			if (nb>sol){
				System.out.println("c'est - !");
				min=nb;
				if (nb<=min){
					System.out.println("Trop grand, je te l'ai deja dit.");
				}
			}
			if (nb<sol) {
				System.out.println("c'est + !");
				max=nb;
				if (nb>=max){
					System.out.println("Trop petit, je te l'ai deja dit.");
				}
			}
			if (minc<0 || maxc<0 || nb<0 || nb<minc ||nb>maxc){
				System.out.println(" ! ERREUR ! ");
			}
			
			System.out.println("il vous reste " +(cpt--)+ " essaies !");

		}while (nb!=sol | nb<minc | nb>maxc);

		if (nb==sol){
			System.out.println("Bravo vous avez gagne ! ");
    	}
    	else {
    		System.out.println("Vous avez perdu ! ");
    	}
    }
}