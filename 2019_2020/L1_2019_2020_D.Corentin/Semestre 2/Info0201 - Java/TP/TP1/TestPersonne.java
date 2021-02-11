package fr.corentin.tp.TP1;

import java.util.Scanner;

public class TestPersonne{
    public static void main (String [] args){
        Personne p2 = new Personne ("DUPONT", "Jeannie", "Mme", 45, 60, 1.60);
        p2.afficher();
        p2.setNom("Lacroix");
        p2.setTaille(1.85);
        p2.afficher();

        Personne p3 = new Personne();

        Personne p1 = saisirPersonne();
        System.out.println();
        p1.afficher();

        System.out.println();
        p1.afficherIMC();
    }

    public static Personne saisirPersonne(){
        Scanner clavier = new Scanner (System.in);

        System.out.print ("Saisir le nom: ");
        String n = clavier.nextLine();

        System.out.print ("Saisir le prenom: ");
        String p = clavier.nextLine();

        System.out.print ("Saisir la civilite: 'Mr' ou 'Mme' ou 'Mlle': ");
        String c = clavier.nextLine();

        System.out.print ("Saisir l'age: ");
        int ag = clavier.nextInt();

        System.out.print ("Saisir la taille en metre (exemple: 1,80): ");
        double t = clavier.nextDouble();

        System.out.print ("Saisir le poids: ");
        int po = clavier.nextInt();

        Personne p1 = new Personne (n, p, c, ag, po, t);
        return p1;
    }
}