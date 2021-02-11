<?php
/**
 * Recherche de l'indice de la case d'un tableau contenant la valeur minimale.
 * @param tableau le tableau
 * @param indice l'indice à partir duquel rechercher le minimum
 * @return l'indice du minimum
 */
function indiceMin(array $tableau, int $indice) : int {
    $resultat = $indice;
    for($i = $indice + 1; $i < count($tableau); $i++) {
        if($tableau[$i] < $tableau[$resultat])
            $resultat = $i;
    }    
    return $resultat;
}

/**
 * Tri un tableau en utilisant le tri par sélection/échange.
 * @param tableau le tableau à trier
 */
function tri(array &$tableau) : void {
    for($i = 0; $i < count($tableau) - 1; $i++) {
        $indice = indiceMin($tableau, $i);
        $tmp = $tableau[$i];
        $tableau[$i] = $tableau[$indice];
        $tableau[$indice] = $tmp;
    }
}

/**
 * Affiche un tableau en HTML.
 * @param tableau le tableau à afficher
 */
function afficher(array $tableau) : void {
    echo "<table class='table table-bordered'>";
    echo "<tr>";
    foreach($tableau as $valeur) {
        echo "<td>$valeur</td>";
    }
    echo "</tr>";
    echo "</table>";
}
?>
<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 5</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Tri de tableau</div>
        <div class="card-body bg-light"><?php
$tab1 = [1, 3, 5, 3, 6];
afficher($tab1);
tri($tab1);
afficher($tab1);
?>
        </div>
      </div>
    </div>
  </body>
</html>