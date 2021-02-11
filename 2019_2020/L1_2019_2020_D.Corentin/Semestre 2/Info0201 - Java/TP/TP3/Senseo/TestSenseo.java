package fr.corentin.tp.TP3.Senseo;

import java.util.Scanner;

public class TestSenseo {

    static Scanner clavier = new Scanner (System.in);

    public static void main (String [] args){
        Senseo s1= new Senseo(1);
        int exit = 0;

        do{
            System.out.println();
            System.out.println("Faite Votre Choix parmis les numeros suivant:");
            System.out.println();
            System.out.println("1. Afficher le distributeur");
            System.out.println("2. Boire un cafe court");
            System.out.println("3. Boire un cafe long");
            System.out.println("4. Ajouter des dosettes");
            System.out.println("5. Remplir le reservoir");
            System.out.println("7. QUITTER");
            System.out.println();

            int choix = clavier.nextInt();
            switch (choix){
                case 1: s1.afficher();
                    break;
                case 2: System.out.println("Veuillez inserer "+s1.getPrixCourt()+" euros");
                    System.out.println("Combien d'euros inserez-vous dans la machine?");
                    double argent = clavier.nextDouble();
                    System.out.println("Votre monnaie sera de: "+s1.boireCafeCourt(argent)+" euros");

                    break;
                case 3: System.out.println("Veuillez inserer "+s1.getPrixLong()+" euros");
                    System.out.println("Combien d'euros inserez-vous dans la machine?");
                    double argent2 = clavier.nextDouble();
                    System.out.println("Votre monnaie sera de: "+s1.boireCafeLong(argent2)+" euros");
                    break;
                case 4: System.out.println("Combien de dosette voulez vous ajouter?");
                    int dosette = clavier.nextInt();
                    s1.ajouterDosettes(dosette);
                    System.out.println("Le nouveau nombre de dosette du distributeur est: "+s1.getNombreDosette());
                    break;
                case 5: System.out.println("Combien d'eau en mL voulez-vous ajouter?");
                    int eau = clavier.nextInt();
                    s1.remplirReservoir(eau);
                    System.out.println("La quantite d'eau dans le reservoir est de: "+s1.getQuantiteEau());
                    break;
                case 7: exit = 1;
                    break;
                default:
                    break;
            }
        }
        while (exit !=1);
    }
}
