import java.util.Scanner;

class Saisie {
 
 public static void main(String[] args) {
 System.out.print("Bonjour");
 System.out.println(" tout le monde !");
 
 Scanner clavier = new Scanner(System.in);
 int a;
 System.out.println("Entrer une valeur entiere");
 a = clavier.nextInt();
 System.out.println("Vous avez saisie : " + a);
 }
}