sommeImpair(N,R):-number(N),number(R).

somme([],0).
somme([X|L],R):-somme(L,S),R is S+X.

somme2([],0).
somme2([X|L],R):-X mod 2=:=1,somme2(L,S),R is S+X.
somme2([X|L],R):-X mod 2=:=0,somme2(L,s),R is S.

base5(N):-number(N),
    \+(N mod 5=:=0),X is N div 5,write(X),N is X,base5(N);
    X is N mod 5,write(X).
