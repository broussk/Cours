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
        <div class="card-header">
          <h1>Les tables de multiplication</h1>
        </div>
        <div class="card-body">
          <div class="mb-2">        
<?php
for($i = 1; $i <= 10; $i++)
    echo "<a href='table$i.php' class='btn btn-primary'>$i</a>&nbsp;";
echo "</div>";

$i = 10;
echo "<table class='table table-stipped table-bordered'>";
echo "<tr><td colspan='2'>Table ".$i."</td></tr>";
for($j = 0; $j < 10; $j++) {
    echo "<tr><td>".$i." x ".$j."</td><td>".$i * $j."</td></tr>";
}        
echo "</table>";
?>
        </div>
      </div>
    </div>
  </body>
</html>