package fr.corentin.tp.TP10;

import fr.corentin.tp.TP10.personne.Enseignant;
import fr.corentin.tp.TP10.personne.Etudiant;
import fr.corentin.tp.TP10.personne.Personne;
import fr.corentin.tp.TP10.personne.Vacataire;

import java.io.*;
import java.util.Scanner;
import java.util.Vector;

/**
 * Classe de test pour les personnes.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class TestPersonne {
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
    public static void main(String args[]) throws IOException {

        Vector<Personne> tableau1 = new Vector<>();
        tableau1.add(creerPersonne());
        tableau1.add(creerEtudiant());
        tableau1.add(creerEnseignant());
        tableau1.add(creerVacataire());

        File f = new File("personnes.txt");
        if (!f.exists()) {
            try {
                f.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }


        //Sérialisation des objets dans le fichier txt
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(new File("personnes.txt")));
            for (int i = 0; i < tableau1.size(); i++){
                oos.writeObject(tableau1.get(i));
            }
            oos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }


        //Désérialisation des objets contenu dans le fichier txt
        Vector<Personne> tableau2 = new Vector<>();
        ObjectInputStream  ois = null;
        try {
            ois =  new ObjectInputStream(new FileInputStream("personnes.txt")) ;
            for (int y = 0 ; y < tableau1.size(); y++){
                tableau2.add((Personne) ois.readObject());
            }
        } catch (ClassNotFoundException | IOException e) {
            e.printStackTrace();
        } finally {
            ois.close();
        }

        //Test d'égalité pour voir si ce sont bien les mêmes
        if(tableau1.size() == tableau2.size()){
            for (int y = 0 ; y < tableau1.size(); y++){
                System.out.println("Case " + y + " identique du T1 et T2 ? " + tableau2.get(y).getClass().equals(tableau1.get(y).getClass()));
            }
        }
    }
}
