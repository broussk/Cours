package fr.corentin.tp.TP9;

import fr.corentin.tp.TP9.personne.Enseignant;
import fr.corentin.tp.TP9.personne.Etudiant;
import fr.corentin.tp.TP9.personne.Personne;
import fr.corentin.tp.TP9.personne.Vacataire;

import java.util.Scanner;

public class TestPersonne1 {
    public static Scanner clavier = new Scanner(System.in);

    /**
     * Création d'une personne depuis des informations saisies au clavier.
     * @return la personne créée
     */
    public static Personne creerPersonne() {
        String nom, prenom;

        System.out.println("Création d'une personne :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prénom            : ");
        prenom = clavier.nextLine();

        return new Personne(nom, prenom);
    }

    /**
     * Création d'un étudiant depuis des informations saisies au clavier.
     * @return l'étudiant créé
     */
    public static Etudiant creerEtudiant() {
        String nom, prenom;
        int numero;

        System.out.println("Création d'un étudiant :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prénom            : ");
        prenom = clavier.nextLine();
        System.out.print("Numéro d'étudiant : ");
        numero = clavier.nextInt();
        clavier.nextLine(); /* Vidage du tampon */

        return new Etudiant(nom, prenom, numero);
    }

    /**
     * Création d'un enseignant depuis des informations saisies au clavier.
     * @return l'enseignant créé
     */
    public static Enseignant creerEnseignant() {
        String nom, prenom;
        double salaire;

        System.out.println("Création d'un enseignant :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prénom            : ");
        prenom = clavier.nextLine();
        System.out.print("Salaire           : ");
        salaire = clavier.nextDouble();
        clavier.nextLine();

        return new Enseignant(nom, prenom, salaire);
    }

    /**
     * Création d'un vacataire depuis des informations saisies au clavier.
     * @return l'enseignant créé
     */
    public static Vacataire creerVacataire() {
        String nom, prenom, entreprise;
        double salaire;

        System.out.println("Création d'un vacataire :");
        System.out.print("Nom               : ");
        nom = clavier.nextLine();
        System.out.print("Prénom            : ");
        prenom = clavier.nextLine();
        System.out.print("Entreprise        : ");
        entreprise = clavier.nextLine();
        System.out.print("Salaire           : ");
        salaire = clavier.nextDouble();
        clavier.nextLine();

        return new Vacataire(nom, prenom, salaire, entreprise);
    }

    /**
     * Méthode principale.
     *
     * @param args les arguments
     */
    public static void main(String args[]) {

        //-----------Tableau 1-----------\\
        Personne[] tableau = new Personne[4];

        tableau[0] = creerPersonne();
        System.out.println();
        tableau[1] = creerEtudiant();
        System.out.println();
        tableau[2] = creerEnseignant();
        System.out.println();
        tableau[3] = creerVacataire();

        System.out.println("Resume Tableau 1: ");
        for (int i = 0; i < tableau.length; i++){
            System.out.println(tableau[i]);
        }

        System.out.println();

        //-----------Tableau 2-----------\\
        Personne[] tableau2 = new Personne[4];

        for (int y = 0; y < tableau.length; y++){
            if(tableau[y] instanceof Personne) {
                tableau2[y] = new Personne(tableau[y]);
            } else if (tableau[y] instanceof Etudiant){
                tableau2[y] = new Etudiant((Etudiant) tableau[y]);
            } else if (tableau[y] instanceof Enseignant){
                tableau2[y] = new Enseignant((Enseignant) tableau[y]);
            } else if (tableau[y] instanceof Vacataire){
                tableau2[y] = new Enseignant((Vacataire) tableau[y]);
            }
        }

        System.out.println("Resume Tabelau 2: ");
        for (int i = 0; i < tableau2.length; i++)
            System.out.println(tableau2[i]);

        System.out.println();

        System.out.println("Case 0 identique du T1 et T2 ? " + tableau2[0].equals(tableau[0]));
        System.out.println("Case 1 identique du T1 et T2 ? " + tableau2[1].equals(tableau[1]));
        System.out.println("Case 2 identique du T1 et T2 ? " + tableau2[2].equals(tableau[2]));
        System.out.println("Case 3 identique du T1 et T2 ? " + tableau2[3].equals(tableau[3]));

        System.out.println();

        //-----------Tableau 3-----------\\
        Personne tableau3[] = new Personne[4];

        tableau3[0] = tableau[0].clone();
        tableau3[1] = tableau[1].clone();
        tableau3[2] = tableau[2].clone();
        tableau3[3] = tableau[3].clone();

        System.out.println("Resume Tableau 3: ");
        for (int z = 0; z < tableau3.length; z++){
            System.out.println(tableau[z]);
        }

        System.out.println();
        System.out.println("Case 0 identique du T1 et T3 ? " + tableau3[0].equals(tableau[0]));
        System.out.println("Case 1 identique du T1 et T3 ? " + tableau3[1].equals(tableau[1]));
        System.out.println("Case 2 identique du T1 et T3 ? " + tableau3[2].equals(tableau[2]));
        System.out.println("Case 3 identique du T1 et T3 ? " + tableau3[3].equals(tableau[3]));

    }
}