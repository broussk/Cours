import java.lang.invoke.MethodHandles;

/**
 * Classe d'exemple illustrant l'utilisation de la classe Config.
 * @author Cyril Rabat
 */
public class Exemple {

    /**
     * Création d'un fichier de configuration par défaut.
     * @param nomFichier le nom du fichier
     * @return la configuration
     */
    public static Config creerFichierConfiguation(String nomFichier) {
        Config config = new Config(nomFichier, true);
        
        /**
         * #TODO#
         * À l'aide des méthodes ajouterValeur, ajouter les valeurs par défaut
         */
        config.ajouterValeur("adresse", "127.0.0.1");
        config.ajouterValeur("port", 1056);
         
        // Sauvegarde du fichier de configuration
        config.sauvegarder();
        
        return config;
    }
        
    /**
     * Fonction principale
     * @param args vide ou contient le nom du fichier de config
     */
    public static void main(String[] args) {       
        // Vérification des arguments
        Config config;        
        if(args.length == 0) {
            // Pas d'argument : on ouvre le fichier json par défaut (nom de la classe)
            
            String className = MethodHandles.lookup().lookupClass().getSimpleName() + ".json";
            if(Config.fichierExiste(className)){
                System.out.println("0 args, \tle fichier existe");
                config = new Config(className);
            }
            else{
                System.out.println("0 args, \tle fichier n'existe pas, création");
                config = creerFichierConfiguation(className);
            }   
        }
        else {
            // Un argument : c'est le nom du fichier JSON de config à ouvrir/créer
            
            if(Config.fichierExiste(args[0])){
                System.out.println("1 args, \tle fichier existe");
                config = new Config(args[0]);
            }   
            else{
                System.out.println("1 args, \tle fichier n'existe pas");
                config = creerFichierConfiguation(args[0]);
            }
        }
        
        // Vérification des données dans le fichier de configuration
        
        /**
         * #TODO#
         * Utilisez les méthodes getString/getInt pour récupérer les données
         * et vérifier le bon fonctionnement de l'ensemble...
         */
        System.out.println("adresse : " + config.getString("adresse") + " port : " + config.getInt("port"));
    }

}