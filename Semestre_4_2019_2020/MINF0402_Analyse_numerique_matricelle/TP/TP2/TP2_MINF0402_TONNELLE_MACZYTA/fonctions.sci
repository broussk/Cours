/*   FONCTIONS de TONNELLE & MACZYTA   */

//fichier contenant toutes les fonctions que les scripts ont besoin
//ce fichier charge toutes les fonctions pour les  exercices

/*   EXERCICE   1   */

    //FONCTION MAGIQUE:
    //A = matrice à traiter
    //res = résultat de l'inverse de la matrice A
    //n = taille des matrices
    function [A,res]=MAGIQUE(A,res,n)
        //TRAITEMENT de la matrice par la méthode magique
        diagX=1;
        diagXInv=1;
        diagY=1;
        diagYInv=1;
        //des 2 parties gauche et droite
        for i = 1:5
            for j = 1:5
                if j<>i then
                    res(j,i)=A(j,i)/A(diagX,diagY)*(-1);//partie droite
                    A(j,i)=modulo(A(j,i),A(diagX,diagY));//partie gauche
                    for k = 1:5
                        if k<>i then
                            A(j,k)=A(j,k)+(A(i,k)*res(j,i));//calcul de toutes les cases de gauche de la ligne j
                            res(j,k)=res(j,k)+(res(i,k)*res(j,i));//calcul de toutes les cases de droite de la ligne j
                        end
                    end
                end
            end
            //affichage des matrices
            affichage = [A res]; //concaténation des 2 matrices
            disp(affichage,"On forme la ''grosse'' matrice :");//affichage avec précision de 3 : \%.3f
            //passage à la diagonale suivante
            diagX=diagX+1;
            diagY=diagX;
        end
        //division par coéfficient diagonal correspondant
        for j = 1:5
            for k = 1:5
                res(j,k)=res(j,k)/A(diagXInv,diagYInv);
            end 
            A(diagXInv,diagYInv)=1;
            //passage à la diagonale suivante
            diagXInv=diagXInv+1;
            diagYInv=diagYInv+1;
        end
    endfunction
    
    
/*   EXERCICE   2   */
    //FONCTION 
    //
    //
    //
    /*
    function ()
        
    endfunction
