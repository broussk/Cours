import java.util.Scanner;
class TestDistributeur{
	public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int rep3;
		int rep;
		Senseo d = new Senseo();
		do{
			System.out.println("1 . Afficher le Distributeur");
			System.out.println("2 . Boire un cafe court");
			System.out.println("3 . Boire un cafe long");
			System.out.println("4 . Ajouter une dosette");
			System.out.println("5 . Remplir le reservoir");
			rep  = clavier.nextInt();
			switch (rep){
				case 1:
					d.afficher();
				break;
				case 2 :
					System.out.println("Inserez votre monaie : ");
					double m=clavier.nextDouble();
					System.out.println("Voici le reste : "+d.boireCafeCourt(m));
				break;
				case 3 :
					System.out.println("Inserez votre monaie : ");
					double mo=clavier.nextDouble();
					System.out.println("Voici le reste : "+d.boireCafeLong(mo));
				break;
				case 4 :
					System.out.println("Nombre de dosettes a mettre 1");
					d.ajouterDosettes(1);
				break;
				case 5 :
					System.out.println("Quantite d'eau a rajouter : ");
					double q=clavier.nextDouble();
					d.remplirReservoir(q);
				break;
			}
			System.out.println("voulez vous encore faire des opperations ? '1': OUI ou '0': NON");
			rep3=clavier.nextInt();
		}while(rep3==1);
	}
}