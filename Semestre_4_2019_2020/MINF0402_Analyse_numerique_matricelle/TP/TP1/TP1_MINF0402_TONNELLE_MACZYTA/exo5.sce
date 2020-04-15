/*   SCRIPT de TONNELLE & MACZYTA   */

clear
pathname=get_absolute_file_path("exo5.sce")
exec(pathname+'\fonctions.sci',-1);

//variables : 
//A= matrice triangulaire supérieure inversible (n,n)
//b= vecteur colonne à n composantes
n=4;
b=round(10*rand(n,1));
A=triu(round(100*rand(n,n)-50));

//affichage des variables : 
disp(n,"n=");
disp(A,"A=");
disp(b,"b=");

/*  TEST fonction
//FONCTION REDUC:
//A=matrice triangulaire suppérieure
//b=vecteur colonne à n composantes
//Ax=b => systeme triangulaire supérieur obtenu après la réduction de Gauss
function [A,b]=REDUC(A,b,n)
    for k=1:n-1
        for i=k+1:n
            Aux=A(i,k)/A(k,k);
            for j=k+1:n
                A(i,j)=A(i,j)-Aux*A(k,j);
            end
            A(i,k)=0;
            b(i)=b(i)-Aux*b(k);
        end
    end
endfunction

//FONCTION RESOUSUP:
//A=matrice triangulaire suppérieure de composant (n,n)
//b=vecteur colonne à n composantes
//Ax=b => systeme triangulaire supérieur obtenu après la réduction de Gauss
function Y=RESOUSUP(A,b,n)
    Y=zeros(b);

    Y(n,1)=b(n,1)/A(n,n);
    for i=n-1:-1:1
         aux=0;
         for k=i+1:n
             aux=aux+A(i,k)*Y(k);
         end
         Y(i)=(b(i)-aux)/A(i,i);
    end
endfunction

//FONCTION GAUSS
//A = matrice triangulaire supérieure de composant (n,n)
//b = vecteur colonne de n composant
//résolution de la matrice A par la méthode de GAUSS
function X=GAUSS(A,b,n)
    X=zeros(n,1);
    [A,b]=REDUC(A,b,n);
    X=RESOUSUP(A,b,n);
endfunction
*/

//affichage des résulatats:
res=GAUSS(A,b,n);
disp(res, "res =");
