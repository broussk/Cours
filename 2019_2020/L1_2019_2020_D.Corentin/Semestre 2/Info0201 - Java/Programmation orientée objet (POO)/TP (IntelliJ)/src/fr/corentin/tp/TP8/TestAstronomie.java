package fr.corentin.tp.TP8;

import fr.corentin.tp.TP8.astronomie.Etoile;
import fr.corentin.tp.TP8.astronomie.Planete;
import fr.corentin.tp.TP8.astronomie.Satellite;

/**
 * Classe de test du package astronomie
 * VOUS NE DEVEZ RIEN MODIFIER A CETTE CLASSE
 * @author Cyril Rabat
 * @version 23/03/2016
 */

public class TestAstronomie {

    /**
     * Methode principale
     * @param args les arguments passés dans l'invite de commande
     */
    public static void main(String[] args) {
        Etoile soleil = new Etoile("Soleil", 1989100, 1392000, 576, 4.5);
      	Planete terre = new Planete("Terre", 5.9736, 12756, 24, soleil, 149597870, 365, "tellurique");
      	Satellite lune = new Satellite("Lune", 0.073477, 3474, 27, terre, 384400, 27);

      	soleil.afficher();
      	terre.afficher();
      	lune.afficher();

      	System.out.print(soleil);
      	if(soleil.toString().compareTo("Soleil, etoile") != 0)
      	    System.out.println(" (toString incorrect)");
      	else
      	    System.out.println(" (toString correct)");

      	System.out.print(terre);
      	if(terre.toString().compareTo("Terre, planete autour de Soleil") != 0)
      	    System.out.println(" (toString incorrect)");
      	else
      	    System.out.println(" (toString correct)");

      	System.out.print(lune);
      	if(lune.toString().compareTo("Lune, satellite de Terre, planete autour de Soleil") != 0)
      	    System.out.println(" (toString incorrect)");
      	else
      	    System.out.println(" (toString correct)");
          }

    }
