clear

function C=SUMB(A,B,n,m)
    for i=1:n
        for j=1:m
            C(i,j)=A(i,j)+B(i,j);
        end 
    end
endfunction

function [C,D]=SUMDIFF(A,B,n,m)
    C=SUMB(A,B,n,m)
    for i=1:n
        for j=1:m
            D(i,j)=A(i,j)-B(i,j);
        end 
    end
endfunction
