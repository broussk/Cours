:-include('divinites').

divinite_male(X):-divinite(X),male(X).
divinite-femelle(X):-divinite(X),femelle(X).

enfant(X,Y):-fruit_de(X,Y).
enfant(X,Y):-fruit_de(X,Y,_).
enfant(X,Y):-fruit_de(X,_,Y).

pere(X,Y):-enfant(X,Y),male(X).
mere(X,Y):-enfant(X,Y),femelle(Y).

parent(X,Y):-enfant(X,Y).

%grandpere(X,Y):-pere(X,I),pere(I,Y).
%grandpere(X,Y):-pere(X,I),mere(I,Y).

grandpere(X,Y):-pere(X,I),enfant(Y,I).
grandmere(X,Y):-mere(X,I),enfant(Y,I).

frere(X,Y):-male(X),parent(P,X),parent(P,Y),X\=Y,format('~a est le frère de ~a~n',[X,Y]).
soeur(X,Y):-femelle(X),parent(P,X),parent(P,Y),X\=Y,format('~a est la soeur de ~a~n',[X,Y]).

tante(X,Y):-soeur(X,P),parent(P,Y).
oncle(X,Y):-frere(X,P),parent(P,Y).

filsDe(X,Y):-male(X),enfant(X,Y).
filleDe(X,Y):-femelle(X),enfant(X,Y).

cousine(X,Y):-filleDe(X,O),oncle(O,Y).
cousine(X,Y):-filleDe(X,T),tante(T,Y).

ancetre2(X,Y):-parent(X,Y).
ancetre2(X,Y):-parent(A,Y),ancetre2(X,A).

identiques(X,X).
differents(X,Y):-X\=Y.

