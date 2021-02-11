<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Exercice 4</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css">
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Zone de saisie</div>
        <div class="card-body bg-light">
          <form method="post" action ="#">
            Tapez le texte à afficher.
            <div class="form-group">
              <label for="pseudo">Pseudo : </label>
              <input class="form-control" type="text" name="pseudo" id="pseudo" value="<?php
if(isset($_POST['pseudo']))
    echo htmlentities($_POST['pseudo'])
?>"/>
            </div>
            <div class="form-group">
              <label for="message">Message : </label>
              <textarea class="form-control" rows="10" name="message" id="message"><?php
if(isset($_POST['message']))
    echo htmlentities($_POST['message']);
?></textarea>
            </div>
            <button type="submit" name="valider" class="btn btn-primary">Valider</button>
          </form>
        </div>
<?php
if(isset($_POST['valider'])) {
    if(isset($_POST['pseudo']) && ($_POST['pseudo'] != "") &&
       isset($_POST['message']) && ($_POST['message'] != "")) {
        echo "<div class=\"card-footer bg-success\">";
        echo "<strong>".$_POST['pseudo']."</strong><br/>";
        $message = str_replace(array("\r\n", "\n", "\r"), "<br/>", htmlentities($_POST['message']));
        echo $message;
    }
    else {
        echo "<div class=\"card-footer bg-danger\">";
        echo "Vous devez saisir votre pseudo et votre message.";
    }
}
?>
        </div>
      </div>
    </div>
  </body>
</html>