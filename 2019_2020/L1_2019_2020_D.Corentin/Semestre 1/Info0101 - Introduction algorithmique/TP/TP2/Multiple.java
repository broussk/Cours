import java.util.Scanner;

public class Multiple {

    public static void main(String[] args) {

		Scanner clavier = new Scanner(System.in);

		System.out.println("1ere borne ? ");
		int a;
		a = clavier.nextInt();

		System.out.println("2nd borne ? ");
		int b;
		b = clavier.nextInt();

		System.out.println("Votre valeur ? ");
		int c;
		c = clavier.nextInt();

		if(b<a) {
			int tmp=b;
			b=a;
			a=tmp;
			if(c>b || c<a) {
				System.out.print("La valeur entre n'est pas comprise dans l'intervalle donne. Resaisisez une valeur : ");
				c = clavier.nextInt();
				for(int i=a; i<=b; i++) {
					if(i%c == 0) {
						System.out.println(i);
					}
				}
			} else {
				for(int i=a; i<=b; i++) {
					if(i%c == 0) {
						System.out.println(i);
					}
				}
			}
		} else if(a<b) {
			if(c>b || c<a) {
				System.out.println("La valeur entre n'est pas comprise dans l'intervalle donne. Resaisisez une valeur : ");
				c = clavier.nextInt();
				for(int i=a; i<=b; i++) {
					if(i%c == 0) {
						System.out.println(i);
					}
				}
			} else {
				for(int i=a; i<=b; i++) {
					if(i%c == 0) {
						System.out.println(i);
					}
				}
			}

		}
	}
}
