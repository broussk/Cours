import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
import java.util.Date;

public class rechercheTbx {
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);
        int taille, min, max, nbRecherche, val;
        long tmp1, tmp2, tmp3;
        

        System.out.print("entrez le nombre de recherches a faire : ");
        nbRecherche=sc.nextInt();
        System.out.print("entrez la taille du tableau : ");
        taille=sc.nextInt();
        System.out.print("entrez le minimum : ");
        min=sc.nextInt();
        System.out.print("entrez le maximum : ");
        max=sc.nextInt()+1;
        
        int [] recherche=new int [nbRecherche]; 
        int [] t=new int [taille];
        recherche=genererTableau(nbRecherche,min,max);
        t=genererTableau(taille, min, max);
        afficher(t);
        afficher(recherche);

		tmp1=System.currentTimeMillis();
        for (int i=0; i<recherche.length; i++) {
            val=recherche[i];
            /*System.out.println("chiffre "+val+" case "+*/rechercheSequentielle(t,val)/*)*/;
        }        
        System.out.println("temps="+(System.currentTimeMillis()-tmp1)+"milisecondes");

		tmp2=System.currentTimeMillis();
		Arrays.sort(t); System.out.println("Arrays.sort(t)");
        afficher(t);
        System.out.println("temps="+(System.currentTimeMillis()-tmp2)+"milisecondes");

        tmp3=System.currentTimeMillis();
        for (int j=0; j<recherche.length; j++) {
        	val=recherche[j];
        	rechercheDichotomique(t, val);
        }
        System.out.println("temps="+(System.currentTimeMillis()-tmp3)+"milisecondes");
        
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

    public static int rechercheSequentielle (int [] t, int val){
        int rep;
        int i=-1;
        do{
            //System.out.print("i:"+i);
            i++;
        }while(t[i]!=val && i<t.length-1);
        if (t[i]==val) {
            rep=i;
        }
        else{
            rep=-1;
        }
        return rep;
    }

    public static void rechercheSequentielleTriee (int [] t){
    	//Je ne sais pas quoi mettre dans cette fonction
    }

    public static int [] rechercheDichotomique(int [] t, int val){
    	int binf=0, bsup=t.length-1, p=(binf+bsup)/2;
    	while(t[binf]==val && t[bsup]==val && t[p]==val){
    		if (t[p]<val) {
    			binf=p+1;
    			p=(binf+bsup)/2;
    		}
    		else {
    			bsup=p-1;
    			p=(binf+bsup)/2;
    		}
    	}
    	return t;
    }

}