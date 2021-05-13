//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo2_script", v.10/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo2_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5; //nombre de ligne
m=4; //nombre de colonne
A = round(10*rand(n,n)); //matrice A
B = round(10*rand(n,n)); //matrice B

disp("/////////////////////////--DEBUT--////////////////////////////");

//Affichage
disp("n= ", n);
disp("m= ", m);
disp("A= ", A);
disp("B= ", B);

disp("////////////////////--Fonction SUMDIFF--//////////////////////");

//Traitement
[SUM, DIFF] = SUMDIFF(A,B,n,m); //calcul de l'addition et soustration matricielle par la fonction SUMDIFF
verif_sum = resize_matrix(A+B,n,m); //calcul de l'addition matricielle par Scilab
verif_diff = resize_matrix(A-B,n,m); //calcul de la soustration matricielle par Scilab

disp("////////////////////////--RESULTAT--//////////////////////////");

//Affichage résultat
disp("-> Résultat (+): ", SUM);
disp("-> Vérification: ", verif_sum);
disp("=> Si le résultat est égal à la vérification, alors le programme est correct.");

disp("-> Résultat (-): ", DIFF);
disp("-> Vérification: ", verif_diff);
disp("=> Si le résultat est égal à la vérification, alors le programme est correct.");

disp("/////////////////////////--FIN--//////////////////////////////");
