package fr.corentin.tp.TP9;

import fr.corentin.tp.TP9.personne.Enseignant;
import fr.corentin.tp.TP9.personne.Etudiant;
import fr.corentin.tp.TP9.personne.Personne;
import fr.corentin.tp.TP9.personne.Vacataire;

import java.lang.reflect.Method;
import java.util.Scanner;

public class TestPersonne2 {
    public static Scanner clavier = new Scanner(System.in);

    public static Personne creerPersonne() {
        String nom, prenom;

        System.out.println("Creation d'une personne :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prenom            : ");
        prenom = clavier.nextLine();

        return new Personne(nom, prenom);
    }

    public static Etudiant creerEtudiant() {
        String nom, prenom;
        int numero;

        System.out.println("Creation d'un etudiant :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prenom            : ");
        prenom = clavier.nextLine();
        System.out.print("Numero d'etudiant : ");
        numero = clavier.nextInt();
        clavier.nextLine(); /* Vidage du tampon */

        return new Etudiant(nom, prenom, numero);
    }

    public static Enseignant creerEnseignant() {
        String nom, prenom;
        double salaire;

        System.out.println("Creation d'un enseignant :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prenom            : ");
        prenom = clavier.nextLine();
        System.out.print("Salaire           : ");
        salaire = clavier.nextDouble();
        clavier.nextLine();

        return new Enseignant(nom, prenom, salaire);
    }

    public static Vacataire creerVacataire() {
        String nom, prenom, entreprise;
        double salaire;

        System.out.println("Creation d'un vacataire :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prenom            : ");
        prenom = clavier.nextLine();
        System.out.print("Salaire           : ");
        salaire = clavier.nextDouble();
        clavier.nextLine();
        System.out.print("Entreprise        : ");
        entreprise = clavier.nextLine();

        return new Vacataire(nom, prenom, salaire, entreprise);
    }

    public static void main(String args[]) {
        Personne p1, p2;
        Etudiant e1, e2;
        Enseignant s1;


        p1 = creerPersonne();
        System.out.println();
        p2 = new Personne(p1);
        e1 = creerEtudiant();
        System.out.println();
        e2 = new Etudiant(e1);
        s1 = creerEnseignant();

        p1 = creerPersonne();
        System.out.println(p1.getClass().getName());



        System.out.println("\nLa personne saisie : " + p1);
        System.out.println("La personne copiee : " + p2 + "\n");


        if(p1.equals(p2)){
            System.out.println("Les personnes " + p1 + " et " + p2 + " sont identiques.\n");
        }
        else{
            System.out.println("Les personnes " + p1 + " et " + p2 + " sont differentes.\n");
        }

        if(e1.equals(e2)){
            System.out.println("Les etudiants " + e1 + " et " + e2 + " sont identiques.\n");
        }
        else{
            System.out.println("Les etudiants " + e1 + " et " + e2 + " sont differents.\n");
        }

        if(e1.equals(p1)){
            System.out.println("La personne " + p1 + " et l'etudiant " + e1 + " sont identiques.\n");
        }
        else{
            System.out.println("La personne " + p1 + " et l'etudiant " + e1 + " sont differents.\n");
        }

        if(e1.equals(s1)){
            System.out.println("L'enseignant " + s1 + " et l'etudiant " + e1 + " sont identiques.\n");
        }
        else{
            System.out.println("L'enseignant " + s1 + " et l'etudiant " + e1 + " sont differents.\n");
        }


        //----------------Test de la symétrie----------------\\

        Personne personne = new Personne("Doe", "John");
        Etudiant etudiant = new Etudiant("Doe", "John", 2000);
        Enseignant enseignant = new Enseignant("Doe", "John", 2000.0);

        System.out.println("\nTest de la symétrie : ");
        if(personne.equals(etudiant) == etudiant.equals(personne)) {
            System.out.println("Top !");
        } else {
            System.out.println("Il faut revoir la symetrie.");
        }
        if(personne.equals(enseignant) == enseignant.equals(personne)) {
            System.out.println("Top !");
        } else{
            System.out.println("Il faut revoir la symetrie.");
        }

    }
}
