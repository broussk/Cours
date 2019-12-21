import java.util.Scanner;

class boucle_for {
 
    public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		long nb, resultat=1;
	    System.out.print("Entrez un entier : ");
	    nb = clavier.nextInt();
		for( int i=1 ; i<=nb; i++ ) {
			resultat=resultat*i;
		}
	    System.out.println("La factorielle du nombre "+nb+" que vous avez tape est : "+resultat);
    }
}