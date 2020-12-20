public class GestionnaireUtilisateurs{

    // attributs

    private String nom_fichier;
    private String[] tabUtlisateur;
    private String [] mdpUtilisateur;


    // constructeur

    public GestionnaireUtilisateurs(String nom_fichier){
        this.nom_fichier = nom_fichier;
        this.tabUtlisateur = tabUtlisateur;
        this.mdpUtilisateur = mdpUtilisateur;
    }

    //getter

    public String getNomFichier(){
        return this.nom_fichier;
    }

    // methode toString

    public String toString(){
        return "nom_fichier : " + this.nom_fichier;
    }

    // methode ajouterUtilisateur

    public void ajouterUtlisateur(String [] tabUtilisateur,String nvUtilisateur){
        int i = 0;
        while(tabUtilisateur[i] != null){
            i++;
        }
        tabUtlisateur[i] = nvUtilisateur;
    }

    // methode rechercherUtilisateur

    public boolean rechercherUtilisateur(String[] tabUtilisateur,String utilisateur){
        boolean resultat = false;
        for(int i = 0; i < tabUtilisateur.length;i++){
            if(tabUtilisateur[i] == utilisateur){
                resultat = true;
            }
        }

        return resultat;
    }

    // methode supprimerUtilisateur

    public void supprimerUtlisateur(String []tabUtilisateur, String utilisateur,String[] mdpUtilisateur){
        for(int i = 0; i < tabUtilisateur.length;i++){
            if(tabUtilisateur[i] == utilisateur){
                tabUtilisateur[i] = null;
                mdpUtilisateur[i] = null;
            }
        }
    }
}