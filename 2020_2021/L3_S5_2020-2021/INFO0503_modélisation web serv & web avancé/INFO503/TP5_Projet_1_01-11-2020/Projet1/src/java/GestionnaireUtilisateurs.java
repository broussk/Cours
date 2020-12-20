import java.io.*;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.*;

public class GestionnaireUtilisateurs {
    private ArrayList<String> login = new ArrayList<String>();
    private ArrayList<String> mdp = new ArrayList<String>();
    private ArrayList<String> profession = new ArrayList<String>();

    public GestionnaireUtilisateurs(String nomFichier, String nomFichier2) {
        try {
            File f = new File(nomFichier);
            Scanner sc = new Scanner(f);
            File f2 = new File(nomFichier2);
            Scanner sc2 = new Scanner(f2);
            //String affichageConsole = "";

            while (sc.hasNext()) {
                String line = sc.nextLine();
                if ((line.indexOf('{') != 0) && (line.indexOf('}') != 0)) {
                    String[] lignes = line.split(":");

                    lignes[0] = lignes[0].replaceAll(" ", "").replaceAll("\"", "").replaceAll(",", "");
                    //affichageConsole += " pseudo : " + lignes[0]+ "\n";

                    lignes[1] = lignes[1].replaceAll(" ", "").replaceAll("\"", "").replaceAll(",", "");
                    //affichageConsole += " mdp : " + lignes[1] + "\n";

                    addLogin(lignes[0]);
                    addMdp(lignes[1]);
                }

                String line2 = sc2.nextLine();
                if ((line2.indexOf('{') != 0) && (line2.indexOf('}') != 0)) {
                    String[] lignes = line2.split(":");

                    lignes[0] = lignes[0].replaceAll(" ", "").replaceAll("\"", "").replaceAll(",", "");
                    //affichageConsole += " profession : " + lignes[0] + "\n";

                    addProfession(lignes[0]);
                }

            }
            sc.close();
            sc2.close();
            //System.out.println(affichageConsole);
        } catch (Exception e) {
            System.out.println("Echec de l'ouverture et de la récupération des données des fichiers.\n");
            e.printStackTrace();
        }
    }

    public ArrayList<String> getLogin() {return this.login;}
    public ArrayList<String> getMdp() {return this.mdp;}
    public ArrayList<String> getProfession() {return this.profession;}

    public void addLogin(String login) {this.login.add(login);}
    public void addMdp(String mdp) {this.mdp.add(mdp);}
    public void addProfession(String profession) {this.profession.add(profession);}

    public boolean log(String login, String mdp) {
        mdp = encodeSha256(mdp);
        boolean res = false;
        int compteur = 0;
        for (String e : this.getLogin()) {
            if(login.equalsIgnoreCase(e) && this.mdp.get(compteur).equalsIgnoreCase(mdp)){
                res = true;
                System.out.println("Connecté : \t login = " + login + "\t mdp = " + mdp);
            }
            compteur++;
        }
        return res;
    }

    private String encodeSha256(String s) {
        String returnString = "";
        MessageDigest md;
        try {
            md = MessageDigest.getInstance("SHA-256");
            byte[]hashInBytes = md.digest(s.getBytes(StandardCharsets.UTF_8));

            StringBuilder sb = new StringBuilder();
            for (byte b : hashInBytes) {
                sb.append(String.format("%02x", b));
            }
            returnString = sb.toString();

        } catch (NoSuchAlgorithmException e) {
            System.out.println("Echec MessageDisgest.getInstance(SHA-256) \t" + e);
        }
        return returnString;
    }
	
}
