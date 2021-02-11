<?php
const JOURS = [ 1 => "lundi", 2 => "mardi", 3 => "mercredi", 4 => "jeudi", 5 => "vendredi", 6 => "samedi", 7 => "dimanche" ];
const MOIS = [ 1 => "janvier", 2 => "Février", 3 => "mars", 4 => "avril", 5 => "mai", 6 => "juin",
               7 => "juillet", 8 => "août", 9 => "septembre", 10 => "octobre", 11 => "novembre", 12 => "décembre" ];
$date = JOURS[date('N')]." ".date("j")." ".MOIS[date('n')]." ".date("Y");

// Version TP
/*setlocale (LC_TIME, 'fr_FR.utf8','fra');
strftime("%A %e %B %Y")*/
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
    <div class="container">
      <div class="card">
        <div class="card-header">
          <h1>Date du jour</h1>
        </div>
        <div class="card-body">
          Aujourd'hui, nous sommes le <?php echo $date; ?>.
        </div>
      </div>
    </div>
  </body>
</html>