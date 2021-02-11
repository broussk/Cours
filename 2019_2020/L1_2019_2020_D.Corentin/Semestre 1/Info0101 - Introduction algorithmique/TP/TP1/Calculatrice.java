import java.util.Scanner;

class Calculatrice{

	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);

		System.out.println("Bienvenue dans une simple calculatrice :)");


		boolean continuer = true;

    while (continuer == true) {

			System.out.println("1 : Faire un calcul");
			System.out.println("2 : Quitter");
			int choix = clavier.nextInt();

			if (choix == 1){
				System.out.print("Entrer une premiere valeur : ");
				int a = clavier.nextInt();
				System.out.print("Entrer une deuxieme valeur : ");
				int b = clavier.nextInt();
				System.out.print("Choissisez une operation (+ ou - ou * ou /) :   ");
				char ope = clavier.next().charAt(0);

				int res = 0;

				if( b==0 && ope == '/' ){
					System.out.print("Vous ne pouvez pas diviser par 0. Resaisisez une valeur : ");
					b = clavier.nextInt();
				}

				switch(ope){
					case '+' : res = a+b;
					break;

					case '-' : res = a-b;
					break;

					case '*' : res = a*b;
					break;

					case '/' : res = a/b;
					break;

					default:
					 	System.out.print("Operation inconnu. Resaisisez une opération : ");
            ope = clavier.next().charAt(0);
				}

				System.out.println("Le resultat de " + a + ope + b + " est : " + res);
			} else {

				continuer = false;
			}

		}

}

}
