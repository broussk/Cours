package fr.corentin.tp.TP6.animalerie;

/**
 * Classe Zoo qui implément IZoo.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 12/03/2020
 */

public class Zoo implements IZoo {

    /**
     * Attributs de la classe
     */
    private AAnimal[] cage;
    private int cagemin = 10;
    private int cagemax = 20;


    /**
     * Constructeur par defaut
     */
    public Zoo() {
        cage = new AAnimal[(int)((Math.random() * (cagemax + 1 - cagemin)) + cagemin)];
    }


    /**
     * Constructeur par initialistaion
     * @param nbr nombre de cage
     */
    public Zoo(int nbr) {
        if (nbr < 10 || nbr > 20) {
            cage = new AAnimal[20];
        } else {
            cage = new AAnimal[nbr];
        }
    }


    /**
     * Ajoute un animal dans une cage du zoo
     * @param a l'animal a ajouter
     * @param i le numero de la cage
     */
    public void ajouterAnimal(AAnimal a, int i) {
        if(getAnimal(i) != null ) {
                  cage[i] = a;
        }
    }


    /**
     * Fait crier tous les animaux du zoo
     */
    public void faireCrier() {
        for (int i = 0; i < cage.length; i++) {
            if (cage[i] != null) {
                System.out.print("Cage "+i + " : ");
                cage[i].crier();
            }
        }
    }


    /**
     * Supprime l'animal situé dans une cage
     * @param i le numéro de la cage
     */
    public void supprimerAnimal(int i) {
        cage[i] = null;
    }


    /**
     * Recupère un animal dans une des cages du zoo
     * @param i le numero de la cage
     * @return l'animal présent dans la cage
     */
    public AAnimal getAnimal(int i){
        return cage[i];
    }


    /**
     * Recupere le nombre totale de pattes dans le zoo.
     * @return nombre totale de pattes
     */
    public int getNombrePattes() {
        int nbrtotalpattes = 0;
        for (int i = 0; i < cage.length; i++) {
            if (cage[i] != null) {
                nbrtotalpattes += cage[i].getNbPattes();
            }
        }
        return nbrtotalpattes;
    }


    /**
     * Recupere le nombre totale d'ailes' dans le zoo.
     * @return nombre totale d'aiiles
     */
    public int getNombreAiles() {
        int nbrtotalailes = 0;
        for (int i = 0; i < cage.length; i++) {
            if (cage[i] != null) {
                nbrtotalailes += cage[i].getNbAiles();
            }
        }
        return nbrtotalailes;
    }


    /**
     * Permet de retirer aléatoirement a un animal choisit aleatoirement 1 patte ou 1 aile
     */
    public void desastre() {
        int rcase = (int)(Math.random() * cage.length);
        int random = (int)(Math.random() * 2);
        AAnimal cagerandom = cage[rcase];

        while (cagerandom == null) {
            rcase = (int)(Math.random() * cage.length);
            cagerandom = cage[rcase];
        }
        if (random == 0) {
            cagerandom.arrachePatte(getAnimal(rcase));
            cagerandom.crier();
        } else if (random == 1) {
            if (cage[rcase].getNbAiles() == 0) {
                cagerandom.arrachePatte(getAnimal(rcase));
                cagerandom.crier();

            } else {
                cagerandom.arracheAiles(getAnimal(rcase));
                cagerandom.crier();
            }
        }
    }

    /**
     * Permet de vieller tous les animaux du zoo de 1 ans .
     * @return si l'anaimal est mort ou pas de vieillesse.
     */

    public boolean vieillirzoo() {
        boolean vivant = true;
        for (int i = 0; i < cage.length; i++) {
            if (cage[i] != null) {
                if (cage[i].getEsperance() >= cage[i].getAge()) {
                    cage[i].vieillir();
                } else {
                    double chance = Math.random();
                    if (chance < 0.5) {
                        cage[i].vieillir();
                    } else {
                        vivant = false;
                        System.out.println("Dans la cage " + i + " , l'animal est mort de vieillesse ");
                        supprimerAnimal(i);
                    }
                }
            }
        }
        return vivant;
    }


    /**
     * Convertit tout le zoo en chaine de caracteres
     * @return une chaine de caracteres
     */
    public String toString() {
        String snbrcage = "Le zoo contient " + cage.length + " cages :";
        String zoo = "";
        System.out.println(snbrcage);
        for (int i = 0; i < cage.length; i++) {
            if (cage[i] != null) {
                zoo = cage[i].toString();
                System.out.println(" - Cage " + i + " : " + zoo);
            }
        }
        return zoo;
    }
}
