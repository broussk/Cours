//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
//                              EX 7 TP1                            //
//////////////////////////////////////////////////////////////////////


      //Import et execution du fichier fonctions.sci
pathname = get_absolute_file_path("Ex7_Script.sce")
exec(pathname+'fonctions.sce', -1);

      //initialisation n=6
n=6;

disp("Resolution matrice tridiagonal : MX=D (M étant composé des diagonales A, B et C");

      //initialisation de 6 matrices colonnes (5x1)
      //et de 1 matrice carrée (6x6)
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

      //Création des trois diagonales de M
for i=2:n-1
     M(i,i)=B(i);
     M(i,i+1)=C(i);
     M(i,i-1)=A(i);
end

      //Appel de  :
      //RESOUTRI dans X qui résout la matrice en triangle supérieur
      //PRODUIT dans Y qui est le résultat de MX sans pour autant former M explicitement. Les colonnes de M étant représenté par les matrices colonnes.
X=RESOUTRI(A,B,C,D,n);
Y=PRODUIT(A,B,C,X,n);


      //Affichage final
disp(D,"D=",C,"C=",B,"B=",A,"A=");
disp(M,"Matrice M=");
disp(X,"X=");
disp(Y,"Y (Resultat de MATRICIELLE=");
disp(M*X,"MX = ","Preuve :");
disp(M*X-Y,"reel preuve:")
// M*X-Y
