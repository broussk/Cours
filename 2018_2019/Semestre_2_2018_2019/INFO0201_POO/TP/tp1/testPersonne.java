import java.util.Scanner;
class testPersonne{
	public static void main(String[] args) {
		Personne monsieur = new Personne("DUPONT", "Jean", "monsieur", 50, 75, 180);
		Personne madame = new Personne("DUPONT", "Jeannie", "madame", 45, 60, 160);
		Personne mademoiselle = new Personne("DUPONT", "Jeanne", "madame", 202, 1700, 606);
		double imc;
		mademoiselle.afficher();
		mademoiselle.setCivilite("mademoiselle");
		mademoiselle.setAge(20);
		mademoiselle.setPoids(60);
		mademoiselle.setTaille(170);
		mademoiselle.afficher();
		System.out.println("Le pere de "+mademoiselle.getPrenom()+" est "+monsieur.getPrenom()+" "+monsieur.getNom()+" et sa mere est "+madame.getPrenom()+" "+madame.getNom()+".");
		System.out.println("Son pere a "+monsieur.getAge()+"ans, est un "+monsieur.getCivilite()+".");
		System.out.println("Sa mere fait "+madame.getTaille()+"cm, pour "+madame.getPoids()+"kg.");
		System.out.println("Entrez une nouvelle personne:");
		Personne autre;
		autre = saisirPersonne();
		System.out.println("Vous avez inscrit la personne suivante : ");
		autre.afficher();
		imc=autre.IMC();
		System.out.println("L'IMC de cette personne est : "+imc+" ce qui correspond a : "+autre.interpreterIMC(imc));
	}

	public static Personne saisirPersonne(){
		Scanner clavier = new Scanner(System.in);
		String nom, prenom, civi;
		int age, taille;
		double poids;

		System.out.print("Nom : ");
		nom=clavier.nextLine();
		System.out.print("Prenom : ");
		prenom=clavier.nextLine();
		System.out.print("Civilite : ");
		civi=clavier.nextLine();
		System.out.print("Age : ");
		age=clavier.nextInt();
		System.out.print("Poids : ");
		poids=clavier.nextDouble();
		System.out.print("Taille : ");
		taille=clavier.nextInt();

		Personne pers= new Personne(nom, prenom, civi, age, poids, taille);
		return pers;
	}
}