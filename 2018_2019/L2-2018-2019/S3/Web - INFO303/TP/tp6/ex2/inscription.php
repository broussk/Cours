<?php
  spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
  });
  session_start();
  // $_SESSION[Utilisateur::SESSION]->deconnexion();
  // if(!isset($_SESSION[Utilisateur::SESSION])){
  //   $userDefault = new Utilisateur("Default","default");
  //   $_SESSION[Utilisateur::SESSION] = $userDefault;
  // }
?>
<html lang="fr">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title></title>
  </head>
  <body>
    <div class="container">
      <div class="card-header">
        <div class="card-body" color="">
          <form name="form" method="post" action="#">
            <?php
              // var_dump($_SESSION);
              $_SESSION[Utilisateur::SESSION]->afficherForm(false);
              if(isset($_POST['createLog2'])){
                if($_POST['password']===$_POST['verifPassword']){
                  $tempUser = new Utilisateur($_POST['login'],$_POST['password']);
                  if(!$tempUser->verification("verifLogin")){
                    if($tempUser->verification("verifInscription")){
                      $tempUser->inscription();
                      $tempUser->connexion();
                      header("Location: deconnexion.php");
                    }
                    else{
                      echo "Erreur inscription</br>";
                    }
                  }
                  else{
                    echo "Erreur login</br>";
                  }
                }
                else{
                  echo "Erreur, mot de passes non identiques</br>";
                }
              }

             ?>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>
