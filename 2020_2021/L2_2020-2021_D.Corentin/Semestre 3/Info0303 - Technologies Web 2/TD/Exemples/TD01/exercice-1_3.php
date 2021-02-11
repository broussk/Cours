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
          <form action='#' method='post' class="mb-2">
<?php
for($i = 1; $i <= 10; $i++)
    echo "<a href='?table=$i' class='btn btn-primary'>$i</a>&nbsp;";
?>
          </form>
<?php
$table = 1;
if(isset($_GET['table']))
    $table = intval($_GET['table']);
if(($table < 1) || ($table > 10)) $table = 1;

echo "<table class='table table-stipped table-bordered'>";
echo "<tr><th colspan='2'>Table ".$table."</th></tr>";
for($j = 0; $j < 10; $j++) {
    echo "<tr><td width='50%'>".$table." x ".$j."</td><td>".$table * $j."</td></tr>";
}        
echo "</table>";
?>
        </div>
      </div>
    </div>
  </body>
</html>