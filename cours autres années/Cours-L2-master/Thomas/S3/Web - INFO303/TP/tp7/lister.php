<?php
spl_autoload_register(function ($class) {
  include 'class/'.$class.'.php';
});

echo "
<form method=\"post\">
  <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"acceuil\" type=\"submit\" class=\"btn btn-primary\" name=\"acceuil\">Retour à l'acceuil</button>
</form>";
if(isset($_POST['acceuil'])){
  header("Location: index.php");
}
$images = "images/";
$imgs = array_diff(scandir($images), array('..','.'));
foreach ($imgs as $key) {
  echo ("</br><a href=\"images/$key\"/></br>".$key);
}
 ?>
