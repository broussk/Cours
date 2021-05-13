//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo1_script", v.24/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo1_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5;
A = 10*rand(n,n)
I = eye(n,n); //matrice identité de A

disp("/////////////////////////--DEBUT--////////////////////////////");

//Affichage
disp("Matrice A=", A);
disp("Matrice identité=", I);

disp("/////////////////////////--TRAITEMENT--////////////////////////////");
//Traitement et affichage résultat

res_inv = inv(A)
res = MAGIQUE(A);

disp("Inversion Scilab:", res_inv)
disp("Si la divion est égale à linversion de Scilab, alors le programme est correct")

disp("/////////////////////////--FIN--//////////////////////////////");

 
