/*   FONCTIONS de TONNELLE & MACZYTA   */

//fichier contenant toutes les fonctions que les scripts ont besoin
//ce fichier charge toutes les fonctions pour les  exercices

/*   EXERCICE   4   */

    //FONCTION RESOUINF:
    //Ainf=matrice triangulaire inférieure inversible
    //b=vecteur colonne à n composantes
    //Ax=b => lorsque Ainf est triangulaire inférieure
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
    //Ax=b => lorsque Asup triangulaire supérieur
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

/*   EXERCICE   5   */

    //FONCTION REDUC:
    //A=matrice triangulaire suppérieure
    //b=vecteur colonne à n composantes
    //Ax=b => systeme triangulaire supérieur obtenu après la réduction de Gauss
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
    
    //FONCTION RESOUSUP utilisé
    
    //FONCTION GAUSS
    //A = matrice triangulaire supérieure de composant (n,n)
    //b = vecteur colonne de n composant
    //résolution de la matrice A par la méthode de GAUSS
    function X=GAUSS(A,b,n)
        X=zeros(n,1);
        [A,b]=REDUC(A,b,n);
        X=RESOUSUP(A,b,n);
    endfunction

/*   EXERCICE   6   */

    //FONCTION RESOUTRI:
    //A= vecteur des variables A des equations 2 a n 
    //B= vecteur des variables B des equations 1 a n
    //C= vecteur des variables C des equations 1 a n-1
    //D= Vecteur contenant les membres droits des equations
    //n= nombre d'équations
    //x= vcteur des solutions
    function x=RESOUTRI(A,B,C,D,n)
        e(1)=C(1)/B(1);
        f(1)=D(1)/B(1);
        for i=2:n-1
            aux=A(i)*e(i-1)+B(i);
            e(i)= -C(i)/aux;
            f(i)=D(i)-A(i)*f(i-1)/aux;
        end
        f(n)=D(n)-A(n)*f(n-1);
        x(n)=f(n);
        for i=n-1:1
            x(i)=e(i)*x(i+1)+f(i);
        end
        
    endfunction
    
    //FONCTION PRODUITMAT:
    //A= vecteur des variables A des equations 2 a n 
    //B= vecteur des variables B des equations 1 a n
    //C= vecteur des variables C des equations 1 a n-1
    //D= Vecteur contenant les membres droits des equations
    //n= nombre d'équations
    //R= résultat du produit matriciel
    function R=PRODUITMAT(A,B,C,D,n)
        R(1)=B(1)*D(1)+C(1)*D(2);
        for i=2:n-1
            R(i)=A(i)*D(i-1)+B(i)*D(i)+C(i)*D(i+1);
        end
        R(n)=A(n)*D(n-1)+B(n)*D(n);
    endfunction
    
