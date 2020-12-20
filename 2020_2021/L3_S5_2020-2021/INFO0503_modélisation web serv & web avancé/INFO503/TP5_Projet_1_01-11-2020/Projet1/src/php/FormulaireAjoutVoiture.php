<!DOCTYPE html>
<html lang='fr'>
<head>
    <title>Formulaire Ajout Voiture </title>
    <meta http-equiv="content-type" content="http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php; charset=utf-8"/>
</head>
<body>
    <h1>Formulaire Ajout Voiture</h1>

    <a href='http://localhost:9876/index'><button>Home</button></a><br>

    <form method="POST" action="http://localhost:9876/ajout" name="formulaire">
        <?php
            $recupModele = json_decode(file_get_contents('../../misc/json/modele.json'), true);
            $recupMoteur = json_decode(file_get_contents('../../misc/json/moteur.json'), true);
            $recupCouleur = json_decode(file_get_contents('../../misc/json/couleurs.json'), true);
            $recupOptions = json_decode(file_get_contents('../../misc/json/options.json'), true);
            $newRecupOptions = $recupOptions;
            for($i = 0; $i < count($newRecupOptions); $i++){
                $newRecupOptions[$i] = str_replace(true, "", $recupOptions[$i]);
            }
        ?>
        <br>
        <label>Numero Identification : </label><input type="text" name="numeroIdentification" placeholder="A5-CF2-5A" size="9" pattern="([A-Z]|[0-9]){2}-([A-Z]|[0-9]){3}-([A-Z]|[0-9]){2}" required/><br><br>
        
        <label for="listeModele">Choisissez un modèle :</label>
        <select name="modele" id="listeModele" required>
            <?php
                $options = "<option value=\"\"> ~~~ Modele ~~~ </option>";
                for($i=0; $i<count($recupModele); $i++){
                    $options .= "<option value=\""; 
                    foreach($recupModele[$i] as $element) $options .= $element;
                    $options .= "\">";
                    foreach($recupModele[$i] as $element) $options .= $element;
                    $options .= "</option>";
                }
                echo $options;
            ?>
        </select><br><br>
        
        <label for="listeMoteur">Choisissez un moteur :</label>
        <select name="moteur" id="listeMoteur" required>
            <?php 
                $options = "<option value=\"\"> ~~~ Moteur ~~~ </option>";
                for($i=0; $i<count($recupMoteur); $i++){
                    $options .= "<option value=\"" ;
                    foreach($recupMoteur[$i] as $element) $options .= $element . ",";
                    $options .= "\">PuissDef, Id, Carburation, Puissance : "; 
                    foreach($recupMoteur[$i] as $element) $options .= $element . "\t";
                    $options .= "</option>" . "\n";
                }
                echo $options;
            ?>
        </select><br><br>
        
        <label>Date de Fabrication : </label><input type="text" name="dateFabrication" placeholder="AAAA-JJ-MM" size="10" pattern="[0-9]{4}-[0-9]{2}-[0-9]{2}" required/><br><br>
        
        <label for="listeCouleur">Choisissez une couleur :</label>
        <select name="couleur" id="listeCouleur" required>
            <?php 
                $options = "<option value=\"\"> ~~~ Couleur ~~~ </option>";
                for($i=0; $i<count($recupCouleur); $i++){
                    $options .= "<option value=\"" . $recupCouleur[$i] . "\">" . $recupCouleur[$i] . "</option>" . "\n";
                }
                echo $options;
            ?>
        </select><br>

        <?php
            $inputs = "<p> Veuillez cocher les options que vous voulez ajouter à la voiture : <br>\n";
            for($i=0; $i<count($recupOptions); $i++){
                $inputs .= "<INPUT type=\"checkbox\" name=\"options4\" value=\"" ;
                foreach($recupOptions[$i] as $element) $inputs .= $element . " ";
                $inputs .= "\"> ";
                foreach($newRecupOptions[$i] as $element) $inputs .= $element;
                $inputs .= "\n";
            }
            $inputs .= "</p><br>";
            echo $inputs;
        ?>
        
        <button>Valider</button>
    </form>
</body>
</html>