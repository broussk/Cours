import java.util.Scanner;
class testPoint{
	public static void main (String[] args){
	/*//point cartesien
		PointCartesien point1= new PointCartesien();
		PointCartesien point2= new PointCartesien(-1,2);
		
		point1.afficher();
		point1.setX(2);
		point1.setY(2);
		point1.afficher();
		System.out.println(point2.distanceALOrigine()+" est la distance a l'origine du point 2");
		point1.translation(-1, 2);
		point1.afficher();
		
	//point polaire
		PointPolaire point3 = new PointPolaire();
		PointPolaire point4 = new PointPolaire(2,2);
		PointPolaire point5 = new PointPolaire(point4);
		
		point5.afficher();
		point5.setX(1);
		point5.setY(3);
		point5.afficher();
		System.out.println(point5.distanceALOrigine()+" est la distance a l'origine du point 5");
		System.out.println(point5.angle()+" est l'angle du point5");
		point5.afficher();
		point3.translation(point4.getX(), point4.getY());
		point3.afficher();
	*/
	//tableau de IPoint
		Scanner clavier = new Scanner(System.in);
		IPoint [] points = new IPoint[5];
		int rep=1;
		double x=1,y=1;
		for(int i=0;i<points.length;i++){
			System.out.println("Point cartesien : 1 ; Point polaire : 2");
			rep=clavier.nextInt();
			if (rep==1) {
			 	System.out.print("x:");
				x=clavier.nextDouble();
				System.out.print("y:");
				y=clavier.nextDouble();
				points[i] = new PointCartesien(x,y);
			}
			else {
				System.out.print("x:");
				x=clavier.nextDouble();
				System.out.print("y:");
				y=clavier.nextDouble();
				points[i] = new PointPolaire(x,y);
			}
		}
		for (int j=0; j<points.length; j++) {
			points[j].afficher();
		}
	}
}
