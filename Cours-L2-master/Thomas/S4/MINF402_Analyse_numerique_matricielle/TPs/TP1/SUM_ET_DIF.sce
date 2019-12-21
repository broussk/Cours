function [Cdum,Ddum]=SUM_ET_DIF(Adum,Bdum,ndum)
    for i=1:ndum
        Cdum(1,i)=Adum(1,i)+Bdum(1,i);
        Ddum(1,i)=Adum(1,i)-Bdum(1,i);        
    end
endfunction
