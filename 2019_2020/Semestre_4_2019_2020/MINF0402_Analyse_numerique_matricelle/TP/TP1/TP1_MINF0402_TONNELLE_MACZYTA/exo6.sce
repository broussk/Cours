/*   SCRIPT de TONNELLE & MACZYTA   */

clear
pathname=get_absolute_file_path("exo6.sce")
exec(pathname+'\fonctions.sci',-1);

//variables : 
//A= vecteur des variables A des equations 2 a n 
//B= vecteur des variables B des equations 1 a n
//C= vecteur des variables C des equations 1 a n-1
//D= Vecteur contenant les membres droits des equations
//n= nombre d'équations
n=6;
A=round(10*rand(n,1));
B=round(10*rand(n,1));
C=round(10*rand(n,1));
D=round(10*rand(n,1));

//affichage des variables : 
disp(n,"n=");
disp(A,"A=");
disp(B,"B=");
disp(C,"C=");
disp(D,"D=");

/*  TEST fonction
//FONCTION RESOUTRI:
//A= vecteur des variables A des equations 2 a n 
//B= vecteur des variables B des equations 1 a n
//C= vecteur des variables C des equations 1 a n-1
//D= Vecteur contenant les membres droits des equations
//n= nombre d'équations
//x= vecteur des solutions
function x=RESOUTRI(A,B,C,D,n)
    e(1)=C(1)/B(1);
    f(1)=D(1)/B(1);
    for i=2:n-1
        aux=A(i)*e(i-1)+B(i);
        e(i)= -C(i)/aux;
        f(i)=D(i)-A(i)*f(i-1)/aux;
    end
    f(n)=D(n)-A(n)*f(n-1);
    x(n)=f(n);
    for i=n-1:1 
        x(i)=e(i)*x(i+1)+f(i);
    end
    
endfunction

//FONCTION PRODUITMAT:
//A= vecteur des variables A des equations 2 a n 
//B= vecteur des variables B des equations 1 a n
//C= vecteur des variables C des equations 1 a n-1
//D= Vecteur contenant les membres droits des equations
//n= nombre d'équations
//R= résultat du produit matriciel
function R=PRODUITMAT(A,B,C,D,n)
    R(1)=B(1)*D(1)+C(1)*D(2);
    for i=2:n-1
        R(i)=A(i)*D(i-1)+B(i)*D(i)+C(i)*D(i+1);
    end
    R(n)=A(n)*D(n-1)+B(n)*D(n);
endfunction
*/

//affichage des résultats:
x=RESOUTRI(A,B,C,D,n);
disp(x,"x=");
res=PRODUITMAT(A,B,C,x,n);
disp(res,"res=");

