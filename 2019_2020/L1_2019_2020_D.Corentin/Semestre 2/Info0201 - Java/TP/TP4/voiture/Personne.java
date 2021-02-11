package fr.corentin.tp.TP4.voiture;

import fr.corentin.tp.TP4.implement.IPersonne;

public class Personne implements IPersonne {
    private String nom;
    private String prenom;
    private int age;

    public Personne(final String nom, final String prenom) {
        this.nom = nom;
        this.prenom = prenom;
    }

    public Personne(final String nom, final String prenom, final int age) {
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
    }

    public String getNom() {
        return this.nom;
    }

    public String getPrenom() {
        return this.prenom;
    }

    public int getAge() {
        return this.age;
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        String s = this.nom + " " + this.prenom + " (" + this.age + " an";
        if (this.age > 1) {
            s += "s";
        }
        return s + ")";
    }
}
