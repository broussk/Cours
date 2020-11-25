import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

public class ClientUDP{

	public static final int port = 666;

	public static final String address = "localhost";
	public static void main(String[] args){
		DatagramSocket socket = null;
		try {
            socket = new DatagramSocket();
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }
		MessageAgregation MeA= new MessageAgregation();
		MessageAgregation MeB= null;
		
//envoi
		//Dans le cas d'une emission
		/*Structure de Message :
			-type de message de 0 à 100
			-contenu : JSON
			-expediteur/destinataire = pas au terme IP --> donc email ou tel comme ID
			-objet (pas obligatoire)
			-date envoi
			-piece jointe
		*/
		DatagramPacket msg = null; 
		 // Création du message
       	byte[] tampon = new byte[1024];
        DatagramPacket msgR = new DatagramPacket(tampon, tampon.length);
		try {
            InetAddress adresse = InetAddress.getByName(address);
			MeA.add(new MessageEchange())
			MeA.getlist()[0].setType(1);
			MeA.getlist()[0].setContenu("Test message tango charly tango ");
			MeA.getlist()[0].setExpediteur("moi@univ-reims.fr");
			MeA.getlist()[0].setDestinataire("toi@univ-reims.fr");
			MeA.getlist()[0].setObjet("Un premier message pour le td de S505-S5O7");
			MeA.getlist()[0].setData(null);
			MeA.getlist()[0].setPj(null);
			byte[] tampon = MeA.getBytes();
			msg = new DatagramPacket(tampon, tampon.length, adresse, port);
			socket.send(msg);
		} catch(UnknownHostException e) {
            System.err.println("Erreur lors de la création du message : " + e);
            System.exit(0);
        }
        socket.receive(msgR)
        msgR = new msgA(msgR.getData(), 0, msgR.getLength());
        int id_msg_received= msgR.getlist()[0].getIdMsg();

		if(!msgR.getlist()[0].getType())
			System.out.println("Ca marche !");
		else
			System.out.println("Ca marche pas OOF!");
		


		//reception
		DatagramPacket msg = null; 
		 // Création du message
       	byte[] tampon = new byte[1024];
        DatagramPacket msgR = new DatagramPacket(tampon, tampon.length);
		try {
            InetAddress adresse = InetAddress.getByName(address);
			MeA.add(new MessageEchange())
			MeA.getlist()[0].setType(2);
			MeA.getlist()[0].setContenu("");
			MeA.getlist()[0].setExpediteur("moi@univ-reims.fr");
			MeA.getlist()[0].setDestinataire(" ");
			MeA.getlist()[0].setObjet("");
			MeA.getlist()[0].setData(null);
			MeA.getlist()[0].setPj(null);
			byte[] tampon = MeA.getBytes();
			msg = new DatagramPacket(tampon, tampon.length, adresse, port);
			socket.send(msg);
		} catch(UnknownHostException e) {
            System.err.println("Erreur lors de la création du message : " + e);
            System.exit(0);
        }
        socket.receive(msgR)
        msgR = new msgA(msgR.getData(), 0, msgR.getLength());
        int id_msg_received= msgR.getlist()[0].getIdMsg();

		if(!msgR.getlist()[0].getType())
			System.out.println("Ca marche !");
		else
			System.out.println("Ca marche pas OOF!");

		// Fermeture des flux et de la socket
        try {
            socket.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
            System.exit(0);
        }
	}

}