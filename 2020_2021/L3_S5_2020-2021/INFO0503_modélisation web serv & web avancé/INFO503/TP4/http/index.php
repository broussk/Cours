<!DOCTYPE html>
<html lang="fr">
    <head>
        <title>Test d'envoi d'une requête HTTP depuis un script PHP</title>
        <meta http-equiv="content-type" content="text/html; charset=utf-8"/>
        <meta name="description" content="Requête HTTP en PHP"/>
        <meta name="author" content="Cyril Rabat"/>
    </head>
    <body>
        <h1>Exemple d'envoi d'une requête HTTP vers un autre script PHP</h1>
        
        <p>Le script actuel appelle le script <i>generateur.php</i> en lui envoyant des données en POST.</p>
        
<?php
    // Préparation de la requête
    $options = [
        'http' =>
            [
                'method'  => 'POST',
                'header'  => 'Content-type: application/x-www-form-urlencoded',
                'content' => 'login=toto&motDePasse=toto'
            ]
        ];

    // Envoi de la requête et lecture du JSON reçu
    // Remplacez l'URL par l'adresse locale vers generateur.php
    $URL = "https://www.cyril-rabat.fr/enseignement/Info0503/generateur.php";
    $contexte  = stream_context_create($options);
    
    if(($jsonTexte = @file_get_contents($URL, false, $contexte)) !== false) {
        // Analyse du JSON reçu
        $tableau = json_decode($jsonTexte, true);
        if($tableau['code'] == "OK")
            echo "<p>Bravo !!! Vous êtes connecté !!!</p>";
        else
            echo "<p>Erreur de connexion ! L'erreur est <strong>".
                 $tableau['message']."</strong></p>";
    }
    else
        echo "<p>Une erreur est survenue lors de la récupération des données.</p>";
?>        
    </body>
</html>