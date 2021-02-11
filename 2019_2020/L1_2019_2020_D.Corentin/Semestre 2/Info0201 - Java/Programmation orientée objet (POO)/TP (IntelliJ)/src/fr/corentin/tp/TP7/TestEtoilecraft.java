package fr.corentin.tp.TP7;
import fr.corentin.tp.TP7.etoilecraft.*;

import java.util.Scanner;

public class TestEtoilecraft{
  public static void main (String[] args){
    Scanner clavier = new Scanner(System.in);


    int tour = 1;

    System.out.println("Choisissez la premiere unite : \n 1-Marine \n 2-Flammeur \n 3-Cuirasse");
    int choix1 = clavier.nextInt();
    IUnite u1 = createUnite(choix1);


    System.out.println("Choisissez la premiere unite : \n 1-Marine \n 2-Flammeur \n 3-Cuirasse");
    int choix2 = clavier.nextInt();
    IUnite u2 = createUnite(choix2);

    System.out.println("------------------------Infos sur les unites---------------------------" + "\n");
    System.out.println(u1.toString() + "\n");
    System.out.println(u2.toString() + "\n");

    while (u1.getPointsDeVie() > 0 && u2.getPointsDeVie() > 0){
      System.out.println("\n" + "-------------------------Tour " + tour + "---------------------------");

      u1.attaquer(u2);
      u2.attaquer(u1);

      System.out.println("Vie du " + nomUnite(u1) + " : " + (double) Math.round(u1.getPointsDeVie() * 100) / 100); //Arrondis les points de vie à deux décimales
      System.out.println("Vie du " + nomUnite(u2) + " : " + (double) Math.round(u2.getPointsDeVie() * 100) / 100); //Arrondis les points de vie à deux décimales

      tour++;
		}

    System.out.println("\n ------------------------Resultats---------------------------" + "\n");
    if (u1.getPointsDeVie() > 0){
  		System.out.println("L'unite " + nomUnite(u1) + " a gagner !");
  	}
  	else {
  		System.out.println("L'unite " + nomUnite(u1) + " a gagner !");
  	}

}

private static IUnite createUnite(int choix){
  IUnite uniteFinal = null;
  switch(choix){
    case 1: uniteFinal = new Marine();
     break;
    case 2: uniteFinal = new Flammeur();
     break;
    case 3: uniteFinal = new Cuirasse();
      break;
    default: System.out.println("Unite inconnue !");
  }
  return uniteFinal;
}

private static String nomUnite(IUnite ref){

  if (ref instanceof Flammeur) {
      return "Flammeur";
  } else if (ref instanceof Cuirasse){
      return "Cuirasse";
  }  else if (ref instanceof Marine){
      return "Marine";
  }
  return null;
}

}
