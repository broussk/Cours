principal : main.o fct1.o fct2.o fcts.o
	@echo creation :
	gcc -o principal main.o fct1.o fct2.o fcts.o
	@echo --------------------------------

main.o : main.c fct1.c fct2.c fcts.c
	@echo creation de main.o :
	gcc main.c
	@echo --------------------------------

fct1.o : fct1.c fct1.h
	@echo creation de fct1.o : 
	gcc ftc1.c
	@echo --------------------------------

fct2.o : fct2.c fct2.h fcts.o
	@echo creation de fct2.o :
	gcc fct2.c
	@echo --------------------------------

fcts.o : fcts.o fcts.h 
	@echo creation de fcts.o :
	gcc fcts.c
	@echo --------------------------------