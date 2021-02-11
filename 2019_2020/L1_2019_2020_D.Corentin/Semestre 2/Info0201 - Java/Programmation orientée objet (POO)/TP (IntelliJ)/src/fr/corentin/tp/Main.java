package fr.corentin.tp;

import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    public static void main (String [] args){

          boolean stop = true;

          while(stop) {
                System.out.println("-1/ Fahrenheit en Celsius \n-2/ Celsius en Fahrenheit \n-3/ Stop le pgrm");
                int choix = sc.nextInt();
                switch (choix){
                    case 1:
                        System.out.println("Saisie une température en Fahrenheit ");
                        double tmp = sc.nextDouble();
                        System.out.println("La température convertie est : " +  ((tmp - 32) * 5/9 ) + "°C");
                        break;
                    case 2:
                        System.out.println("Saisie une température en Celsius ");
                        double tmp1 = sc.nextDouble();
                        System.out.println("La température convertie est : " +  (((tmp1 * 9/5)) + 32 )+ "°C");
                        break;
                    case 3:
                        stop = false;
                        System.out.println("Au revoir");
                        break;
                    default:  System.out.println("Saisie incorrect !");
                }
            }
}
}
