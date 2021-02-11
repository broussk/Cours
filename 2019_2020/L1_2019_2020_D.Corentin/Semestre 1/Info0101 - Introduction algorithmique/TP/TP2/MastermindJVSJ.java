import java.util.Scanner;

class MastermindJVSJ {

	public static void main(String[] args) {

		Scanner clavier = new Scanner(System.in);
		int rdm1 = (int)(Math.random()*10);
		int rdm2 = (int)(Math.random()*10);
		int rdm3 = (int)(Math.random()*10);
		int rdm4 = (int)(Math.random()*10);

		int a=0;
		int b=0;
		int c=0;
		int d=0;
		int a1=0;
		int b1=0;
		int c1=0;
		int d1=0;

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


		while(a!=rdm1 || b!=rdm2 || c!=rdm3 || d!=rdm4 && a1!=rdm1 || b1!=rdm2 || c1!=rdm3 || d1!=rdm4) {
			System.out.println("------------");
			System.out.println("| Joueur 1 |");
			System.out.println("------------");
			System.out.print("| ");
			a = clavier.nextInt();
			System.out.print("| ");
			b = clavier.nextInt();
			System.out.print("| ");
			c = clavier.nextInt();
			System.out.print("| ");
			d = clavier.nextInt();
			System.out.println("------------");
			System.out.println("| Joueur 2 |");
			System.out.println("------------");
			System.out.print("| ");
			a1 = clavier.nextInt();
			System.out.print("| ");
			b1 = clavier.nextInt();
			System.out.print("| ");
			c1 = clavier.nextInt();
			System.out.print("| ");
			d1 = clavier.nextInt();


			if(a!=rdm1 && b!=rdm2 && c!=rdm3 && d!=rdm4) {

				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * * * * |");
				System.out.println("-----------");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * * * * |");
				System.out.println("-----------");
			}


			else if(a!=rdm1 && b!=rdm2 && c!=rdm3 && d==rdm4 || a1!=rdm1 && b1!=rdm2 && c1!=rdm3 && d1==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * * * O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * * * O |");
				System.out.println("-----------");
			}
			else if(a != rdm1 && b != rdm2 && c == rdm3 && d !=rdm4 || a1!= rdm1 && b1!= rdm2 && c1== rdm3 && d1!=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * * O * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * * O * |");
				System.out.println("-----------");
			}
			else if (a != rdm1 && b != rdm2 && c ==rdm3 && d ==rdm4 || a1!= rdm1 && b1!= rdm2 && c1==rdm3 && d1==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * * O O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * * O O |");
				System.out.println("-----------");
			}
			else if(a != rdm1 && b == rdm2 && c != rdm3 && d !=rdm4 || a1!= rdm1 && b1== rdm2 && c1!= rdm3 && d1!=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * O * * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * O * * |");
				System.out.println("-----------");
			}
			else if(a != rdm1 && b == rdm2 && c != rdm3 && d ==rdm4 || a1!= rdm1 && b1== rdm2 && c1!= rdm3 && d1==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * O * O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * O * O |");
				System.out.println("-----------");
			}
			else if(a != rdm1 && b == rdm2 && c == rdm3 && d !=rdm4 || a1!= rdm1 && b1== rdm2 && c1== rdm3 && d1!=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * O O * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * O O * |");
				System.out.println("-----------");
			}
			else if(a != rdm1 && b == rdm2 && c == rdm3 && d ==rdm4 || a1!= rdm1 && b1 == rdm2 && c1 == rdm3 && d1 ==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| * O O O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| * O O O |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b != rdm2 && c != rdm3 && d !=rdm4 || a1 == rdm1 && b1 != rdm2 && c1 != rdm3 && d1 !=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O * * * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O * * * |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b != rdm2 && c != rdm3 && d ==rdm4 || a1 == rdm1 && b1 != rdm2 && c1 != rdm3 && d1 ==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O * * O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O * * O |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b != rdm2 && c == rdm3 && d !=rdm4 || a1 == rdm1 && b1 != rdm2 && c1 == rdm3 && d1 !=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O * O * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O * O * |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b != rdm2 && c ==rdm3 && d ==rdm4 || a1 == rdm1 && b1 != rdm2 && c1 ==rdm3 && d1 ==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O * O O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O * O O |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b == rdm2 && c != rdm3 && d !=rdm4 || a1 == rdm1 && b1 == rdm2 && c1 != rdm3 && d1 !=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O O * * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O O * * |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b == rdm2 && c != rdm3 && d ==rdm4 || a1 == rdm1 && b1 == rdm2 && c1 != rdm3 && d1 ==rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O O * O |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O O * O |");
				System.out.println("-----------");
			}
			else if(a == rdm1 && b == rdm2 && c == rdm3 && d !=rdm4 || a1 == rdm1 && b1 == rdm2 && c1 == rdm3 && d1 !=rdm4) {
				System.out.println("-----------");
				System.out.println("|Joueur--1|");
				System.out.println("| O O O * |");
				System.out.println("-----------");
				System.out.println(" ");
				System.out.println("-----------");
				System.out.println("|Joueur--2|");
				System.out.println("| O O O * |");
				System.out.println("-----------");
			}else if(a == rdm1 && b == rdm2 && c == rdm3 && d == rdm4 || a1 == rdm1 && b1 == rdm2 && c1 == rdm3 && d1 == rdm4) {
				System.out.println("------------------------");
				System.out.println("|       Egalite        |");
				System.out.println("|       O O O O        |");
				System.out.println("| Reponse : " + a+" "+b+" "+c+ " "+d + "    |");
				System.out.println("------------------------");
			}else if(a == rdm1 && b == rdm2 && c == rdm3 && d == rdm4) {
				System.out.println("------------------------");
				System.out.println("|    Bravo joueur 1    |");
				System.out.println("|       O O O O        |");
				System.out.println("| Reponse : " + a+" "+b+" "+c+ " "+d + "    |");
				System.out.println("------------------------");
			}else if(a1 == rdm1 && b1 == rdm2 && c1 == rdm3 && d1 == rdm4) {
				System.out.println("------------------------");
				System.out.println("|    Bravo joueur 2    |");
				System.out.println("|       O O O O        |");
				System.out.println("| Reponse : " + a+" "+b+" "+c+ " "+d + "    |");
				System.out.println("------------------------");
			}
		}
	}
}
