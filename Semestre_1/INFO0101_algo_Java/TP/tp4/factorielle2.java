import java.util.Scanner;

public class factorielle2 {

	public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		long nb;
	    System.out.print("Entrez un entier : ");
	    nb = clavier.nextInt();
		
	    System.out.println("La factorielle du nombre "+nb+" que vous avez tape est : "+factorielle(nb));
    }

    public static long factorielle(long nb){
    	long resultat=1;
    	for (int i=1; i<=nb;i++){
    		resultat=resultat*i;
    	}
    	return resultat;
    }
}