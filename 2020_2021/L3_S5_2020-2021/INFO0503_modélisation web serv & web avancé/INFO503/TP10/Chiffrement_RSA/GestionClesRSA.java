import java.security.KeyFactory;
import java.security.PublicKey;
import java.security.PrivateKey;
import java.security.NoSuchAlgorithmException;

import java.security.spec.X509EncodedKeySpec;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.InvalidKeySpecException;

import java.io.IOException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.file.Files;

/**
 * Classe permettant de sauvegarder et charger des clés privées ou publiques depuis des fichiers.
 * @author Cyril Rabat
 */
public class GestionClesRSA {

    /**
     * Sauvegarde de la clé publique dans un fichier.
     * @param clePublique la clé publique
     * @param nomFichier le nom du fichier dans lequel sauvegarder la clé
     */
    public static void sauvegardeClePublique(PublicKey clePublique, String nomFichier) {
        X509EncodedKeySpec spec = new X509EncodedKeySpec(clePublique.getEncoded());
        try {
            FileOutputStream fos = new FileOutputStream(nomFichier);
            fos.write(spec.getEncoded());
            fos.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la sauvegarde de la clé : " + e);
            System.exit(0);
        }
    }

    /**
     * Sauvegarde de la clé privée dans un fichier.
     * @param clePublique la clé privée
     * @param nomFichier le nom du fichier dans lequel sauvegarder la clé
     */
    public static void sauvegardeClePrivee(PrivateKey clePrivee, String nomFichier) {
        PKCS8EncodedKeySpec spec = new PKCS8EncodedKeySpec(clePrivee.getEncoded());
        try {
            FileOutputStream fos = new FileOutputStream(nomFichier);
            fos.write(spec.getEncoded());
            fos.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la sauvegarde de la clé : " + e);
            System.exit(0);
        }
    }

    /**
     * Lecture d'une clé privée depuis un fichier.
     * @param nomFichier le nom du fichier contenant la clé privée
     * @return la clé privée
     */
    public static PrivateKey lectureClePrivee(String nomFichier) {
        PrivateKey clePrivee = null;
        try {
            File fichier = new File(nomFichier);
            byte[] donnees = Files.readAllBytes(fichier.toPath());
            PKCS8EncodedKeySpec spec = new PKCS8EncodedKeySpec(donnees);
            KeyFactory usine = KeyFactory.getInstance("RSA");
            clePrivee = usine.generatePrivate(spec);
        } catch(IOException e) {
             System.err.println("Erreur lors de la lecture de la clé : " + e);
             System.exit(0);
        } catch(NoSuchAlgorithmException e) {
            System.err.println("Algorithme RSA inconnu : " + e);
            System.exit(0);
        } catch(InvalidKeySpecException e) {
            System.err.println("Spécification incorrecte : " + e);
            System.exit(0);
        }
        
        return clePrivee;
    }

    /**
     * Lecture d'une clé publique depuis un fichier.
     * @param nomFichier le nom du fichier contenant la clé publique
     * @return la clé publique
     */
    public static PublicKey lectureClePublique(String nomFichier) {
        PublicKey clePublique = null;
        try {
            File fichier = new File(nomFichier);
            byte[] donnees = Files.readAllBytes(fichier.toPath());
            X509EncodedKeySpec spec = new X509EncodedKeySpec(donnees);
            KeyFactory usine = KeyFactory.getInstance("RSA");
            clePublique = usine.generatePublic(spec);
        } catch(IOException e) {
             System.err.println("Erreur lors de la lecture de la clé : " + e);
             System.exit(0);
        } catch(NoSuchAlgorithmException e) {
            System.err.println("Algorithme RSA inconnu : " + e);
            System.exit(0);
        } catch(InvalidKeySpecException e) {
            System.err.println("Spécification incorrecte : " + e);
            System.exit(0);
        }
        
        return clePublique;
    }

}