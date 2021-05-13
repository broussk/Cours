//DUPONT Corentin & LACROIX Owen S4F3B
//File "functions", v.12/02/2021

//Fonction MON_SCA
//A & B = matrice de taille (n,n)
//n = nombre de ligne pour A et B
//=> retourne le produit scalaire de A et B
function SCA=MON_SCA(A,B,n)
    SCA=0
    for i=1:n
        SCA=SCA+A(i)*B(i)
    end
endfunction


//Fonction SUMB
//A & B = matrice de taile (n,m)
//n = nombre de ligne de A et B
//m = nombre de colonne de A et B
//=> retourne l'addition matricielle entre A et B
function C=SUMB(A,B,n,m)
     for i=1:n
        for j=1:m
            C(i,j)= A(i,j) + B(i,j)
        end 
    end
endfunction


//Fonction SUMDIFF
//A & B = matrice de taile (n,m)
//n = nombre de ligne de A et B
//m = nombre de colonne de A et B
// => retourne la soustraction matricielle entre A et B
function [C,D]=SUMDIFF(A,B,n,m)
    C=SUMB(A,B,n,m)
    for i=1:n
        for j=1:m
            D(i,j)=A(i,j)-B(i,j)
        end 
    end
endfunction

//Fonction PRODMAT
//A = matrice de taille (n,m)
//B = matrice de taille (m,q)
//n = nombre de ligne pour A
//m = nombre de ligne pour B et nombre de colonne pour A
//q = nombre de colonne pour B
// => retourne le produit matricielle entre A et B
function C=PRODMAT(A,B,n,m,q)
    for i=1:n
        for j=1:q
            C(i,j)=0
            for k=1:m
               C(i,j)=C(i,j) +A(i,k)*B(k,j)
            end
        end
    end
endfunction


//Fonction RESOUINF
//INF = partie triangulaire inférieur inversible d'une matrice de taille (n,n)
//b = un vecteur à (n,1) composante
//n = taille de la matrice SUP et le nombre de composante du vecteur b
//=> retourne la solution X qui est un vecteur de taille (n,1) => INF*x = b
function [X]=RESOUINF(INF,b,n)
    X=zeros(b); 
    X(1)=b(1)/INF(1,1)
    for i=2:n
         tmp=0;
         for k=1:i-1
             tmp=tmp+INF(i,k)*X(k)
         end
         X(i)=(b(i)-tmp)/INF(i,i)
    end
endfunction


//Fonction RESOUSUP
//SUP = partie triangulaire supérieur inversible d'une matrice de taille (n,n)
//b = un vecteur à (n,1) composante
//n = taille de la matrice SUP et le nombre de composante du vecteur b
//=> retourne la solution X qui est un vecteur de taille (n,1) => SUP*x = b
function [X]=RESOUSUP(SUP,b,n)
    X=zeros(b);
    X(n)=b(n)/SUP(n,n)
    for i=n-1:-1:1
         tmp=0
         for k=i+1:n
             tmp=tmp+SUP(i,k)*X(k)
         end
         X(i)=(b(i)-tmp)/SUP(i,i)
    end
endfunction


//Fonction REDUC
//A = une matrice de taille (n,n)
//b = un vecteur à (n,1) composante
//n = taille de la matrice A et le nombre de composante du vecteur b
//=> retourne une matrice A(n,n) et un vecteur b(n,1)
function [A,b]=REDUC(A,b,n)
    for k=1:n-1
        for i=k+1:n
            tmp=A(i,k)/A(k,k)
            for j=k+1:n
                A(i,j)=A(i,j)-tmp*A(k,j)
            end
            A(i,k)=0
            b(i)=b(i)-tmp*b(k)
        end
    end
endfunction


//Fonction GAUSS
//A = une matrice de taille (n,n)
//b = un vecteur à (n,1) composante
//n = taille de la matrice A et le nombre de composante du vecteur b
//=> retourne la solution X qui est un vecteur de taille (n,1)
function [X]=GAUSS(A,b,n)
    X=zeros(n);
    [A,b]=REDUC(A,b,n)
    X=RESOUSUP(A,b,n)
endfunction
