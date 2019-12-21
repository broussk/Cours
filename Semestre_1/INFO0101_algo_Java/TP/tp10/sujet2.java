import java.util.Scanner;
import java.lang.Math;

public class sujet2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nbEssais;

        System.out.print("Entrez le nombre d'essais a realiser : ");
        nbEssais =sc.nextInt();
        boolean [] essais =new boolean [nbEssais];
        System.out.print("Les essais generes sont : ");
        genererEssais(essais);
        afficherEssais(essais);
        System.out.println();
        System.out.println("Pourcentage de pile : "+ statsEssais(essais)+" %");
        System.out.println("Pourcentage de face : "+ (100-statsEssais(essais))+" %");
        System.out.println("Regardez derriere vous, un avion !");
        System.out.println("( Nombre de decalages necessaires : "+truquer(essais)+" )");
        System.out.print("Les essais generes sont : ");
        afficherEssais(essais);
        System.out.println();
        System.out.println("Pourcentage de pile : "+statsEssais(essais)+" %");
        triEchange(essais);
        System.out.print("Les essais trie sont :    ");
        afficherEssais(essais);
    }

    public static boolean lancerPiece (){
        boolean rep;
        int i;

        i = (int)(Math.random()*2);
        if (i==0) {
            rep=true;
        }
        else {
            rep=false;
        }

        return rep;
    }

    public static void genererEssais (boolean [] essais){
        for (int i=0; i<essais.length; i++) {
            essais[i]=lancerPiece();
        }
    }

    public static void afficherEssais (boolean [] essais){
        for (int i=0; i<essais.length; i++) {
            if (essais[i]==true) {
                System.out.print("pile ");
            }
            else {
                System.out.print("face ");
            }
        }
    }

    public static int statsEssais (boolean [] essais){
        int stat;
        int cpt=0, taille=essais.length;

        for (int i=0; i<essais.length; i++) {
            if (essais[i]==true) {
                cpt++;
            }
        }
        stat = (int)(((double)cpt/taille)*100);
        return stat;
    }

    public static int truquer (boolean [] essais){
        boolean [] essais1 = new boolean [essais.length];
        int cpt=0;
        essais1=essais;
        while(statsEssais(essais1)<=50){
            for (int i=0; i<essais.length; i++) {
                if (i<essais.length-1){
                    essais[i]=essais[i+1];
                }
            }
            essais[(essais.length-1)]=lancerPiece();
            cpt++;
        }

        return cpt;
    }

    public static void triEchange (boolean [] essais){
        boolean tmp;
        int i=0;
        
        for (int j=0; j<essais.length; j++) {
            i=0;
            while(essais[i]!=false){
                i++;
            }
            tmp=essais[j];
            essais[j]=essais[i];
            essais[i]=tmp;
        }
    }
}