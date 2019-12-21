import java.util.Scanner;
import java.lang.Math;

public class test {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
    	double popTarts;
        for (int i=0;i<100 ;i++ ) {
            popTarts=Math.random()*20+1;
        System.out.println((int)popTarts);
        }
    	
    }
}