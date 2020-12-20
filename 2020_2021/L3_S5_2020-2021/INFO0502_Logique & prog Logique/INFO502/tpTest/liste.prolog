afficheValeurPaires(L):-L mod 2 =:=0,write(L).

estPasNombre(I,L):-number(L+I).

suite([],_,[]).
suite([X|L1], I, [Y|L2]) :- Y is X+I, suite(L1,I,L2).
% il affiche si la liste 2 est la suite de la liste 1