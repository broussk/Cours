//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo0_q2_script_script", v.02/03/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo0_q2_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Déclarations
NN = [10, 10^2, 10^3, 10^4, 10^5, 10^6] //tableau contenant les tailles à tester

//On a testé avec 10^7 il a fallut 2min17s

EX = [] //tableau qui va contenir le résultat de chaque temps dexécution
normes = [] //tableau qui va contenir la norme de chaque calcul derreur
decN = [] //tableau qui va contenir les logarithmes décimal de n
decEX = [] //tableau qui va contenir les logarithmes du temps d’exécution

for i=1:6
    n = NN(i);
    A = ones(n, 1)* -1 //vecteur de taille (n,1) composé de -1
    B = ones(n, 1)* 2 //vecteur de taille (n,1) composé de 2
    C = A //vecteur de taille (n,1) composé de -1
    D = ones(n, 1) //vecteur de taille (n,1) composé de 1
    //Ses 4 vecteurs (A,B,C et D) forment la matrice M
    
    timer()    
    X = RESOUTRI(A,B,C,D,n); //on appelle la fonction RESOUTRI
    erreur = PRODUIT(A,B,C,X,n) - D //on résout MX-D
    normes(i) = norm(erreur) //on stocke dans normes le calcul de la norme de l'erreur
    EX(i) = timer() //on stocke dans EX la durée dexécution pour le n actuel
    
    decN(i) = log10(NN(i)); //on stocke dans decN le logarithme décimal de n
    decEX(i) = log10(EX(i)); //on stocke dans decEX le logarithme du temps d’exécution
end 

disp("/////////////////////////--RESULTATS--////////////////////////////");

disp("Temps exécution: ", EX)
disp("Normes: ", normes)

//graphe: le logarithme décimal du temps d’exécution en fonction du logarithme décimal de n
plot(decN, decEX);

