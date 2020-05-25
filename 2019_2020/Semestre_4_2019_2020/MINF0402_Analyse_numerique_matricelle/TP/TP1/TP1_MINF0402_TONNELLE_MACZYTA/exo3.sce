clear

function C=PRODMAT(A,B,n,m,q)
    for i=1:n
        for j=1:q
            C(i,j)=0;
            for k=1:m
               C(i,j)=C(i,j)+A(i,k)*B(k,j);
            end
        end
    end
endfunction
