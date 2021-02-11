<?php
/***********************
Pour exécuter ce code, vous devez avoir créé une base de données correspondant au nom spécifié dans DBConfig.php.
Créez une table 'exemple' dans cette base :
CREATE TABLE `exemple` (
   `id` int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
   `champ1` varchar(100) NOT NULL,
   `champ2` varchar(100) NOT NULL
   ) ENGINE=MyISAM DEFAULT CHARSET=utf8;
Ajoutez des enregistrements dans la table :
INSERT INTO `exemple` (`id`, `champ1`, `champ2`)
VALUES (NULL, "toto", "toto"),
       (NULL, "titi", "titi"),
       (NULL, "tata", "tata");
************************/

include("DBConfig.php");

spl_autoload_register(function ($class) {
    include $class . '.php';
});
$DB = MyPDO::getInstance();
?>
<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 1</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Exercice 1</div>
        <div class="card-body bg-light">
<?php
$SQL = "SELECT * FROM `exemple`";
if($requete = $DB->prepare($SQL)) {
    if($requete->execute()) {
        while($res = $requete->fetch()) {
            echo "<p>{$res['id']} : {$res['champ1']} ; {$res['champ2']} </p>";
        }
    }
    else
        echo "<p> Erreur lors de l'exécution de la requête. </p>";
}
else
    echo "<p> Erreur lors de la préparation de la requête. </p>";

?>
        </div>
      </div>
    </div>
  </body>
</html>