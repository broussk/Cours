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
echo "<div class='mb-2'>";
for($i = 1; $i <= 10; $i++)
    echo "<a href='javascript:selection($i);' class='btn btn-primary'>$i</a>&nbsp;";
echo "</div>";

for($i = 1; $i <= 10; $i++) {
    echo "<table id='table$i' class='table table-stipped table-bordered' ".($i!=1?"style='display:none;'":"").">";
    echo "<tr><td colspan='2'>Table ".$i."</td></tr>";
    for($j = 0; $j < 10; $j++) {
        echo "<tr><td width='50%'>".$i." x ".$j."</td><td>".$i * $j."</td></tr>";
    }        
    echo "</table>";
}
?>
        </div>
      </div>
    </div>
    <script src="https://ajax.aspnetcdn.com/ajax/jQuery/jquery-3.5.1.slim.min.js"></script>
    <script src="exercice-1_4.js"></script>
  </body>
</html>