#Makefile by J.C. BOISSON (2005)

CC = g++
#CC = icpc
CFLAGS = -W -Wall -Werror -ansi -pedantic
CFLAGS += -g
#CFLAGS += -O5
CFLAGS += -pg
SRCDIR = ./src/
INCDIR = -I $(SRCDIR)include/
OBJECTS = seqio.o digest.o cleavage.o error.o ascq_me_display.o ascq_me_configuration.o util.o 
OBJECTS += aa.o formula.o tables.o
OBJECTS += isodistrib.o complex.o fft4g.o
OBJECTS += modification_table.o modifications_for_digestion.o
RESULTS += *_ascq_me_*.txt *_ascq_me_*.xml

###------------------------------
### Main targets 
###------------------------------------------------------------
BINARIES= ascq_me

all: $(BINARIES) 

###------------------------------
### Main rules 
###------------------------------------------------------------

%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -c $< $(INCDIR)

ascq_me: ascq_me.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $+

###------------------------------
### Docs
###------------------------------------------------------------

doc:
	-@mkdir docs
	-@doxygen Doxyfile

clean_doc:
	-@rm -rf docs

###------------------------------
### Misc.
###------------------------------------------------------------
clean_all: clean_doc clean

clean: clean_aux cleanSource 
	$(RM) *.o $(BINARIES) $(RESULTS)

clean_aux:
	$(RM) $(RESULTS)

cleanSource:
	-find . \( -name "*~" -o -name "*.old" -o -name "#*" \) -print -exec rm \{\} \;

.PHONY: docs clean_all clean clean_aux ascq_me clean_doc
