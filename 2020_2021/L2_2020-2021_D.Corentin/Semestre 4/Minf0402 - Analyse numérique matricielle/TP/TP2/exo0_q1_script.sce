//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo0_q1_script", v.17/02/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo0_q1_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
n=7;
A = 10*rand(n,1);
B = 10*rand(n,1);
C = 10*rand(n,1);
D = 10*rand(n,1);

disp("/////////////////////////--DEBUT--////////////////////////////");

//Affichage
disp("n=", n);
disp("A=", A);
disp("B=", B);
disp("C=", C);
disp("D=", D);

//Traitement
resoutri = RESOUTRI(A,B,C,D,n);
res_prod = PRODUIT(A,B,C,resoutri,n) //M*resoutri => vecteur d ci-dessus
verif = res_prod - D // => avoir des valeurs très petites ou proches de 0

disp("/////////////////////////--RESULTATS--////////////////////////////");

//Affichage résultat
disp("Resoutri=", resoutri);
disp("Produit=", res_prod);
disp("Verif =", verif );

disp("Si (Produit == vecteur D) et que la vérification contient des valeurs proches ou égale à 0, alors le programme est correct");

disp("/////////////////////////--FIN--//////////////////////////////");

 
