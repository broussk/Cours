u=zeros(5,5);
y=zeros(5,1);
n=n;
A=round(10*rand(n,n));
b=round(10*rand(5,1)); 
[U,b]=REDUC(A,Y,n);
disp(U);
K=RESOUSUP(U,b,n);
disp(K);

L=GAUSS(A,b,n);
disp(L);

function [U,y]=REDUC(A,b,n)
   
    for i=2:n
         aux=0;
         for k=1:i-1
             aux=aux+A(i,k)*X(k);
         end
         X(i)=(b(i)-aux)/A(i,i);
    end 
    
endfunction

function X=GAUSS(A,b,n)
    X=zeros(n,1);
    [A,b]=REDUC(A,b,n);
    X=RESOUSUP(A,b,n);
endfunction



