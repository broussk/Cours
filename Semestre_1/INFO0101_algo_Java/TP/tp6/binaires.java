import java.util.Scanner;
import java.lang.Math;

public class binaires {
	public static void main(String[] args) {  
	   	Scanner sc = new Scanner(System.in);
	   	int nbOctets, entier, cpt=1, somme;

	   	System.out.print("Entrez un entier de Octets (pour la suite, tout les binaires seront en ce nombre d'Octets) : ");
	   	nbOctets=sc.nextInt();

	   	int [] nbBinaire01 = new int [nbOctets*8];
	   	int [] nbBinaire0 = new int [nbOctets*8];
	   	int [] nbBinaire1 = new int [nbOctets*8];
	   	int [] nbBinaire2 = new int [nbOctets*8];
	   	int [] resSomme = new int [nbOctets*8];

	   	System.out.println("Conversion d'un entier en binaire :");
	   	System.out.print("Entrez un entier : ");
	   	entier=sc.nextInt();
	   	System.out.print(" en binaire : ");
	   	nbBinaire01=complementA2(entier2binaire(entier,nbOctets));
	   	for (int p=nbBinaire01.length-1; p>=0; p--) {
    		System.out.print(nbBinaire01[p]);
    	}
    	System.out.println();

	   	System.out.println("Conversion d'un nombre binaire en entier : ");
	  	System.out.println("Entrez un nombre binaire : ");
	   	for (int i=nbBinaire0.length-1; i>=0; i--) {
	   		System.out.print("case "+(cpt)+" : ");
	   		nbBinaire0[i]=sc.nextInt();
	   		cpt++;
	   	}
	   	System.out.println(" en entier : " + binaire2entier(nbBinaire0));

	   	cpt=1;
	   	System.out.println("Somme de 2 nombres binaires :");
	   	System.out.println("Entrez le premier :");
	   	for (int j=nbBinaire1.length-1; j>=0; j--) {
	   		System.out.print("case "+(cpt)+" : ");
	   		nbBinaire1[j]=sc.nextInt();
	   		cpt++;
	   	}
	   	cpt=1;
	   	System.out.println("Entrez le deuxieme :");
	   	for (int k=nbBinaire2.length-1; k>=0; k--) {
	   		System.out.print("case "+(cpt)+" : ");
	   		nbBinaire2[k]=sc.nextInt();
	   		cpt++;
	   	}
	   	somme=somme(nbBinaire1, nbBinaire2);
	   	System.out.println("Voici le resultat de la somme: "+ somme);
	   	
	   	resSomme=complementA2(entier2binaire(somme, nbOctets));
	   	System.out.print("Soit : ");
	   	for (int l=resSomme.length-1; l>=0; l--) {
	   		System.out.print(resSomme[l]);
	   	}
    }

    public static int [] entier2binaire (int valeur, int nbOctets){
    	int [] t = new int [(nbOctets*8)];
    	int rest, bin, max=t.length;
    	for (int i=0; i<max; i++) {
    		bin=valeur%2;
    		valeur=(valeur-bin)/2;
    		t[i]=bin;
    	}
    	binaire2entier(t);
    	return t;
    }

    public static int binaire2entier (int [] binaire){
    	int valeur=0, nega=1;
    	if (binaire[binaire.length-1]==1) {
    		binaire[binaire.length-1]=0;
    		nega=-1;
    	}
    	for (int i=binaire.length-1; i>=0; i--) {
    		valeur=binaire[i]+valeur*2;
    	}
    	valeur=valeur*nega;
    	return valeur;
    }

    public static int somme (int [] binaire1, int [] binaire2){
    	int val, val1, val2;
    	val1=binaire2entier(binaire1);
    	val2=binaire2entier(binaire2);
    	val=val1+val2;
    	return val;
    }

    public static int [] complementA2 (int [] binaire){
    	if (binaire2entier(binaire)<0) {
    		binaire=entier2binaire(-binaire2entier(binaire),1);
    		binaire[binaire.length-1]=1;
    	}
    	else{
    		binaire[binaire.length-1]=0;
    	}
       	return binaire;
    }
}