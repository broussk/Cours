import java.io.*;
import java.util.*;
import org.json.JSONObject;

public class GestionnaireUtilisateurs {
	
	private ArrayList<String> login = new ArrayList<String>();
	private ArrayList<String> mdp = new ArrayList<String>();
	private ArrayList<String> metier = new ArrayList<String>();
	
	public GestionnaireUtilisateurs(String nomFichier, String nomFichier2){
		try {
			File f = new File(nomFichier);
			Scanner sc = new Scanner(f);
			while(sc.hasNext()){
				String line = sc.nextLine();
				if((line.indexOf('{')!=0)&&(line.indexOf('}')!=0)) {
					String[] lignes = line.split(":");
					
					lignes[0] = lignes[0].replaceAll(" ", "");
					lignes[0] = lignes[0].replaceAll("\"", "");
					lignes[0] = lignes[0].replaceAll(",", "");
					System.out.println(lignes[0]);
					lignes[1] = lignes[1].replaceAll(" ", "");
					lignes[1] = lignes[1].replaceAll("\"", "");
					lignes[1] = lignes[1].replaceAll(",", "");
					System.out.println(lignes[1]);
					addLogin(lignes[0]);
					addMdp(lignes[1]);
				}
			}
			File f2 = new File(nomFichier2);
			Scanner sc2 = new Scanner(f2);
			while(sc2.hasNext()){
				String line = sc2.nextLine();
				if((line.indexOf('{')!=0)&&(line.indexOf('}')!=0)) {
					String[] lignes = line.split(":");
					
					lignes[0] = lignes[0].replaceAll(" ", "");
					lignes[0] = lignes[0].replaceAll("\"", "");
					lignes[0] = lignes[0].replaceAll(",", "");
					System.out.println(lignes[0]);
					addMetier(lignes[0]);
				}
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void addLogin(String e) {
		this.login.add(e);
	}

	public void addMdp(String e) {
		this.mdp.add(e);
	}
	
	public void addMetier(String e) {
		this.metier.add(e);
	}

	public ArrayList<String> getLogin() {
		return login;
	}

	public ArrayList<String> getMdp() {
		return mdp;
	}

	public ArrayList<String> getMetier() {
		return metier;
	}
	
	public boolean log(String login, String mdp) {
		boolean res = false;
		int compteur = 0;
		for(String e : this.getLogin()) {
		  	if(login==e && this.getMdp().get(compteur)==mdp) {
		  		res = true;
		  	};
		  	compteur++;
		}
		return res;
	}
	
}
