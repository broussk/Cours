CC = gcc -Wall -O3
OBJECTS = main.o liste.o cellule.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c liste.h
	$(CC) -c main.c

liste.o : liste.c liste.h cellule.h
	$(CC) -c liste.c

cellule.o : cellule.c cellule.h
	$(CC) -c cellule.c

clean : 
	rm main $(OBJECTS)