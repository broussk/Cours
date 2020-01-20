import java.util.Scanner;
import java.lang.Math;

public class cercle {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);	
		double r, p;
		
		System.out.print("saisir un entier pour rayon ");
		r=sc.nextDouble();
		
		do{
			if (r<0){
				System.out.println("vous avez tape une valeur negative, ce qui est faux");
				System.out.print("saisir un entier pour rayon ");
				r=sc.nextDouble();
			}
		}while (r<0);
		p=2*Math.PI*r;
		System.out.println("le perimetre du cercle de rayon " +r+ " est : " +p);

		System.out.println();
    }
}