<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title>Manipulation de tableaux</title>
  </head>
  <body>
    <div>
      <?php
        $titres = ["age","prenom","nom"];
        $valeurs =[
                    ["age"=>88,"nom"=>"Eastwood", "prenom"=>"Clint"],
                    ["nom"=>"Madonna", "age"=>61],
                  ];
        $sep = " - ";
        // afficher($titres,$valeurs);
        $res=tableau2String($titres,$sep);
        echo $res;

        function afficher(array $titres, array $valeurs){
          echo "<table class='table table-bordered'>";
          echo "<tr>";
          foreach($titres as $key){
            echo "<th> $key </th>";
          }
          echo "</tr>";
          for($i=0 ; $i < count($valeurs) ; $i++){
            echo "<tr>";
            foreach($titres as $val){
              if(isset($valeurs[$i][$val])){
                echo "<td>".$valeurs[$i][$val]."</td>";
              }
              else{
                echo "<td>Non défini</td>";
              }
            }
            echo "</tr>";
          }
          echo "</table>";
        }

        function tableau2String(array $tab, $sep): String{
          $str = "";
          $long = count($tab)
          foreach($tab as $key){
            
            $str = $str.$key.$sep;
          }
          return $str;
        }
      ?>
    </div>


  <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
  </body>
</html>
