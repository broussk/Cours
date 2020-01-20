<?php
  include 'ex1.php';
  setcookie("TestCookieLog",NULL,time()-3600);
  echo '<a href="ex1.php">Retourner à l\'acceuil</a>';
?>
