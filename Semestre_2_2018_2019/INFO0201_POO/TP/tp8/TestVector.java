import java.util.Vector;
import etoilecraft.*;
public class TestVector{
	public static void main(String[] args){
		Vector<IUnite> vecteur = new Vector<IUnite>();
		Marine marine = new Marine();
		Flammeur flammeur = new Flammeur();
		Cuirrasse cuirrasse = new Cuirrasse();
		vecteur.add(marine);
		vecteur.add(flammeur);
		vecteur.add(cuirrasse);
		for(int i=0;i<vecteur.size();i++){
			System.out.println("-"+vecteur.get(i));
		}
		if(vecteur.remove(cuirrasse))
			System.out.println("Suppression de Cuirasse");
		for(int i=0;i<vecteur.size();i++){
			System.out.println("-"+vecteur.get(i));
		}
	}
}
