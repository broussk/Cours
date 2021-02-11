package fr.corentin.tp.TP4;

import fr.corentin.tp.TP4.exceptions.AgeInvalidException;
import fr.corentin.tp.TP4.voiture.Moteur;
import fr.corentin.tp.TP4.voiture.Personne;
import fr.corentin.tp.TP4.voiture.Reservoir;
import fr.corentin.tp.TP4.voiture.VoitureProfonde;

public class  TestVoitureProfonde{
  public static void main(String[] args){
    Moteur m1 = new Moteur("Diesel", 6.5);
    Reservoir r1 = new Reservoir(80);
    Personne p1 = new Personne("Jean", "Bond", 23);
    Personne p2 = new Personne("Danielle","Jacques",16);
    Personne p3 = new Personne("Mamie", "Nova", 51);

    System.out.println("Ici nous testons la copie profonde. V2 est la copie profonde de V1 \n");

    System.out.println("V1 : ");
    VoitureProfonde vp1 = new VoitureProfonde(m1, r1);
    System.out.println("La voiture a fait le plein de : " + vp1.faireLePlein() + "L de " + vp1.getMoteur().getCarburation());

    try{
        vp1.setConducteur(p2);
    } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }

    try{
      vp1.setConducteur(p1);
    } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }


    vp1.afficher();

    System.out.println("\n");

    System.out.print("V2 : ");
    VoitureProfonde vp2 = new VoitureProfonde(vp1);

    try{
      vp2.setConducteur(p3);
     } catch (AgeInvalidException e ){
      System.out.println(e.getMessage());
    }

    vp2.afficher();

    System.out.println("\n" );
    System.out.println("Distance parcourue par la V1 : " + vp1.avancer(15) +"km" );
    System.out.println("Réservoir V1 : " + vp1.getReservoir().getContenu() +"L" );
    System.out.println("Réservoir V2 : " + vp2.getReservoir().getContenu() +"L" );




  }
}
