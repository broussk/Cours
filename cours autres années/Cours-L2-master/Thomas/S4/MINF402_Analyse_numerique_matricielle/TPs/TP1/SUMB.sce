function Cdum=SUMB(Adum,Bdum,ndum,mdum)
    for i=1:ndum
        for j=1:mdum
          Cdum(i,j)=Adum(i,j)+Bdum(i,j);
        end
    end
endfunction
