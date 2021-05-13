//DUPONT Corentin & LACROIX Owen S4F3B
//File "functions", v.24/02/2021

//Fonction RESOUTRI
//A = vecteur (n,1) de la matrice M (n,n)
//B = vecteur (n,1) de la matrice M (n,n)
//C = vecteur (n,1) de la matrice M (n,n)
//D = vecteur (n,1) de la matrice M (n,n)
//n = taille
function [X] = RESOUTRI(A,B,C,D,n)
    E(1)= -C(1)/B(1)
    F(1)= D(1)/B(1)
    for i=2:n-1
        denom = A(i)* E(i-1)+B(i)
        E(i)= -C(i)/denom
        F(i)= (D(i)-A(i)*F(i-1))/denom    
    end
    F(n)= (D(n)-A(n)*F(n-1))/(A(n)*E(n-1)+B(n))
    X(n)= F(n)
    for i=n-1:-1:1 
        X(i)= E(i)*X(i+1)+F(i);
    end
endfunction


//Fonction PRODUIT
//A = vecteur (n,1) de la matrice M (n,n)
//B = vecteur (n,1) de la matrice M (n,n)
//C = vecteur (n,1) de la matrice M (n,n)
//x = vecteur (n,1) de la fonction RESOUTRI
//n = taille
//calcul le produit : M*x => D
function Y=PRODUIT(A,B,C,X,n)
    Y=zeros(n,1);
    Y(1)=B(1)*X(1)+C(1)*X(2);
    Y(n)=B(n)*X(n)+A(n)*X(n-1);
    for i=2:n-1
        Y(i)=A(i)*X(i-1)+B(i)*X(i)+C(i)*X(i+1);
    end
endfunction


//Résout une matrice selon la méthode magique de Gauss
function B=MAGIQUE(A)
    B=eye(A); //Matrice identité de A
    I = 1; //compteur des étapes
    for k=1:n
       for i=1:k-1
               tmp=A(i,k)/A(k,k);
               for j=1:n
                   A(i,j)=A(i,j)-A(k,j)*tmp
                   B(i,j)=B(i,j)-B(k,j)*tmp
               end
       end
       for i=k+1:n
               tmp=A(i,k)/A(k,k);
               for j=1:n
                   A(i,j)=A(i,j)-A(k,j)*tmp
                   B(i,j)=B(i,j)-B(k,j)*tmp
               end
       end
       disp("ETAPE:", I)
       disp([A,B])
       I = I+1
   end
   disp("/////////////////////////--RESULTATS--//////////////////////////////");
   //On divise par les coefficients de la diagonale
   for i=1:n
           for k=1:n
               B(i,k)=B(i,k)/A(i,i)
       end
        A(i,i)=A(i,i)/A(i,i)
   end
   disp("Division:", [A,B])
endfunction

//Définition de la fonction ua(t)
function y=ua(t); y=t.*sin(7*%pi*t); endfunction

//Définition de la fonction ub(t)
function y=ub(t); y=(t-t^2).*(2+sin(9*%pi*t)); endfunction

//Définition de la fonction fa(t)
function y=fa(t); y=49*%pi^2*t.*sin(7*%pi*t)-14*%pi*cos(7*%pi*t); endfunction

//Définition de la fonction fb(t)
function y=fb(t); y=4+2*sin(9*%pi*t)+(2*t-1)*18*%pi*cos(9*%pi*t)+(t-t^2)*((9*%pi)^2)*sin(9*%pi*t); endfunction






