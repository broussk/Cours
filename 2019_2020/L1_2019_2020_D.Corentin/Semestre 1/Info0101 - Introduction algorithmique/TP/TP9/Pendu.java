
import java.util.Scanner;
class Pendu {
	private static Scanner cl = new Scanner(System.in);

	public static void main(String[] args) {
		char[] solution = initialiserSolution();
		char[] masque = creerMasque(solution.length);
		int nbEssais = 0;


		while(nbEssais<5 && estFini(masque)!=true){

			afficherEssais(nbEssais,masque);
			System.out.println("Entrez un caractere : ");
			String l = cl.nextLine();
			char car = l.charAt(0);
			if(!jouer(solution,masque,car)){
				nbEssais++;
				afficherEssais(nbEssais,masque);
			}
		}

		if(estFini(masque)==true){
			System.out.println("Bravo ! Vous avez remportez la partie. ;)");
		}else{
			System.out.println("Aie ! Vous avez perdu la partie. :|");
		}
		System.out.print("Le mot a deviner ete: " );
		afficher(solution);

	}

	public static boolean estValide(String mot){
		boolean valide =false;
		int taille = mot.length();
		char tab[] = new char[taille];

		for(int i=0; i<taille; i++){
			tab[i] = mot.charAt(i);
			if(tab[i] >= 'A' && tab[i] <= 'Z' && mot.length() >= 4){
				valide = true;
			} else {
				valide = false;
			}
		}
		return valide;
	}

	public static char[] convertir(String mot){
		int i;
		int j = 0;
		char[] t = new char[mot.length()];
		for(i=0;i<t.length;i++){
			t[i]= mot.charAt(j);
			j++;
		}
		return t;
	}

	public static char[] initialiserSolution(){
		System.out.print("Entrez le mot a deviner: ");
		String solution = cl.nextLine();
		while(estValide(solution)!=true){
			System.out.println("Le mot doit avoir au moins 4 caracteres, etre en majuscule, et ne comporter aucun accent.");
			solution = cl.nextLine();
		}
		return convertir(solution);
	}

	public static char[] creerMasque(int n){
		char[] t = new char[n];
		int i;
		for (i=0;i<t.length;i++) {
			t[i] = '-';
		}
		return t;
	}

	public static void afficher(char[] t){
		StringBuffer mot = new StringBuffer(t.length);
		int i;
		for(i=0;i<t.length;i++){
			char car = t[i];
			mot.append(car);
		}
		System.out.println(mot);
	}

	public static boolean jouer(char[] solution, char[] masque, char car){
		int i;
		boolean res = false;
		for(i=0;i<solution.length;i++){
			if (solution[i]==car) {
				res = true;
				masque[i] = car;
			}
		}
		return res;
	}

	public static void afficherEssais(int nbEssais, char[] masque){
		switch(nbEssais) {
		case 5: // La potence en entier et le pendu
			System.out.println(" /---\\\n | |\n | O\n | /|\\\n | / \\\n-^-");
		break;
		case 4: // La potence en entier
			System.out.println(" /---\\\n | |\n |\n |\n |\n-^-");
		break;
		case 3: // La potence sans la corde
			System.out.println(" /---\\\n |\n |\n |\n |\n-^-");
		break;
		case 2: // Le corps de la potence
			System.out.println("\n |\n |\n |\n |\n-^-");
		break;
		case 1: // Le pied de la potence
			System.out.println("\n\n\n\n\n-^-");
		break;
		}
		System.out.println("");
		System.out.println("Masque : ");
		afficher(masque);
	}

	public static boolean estFini(char[] masque){
		int i;
		int j=0;
		boolean res = false;
		for(i=0;i<masque.length;i++){
			if (masque[i]!='-') {
				j++;
			}
		}
		if (j==masque.length) {
			res = true;
		}
		return res;
	}

}
