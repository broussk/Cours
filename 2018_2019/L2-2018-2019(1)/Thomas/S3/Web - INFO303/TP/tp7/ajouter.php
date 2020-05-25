<?php
if(isset($_POST['acceuil'])){
  header("Location: index.php");
}
else if(isset($_POST['valider'])){
    $title = $_FILES['upload']['name'];
    $data = $_FILES['upload']['tmp_name'];
    $content = file_get_contents($data);
    if($_FILES['upload']['error']===UPLOAD_ERR_OK){
      // $img = "images/".$title;
      $name = '' .time(). '' .$title. '';
      move_uploaded_file($data, 'images/' . $name);
      echo "Le fichier a été correctement uploadé ! ";
    }
    else{
      echo "Un problème est survenu lors de l'envoi du fichier.";
    }
  }
?>


<html lang="fr">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <title>Ajouter une image</title>
  </head>
  <body>
    <div class="container">
      <form name="form" method="post" action="#" enctype="multipart/form-data">
        <label for="upload">Ajouter une image</label>
        <input name="upload" type="file" class="form-control-file" id="upload">
        <button style="margin-left: 1em; margin-top: 5px;" id="valider" type="submit" class="btn btn-primary" name="valider">Valider</button>
        <button style="margin-left: 1em; margin-top: 5px;" id="acceuil" type="submit" class="btn btn-primary" name="acceuil">Retour à l'acceuil</button>
      </form>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
  </body>
</html>
