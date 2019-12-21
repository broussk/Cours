import animalerie.*;
public class TestAnimalerie{
	public static void main(String[] args){
		Animal animal=new Animal("Bidule",8);
		Mammifere mammifere=new Mammifere("Bob");
		Chien chien=new Chien("Medor");
		Chat chat=new Chat("Azrael");
		animal.afficher();
		mammifere.afficher();
		chien.afficher();
		chat.afficher();
	}
}
