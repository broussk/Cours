<!DOCTYPE html>
<html lang='fr'>
<head>
    <title>Liste des Modèles </title>
    <meta http-equiv="content-type" content="http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php; charset=utf-8"/>
</head>
<body>
    <h1>Liste des Modeles Crées</h1>
    <a href='http://localhost:9876/index'><button>Home</button></a><br><br>
    <?php
        $recupModeles = json_decode(file_get_contents('../../misc/json/modele.json'), true);
        $listeModeles = "<b>Modèles : </b><br>\n";
        
        for($i=0; $i < count($recupModeles); $i++){
            foreach($recupModeles[$i] as $element) $listeModeles .= $element . " ";
            $listeModeles .= "<br>\n";
        }
     
        echo $listeModeles
    ?>
</body>
</html>