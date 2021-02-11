package fr.corentin.tp.TP5.animalerie;

/**
 * Classe Zoo qui implément IZoo.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public class Zoo implements IZoo {

    /**
     * Attributs de la classe
     */
    private Animal[] cage;
    private int cagemin = 10;
    private int cagemax = 20;

    /**
     * Constructeur par defaut
     */
    public Zoo() {
        cage = new Animal[(int)((Math.random() * (cagemax + 1 - cagemin)) + cagemin)];
    }

    /**
     * Constructeur par initialistaion
     * @param nbr nombre de cage
     */
    public Zoo(int nbr) {
        if (nbr < 10 || nbr > 20) {
            cage = new Animal[20];
        } else {
            cage = new Animal[nbr];
        }
    }

    /**
     * Ajoute un animal dans une cage du zoo
     * @param a l'animal a ajouter
     * @param i le numero de la cage
     */
    public void ajouterAnimal(Animal a, int i) {
        cage[i] = a;
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
     * Supprime l'animal situe dans une cage
     * @param i le numero de la cage
     */
    public void supprimerAnimal(int i) {
        cage[i] = null;
    }

    /**
     * Recupere un animal dans une des cages du zoo
     * @param i le numero de la cage
     * @return l'animal present dans la cage
     */
    public Animal getAnimal(int i){
        return cage[i];
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
