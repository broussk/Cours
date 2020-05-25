import java.util.Scanner;
import java.lang.Math;

public class nbalea {
	
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);	
		double m, n, min=0, max=0;
		
		System.out.print("entrez un entier :");
		n=sc.nextDouble();
		
		for(int i=1;i<=n;i++){
			System.out.println(i);
			m= Math.random()*(100+1-10)+(10);
			m=(int)m;
			System.out.println("nombre random: " +m);
			if (i==1){
				min=m;
				max=m;
			}
			if (m<min){
				min=m;
			}
			if(m>max){
				max=m;
			}
		}
		System.out.println("le minimum est: "+ min + " et le maximum est : "+ max);
    }
}