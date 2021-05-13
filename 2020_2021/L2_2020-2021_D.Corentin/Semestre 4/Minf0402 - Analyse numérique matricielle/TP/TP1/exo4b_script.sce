//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo4b_script", v.12/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo4b_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=5; //nombre de ligne et colonne
b = round(10*rand(n,1)); //vecteur colonne à n composantes
A = round(1000*rand(n,n)-500); //matrice 

disp("/////////////////////////--DEBUT--///////////////////////////");
disp("Variables :");

//Affichage
disp("n= ", n);
disp("A= ", A);
disp("b= ", b);

disp("////////////////////--Fonction RESOUSUP--/////////////////////");

//Traitement
A_SUP = triu(A); //récupére la partie triangulaire supérieur de A.
disp("Partie triangulaire supérieur (A): ", A_SUP );

res_sup = RESOUSUP(A_SUP,b,n); //résolution du système A_SUP*x = b si A_SUP est inversible par notre fonction
verif_res_sup = A_SUP\b; //résolution du système A_SUP*x = b si A_SUP est inversible par Scilab
sol = A_SUP*res_sup-b; //résolution de A_SUP*res_sup-b


disp("////////////////////////--RESULTAT--//////////////////////////");

//Affichage résultat
disp("-> Résolution A_SUP*x = b, par notre fonction:: ", res_sup);
disp("-> Vérification A_SUP*x = b, par Scilab: ", verif_res_sup);

disp("-> Solution: AX-b = ", sol );
disp("=> AX-b=0 donc AX = b (ou proche de 0), si cela est vrai alors le programme est correct.");

disp("/////////////////////////--FIN--//////////////////////////////");
