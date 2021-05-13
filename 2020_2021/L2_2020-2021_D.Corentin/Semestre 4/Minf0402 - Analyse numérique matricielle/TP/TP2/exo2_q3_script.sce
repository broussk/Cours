//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo2_q3_script", v.2/03/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo2_q3_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

i=15 //un entier avec 1 ≤ i ≤ N
T=[] //tableau ou on va sctocker i*h
D=[] //tableau ou on va sctocker (h^2)*fa(T(i)) et (h^2)*fb(T(i))

//On va afficher le graphe avec N évoluant de 10 en 10. (de 10 à 100)
for N=10:10:100
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

  sleep(2000) // Attend 2 secondes puis affiche le prochaine graphe (N+=10)
  clf; //Vide la fenêtre ou il y a le graphe
end

