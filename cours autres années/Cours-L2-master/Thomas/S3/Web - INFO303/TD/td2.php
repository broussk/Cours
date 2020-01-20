<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-1.10.2.js"></script>
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Tri de tableau</div>
        <div class="card-body bg-light"><?php
        $tab = [1,3,5,3,6];
        afficher($tab);
        tri($tab);
        afficher($tab);?>
      </div>
    </div>
  </div>
    <?php
      function indiceMin(array $tableau, int $indice) : int{
        $resultat = $indice;
        for($i=$indice+1 ; $i < count($tableau) ; $i++){
          if($tableau[$i] < $tableau[$resultat])
            $resultat = $i;
        }
        return $resultat;
      }

      function tri(array &$tableau){
        for($i=0 ; $i<count($tableau)-1 ; $i++){
          $indice = indiceMin($tableau, $i);
          $tmp = $tableau[$i];
          $tableau[$i] = $tableau[$indice];
          $tableau[$indice] = $tmp;
        }
      }

      function afficher(array $tableau){
        echo "<table class='table table-bordered'>";
        $nbMax = 0;
        foreach($tableau as $ligne){
          if($nbMax < count($ligne)){
            $nbMax = count($ligne);
          }
        }
        foreach($tableau as $valeur){
          echo "<tr>$valeur</tr>";
          $nbcase = count($valeur);
          for($i=0 ; $i<$nbMax ; i++){
            echo "<td>";
            if($i<$nbcase){
              echo $valeur[$i];
            }
          echo "</td>";
          }
        }
        echo "</table>";
      }
    ?>
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
  </body>
  </html>
