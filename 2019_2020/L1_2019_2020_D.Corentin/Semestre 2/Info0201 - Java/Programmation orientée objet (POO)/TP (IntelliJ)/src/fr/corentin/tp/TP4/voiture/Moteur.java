package fr.corentin.tp.TP4.voiture;

import fr.corentin.tp.TP4.implement.IMoteur;

public class Moteur implements IMoteur {
    private String carburation;
    private double consommation;

    public Moteur() {
        this.carburation = "essence";
        this.consommation = 0.065;
    }

    public Moteur(final String carburation, final double consommation) {
        this.carburation = carburation;
        this.consommation = consommation;
    }

    public Moteur(final Moteur moteur) {
        this.carburation = moteur.carburation;
        this.consommation = moteur.consommation;
    }

    public String getCarburation() {
        return this.carburation;
    }

    public double getConsommation() {
        return this.consommation;
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        return this.carburation + " (" + this.consommation + "L/100km)";
    }
}
