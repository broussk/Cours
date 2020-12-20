import java.security.PrivateKey;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.InvalidKeyException;
import java.security.spec.RSAPrivateKeySpec;

import javax.crypto.NoSuchPaddingException;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.Cipher;

import java.io.FileInputStream;
import java.io.IOException;

/**
 * Classe permettant de déchiffrer un message à l'aide une clé privée.
 * @author Cyril Rabat
 */
public class Dechiffrement {

    /**
     * Methode principale.
     * @param args[0] nom du fichier dans lequel se trouve la clé privée
     * @param args[1] message à déchiffrer
     */
    public static void main(String[] args) {
        // Vérification des arguments
        if(args.length != 2) {
            System.err.println("Utilisation :");
            System.err.println("  java Dechiffrement clePrivee message output");
            System.err.println("    où :");
            System.err.println("      - clePrivee : nom du fichier qui contient la clé privée");
            System.err.println("      - input     : nom du fichier contenant le message à dechiffrer");
            System.exit(0);        
        }

        // Récupération de la clé privée
        PrivateKey clePrivee = GestionClesRSA.lectureClePrivee(args[0]);

        // Chargement du message chiffré
        byte[] messageCode = null;
        try {
            FileInputStream fichier = new FileInputStream(args[1]);
            messageCode = new byte[fichier.available()]; 
            fichier.read(messageCode);
            fichier.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture du message : " + e);
            System.exit(0);
        }

        // Déchiffrement du message
        byte[] bytes = null;
        try {
            Cipher dechiffreur = Cipher.getInstance("RSA");
            dechiffreur.init(Cipher.DECRYPT_MODE, clePrivee);
            bytes = dechiffreur.doFinal(messageCode);
        } catch(NoSuchAlgorithmException e) {
            System.err.println("Erreur lors du chiffrement : " + e);
            System.exit(0);
        } catch(NoSuchPaddingException e) {
            System.err.println("Erreur lors du chiffrement : " + e);
            System.exit(0);
        } catch(InvalidKeyException e) {
            System.err.println("Erreur lors du chiffrement : " + e);
            System.exit(0);
        } catch(IllegalBlockSizeException e) {
            System.err.println("Erreur lors du chiffrement : " + e);
            System.exit(0);
        } catch(BadPaddingException e) {
            System.err.println("Erreur lors du chiffrement : " + e);
            System.exit(0);
        }

        // Affichage du message
        String message = new String(bytes);
        System.out.println("Message : " + message);
    }
}