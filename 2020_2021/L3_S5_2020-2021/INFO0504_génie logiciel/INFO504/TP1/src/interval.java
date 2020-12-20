import java.util.Scanner;

public class interval {

	public static void main(String[] args) {
		int n, a, b, multiple;
		Scanner clavier = new Scanner(System.in);
		System.out.println("saisir a :");
		a = clavier.nextInt();
		System.out.println("saisir b :");
		b = clavier.nextInt();
		do {
			System.out.println("saisir n :");
			n = clavier.nextInt();
		}while(n>b || n<a);
		System.out.println("multiple de " + n + " :");
		multiple = 0;
		while(multiple<=b){
			System.out.print(multiple + "; ");
			multiple += n;
		}
		clavier.close();
	}
}
