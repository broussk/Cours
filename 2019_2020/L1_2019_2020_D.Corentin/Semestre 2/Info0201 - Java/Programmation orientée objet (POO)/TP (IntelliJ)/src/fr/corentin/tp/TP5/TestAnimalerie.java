package fr.corentin.tp.TP5;

import java.util.Scanner;
import fr.corentin.tp.TP5.animalerie.Animal;
import fr.corentin.tp.TP5.animalerie.Chat;
import fr.corentin.tp.TP5.animalerie.Chien;

public class TestAnimalerie{
  static Scanner clavier = new Scanner(System.in);
  public static void main(String[] args){
    Scanner clavier = new Scanner(System.in);

    Animal a1 = saisirAnimal();
    Chien c1 = new Chien("Léo");
    Animal chat = new Chat("Orphée");

    a1.afficher();
    c1.afficher();
    chat.afficher();
  }

  public static Animal saisirAnimal() {
    Scanner clavier = new Scanner(System.in);
    System.out.print("Saisir un nom: ");
    String n = clavier.nextLine();
    System.out.print("Saisir un nombre de pattes: ");
    int p = clavier.nextInt();
    Animal a2 = new Animal(n, p);
    return a2;
  }
}
