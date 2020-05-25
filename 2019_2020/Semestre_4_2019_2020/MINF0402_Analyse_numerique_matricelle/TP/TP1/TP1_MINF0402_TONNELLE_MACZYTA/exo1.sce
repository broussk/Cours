clear

function C=MA_SOMME(A,B,n)
    for i=1:n
        C(i)=A(i)+B(i);
    end
endfunction

function SCA=MON_SCA(A,B,n)
    SCA=0;
    for i=1:n
        SCA=SCA+A(i)*B(i);
    end
endfunction

function [C, D]=SUM_ET_DIF(A,B,n)
    C=MA_SOMME(A,B,n);
    D=0;
    for i=1:n
        D(i)=A(i)-B(i);
    end
//    D>exec;
endfunction
