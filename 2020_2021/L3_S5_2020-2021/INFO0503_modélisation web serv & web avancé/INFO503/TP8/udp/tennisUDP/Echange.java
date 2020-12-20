/*
 * comilation : javac *.java
 * execution serveur : java Serveur
 * execution client : java Client
 * generation javadoc : javadoc *.java -d Doc
 */



import java.util.Random;

/**
 * Classe permettant de jouer au Tennis entre Client
 * @author Nathan TONNELLE
 */
public class Echange {
    private static final int scoreMax = 5;
    private static final int positionDefaut = 3;
    private String echangeString;
    private int scoreMaxPartie;
    private int scoreClient1;
    private int scoreClient2;
    private int positionClient1;
    private int positionClient2;
    private int tirClient1;
    private int tirClient2;

    /**
     * création d'un echange
     */
    public Echange(){
        this.scoreMaxPartie = Echange.scoreMax;
        this.scoreClient1 = 0;
        this.scoreClient2 = 0;
        resetEchange();
    }

    /**
     * création d'un echange
     * @param nbPointsMax nombre de points maximum dans la partie
     */
    public Echange(int nbPointsMax) {
        this.scoreMaxPartie = nbPointsMax;
        this.scoreClient1 = 0;
        this.scoreClient2 = 0;
        resetEchange();
    }

    /**
     * Ouverture/création d'un echange
     * @param creation si 'true', cree un nouvel echange vide . si 'false' si la création dois se faire à partir d'une chaine de caractère valide (JSON)
     * @param chaineDeChargement chaine permettant le chargement de l'objet
     */
    public Echange(boolean creation, String chaineDeChargement) {
        if(!creation) {
            this.scoreMaxPartie = Echange.scoreMax;
            charger(1, chaineDeChargement);
            charger(2, chaineDeChargement);
        }
        else {
            this.echangeString = "";
            this.scoreMaxPartie = Echange.scoreMax;
            this.scoreClient1 = 0;
            this.scoreClient2 = 0;
            this.positionClient1 = Echange.positionDefaut;
            this.positionClient2 = Echange.positionDefaut;
            this.tirClient1 = -1;
            this.tirClient2 = -1;
        }
    }
    
    /**
     * Ouverture/creation d'un fichier d'echange.
     * @param creation si 'true', cree un nouvel echange vide
     * @param nbPointsMax le nombre de points maximum 
     * @param chaineDeChargement chaine permettant le chargement de l'objet
     */
    public Echange(boolean creation, int nbPointsMax, String chaineDeChargement) {
        if(!creation) {
            this.scoreMaxPartie = nbPointsMax;
            charger(1, chaineDeChargement);
            charger(2, chaineDeChargement);
        }
        else {
            this.echangeString = "";
            this.scoreMaxPartie = Echange.scoreMax;
            this.scoreClient1 = 0;
            this.scoreClient2 = 0;
            this.positionClient1 = Echange.positionDefaut;
            this.positionClient2 = Echange.positionDefaut;
            this.tirClient1 = -1;
            this.tirClient2 = -1;
        }
    }

    /**
     * retourne l'echange sous forme de string en format JSON
     * @param entityJoueur identite du joueur
     * @return un chaine de caractère de l'echange
     */
    public String getEchangeString(int entityJoueur){
        this.echangeString = "";
        if(entityJoueur == 1 || entityJoueur == 2)
            construireChaineEnvoie(entityJoueur);
        else System.out.println("[ERREUR FCT: GET ECHANGE STRING] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
        return this.echangeString;
    }

    /**
     * retourne le score maximum de la partie
     * @return la valeur du score maximum de la partie
     */
    public int getScoreMaxPartie(){
        return this.scoreMaxPartie;
    }

    /**
     * retourne le score du joueur
     * @param entityJoueur identite du joueur
     * @return la valeur du score du joueur
     */
    public int getScore(int entityJoueur){
        int valeur = -1;
        if(entityJoueur == 1)
            valeur = this.scoreClient1;
        else if(entityJoueur == 2)
            valeur = this.scoreClient2;
        else
            System.out.println("[ERREUR FCT: SET POSITION] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
        return valeur;
    }

    /**
     * retourne la position du joueur
     * @param entityJoueur identite du joueur
     * @return la valeur de la position du joueur
     */
    public int getPosition(int entityJoueur){
        int valeur = -1;
        if(entityJoueur == 1)
            valeur = this.positionClient1;
        else if(entityJoueur == 2)
            valeur = this.positionClient2;
        else
            System.out.println("[ERREUR FCT: SET POSITION] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
        return valeur;
    }

    /**
     * retourne la position du tir du joueur
     * @param entityJoueur identite du joueur
     * @return la valeur de la position du tir du joueur
     */
    public int getTir(int entityJoueur){
        int valeur = -1;
        if(entityJoueur == 1)
            valeur = this.tirClient1;
        else if(entityJoueur == 2)
            valeur = this.tirClient2;
        else
            System.out.println("[ERREUR FCT: SET POSITION] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
        return valeur;
    }

    //pas besoin
    /**
     * change le score maximum de la partie
     * @param maxPoints la valeur du score maximum de la partie
     */
    public void setScoreMaxPartie(int maxPoints){
        this.scoreMaxPartie = maxPoints;
    }

    //pas besoin
    /**
     * change le score du joueur
     * @param entityJoueur identite du joueur
     * @param nbPoints la valeur du score du joueur
     */
    public void setScore(int entityJoueur, int nbPoints){
        if(entityJoueur == 1)
            if(nbPoints > 0)
                this.scoreClient1 = nbPoints;
            else
                System.out.println("[ERREUR FCT: SET SCORE] nombre de points invalide, le nombre de points doit être positif.");
        else if(entityJoueur == 2)
            if(nbPoints > 0)
                this.scoreClient2 = nbPoints;
            else 
                System.out.println("[ERREUR FCT: SET SCORE] nombre de points invalide, le nombre de points doit être positif.");
        else
            System.out.println("[ERREUR FCT: SET SCORE] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
    }

    /**
     * change la position du joueur
     * @param entityJoueur identite du joueur
     * @param position la valeur de la position
     */
    public void setPosition(int entityJoueur, int position){
        if(entityJoueur == 1)
            if(verifPosition(position))
                this.positionClient1 = position;
            else
                System.out.println("[ERREUR FCT: SET POSITION] Position incorrecte, elle doit être entre 1 et 5.");
        else if(entityJoueur == 2)
            if(verifPosition(position))
                this.positionClient2 = position;
            else
                System.out.println("[ERREUR FCT: SET POSITION] Position incorrecte, elle doit être entre 1 et 5.");
        else
            System.out.println("[ERREUR FCT: SET POSITION] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
    }

    /**
     * change la position du tir du joueur
     * @param entityJoueur identite du joueur
     * @param position la valeur de la position du tir
     */
    public void setTir(int entityJoueur, int position){
        if(entityJoueur == 1)
            if(verifPosition(position))
                this.tirClient1 = position;
            else
                System.out.println("[ERREUR FCT: SET TIR] Position incorrecte, elle doit être entre 1 et 5.");
        else if(entityJoueur == 2)
            if(verifPosition(position))
                this.tirClient2 = position;
            else
                System.out.println("[ERREUR FCT: SET TIR] Position incorrecte, elle doit être entre 1 et 5.");
        else
            System.out.println("[ERREUR FCT: SET TIR] Joueur introuvable, l'entityJoueur doit être égal à 1 ou 2.");
    }

    /**
     * retourne une chaine de caractere decrivant l'echange en cours
     * @param entityJoueur identite du joueur
     * @return description de l'echange avec le coup du joueur adverse
     */
    public String toString(int entityJoueur){
        String toStringString = "";
        if(entityJoueur == 1){
            toStringString =
                "\nEchange en Cours : " + 
                "\n\t Score : \t(J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)" +
                "\n\t Tir J2 : " + tir_position_ToString(this.tirClient2) + 
                "\n";

        }
        else if(entityJoueur == 2){
            toStringString =
                "\nEchange en Cours : " + 
                "\n\t Score : \t(J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)" +
                "\n\t Tir J1 : " + tir_position_ToString(this.tirClient1) + 
                "\n";
        }
        else{
            System.out.println("[ERREUR FCT: TO STRING] L'identité du joueur est inconnue, l'entityJoueur doit être égal à 1 ou 2.");
        }
        return toStringString;
    }

    /**
     * retourne une chaine de caractere decrivant l'echange en cours
     * @param entityJoueur identite du joueur
     * @return description de l'echange sans le tir du joueur adverse
     */
    public String toString_Masquer(int entityJoueur){
        String toStringString = "";
        if(entityJoueur == 1){
            toStringString =
                "\nEchange en Cours : " + 
                "\n\t Score : \t(J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)" +
                "\n\t Tir J2 : ************" + 
                "\n";

        }
        else if(entityJoueur == 2){
            toStringString =
                "\nEchange en Cours : " + 
                "\n\t Score : \t(J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)" +
                "\n\t Tir J1 : ************" + 
                "\n";
        }
        else{
            System.out.println("[ERREUR FCT: TO STRING MASQUER] L'identité du joueur est inconnue, l'entityJoueur doit être égal à 1 ou 2.");
        }
        return toStringString;
    }

    /**
     * retourne un String décrivant le coup
     * @param position la position choisi
     * @return une description du coup
     */
    public String tir_position_ToString(int position){
        String returnValue = "";
        switch(position){
            case 1 :
                returnValue = "gauche";
                break;
            case 2 :
                returnValue = "milieu-gauche";
                break;
            case 3 :
                returnValue = "milieu";
                break;
            case 4 :
                returnValue = "milieu-droite";
                break;
            case 5 :
                returnValue = "droite";
                break;
            case -10 :
                returnValue = "Aucun";
                break;
        }
        return returnValue;
    }

    /**
     * retourne une chaine de caractere decrivant le score en cours
     * @return description du score en cours
     */
    public String scoreToString(){
        String toStringString = "";
        toStringString =
            "\nEchange en Cours : " + 
            "\n\t Score : \t(J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)" + 
            "\n";
        return toStringString;
    }

    /**
     * Ajoute 1 point au joueur ciblé
     * @param entityJoueur identite du joueur
     */
    public void addPoint(int entityJoueur){
        if(entityJoueur == 1 || entityJoueur == 2){
            switch(entityJoueur){
                case 1 : 
                    setScore(1, this.scoreClient1 + 1);
                    break;
                case 2 :
                    setScore(2, this.scoreClient2 + 1);
                    break;
            }
        }
        else{
            System.out.println("[ERREUR FCT: ADD POINT] Le joueur n'est pas correcte, entityJoueur doit être égal à 1 ou 2. \n");
        }
    }

    /**
     * augmente ou diminue la position du joueur
     * @param entityJoueur identite du joueur
     * @param upDownPosition si la position doit monter ou descendre de 1 (symbolisé par 0: descendre et 1: monter, -1: rester)
     */
    public void upDownPosition(int entityJoueur, int upDownPosition){
        if(entityJoueur == 1 || entityJoueur == 2){
            if(upDownPosition == 0 || upDownPosition == 1){
                switch(entityJoueur){
                    case 1 : 
                        switch(upDownPosition){
                            case -1: setPosition(1, this.positionClient1);    break;
                            case 0: setPosition(1, this.positionClient1 -1);    break;
                            case 1: setPosition(1, this.positionClient1 +1);    break;
                        }
                        break;
                    case 2 :
                        switch(upDownPosition){
                            case -1: setPosition(2, this.positionClient2);    break;
                            case 0: setPosition(2, this.positionClient2 -1);    break;
                            case 1: setPosition(2, this.positionClient2 +1);    break;
                        }
                        break;
                }
            }
            else{
                System.out.println("[ERREUR FCT: UP DOWN POSITION] L'ordre de repositionnement n'est pas correcte, il doit être égal à 0 (descendre) ou 1 (monter) ou -1. \n");
            }
        }
        else{
            System.out.println("[ERREUR FCT: UP DOWN POSITION] Le joueur n'est pas correcte, entityJoueur doit être égal à 1 ou 2. \n");
        }

    }

    /**
     * affiche le gagnant
     */
    public void afficherGagnant(){
        if(scoreGagnant(this.scoreClient1, this.scoreClient2)){
            spaceX(10);
            System.out.println("\tLa partie est finie, \n\tLe gagnant est le joueur 1");
            System.out.println(afficherScoreFinal());
            spaceX(10);
        }
        else if(scoreGagnant(this.scoreClient2, this.scoreClient1)){
            spaceX(10);
            System.out.println("\tLa partie est finie, \n\tLe gagnant est le joueur 2");
            System.out.println(afficherScoreFinal());
            spaceX(10);
        }
        else{
            System.out.println("\n\t\tToujours pas de gagnant, le jeu continue...\n");
        }
    }

    /**
     * retourne si le score gagnant est correcte
     * au minimum de la valeur de MaxPoints
     * et avec une difference de 2 avec le score de l'adversaire
     * @param gagnant valeur d'un score
     * @param perdant valeur de l'autre score
     * @return 'true' si score du gagnant est correct
     */
    public boolean scoreGagnant(int gagnant, int perdant){
        boolean rep = false;

        if(gagnant >= this.scoreMaxPartie){
            if(gagnant >= (perdant + 2)){
                rep = true;
            }
        }

        return rep;
    }

    /**
     * retourne un String de score final
     * @return description finale de l'échange
     */
    public String afficherScoreFinal(){
        return (
            "\n ~~~~\tLe Score Final est de :\t~~~~ \n" + 
            "\t    (J1) " + this.scoreClient1 + " - " + this.scoreClient2 + " (J2)\n"
        );
    }

    /**
     * regarde s'il y a un des joueur qui a atteind le score maximum 
     * avec une difference de 2 avec son adversaire
     * @return 'true' s'il y a un gagnant
     */
    public boolean partieFini(){
        boolean rep = false;

        if(this.scoreClient1 >= this.scoreMaxPartie || this.scoreClient2 >= this.scoreMaxPartie){
            if((this.scoreClient1 >= (this.scoreClient2 +2)) 
                || (this.scoreClient2 >= (this.scoreClient1 +2))){
                    rep = true;
            }
        }

        return rep;
    }

    /**
     * Met :
     * echangeString = "" ;
     * positionClient1 et positionClient2 = la position par defaut ;
     * tirClient1 et tirClient2 à -1 ;
     */
    public void resetEchange(){
        this.echangeString = "";
        this.positionClient1 = Echange.positionDefaut;
        this.positionClient2 = Echange.positionDefaut;
        this.tirClient1 = -10;
        this.tirClient2 = -10;
    }

    /**
     * Charge un chaine de caractères au format json en mémoire.
     * @param entityJoueur identite du joueur
     * @param chaineDeChargement chaine de caracteres au format JSON, permettant de charger un echange
     */
    private void charger(int entityJoueur, String chaineDeChargement) {
        if(entityJoueur == 1){
            if(verifChaineJson(chaineDeChargement)){
                this.echangeString = "";
                this.tirClient2 = -1;
                this.scoreClient1 = -1;
                this.scoreClient2 = -1;

                chaineDeChargement = chaineDeChargement.replace("{", "").replace("}", "");
                String[] parseChaine = chaineDeChargement.split(",");
                String[] recupScoreClient1 = parseChaine[0].split(":");
                String[] recupScoreClient2 = parseChaine[1].split(":");
                String[] recupTirClient2 = parseChaine[2].split(":");

                if(recupScoreClient1[0].equals("scoreClient1")) this.scoreClient1 = Integer.parseInt(recupScoreClient1[1]);
                else System.out.println("[ERREUR FCT: CHARGER] Score Client-1 non trouvé.");
                if(recupScoreClient2[0].equals("scoreClient2")) this.scoreClient2 = Integer.parseInt(recupScoreClient2[1]);
                else System.out.println("[ERREUR FCT: CHARGER] Score Client-2 non trouvé.");
                if(recupTirClient2[0].equals("tirClient")) this.tirClient2 = Integer.parseInt(recupTirClient2[1]);
                else System.out.println("[ERREUR FCT: CHARGER] tir Client-2 non trouvé.");
            }
            else{
                System.out.println("[ERREUR FCT: CHARGER] Impossible de charger, chaine de caractère invalide, format non correct, format attendu : JSON.");
            }
        }
        else if(entityJoueur == 2){
            if(verifChaineJson(chaineDeChargement)){
                this.echangeString = "";
                this.tirClient1 = -1;
                this.scoreClient1 = -1;
                this.scoreClient2 = -1;

                chaineDeChargement = chaineDeChargement.replace("{", "").replace("}", "");
                String[] parseChaine = chaineDeChargement.split(",");
                String[] recupScoreClient1 = parseChaine[0].split(":");
                String[] recupScoreClient2 = parseChaine[1].split(":");
                String[] recupTirClient1 = parseChaine[2].split(":");

                if(recupScoreClient1[0].equals("scoreClient1")) this.scoreClient1 = Integer.parseInt(recupScoreClient1[1]);
                else System.out.println("[ERREUR FCT: CHARGER] Score Client-1 non trouvé.");
                if(recupScoreClient2[0].equals("scoreClient2")) this.scoreClient2 = Integer.parseInt(recupScoreClient2[1]);
                else System.out.println("[ERREUR FCT: CHARGER] Score Client-2 non trouvé.");
                if(recupTirClient1[0].equals("tirClient")) this.tirClient1 = Integer.parseInt(recupTirClient1[1]);
                else System.out.println("[ERREUR FCT: CHARGER] tir Client-1 non trouvé.");
            }
            else{
                System.out.println("[ERREUR FCT: CHARGER] Impossible de charger, chaine de caractère invalide, format non correct, format attendu : JSON.");
            }
        }
        else{
            System.out.println("[ERREUR FCT: CHARGER] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
        }
    }


    /**
     * vérifie le format de la chaine de caractère transmise, si c'est du JSON, alors c'est correcte, sinon non
     * @param chaineJson chaine à vérifier
     * @return retourne le résultat de la vérification
     */
    public static boolean verifChaineJson(String chaineJson){
        boolean verif = false;
        if(chaineJson.contains("{") && chaineJson.contains("}")) verif = true;
        return verif;
    }

    /**
     * Reharge une chaine de caractères d'echange en mémoire.
     * @param entityJoueur identite du joueur
     * @param chaineDeChargement chaine servant a charger l'echange en cours
     */
    public void recharge(int entityJoueur, String chaineDeChargement){
        if(entityJoueur == 1 || entityJoueur == 2) charger(entityJoueur, chaineDeChargement);
        else System.out.println("[ERREUR FCT: RECHARGE] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
    }

    /**
     * Construit l'echangeStirng de l'échange avec les valeurs de l'objet.
     * Pour le Client-1, son tir sera construit dans l'echange.
     * Pour le Client-2, son tir sera construit dans l'echange.
     * @param entityJoueur identite du joueur
     */
    public void construireChaineEnvoie(int entityJoueur){
        if(entityJoueur == 1){
            this.echangeString = "{";
            this.echangeString += "scoreClient1:" + this.scoreClient1 + ",";
            this.echangeString += "scoreClient2:" + this.scoreClient2 + ",";
            this.echangeString += "tirClient:" + this.tirClient1;
            this.echangeString += "}";
        }
        else if(entityJoueur == 2){
            this.echangeString = "{";
            this.echangeString += "scoreClient1:" + this.scoreClient1 + ",";
            this.echangeString += "scoreClient2:" + this.scoreClient2 + ",";
            this.echangeString += "tirClient:" + this.tirClient2;
            this.echangeString += "}";
        }
        else{
            System.out.println("[ERREUR FCT: CONSTRUIRE CHAINE ENVOIE] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
        }
    }

    /**
     * Construit l'echangeString de l'échange avec les valeurs de l'objet.
     * @param entityJoueur identite du joueur
     * @param tirJoueur numero de position du tir
     */
    public void construireChaineEnvoie(int entityJoueur, int tirJoueur){
        if(entityJoueur == 1 || entityJoueur == 2){
            this.echangeString = "{";
            this.echangeString += "scoreClient1:" + this.scoreClient1;
            this.echangeString += "scoreClient2:" + this.scoreClient2;
            this.echangeString += "tirClient:" + tirJoueur;
            this.echangeString += "}";
        }
        else{
            System.out.println("[ERREUR FCT: CONSTRUIRE CHAINE ENVOIE] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
        }
    }

    /**
     * retourne un aléatoire pour le coup
     * @return le numéro du coup
     */
    public int coupAleatoire(){
        Random rand = new Random(); 
        return (rand.nextInt(5) + 1);
    }

    /**
     * regarde si la position du tir de l'adversaire a ete devine
     * @param entityJoueur identite du joueur qui a tire
     * @param position la position devine par le joueur
     * @return 'true' si la position a ete devine par le joueur; 'false' sinon et attribue un point au joueur adverse
     */
    public boolean positionTirAdverseDevine(int entityJoueur, int position){
        boolean devineRep = false;
        String affichage = "";
        if(entityJoueur == 1){
            if(this.tirClient2 == position){
                affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                affichage += "\n\tVous pouvez jouer\n";
                devineRep = true;
            }
            else if((this.tirClient2 -1) == position || (this.tirClient2 +1) == position){
                Random rand = new Random(); 
                int nombreAleatoire = rand.nextInt(2);
                switch(nombreAleatoire){
                    case 0 :
                        affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                        affichage += "\n\tVous pouvez jouer\n";
                        devineRep = true;
                        break;
                    case 1 :
                        affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                        affichage += "\n\tVotre adversaire gagne le point";
                        affichage += "\n\tC'est à lui de relancer\n";
                        addPoint(2);
                        devineRep = false;
                        break;
                }
            }
            else{
                affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                affichage += "\n\tVotre adversaire gagne le point";
                affichage += "\n\tC'est à lui de relancer\n";
                addPoint(2);
                devineRep = false;
            }
        }
        else if(entityJoueur == 2){
            if(this.tirClient1 == position){
                affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                affichage += "\n\tVous pouvez jouer\n";
                devineRep = true;
            }
            else if((this.tirClient1 -1) == position || (this.tirClient1 +1) == position){
                Random rand = new Random(); 
                int nombreAleatoire = rand.nextInt(2);
                switch(nombreAleatoire){
                    case 0 :
                        affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                        affichage += "\n\tVous pouvez jouer\n";
                        devineRep = true;
                        break;
                    case 1 :
                        affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                        affichage += "\n\tVotre adversaire gagne le point";
                        affichage += "\n\tC'est à lui de relancer\n";
                        addPoint(1);
                        devineRep = false;
                        break;
                }
            }
            else{
                affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                affichage += "\n\tVotre adversaire gagne le point";
                affichage += "\n\tC'est à lui de relancer\n";
                addPoint(1);
                devineRep = false;
            }
        }
        else{
            System.out.println("[ERREUR FCT:POSITION TIR ADVERSE DEVINE] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
            devineRep = false;
        }
        System.out.println(affichage);
        if(!partieFini()) resetEchange();
        return devineRep;
    }

    /**
     * regarde si la position du tir de l'adversaire a ete devine
     * @param entityJoueur identite du joueur qui a tire
     * @return 'true' si la position a ete devine par le joueur; 'false' sinon et attribue un point au joueur adverse
     */
    public boolean positionTirAdverseDevine(int entityJoueur){
        boolean devineRep = false;
        String affichage = "";
        if(entityJoueur == 1){
            if(this.tirClient2 == this.positionClient1){
                affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                affichage += "\n\tVous pouvez jouer\n";
                devineRep = true;
            }
            else if((this.tirClient2 -1) == this.positionClient1 || (this.tirClient2 +1) == this.positionClient1){
                Random rand = new Random(); 
                int nombreAleatoire = rand.nextInt(2);
                switch(nombreAleatoire){
                    case 0 :
                        affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                        affichage += "\n\tVous pouvez jouer\n";
                        devineRep = true;
                        break;
                    case 1 :
                        affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                        affichage += "\n\tVotre adversaire gagne le point";
                        affichage += "\n\tC'est à lui de relancer\n";
                        addPoint(1);
                        devineRep = false;
                        break;
                }
            }
            else{
                affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient2);
                affichage += "\n\tVotre adversaire gagne le point";
                affichage += "\n\tC'est à lui de relancer\n";
                addPoint(1);
                devineRep = false;
            }
        }
        else if(entityJoueur == 2){
            if(this.tirClient1 == this.positionClient2){
                affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                affichage += "\n\tVous pouvez jouer\n";
                devineRep = true;
            }
            else if((this.tirClient1 -1) == this.positionClient2 || (this.tirClient1 +1) == this.positionClient2){
                Random rand = new Random(); 
                int nombreAleatoire = rand.nextInt(2);
                switch(nombreAleatoire){
                    case 0 :
                        affichage = "\n\tVous vous êtes bien placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                        affichage += "\n\tVous pouvez jouer\n";
                        devineRep = true;
                        break;
                    case 1 :
                        affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                        affichage += "\n\tVotre adversaire gagne le point";
                        affichage += "\n\tC'est à lui de relancer\n";
                        addPoint(1);
                        devineRep = false;
                        break;
                }
            }
            else{
                affichage = "\n\tVous êtes mal placé, la position du tir de votre adversaire était : " + tir_position_ToString(this.tirClient1);
                affichage += "\n\tVotre adversaire gagne le point";
                affichage += "\n\tC'est à lui de relancer\n";
                addPoint(1);
                devineRep = false;
            }
        }
        else{
            System.out.println("[ERREUR FCT:POSITION TIR ADVERSE DEVINE] Joueur non trouvé, l'entityJoueur doit être égal à 1 ou 2.");
            devineRep = false;
        }
        System.out.println(affichage);
        if(!partieFini()) resetEchange();
        return devineRep;
    }

    /**
     * nouvel Echange
     * @param entityJoueur identite du joueur
     * @param coup numéro du coup qui sera donné
     */
    public void nouvelEchange(int entityJoueur, int coup){
        if(entityJoueur == 1){
            if(!partieFini()){
                this.tirClient1 = coup;
            }
        }
        else if(entityJoueur == 2){
            if(!partieFini()){
                this.tirClient2 = coup;
            }
        }
        else{
            System.out.println("[ERREUR FCT: NOUVEL ECHANGE] Joueur inexistant, entityJoueur doit être égal à 1 ou 2.");
        }
    }

    /**
     * Retourne si la position donnee est correcte
     * @param position une position sur le terrain
     */
    public boolean verifPosition(int position){
        boolean rep = false;
        if(position >= 1 && position <= 5) rep = true;
        return rep;
    }

    /**
     * affiche x fois le retour à la ligne.
     * @param x nombre de fois 
     */
    private void spaceX(int x){
        String spaceX = "";
        for(int i = 0; i < x; i++){
            spaceX += "\n";
        }
        System.out.print(spaceX);
    }
}