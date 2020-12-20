CC = gcc -Wall -O3
OBJECTS = prog_file.o File.o Sommet.o

prog_file : $(OBJECTS)
	$(CC) -o prog_file $(OBJECTS)

prog_file.o: prog_file.c File.h
	$(CC) -c prog_file.c

v.o : File.c File.h Sommet.h
	$(CC) -c File.c

Sommet.o : Sommet.c Sommet.h
	$(CC) -c Sommet.c

clean : 
	rm prog_file $(OBJECTS)