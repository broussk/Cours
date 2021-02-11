package fr.corentin.tp.TP5;

import fr.corentin.tp.TP5.animalerie.*;


import java.util.Scanner;

public class TestZoo {
    static  Scanner clavier = new Scanner(System.in);
    public static void main(String[] args) {

        Zoo z1 = saisirZoo();
        boolean continuer = true;

        while (continuer == true) {
            System.out.println("\nMenu du ZOO : \n"
                    + "-1 Ajout d'un animal\n"
                    + "-2 Supprimer un animal\n"
                    + "-3 Faire crier le zoo\n"
                    + "-4 Afficher le zoo\n"
                    + "-5 Sortir du zoo ");

            int menu = clavier.nextInt();

            switch (menu) {
                case 1:
                    System.out.println("Ajouter : \n-1 Chien \n-2 Chat ");
                    int c = clavier.nextInt();
                    if (c == 1) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter un Chien : ");
                        int x = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom au chien : ");
                        String nchien = clavier.nextLine();
                        Animal chien = new Chien(nchien);
                        z1.ajouterAnimal(chien, x);

                    } else if (c == 2) {
                        System.out.print("Indiquer le numero de la cage dans laquelle vous voulez ajouter un Chat : ");
                        int y = clavier.nextInt();
                        clavier.nextLine();
                        System.out.print("Donner un nom au chat : ");
                        String nchat = clavier.nextLine();
                        Animal chat = new Chat(nchat);
                        z1.ajouterAnimal(chat, y);
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
        int n = clavier.nextInt();
        Zoo z2 = new Zoo(n);
        return z2;
    }
}
