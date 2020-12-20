CC = gcc -Wall -O3
OBJETS = TestFile.o file.o pile.o cellule.o graphe.o liste.o sommet.o 

TestFile : $(OBJETS)
	$(CC) -o TestFile $(OBJETS)

TestFile.o : TestFile.c
	$(CC) -c TestFile.c

graphe.o : graphe.c graphe.h
	$(CC) -c graphe.c

liste.o : liste.c liste.h cellule.h
	$(CC) -c liste.c 

cellule.o : cellule.c cellule.h
	$(CC) -c cellule.c

file.o : file.c file.h
	$(CC) -c file.c

sommet.o : sommet.c sommet.h
	$(CC) -c sommet.c

pile.o : pile.c pile.h
	$(CC) -c pile.c

clean: 
	rm prog_liste $(OBJETS)