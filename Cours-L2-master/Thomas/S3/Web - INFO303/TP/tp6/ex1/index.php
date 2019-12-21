<?php
spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
});
session_start();
if(!isset($_SESSION["usersConnected"])){
  $userDefault = new Utilisateur("Default","default");
  $_SESSION["usersConnected"] = $userDefault;
}
// var_dump($_SESSION); VERIFICATION DE LA DECONNEXION DES COMPTES

function afficherForm(){
  echo
  "
  <div class=\"form-group col-md-6\">
    <label for=\"login\">Login</label>
    <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre pseudo ici\" required>
  </div>
  <div class=\"form-group col-md-6\">
    <label for=\"password\">Mot de passe</label>
    <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe ici\" required>
  </div>
  <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"createLog\" type=\"submit\" class=\"btn btn-primary\" name=\"createLog\">Créer un compte</button>
  <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"seConnecter\" type=\"submit\" class=\"btn btn-primary\" name=\"seConnecter\">Se connecter</button>
  ";
}

function addUser(string $login, string $password){
  $t = file('password.txt');
  $log = "$login;$password\n";
  $alreadyDefined=0;
  foreach ($t as $key => $value) {
    if($value===$log){
      $alreadyDefined=1;
    }
  }
  if($alreadyDefined!=1){
    $t[] = $log;
    file_put_contents("password.txt",$t);
    $alreadyDefined=0;
  }
}

function fromForm(string $login, string $password):Utilisateur{
  $user = new Utilisateur($login,$password);
  return $user;
}

 ?>
<!doctype html>
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
          if(isset($_POST['createLog'])){
            addUser($_POST['login'],$_POST['password']);
          }
            // afficherForm();
          ?>
          </br>
          <?php
            // $user->verification($user->getLogin(),$user->getPassword());
            if(isset($_POST['seConnecter'])){
              $user = new Utilisateur($_POST['login'],$_POST['password']);
              // if($user->verification($user->getLogin(),$user->getPassword())){
              //   echo "Vous avez un compte !";
              if($user->verification($user->getLogin(),$user->getPassword())){
                $user->connexion();
                // var_dump($_SESSION);
                // echo "</br>";
                // var_dump($user);
              }
              else{
                echo "<script>alert(\"Vous n'avez pas de compte.\")</script>";
                header("Refresh:0");
              }
              if($user->isConnected($_POST['login'],$_POST['password'])){
                header("Location: deconnexion.php");
              }
              else{
                header("Refresh:0");
              }
            }
            else{
              afficherForm();
            }
          ?>
          </form>
        </div>
      </div>
    </div>
   <!-- Optional JavaScript -->
   <!-- jQuery first, then Popper.js, then Bootstrap JS -->
   <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
   <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
   <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
 </body>
</html>
