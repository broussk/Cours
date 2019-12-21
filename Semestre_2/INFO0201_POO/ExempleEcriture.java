/***********
 * Exemple d'ecriture de fichier texte
 *
 * Permet d'ecrire dans un fichier dont le nom  (un objet String) est dans la variable nomFichier
 * 
 * Si le fichier existe deja, le texte sera rajoute a la fin, sinon le fichier sera cree et le texte ajoute
 ***********/
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

class ExempleEcriture{
  public static void main(String[] args){
    String nomFichier = "nouveauFichier.txt"; // le fichier dans lequel on veut ecrire
    int entier = 5;
    try{
      BufferedWriter out = new BufferedWriter(new FileWriter(nomFichier, true));
     
      out.write("Ajout de texte dans un fichier\n");
      out.write("On peut mettre des entiers : ");
      out.write(entier);
      out.newLine();
      out.write("On peut mettre des instances de Object : ");
      out.write(new Integer(36));
      out.newLine();
      out.write("Attention c'est la description de l'objet qui est ecrite (methode toString)\n");
      out.close();
    }catch (IOException e) {
        System.out.println("Probleme de fichier : " + e.getMessage());
    }
  }
} 