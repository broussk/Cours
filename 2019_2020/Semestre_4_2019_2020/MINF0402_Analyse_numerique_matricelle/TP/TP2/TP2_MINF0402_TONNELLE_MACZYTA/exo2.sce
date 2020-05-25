/*   SCRIPT de TONNELLE & MACZYTA   */

//test avec matrices aléatoires et vérification du résultat
clear
/*
pathname=get_absolute_file_path("exo2.sce")
exec(pathname+'\fonctions.sci',-1);
*/

/*  variables  */
//N = nombre de points/noeuds
//h = ?
//x = vecteur des xi
//A = matrice du système
//A1 = première sous-matrice de A
//A2 = deuxième sous-matrice de A
//d = second membre
N=7;
h=1/(N+1);
x=linspace(0,1,N);
x([1,N+2])=[];
A=zeros(N,N);

/*  initialisation de A  */
A(1,1) = 2;
A(1,2) = -1;
for i = 2:N-1
    A(i,i) = 2;
    A(i,i+1)=-1;
    A(i,i-1)=-1;
end
A(N,N-1) = -1;
A(N,N) = 2;

/*  affichage des variables  */
disp(N,"nombre de noeuds N = ");
disp(h,"h = ");
disp(A,"A = ");

/*  Début traitement  */
//sous-matrices de A pour ses diagonales
for j = 1:N
    A1(j) = -1;
end
for k = 1:N
    A2(k) = 2;
end
//affichage des sous-matrices
disp(A1,"première sous-matrice de A : ");
disp(A2, "deuxième sous-matrice de A : ");

/*  fonctions  */
    //FONCTION ajouterElementDebutMonoDimLigne:
    //M : matrice mono-dimentionelle Ligne
    //val : valeur a rajouter à la matrice
function M=ajouterElementDebutMonoDimLigne(M,val)
    M = [val M];
endfunction
    //FONCTION ajouterElementFinMonoDimLigne:
    //M : matrice mono-dimentionelle Ligne
    //val : valeur a rajouter à la matrice
function M=ajouterElementFinMonoDimLigne(M,val)
    M = [M val];
endfunction

    //FONCTION ajouterElementDebutMonoDimColonne:
    //M : matrice mono-dimentionelle Colonne
    //val : valeur a rajouter à la matrice
function M=ajouterElementDebutMonoDimColonne(M,val)
    M = [val; M];
endfunction
    //FONCTION ajouterElementFinMonoDimColonne:
    //M : matrice mono-dimentionelle Colonne
    //val : valeur a rajouter à la matrice
function M=ajouterElementFinMonoDimColonne(M,val)
    M = [M; val];
endfunction

  /*   fonction f(x)  */
    //FONCTION fonction_fa:
    //x = valeur quelconque
function res=fonction_fa(x)
    res = 8.*ones(x);
endfunction
    //FONCTION fonction_fb:
    //x = valeur quelconque
function res=fonction_fb(x)
    res = %pi*%pi.*sin(%pi*x);
endfunction
    //FONCTION fonction_fc:
    //x = valeur quelconque
function res=fonction_fc(x)
    res = (6.*x-2).*ones(x);
endfunction
    //FONCTION fonction_fd:
    //x = valeur quelconque
function res=fonction_fd(x)
    res = 25*(%pi*%pi).*sin(5*%pi*x);
endfunction
    //FONCTION fonction_fe:
    //x = valeur quelconque
function res=fonction_fe(x)
    res = 49*(%pi*%pi).*x.*sin(7*%pi*x)-14*%pi.*cos(7*%pi*x);
endfunction

  /*   fonction u(x)  */
    //FONCTION fonction_ua:
    //x = valeur quelconque
function res=fonction_ua(x)
    res = 4*x.*(1-x);
endfunction
    //FONCTION fonction_ub:
    //x = valeur quelconque
function res=fonction_ub(x)
    res = sin(%pi*x).*ones(x);
endfunction
    //FONCTION fonction_uc:
    //x = valeur quelconque
function res=fonction_uc(x)
    res = x.*x.*(1-x);
endfunction
    //FONCTION fonction_ud:
    //x = valeur quelconque
function res=fonction_ud(x)
    res = sin(5*%pi*x).*ones(x);
endfunction
    //FONCTION fonction_ue:
    //x = valeur quelconque
function res=fonction_ue(x)
    res = x.*sin(7*%pi*x);
endfunction

    //FONCTION resolution_illustree:
    //les fonctions à comparer : f(x) et u(x)
/*
function resolution_illustree(X,Y,FONCTION_F, FONCTION_U)
    plot(X,Y);
    plot(FONCTION_F,FONCTION_U,'r*');
endfunction
*/

  //*  on reprend la fonction RESOUTRI de exo 6 TP1  */
    //FONCTION RESOUTRI:
    //A= vecteur des variables A des equations 2 a n 
    //B= vecteur des variables B des equations 1 a n
    //C= vecteur des variables C des equations 1 a n-1
    //D= Vecteur contenant les membres droits des equations
    //n= nombre d'équations
    //x= vecteur des solutions
function x=RESOUTRI(A,B,C,D,n)
    e(1) = C(1)/B(1);
    f(1) = D(1)/B(1);
    for i = 2:n-1
        aux = A(i)*e(i-1)+B(i);
        e(i) = -C(i)/aux;
        f(i) = D(i)-A(i)*f(i-1)/aux;
    end
    f(n) = D(n)-A(n)*f(n-1);
    x(n) = f(n);
    for i = n-1:1 
        x(i) = e(i)*x(i+1)+f(i);
    end
endfunction


/*  exécution  */
    //avec les fonctions fd et ud
Fx=fonction_fd(x);
    //construction du second membre
d=h*h*Fx;
    //traitement des équations
Ux=RESOUTRI(A1,A2,A1,d,N);
    //ajout des bords
Ux=ajouterElementDebutMonoDimColonne(Ux,0);
Ux=ajouterElementFinMonoDimColonne(Ux,0);
Ux=ajouterElementDebutMonoDimLigne(Ux,0);
Ux=ajouterElementFinMonoDimLigne(Ux,1);

/*  affichage des résultats  */
    //affichage de nos points(en fonction de N) et de la courbe de référence (avec 1000 points)
clf;
    //courbe de référence
NN=1000;
X=linspace(0,1,NN);
Y=fonction_fd(X);
plot(X,Y);
    //nos points
plot(x,Ux,'r*');
