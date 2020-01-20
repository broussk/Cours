<?php
include 'Message.php';
if(!isset($_SESSION)){
  session_start();
}
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
            if(isset($_POST['deco'])){
              header("Refresh:0");
              session_destroy();
            }
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
              $mes = new Message(date("j/n/Y"),date("H:i:s"));
              $_SESSION['messages'][] = $mes->__toString()." ".$_POST['saisie'];
            }
            foreach ($_SESSION['messages'] as $valeur) {
              echo $valeur."<br>";
            }
          ?>
        </div>
      </div>
    </div>
  </body>
</html>
