import java.util.Scanner;
class Saisie {
 
    public static void main(String[] args) {
	System.out.print("Bonjour ");
	System.out.println("tout le monde !");
	System.out.print("Veuillez entrer un entier : ");
	Scanner clavier = new Scanner(System.in);
 
	int a;
	a = clavier.nextInt();	
	System.out.println("L'entier tape est : "+a);
    }
 
}