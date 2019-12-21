import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
import java.util.Date;

public class tri {
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);
        int [] t2;
        int taille, min, max;
        long tmp3;

        System.out.print("entrez la taille du tableau : ");
        taille=sc.nextInt();
        System.out.print("entrez le minimum : ");
        min=sc.nextInt();
        System.out.print("entrez le maximum : ");
        max=sc.nextInt()+1;
        
        int [] t=new int [taille];
        t=genererTableau(taille, min, max);
        afficher(t);
        t2=clone(t);   
        tmp3=System.currentTimeMillis();
        triSelection(t2); 
        System.out.println("temps = "+(System.currentTimeMillis()-tmp3)+" milisecondes");
    }

    public static int aleatoire (int min, int max){
        int nb;
        nb=(int)(Math.random()*(max-min)+min);
        return nb;   
    }

    public static int [] genererTableau (int n, int min, int max){
        int [] t = new int [n];
        for (int i=0; i<t.length; i++) {
            t[i] = aleatoire(min, max);
        }
        return t;
    }

    public static void afficher (int [] t){
        for (int i=0; i<t.length; i++) {
            System.out.print(t[i]+" ");
        }
        System.out.println();
    }

    public static int [] clone (int [] t){
        int [] clone = new int [t.length];
        clone=t;
        return t;
    }
    
    public static void triSelection(int t[]){
        int [] t2= new int [t.length];
        int j=0;
        System.out.println();
        for (int i=0; i<t.length; i++) {
            j=indiceMinimum(t);
            t2[i]=t[(int)j]; 
            t[(int)j]=maximum(t);
        }
        afficher(t2);
    }

    public static int indiceMinimum(int t[]){
        int j=0;
        double min=999999999;
        for (int i=0; i<t.length; i++) {
            if (min>t[i]) {
                min=t[i];
                j=i;
            }
        }
        return (int)j;
    }

    public static int maximum(int t[]){
        double max=-999999999;
        for (int i=0; i<t.length; i++) {
            if (max<t[i]) {
                max=t[i];
            }
        }
        return (int) max;
    }

    public static void triSelectionEchange (int [] t){
        
    }
}