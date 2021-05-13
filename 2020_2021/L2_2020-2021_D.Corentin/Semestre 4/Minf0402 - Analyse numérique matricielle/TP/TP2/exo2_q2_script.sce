//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo2_q2_script", v.2/03/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo2_q2_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

N=40 //un entier
i=15 //un entier avec 1 ≤ i ≤ N
T=[] //tableau ou on va sctocker i*h
D=[] //tableau ou on va sctocker (h^2)*fa(T(i)) et (h^2)*fb(T(i))
h=1/(N+1) //définiton de h
A = ones(N, 1)* -1 //vecteur de taille (n,1) composé de -1
B = ones(N, 1)* 2 //vecteur de taille (n,1) composé de 2
C = A //vecteur de taille (n,1) composé de -1

//On remplit T et D avec la fonction fa(t)
for i=1:N
    T(i)=i*h
    D(i)=(h^2)*fa(T(i)) //on fait appelle à fa(t) qui est dans le fichier functions
end
Y= RESOUTRI(A,B,C,D,N) // On ressout MY = D quand D est calculé avec fa(t) avec la fonction RESOUTRI

//On fait le tracage de Y quand D est calculé avec fa(t)
plot(T,Y,'b')  // courbe en bleu
plot(T,Y,'r+') // on ajoute des + en rouge

//On remplit T et D avec la fonction fb(t)
for i=1:N
    T(i)=i*h
    D(i)=(h^2)*fb(T(i)) //on fait appelle à fb(t) qui est dans le fichier functions
end
Y= RESOUTRI(A,B,C,D,N) // On ressout MY = D quand D est calculé avec fb(t) avec la fonction RESOUTRI

//On fait le tracage de Y quand D est calculé avec fb(t)
plot(T,Y,'g') // courbe en bleu
plot(T,Y,'r+') // on ajoute des + en rouge

