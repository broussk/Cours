import java.util.Scanner;

class main{
    public static void main (String [] args) {
        Scanner clavier = new Scanner(System.in);

        //initialisation des variables usuelles
        int taille, i, j;

        //titre du programme
        System.out.println("Calcul du maximum de 2 images binaires");

        //initialisation des matrices carées
        System.out.println("entrez une taille des matrices carree");
        taille = clavier.nextInt();
        int [][] M1 = new int [taille][taille];
        int [][] M2 = new int [taille][taille];
        int [][] M3 = new int [taille][taille];

        //initialisation de la matrice M1
        System.out.println("entrez les valeurs de la matrice M1");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print("M1["+i+"]["+j+"] = ");
                M1[i][j]=clavier.nextInt();
            }
        }

        //initialisation de la matrice M2
        System.out.println("entrez les valeurs de la matrice M2");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print("M2["+i+"]["+j+"] = ");
                M2[i][j]=clavier.nextInt();
            }
        }

        //affichage de la matrice M1
        System.out.println("affichage de la matrice M1 :");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print(" "+M1[i][j]);
            }
            System.out.println();
        }

        //affichage de la matrice M2
        System.out.println("affichage de la matrice M2 :");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print(" "+M2[i][j]);
            }
            System.out.println();
        }

        //calcul du maximum des 2 images
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                if(M1[i][j]==0 && M2[i][j]==0){
                    M3[i][j]=0;
                }
                else{
                    M3[i][j]=1;
                }
            }
        }

        //affichage de la matrice M3
        System.out.println("affichage de la matrice M3");
        for(i=0;i<taille;i++){
            for(j=0;j<taille;j++){
                System.out.print(" "+M3[i][j]);
            }
            System.out.println();
        }

        //fin
    }
}