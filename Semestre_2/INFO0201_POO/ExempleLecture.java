/***********
 * Exemple de lecture de fichier texte
 *
 * permet de lire un fichier dont le nom  (un objet String) est dans la variable nomFichier
 ***********/
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;

class ExempleLecture {

    public static void main (String [] args) { 
    	String nomFichier = "ex-fichier.txt"; // le fichier a lire
        String ligne;

		try {
	    	BufferedReader in = new BufferedReader(new FileReader(nomFichier));
	    	while ((ligne = in.readLine()) != null) {
				System.out.println(ligne); // affiche la ligne lue 
	    	}
	    	in.close();
		}catch (FileNotFoundException e) {
	    	System.out.println("Probleme de fichier avec " + nomFichier);
		}catch (IOException e) {
	    	System.out.println("Probleme de lecture : " + e.getMessage());
		}
    }
}