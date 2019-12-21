import java.util.Scanner;

public class sujet1 {
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
        int cpt=0;
        Scanner sc= new Scanner(System.in);

        do{
            resultat=true;
            System.out.print("Entrez un mot : ");
            mot=sc.nextLine();
            for (int i=0; i<t.length; i++) {
                char caracMot = mot.charAt(i);
                /*for (int j='a'; j<='z'; j++) {
                    if (caracMot==j) {
                        cpt++;
                    }
                }*/
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
        char [] chiffree = new char [t.length];
        char carac;
        
                //boucle bonne
        char tmp=t[t.length-1];
        for (int j=t.length-1; j>=0; j--) {
            /*if (j==0) {
                chiffree[j]=tmp;
            }
            else{*/
                if(j>0){
                chiffree[j]=chiffree[j-1];  
            }//}
        }
        chiffree[0]=tmp++;

                //a revoir
        for (int i=0; i<t.length; i++) {
                carac=t[i];
                carac++;
                chiffree[i]=carac;
            if (t[i]=='z') {
                chiffree[i]='a';
            }
            /*else{
                carac=t[i];
                carac++;
                chiffree[i]=carac;
            }*/
        }
        return chiffree;
    }

    public static char [] dechiffrer (char [] chiffree){
        char carac;
                //boucle bonne
        char tmp=chiffree[0];
        for (int j=0; j<chiffree.length; j++) {
            if (j==chiffree.length-1) {
                chiffree[j]=tmp;
            }
            else{
                chiffree[j]=chiffree[j+1];                
            }
        }
                //pour verlan
         /*tmp=chiffree[0];
        for (int j=0; j<chiffree.length; j++) {
            if (j==chiffree.length-1) {
                chiffree[j]=tmp;
            }
            else{
                chiffree[j]=chiffree[j+1];                
            }
        }*/
                //bon
        for (int i=0; i<chiffree.length; i++) {
            
            if (chiffree[i]=='a') {
                chiffree[i]='z';
            }
            else{
                carac=chiffree[i];
                carac--;
                chiffree[i]=carac;
            }
        }
        return chiffree;
    }
}