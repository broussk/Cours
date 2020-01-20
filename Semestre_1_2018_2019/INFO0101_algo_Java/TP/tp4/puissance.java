import java.util.Scanner;

public class puissance {

	public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int x,y;
		System.out.println("Le calcule sera : x puissance y");
	    System.out.print("Entrez un entier x : ");
	    x = clavier.nextInt();
	    System.out.print("Entrez un entier y : ");
	    y= clavier.nextInt();
		
	    System.out.println("La puissance du nombre "+x+" par "+y+" est : "+puissance(x,y)+".");
    }

    public static long puissance(int a, int b){
    	long resultat1=1;
    	for (int i=1; i<=b;i++){
    		resultat1=a*resultat1;
    	}
    	return resultat1;
    }
}