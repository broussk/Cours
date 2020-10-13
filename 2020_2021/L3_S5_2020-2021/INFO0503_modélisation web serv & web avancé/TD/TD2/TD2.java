import java.io.BufferedReader;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;

import jdk.internal.jline.internal.InputStreamReader;
import sun.net.InetAddressCachePolicy;

/*
 * TD2 INFO0503
 * TONNELLE Nathan
 */

//question 5
class Serveur{
    private Vector<String> iduse;
    private int pont = 15000;
    private String adresse;
    
    public static void main(String[] arg){
        serverSocket ssoket = new serverSocket(port);
        Socket s = ssocket.accept();
        Scanner scan = new Scanner (s.getInputScanner);
        String line = scan.nextLine();
        /*
         * "00"
         * "10"
         */
        switch (line.substring(0,2)) {
            case "00":
                renvoie sur la socket la réponse;
                enregistrer utilisateur;
                break;
            //...
            case "10" :
                break;
            default:
                break;
        }
        scan.close();
    }
}

public class Client{
    private String adUSer;
    private int port;
    public void main(String[] arg){
        client c = NULL;
        socket s = NULL;
        scanner scan = NULL;
        c = new client("mess",3128);
        s = new socket("localhost", getPort());
        s.connect();
        bufferReader entree = NULL;
        ObjectInputStream sortie = 
        entree = new BufferReader(new InputStreamReader);
        sortie = new ObjectInputStream(socket.getOutputStream);
        String retour.mess = entree readLine();
        sortie.writeObject(m);

    }
}

public class TestServeurThreadTCP extends Thread{
    final static int port = 66666;
    private Socket socket;  //annonciation de la class threadTCP 
    public static void main(String[] args){
        ServeurSocket ServeurS = new ServeurSocket(port);
        while(time){
            socket = ServeurS.accept();
            Thread t = new ThreadTCP(socket);
            t.stort();
        }
    }
}

//classe :threadTCP
public void run(){
    traitement();
}
public void traitement(){
    String toto = "";
    String revient = "";
    PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
    BufferedReader in = new BufferedReader(
     new InputStreamReader(socket.getInputStream()));
    toto = in.readLine();
    switch(toto.substring(0,2)){
        case "01" :
            revient = choixIdentifiant();
            break;
        ...
    }
    PrintStream out = new PrintStream(socket.getOutputStream());
    out.println(revient);
    socket.close();
}

public class clientTCP{
    final static int port = 6666;
    public static void main(String[] args){
        Socket s;
        String t;
        InetAddress ip = new InetAddress(getByName(args[0]));
        s = new Socket(ip, port);
        BefferedReader in = new BufferedReader(
            new InputStreamReader(socket.getInputStream()));
        PrintStream out = new PrintStream(socket.getOutputStream());
        preparerTram(args[1], args[2], args[3], (-));
        out.println(t);
        String ret = ip.readLine();
        System.out.println(ret);
    }
}