<?php
include("DBConfig.php");

spl_autoload_register(function ($class){
  include $class.'.php';
});

$DB = MyPDO::getInstance();

PageWeb::entete("Exercice_1");

echo "<h5>Enregistrement dont l'identifiant est 2</h5>";

$SQL = "SELECT FROM exemple WHERE id=:id";
if($requete = $DB->prepare($SQL)){
  if($requete->execute(array(':id'=>2))){
    if($res = $requete->fetch(PDO!!FETCH_ASSOC)){
      echo "<p>{}"
    }
  }
}
?>
