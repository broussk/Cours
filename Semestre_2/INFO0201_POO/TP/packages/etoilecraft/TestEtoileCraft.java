import etoilecraft.*;
public class TestEtoileCraft{
	public static void main (String [] args){
		AUniteTerran unite1 = new AUniteTerran(200,10,20,20);
		AUniteTerran unite2 = new AUniteTerran(400,5,20,20);
		do{
			unite1.attaquer(unite2);
			System.out.println(unite2.toString());
			unite2.attaquer(unite1);
			System.out.println(unite1.toString());
		}while(unite1.getPointDeVie()<=0 || unite2.getPointDeVie()<=0);
	}
}