//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo3_script", v.10/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo3_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5; //nombre de ligne pour A
m=4; //nombre de ligne pour B et nombre de colonne pour A
q=5; //nombre de colonne pour B
A = round(10*rand(n,m)); //matrice A
B = round(10*rand(m,q)); //matrice B

disp("/////////////////////////--DEBUT--////////////////////////////");

//Affichage variable
disp("n= ", n);
disp("m= ", m);
disp("q= ", q);
disp("A= ", A);
disp("B= ", B);

disp("////////////////////--Fonction PRODMAT--//////////////////////");

//Traitement
MUL = PRODMAT(A,B,n,m,q); //calcul de l'addition et soustration matricielle par la fonction SUMDIFF
verif_mul = A*B; //calcul de l'addition matricielle par Scilab

disp("////////////////////////--RESULTAT--//////////////////////////");

//Affichage résultat
disp("-> Résultat (*): ", MUL);
disp("-> Vérification: ", verif_mul);
disp("=> Si le résultat est égal à la vérification, alors le programme est correct.");

disp("/////////////////////////--FIN--//////////////////////////////");
