import java.util.Scanner;
class testDate{
	public static void main (String[] args){
		Scanner clavier = new Scanner(System.in);

		Date date1 = new Date(2,1,2016);
		Date date2 = new Date();
		
		date1.afficher();
		System.out.println("jour par défaut : 0"+date2.getJour()+"/0"+date2.getMois()+'/'+date2.getAnnee());
		date2.setJour(28);
		date2.setMois(12);
		date2.setAnnee(2000);
		date2.afficher();
	}
}
