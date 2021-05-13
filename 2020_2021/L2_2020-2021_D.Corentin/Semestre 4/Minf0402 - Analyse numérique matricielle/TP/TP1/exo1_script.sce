//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo1_script", v.10/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo1_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5;
A = round(10*rand(n,n));
B = round(10*rand(n,n));

disp("/////////////////////////--DEBUT--////////////////////////////");

//Affichage
disp("n= ", n);
disp("A= ", A);
disp("B= ", B);
scal = MON_SCA(A, B, n); //Calcul du scalaire avec la fonction MON_SCA


//Affichage résultat
disp("-> Résultat: ", scal);
disp("/////////////////////////--FIN--//////////////////////////////");
