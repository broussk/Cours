import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.security.NoSuchAlgorithmException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import java.security.InvalidKeyException;

/**
 * Classe permettant de tester le chiffrement et le dechiffrement avec AES.
 * @author Cyril Rabat
 */
public class ChiffrementAES {

    /**
     * Methode principale.
     * @param args[0] cle de chiffrement de 16 caractères
     * @param args[1] message que l'on veut chiffrer
     */
    public static void main(String[] args) {
        // Verification des arguments
        if(args.length != 2) {
            System.err.println("Utilisation :");
            System.err.println("  java ChiffrementAES motDePasse message");
            System.err.println("    où :");
            System.err.println("      - motDePasse : mot de passe de 16 caractères");
            System.err.println("      - message    : message que l'on veut chiffrer");
            System.exit(0);
        }
        String motDePasse = args[0];
      
        // Chiffrement du message
        System.out.println("Message origine   : " + args[1]);
        SecretKeySpec specification = new SecretKeySpec(motDePasse.getBytes(), "AES");
        byte[] bytes = null;
        try {
            Cipher chiffreur = Cipher.getInstance("AES");
            chiffreur.init(Cipher.ENCRYPT_MODE, specification);
            bytes = chiffreur.doFinal(args[1].getBytes());
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
        System.out.println("Message chiffré : " + bytes); 
        
        // Dechiffrement du message
        try {
            Cipher dechiffreur = Cipher.getInstance("AES");
            dechiffreur.init(Cipher.DECRYPT_MODE, specification);
            bytes = dechiffreur.doFinal(bytes);
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

        System.out.println("Message déchiffré : " + new String(bytes));
    }

}