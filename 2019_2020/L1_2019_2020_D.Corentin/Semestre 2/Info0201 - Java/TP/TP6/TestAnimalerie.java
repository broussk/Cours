package fr.corentin.tp.TP6;

import fr.corentin.tp.TP6.animalerie.*;


public class TestAnimalerie{

  public static void main(String[] args){


    Chien chien = new Chien("Medor");
    AAnimal chat = new Chat("Azrael");
    Pigeon pigeon = new Pigeon("Hector");
    Abeille abeille = new Abeille("Maya");


    chien.afficher();
    chat.afficher();
    pigeon.afficher();
    pigeon.arracheAiles(pigeon);
    pigeon.afficher();
    abeille.afficher();
  }


}
