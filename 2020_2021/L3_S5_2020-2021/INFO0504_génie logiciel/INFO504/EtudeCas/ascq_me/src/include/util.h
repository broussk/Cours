/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s): 
     Jean-Charles BOISSON
     
  Contact: Ascq-me-help@lists.gforge.inria.fr
  
  This software is a computer program whose purpose is to identify proteins
  by peptide mass fingerprinting. Its scoring is based on spectral correlation
  between an experimental MS spectrum and theoretical MS spectra. The experimental
  spectrum is a mass spectrum without mono isotopic mass extraction. Theoretical
  spectra are generated from proteins in FASTA format thanks to an algorithm
  based on Fast Fourier Transform.
  
  This software is governed by the CeCILL-C license under French law and
  abiding by the rules of distribution of free software.  You can  use, 
  modify and/ or redistribute the software under the terms of the CeCILL-C
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info". 
  
  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability. 
  
  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or 
  data to be ensured and,  more generally, to use and operate it in the 
  same conditions as regards security. 
  
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-C license and that you accept its terms.
*/

/*! 
  \file util.h
  \author Jean-Charles BOISSON (2006-2008)
  \brief Definition of several useful things.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _util_h
#define _util_h

#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "error.h"

/*! 
  \def TRUE
  \brief Value in order to have an equivalent to the boolean true (the code is originaly in C).
*/
#define TRUE 1

/*! 
  \def FALSE
  \brief Value in order to have an equivalent to the boolean false (the code is originaly in C).
*/
#define FALSE 0

/*! 
  \def EOL(c)
  \brief Allows to indicate if a character is an EOF, the end of a char* or an end of line.
  This definition has been kept from the ASCQ-Prot software.
*/
#define EOL(c) (((c) == EOF)||((c) == '\0')||((c) == '\n'))

/*! 
  \def SEPARATOR(c)
  \brief Allows to indicate if a character can be equivalent to a field separator.
  This definition has been also kept from the ASCQ-Prot software.
*/
#define SEPARATOR(c) (((c) == ' ')||((c) == '\t')||(EOL(c)))

/*!
  \fn int jump_commentaries(FILE* file,char commentary)
  \brief Function which allows to jump commentaries in a file.
  \param file The file to read.
  \param commentary The character designing a line as a commentary.
  \result The result of the command fscanf <=> number of characters read on the last called or EOF.
  
  NB: a commentary is a line beginning by a special character or an empty line beginning by ' '.*/
int jump_commentaries(FILE* file,char commentary);

/*!
  \fn int jump_a_line(FILE* file)
  \brief Function which allows to jump a line from a file.
  \param file The file to read.
  \result The result of the command fscanf <=> number of characters read on the last called or EOF.*/
int jump_a_line(FILE* file);

/*!
  \fn char* read_line(FILE* file)
  \brief Function which allows to read a line and put it in a char*.
  \param file The file opened on the line to read.
  \result The char* read.*/
char* read_line(FILE* file);

/*!
  \fn char* read_until(FILE* file,char separator)
  \brief Function which allows to read a char* until a special separator, EOF or the end of the line.
  \param file The file where the char* has to be read.
  \param separator The separator.
  \result the char* read.*/
char* read_until(FILE* file,char separator);

/*!
  \fn int jump_blanks(FILE* file)
  \brief Function which allows to not take the blanks of a file.
  \param file The file where we want to avoid the blanks.
  \result The result of the command fscanf <=> number of characters read on the last called or EOF.*/
int jump_blanks(FILE* file);

/*!
  \fn void delete_final_blanks(char* buffer)
  \brief Procedure which deletes all the final blanks of a char*.
  \param buffer The char* to process.*/
void delete_final_blanks(char* buffer); 

/*!
  \fn void activate_verbose_mode()
  \brief Procedure which activates the verbose mode.*/
void activate_verbose_mode();

/*!
  \fn int is_verbose_mode_activated()
  \brief Function which indicates if the verbose mode is activated.
  \result TRUE or FALSE.*/
int is_verbose_mode_activated();

/*!
  \fn char* add_chains(const char* first, const char* second)
  \brief Function which allows to append the second char* to the end of the first char*.
  \result The result char*

  This method is equivalent to the C++ method '+' for the strings.*/
char* add_chains(const char* first, const char* second);

/*!
  \fn int equals(double value1, double value2, double delta)
  \brief Tool function which indicates if 2 double are equal or not according to a delta
  \param value1 The first value.
  \param value2 The second value.
  \param delta The delta.
  \result TRUE or FALSE*/
int equals(double value1, double value2, double delta);

/*!
  \fn double* copy_double_array(double* src, int src_size)
  \brief Tool Function which makes the copy of a double array
  \param src The original double array.
  \param src_size The size of the array.
  \result The copie.*/
double* copy_double_array(double* src, int src_size);

/*!
  \fn int compare_doubles(const void* first,const void* second)
  \brief Tool Function which compares two double ==> useful for making qsort.
  \param first The first double.
  \param second The second double.
  \result -1, 0 or 1 according to the first <, = or > second.*/
int compare_doubles(const void* first,const void* second);

#endif
