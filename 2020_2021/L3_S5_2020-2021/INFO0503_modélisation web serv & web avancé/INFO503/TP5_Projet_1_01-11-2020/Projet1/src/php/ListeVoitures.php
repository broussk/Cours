<!DOCTYPE html>
<html lang='fr'>
<head>
    <title>Liste des Voitures </title>
    <meta http-equiv="content-type" content="http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php; charset=utf-8"/>
</head>
<body>
    <h1>Liste des Voitures Crées</h1>
    <a href='http://localhost:9876/index'><button>Home</button></a><br><br>
    <?php
        $recupVoitures = json_decode(file_get_contents('../../misc/json/voiture.json'), true);
        $listeVoitures = "<b>Voitures : </b><br>\n";

        //pour tableau de voiture => non fonctionnel :/
        /*
        for($i=0; $i < count($recupVoitures); $i++){
            foreach($recupVoitures[$i] as $element) $listeVoitures .= $element . " ";
            $listeVoitures .= "<br>\n";
        }
        */
        
        //afficher la voiture du json => fonctionnel :)
        
        foreach($recupVoitures as $element) $listeVoitures .= $element . " ";
        $listeVoitures .= "<br>\n";
     
        echo $listeVoitures
    ?>
</body>
</html>