<?php
  spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
  });
  session_start();
  // if(isset($_POST['deconnexion'])){
  //   $_SESSION[Utilisateur::SESSION]->deconnexion();
  //   header("Location: index.php");
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
          <form name="form" method="post" action="index.php">
            <?php
            echo "Bienvenue ".$_SESSION[Utilisateur::SESSION]->getLogin();
            echo "</br></br><button style=\"margin-left: 1em; margin-top: 5px;\" id=\"deconnexion\" type=\"submit\" class=\"btn btn-primary\" name=\"deconnexion\">Déconnexion</button>";
            $_SESSION[Utilisateur::SESSION]->deconnexion();
             ?>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>
