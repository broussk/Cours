<?php
spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
});
session_start();
// $_SESSION[Utilisateur::SESSION] = new Utilisateur("","");
// $user = fromForm("L","");
// echo $user->getLogin();

function fromForm(string $login, string $password):Utilisateur{
    $user = new Utilisateur($login,$password);
  return $user;
}

function afficherForm():void{
  echo "
  <form name=\"form\" method=\"post\" action=\"#\">
  <div class=\"form-group col-md-6\">
  <label for=\"login\">Login</label>
  <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre pseudo ici\" required>
  </div>
  <div class=\"form-group col-md-6\">
  <label for=\"password\">Mot de passe</label>
  <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe\" required>
  </div>
  <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"seConnecter\" type=\"submit\" class=\"btn btn-primary\" name=\"seConnecter\">Se connecter</button></br>
  </form>
  <form name=\"form\" method=\"post\" action=\"inscription.php\">
  <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"createLog\" type=\"submit\" class=\"btn btn-primary\" name=\"createLog\">S'inscire</button>
  </form>
  ";
}

function afficherBienvenue(Utilisateur $u):void{
  echo "
  Bienvenue ".$u->getLogin()."</br></br>
  <form name=\"form\" method=\"post\" action=\"#\">
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"lister\" type=\"submit\" class=\"btn btn-primary\" name=\"lister\">Lister les images</button>
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"addPicture\" type=\"submit\" class=\"btn btn-primary\" name=\"addPicture\">Ajouter une image</button>
  </form>
  <form name=\"form\" method=\"post\" action=\"deconnexion.php\">
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"deconnexion\" type=\"submit\" class=\"btn btn-primary\" name=\"deconnexion\">Déconnexion</button>
  </form>
  ";
}
?>
<!doctype html>
<html lang="fr">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width  <head>
, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title></title>
  </head>
  <body>
    <div class="container">
      <div class="card-header">
        <div class="card-body" color="">
          <?php
          if(isset($_SESSION[Utilisateur::SESSION])){
            afficherBienvenue($_SESSION[Utilisateur::SESSION]);
            if(isset($_POST['addPicture'])){
              header("Location: ajouter.php");
            }
            if(isset($_POST['lister'])){
              header("Location: lister.php");
            }
          }
          else{
            afficherForm();
            if(isset($_POST['seConnecter'])){
              $user = fromForm($_POST['login'],$_POST['password']);
              if($user->verification("verifLogin")){
                $user->connexion();
                if($user->isConnected()){
                  afficherBienvenue($user);
                  if(isset($_POST['addPicture'])){
                    header("Location: ajouter.php");
                  }
                  if(isset($_POST['lister'])){
                    header("Location: lister.php");
                  }
                }
                else{
                  afficherForm();
                }
                header("Refresh: 0");
              }
            }
          }


           ?>
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
