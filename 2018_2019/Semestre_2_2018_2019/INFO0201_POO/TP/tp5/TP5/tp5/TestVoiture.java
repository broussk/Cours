//import transport.*;
import transport.Moteur;
import transport.Reservoir;
import transport.VoitureProfonde;
import transport.VoitureSurface;
//import personne.*;
import personne.Personne;
class TestVoiture{
	public static void main (String[] args){
	//VoitureSurface
		System.out.println("Voiture Surface : ");
		Moteur m1= new Moteur();
		Moteur m2= new Moteur("Diesel",0.05);
		Reservoir r1= new Reservoir();
		Reservoir r2= new Reservoir(100);
		Personne p1= new Personne("Mamie","Monique",68);
		Personne p2= new Personne("Jack","Chloe",17);
		VoitureSurface v1= new VoitureSurface(m1,r1);
		VoitureSurface v2= new VoitureSurface(m2,r2);
		System.out.println("v3 est la copie surface de v2");
		VoitureSurface v3= new VoitureSurface(v2);
		v1.setConducteur(p2);
		v2.setConducteur(p1);
		System.out.println("Moteur voiture 1 : "+v1.getMoteur()+" Reservoir : "+v1.getReservoir());
		System.out.print("V2:");	v2.afficher();
		System.out.println("La voiture 1 a avancer de "+v1.avancer(10000000));
		System.out.println("La voiture 2 remis "+v2.faireLePlein()+"L d'essence.");
		System.out.println("la voiture 2 a avancer de "+v2.avancer(100)+"km.");
		System.out.println("Le reservoir de la voiture 2 est a "+v2.getContenuReservoir()+"L");
		System.out.println("Le reservoir de la voiture 3 est a "+v3.getContenuReservoir()+"L");
		v3.setConducteur(p1);
		System.out.print("V3:");	v3.afficher();
	//VoitureProfonde
		System.out.println("Voiture Pronfonde : ");
		Moteur m3= new Moteur();
		Moteur m4= new Moteur("Essence",0.08);
		Reservoir r3= new Reservoir();
		Reservoir r4= new Reservoir(115);
		Personne p3= new Personne("Papi","Jean",70);
		Personne p4= new Personne("Branche","Michael",15);
		VoitureProfonde v4= new VoitureProfonde(m3,r3);
		VoitureProfonde v5= new VoitureProfonde(m4,r4);
		System.out.println("v6 est la copie profonde de v5");
		VoitureProfonde v6= new VoitureProfonde(v5);
		v4.setConducteur(p4);
		v5.setConducteur(p3);
		System.out.println("Moteur voiture 1 : "+v4.getMoteur()+" Reservoir : "+v4.getReservoir());
		System.out.print("V5:");	v5.afficher();
		System.out.println("La voiture 1 a avancer de "+v4.avancer(10000000));
		System.out.println("La voiture 2 remis "+v5.faireLePlein()+"L d'essence.");
		System.out.println("la voiture 2 a avancer de "+v5.avancer(100)+"km.");
		System.out.println("Le reservoir de la voiture 2 est a "+v5.getContenuReservoir()+"L");
		System.out.println("Le reservoir de la voiture 3 est a "+v6.getContenuReservoir()+"L");
		v6.setConducteur(p3);
		System.out.print("V6:");	v6.afficher();
	}
}
