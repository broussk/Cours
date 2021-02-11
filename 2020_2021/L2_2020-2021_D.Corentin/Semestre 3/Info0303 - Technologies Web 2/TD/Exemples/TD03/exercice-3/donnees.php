<?php   
include("DBConfig.php");

spl_autoload_register(function ($class) {
    include $class . '.php';
});
$DB = MyPDO::getInstance();

if(isset($_POST['numero']))
    $numero = intval($_POST['numero']);
else
    $numero = 0;

$SQL = "SELECT * FROM `actualite` LIMIT :numero,1;";

try {
    if(!$requete = $DB->prepare($SQL))
        throw new Exception("Erreur lors de la préparation de la requête SQL.");
    $requete->bindParam(':numero', $numero, PDO::PARAM_INT);
    if(!$requete->execute())
        throw new Exception("Erreur lors de l'exécution de la requête SQL.");
    
    if($row = $requete->fetch()) {
        // L'actualité demandée existe
        $json['actualite'] = $row;
        $json['next'] = $numero + 1;
    }
    else {
        // L'actualité demandée n'existe pas
        $numero = 0;
        if(!$requete->execute())
            throw new Exception("Erreur lors de l'exécution de la requête SQL.");
        
        if($row = $requete->fetch()) {
            $json['actualite'] = $row;
            $json['next'] = 1;
        }
        else
            throw new Exception("Il n'y a pas d'actualité dans la base.");
    }
}
catch(Exception $e) {
    $json['erreur'] = $e->getMessage();
}

header("Content-type: application/json");
echo json_encode($json);