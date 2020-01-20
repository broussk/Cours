<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title>TP2</title>
  </head>
  <body>
    <div class="container">
      <div class="card-header">
        <div class="card-body" color="">
          <form method="post" action="#">
            <div class="form-group col-md-6">
              <label>Variable a</label>
              <input type="number" class="form-control" name="a" placeholder="Entrez la variable a" required>
            </div>
            <div class="form-group col-md-6">
              <label>Variable b</label>
              <input type="number" class="form-control" name="b" placeholder="Entrez la variable b" required>
            </div>
            <div class="form-group col-md-6">
              <label>Variable c</label>
              <input type="number" class="form-control" name="c" placeholder="Entrez la variable c" required>
            </div>
            <button type="submit" class="btn btn-primary" name="valider">Valider les valeurs</button>
          </div>
      </div>
    </div>

    <?php
    // if(isset($_POST['valider'])){
    if(isset($_POST['a']) && isset($_POST['b']) && isset($_POST['c'])){
      $a=$_POST['a'];
      $b=$_POST['b'];
      $c=$_POST['c'];
      echo "Variable a : $a<br>Variable b : $b<br>Variable c : $c<br>";
      $delta = $b**2 - (4*$a*$c);
      $x1 = 0;
      $x2 = 0;

      if($delta >= 0){
        $x1 = ((-$b - sqrt($delta))/2*$a);
        $x2 = ((-$b + sqrt($delta))/2*$a);
        echo "Delta = $delta donc il y a deux solutions<br>
        Solution 1 = $x1<br>
        Solution 2 = $x2<br>";
      }
      elseif($delta == 0){
        $x1 = (-$b/2*$a);
        echo "Delta = $delta donc une solution = $x1";
      }
      else{
        echo "Delta = $delta. Inférieur à zéro, donc aucune solution";
      }
      // echo "<br><br><a href='index.html'>Revenir à l'acceuil</a>";
    }
    ?>

    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
    </body>
  </html>
