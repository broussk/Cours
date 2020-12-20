package mediatheque1;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import org.json.JSONObject;

public class testLivre {

	public static void main(String[] args) {
		Auteur auteur1 = new Auteur("Cyril RABAT", "15/05/1980");
		Livre livre1 = new Livre("L'ile de l'oublie", auteur1);
		Auteur auteur2 = new Auteur("Nathan TONNELLE", "15/05/2000");
		Livre livre2 = new Livre("L'ile de l'etudiant", auteur2);
		Auteur auteur3 = new Auteur("Florent NOLOT", "15/05/1975");
		Livre livre3 = new Livre("L'ile du CTF", auteur3);
		Mediatheque mediatheque1 = new Mediatheque();
		
		String cheminDuFichier = "C:\\Users\\tonne\\Desktop\\L3-TP\\INFO503\\TP3\\json_Mediateque.txt";
		
		mediatheque1.ajouterLivre(livre1);
		mediatheque1.ajouterLivre(livre2);
		mediatheque1.ajouterLivre(livre3);

		System.out.println(livre1.toString());
		
		//s�rialisation JSON
		JSONObject jsonObjectLivre1 = new JSONObject(livre1);
		System.out.println(jsonObjectLivre1.toString());
		JSONObject jsonObjectMediateque1 = new JSONObject(mediatheque1);
		System.out.println(jsonObjectMediateque1.toString());
		System.out.println(auteur1.toJSON().toString());
		System.out.println(livre1.toJSON().toString());
		System.out.println(mediatheque1.toJSON().toString());
		
		File file = new File(cheminDuFichier);

		try {
			if (!file.exists())
				file.createNewFile();
			FileWriter writer = new FileWriter(file);
			writer.write(mediatheque1.toJSON().toString());
			writer.flush();
			writer.close();
		} catch (IOException e) {
			System.out.println("Erreur: impossible de cr�er le fichier '"
					+ cheminDuFichier + "'");
		}
	}

}
