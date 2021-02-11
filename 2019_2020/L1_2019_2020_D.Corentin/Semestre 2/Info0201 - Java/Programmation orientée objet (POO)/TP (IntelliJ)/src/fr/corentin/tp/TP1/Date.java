package fr.corentin.tp.TP1;

public class Date {
  private int jour;
  private int mois;
  private int annee;

  public Date(int j, int m, int a){
    if (estValide()){
      jour = j;
    }else{
      correction();
    }

    if (estValide()){
      mois = m;
    }else{
      correction();
    }

    annee = a;
  }

  public Date(){
    this(01,01,1881);
  }

  public int getJour(){
    return jour;
  }

  public void setJour(int j){
    if (!(j > 31)||(j==0)){
      jour = j;
    }else{jour = 01;}
  }

  public int getMois(){
    return mois;
  }

  public void setMois(int m){
    if (!(m > 12)||(m==0)){
      mois = m;
    }else{mois = 01;}
  }

  public int getAnnee(){
    return annee;
  }

  public void setAnnee(int a){
    annee = a;
  }

  public boolean estBissextile(){
    boolean bi = false;
    if ((annee%4==0 && annee%100!=0) || (annee%400==0)){
      bi = true;
    }
    return bi;
  }

  public int nbJours(){
    int nbj = -1;
    switch(mois){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12: nbj = 31;
      break;
      case 2:
      if(estBissextile()){
        nbj = 29;
      } else {
        nbj = 28;
      }
      break;
      case 4: case 6: case 9: case 11: nbj = 30;
      break;
      default: System.out.print("ERREUR ! Ce mois n'existe pas ! ");
    }
    return nbj;
  }

  public boolean estValide(){
    boolean valJour = false;
    boolean valMois = false;
    boolean valAnnee = false;
    boolean valDate = false;
    if (getJour()>0 && getJour()<=nbJours()){
      valJour = true;
    }
    if (getMois()>0 && getMois()<=12){
      valMois = true;
    }
    if (getAnnee()>0){
      valAnnee = true;
    }
    if (valJour == true && valMois == true && valAnnee == true){
      valDate = true;
    }

    return valDate;
  }

  private void correction(){
    if (getJour()<=0 || getJour()>nbJours()){
      setJour(1);
    };
    if (getMois()<=0 || getMois()>12){
      setMois(1);
    }
  }


  public String toString(){
      String date;

      if((jour< 10)&&(mois< 10)){
        date = ("0"+jour+"/0"+mois+"/"+annee);
      } else if (jour< 10){
        date = ("0"+jour+"/"+mois+"/"+annee);
      } else if (mois< 10){
        date = (jour+"/0"+mois+"/"+annee);
      } else {
        date = (jour+"/"+mois+"/"+annee);
      }

    return date;
  }

  public void afficher(){
    System.out.println(this);
  }

}
