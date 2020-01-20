import java.util.Scanner;

public class notes {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int nbNotes, noteMax;
		System.out.print("Entrez le nombre de notes : ");
		nbNotes=sc.nextInt();
		double [] t=new double [nbNotes];
		System.out.println("Entrez la note maximale qui peut etre obtenue : ");
		noteMax=sc.nextInt();
		saisieTableau(t, noteMax);
		System.out.println("La moyenne est de : "+moyenne(nbNotes,t));
    }

    public static double saisieTableau(double t[], int noteMax){
    	Scanner sc = new Scanner(System.in);
    	for (int i=0;i<t.length;i++) {
    		do{
	    		System.out.print("Entrez la note "+i+" : ");
	    		t[i]=sc.nextDouble();
    		}while(t[i]<0 || t[i]>noteMax);
    	}
    	afficheTableau(t);
		return 0;
    }

    public static double afficheTableau(double t[]){
    	for (int j=0;j<t.length;j++) {
			System.out.println("j="+t[j]);
		}
		return 0;
    }

    public static double moyenne (int nbNotes, double t[]){
    	double somme=0, moyenne;
    	for (int i=0;i<t.length;i++) {
    		somme=somme+t[i];
    	}
    	moyenne=somme/nbNotes;
    	return moyenne;
    }
}