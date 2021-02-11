package fr.corentin.tp.TP1;


import java.util.Scanner;


public class TestDate{
  static Scanner cl = new Scanner(System.in);
  public static void main (String[] args){
    Date d1 = new Date();
    System.out.println("Entrez un jour: ");
    int jour = cl.nextInt();
    System.out.println("Entrez un mois: ");
    int mois = cl.nextInt();
    System.out.println("Entrez une annee: ");
    int annee = cl.nextInt();
    Date d2 = new Date(jour,mois,annee);
    System.out.println("Vous avez entre cette date: " + d2.toString());


    System.out.println("Le mois "+ d2.getMois() + " a: " + d2.nbJours() + " jours");
    System.out.println("L'annee "+ d2.getAnnee() + " est bissextile: " + d2.estBissextile());




    System.out.println(d1.getJour());
    System.out.println(d2.getAnnee());


    d1.setJour(13);
    d2.setAnnee(2089);

    System.out.println(d1.toString());
    d2.afficher();


  }
}
