<?php
            //bibliothèques
include("Voiture/Voiture.php");

include("Usine/Parking.php");
include("Usine/Place.php");
include("Usine/Usine.php");

include("ConstructeurAuto/Catalogue.php");
include("ConstructeurAuto/Constructeur.php");
include("ConstructeurAuto/Stock.php");

include("Commande.php");
include("Concessionnaire.php");

$affichage = "<h2 align=\"center\">Test classe Voiture </h2>";

            //initialisation des variables
$modele0 = new Modele();
$modele1 = new Modele("C3");
$modeles = array($modele0, $modele1);
/*
$modele2 = new Modele("Megane");
$modele3 = new Modele("C1");
$modele4 = new Modele("C3 Picaso");
$modele5 = new Modele("Turbo");
$modeles = array($modele0, $modele1, $modele2, $modele3, $modele4, $modele5);
*/

$moteur0 = new Moteur();
$moteur1 = new Moteur(Carburation::ELECTRIQUE, 100);
$moteurs = array($moteur0, $moteur1);
/*
$moteur2 = new Moteur(Carburation::ESSENCE, 50);
$moteur3 = new Moteur(Carburation::GPL, 25);
$moteur4 = new Moteur(Carburation::HYBRIDE, 150);
$moteur5 = new Moteur(Carburation::DIESEL, 100);
$moteurs = array($moteur0, $moteur1, $moteur2, $moteur3, $moteur4, $moteur5);
*/

$date0 = new DateTime("2015-05-05");
$date1 = new DateTime("2019-08-09");
$dates = array ($date0, $date1);
/*
$date2 = new DateTime("2020-07-08");
$date3 = new DateTime("2020-01-09");
$date4 = new DateTime("1999-12-25");
$date5 = new DateTime("2005-01-30");
$dates = array ($date0, $date1, $date2, $date3, $date4, $date5);
*/

$options0 = new Options(false, true, true, false, false, true, true, false);
$options1 = new Options(true, false, false, true, true, false, false, true);
$Options = array($options0, $options1);
/*
$options2 = new Options(true, false, false, true, true, false, false, true);
$options3 = new Options(false, true, true, false, false, true, true, false);
$options4 = new Options(true, true, true, false, false, true, true, true);
$options5 = new Options(true, true, false, true, true, false, true, true);
$Options = array($options0, $options1, $options2, $options3, $options4, $options5);
*/

$voiture0 = new Voiture($modele0, $moteur0, Couleur::BLANC, $options0, $date0);
$voiture1 = new Voiture($modele1, $moteur1, Couleur::BLEU_NUIT, $options1, $date1);
$voitures = array($voiture0, $voiture1);
/*
$voiture2 = new Voiture($modele2, $moteur2, Couleur::MARRON, $options2, $date2, 3);
$voiture3 = new Voiture($modele3, $moteur3, Couleur::ROSE, $options3, $date3, 4);
$voiture4 = new Voiture($modele4, $moteur4, Couleur::VIOLET, $options4, $date4, 5);
$voiture5 = new Voiture($modele5, $moteur5, Couleur::CYAN, $options5, $date5, 6);
$voitures = array($voiture0, $voiture1, $voiture2, $voiture3, $voiture4, $voiture5);
*/

$placeA1 = new Place('A', 1);
$placeA4 = new Place('A', 4);
$placesA = array($placeA1,$placeA4);

$placeB1 = new Place('B', 1);
$placeB3 = new Place('B', 3);
$placesB = array($placeB1,$placeB3);

$parking = new Parking($placesA);

$usine0 = new Usine("Citröen", $parking);

$stock0 = new Stock($usine0);

$catalogue0 = new Catalogue($voitures);

$commande0 = new Commande($voitures);

$constructeur0 = new Constructeur("Citröen Automobile", array($usine0), array($stock0));

$concessionnaire0 = new Concessionnaire($catalogue0, "Citroën de L'avenir");

            //test
$affichage .= "Les modèles : <br>";
for($i = 0; $i < count($modeles); $i++){
    $affichage .= $modeles[$i]->__toString() . "<br>";
}

$affichage .= "<br>Les Moteurs : <br>";
for($i = 0; $i < count($moteurs); $i++){
    $affichage .= $moteurs[$i]->__toString() . "<br>";
}

$affichage .= "<br>Les Dates : <br>";
for($i = 0; $i < count($dates); $i++){
    $affichage .= date_format($dates[$i], 'Y-m-d') . "<br>";
}

$affichage .= "<br>Les Options : <br>";
for($i = 0; $i < count($Options); $i++){
    $affichage .= $Options[$i] . "<br>";
}

$affichage .= "<br>Les Voitures : <br>";
for($i = 0; $i < count($voitures); $i++){
    $affichage .= $voitures[$i]->__toString() . "<br>";
}

$affichage .= "<br>Les Places : <br>";
for($i = 0; $i < count($placesA); $i++){
    $affichage .= $placesA[$i]->__toString() . "<br>";
}
for($i = 0; $i < count($placesB); $i++){
    $affichage .= $placesB[$i]->__toString() . "<br>";
}

$affichage .= "<br>Le Parking : <br>";
$affichage .= $parking->__toString() . "<br>";

$affichage .= "<br>L'Usine : <br>";
$affichage .= $usine0->__toString() . "<br>";

$affichage .= "<br>Le Stock : <br>";
$affichage .= $stock0->__toString() . "<br>";

$affichage .= "<br>Le Catalogue : <br>";
$affichage .= $catalogue0->__toString() . "<br>";

$affichage .= "<br>La Commande : <br>";
$affichage .= $commande0->__toString() . "<br>";

$affichage .= "<br>Le Constructeur : <br>";
$affichage .= $constructeur0->__toString() . "<br>";

$affichage .= "<br>Le Concessionnaire : <br>";
$affichage .= $concessionnaire0->__toString() . "<br>";

$affichage .= spaceX(10);

$affichage .= "<h2 align=\"center\">Test Functions </h2>";

$affichage .= spaceX(5) . "<h2>Fonctions : Moteur </h2>";
    $affichage .= $moteur0->__toString();
    $affichage .= "<h4>Fonctions : setCarburation </h4>";
        $moteur0->setCarburation(Carburation::ELECTRIQUE);
    $affichage .= "<h4>Fonctions : setPuissance </h4>";
        $moteur0->setPuissance(100);
    $affichage .= $moteur0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Modele </h2>";
    $affichage .= $modele0->__toString();
    $affichage .= "<h4>Fonctions : setModele </h4>";
        $modele0->setModele("DS 3");
    $affichage .= $modele0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Options </h2>";
    $affichage .= $options0->__toString();
    $affichage .= "<h4>Fonctions : setGPS </h4>";
    $affichage .= $options0->setGPS(true);
    $affichage .= "<h4>Fonctions : setAlarme </h4>";
    $affichage .= $options0->setAlarme(false);
    $affichage .= $options0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Voiture </h2>";
    $affichage .= $voiture0->__toString();
    $affichage .= "<h4>Fonctions : setCouleur </h4>";
        $voiture0->setCouleur(Couleur::NOIR);
    $affichage .= "<h4>Fonctions : setOption </h4>";
        $voiture0->setOption($options1);
    $affichage .= $voiture0->__toString();
    $affichage .= "<h4>Fonctions : jsonSerialize (to JSON serialize & unserialize)</h4>";
    $affichage .= "json_encode : <br>";
        $jsonVoiture0 = json_encode($voiture0);
    $affichage .= $jsonVoiture0;
    $affichage .= "<br><br>serialize : <br>";
        $jsonVoiture0serialized = serialize($voiture0);
    $affichage .= $jsonVoiture0serialized;
    $affichage .= "<br><br>unserialize : <br>";
        $deserialisationVoiture0 = unserialize($jsonVoiture0serialized);
    $affichage .= $deserialisationVoiture0;
        
    $affichage .= "<h4>Fonctions : FromJson (With JSON)</h4>";
        $voitureMadeByJSON = Voiture::FromJson($jsonVoiture0);
    $affichage .= $voitureMadeByJSON->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Place </h2>";
    $affichage .= $placeA1->__toString();
    $affichage .= "<h4>Fonctions : setVoiture </h4>";
        $placeA1->setVoiture($voiture0);
    $affichage .= "<h4>Fonctions : setOccupee </h4>";
echo($affichage);
        $placeA1->setOccupee(false);
    $affichage = "<br>" . $placeA1->__toString();
    $affichage .= "<h4>Fonctions : enleverVoiture </h4>";
        $voitureEnlevee = Place::enleverVoiture($placeA1);
    $affichage .= $placeA1->__toString();
    $affichage .= "<br>voiture enlevée : " . $voitureEnlevee->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Parking </h2>";
    $affichage .= $parking->__toString();
    $affichage .= "<h4>Fonctions : setPlace </h4>";
        $parking->setPlace($placesB);
    $affichage .= "<h4>Fonctions : addPlace </h4>";
        $parking->addPlace($placeA1);
        $parking->addPlace($placeA4);
    $affichage .= $parking->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Usine </h2>";
    $affichage .= $usine0->__toString();
    $affichage .= "<h4>Fonctions : setNomUsine </h4>";
        $usine0->setNomUsine("Tabarnak Voitures");
    $affichage .= "<h4>Fonctions : setParking </h4>";
        $usine0->setParking();
    $affichage .= $usine0->__toString();

    
$affichage .= spaceX(5) . "<h2>Fonctions : Stock </h2>";
    $affichage .= $stock0->__toString();
    $affichage .= "<h4>Fonctions : setUsine </h4>";
        $stock0->setUsine();
    $affichage .= $stock0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Constructeur </h2>";
    $affichage .= $constructeur0->__toString();
    $affichage .= "<h4>Fonctions : setNom </h4>";
        $constructeur0->setNom();
    $affichage .= "<h4>Fonctions : setUsines </h4>";
        $constructeur0->setUsines(array($usine0));
    $affichage .= "<h4>Fonctions : setStocks </h4>";
        $constructeur0->setStocks(array($stock0));
    $affichage .= $constructeur0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Catalogue </h2>";
    $affichage .= $catalogue0->__toString();
    $affichage .= "<h4>Fonctions : ajouterVoiture </h4>";
        $catalogue0->ajouterVoiture($voiture1);
    $affichage .= "<h4>Fonctions : supprimerVoiture </h4>";
        $catalogue0->supprimerVoiture($voiture0);
    $affichage .= "<h4>Fonctions : rechercherVoiture </h4>";
echo($affichage);
        $catalogue0->rechercherVoiture($voiture1);
    $affichage = "<br>" . $catalogue0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Concessionnaire </h2>";
    $affichage .= $concessionnaire0->__toString();
    $affichage .= "<h4>Fonctions : setNom </h4>";
        $concessionnaire0->setNom();
    $affichage .= "<h4>Fonctions : setCatalogue </h4>";
        $concessionnaire0->setCatalogue();
    $affichage .= $concessionnaire0->__toString();

$affichage .= spaceX(5) . "<h2>Fonctions : Commande </h2>";
    $affichage .= $commande0->__toString();
    $affichage .= "<h4>Fonctions : setVoituresCommande </h4>";
        $commande0->setVoituresCommande();
    $affichage .= "<h4>Fonctions : ajouterVoitureCommande </h4>";
        $commande0->ajouterVoitureCommande($voiture1);
    $affichage .= "<h4>Fonctions : retirerVoitureCommande </h4>";
        $commande0->retirerVoitureCommande($voiture0);
    $affichage .= $commande0->__toString();


    $affichage .= "<h2 align=\"center\">FIN </h2>";

echo $affichage;

function spaceX($i){$rep =""; for($j=0; $j < $i; $j++){$rep .= "<br>";} return $rep;}
?>