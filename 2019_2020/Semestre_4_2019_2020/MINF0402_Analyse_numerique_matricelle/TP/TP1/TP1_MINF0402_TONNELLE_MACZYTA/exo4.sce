/*   SCRIPT de TONNELLE & MACZYTA   */

clear
pathname=get_absolute_file_path("exo4.sce")
exec(pathname+'\fonctions.sci',-1);

//variables : 
//Asup= matrice triangulaire supérieure inversible (n,n)
//Ainf= matrice triangulaire inférieure inversible (n,n)
//b= vecteur colonne à n composantes
n=5;
b=round(10*rand(n,1));
Asup=triu(round(100*rand(n,n)-50));
Ainf=tril(round(100*rand(n,n)-50));

//affichage des variables : 
disp(n,"n=");
disp(Asup,"Asup=");
disp(Ainf,"Ainf=");
disp(b,"b=");

/*  TEST fonction
//FONCTION RESOUINF:
//Ainf=matrice triangulaire inférieure inversible
//b=vecteur colonne à n composantes
//Ax=b => lorsque A est triangulaire inférieure
function X=RESOUINF(Ainf,b,n)
    X=zeros(b);
    X(1,1)=b(1,1)/Ainf(1,1);
    for i=2:n
         aux=0;
         for k=1:i-1
             aux=aux+Ainf(i,k)*X(k);
         end
         X(i)=(b(i)-aux)/Ainf(i,i);
    end
endfunction


//FONCTION RESOUSUP:
//Asup=matrice triangulaire supérieure inversible
//b=vecteur colonne à n composantes
//Ax=b => lorsque A triangulaire supérieur
function Y=RESOUSUP(Asup,b,n)
    Y=zeros(b);

    Y(n,1)=b(n,1)/Asup(n,n);
    for i=n-1:-1:1
         aux=0;
         for k=i+1:n
             aux=aux+Asup(i,k)*Y(k);
         end
         Y(i)=(b(i)-aux)/Asup(i,i);
    end
endfunction
*/

//affichage des résultats :
res=RESOUSUP(Asup,b,n);
disp(res,"res Asup =");
res=RESOUINF(Ainf,b,n);
disp(res,"res Ainf =");
