package theSurvivor;

class RunTheSurvivor
{
    public static void main(String args[])
    {
	TheSurvivorConfiguration jeu=new TheSurvivorConfiguration();
	if(jeu==null)
	    {
		System.out.println("Erreur lors de l'instanciation du jeu");
	    }
    }
}