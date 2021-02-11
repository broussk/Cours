<?php
include("Utilisateur.php");
$utilisateur = Utilisateur::fromForm();
?>
<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 2</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Exercice 2</div>
        <div class="card-body bg-light">
<?php
if(!$utilisateur->verification()) {
?>      
          <form action="#" method="post">
<?php
$utilisateur->afficherForm();
?>
            <button type="submit" name="valider" class="btn btn-primary">Connexion</button>
          </form>
<?php
if(isset($_POST['valider']))
    echo <<<HTML
        </div>
        <div class="card-footer bg-danger">
        Identifiants incorrects.
        </div>
HTML;
}
else
    echo "Bienvenue <span class='badge badge-primary'>".$utilisateur->getLogin()."</span>.</div>";
?>
      </div>
    </div>
  </body>
</html>