import java.util.Scanner;

class main{
    public static void main (String [] args) {
        Scanner clavier = new Scanner(System.in);

        //initialisation des variables
        int taille , i, j , k, max=0;

        //initialisation de taille
        System.out.println("entrez la taille des tableaux : ");
        taille=clavier.nextInt();

        //initialisation de T1 et T2 et recherche du maxmimum
        int [] T1 = new int [taille];
        int [] T2 = new int [taille];
        int [] T3 = new int [taille*2];
        System.out.println("Entrez les valeurs de T1 : ");
        for(i=0;i<taille;i++){
            System.out.print("T1["+i+"] = ");
            T1[i]=clavier.nextInt();
            if(T1[i]>max) max=T1[i];
        }
        System.out.println("Entrez les valeurs de T2 : ");
        for(i=0;i<taille;i++){
            System.out.print("T2["+i+"] = ");
            T2[i]=clavier.nextInt();
            if(T2[i]>max) max=T2[i];
        }
        
        //affichage de T1 et T2
        System.out.print("T1 :");
        for(i=0;i<taille;i++){
            System.out.print(T1[i]+", ");
        }
        System.out.println();
        System.out.print("T2 :");
        for(i=0;i<taille;i++){
            System.out.print(T2[i]+", ");
        }
        System.out.println();

        //initialisation de T3
        i=0;
        j=0;
        k=0;
        while(i<taille && j<taille && k<(taille*2)){
            if(T1[i]<T2[j]){
                T3[k]=T1[i];
                if(i<taille){
                    i++;
                }
            }
            else{
                T3[k]=T2[j];
                if(j<taille){
                    j++;
                }
            }
            k++;
        }
        T3[taille*2-1]=max;

        //affichage de T3
        System.out.print("T3 :");
        for(i=0;i<taille*2;i++){
            System.out.print(T3[i]+", ");
        }
    }
}