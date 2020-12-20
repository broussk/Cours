package herosNathan;

public class testHeros {

	public static void main(String[] args) {
		Archer archer1 = new Archer("Poule !");
		Guerrier guerrier1 = new Guerrier("Le Long Sabre");
		Magicien mage1 = new Magicien("Ender");
		
		System.out.println("Descriptions de nos 3 h�ros :\n");
		System.out.println(archer1.toString());
		System.out.println(guerrier1.toString());
		System.out.println(mage1.toString());
		
		System.out.println("\nNotre Guerrier : " + guerrier1.getNom() + " poss�de " + guerrier1.getPointsDeVie() + "pv");
		System.out.println("Notre Mage : " + mage1.getNom() + " poss�de " + mage1.getPointsDeMagie() + "pm");
		System.out.println("Notre Archer : " + archer1.getNom() + " est niveau " + archer1.getNiveau() + " et poss�de " + archer1.getDexterite() + " points de dext�rit� !");
		
		System.out.println("\n" + archer1.getNom() + " et " + guerrier1.getNom() + " veulent se battre !");
		archer1.soustrairePointsDeVie(guerrier1.getForce());
		guerrier1.soustrairePointsDeVie(archer1.getDexterite() - guerrier1.getDexterite());
		archer1.ajouterExperience(2);
		guerrier1.ajouterExperience(2);
		System.out.println("Alors que notre archer d�coche sa meilleure fl�che, il se fait attaqu� f�rocement par " + guerrier1.getNom() + ", \nles 2 se touchent mais " + guerrier1.getNom() + " poss�de une grosse armure");
		System.out.println(archer1.getNom() + " : " + archer1.getPointsDeVie() + "pv");
		System.out.println(guerrier1.getNom() + " : " + guerrier1.getPointsDeVie() + "pv");
		archer1.ajouterPointsDeVie(mage1.getIntelligence() *3);
		mage1.ajouterExperience(3);
		System.out.println("Alors que le Guerrier " + guerrier1.getNom() + " demande des applodissements du groupe qui s'est form� atour d'eux pendant le combat, \nle mage " + mage1.getNom() + " donne une potion de vie � l'archer, il se retrouve en pleine forme avec " + archer1.getPointsDeVie() + "pv.");
		guerrier1.soustrairePointsDeVie(archer1.getDexterite() * archer1.getIntelligence() *5);
		archer1.ajouterExperience(8);
		System.out.println(archer1.getNom() + " surprend " + guerrier1.getNom() + " avec une fl�che dans la main, faisant un coup critique et diminimum �norm�ment la vie de notre jeune Guerrier.\n" + archer1.getNom() + " augmente ainsi de 1 niveau !"); 
		System.out.println(guerrier1.getNom() + " : " + guerrier1.getPointsDeVie() + "pv");
		System.out.println("\n" + archer1.toString());		
	}

}
