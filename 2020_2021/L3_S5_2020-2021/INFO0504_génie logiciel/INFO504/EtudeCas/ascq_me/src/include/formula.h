/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s): 
     Jean-Charles BOISSON
     Nicolas DOLET
     Nicolas GRUSZCZYNSKA
     
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
  \file formula.h
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Definition of a chemical formula.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _formula_h
#define _formula_h

#include "util.h"

/*!
  \struct isotop
  \brief An isotopic structure represents the isotop of an element.
 */
typedef struct isotop
{
  //! The relative mass
  double relative_mass;
  //! The isotopic composition 
  double isotopic_composition;
}
isotop_t;


/*!
  \struct element
  \brief Structure representing an element in the NIST table
 */
typedef struct element
{
  //! The symbol of the element, for example: C.
  char symbol[3];
  //! The number of isotops.
  int nb_isotops;
  //! The isotops.
  isotop_t *isotops; 
}
element_t;

/*!
  \struct composition
  \brief Structure representing an element with its quantity, for example: C2
*/
typedef struct composition
{
  //! The element.
  element_t *element;
  //! The element quantity.
  int quantity;
}
composition_t;

/*!
  \struct formula
  \brief Structure representing a formula made of compositions, for example : C2H4.
*/
typedef struct formula
{
  //! The number of distinct compositions (ie elements).
  int nb_comp;
  //! The compositions.
  composition_t *comps;
}
formula_t;

/*!
  \fn element_t *get_element_table(const char* filename,int* nb_elements)
  \brief Function that initializes and returns the isotopic distribution element table stored in a file.
  \param filename The file which contains the isotopic districution.
  \param nb_elements The number of elements in the table.
  \result the first element_t structure*/
element_t *get_element_table(const char* filename,int* nb_elements);

/*!
  \fn formula_t *read_formula(const char *c,element_t *elem_table,int elem_table_size)
  \brief Allocate and read a formula from a string.
  \param c The string containing formula : CH3...
  \param elem_table The element table.
  \param elem_table_size The number of elements in the table.
  \result the read formula_t structure.*/
formula_t *read_formula(const char* c,element_t* elem_table,int elem_table_size);

/*!
  \fn void add_formula(formula_t* dest,formula_t* src)
  \brief Add two formula.
  \param dest The first formula before/after the addition.
  \param src The second formula.*/
void add_formula(formula_t* dest,formula_t* src);

/*!
  \fn int sub_formula(formula_t *dest,formula_t *src)
  \brief Substrate two formula.
  \param dest The first formula before/after the substraction.
  \param src The second formula.
  \result 1 if possible, 0 else.*/
int sub_formula(formula_t* dest,formula_t* src);

/*!
  \fn element_t *get_element(char *sym,element_t *elem_table,int elem_table_size)
  \brief Returns an element for element table.
  \param sym The atom symbol.
  \param elem_table The element table.
  \param elem_table_size The number of elements in the table.
  \result the element_t structure corresponding to sym*/
element_t *get_element(char* sym,element_t* elem_table,int elem_table_size);

/*!
  \fn char *formula_tochar(formula_t *f)
  \brief Returns a string representing a formula.
  \param f The formula.
  \result The string corresponding to f.*/
char *formula_tochar(formula_t* f);

/*!
  \fn void free_element_table(element_t *e,int tsize)
  \brief Free the memory allocated for the element table.
  \param e The element table table.
  \param tsize the size of e*/
void free_element_table(element_t* e,int tsize);

/*!
  \fn void free_formula(formula_t *f)
  \brief Free the memory allocated for a formula
  \param f The formula.*/
void free_formula(formula_t *f);

/*!
  \fn void free_composition(composition_t* composition, int number)
  \brief Procedure which frees the memory allocated for a composition.
  \param composition The composition to free
  \param number The number of element*/
void free_composition(composition_t* composition, int number);

/*!
  \fn void free_n_formula(formula_t* formula,int number)
  \brief Free the memory for n formula.
  \param formula The formulae.
  \param number The number of formulae.*/
void free_n_formula(formula_t* formula,int number);

/*!
  \fn double get_weight(formula_t *f)
  \brief Get the weight of a formula.
  \param f The formula from which we want the weight.
  \result The wanted weight.*/
double get_weight(formula_t *f);

/*!
  \fn formula_t* copy_formula(formula_t* formula)
  \brief Get the copy of a formula.
  \param formula The original formula.
  \result the copy.*/
formula_t* copy_formula(formula_t* formula);

/*!
  \fn composition_t* copy_composition(composition_t* composition,int number)
  \brief Get the copy of a composition.
  \param composition The original composition.
  \param number The number of elements.
  \result The copy.*/
composition_t* copy_composition(composition_t* composition,int number);

/*!
  \fn void print_formula(formula_t* formula, int number)
  \brief Print the formula on the screen.
  \param formula The formula we want to print.
  \param number Their number.*/
void print_formula(formula_t* formula, int number);

/*!
  \fn void fprint_formula(FILE* file,formula_t* formula, int number)
  \brief Print the formula in a file.
  \param file The file.
  \param formula The formula we want to print.
  \param number The number of formula.
*/
void fprint_formula(FILE* file,formula_t* formula, int number);

/*!
  \fn void print_element_table(element_t* element_table, int size)
  \brief Print the element table on the screen.
  \param element_table The element table.
  \param size the size of the element table.*/
void print_element_table(element_t* element_table, int size);

/*!
  \fn void fprint_element_table(FILE* file,element_t* element_table, int size)
  \brief Print the element table in a file.
  \param file the file.
  \param element_table The element table.
  \param size The size of the element table.*/
void fprint_element_table(FILE* file,element_t* element_table, int size);
 
#endif
