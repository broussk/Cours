package fr.corentin.tp.TP3.Kawa;

import fr.corentin.tp.TP3.Kawa.Distributeur;

import java.util.Scanner;

public class TestDistributeur {

  static Scanner clavier = new Scanner(System.in);

  public static void main(String[] args) {
    Distributeur d1 = new Distributeur(10, 2.0);
    int exit = 0;

    do {
      System.out.println();
      System.out.println("Faite Votre Choix parmis les numeros suivant:");
      System.out.println();
      System.out.println("1. Afficher le distributeur");
      System.out.println("2. Boire un cafe court");
      System.out.println("3. Boire un cafe long");
      System.out.println("4. Ajouter des dosettes");
      System.out.println("5. Remplir le reservoir");
      System.out.println("6. Recuperer, modifier ou augmenter les prix");
      System.out.println("7. QUITTER");
      System.out.println();

      int choix = clavier.nextInt();
      switch (choix) {
        case 1:
          d1.afficher();
          break;

        case 2:
          System.out.println("Veuillez inserer " + d1.getPrixCourt() + " euros");
          System.out.println("Combien d'euros inserez-vous dans la machine?");
          double argent = clavier.nextDouble();
          System.out.println("Votre monnaie sera de: " + d1.boireCafeCourt(argent) + " euros");
          break;

        case 3:
          System.out.println("Veuillez inserer " + d1.getPrixLong() + " euros");
          System.out.println("Combien d'euros inserez-vous dans la machine?");
          double argent2 = clavier.nextDouble();
          System.out.println("Votre monnaie sera de: " + d1.boireCafeLong(argent2) + " euros");
          break;

        case 4:
          System.out.println("Combien de dosette voulez vous ajouter?");
          int dosette = clavier.nextInt();
          d1.ajouterDosettes(dosette);
          System.out.println("Le nouveau nombre de dosette du distributeur est: " + d1.getNbrDose());
          break;

        case 5:
          System.out.println("Combien d'eau en mL voulez-vous ajouter?");
          int eau = clavier.nextInt();
          d1.remplirReservoir(eau);
          System.out.println("La quantite d'eau dans le reservoir est de: " + d1.getReservoir());
          break;

        case 6:
          System.out.println();
          System.out.println("Que voulez vous faire?");
          System.out.println("1. Recuperer prix des cafes");
          System.out.println("2. Modifier prix des cafes");
          System.out.println("3. Augmenter prix des cafes");
          int choix2 = clavier.nextInt();
            switch (choix2) {

              case 1:
                System.out.println();
                System.out.println("Prix du cafe court: " + d1.getPrixCourt() + " euros");
                System.out.println("Prix du cafe long: " + d1.getPrixLong() + " euros");
                break;

              case 2:
                System.out.println();
                System.out.println("Quel cafe voulez vous modifier: 'c' pour court et 'l' pour long");
                clavier.nextLine();
                String choix3 = clavier.nextLine();
                if (choix3.charAt(0) == 'c') {
                  System.out.println("Saisir nouveau prix en euro");
                  double choix4 = clavier.nextDouble();
                  d1.setPrixCourt(choix4);
                }
                if (choix3.charAt(0) == 'l') {
                  System.out.println("Saisir nouveau prix en euro");
                  double choix4 = clavier.nextDouble();
                  d1.setPrixLong(choix4);
                }
                break;

              case 3:
                System.out.println();
                System.out.println("Saisir pourcentage d'augmentation");
                double choix5 = clavier.nextDouble();
                d1.augmenter(choix5);
                break;
            }

        break;

        case 7:
          exit = 1;
          break;

        default:
          break;
      }
    }
    while (exit != 1);
  }
}
