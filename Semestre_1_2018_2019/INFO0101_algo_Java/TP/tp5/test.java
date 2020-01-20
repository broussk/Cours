import java.util.Scanner;
import java.lang.Math;

public class test {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int nbMax=0, cpt=0, reste,max=-999999999; ;
		for (int i=0; i<10; i++ ) {
			System.out.print("entrez un entier : ");
			nbMax=sc.nextInt();
			if (nbMax>max) {
				max=nbMax;
			}
		}
		
		for (int i=0; max>0; i++) {
			reste=max%10;
			System.out.println(reste+"reste");
    		max=(max-reste)/10;
    		System.out.println(max+"max");
    		cpt++;
    	}
		System.out.println(cpt+"fois");
    }
}