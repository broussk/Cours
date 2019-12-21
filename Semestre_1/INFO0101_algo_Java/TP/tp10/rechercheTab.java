import java.util.Scanner;

public class rechercheTab {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int taille=5;
        char [] tableau = new char [taille];
            System.out.println("mot, lettre par lettre :");
        for (int i=0; i<taille; i++) {
            tableau[i]=sc.nextLine().charAt(0);
        }
        System.out.print("1-tableau :");
        for (int j=0; j<taille; j++) {
            System.out.print(tableau[j]);
        }
        System.out.println();




        char [] chiffree = tableau;
        char carac;
        
                //boucle bonne
        char tmp=tableau[taille-1];
        for (int k=taille-1; k>0; k--) {
            /*if (j==0) {
                chiffree[j]=tmp;
            }
            else{*/
                if(k>0){
                chiffree[k]=chiffree[k-1];  
            }//}
        }
        chiffree[0]=tmp++;

        System.out.print("tableau :");
        for (int m=0; m<taille; m++) {
            System.out.print(chiffree[m]);
        }
        System.out.println();

                //a revoir
        for (int l=0; l<taille; l++) {
                /*carac=chiffree[l];
                carac++;
                chiffree[l]=carac;*/
            if (chiffree[l]=='z') {
                chiffree[l]='a';
            }
            else{
                carac=chiffree[l];
                carac++;
                chiffree[l]=carac;
            }
        }


        System.out.print("2-tableau :");
        for (int j=0; j<taille; j++) {
            System.out.print(chiffree[j]);
        }
        System.out.println();



        char carac1;
                //boucle bonne
        char tmp1=chiffree[0];
        for (int j=0; j<chiffree.length; j++) {
            if (j==chiffree.length-1) {
                chiffree[j]=tmp1;
            }
            else{
                chiffree[j]=chiffree[j+1];                
            }
        }

        System.out.print("tableau :");
        for (int j=0; j<taille; j++) {
            System.out.print(chiffree[j]);
        }
        System.out.println();
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
                carac1=chiffree[i];
                carac1--;
                chiffree[i]=carac1;
            }
        }

        System.out.print("3-tableau :");
        for (int j=0; j<taille; j++) {
            System.out.print(chiffree[j]);
        }
        System.out.println();
    }
}