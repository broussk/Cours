package heros;

public class testClasseHeros {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ClasseHeros hero1 = new ClasseHeros("petit", "magicien", 100, 200, 0, 0, 5, 50, 20);
		ClasseHeros hero2 = new ClasseHeros("Petit Penis", "Arracheur de sac à la sauvette", 50, 10, 50, 5, 30, 5, 100);
		
		System.out.println("Héros1 :\n nom : " + hero1.getNom() + "\n pv : " + hero1.getPointsDeVie() + "\n magie : " + hero1.getPointsDeMagie() + "\n xp : " + hero1.getExperience() + "\n force : " + hero1.getForce() + "\n magie : " + hero1.getMagie() + "\n dexterité " + hero1.getDexterite());
		System.out.println(hero2.toString());
		
		hero2.setNom('B');
		hero2.ajouterExperience(50);
		hero2.ajouterPointsDeVie(-5);
		hero2.ajouterUnNiveau();
		hero2.soustrairePointsDeVie(9);
		
		System.out.println(hero2.toString());
	}

}
