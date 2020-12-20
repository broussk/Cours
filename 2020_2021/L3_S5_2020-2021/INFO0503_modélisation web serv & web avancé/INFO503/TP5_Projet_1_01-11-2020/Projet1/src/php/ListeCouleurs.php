<!DOCTYPE html>
<html lang='fr'>
<head>
    <title>Liste des Couleurs </title>
    <meta http-equiv="content-type" content="http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php; charset=utf-8"/>
</head>
<body>
    <h1>Liste des Couleurs</h1>
    <a href='http://localhost:9876/index'><button>Home</button></a><br>
    <?php
        $recupCouleurs = json_decode(file_get_contents('../../misc/json/couleurs.json'), true);
        $listeCouleurs = "<b>Couleurs : </b><br>\n";
        
        foreach($recupCouleurs as $element) $listeCouleurs .= $element . " <br>\n";
        $listeCouleurs .= "<br>\n";
     
        echo $listeCouleurs
    ?>
</body>
</html>