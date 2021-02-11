public class Image {
    public static void main(String[] args) {
        boolean[][] image = {
                {false, false, false, false, false, false, false, false, false, false, false, false},
                {false, false, false, false, true, true, true, true, false, false, false, false},
                {false, false, false, true, false, false, false, false, true, false, false, false},
                {false, false, true, false, true, false, false, true, false, true, false, false},
                {false, false, true, false, false, false, false, false, false, true, false, false},
                {false, false, true, false, true, false, false, true, false, true, false, false},
                {false, false, true, false, false, true, true, false, false, true, false, false},
                {false, false, false, true, false, false, false, false, true, false, false, false},
                {false, false, false, false, true, true, true, true, false, false, false, false},
                {false, false, false, false, false, false, false, false, false, false, false, false}
        };

        afficherImage(image);
        int[][] coords = cadre(image);
        System.out.println("Coordonees: (" + coords[0][0] + "," + coords[0][1] + ")-(" + coords[1][0] + "," + coords[1][1] + ")");
        System.out.println("\n\n");
        effacerImage(image);
        afficherImage(image);
        System.out.println("\n\n");
        boolean [][] test = creerImage(7, 9);
        ligne(test, 3);
        afficherImage(test);
        System.out.println("\n\n");
        setPixel(test, 2, 4);
        afficherImage(test);
        int[][] coords2 = cadre(test);
        System.out.println("Coordonees: (" + coords2[0][0] + "," + coords2[0][1] + ")-(" + coords2[1][0] + "," + coords2[1][1] + ")");


    }

    public static void effacerImage(boolean[][] image) {
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[i].length; j++) {
                if (image[i][j]) {
                    image[i][j] = false;
                }
            }
        }
    }

    public static boolean[][] creerImage(int largeur, int hauteur) {
        char grille = new char[3][3];
        int joueur = 1;

        System.out.print("Sur quelle ligne: ");
        int l = cl.nextInt();
        System.out.print("Sur quelle colonne ");
        int c =  cl.nextInt();

        if(joueur == 1){
          joueur++;
          grille[l][c] = 'X';
          System.out.print("Au joueur 0 de jouer");
        }else if (joueur == 2){
          joueur--;
          grille[l][c] = 'O';
          System.out.print("Au joueur X de jouer");
        }







        return image;
    }

    public static void afficherImage(boolean[][] image) {
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[i].length; j++) {
                if (image[i][j]) {
                    System.out.print("X");
                } else {
                    System.out.print("-");
                }
            }
            System.out.println();
        }
    }

    public static void setPixel(boolean[][] image, int i, int j) {
        if (i > image.length - 1) {
            System.out.print("ERREUR ! Le numero de ligne est incorrect.");
        } else {
            if (j > image[i].length - 1) {
                System.out.print("ERREUR ! Le numero de colonne est incorrect.");
            } else {
                image[i][j] = true;
            }
        }
    }

    public static void ligne(boolean[][] image, int ligne) {
        if (ligne > image.length - 1) {
            System.out.print("ERREUR ! Le numero de ligne est incorrect.");
        } else {
            for (int j = 0; j < image[ligne].length; j++) {
                image[ligne][j] = true;
            }
        }
    }

    public static int premiereLigne(boolean[][] image) {
        boolean trouve = false;
        int i = 0;
        while (!trouve && i < image.length) {
            int j = 0;
            while (!trouve && j < image[i].length) {
                if (image[i][j]) {
                    trouve = true;
                } else {
                    j++;
                }
            }
            if (!trouve) {
                i++;
            }
        }
        return i;
    }

    public static int premiereColonne(boolean[][] image) {
        int i = 0;
        int j = 0;
        boolean val = false;
        while(j<image[i].length && val==false){
            while(i<image.length && val==false){
                if(image[i][j]==false){
                    i++;
                }
                else{
                    val = true;
                }
            }
            if(val == false){
                j++;
                i = 0;
            }
        }
        if(val == false){
            j = 0;
        }
        return j ;
    }


    public static int derniereLigne(boolean[][] image) {
        int i = image.length-1;
        int j = image[i].length-1;
        boolean val = false;
        while(i>-1 && val==false){
            while(j>-1 && val==false){
                if(image[i][j] == false){
                    j--;
                }
                else{
                    val = true;
                }
            }
            if(val==false){
                i--;
                j = image[i].length-1;
            }
        }
        if(val == false){
            i = image.length-1;
        }
        return i ;
    }

    public static int derniereColonne(boolean[][] image) {
        int i = image.length-1;
        int j = image[i].length-1;
        boolean val = false;
        while(j<-1 && val==false){
            while(i<-1 && val==false){
                if(image[i][j]==false){
                    i--;
                }
                else{
                    val = true;
                }
            }
            if(val == false){
                j--;
                i = image[i].length-1;
            }
        }
        if(val == false){
            j = image.length-1;
        }
        return j ;
    }

    public static int[][] cadre(boolean[][] image) {
        int coords[][] = new int [2] [2];
        coords[0][0]= premiereLigne(image);
        coords[0][1]= premiereColonne(image);
        coords[1][0]= derniereLigne(image);
        coords[1][1]= derniereColonne(image);
        return coords;
    }


}
