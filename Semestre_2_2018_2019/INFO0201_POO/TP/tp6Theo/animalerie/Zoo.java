package animalerie;

import java.lang.Math;

public class Zoo implements IZoo{
  //Constantes
  public static final int NB_CAGES_MAX = 20;
  public static final int NB_CAGES_MIN = 10;

  //Attributs
  private AAnimal[] animaux;
  private int nbCages;

  //Constructeur par initialisation
  public Zoo(int nbCages){
    this.nbCages=(int)(Math.random()*(NB_CAGES_MAX-NB_CAGES_MIN)+NB_CAGES_MIN);
    if(nbCages>=NB_CAGES_MIN && nbCages<=NB_CAGES_MAX){
      this.nbCages=nbCages;
    }else{
      System.out.println("Nombre de cages invalide, nombre aleatoire genere : "+this.nbCages);
    }
    animaux=new AAnimal[this.nbCages];
  }

  //Constructeur par défaut
  public Zoo(){
    this.nbCages=(int)(Math.random()*(NB_CAGES_MAX-NB_CAGES_MIN)+NB_CAGES_MIN);
    animaux=new AAnimal[this.nbCages];
  }

  //getters

  public int getNbCages(){
    return nbCages;
  }

  public AAnimal getAnimal(int i){
    AAnimal ref=null;
    if(i>=0 && i<nbCages){
      ref=animaux[i];
    }
    return ref;
  }

  public void ajouterAnimal(AAnimal a, int i){
    if(i>=0 && i<nbCages && animaux[i]==null){
      animaux[i]=a;
    }else if(i<0){
      System.out.println("L'animal n'a pas pu etre ajoute car indice negatif");
    }else if(i>=nbCages){
      System.out.println("L'animal n'a pas pu etre ajoute car indice plus grand que le nombre de cages");
    }else{
      System.out.println("L'animal n'a pas pu etre ajoute car la cage "+i+" est deja occupee");
    }
  }

  public void supprimerAnimal(int i){
    if(i>=0 && i<nbCages && animaux[i]!=null){
      animaux[i]=null;
    }else if(i<0 || i>=nbCages){
      System.out.println("La cage "+i+" n'existe pas");
    }else if(animaux[i] == null){
      System.out.println("La cage "+i+" est deja vide");
    }
  }

  public void faireCrier(){
    for(int i=0;i<nbCages;i++){
      if(animaux[i]!=null){
        animaux[i].crier();
      }
    }
  }

  public String toString(){
    String str="Zoo de "+nbCages+" cages [\n";
    for(int i=0;i<nbCages;i++){
      if(animaux[i]!=null){
        str+=animaux[i].toString()+"(cage "+String.valueOf(i)+")";
        if(i!=nbCages-1){
          str+="\n";
        }
      }
    }
    str+="]";
    return str;
  }
  
  public void desastre(){
	int cage = (int)(Math.random()*(nbCages-1));  
	double membreArrache = (Math.random()*2)-1;
	if(membreArrache>0){
		if(animaux[cage]!=null){
			animaux[cage].arrachePatte();
		}
	}else{
		if(animaux[cage]!=null){
			animaux[cage].arracheAile();
		}
	}
  }
  
  public int getNombrePattes(){
	  int somme=0;
	  for(int i=0;i<nbCages;i++){
		  if(animaux[i]!=null){
			  somme+=animaux[i].getNbPattes();
		  }
	  }
	  return somme;
  }
  
  public int getNombreAiles(){
	  int somme=0;
	  for(int i=0;i<nbCages;i++){
		  if(animaux[i]!=null){
			  somme+=animaux[i].getNbAiles();
		  }
	  }
	  return somme;
  }
  
}
