package fr.corentin.tp.TP4;

import fr.corentin.tp.TP4.exceptions.AgeInvalidException;
import fr.corentin.tp.TP4.voiture.Moteur;
import fr.corentin.tp.TP4.voiture.Personne;
import fr.corentin.tp.TP4.voiture.Reservoir;
import fr.corentin.tp.TP4.voiture.VoitureSurface;

public class TestVoitureSurface{
  public static void main (String [] args) throws AgeInvalidException {
    Moteur m1 = new Moteur("Diesel", 6.5);
    Reservoir r1 = new Reservoir(80);
    Personne p1 = new Personne("Jean", "Bond", 23);
    Personne p2 = new Personne("Danielle","Jacques",16);
    Personne p3 = new Personne("Mamie", "Nova", 51);

    System.out.println("Ici nous testons la copie de surface. V2 est la copie de surface de V1\n ");

    System.out.println("V1 : ");
    VoitureSurface vs1 = new VoitureSurface(m1, r1);
    System.out.println ("La voiture a fait le plein de : " + vs1.faireLePlein() + "L de " + vs1.getMoteur().getCarburation());

    try{
      vs1.setConducteur(p2);
    } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }

    try{
      vs1.setConducteur(p1);
    } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }

    vs1.afficher();

    System.out.println("\n");

    System.out.print("V2 : ");
    VoitureSurface vs2 = new VoitureSurface(vs1);

    try{
      vs2.setConducteur(p3);
    } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }

    vs2.afficher();

    System.out.println("\n" );
    System.out.println("Distance parcourue par la V1 : " + vs1.avancer(15) +"km" );
    System.out.println("Réservoir V1 : " + vs1.getReservoir().getContenu() +"L" );
    System.out.println("Réservoir V2 : " + vs2.getReservoir().getContenu() +"L" );










  }
}
