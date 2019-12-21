<?php
spl_autoload_register(function ($class) {
  include 'class/'.$class.'.php';
});

$fichier = file("password.txt");
$id = file_get_contents("password.txt");
foreach ($fichier as $key => $value) {
  $explodedValueexplode(";",$value);
  $verif=true;
  echo "$"
}
 ?>
