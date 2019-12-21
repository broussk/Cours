//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
pathname = get_absolute_file_path("EX6_Script.sce")
exec(pathname+'\Fonctions.sci', -1);
/////////////////////////////////////////////////////////////////////
    //INITIALISATION

//initialisation de la taille n
n=5;


//initialisation aléatoire de la Matrice A de taille 5,5
A=round(10*rand(n,n)); 

//initialisation aléatoire de la Matrice b de taille 5,1
b=round(10*rand(5,1));


  //affichage
disp("affichage de A :")
disp(A);
disp("affichage de b :")
disp(b);
disp("////////////////////////////////////////////////////////////////")

  
//FONCTIONS

    //TEST REDUC
disp("REDUC");
//Appelle de la fonction REDUC
//Prend en parametre A Matrice 5,5
//                   b Matrice 5,1
//                   n la taille de la Matrice carré A(5x5/n=5)
//Renvoie une Matrice U 5,5 et une matrice c 5,1
[U,c]=REDUC(A,b,n);
//affichage de la Matrice triangulaire Supérieur et du vecteur c
disp("Matrice triangulaire inversible de A :")
disp(U,"U=");
disp("Vecteur:")
disp(c,"c=");
//Appelle de RESOUSUP sur la solution 
//sur la Matrice triangulaire superieur inversible U
//                             et le vecteur b et la taille n
K=RESOUSUP(U,b,n);
//Affichage de la Matrice K solution 
disp("Affichage de la Matrice K solution de RESOUSUP sur U et b:")
disp(K);

//Test Comparaison
    //si au final de l'appelle de GAUSS on Obtient les bons résultat alors 
    //REDUC fonctionne

disp("////////////////////////////////////////////////////////////////")
disp("GAUSS");
    //TEST GAUSS
 
//Appelle de GAUSS
//prend en parametre A(Matrice 5,5)
//                  ,b(vecteur 1,5)
//                  ,n(taille 5 de A(n,n ou b(1,n)
//retourne L Solution 
L=GAUSS(A,b,n);
//test de comparaison
    //si A*l == H alors le programme fonctionne
H=A*L;
disp("COMPARAISON");
disp("b=");
disp(b);
disp("H=");
disp(H);
disp("SI H==b alors GAUSS fonctionne");




//////////////////////////////////////////////////////////////////////
