<!DOCTYPE html>
<html lang="fr">
  <head>
    <title>Actualités dynamiques</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.min.css">
    <meta name="author" content="Cyril Rabat"/>
  </head>
  <body>
    <div class="container">
      <div class="card">
        <div class="card-header bg-primary text-white text-center">Actualités</div>
        <div class="card-body" id="content">
        </div>
      </div>
    </div>
    <script src="https://code.jquery.com/jquery-3.5.1.min.js" integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=" crossorigin="anonymous"></script>
    <script src="script.js?v=<?php echo time(); ?>" type="text/javascript"></script>
    <script>
      $(document).ready(function() {
            next();
      });
    </script>
  </body>
 </html>