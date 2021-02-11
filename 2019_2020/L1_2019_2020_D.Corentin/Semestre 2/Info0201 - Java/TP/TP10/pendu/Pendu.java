package pendu;

/**
 * Classe Pendu
 * @author Jessica Jonquet modifié par DUPONT Corentin
 * @version 09/04/2020
 */

public class Pendu {

  /**
   * Attributs de clas
   */
    public static final int NB_ESSAIS = 5;
    private String mot;
    private char[] masque;
    private char[] solution;
    private int nbEssais;


    /**
     * Construteur de pendu : initialise le mot, le masque et le nombre d'essais
     * @param m le mot a deviner
     * @throws PenduException exception si le mot n'est pas valide
     */
    public Pendu(String m) throws PenduException {
        mot = m;
        if(!estValide()){
            throw new PenduException(m);
        }
        nbEssais=0;
        convertirMot();
        initialiseMasque();
    }


    /**
     * Getter du mot
     * @return retourne le mot
     */
    public String getMot(){return mot;}


    /**
     * Verifie si le mot est valide (au moins 4 caracteres, et uniquement de lettres non accentuees)
     * @return vrai ou faux
     */
    public boolean estValide(){
        boolean res = false;
        int k = 0;
        if(mot.length()>=4){
            mot=mot.toUpperCase();
            while(k<mot.length() && mot.charAt(k)>='A' && mot.charAt(k)<='Z')
                k++;
        }
        if(k==mot.length())
            res = true;
        return res;
    }


    /**
     * Convertit le mot en un tableau de caracteres et le stocke dans solution.
     * Chaque case du tableau contient un caractere de la chaine.
     */
    public void convertirMot() {
        solution = new char [mot.length()];
        for(int i=0; i<mot.length(); i++){
            solution[i] = mot.charAt(i);
        }
    }


    /**
     * Initialise le masque avec le nombre de caractere du mot et le remplit de '-'.
     */
    public void initialiseMasque(){
        masque = new char [mot.length()];
        for(int i = 0; i<mot.length(); i++){
            masque[i] = '-';
        }
    }


    /**
     * Affiche le masque a l'ecran comme une chaine de caracteres.
     */
    public void afficheMasque(){
        for(int k = 0; k<masque.length; k++){
            System.out.print(masque[k]);
        }
    }


    /**
     * Verifie si le caractere propose existe dans la solution.
     * Met a jour le masque pour toutes les occurences de la lettre.
     * Met a jour le nombre d'essai realiser et signale quand le nombre d'essai max est atteint
     * @param lettre lettre proposee a ajoute au masque si present dans le mot
     * @return retourne faux si le nombre d'essai max est atteint
     */
    public boolean jouer(char lettre){
        lettre = Character.toUpperCase(lettre);
        boolean res = false;
        boolean trouve = false;
        if(nbEssais<NB_ESSAIS){
            res = true;
            for(int k = 0; k<solution.length; k++){
                if(solution[k] == lettre){
                    trouve = true;
                    masque[k]=lettre;
                }
            }
            if(!trouve)
                nbEssais++;
        }
        if(nbEssais>=NB_ESSAIS)
            res = false;
        return res;
    }


    /**
     * Affiche le nombre de coups restants, l'etat courant du jeu : le masque et la potence.
     */
    public void afficherEssais(){
        System.out.println("Il vous reste " + (NB_ESSAIS-nbEssais) + " coups avant de perdre.");
        System.out.print("Le mot a devine : ");
        afficheMasque();
        System.out.println();
        switch(nbEssais) {
            case 5: // La potence en entier et le pendu
                System.out.println(" /---\\\n |   |\n |   O\n |  /|\\\n |  / \\\n-^-");
                break;
            case 4: // La potence en entier
                System.out.println(" /---\\\n |   |\n |\n |\n |\n-^-");
                break;
            case 3: // La potence sans la corde
                System.out.println(" /---\\\n |\n |\n |\n |\n-^-");
                break;
            case 2: // Le corps de la potence
                System.out.println("\n |\n |\n |\n |\n-^-");
                break;
            case 1: // Le pied de la potence
                System.out.println("\n\n\n\n\n-^-");
                break;
            default : break;
        }
    }


    /**
     * Verifie si tous les caractères du mot ont ete trouves
     * @return true si toutes les lettres ont ete trouvees
     */
    public boolean estFini(){
        boolean fini = true;
        int i = 0;
        while(i<masque.length && fini){
            if(masque[i]=='-'){
                fini = false;
            }
            i++;
        }
        return fini;
    }
}
