//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo4a_script", v.12/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo4a_script.sce");
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

disp("////////////////////--Fonction RESOUINF--/////////////////////");

//Traitement
A_INF = tril(A); //récupére la partie triangulaire inferieur de A.
disp("Partie triangulaire inférieur (A_INF): ", A_INF );

res_inf = RESOUINF(A_INF,b,n); //résolution du système A_INF*x = b si A_INF est inversible par notre fonction
verif_res_inf = A_INF\b; //résolution du système A_INF*x = b si A_INF est inversible par Scilab
sol = A_INF*res_inf-b; //résolution de A_INF*res_inf-b

disp("////////////////////////--RESULTAT--//////////////////////////");

//Affichages résultat
disp("-> Résolution A_INF*x = b, par notre fonction: ", res_inf);
disp("-> Vérification A_INF*x = b, par Scilab: ", verif_res_inf);

disp("-> Solution de AX-b: ", sol );
disp("=> AX-b=0 donc AX = b (ou proche de 0), si cela est vrai alors le programme est correct.");

disp("/////////////////////////--FIN--//////////////////////////////");
