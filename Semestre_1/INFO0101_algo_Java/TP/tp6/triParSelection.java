import java.util.Scanner;
import java.lang.Math;

public class triParSelection {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
        int taille;
        double a, b;
        double [] t;

        System.out.print("Taille du tableau :");
        taille=sc.nextInt();
        System.out.println("Intervalle [a,b[ : ");
        System.out.print("a:");
        a=sc.nextDouble();
        System.out.print("b:");
        b=sc.nextDouble();

        t=allocation(taille);
        remplirAleatoire(t,a,b);
        afficher(t);
        triSelection(t);
	}

    public static double [] allocation(int n){
        double [] t = new double [n];
        return t;
    }

    public static double aleatoire(double a, double b){
        double nombre;
        final double cst=10;
        nombre = (double)((int)((Math.random()*b)*cst))/cst;
        if (nombre<3) {
            nombre=(double)((int)((nombre+a)*cst))/cst;
        }
        return nombre;
    }

    public static void remplirAleatoire(double t[], double a, double b){
        for(int i = 0; i < t.length; i++){
            t[i] = aleatoire(a,b);
        }
    }

    public static void afficher(double t[]){
        for (int i=0; i<t.length; i++) {
            System.out.print(t[i]+" ");
        }
    }

    public static double indiceMinimum(double t[]){
        int j=0;
        double min=999999999;
        for (int i=0; i<t.length; i++) {
            if (min>t[i]) {
                min=t[i];
                j=i;
            }
        }
        return j;
    }

    public static int maximum(double t[]){
        double max=-999999999;
        for (int i=0; i<t.length; i++) {
            if (max<t[i]) {
                max=t[i];
            }
        }
        return (int) max;
    }

    public static void triSelection(double t[]){
        double [] t2= new double [t.length];
        double j=0;
        System.out.println();
        for (int i=0; i<t.length; i++) {
            j=indiceMinimum(t);
            t2[i]=t[(int)j]; 
            t[(int)j]=maximum(t);

            System.out.print("t2-"+i+")"+t2[i]+" ");
            System.out.print("t:");afficher(t);System.out.println();
        }
        afficher(t2);
    }
}