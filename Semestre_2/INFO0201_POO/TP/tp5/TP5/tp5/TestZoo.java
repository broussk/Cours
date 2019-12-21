import java.util.Scanner;
import animalerie.*;
public class TestZoo{
	public static void main (String[] args){
		Scanner clavier = new Scanner(System.in);
		int vote, nbC, nbPA, nCA, numA;
		String nomA="", message;
		Animal ajouterA;
		Zoo zoo;
		/*System.out.println("Ecrivez un message : ");
		message = clavier.nextLine();*/
		System.out.println("Nous allons creer votre parc ensemble");
		System.out.println("Entrez un nombre de cage entre 10 et 20 que vous voulez dans votre zoo :");
		nbC=clavier.nextInt();
		try{
			zoo = new Zoo(nbC);
		}catch(ArithmeticException e){
			System.out.println(e.getMessage());
			System.out.println("Votre zoo est cree avec le minimum de cages, soit 10.");
			zoo = new Zoo(10);
		}
		for(int i=100;i>0;i--){
			System.out.println();
			System.out.println("Il vous reste "+i+" commandes a faire");
			System.out.println();
			System.out.println("Veuillez entrez un entier correspondant a ce que vous voulez faire :");
			System.out.println("Attention, si vous voulez faire les commandes 1 ou 4, il faut remplir le zoo d'abbord");
			System.out.println("1 : afficher le zoo");
			System.out.println("2 : ajouter animal de votre choix (nom de votre choix)");
			System.out.println("3 : supprimer un animal");
			System.out.println("4 : faire crier tout les animaux");
			System.out.println("5 : voir un animal");
			vote=clavier.nextInt();
			
			switch (vote){
				case 1:
					System.out.println(zoo.toString());
				break;
				case 2:
					System.out.print("Nom de l'animal : ");
					nomA=string();				//probleme a cette ligne, passe a la ligen de code suivante quand nomA=clavier.nextLine(); est utilisé
					System.out.print("Nombre de patte : ");
					nbPA=clavier.nextInt();
					System.out.print("Numero de la cage ou ajouter cet animal : ");
					nCA=clavier.nextInt();
					ajouterA = new Animal(nomA,nbPA);
					zoo.ajouterAnimal(ajouterA,nCA);
				break;
				case 3:
					System.out.print("Numero de la cage ou l'animal doit etre supprime : ");
					nCA=clavier.nextInt();
					zoo.supprimerAnimal(nCA);
				break;
				case 4:
					zoo.faireCrier();
				break;
				case 5:
					System.out.print("Numero de la cage de l'animal que vous voulez voir : ");
					nCA=clavier.nextInt();
					System.out.println(zoo.getAnimal(nCA).toString());
				break;
				default: System.out.println("La commande que vous cherchez n'existe pas");
			}
		}
	}

	public static String string (){
		Scanner clavier = new Scanner(System.in);
		return clavier.nextLine();
	}
}
