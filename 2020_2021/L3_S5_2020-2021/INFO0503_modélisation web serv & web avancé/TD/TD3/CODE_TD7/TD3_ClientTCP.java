import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

public class ClientTCP{

	public static final int port = 666;
	public static final String address = "localhost";
	public static void main(String[] args){
		Socket socket = null;
		try{
			socket = new Socket(address,port);

		}catch(UnknownHostException e) {
            System.err.println("Erreur sur l'hôte : " + e);
        }catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
        }
        InputStream is = s.getInputStream(); //entrée C <- S
		ObjectInputStream ois = new ObjectInputStream(is);//entrée C <- S
		OutputStream os = s.getOutputStream(); //sortie C ->S
		ObjectOutputStream oos =new ObjectOutputStream(os); //sortie C ->S
		MessageAgregation MeA= new MessageAgregation();
		MessageAgregation MeB= null;
		




		//Dans le cas d'une emission
		/*Structure de Message :
			-type de message de 0 à 100
			-contenu : JSON
			-expediteur/destinataire = pas au terme IP --> donc email ou tel comme ID
			-objet (pas obligatoire)
			-date envoi
			-piece jointe
		*/
		MeA.add(new MessageEchange())
		MeA.getlist()[0].setType(1);
		MeA.getlist()[0].setContenu("Test message tango charly tango ");
		MeA.getlist()[0].setExpediteur("moi@univ-reims.fr");
		MeA.getlist()[0].setDestinataire("toi@univ-reims.fr");
		MeA.getlist()[0].setObjet("Un premier message pour le td de S505-S5O7");
		MeA.getlist()[0].setData(null);
		MeA.getlist()[0].setPj(null);

		oos.writeObject(MeA);
		MeB = (( MessageAgregation ) ois.readObject()).clone();

		if(!MeB.getlist()[0].getType())
			System.out.println("Ca marche !");
		else
			System.out.println("Ca marche pas OOF!");
		





		//dans le cas d'une reception de message 

		MeA.add(new MessageEchange())
		MeA.getlist()[0].setType(2);
		MeA.getlist()[0].setContenu("");
		MeA.getlist()[0].setExpediteur("moi@univ-reims.fr");
		MeA.getlist()[0].setDestinataire("");
		MeA.getlist()[0].setObjet("RecupU");
		MeA.getlist()[0].setData(null);
		MeA.getlist()[0].setPj(null);

		oos.writeObject(MeA);
		MeB = (( MessageAgregation ) ois.readObject()).clone();

		if(!MeB.getlist()[0].getType())
			System.out.println("Ca marche ! voici les messages"+MeB);
		else
			System.out.println("Jai pas de message");
		oos.writeObject();
		ois.readObject();

		// Fermeture des flux et de la socket
        try {
            is.close();
            os.close();
            ois.close();
            oos.close();
            socket.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
            System.exit(0);
        }
	}

}