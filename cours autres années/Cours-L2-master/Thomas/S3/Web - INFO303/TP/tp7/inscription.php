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

  function afficherForm():void{
    echo
    "
    <div class=\"form-group col-md-6\">
      <label for=\"login\">Login</label>
      <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre mot de passe\" value=\"\" required>
      <small id=\"passwordHelpInline\" class=\"text-muted\">Votre login doit comporter au moins 3 caractères</small>
    </div>
    <div class=\"form-group col-md-6\">
      <label for=\"password\">Mot de passe</label>
      <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe\" required>
      <small id=\"passwordHelpInline\" class=\"text-muted\">Mot de passe : Au moins 1 Majuscule, 1 caractère spécial [#?!@$%^&*-] et 6 de longueur</small>
    </div>
    <div class=\"form-group col-md-6\">
      <label for=\"verifPassword\">Vérification mot de passe</label>
      <input name=\"verifPassword\"  type=\"password\" class=\"form-control\" id=\"verifPassword\" placeholer=\"Entrez de nouveau votre mot de passe\" required>
    </div>
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"createLog2\" type=\"submit\" class=\"btn btn-primary\" name=\"createLog2\">S'inscire</button></br>
    ";
  }
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
              afficherForm();
              if(isset($_POST['createLog2'])){
                if($_POST['password']===$_POST['verifPassword']){
                  $tempUser = new Utilisateur($_POST['login'],$_POST['password']);
                  if(!$tempUser->verification("verifLogin")){
                    if($tempUser->verification("verifInscription")){
                      $tempUser->inscription();
                      $tempUser->connexion();
                      echo "<script>alert(".var_dump($_SESSION).")</script>";
                      header("Location: index.php");
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
          <form name="cancelSignUp" method="post" action="index.php">
            <button style="margin-left:1em; margin-top: 5px;" id="cancelSignUp" type="submit" class="btn btn-primary" name="cancelSignUp">Annuler</button>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>
