import animalerie.*;
import java.util.Scanner;

public class TestZoo{
  public static void main(String[] args){
    Scanner clavier=new Scanner(System.in);
    Zoo zoo = new Zoo();
    boolean ok=true;
    int chx=0;
    String continuer="o";
    int cage;
    while(ok==true){
      System.out.println("----------------------------------------------------------------");//54
      System.out.println("|                     Bienvenue au zoo !                       |");//23-18-23;
      System.out.println("----------------------------------------------------------------");//64
      System.out.println("| Entrez le numero de l'action a realiser:                     |");//64
      System.out.println("|                                                              |");//64
      System.out.println("| 1.Afficher le Zoo                2.Ajouter un animal         |");//64
      System.out.println("| 3.Supprimer un animal            4.Faire crier les animaux   |");//64
	  System.out.println("| 5.Obtenir le nombre de pattes    6.Obtenir le nombre d'ailes |");//64
	  System.out.println("| 7.Provoquer un desastre                                      |");//64
      System.out.println("----------------------------------------------------------------");//64
      chx=clavier.nextInt();
      clavier.nextLine();
      if(chx==1){ //Affichage

        System.out.println(zoo);

      }else if(chx==2){//Ajout d'animal

        String typeAnimal;
        AAnimal animal;
        String nom;

        //Sélection du nom de l'animal
        System.out.println("Quel est le nom de l'animal ?");
        nom=clavier.nextLine();

        //Sélection du type d'animal
        System.out.println("Quel animal voulez-vous ajouter ?(Chat/Chien/Pigeon/Abeille)");
        typeAnimal=clavier.nextLine();
        while(!typeAnimal.toLowerCase().equals("chien") && !typeAnimal.toLowerCase().equals("chat") && !typeAnimal.toLowerCase().equals("pigeon") && !typeAnimal.toLowerCase().equals("abeille")){
          System.out.println("Animal incorrect, ressaisir : ");
          typeAnimal=clavier.nextLine();
        }

        //Instanciation de l'animal
        if(typeAnimal.toLowerCase().equals("chien")){
          animal=new Chien(nom);
        }else if(typeAnimal.toLowerCase().equals("chat")){
          animal=new Chat(nom);
        }else if(typeAnimal.toLowerCase().equals("pigeon")){
          animal=new Pigeon(nom);
        }else{
          animal=new Abeille(nom);
        }

        //Sélection du numéro de cage
        System.out.println("Dans quel cage voulez-vous placer l'animal ? (numero de cage)");
        cage=clavier.nextInt();
        clavier.nextLine();
        while(cage<0){
          System.out.println("Entrez un numero de cage positif : ");
          cage=clavier.nextInt();
          clavier.nextLine();
        }

        //Ajout de l'animal
        zoo.ajouterAnimal(animal,cage);

      }else if(chx==3){//Suppression d'animal
        System.out.println("Supprimer l'animal de quelle cage ?(numero de cage)");
        cage=clavier.nextInt();
        clavier.nextLine();
        while(cage<0){
          System.out.println("Entrez un numero de cage positif : ");
          cage=clavier.nextInt();
          clavier.nextLine();
        }
        zoo.supprimerAnimal(cage);
      }else if(chx==4){ //Faire crier
        for(int i=0;i<zoo.getNbCages();i++){
          if(zoo.getAnimal(i)!=null){
            System.out.print(zoo.getAnimal(i).getClass().getName().substring(11)+" "+zoo.getAnimal(i).getNom()+" : ");
            zoo.getAnimal(i).crier();
          }
        }
	  }else if(chx==5){
		  System.out.println("Nombre de pattes : "+zoo.getNombrePattes());
	  }else if(chx==6){
		  System.out.println("Nombre d'ailes : "+zoo.getNombreAiles());
	  }else if(chx==7){
		  zoo.desastre();
      }else{ //Autre
        System.out.println("Aucune action n'est liee a ce numero");
      }

      //Continuation ?
      System.out.println("Voulez-vous continuer ? (O/N)");
      continuer=clavier.nextLine();
      if(continuer.toUpperCase().equals("N")) ok = false;
    }
  }
}
