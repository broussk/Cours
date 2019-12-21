package theSurvivor;

class Manager
{
    private int [][] island; 
    private int RimboRow;
    private int RimboColumn;
    private int cptOcean=0;

    public Manager(int nbRow, int nbColumn)
    {

	this.island=new int [nbRow][nbColumn];
	for (int i=0; i<nbRow; i++) {
		for (int j=0; j<nbColumn; j++) {
			this.island[i][j]=0;
		}
	}
	
    }

    public String toString()
    {
	return "Manager of the behaviour of the system";
    }

    public void init()
    {
	island[RimboRow][RimboColumn]=1;
	this.RimboRow=(int)(Math.random()*this.island.length);
	this.RimboColumn=(int)(Math.random()*this.island[0].length);
	this.island[this.RimboRow][this.RimboColumn]=2;
    }

    public boolean exploration(String direction)
    {
	boolean valid;

	island[RimboRow][RimboColumn]=1;

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

	island[RimboRow][RimboColumn]=2;

	if(valid)
	    {
		island[RimboRow][RimboColumn]=1;
	    }
	else
	    {
		System.out.println("Je suis au bord de l'océan");
		cptOcean++;
	    }
	if (cptOcean==2) {
		System.out.println("Oh bah mince, Rimbo so pa nager, Rimbo a noyer..."); //desactiver les boutons
		System.exit(0);
	}
	
	return true;
	
    }
    public int getPosition(int row, int column){
    	return this.island[row][column];
    }
}