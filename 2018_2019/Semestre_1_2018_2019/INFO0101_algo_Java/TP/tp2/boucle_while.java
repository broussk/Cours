import java.util.Scanner;

class boucle_while {
 
    public static void main(String[] args) {
		Scanner clavier = new Scanner(System.in);
		int a, b, n, resultat=1;
		System.out.print("Ecrire un nombre entier a de l'intervalle minimum (avec un minimum de 1):");
		a = clavier.nextInt();
		System.out.print("Ecrire un nombre entier b de l'intervalle maximum:");
		b = clavier.nextInt();
		System.out.print("Ecrire un nombre entier n :");
		n = clavier.nextInt();
		if(a>b){
			System.out.println("a<b, ceci est une erreur");
		}
		else{	
			for(int i=0; i<=b; i++){
				if(i<a){
					i++;
				}
				resultat=n%i;
				if (resultat==0){
					System.out.println("multiple de : "+i);
				}
			}
		}
    }
}