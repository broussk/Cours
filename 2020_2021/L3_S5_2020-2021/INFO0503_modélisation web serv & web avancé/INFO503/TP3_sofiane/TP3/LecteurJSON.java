public class LecteurJSON{

    public static void main(String[] args) {
        // Vérification des arguments
        if(args.length != 1) {
            System.err.println("Erreur : vous devez spécifier le nom du fichier JSON.");
            System.err.println();            
            System.err.println("Usage : java LecteurJSON fichier.json");
            System.err.println("\toù 'fichier.json' est le nom du fichier à ouvrir");
            System.exit(0);
        }
        
        // Récupération de la chaîne JSON depuis le fichier
        String json = "";
        try {
          byte[] contenu = Files.readAllBytes(Paths.get(args[0]));
          json = new String(contenu);        
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture du fichier '" + args[0] + "'");
            System.exit(0);
        } 
        
        // Création d'un objet JSON
        JSONObject objet1 = new JSONObject(json);
        JSONObject objet2 = new JSONObject(json);
        System.out.println("Contenu JSON : ");
        System.out.println(json);

        // Affichage à l'écran
        JSONArray tableau1 = objet.getJSONArray("contacts");
        JSONArray tableau2 = objet.getJSONArray("media");
        System.out.println("Liste des livres :");
        for(int i = 0; i < tableau1.length(); i++) {
            JSONObject element = tableau1.getJSONObject(i);
            System.out.print("titre=" + element.getString("titre"));
            System.out.print(", Auteur=" + element.getString("auteur"));
        }
        System.out.println("Mediatheque :");
        for(int i = 0; i < tableau2.length(); i++) {
            JSONObject element = tableau2.getJSONObject(i);
            System.out.print("livre=" + element.getString("livre"));
        }
    }
}