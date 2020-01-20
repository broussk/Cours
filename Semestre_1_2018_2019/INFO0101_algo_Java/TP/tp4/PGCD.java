import java.util.Scanner;

public class PGCD {

	public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int a=0,b=0;
		while(estValide(a,b)==0){
			if (estValide(a,b)==0) {
				System.out.println("Veuillez taper des valeurs positives, merci");
			}
			System.out.print("Entrez un entier a : ");
			a=clavier.nextInt();
			System.out.print("Entrez un entier b : ");
			b=clavier.nextInt();
		}

		System.out.println("le PGCD de "+a+" et "+b+" est : "+PGCD(a,b)+".");
    }

    public static int PGCD(int a, int b){
    	int r;
    	r=a%b;
    	while(r!=0){
    		a=b;
    		b=r;
    		r=a%b;
    	}
    	return b;
    }

    public static int estValide(int a, int b){
    	int reponse;
    	if (a<=0 || b<=0) {
    		reponse=0;
    		return reponse;
    	}
    	else{
    		reponse=1;
    		return reponse;
    	}
    }
}