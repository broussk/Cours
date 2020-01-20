<?php
if(!isset($_SESSION)){
  session_start();
}
define("LOGIN","Thomas");
define("MDP","azerty");
$timestamp=time()+60;
setcookie("TestCookieLog",LOGIN,$timestamp);

?>
<!DOCTYPE html>
<html lang="fr">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title>Session et cookie</title>
  </head>
  <body>
    <div class="container">
      <div class="card-header">
        <div class="card-body" color="">
          <?php
          if(isset($_POST["validerLog"])){
            if($_POST['pseudo']==LOGIN &&$_POST['mdp']==MDP){
              $_SESSION['user'] = $_POST['pseudo'];
              $_SESSION['pwdUser'] = $_POST['mdp'];
            }
          }
          if(isset($_POST['deco'])){
            header("Refresh:0");
            session_destroy();
          }
          if(!isset($_SESSION['user']) || !isset($_SESSION['pwdUser'])){
            if(isset($_COOKIE['TestCookieLog'])){
              echo "<h3>Je vous connais !</h3>";
            }
            else{
              echo "<h3>Je ne vous connaissais pas, mais maintenant si !</h3>";
            }
            echo
            "<form method=\"post\" action=\"#\">
              <div class=\"form-group col-md-6\">
                <label for=\"pseudo\">Pseudo</label>
                <input name=\"pseudo\"  type=\"text\" class=\"form-control\" id=\"pseudo\" placeholer=\"entrez votre pseudo\" required>
              </div>
              <div class=\"form-group col-md-6\">
                <label for=\"mdp\">Mot de passe</label>
                <input name=\"mdp\"  type=\"password\" class=\"form-control\" id=\"mdp\" required>
              </div>
              <button style=\"margin-left: 1em;\" type=\"submit\" class=\"btn btn-primary\" name=\"validerLog\">Valider</button>";
          }
          else{
            echo
            "<form method=\"post\" action=\"#\">
              <div class=\"form-group col-md-6\">
                <textarea name=\"saisie\" cols=\"25\" rows=\"5\" placeholder=\"Entrez ce que vous souhaitez ici.\"required></textarea>
              </div>
            <button style=\"margin-left: 1em;\" type=\"submit\" class=\"btn btn-primary\" name=\"validerText\">Valider</button>
            </form>
            <form method=\"post\" action=\"#\">
              <button style=\"margin-left: 1em; margin-top: 5px;\" type=\"submit\" class=\"btn btn-primary\" name=\"deco\">Déconnexion</button>
            </form>
            <h4>Liste message(s) : <br></h4>";
            if(!isset($_SESSION['messages'])){
              $_SESSION['messages'] = array();
            }
            if(isset($_POST['saisie'])){
              $_SESSION['messages'][] = $_POST['saisie'];
            }
            foreach ($_SESSION['messages'] as $valeur) {
              echo $valeur."<br>";
            }
          }
          ?>
        </div>
      </div>
      <div name="cookies" id="cookies">
        <a href="supprime.php">Supprimer le cookie</a>
        <br>
        <a href="etat.php">Voir l'état du cookie</a>
      </div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
  </body>
</html>
