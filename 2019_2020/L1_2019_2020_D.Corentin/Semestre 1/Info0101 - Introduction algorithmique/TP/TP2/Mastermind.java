import java.util.Scanner;


class Mastermind{

	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);

		 int rdm1 = (int)(Math.random()*10);
		 int rdm2 = (int)(Math.random()*10);
		 int rdm3 = (int)(Math.random()*10);
		 int rdm4 = (int)(Math.random()*10);

		 int a = 0;
		 int b = 0;
		 int c = 0;
		 int d = 0;

		System.out.println("----------------------------------------");
 		System.out.println("|                                      |");
 		System.out.println("| Bienvenue dans le Mastermind Java !  |");
 		System.out.println("|                                      |");
 		System.out.println("| Bonne chance pour trouver la reponse |");
 		System.out.println("|                                      |");
 		System.out.println("|       Rappel: chiffre de 1 a 9       |");
		System.out.println("|                                      |");
 		System.out.println("|       *: Chiffre invalide            |");
 		System.out.println("|       O: Chiffre valide              |");
		System.out.println("|                                      |");
 		System.out.println("----------------------------------------");

 		while(a!=rdm1 || b!=rdm2 || c!=rdm3 || d!=rdm4) {
             System.out.print("| ");
             a = clavier.nextInt();
             System.out.print("| ");
             b = clavier.nextInt();
             System.out.print("| ");
             c = clavier.nextInt();
             System.out.print("| ");
             d = clavier.nextInt();

 			if(a!=rdm1 && b!=rdm2 && c!=rdm3 && d!=rdm4) {
 				System.out.println("-----------");
 				System.out.println("| * * * * |");
 				System.out.println("-----------");
 			}
 			else if(a!=rdm1 && b!=rdm2 && c!=rdm3 && d==rdm4) {
 				System.out.println("-----------");
 				System.out.println("| * * * O |");
 				System.out.println("-----------");
 			}
             else if(a != rdm1 && b != rdm2 && c == rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| * * O * |");
                 System.out.println("-----------");
             }
             else if (a != rdm1 && b != rdm2 && c ==rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| * * O O |");
                 System.out.println("-----------");
             }
             else if(a != rdm1 && b == rdm2 && c != rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| * O * * |");
                 System.out.println("-----------");
             }
             else if(a != rdm1 && b == rdm2 && c != rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| * O * O |");
                 System.out.println("-----------");
             }
             else if(a != rdm1 && b == rdm2 && c == rdm3 && d !=rdm4) {
             	System.out.println("-----------");
                 System.out.println("| * O O * |");
                 System.out.println("-----------");
             }
             else if(a != rdm1 && b == rdm2 && c == rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| * O O O |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b != rdm2 && c != rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O * * * |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b != rdm2 && c != rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O * * O |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b != rdm2 && c == rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O * O * |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b != rdm2 && c ==rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O * O O |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b == rdm2 && c != rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O O * * |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b == rdm2 && c != rdm3 && d ==rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O O * O |");
                 System.out.println("-----------");
             }
             else if(a == rdm1 && b == rdm2 && c == rdm3 && d !=rdm4) {
                 System.out.println("-----------");
                 System.out.println("| O O O * |");
                 System.out.println("-----------");
             }
 						else {
             	   System.out.println("------------------------");
                 System.out.println("|       O O O O        |");
                 System.out.println("| Reponse : " + a+" "+b+" "+c+ " "+d + "    |");
                 System.out.println("------------------------");

 			}
 		}
 	}
 }
