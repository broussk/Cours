import java.util.Scanner;

public class sujet1bis {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int taille;

        System.out.print("Entrez le nombre de caracteres du mot : ");
        taille=sc.nextInt();
        char [] t = new char [taille];
        t=initialiserMot(t);

        System.out.print("Le mot entre est "); afficherMot(t);
        t=chiffrer(t);
        System.out.println();
        System.out.print("Le mot crypte est "); afficherMot(t);
        t=dechiffrer(t);
        System.out.println();
        System.out.print("Le mot decrypte est "); afficherMot(t);
    }

    public static char [] initialiserMot ( char [] t){
        String mot;
        boolean resultat;
        int cpt;
        Scanner sc= new Scanner(System.in);

        do{
            resultat=true;
            cpt=0;
            System.out.print("Entrez un mot : ");
            mot=sc.nextLine();

            for (int i=0; i<t.length; i++) {
                char caracMot = mot.charAt(i);
                if(caracMot>='a' && caracMot<='z'){
                    cpt++;
                }
            }

            if (cpt!=t.length) {
                resultat=false;
                System.out.println("Erreur ! Le mot ne doit contenir que des lettres minuscules !");
            }
        }while(resultat==false);

        for (int k=0; k<t.length; k++) {
            t[k]=mot.charAt(k);
        }
        return t;
    }

    public static void afficherMot (char [] t){
        for (int i=0; i<t.length; i++) {
            System.out.print(t[i]);
        }
    }

    public static char [] chiffrer (char [] t){
        char [] chiffree = t;
        char carac;
        char tmp=t[t.length-1];

        for (int k=t.length-1; k>0; k--) {
                if(k>0){
                chiffree[k]=chiffree[k-1];  
            }
        }
        chiffree[0]=tmp++;

        for (int l=0; l<t.length; l++) {
            if (chiffree[l]=='z') {
                chiffree[l]='a';
            }
            else{
                carac=chiffree[l];
                carac++;
                chiffree[l]=carac;
            }
        }
        return chiffree;
    }

    public static char [] dechiffrer (char [] chiffree){
        char carac1;
        char tmp1=chiffree[0];

        for (int j=0; j<chiffree.length; j++) {
            if (j==chiffree.length-1) {
                chiffree[j]=tmp1;
            }
            else{
                chiffree[j]=chiffree[j+1];                
            }
        }

        for (int i=0; i<chiffree.length; i++) {
            
            if (chiffree[i]=='a') {
                chiffree[i]='z';
            }
            else{
                carac1=chiffree[i];
                carac1--;
                chiffree[i]=carac1;
            }
        }
        return chiffree;
    }
}