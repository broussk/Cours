<?php
  spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
  });
  session_start();
  // if(isset($_POST['deconnexion'])){
  //   $_SESSION[Utilisateur::SESSION]->deconnexion();
  //   header("Location: index.php");} //
  // include 'index.php';
  $user = $_SESSION[Utilisateur::SESSION];
  var_dump($user);
  var_dump($_SESSION);
  header("Location: index.php");
  $user->deconnexion();
?>
