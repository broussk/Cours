import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

import org.json.JSONObject;
import org.json.JSONArray;

/**
 * Classe permettant de jouer au Tennis entre Client-Serveur
 * @author Nathan TONNELLE
 */
public class Echange {
    public static final int nbPointsMaxDefaut = 5;
    public static int nbPointsMax;

    private String nomFichier;
    private JSONObject echange; 
    private int[] score;
    private int coup;
    private String infos;
    private String commentaire;

    /**
     * Ouverture d'un fichier d'echange.
     */
    public Echange() {
        this.nomFichier = "echange.json";
        Echange.nbPointsMax = Echange.nbPointsMaxDefaut;
        charger();
    }

    /**
     * Ouverture d'un fichier d'echange.
     * @param nbPointsMax le nombre de points maximum
     */
    public Echange(int nbPointsMax) {
        this.nomFichier = "echange.json";
        Echange.nbPointsMax = nbPointsMax;
        charger();
    }

    /**
     * Ouverture d'un fichier d'echange.
     * @param nomFichier le nom du fichier d'echange
     */
    public Echange(String nomFichier) {
        this.nomFichier = nomFichier;
        Echange.nbPointsMax = Echange.nbPointsMaxDefaut;
        charger();
    }

    /**
     * Ouverture d'un fichier d'echange.
     * @param nomFichier le nom du fichier d'echange
     * @param nbPointsMax le nombre de points maximum
     */
    public Echange(String nomFichier, int nbPointsMax) {
        this.nomFichier = nomFichier;
        Echange.nbPointsMax = nbPointsMax;
        charger();
    }

    /**
     * Ouverture/création d'un fichier d'echange.
     * @param nomFichier le nom du fichier d'echange
     * @param creation si 'true', crée un nouveau fichier vide
     */
    public Echange(String nomFichier, boolean creation) {
        if(!creation) {
            this.nomFichier = nomFichier;
            Echange.nbPointsMax = Echange.nbPointsMaxDefaut;
            charger();
        }
        else {
            this.nomFichier = nomFichier;
            echange = new JSONObject();
            this.score = new int[2];
            this.coup = -10;
            this.infos = "";
            this.commentaire = "";
            Echange.nbPointsMax = Echange.nbPointsMaxDefaut;
            sauvegarder();
        }
    }

    /**
     * Ouverture/création d'un fichier d'echange.
     * @param nomFichier le nom du fichier d'echange
     * @param creation si 'true', crée un nouveau fichier vide
     * @param nbPointsMax le nombre de points maximum
     */
    public Echange(String nomFichier, boolean creation, int nbPointsMax) {
        if(!creation) {
            this.nomFichier = nomFichier;
            Echange.nbPointsMax = nbPointsMax;
            charger();
        }
        else {
            this.nomFichier = nomFichier;
            echange = new JSONObject();
            this.score = new int[2];
            this.coup = -10;
            this.infos = "";
            this.commentaire = "";
            Echange.nbPointsMax = nbPointsMax;
        }
    }

    /**
    * Indique si un fichier existe.
    * @param nomFichier le nom du fichier
    * @return 'true' s'il existe
    */
    public static boolean fichierExiste(String nomFichier) {
        File f = new File(nomFichier);
        return f.exists();       
    }

    /**
    * Retourne la valeur associée à une clef.
    * @param clef le nom de la clef
    * @return la valeur de la clef
    */
    public String getString(String clef) {
        return this.echange.getString(clef);       
    }

    /**
    * Retourne la valeur associée à une clef.
    * @param clef le nom de la clef
    * @return la valeur de la clef
    */
    public int getInt(String clef) {
        return this.echange.getInt(clef);
    }

    /**
    * Retourne la valeur associée à une clef.
    * @param clef le nom de la clef
    * @return la valeur de la clef
    */
    public int[] getIntTab(String clef) {
        JSONArray scoreJSONArray = this.echange.getJSONArray(clef);
        int[] scoreTabInt = {
            Integer.parseInt(scoreJSONArray.toString().replace("[", "").replace("]", "").split(",")[0]), 
            Integer.parseInt(scoreJSONArray.toString().replace("[", "").replace("]", "").split(",")[1])
        };
        return scoreTabInt;
    }

    /**
    * Ajoute une valeur de type entier dans l'echange.
    * @param clef le nom de la clef
    * @param valeur la valeur de la clef
    */
    private void ajouterValeur(String clef, int valeur) {
        this.echange.put(clef, valeur);
    }

    /**
    * Ajoute une valeur de type entier dans l'echange.
    * @param clef le nom de la clef
    * @param valeur les valeurs de la clef
    */
    private void ajouterValeur(String clef, int[] valeurs) {
        JSONArray valeursArray = new JSONArray();
        for(int i = 0; i < valeurs.length; i++){
            valeursArray.put(valeurs[i]);
        }
        this.echange.put(clef, valeursArray);
    }

    /**
    * Ajoute une valeur de type chaîne de caractères dans l'echange.
    * @param clef le nom de la clef
    * @param valeur la valeur de la clef
    */
    private void ajouterValeur(String clef, String valeur) {
        this.echange.put(clef, valeur);
    }

    /**
    * Retourne le nom du fichier dans lequel va être enregistrer et lu les données.
    * @return le nom du fichier
    */
    public String getNomFichier(){
        return this.nomFichier;
    }

    /**
    * Retourne le Score.
    * @return le tableau des scores
    */
    public int[] getScore(){
        return this.score;
    }

    /**
    * Retourne le coup.
    * @return le numéro du coup
    */
    public int getCoup(){
        return this.coup;
    }

    /**
    * Retourne les informations sur le coup.
    * @return les informations
    */
    public String getInfos(){
        return this.infos;
    }

    /**
    * Retourne le commentaire du coup.
    * @return le commentaire
    */
    public String getCommentaire(){
        return this.commentaire;
    }

    /**
    * Retourne l'échange en JSONObject.
    * @return l'échange en JSONObject
    */
    public JSONObject getEchange(){
        return this.echange;
    }

    /**
    * Retourne la valeur du nombre de points maximum.
    * @return le nombre de points maximum
    */
    public int getNbPointsMax() {
        return Echange.nbPointsMax;
    }

    /**
    * Change le score.
    * @param score les valeurs du nouveau score
    */
    public void setScore(int[] score){
        if(score.length == 2){
            for(int i = 0; i < 2; i++){
                this.score[i] = score[i];
            }
        }
        else{
            System.out.println("\n\tLe score n'est pas correcte, il doit contenir 2 valeurs. \n");
        }
    }

    /**
    * Change le score.
    * @param score la valeur du nouveau score du joueur 1
    */
    public void setScoreJoueur1(int score){
        if(score > 0){
            this.score[0] = score;
        }
        else{
            System.out.println("\n\tLe score n'est pas correcte, il doit être supérieur à 0. \n");
        }
    }
    
    /**
    * Change le score.
    * @param score la valeur du nouveau score du joueur 2
    */
    public void setScoreJoueur2(int score){
        if(score > 0){
            this.score[1] = score;
        }
        else{
            System.out.println("\n\tLe score n'est pas correcte, il doit être supérieur à 0. \n");
        }
    }

    /**
    * Change la valeur du coup.
    * @param coup la valeur du nouveau coup choisi
    */
    public void setCoup(int coup){
        if(coup == 1 || coup == 2 || coup == 3){
            this.coup = coup;
        }
        else{
            System.out.println("\n\tLe coup n'est pas correcte, il doit être égal à 1 ou 2 ou 3. \n");
        }
    }

    /**
    * Change la valeur des informations.
    * @param infos la valeurs des nouvelles informations
    */
    public void setInfos(String infos){
        this.infos = infos;
    }

    /**
    * Change la valeur du commentaire.
    * @param commentaire la valeur du nouveau commentaire
    */
    public void setCommentaire(String commentaire){
        this.commentaire = commentaire;
    }

    /**
    * Change le nombre de points maximum dans la partie.
    * @param nbPoints le nombre de points maximum
    */
    public void setNbPointsMax(int nbPoints) {
        Echange.nbPointsMax = nbPoints;
    }

    /**
    * Charge un fichier de echange en mémoire.
    */
    private void charger() {
        this.echange = new JSONObject();
        this.score = new int[2];
        
        //System.out.println("\ncharger : " + this.nomFichier + "\n");
        String json = "";
        try {
            byte[] contenu = Files.readAllBytes(Paths.get(this.nomFichier));
            json = new String(contenu);        
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture du fichier " + this.nomFichier + " .");
            System.exit(0);
        } 

        JSONObject objetRecup = new JSONObject(json);
        //System.out.println("\nobjetRecup : \n\t" + objetRecup.toString() + "\n");

            //score
        JSONArray scoreJSONArray = objetRecup.getJSONArray("score");
        int[] scoreTabInt = {
            Integer.parseInt(scoreJSONArray.toString().replace("[", "").replace("]", "").split(",")[0]), 
            Integer.parseInt(scoreJSONArray.toString().replace("[", "").replace("]", "").split(",")[1])
        };
        //System.out.println("\t\tscore : " + scoreTabInt[0] + " - " + scoreTabInt[1]);
        this.echange.put("score", scoreJSONArray);
        this.score[0] = scoreTabInt[0];
        this.score[1] = scoreTabInt[1];
            //coup
        int coup = objetRecup.getInt("coup");
        //System.out.println("\t\tcoup : " + coup);
        this.echange.put("coup", coup);
        this.coup = coup;
            //infos
        String infos = objetRecup.getString("infos");
        //System.out.println("\t\tinfos : " + infos);
        this.echange.put("infos", infos);
        this.infos = infos;
            //commentaire
        String commentaire = objetRecup.getString("commentaire");
        //System.out.println("\t\tcommentaire : " + commentaire);
        this.echange.put("commentaire", commentaire);
        this.commentaire = commentaire;

        //System.out.println("echange  = \n\t" + this.echange.toString());
    }

    /**
    * Reharge un fichier d'echange en mémoire.
    */
    public void recharge(){
        charger();
    }

    /**
    * Sauvegarde l'echange dans le fichier.
    */
    public void sauvegarder() {
        setEchange();

        // Ouverture du fichier
        FileWriter fs = null;
        try {
            fs = new FileWriter(this.nomFichier);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'ouverture du fichier '" + this.nomFichier + "'.");
            System.err.println(e);
            System.exit(0);
        }

        // Ecriture du fichier
        try {
            this.echange.write(fs, 3, 0);
            fs.flush();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'écriture dans le fichier.");
            System.err.println(e);
            System.exit(0);
        }

        // Fermeture du fichier
        try {
            fs.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture du fichier.");
            System.err.println(e);
            System.exit(0);
        }
    }

    /**
    * Mets à null ou 0 les variables de l'objet, sauf le nomFichier.
    */
    public void resetEchange(){
        this.commentaire = "";
        this.coup = -10;
        this.infos = "";
        this.score = new int[2];
        this.score[0] = 0;
        this.score[1] = 0;
        this.echange = new JSONObject();
        this.sauvegarder();
    }

    /**
    * Construit l'objet Json de l'échange avec les valeurs de l'objet.
    */
    public void setEchange(){
        ajouterValeur("score", this.score);
        ajouterValeur("coup", this.coup);
        ajouterValeur("infos", this.infos);
        ajouterValeur("commentaire", this.commentaire);
    }

    /**
    * Construit l'objet Json de l'échange avec les valeurs en paramètre, et change également les valeurs prises par l'objet par celles en commentaire.
    * @param score les valeurs du score
    * @param coup la valeur du coup
    * @param infos la valeur des informations
    * @param commentaire la valeur du commentaire
    */
    public void setEchange(int[] score, int coup, String infos, String commentaire){
        if(score.length == 2){
            if(coup == 1 || coup == 2 || coup == 3){
                ajouterValeur("score", score);
                ajouterValeur("coup", coup);
                ajouterValeur("infos", infos);
                ajouterValeur("commentaire", commentaire);
        
                for(int i = 0; i < 2; i++){
                    this.score[i] = score[i];
                }
                this.coup = coup;
                this.infos = infos;
                this.commentaire = commentaire;
            }
            else{
                System.out.println("\n\tLe coup n'est pas correcte, il doit être égal à 1 ou 2 ou 3. \n");
            }
        }
        else{
            System.out.println("\n\tLe score n'est pas correcte, il doit contenir 2 valeurs. \n");
        }
    }

    /**
     * Ajoute 1 point au joueur ciblé
     * @param joueur cible le joueur auquel on ajoutera un point
     */
    public void addPoint(int joueur){
        if(joueur == 0 || joueur == 1){
            switch(joueur){
                case 0 : 
                    setScoreJoueur1(this.score[0] + 1);
                    break;
                case 1 :
                    setScoreJoueur2(this.score[1] + 1);
                    break;
            }
        }
        else{
            System.out.println("\n\tLe joueur n'est pas correcte, il doit être égal à 0 ou 1. \n");
        }
    }

    /**
     * regarde s'il y a un gagnant
     * @return s'il y a un gagnant
     */
    public boolean partieFini(){
        boolean returnValue = false;
        if(this.score[0] >= Echange.nbPointsMax || this.score[1] >= Echange.nbPointsMax){
            afficherGagnant();
            returnValue = true;
        }
        return returnValue;
    }

    /**
     * regarde s'il y a un gagnant sans afficher le gagnant
     * @return s'il y a un gagnant
     */
    private boolean partieFiniSansAffichage(){
        boolean returnValue = false;
        if(this.score[0] >= Echange.nbPointsMax || this.score[1] >= Echange.nbPointsMax){
            returnValue = true;
        }
        return returnValue;
    }

    /**
     * affiche le gagnant et remet à 0 les scores
     */
    private void afficherGagnant(){
        if(this.score[0] >= Echange.nbPointsMax){
            spaceX(10);
            System.out.println("\tLa partie est finie, \n\tLe gagnant est le joueur 1");
            System.out.println(afficherFinalScore());
            spaceX(10);
        }
        else if(this.score[1] >= Echange.nbPointsMax){
            spaceX(10);
            System.out.println("\tLa partie est finie, \n\tLe gagnant est le joueur 2");
            System.out.println(afficherFinalScore());
            spaceX(10);
        }
        else{
            System.out.println("\n\t\tToujours pas de gagnant, le jeu continue...\n");
        }
    }

    /**
     * retourne un String de score final
     * @return description de l'échange
     */
    public String afficherFinalScore(){
        return (
            "\n ~~~~\tLe Score Final est de :\t~~~~ \n" + 
            "\t    (J1) " + this.score[0] + " - " + this.score[1] + " (J2)\n"
        );
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

    /**
     * retourne un String de l'échange en cours
     * @return description de l'échange
     */
    public String toString(){
        return (
            "\nEchange en cours : \n" + 
            "\t Score : \t(J1) " + this.score[0] + " - " + this.score[1] + " (J2)\n" +
            "\t Coup : " + this.coupToString() + "\n" + 
            "\t Informations : " + this.infos + "\n" + 
            "\t Commentaire : " + this.commentaire + "\n"
        );
    }

    /**
     * retourne un String de l'échange en cours avec le coup masqué
     * @return description de l'échange
     */
    public String toStringCoupMasquer(){
        return (
            "\nEchange en cours : \n" + 
            "\t Score : \t(J1) " + this.score[0] + " - " + this.score[1] + " (J2)\n" +
            "\t Coup : *********** \n" + 
            "\t Informations : " + this.infos + "\n" + 
            "\t Commentaire : " + this.commentaire + "\n"
        );
    }

    /**
     * retourne un String décrivant le coup
     * @param coup le coup choisi
     * @return une description du coup
     */
    public String coupToString(int coup){
        String returnValue = "";
        switch(coup){
            case 1 :
                returnValue = "gauche";
                break;
            case 2 :
                returnValue = "milieu";
                break;
            case 3 :
                returnValue = "droite";
                break;
            case -10 :
                returnValue = "Aucun";
                break;
        }
        return returnValue;
    }

    /**
     * retourne un String décrivant le coup
     * @return une description du coup
     */
    public String coupToString(){
        String returnValue = "";
        switch(this.coup){
            case 1 :
                returnValue = "gauche";
                break;
            case 2 :
                returnValue = "milieu";
                break;
            case 3 :
                returnValue = "droite";
                break;
            case -10 :
                returnValue = "Aucun";
                break;
        }
        return returnValue;
    }

    /**
     * nouvel Echange
     * @param joueur le numéro du joueur qui allant porter le coup
     * @param coup numéro du coup qui sera donné
     * @param infos informations sur le coup
     * @param commentaire commentaire sur l'échange
     */
    public void nouvelEchange(int entityJoueur, int coup, String infos, String commentaire){
        if(!partieFini()){
            this.setCoup(coup);
            this.setCommentaire(commentaire);
            this.setInfos(infos);
            sauvegarder();
        }
    }

    /**
     * retourne un aléatoire pour le coup
     * @return le numéro du coup
     */
    public int coupAleatoire(){
        Random rand = new Random(); 
        return (rand.nextInt(3) + 1);
    }

    /**
     * regarde si le coup de l'adversaire a été deviné
     * @param entityJoueur le numéro du joueur
     * @param coup le coup deviné par le joueur
     */
    public void coupAdverseDevine(int entityJoueur, int coup){
        String affichage = "";
        if(this.coup == coup){
            affichage = "\n\tVous avez deviné le coup de votre adversaire : " + coupToString(this.coup);
            affichage += "\n\tVous pouvez jouer\n";
        }
        else if((this.coup -1) == coup || (this.coup +1) == coup){
            Random rand = new Random(); 
            int nombreAleatoire = rand.nextInt(2);
            switch(nombreAleatoire){
                case 0 :
                    affichage = "\n\tVous avez deviné le coup de votre adversaire : " + coupToString(this.coup);
                    affichage += "\n\tVous pouvez jouer\n";
                    break;
                case 1 :
                    affichage = "\n\tVous n'avez pas deviné le coup de votre adversaire : " + coupToString(this.coup);
                    affichage += "\n\tVotre adversaire gagner le point\n";
                    if(entityJoueur == 0) addPoint(1);
                    else if(entityJoueur == 1) addPoint(0);
                    break;
            }
        }
        else if((this.coup -2) == coup || (this.coup +2) == coup){
            affichage = "\n\tVous n'avez pas deviné le coup de votre adversaire : " + coupToString(this.coup);
            affichage += "\n\tVotre adversaire gagner le point\n";
            if(entityJoueur == 0) addPoint(1);
            else if(entityJoueur == 1) addPoint(0);
        }
        else if(this.coup == -10){
            affichage = "aucun coup à deviner";
        }

        System.out.println(affichage);
        int[] scoreEchange = {this.score[0], this.score[1]};

        if(!partieFiniSansAffichage()) resetEchange();
        else{sauvegarder();}
        this.setScore(scoreEchange);
    }
}