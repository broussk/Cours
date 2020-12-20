public class Place{
    private char rangee;
    private int numPlace;
    private boolean estVide;
    private Voiture voiture;

    public Place(char rangee, int numPlace) {
        this.rangee = rangee;
        this.numPlace = numPlace;
        this.estVide = false;
        this.voiture = null;
    }
    public Place(char rangee, int num, Voiture voiture) {
        this.rangee = rangee;
        this.numPlace = numPlace;
        this.voiture = voiture;
        this.estVide = true;
    }
    public Place(Place pl) {
        this.rangee = pl.rangee;
        this.numPlace = pl.numPlace;
        this.estVide = pl.estVide;
        this.voiture = pl.voiture;
    }

    public char getRangee() {return rangee;}
    public int getNumPlace() {return numPlace;}
    public boolean estvide() {return estVide;}
    public Voiture getVoiture() {return voiture;}

    public void setVoiture(Voiture voiture) {
        this.voiture = voiture;
        this.estVide = true;
    }

    public Voiture enleverVoiture() {
        if(!this.estVide) return null;

        Voiture voiture = this.getVoiture();
        this.voiture = null;
        this.estVide = false;
        return voiture;
    }

    @Override
    public String toString() {
        return "Place [rangee=" + rangee + ", num=" + numPlace + ", estVide=" + (this.estVide?(this.estVide+ " ; Voiture : " + this.voiture.toString() + "]"):(this.estVide + "]"));
    }
}