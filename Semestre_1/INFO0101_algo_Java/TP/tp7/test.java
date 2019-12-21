import java.util.Scanner;
import java.lang.Math;

public class test {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
        double random=0;
        int min, max;
        min=sc.nextInt();
        max=sc.nextInt();

        for (int i=1; i<=100; i++) {
            random=(int)(Math.random()*((max+1)-min)+min);
            System.out.println(i+") "+random);
        }
    }
}