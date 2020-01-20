//////////////////////////////////////////////////////////////////////
//                          DAUNIQUE WILFRIED                       //
//                          GIGOUT     THOMAS                       //
//////////////////////////////////////////////////////////////////////
pathname = get_absolute_file_path("EX7_Script.sce")
exec(pathname+'\Fonctions.sci', -1);
n=5;
A=round(10*rand(5,1)); 
B=round(10*rand(5,1)); 
C=round(10*rand(5,1)); 
D=round(10*rand(5,1)); 
X=zeros(n,1); 
[X,Y]=RESOUTRI(A,B,C,D,n);
disp(X);
