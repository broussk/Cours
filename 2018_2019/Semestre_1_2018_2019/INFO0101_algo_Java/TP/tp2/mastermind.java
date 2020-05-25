import java.util.Scanner;

class mastermind {
 
    public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int a1, b1, c1, d1, compteur1=0;
		int a2, b2, c2, d2, compteur2=0;
		int a = (int)(Math.random()*10);
		int b = (int)(Math.random()*10);
		int c = (int)(Math.random()*10);
		int d = (int)(Math.random()*10);



		for (int essaies=1;essaies<10 ;essaies++ ) {
			System.out.println("Tour n*" +essaies);
			System.out.println("! entiers compris entre 0 et 9 !");
			System.out.print("Entrez un entier A: ");
			a1=clavier.nextInt();
			System.out.print("Entrez un entier B: ");
			b1=clavier.nextInt();
			System.out.print("Entrez un entier C: ");
			c1=clavier.nextInt();
			System.out.print("Entrez un entier D: ");
			d1=clavier.nextInt();

			compteur1=0;
			compteur2=0;

			if (a1==a) {
				compteur1++;
			}
			if (b1==b) {
				compteur1++;
			}
			if (c1==c) {
				compteur1++;
			}
			if (d1==d) {
				compteur1++;
			}

			System.out.println("Vous avez " +compteur1+ " chiffres bien places, donc il vous reste a trouver les "+(4-compteur1)+ " derniers chiffres.");

			System.out.println("! entiers compris entre 0 et 9 !");
			System.out.print("Entrez un entier A: ");
			a2=clavier.nextInt();
			System.out.print("Entrez un entier B: ");
			b2=clavier.nextInt();
			System.out.print("Entrez un entier C: ");
			c2=clavier.nextInt();
			System.out.print("Entrez un entier D: ");
			d2=clavier.nextInt();

			if (a2==a) {
				compteur2++;
			}
			if (b2==b) {
				compteur2++;
			}
			if (c2==c) {
				compteur2++;
			}
			if (d2==d) {
				compteur2++;
			}

			System.out.println("Vous avez " +compteur2+ " chiffres bien places, donc il vous reste a trouver les "+(4-compteur2)+ " derniers chiffres.");

			if (compteur1==4) {
				break;
			}
			if (compteur2==4) {
				break;
			}
		}

		if (compteur1==4 && compteur2==4) {
			System.out.println("Les joeurs sont a egalite");
		}
		else {
			if (compteur1==4){
			System.out.println("Le joueur 1 gagne ! Bravo !");
			}
			else{
				if (compteur2==4) {
					System.out.println("Le joueur 2 gagne ! Bravo !");
				}
				else {
					System.out.println("Les deux joueurs ont perdu :'(");
				}
			}
		}

    }
}