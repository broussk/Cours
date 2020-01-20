<?php
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
  echo "<br><br><a href='index.html'>Revenir à l'acceuil</a>";
?>
