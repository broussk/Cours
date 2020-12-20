<?php
include("Modele.php");
include("Moteur.php");
include("Options.php");
include("Couleur.php");
include("Place.php");
include("parking.php");
include("Voiture.php");
include("Usine.php");
include("Stock.php");
include("Catalogue.php");
include("Commande.php");
include("Constructeur.php");
include("Concessionnaire.php");

$m1 = new Modele("GOLF 7 GTD");

$mo2 = new Modele("Renault TWINGO Electric");

$m = new Moteur(Carburation::DIESEL, 195);

$m2 = new Moteur(Carburation::HYBRIDE, 82);

$d1 = new DateTime('2011-11-05');

$d2 = new DateTime('2019-09-03');

$options = new Options(true,true,true);

$options2 = new Options(true,true,true);

$v1 = new Voiture("DV-544-EG",$m1,$m,$d1,Couleur::NOIR,$options);

$v2 = new Voiture("EK-960-YA",$mo2,$m2,$d2,Couleur::BLANC,$options2);

$listeVoiture = array();
array_push($listeVoiture,$v1);
array_push($listeVoiture,$v2);
echo("Test classe Voiture ");
echo("<br/>");
echo("<br/>");
for($i = 0; $i < count($listeVoiture);$i++){
 echo($listeVoiture[$i]);
 echo("<br/>");
}

$p1 = new Place('A',1);
$p2 = new Place('A',3);
$placeRangeeA = array($p1,$p2);
$p = new Parking($placeRangeeA);

$u = new Usine("Volkswagen",$p);

$stock = new Stock($u);

echo("<br/>");
echo("<br/>");
echo("Test classe Usine");
echo("<br/>");
echo("<br/>");
echo($u->__toString());
echo("<br/>");
echo("<br/>");

echo($stock->__toString());
echo("<br/>");
echo("<br/>");
echo("Test Catalogue");
$c = new Catalogue();
echo("<br/>");
echo("<br/>");
$c->ajouterVoiture($v1);
echo("<br/>");
$c->ajouterVoiture($v2);
echo("<br/>");
echo("<br/>");
echo("Test Affichage Parking");
echo("<br/>");
echo("<br/>");
echo($p->__toString());
echo("<br/>");
echo("<br/>");
echo("Test Recherche Voiture");
echo("<br/>");
echo("<br/>");
if($c->rechercherVoiture($v1)){
 echo("La voiture est bien présente");
}else{
 echo("La voiture n'est pas présente");
}
echo("<br/>");
if($c->rechercherVoiture($v2)){
 echo("La voiture est bien présente");
}else{
 echo("La voiture n'est pas présente");
}
echo("<br/>");
echo("<br/>");
echo("Test Classe Commande");
echo("<br/>");
echo("<br/>");
$commande = new Commande($v1);
echo($commande->__toString());
echo("<br/>");
echo("<br/>");
echo("Test Classe Constructeur");
echo("<br/>");
echo("<br/>");
$constructeur = new Constructeur("T-shirt", $u, $stock);
echo($constructeur->__toString());
echo("<br/>");
echo("<br/>");
echo("Test Classe Concessionnaire");
echo("<br/>");
echo("<br/>");
$concessionnaire = new Concessionnaire($c);
echo($concessionnaire->__toString());
echo("<br/>");
echo("<br/>");
echo("Test Suppression voiture");
echo("<br/>");
echo("<br/>");
$v1 = $p1->enleverVoiture();
if($v1 == null){
 echo("La voiture a bien ete enleve du parking");
}
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la Voiture v1");
echo("<br/>");
echo("<br/>");
$tab1 = array();
$tab1["numeroIdentification"] = "DV-544-AD";
$tab1["modele"] = $m1->__toString();
$tab1["moteur"] = $m->__toString();
$tab1["options"] = $options->__toString();
$tab1["couleur"] = Couleur::NOIR;
$tab1["dateFabrication"] = $d1;
//$u = json_encode($v1);
//var_dump(json_encode($v1));
echo(json_encode($tab1));
//var_dump(unserialize(serialize($v1),$v1));
//var_dump(json_decode($u));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la Voiture v2");
echo("<br/>");
echo("<br/>");
$tab2 = array();
$tab2["numeroIdentification"] = "EK-960-YA";
$tab2["modele"] = $mo2->__toString();
$tab2["moteur"] = $m2->__toString();
$tab2["options"] = $options2->__toString();
$tab2["couleur"] = Couleur::BLANC;
$tab2["dateFabrication"] = $d2;
echo(json_encode($tab2));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json du modele m1");
echo("<br/>");
echo("<br/>");
$tab3 = array();
$tab3["modele"] = $m1->__toString();
echo(json_encode($tab3));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json du modele mo2");
echo("<br/>");
echo("<br/>");
$tab4 = array();
$tab4["modele"] = $mo2->__toString();
echo(json_encode($tab4));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Place");
echo("<br/>");
echo("<br/>");
$tab5 = array();
$tab5["Place"] = $p1->__toString();
echo(json_encode($tab5));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Usine");
echo("<br/>");
echo("<br/>");
$tab7 = array();
$tab7["Usine"] = $u->__toString();
echo(json_encode($tab7));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe  Stock");
echo("<br/>");
echo("<br/>");
$tab8 = array();
$tab8["Stock"] = $stock->__toString();
echo(json_encode($tab8));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Catalogue");
echo("<br/>");
echo("<br/>");
$tab9 = array();
$tab9["Catalogue"] = $c->__toString();
echo(json_encode($tab9));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Commande");
echo("<br/>");
echo("<br/>");
$tab10 = array();
$tab10["Commande"] = $commande->__toString();
echo(json_encode($tab10));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Constructeur");
echo("<br/>");
echo("<br/>");
$tab11 = array();
$tab11["Constructeur"] = $constructeur->__toString();
echo(json_encode($tab11));
echo("<br/>");
echo("<br/>");
echo("Affichage du Json de la classe Concessionnaire");
echo("<br/>");
echo("<br/>");
$tab11 = array();
$tab11["Concessionnaire"] = $concessionnaire->__toString();
echo(json_encode($tab11));
echo("<br/>");
echo("<br/>");
echo("Test JsonSerialize");
echo("<br/>");
echo("<br/>");
$v4 = new Voiture("DV-544-EG",$m1->__toString(),$m->__toString(),$d1,Couleur::NOIR,$options->__toString());
$jsonP = json_encode($v4);
print_r($jsonP);
$json = serialize($v4);
echo("<br/>");
echo("<br/>");
print_r($json);
echo("<br/>");
echo("<br/>");
echo("Test deserialisation");
echo("<br/>");
echo("<br/>");
$deserialisation = unserialize($json);
print_r($deserialisation);
echo("<br/>");
echo("<br/>");
echo("Test fonction FromJson");
echo("<br/>");
echo("<br/>");
$v5 = Voiture::FromJson($jsonP);
echo($v5->__toString());
?>
