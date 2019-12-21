import java.util.Scanner;
class signe {
 
    public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int a;
	    System.out.print("Entrez un entier positif ou negatif : ");
	    a = clavier.nextInt();
	     if (a<0){
		     System.out.print("L'entier est negatif");
		 }
		 else {

			 if (a==0) {
				System.out.print("Vous avez saisi 0");
			 }	
             else {
                 System.out.print("L'entier est positif");
			 }
	     }
	    
    }
}