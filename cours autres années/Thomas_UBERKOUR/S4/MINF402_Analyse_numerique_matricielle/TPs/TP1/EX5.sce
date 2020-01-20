n=5;
A=round(10*rand(n,n));
b=round(10*rand(5,1));
D=tril(A);
E=triu(A);
X=RESOUINF(A,b,n);
Y=RESOUSUP(A,b,n);
disp(X);
C=D*X-b;
disp(C);
F=E*Y-b;
disp(F);

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


