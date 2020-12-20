import java.security.InvalidKeyException;
import java.security.spec.RSAPrivateKeySpec;
import java.security.KeyPairGenerator;
import java.security.KeyPair;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.KeyFactory;
import java.security.spec.X509EncodedKeySpec;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.InvalidKeySpecException;

import javax.crypto.NoSuchPaddingException;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.Cipher;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.File;
import java.io.FileOutputStream;
import java.nio.file.Files;

public class RSA {

    /**
     * Génération des clés RSA.
     * @param nomFichierClePriv nom du fichier dans lequel sauvegarder la clé privée
     * @param nomFichierClePubl nom du fichier dans lequel sauvegarder la clé publique
     */
    public RSA(String nomFichierClePriv, String nomFichierClePubl){
        if(!exists(nomFichierClePriv) && !exists(nomFichierClePubl)){
            generationClesRSA(nomFichierClePriv, nomFichierClePubl);
        }
        else{
            System.out.println("Les fichiers ou un des fichiers : \"" + nomFichierClePriv + "\" et \"" + nomFichierClePubl + "\" existe(nt) déjà.");
        }
    }

    /**
     * Génération des clés RSA.
     * @param nomFichierClePriv nom du fichier dans lequel sauvegarder la clé privée
     * @param nomFichierClePubl nom du fichier dans lequel sauvegarder la clé publique
     * @param forcedCreation boolean, si 'true' force la reCréation des fichier
     */
    public RSA(String nomFichierClePriv, String nomFichierClePubl, boolean forcedCreation){
        if(!exists(nomFichierClePriv) && !exists(nomFichierClePubl)){
            generationClesRSA(nomFichierClePriv, nomFichierClePubl);
        }
        else if(forcedCreation){
            generationClesRSA(nomFichierClePriv, nomFichierClePubl);
        }
        else{
            System.out.println("Les fichiers ou un des fichiers : \"" + nomFichierClePriv + "\" et \"" + nomFichierClePubl + "\" existe(nt) déjà et vous ne voulez pas forcer leurs reCréation.");
        }
    }

    /**
     * Génération des clés RSA.
     * @param nomFichierClePriv nom du fichier dans lequel sauvegarder la clé privée
     * @param nomFichierClePubl nom du fichier dans lequel sauvegarder la clé publique
     */
    public void generationClesRSA(String nomFichierClePriv, String nomFichierClePubl) {
        // Vérification des arguments
        if(nomFichierClePriv == null || nomFichierClePubl == null){
            System.err.println("Utilisation :");
            System.err.println("  generationClesRSA ( privee , publique )");
            System.err.println("    où :");
            System.err.println("      - privee   : nom du fichier qui contiendra la clé privée");
            System.err.println("      - publique : nom du fichier qui contiendra la clé publique");
            System.exit(-1);
        }

        // Création d'un générateur RSA
        KeyPairGenerator generateurCles = null;
        try {
            generateurCles = KeyPairGenerator.getInstance("RSA");
            generateurCles.initialize(2048);
        } catch(NoSuchAlgorithmException e) {
            System.err.println("Erreur lors de l'initialisation du générateur de clés : " + e);
            System.exit(-1);
        }

        // Génération de la paire de clés
        KeyPair paireCles = generateurCles.generateKeyPair();

        // Sauvegarde de la clé privée
        System.out.println("\nClé privée : " + paireCles.getPrivate());
        sauvegardeClePrivee(paireCles.getPrivate(), nomFichierClePriv);

        // Sauvegarde de la clé publique
        System.out.println("\nClé publique : " + paireCles.getPublic());
        sauvegardeClePublique(paireCles.getPublic(), nomFichierClePubl);

        System.out.println("Clés sauvegardées.");
    }

    /**
     * Sauvegarde de la clé publique dans un fichier.
     * @param clePublique la clé publique
     * @param nomFichier le nom du fichier dans lequel sauvegarder la clé
     */
    public void sauvegardeClePublique(PublicKey clePublique, String nomFichier) {
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
    public void sauvegardeClePrivee(PrivateKey clePrivee, String nomFichier) {
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
    public PrivateKey lectureClePrivee(String nomFichier) {
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
    public PublicKey lectureClePublique(String nomFichier) {
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

    /**
     * Chiffrement.
     * @param nomFichierClePubl nom du fichier dans lequel se trouve la clé publique
     * @param msg message à chiffrer
     * @param nomFichierSauvegarderMessage nom du fichier dans lequel sauvegarder le message chiffré
     */
    public void chiffrement(String nomFichierClePubl, String msg, String nomFichierSauvegarderMessage) {
        // Vérification des arguments
        if(nomFichierClePubl == null || msg == null || nomFichierSauvegarderMessage == null) {
            System.err.println("Utilisation :");
            System.err.println("  chiffrement ( clePublique , message , output )");
            System.err.println("    où :");
            System.err.println("      - clePublique : nom du fichier qui contient la clé publique");
            System.err.println("      - message     : message à chiffrer");
            System.err.println("      - output      : fichier contenant le message chiffré");
            System.exit(0);
        }

        System.out.println("Message à chiffrer : " + msg);

        // Recuperation de la cle publique
        PublicKey clePublique = lectureClePublique(nomFichierClePubl);

        // Chiffrement du message
        byte[] bytes = null;
        try {
            Cipher chiffreur = Cipher.getInstance("RSA");
            chiffreur.init(Cipher.ENCRYPT_MODE, clePublique);
            bytes = chiffreur.doFinal(msg.getBytes());
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

        // Sauvegarde du message chiffré
        try {
            FileOutputStream fichier = new FileOutputStream(nomFichierSauvegarderMessage);
            fichier.write(bytes);
            fichier.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la sauvegarde du message chiffré : " + e);
            System.exit(0);
        }
        System.out.println("Message code enregistré dans '" + nomFichierSauvegarderMessage + "'");
    }

    /**
     * Déchiffrement.
     * @param nomFichierClePriv nom du fichier dans lequel se trouve la clé privée
     * @param msg nom du fichier dans lequel se trouve le message à déchiffrer
     */
    public void dechiffrement(String nomFichierClePriv, String output){
        // Vérification des arguments
        if(nomFichierClePriv == null || output == null) {
            System.err.println("Utilisation :");
            System.err.println("  dechiffrement ( clePrivee , message , output )");
            System.err.println("    où :");
            System.err.println("      - clePrivee : nom du fichier qui contient la clé privée");
            System.err.println("      - input     : nom du fichier contenant le message à dechiffrer");
            System.exit(0);        
        }

        // Récupération de la clé privée
        PrivateKey clePrivee = lectureClePrivee(nomFichierClePriv);

        // Chargement du message chiffré
        byte[] messageCode = null;
        try {
            FileInputStream fichier = new FileInputStream(output);
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
        System.out.println("Message déchiffré : " + message);
    }

    /**
     * Vérifie si le nom de fichier en paramètre existe
     * @param nomFichier nom du fichier
     */
    public boolean exists(String nomFichier){
        File file = new File(nomFichier);
        return file.exists();
    }
}
