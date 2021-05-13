//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo5_script", v.12/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo5_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5; //nombre de ligne et colonne
b = round(10*rand(n,1)); //vecteur colonne à n composantes
A = round(1000*rand(n,n)-500); //matrice A

disp("/////////////////////////--DEBUT--////////////////////////////");
disp("Variables :");

//Affichage des variables
disp("n= ", n);
disp("A= ", A);
disp("b= ", b);

disp("////////////////////--Fonction REDUC--//////////////////////");

//Traitement
[C,d] = REDUC(A,b,n); // retourne le nouveau système triangulaire supérieur Cx = d
res_sup = RESOUSUP(C,b,n); //Appelle de RESOUSUP sur la solution sur la matrice triangulaire superieur inversible C et le vecteur d

//Affichage
disp("Matrice triangulaire inversible de A :", C)
disp("Vecteur:", d)
disp("Matrice solution de RESOUSUP:", res_sup);

disp("////////////////////--Fonction GAUSS--//////////////////////");

//Traitement
gauss = GAUSS(A,b,n); //resolution de gauss Ax = b par notre fonction GAUSS
verif = A*gauss; //resolution de gauss Ax = b par Scilab

disp("////////////////////--RESULTAT--//////////////////////");

//Affichage
disp("b=", b);
disp("Verificaiton Ax = b: ", verif);

disp("Si (b == vérification) alors le programme est correct. Gauss est fonctionel");

disp("/////////////////////////--FIN--//////////////////////////////");
