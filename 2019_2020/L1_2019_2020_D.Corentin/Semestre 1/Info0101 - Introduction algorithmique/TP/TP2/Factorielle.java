import java.util.Scanner;
public class Factorielle{
	public static void main(String[] args){
	 Scanner clavier = new Scanner (System.in);
		
		System.out.print("Entrer une factorielle : ");
		
		int n=clavier.nextInt();
		int r=1;
		
		
		for (int i=1; i<=n; i++) {
			r=r*i;
			System.out.println(r);
		}
		
	     System.out.print("La factorielle de " + n +" est " +r);
	}
}