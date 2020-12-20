CC = gcc -Wall -O3
OBJECTS = main.o file.o sommet.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c file.h
	$(CC) -c main.c

v.o : file.c file.h sommet.h
	$(CC) -c file.c

sommet.o : sommet.c sommet.h
	$(CC) -c sommet.c

clean : 
	rm main $(OBJECTS)