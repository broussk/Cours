<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title>Calcul d'une racine carée à l'aide de la méthode de Newton</title>
  </head>
  <body>
    <div class="container">
      <div class="card-header">
        <div class="card-body">
          <form method="post" action="#">
            <div class="form-group col-md-6">
              <label>Variable a</label>
              <input type="number" class="form-control" name="a" placeholder="Entrez un nombre" required>
            </div>
            <button style="margin-left: 1em;" type="submit" class="btn btn-primary" name="valider">Calculer</button>
          </div>
      </div>
    </div>

    <?php
    if(isset($_POST['a'])){
      $a = $_POST['a'];
      if($a > 0){
        $resultat=newton($a);
        echo "La racine carrée de $a est $resultat";
      }
      else{
        echo "La valeur entrée est négative ou égale à 0";
      }
    }
    function newton($a){
      $x;
      $x0 = (1+$a)/2;
      $x1;
      $abs = 20;
      $i = 1;
      while($abs > 0.0001){
        $x = (1/2)*($x0+$a/$x0);
        $x0 = $x;
        $x1 = (1/2)*($x+$a/$x); //Merci Nanou !
        if((($x1-$x)/$x) > 0){
          $abs = ($x1-$x)/$x;
        }
        else {
          $abs = -($x1-$x)/$x;
        }
      }
      return $x1;
    }
    ?>

    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
    </body>
  </html>
