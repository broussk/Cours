package fr.corentin.tp.TP6;


import fr.corentin.tp.TP6.animalerie.*;

import java.util.Scanner;

public class TestZoo {
    static  Scanner clavier = new Scanner(System.in);
    public static void main(String[] args) {

        Zoo z1 = saisirZoo();
        boolean continuer = true;

        while (continuer == true) {
            System.out.println("\nMenu du ZOO : \n" +
                " -1 Ajout d'un animal.\n" +
                " -2 Supprimer un animal.\n" +
                " -3 Faire crier le zoo.\n" +
                " -4 Afficher le zoo.\n" +
                " -5 Compter le nombre de pattes et d'ailes du zoo.\n" +
                " -6 Arracher pattes ou aile d'une cage aleatoire. (Désastre)\n" +
                " -7 Faire vieillir d'un an tout les animaux.\n" +
                " -8 Sortir du zoo.\n");

            int menu = clavier.nextInt();

            switch (menu) {
                case 1:
                    System.out.println("Ajouter : \n-1 Chien \n-2 Chat \n-3 Pigeon \n-4 Abeille ");
                    int c = clavier.nextInt();
                    if (c == 1) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter un Chien : ");
                        int x = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom au chien : ");
                        String nchien = clavier.nextLine();
                        AAnimal chien = new Chien(nchien);
                        z1.ajouterAnimal(chien, x);

                    } else if (c == 2) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter un Chat : ");
                        int y = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom au chat : ");
                        String nchat = clavier.nextLine();
                        AAnimal chat = new Chat(nchat);
                        z1.ajouterAnimal(chat, y);
                    } else if (c == 3) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter un Pigeon : ");
                        int y = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom au pigeon : ");
                        String npig = clavier.nextLine();
                        AAnimal pigeon = new Pigeon(npig);
                        z1.ajouterAnimal(pigeon, y);
                    } else if (c == 4) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter une Abeille : ");
                        int y = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom à l'abeille : ");
                        String nab = clavier.nextLine();
                        AAnimal ab = new Abeille(nab);
                        z1.ajouterAnimal(ab, y);
                    }

                    break;
                case 2:
                    System.out.print("Indiquer le numero de la cage dans laquelle vous voulez supprimer l'animal : ");
                    int spr = clavier.nextInt();
                    clavier.nextLine();
                    System.out.print("Vous avez supprimer : " + z1.getAnimal(spr) + " de la cage numero : " + spr);
                    z1.supprimerAnimal(spr);

                    break;

                    case 3:
                        z1.faireCrier();
                        break;
                    case 4:
                        System.out.println(z1.toString());
                        break;
                    case 5:
                        System.out.println("Pattes : " + z1.getNombrePattes() + "\nAiles : " + z1.getNombreAiles());
                        break;
                    case 6:
                        z1.desastre();
                        break;
                    case 7:
                        z1.vieillirzoo();
                        System.out.print("Les animaux ont viellit d'un an.");
                        break;
                    case 8:
                        continuer = false;
                        break;
            }
        }
    }

    /**
     * Crée un zoo.
     * @return le zoo
     */
    public static Zoo saisirZoo() {
        Scanner clavier = new Scanner(System.in);
        System.out.print("Saisir un nombre de cages entre 10 et 20 : ");
        return new Zoo(clavier.nextInt());
    }
}
