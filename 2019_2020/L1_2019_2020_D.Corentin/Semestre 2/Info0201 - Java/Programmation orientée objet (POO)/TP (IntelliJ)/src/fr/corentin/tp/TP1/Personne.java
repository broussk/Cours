package fr.corentin.tp.TP1;

public class Personne {
  private String nom;
  private String prenom;
  private String civilite;
  private int age;
  private double poids;
  private double taille;

  public Personne(String nom, String prenom, String civilite, int age, double poids, double taille){
    this.nom = nom;
    this.prenom = prenom;

    if(!(civilite.equals("Mme") || civilite.equals("Mr") || civilite.equals("Mlle"))){
      civilite = "neutre";
    } else {
      this.civilite = civilite;
    }

    if (age <= 0||age >=150){
      age = 1;
    } else{
      this.age = age;
    }

    if (poids <=0.0){
      poids = 1.0;
    } else{
      this.poids = poids;
    }

    if (taille <= 0.0||taille>=3.0){
      taille = 1.0;
    } else{
      this.taille = taille;
    }
  }

  public Personne(){
    this("X", "x","neutre",1, 1.0,1.0);
  }

  public String getNom(){
    return nom;
  }

  public String getPrenom(){
    return prenom;
  }

  public String getCivilite(){
    return civilite;
  }

  public int getAge(){
    return age;
  }

  public double getPoids(){
    return poids;
  }

  public double getTaille(){
    return taille;
  }

  public void setNom(String nom){
    this.nom = nom;
  }

  public void setPrenom(String prenom){
    this.prenom = prenom;
  }


  public void setCivilite(String civilite){
    if(!(civilite.equals("Mme") || civilite.equals("Mr") || civilite.equals("Mlle"))){
      civilite = "neutre";
    } else {
    this.civilite = civilite;
    }
  }

  public void setAge(int age){
    if (age <= 0||age >=150){
      age = 1;
    } else{
      this.age = age;
    }
  }

  public void setPoids(double poids){
    if (poids <=0.0){
      poids = 1.0;
    } else{
      this.poids = poids;
    }
  }

  public void setTaille(double taille){
    if (taille <= 0.0||taille>=3.0){
      taille = 1.0;
    } else{
      this.taille = taille;
    }
  }

  public String toString(){
    return civilite+" "+prenom+" "+nom+" : "+age+" ans, "+taille+" metre, "+poids+" kg";
  }

  public void afficher(){
    System.out.println(toString());
  }

  public double IMC(){
    double masse = Math.round(getPoids()/(Math.pow(getTaille(), 2)));
    return masse;
  }

  public String typeIMC(){
    String typeIMC = "Non Valide";
    if (IMC()<16.5)
      typeIMC = "Denutrition";
    else if (IMC()>16.5 && IMC()<18.5)
      typeIMC = "Maigreur";
    else if (IMC()>18.5 && IMC()<25)
      typeIMC = "Corpulence normal";
    else if (IMC()>25 && IMC()<30)
      typeIMC = "Surpoids";
    else if (IMC()>30 && IMC()<35)
      typeIMC = "Obesite moderee";
    else if (IMC()>35 && IMC()<40)
      typeIMC = "Obesite severe";
    else if (IMC()>40)
      typeIMC = "Obesite morbide";
    return typeIMC;
  }

  public String toString2(){
    return "l'IMC de "+nom+" "+prenom+" est de "+IMC()+". L'IMC de cette personne est de type: "+typeIMC();
  }
  public void afficherIMC(){
    System.out.println(toString2());
  }












































}
