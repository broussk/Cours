import java.util.Scanner;
import java.lang.Math;

public class coeffBinomial {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		long a, b;
	    System.out.print("Entrez un entier n : ");
	    a=sc.nextLong();
	    System.out.print("un autre p : ");
	    b=sc.nextLong();
		
	    System.out.println("le coeffBinomial des nombre "+a+" "+ b+" est : "+coeffBinomial(a,b));
    }
    public static long coeffBinomial(long n, long p){
    	long resultat;
    	resultat=factorielle(n)/(factorielle(p)*factorielle(n-p));
		return resultat;    
    }

    public static long factorielle(long nb){
    	long resultat=1;
    	for (int i=1; i<=nb;i++){
    		resultat=resultat*i;
    	}
    	return resultat;
    }
}