//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////

//FONCTIONS

    //RESOUINF
function [X]=RESOUINF(A,b,n)
    X=zeros(b); 
    X(1,1)=b(1,1)/A(1,1);
    for i=2:n
         aux=0;
         for k=1:i-1
             aux=aux+A(i,k)*X(k);
         end
         X(i)=(b(i)-aux)/A(i,i);
    end
endfunction

    //RESOUSUP
function [Y]=RESOUSUP(A,b,n)
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

    //REDUC
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

    //GAUSS
function X=GAUSS(A,b,n)
    X=zeros(n,1);
    [A,b]=REDUC(A,b,n);
    X=RESOUSUP(A,b,n);
endfunction



//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
