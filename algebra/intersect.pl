less(X,Y) :- X<Y.
less_equal(X,Y) :- X=<Y.
greater(X,Y) :- X>Y.
greater_equal(X,Y) :- X>=Y.

fullless(X,Y,X):-less(X,Y).
fullless(X,Y,Y):-less(Y,X).

intersectLeft(Al,Ad,Au,Bl,Br,Bd,Bu):-
    greater_equal(Al,Bl),
    less_equal(Al,Br),
    greater(Ad,Bu),
    less(Au,Bd).

intersectRight(Ar,Ad,Au,Bl,Br,Bd,Bu):-
    greater_equal(Ar,Bl),
    less_equal(Ar,Br),
    greater(Ad,Bu),
    less(Au,Bd).

intersectUp(Al,Ar,Au,Bl,Br,Bd,Bu):-
    greater_equal(Au,Bu),
    less_equal(Au,Bd),
    greater(Ar,Bl),
    less(Al,Br).

intersectDown(Al,Ar,Ad,Bl,Br,Bd,Bu):-
    greater_equal(Ad,Bu),
    less_equal(Ad,Bd),
    greater(Ar,Bl),
    less(Al,Br).

inter(_):- true.
