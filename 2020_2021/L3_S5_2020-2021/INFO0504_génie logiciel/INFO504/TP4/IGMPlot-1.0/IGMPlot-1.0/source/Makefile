#
##Copyright University of Reims Champagne-Ardenne
#Authors: Emmanuel PLUOT, Gaetan RUBEZ, Jean-Charles-BOISSON and Eric HENON
#Contributors: Hassan Khartabil, Corentin Lefebvre, Julia Contreras-Garcia
#(24/07/2017)
#
##jean-charles.boisson@univ-reims.fr, eric.henon@univ-reims.fr
#
##This software is a computer program whose purpose is to 
#detect and prepare the plot of molecular interactions
#from electron density and IGM reference using promolecular
#electron density.
#
##This software is governed by the CeCILL-C license under French law and
#abiding by the rules of distribution of free software.  You can  use, 
#modify and/ or redistribute the software under the terms of the CeCILL-C
#license as circulated by CEA, CNRS and INRIA at the following URL
#"http://www.cecill.info". 
#
##As a counterpart to the access to the source code and  rights to copy,
#modify and redistribute granted by the license, users are provided only
#with a limited warranty  and the software's author,  the holder of the
#economic rights,  and the successive licensors  have only  limited
#liability. 
#
##In this respect, the user's attention is drawn to the risks associated
#with loading,  using,  modifying and/or developing or reproducing the
#software by the user in light of its specific status of free software,
#that may mean  that it is complicated to manipulate,  and  that  also
#therefore means  that it is reserved for developers  and  experienced
#professionals having in-depth computer knowledge. Users are therefore
#encouraged to load and test the software's suitability as regards their
#requirements in conditions enabling the security of their systems and/or 
#data to be ensured and,  more generally, to use and operate it in the 
#same conditions as regards security. 
#
##The fact that you are presently reading this means that you have had
#knowledge of the CeCILL-C license and that you accept its terms.
#
#


CC=g++

CFLAGS=-Werror  -ansi -Wall  -pedantic -std=c++11 -O2 -pg -g
LDFLAGS=-Werror -Wall  -pedantic -std=c++11 -O2 -pg -g

# For compiling with OpenMP (default mode)
#CFLAGS+=-fopenmp
#LDFLAGS+=-fopenmp


# For compiling without OpenMP
CFLAGS+= -DNo_OpenMP

EXEC=igmplot

OBJ = main.o reader.o output.o vmdFileGenerator.o

$(EXEC): $(OBJ)
	-@echo "Linking    $(EXEC)"
	-@$(CC) -o $@ $+ $(LDFLAGS)

%.o: %.cpp %.h
	-@echo "Generating $@"
	-@$(CC) $(CFLAGS) -c $< 

###------------------------------
### Cleaning
###------------------------------------------------------------

clean:
	-@rm -rf $(OBJ)

mrproper: clean clean_doc cleanSource
	-@rm -rf $(EXEC)

cleanSource:
	-@find . \( -name "*~" -o -name "*.old" -o -name "#*" \) -print -exec rm \{\} \;


###------------------------------
### Docs
###------------------------------------------------------------

doc:
	-@mkdir docs
	-@doxygen Doxyfile

clean_doc:
	-@rm -rf docs


.PHONY: clean mrproper cleanSource doc clean_doc
