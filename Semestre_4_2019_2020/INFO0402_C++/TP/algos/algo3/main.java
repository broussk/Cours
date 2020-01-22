import java.util.Scanner;

class main{
    public static void main (String [] args) {
        Scanner clavier = new Scanner(System.in);

        //initialisation des variables usuelles
        int taille, i, j;

        //initialisation de taille
        System.out.println("entrez la taille de la matrice :");
        taille=clavier.nextInt();

        //initialisation des matrices M1 et M2
        int [][] M1= new int [taille][taille];
        int [][] M2= new int [taille][taille];
        int [][] M3= new int [taille][taille];
        System.out.println("entrez les valeurs de la matrice M1 :");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print("M1["+i+"]["+j+"] = ");
                M1[i][j]=clavier.nextInt();
            }
        }
        System.out.println("entrez les valeurs de la matrice M2 :");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print("M2["+i+"]["+j+"] = ");
                M2[i][j]=clavier.nextInt();
            }
        }

        //initialisation de M3
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                if(M1[i][j]==1 && M2[i][j]==1){
                    M3[i][j]=1;
                }
                else{
                    M3[i][j]=0;
                }
            }
        }


        //affichage M3
        System.out.println("M3 :");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print(" "+M3[i][j]);
            }
            System.out.println();
        }
    }
}