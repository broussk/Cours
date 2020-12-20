%republicain
republicain(paulRyan).
republicain(kevinMcCarthy).
republicain(mitchMcConnell).

%democrate
democrate(barackObama).
democrate(johnKerry).
democrate(hillaryClinton).

repDemo(X,Y):-republicain(X),democrate(Y).

duoDemo(X,Y):-X\==Y,democrate(X),democrate(Y).