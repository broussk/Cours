CC = gcc -Wall -O3
OBJECTS = prog_liste.o graphe.o liste.o cellule.o

prog_liste : $(OBJECTS)
	$(CC) -o prog_liste $(OBJECTS)

prog_liste.o: prog_liste.c liste.h
	$(CC) -c prog_liste.c

graphe.o : graphe.c graphe.h
	$(CC) -c graphe.c

liste.o : liste.c liste.h cellule.h
	$(CC) -c liste.c

cellule.o : cellule.c cellule.h
	$(CC) -c cellule.c

clean : 
	rm prog_liste $(OBJECTS)