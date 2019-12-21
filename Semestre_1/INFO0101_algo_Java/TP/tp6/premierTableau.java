import java.util.Scanner;

public class premierTableau {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int taille, max=-200;
		System.out.print("Taille du tableau :");
		taille=sc.nextInt();
		int [] t= new int [taille];
		for (int i=0;i<t.length;i++ ) {
			System.out.print("Case "+i+" : ");
			t[i]=sc.nextInt();
		}
		for (int j=0;j<t.length;j++) {
			System.out.println("j="+t[j]);
		}
		for (int k=0;k<t.length;k++) {
			if (t[k]>max) {
				max=t[k];
			}
		}
		System.out.println("le max est : "+max);
    }
}