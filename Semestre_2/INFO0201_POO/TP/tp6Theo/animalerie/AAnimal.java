package animalerie;

public abstract class AAnimal {
  private int nbPattes=4;
  private int nbAiles=0;
  private String nom;

  public AAnimal(int nbP, int nbA, String n) {
    if(nbA>=0){nbAiles=nbA;}
    if(nbP>=0){nbPattes=nbP;}
    nom=n;
  }

  public AAnimal(){nom="Bidule";}

  public int getNbPattes(){return nbPattes;}

  public int getNbAiles(){return nbAiles;}

  public String getNom(){return nom;}

  public void setNom(String n){nom=n;}

  public String toString(){
    return (nom+", animal a "+nbPattes+" patte(s) et "+nbAiles+" aile(s).");
  }

  public void afficher(){System.out.println(this);}
  
  /*public void arracheAile(){
	  if(nbAiles>0){
		  nbAiles-=1;
		  System.out.print(nom +" : ");
		  crier();
	  }
  }
  
    public void arrachePatte(){
	  if(nbPattes>0){
		  nbPattes-=1;
		  System.out.print(nom +" : ");
		  crier();
	  }
  }*/

  public abstract void crier();

}
