package theSurvivor;

class Manager
{
    private Etat[][] island;
    private int RimboRow;
    private int RimboColumn;

    public Manager(int nbRows, int nbColumns)
    {
	int i,j;

	 this.island=new Etat[nbRows][nbColumns];
		for(i=0;i<this.island.length;i++)
		    {
			for(j=0;j<this.island[i].length;j++)
			    {
				this.island[i][j]=Etat.NON_VISITE;
			    }
		    }

		this.RimboRow=this.RimboColumn=0;
		init();



    }

    public String toString()
    {
	return "Manager of the behaviour of the system";
    }

    public void init()
    {

	this.RimboRow=(int)(Math.random()*this.island.length);
	this.RimboColumn=(int)(Math.random()*this.island[0].length);

	this.island[this.RimboRow][this.RimboColumn]=Etat.RIMBO;
    }

    public Etat getZoneState (int i, int j){
      return island[i][j];
    }

    public boolean exploration(String direction)
    {
	boolean valid;

	island[RimboRow][RimboColumn]=Etat.VISITE;

	valid=false;
	if(direction.compareTo("haut")==0)
	    {
		if(this.RimboRow>0)
		    {
			valid=true;
			this.RimboRow-=1;
			System.out.println("Vers le nord");
		    }
	    }
	else if (direction.compareTo("gauche")==0)
	    {
		if(this.RimboColumn>0)
		    {
			valid=true;
			this.RimboColumn-=1;
			System.out.println("Vers l'ouest");
		    }
	    }
	else if (direction.compareTo("bas")==0)
	    {
		if(this.RimboRow<(this.island.length-1))
		    {
			valid=true;
			this.RimboRow+=1;
			System.out.println("Vers le sud");
		    }
	    }
	else
	    {
		if(this.RimboColumn<(this.island[0].length-1))
		    {
			valid=true;
			this.RimboColumn+=1;
			System.out.println("Vers l'est");
		    }
	    }

	island[RimboRow][RimboColumn]=Etat.RIMBO;

	if(valid)
	    {
	       return true;
	    }
	else
	    {
		      System.out.println("Je suis au bord de l'océan");
          return false;
	    }

    }

}
