//DUPONT Corentin & LACROIX Owen S4F3B
//File "exo2_q1_script", v.2/03/2021

//Importation du fichier contenant les fonctions
pathname = get_absolute_file_path("exo2_q1_script.sce");
exec(pathname+'\functions.sci', -1);

//Vide la console
clc;

//Génére 2000 points comprit entre 0 et 1 
t = linspace(0,1,2000);

//On affiche le tracé des fonction ua(t) et ub(t). 
plot(t, ua(t), 'b'); //=> en bleu
plot(t, ub(t), 'r'); //=> en rouge


 
