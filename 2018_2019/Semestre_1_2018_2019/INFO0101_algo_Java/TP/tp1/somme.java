import java.util.Scanner;
class somme {
 
    public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int a,b,somme;
	    System.out.print("Valeur 1 : ");
	    a = clavier.nextInt();
	    System.out.print("Valeur 2 : ");
	    b = clavier.nextInt();
	
	    
        somme=a+b;
	    System.out.println("La somme de " + a + "+"+ b+"="+somme);
    }
 
}