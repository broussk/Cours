package fr.corentin.tp.TP4.voiture;

import fr.corentin.tp.TP4.implement.IReservoir;

public class Reservoir implements IReservoir {
    private double capacite;
    private double contenu;

    public Reservoir() {
        this.capacite = 50.0;
        this.contenu = 0.0;
    }

    public Reservoir(final double capacite) {
        this.capacite = capacite;
        this.contenu = 0.0;
    }

    public Reservoir(final Reservoir reservoir) {
        this.capacite = reservoir.capacite;
        this.contenu = 0.0;
    }

    public double getCapacite() {
        return this.capacite;
    }

    public double getContenu() {
        return this.contenu;
    }

    public void remplir(final double n) {
        this.contenu += n;
        if (this.contenu > this.capacite) {
            this.contenu = this.capacite;
        }
    }

    public void vider(final double n) {
        if (this.contenu > n) {
            this.contenu -= n;
        }
        else {
            this.contenu = 0.0;
        }
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        return this.contenu + "/" + this.capacite;
    }
}
