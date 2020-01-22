import java.util.Scanner;

class main{
    public static void main (String [] args) {
        Scanner clavier = new Scanner(System.in);
        int taille, i=0, max;

        //initialisation de taille
        System.out.println("Entrez la taille du tableau:");
        taille=clavier.nextInt();

        //initialisation des tableaux
        int [] T1= new int [taille];
        int [] T2= new int [taille];
        System.out.println("Entrez les valeurs du tableau:");
        while(i<taille){
            T1[i]=clavier.nextInt();
            i++;
        }

        //affichage de T1
        i=0;
        while(i<taille){
            System.out.println("valeur "+i+" = "+T1[i]+" ");
            i++;
        }

        //recherche du max
        max=T1[0];
        for(i=1;i<taille;i++){
            if(max<T1[i]){
                max=T1[i];
            }
        }

        //normalisation
        System.out.println("max="+max+" ");
        for(i=0;i<taille;i++){
            T2[i]=T1[i]/max;
        }

        //affichage de T2
        for(i=0;i<taille;i++){
            System.out.println(T2[i]+" ");
        }
    }
}