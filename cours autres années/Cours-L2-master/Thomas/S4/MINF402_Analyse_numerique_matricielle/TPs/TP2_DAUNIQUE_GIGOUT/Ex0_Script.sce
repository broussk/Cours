//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
//                              EX 0 TP2                            //
//////////////////////////////////////////////////////////////////////


    //import et execution du fichier fonctions
pathname = get_absolute_file_path("Ex0_Script.sce")
exec(pathname+'\fonctions.sce', -1);

    //initialisation n=3
n=3

    //Création d'une Matrice 3x3 random
A=round(rand(n,n)*10+1);

    //affichage
disp(A,"¨Matrice A")

    //appelle de la fonction MAGIQUE
    //qui résout avec la méthode de Gauss la matrice A
Z=MAGIQUE(A);

    //Création de la matrice inverse de A
Y=inv(A)


    //Preuve MAGIQUE crée la matrice inverse de A donc Y doit être égale à Z
disp(Y-Z,"preuve:");
disp("Les coefficients sont égaux à 0 ou très proches de 0. C est alors vérifié")
