<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 1</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Liste d'actualités</div>
        <div class="card-body">
          <div class="row">
<?php
include("Actualite.php");
if(($liste = @file("actualites.txt")) !== FALSE) {
    foreach($liste as $ligne) {
        $actualite = Actualite::fromString($ligne);
        
        // Avec la méthode __toString
        //echo $actualite;
        
        // Avec la vue
        include 'vue.php';
    }
}
?>
          </div>
        </div>
      </div>
    </div>
  </body>
</html>