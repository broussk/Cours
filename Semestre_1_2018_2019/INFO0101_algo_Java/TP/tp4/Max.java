import java.util.Scanner;

public class max {

	public static double maximum(double nb1, double nb2){
    	if (nb1>nb2){
			return nb1;
		}
		else{
			return nb2;
		}
    }

	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		double m=0, gard=-999999999;
		int n;

		System.out.print("Saisissez un entier n : ");
		n=sc.nextInt();

		for (int i=1; i<=n; i++){
			System.out.print("Saisissez un reel : ");
			m=sc.nextDouble();
			if (m>gard){
				gard=m;
			}
		}
		System.out.println("le reel : " +maximum(m,gard)  + " est le maximum que vous aviez saisi.");
    }
}