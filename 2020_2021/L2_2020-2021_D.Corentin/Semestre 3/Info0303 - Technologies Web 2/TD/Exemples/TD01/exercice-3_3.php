<?php
/*
Le ième jour du mois se trouve grâce à date("z") qui retourne 0 à 365.
Ici, c'est interdit, donc on calcule la somme du nombre de jours de chaque mois et on ajoute le jour du mois courant.
*/
$nbJours = date("j");
for($i = 1; $i < date("n"); $i++) {
    $nbJours += date("t", mktime(0, 0, 0, $i, 1, date("Y")));
}
?>
<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 3</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css">
  </head>
  <body>
    <h1>Date du jour</h1>

    <p>Nous sommes le <?php echo (date("z")+1)." vs $nbJours"; ?>ième jour de l'année.</p>
  </body>
</html>