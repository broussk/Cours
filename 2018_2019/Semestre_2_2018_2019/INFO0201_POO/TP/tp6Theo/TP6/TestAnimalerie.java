import animalerie.*;
import java.util.Scanner;

public class TestAnimalerie{
	public static void main(String[] args){
		Scanner clavier=new Scanner(System.in);
		AAnimal[] animaux = new AAnimal[4];
		
		System.out.println("Creation de chien : quel est son nom ?");
		String n=clavier.nextLine();
		animaux[0]=new Chien(n);
		
		System.out.println("Creation de chat : quel est son nom ?");
		n=clavier.nextLine();
		animaux[1]=new Chat(n);
		
		System.out.println("Creation de pigeon : quel est son nom ?");
		n=clavier.nextLine();
		animaux[2]=new Pigeon(n);
		
		System.out.println("Creation d'abeille : quel est son nom ?");
		n=clavier.nextLine();
		animaux[3]=new Abeille(n);
		
		for(int i=0 ; i<animaux.length;i++){
			System.out.print(animaux[i].getNom()+" : ");
			animaux[i].crier();
			animaux[i].setNom("Bidule");
			animaux[i].afficher();
		}
	}
}