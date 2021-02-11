package fr.corentin.tp.TP2;

import fr.corentin.tp.TP2.point.IPoint;
import fr.corentin.tp.TP2.point.PointCartesien;
import fr.corentin.tp.TP2.point.PointPolaire;

import java.util.Scanner;

public class TestPoint {
    static Scanner cl = new Scanner(System.in);
    public static void main(String[] args){

        IPoint[] tab = new IPoint[5];
        for(int i = 0 ; i < tab.length ; i++) {
            System.out.println("Type de point: 1 - Cartesien / 2 - Polaire ?");
            int choix = cl.nextInt();
            if(choix == 1) {
                System.out.println("Saisir un nom :");
                String nomc = cl.nextLine();
                cl.nextLine();
                System.out.println("Saisir x :");
                double x = cl.nextDouble();
                System.out.println("Saisir y :");
                double y = cl.nextDouble();
                tab[i] = new PointCartesien(nomc,x,y);
            } else if(choix == 2) {
                System.out.println("Saisir un nom :");
                String nomp = cl.nextLine();
                cl.nextLine();
                System.out.println("Saisir distance :");
                double r = cl.nextDouble();
                System.out.println("Saisir angle :");
                double t = cl.nextDouble();
                tab[i] = new PointPolaire(nomp,r,t);
            }
        }

        for(int j = 0 ; j < tab.length ; j++) {
            System.out.println((j+1)+" - "+tab[j].toString());
            System.out.println("Distance a l'origine de "+(j+1)+" - "+tab[j].distanceALOrigine()+"\n");
        }
    }
}
