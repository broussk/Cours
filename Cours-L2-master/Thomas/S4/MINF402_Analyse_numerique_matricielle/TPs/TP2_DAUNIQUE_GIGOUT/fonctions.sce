//Fonction qui résout une matrice selon l'algorithme vu en CM/TD.
function X = RESOUTRI(A,B,C,D,n)
    E=zeros(n,1);
    F=zeros(n,1);
    E(1)=-C(1)/B(1);
    F(1)=D(1)/B(1);
    for i=2:n-1
        Denom=A(i)*E(i-1)+B(i);
        E(i)=-C(i)/Denom;
        F(i)=(D(i)-A(i)*F(i-1))/Denom;
    end
    F(n)=(D(n)-A(n)*F(n-1))/(A(n)*E(n-1)+B(n));
    X(n)=F(n);
    for i=n-1:-1:1
        X(i)=E(i)*X(i+1)+F(i);
    end
endfunction

//Fonction qui retourne le produit de plusieurs matrices colonnes entre elles.
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
    B=eye(A);
    for k=1:n
       for i=1:k-1
               temp=A(i,k)/A(k,k);
               for j=1:n
                   A(i,j)=A(i,j)-A(k,j)*temp;
                   B(i,j)=B(i,j)-B(k,j)*temp;
               end
       end
       for i=k+1:n
               temp=A(i,k)/A(k,k);
               for j=1:n
                   A(i,j)=A(i,j)-A(k,j)*temp;
                   B(i,j)=B(i,j)-B(k,j)*temp;
               end
       end

       //diviser par les coefficient diag
       disp( "ETAPE:")
       disp ([A,B])
   end
   for i=1:n
           for k=1:n
               B(i,k)=B(i,k)/A(i,i);
       end
        A(i,i)=A(i,i)/A(i,i)
   end
   disp ([A,B],"Division:")
endfunction
