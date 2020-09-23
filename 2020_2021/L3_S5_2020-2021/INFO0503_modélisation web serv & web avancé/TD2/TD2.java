/*
 * TD2 INFO0503
 * TONNELLE Nathan
 */

//question 5
Class Serveur{
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