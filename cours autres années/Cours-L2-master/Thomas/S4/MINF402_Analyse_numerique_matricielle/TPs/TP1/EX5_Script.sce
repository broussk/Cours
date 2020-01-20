//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
pathname = get_absolute_file_path("EX5_Script.sce")
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

  

    //TEST RESOUINF
    
disp("FONCTION RESOUINF :");

//Appelle de la fonstion RESOUINF qui renvoit une matrice
//X de taille 5,1 et qui a pour parametres 
//la Matrice A et b et la taille n
X=RESOUINF(A,b,n);

//initalisation d'une Matrice D correspondant A la matrice 
//triangulaire inferieur inversible de A 
D=tril(A);

//Affichage de la Matrice X solution 
disp("Affichage de la Matrice X solution de RESOUINF sur A et b:")
disp(X);

//Test Comparaison
    //si toutes les valeurs de C sont =0 ou très proche de zéros
    //alors RESOUINF fonctionne
C=D*X-b;
//Affichage de la matrice 5,1 C
disp(C,"Solution: AX-b");
disp("AX-b=0 donc AX = b (ou tres proche de 0)");
disp("Cela prouve que le programme fonctionne");
disp("////////////////////////////////////////////////////////////////")
//////////////////////////////////////////////////////////////////////

    //TEST RESOUSUP
disp("FONCTION RESOUSUP :");


//Appelle de la fonstion RESOUSUP qui renvoit une matrice
//Y de taille 5,1 et qui a pour parametres 
//la Matrice A et b et la taille n

Y=RESOUSUP(A,b,n);

//initalisation d'une Matrice D correspondant A la matrice 
//Supérieur inversible de A pour le test
E=triu(A);

//Affichage de la Matrice Y solution 
disp("Affichage de la Matrice Y solution de RESOUSUP sur A et b:")
disp(Y);

//Test Comparaison
    //si toutes les valeurs de F sont =0 ou très proche de zéros
    //alors RESOUSUP fonctionne
F=E*Y-b;
//Affichage de la matrice 5,1 C
disp(F,"Solition : AY-b");
disp("AY-b=0 donc AY = b (ou tres proche de 0)");
disp("Cela prouve que le programme fonctionne");
