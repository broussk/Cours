function Cdum=PRODA(Adum,Bdum,ndum,mdum,qdum)
    Cdum=zeros(ndum,mdum);
    for i=1:ndum
        for j=1:qdum
            for k=1:mdum
                Cdum(i,j)=Cdum(i,j)+Adum(i,k)*Bdum(k,j);
            end
        end
    end
endfunction
