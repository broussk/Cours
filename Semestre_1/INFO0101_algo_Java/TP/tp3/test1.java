import java.util.Scanner;
import java.lang.Math;

public class test1 {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);	
		double m, n;
		
		System.out.print("entrez un entier :");
		n=sc.nextDouble();
		for(int i=1;i<=n;i++){
			System.out.println(i);
			m= Math.random();
			System.out.println("nombre random: " +m);
		}
    }
	
}