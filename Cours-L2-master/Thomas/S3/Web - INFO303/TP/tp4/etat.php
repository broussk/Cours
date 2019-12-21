<?php
  if(!isset($_COOKIE["TestCookieLog"])){
    echo "Aucun cookie existant.";
  }
  else{
    echo "Le cookie existe.";
  }
  echo '<a href="ex1.php">Retourner à l\'acceuil</a>';

?>
