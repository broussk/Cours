<!DOCTYPE html>
<html lang='fr'>
<head>
    <title>Liste des Moteurs </title>
    <meta http-equiv="content-type" content="http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php; charset=utf-8"/>
</head>
<body>
    <h1>Liste des Moteurs Crées</h1>
    <a href='http://localhost:9876/index'><button>Home</button></a><br><br>
    <?php
        $recupMoteur = json_decode(file_get_contents('../../misc/json/moteur.json'), true);
        $listeMoteurs = "<b>Moteurs : </b><br>\n";

        for($i=0, $j=0; $i < count($recupMoteur); $i++){
            foreach($recupMoteur[$i] as $element){
                $listeMoteurs .= array_keys($recupMoteur[0])[$j] . " : " .  $element . " ";
                if($j<3)$j++;
                else $j=0;
            }
            $listeMoteurs .= "<br>\n";
        }
    
        echo $listeMoteurs
    ?>
</body>
</html>