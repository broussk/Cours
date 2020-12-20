import java.io.IOException;
import com.sun.net.httpserver.HttpServer;
import java.net.InetSocketAddress;

public class ServeurHttp{

    public static void main(String[] args) {    
        HttpServer serveur = null;
        try {
            serveur = HttpServer.create(new InetSocketAddress(9876), 0);
        } catch(IOException e) {
            System.err.println("Erreur lors de la création du serveur " + e);
            System.exit(0);
        }

        serveur.createContext("/index", new IndexHandler());
        serveur.createContext("/login", new LoginHandler());
        serveur.createContext("/ajout", new AjoutVoitureHandler());
        serveur.setExecutor(null);
        serveur.start();

        System.out.println("Serveur démarré. Pressez CRTL+C pour arrêter.");
    }

}