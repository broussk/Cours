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
        <div class="card-header">
          <h1>Les tables de multiplication</h1>
        </div>
        <div class="card-body">
<?php
for($i = 1; $i <= 10; $i++) {
    echo "<table class='table table-stipped table-bordered'>";
    echo "<tr><th colspan='2'>Table ".$i."</th></tr>";
    for($j = 0; $j < 10; $j++) {
        echo "<tr><td width='50%'>".$i." x ".$j."</td><td>".$i * $j."</td></tr>";
    }        
    echo "</table>";
}
?>
        </div>
      </div>
    </div>
  </body>
</html>