/*   SCRIPT de TONNELLE & MACZYTA   */

//test avec matrices aléatoires et vérification du résultat
clear
pathname=get_absolute_file_path("exo1.sce")
exec(pathname+'\fonctions.sci',-1);

/*  variables  */
    //A = matrice inversible
    //res = résultat de l'inversion
    //n = type de matrice (n,n)
n=5;
A=round(100*rand(n,n)-50);
//A=[4,-3,18,-52,-138;-12,8,-50,146,388;8,-7,42,-120,-318;4,-2,10,-32,-84;-12,9,-50,140,376];
//A=[7,13,9,2,10;3,11,4,12,14;15,8,16,5,17;18,19,6,20,21;22,23,24,25,26];
res=eye(5,5);

/*  affichage des variables  */
disp(n,"n=");
disp(A,"A=");
disp(res,"res=");

/*  affichage résultat attendu  */
disp(inv(A),"résultat attendu : A^-1 = ");

/*  affichage de début  */
affichage = [A res]; //concaténation des 2 matrices
disp(affichage,"On forme la ''grosse'' matrice :");

/*  fonctions  */
//FONCTION MAGIQUE:
//A = matrice à traiter
//res = résultat de l'inverse de la matrice A
//n = taille des matrices
/*
function [A,res]=MAGIQUE(A,res,n)
    //TRAITEMENT de la matrice par la méthode magique
    diagX=1;
    diagXInv=1;
    diagY=1;
    diagYInv=1;
    //des 2 parties gauche et droite
    for i = 1:5
        for j = 1:5
            if j<>i then
                res(j,i)=A(j,i)/A(diagX,diagY)*(-1);//partie droite
                A(j,i)=modulo(A(j,i),A(diagX,diagY));//partie gauche
                for k = 1:5
                    if k<>i then
                        A(j,k)=A(j,k)+(A(i,k)*res(j,i));//calcul de toutes les cases de gauche de la ligne j
                        res(j,k)=res(j,k)+(res(i,k)*res(j,i));//calcul de toutes les cases de droite de la ligne j
                    end
                end
            end
        end
        //affichage des matrices
        affichage = [A res]; //concaténation des 2 matrices
        disp(affichage,"On forme la ''grosse'' matrice :");
        //passage à la diagonale suivante
        diagX=diagX+1;
        diagY=diagX;
    end
    //division par coéfficient diagonal correspondant
    for j = 1:5
        for k = 1:5
            res(j,k)=res(j,k)/A(diagXInv,diagYInv);
        end 
        A(diagXInv,diagYInv)=1;
        //passage à la diagonale suivante
        diagXInv=diagXInv+1;
        diagYInv=diagYInv+1;
    end
endfunction
*/

/*  exécution  */
[A,res]=MAGIQUE(A,res,n);

//affichage des résultats :
affichage = [A res]; //concaténation des 2 matrices
disp(affichage,"Résultat de la ''grosse'' matrice :");
//affichage du résultat : 
disp(res,"résultat de la matrice :");
