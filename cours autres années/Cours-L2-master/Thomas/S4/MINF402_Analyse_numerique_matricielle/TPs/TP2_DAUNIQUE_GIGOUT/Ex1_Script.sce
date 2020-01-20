//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
//                              EX 1 TP2                            //
//////////////////////////////////////////////////////////////////////


      //import et execution du fichier fonctions.sci
pathname = get_absolute_file_path("Ex1_Script.sce")
exec(pathname+'\fonctions.sce', -1);

      //initialisation n=10
n=10;

disp("Resolution matrice tridiagonal : MX=D (M étant composé des diagonales A, B et C");

      //initialisation de 6 matrices colonnes (5x1)
      //et de 1 matrice carrée (10x10)
      //toutes à 0
A=zeros(n,1);
B=zeros(n,1);
C=zeros(n,1);
X=zeros(n,1);
D=zeros(n,1);
M=zeros(n,n);
Y=zeros(n,1);

      //Création random des matrices 5x1
A=round(rand(n,1)*10+1);  //Random entre 1 et 10
B=round(rand(n,1)*10+20); //Random entre 20 et 30
C=round(rand(n,1)*10+1);  //Random entre 1 et 10
D=round(rand(n,1)*10+1);  //Random entre 1 et 10

      //création des trois diagonales de M
for i=2:n-1
     M(i,i)=B(i);
     M(i,i+1)=C(i);
     M(i,i-1)=A(i);
end

      //Modifications pour que RESOUTRI fonctionne
      //On modifie les quatres coins de la matrice avec les bonnes valeurs
M(1,1)=B(1);
M(1,2)=C(2);
M(n,n)=B(n);
M(n,n-1)=A(n);
disp("APPEL RESOUTRI")
X=RESOUTRI(A,B,C,D,n);
disp("APPEL PRODUIT")
Y=PRODUIT(A,B,C,X,n);

      //affichage
disp(D,"D=",C,"C=",B,"B=",A,"A=");
disp(M,"Matrice M=");
disp(X,"X=");
disp(Y,"Y (Resultat de PRODUIT MATRICIELLE=");
disp(M*X,"MX = " );
disp(M*X-Y,"reel preuve:");
