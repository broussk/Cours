/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s): 
     Jean-Charles BOISSON
     Pierre LAURENCE
     David BOENS
     

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
  \file cleavage.h
  \author Pierre LAURENCE and David BOENS (2003).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Description of methods allowing to know where enzymes can cut proteins.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _cleavage_h
#define _cleavage_h

#include "util.h"

/*! 
  \def N_SIDE
  \brief Correspond to the N-terminal side.*/
#define N_SIDE 0

/*! 
  \def C_SIDE
  \brief Correspond to the C-terminal side.*/
#define C_SIDE 1

/*!
  \struct cleavePoint
  \brief Structure representing a cleavage point.
 */
typedef struct cleavePoint
{
  //! The letter on which we can cut (before or after).
  char letter;
  //! The number of different letters that cannot be before the cleavage-letter.
  int nbexceptbefore; 
  //! The letters which cannot be before the cleavage-letter.
  char *exceptbefore;
  //! The number of different letters than cannot be after the cleavage-letter.
  int nbexceptafter;
  //! The letters which cannot be after the cleavage-letter.
  char *exceptafter;
}
cp_t;

/*!
  \struct cleavePointList
  \brief Structure representing a list of cleavage point <=> cleavage rules.
 */
typedef struct cleavePointList
{
  //! The rules number.
  int size;
  //! The different rules.
  cp_t *cp;
}
cpl_t;

/*!
  \struct enzyme
  \brief Structure that represents an enzyme.
 */
typedef struct enzyme
{
  //! The enzyme name.
  char * name;
  //! The cut side of the enzyme (N-terminal or C-terminal).
  int side;
  //! The cleavage rules.
  cpl_t * cpl;
}
enz_t;

/*!
  \struct enzyme_list
  \brief Structure that represents an enzyme list.*/
typedef struct enzyme_list
{
  //! The list size.
  int size;
  //! The enzyme list
  enz_t * enz;
}
enztable_t;

/*!
  \fn cpl_t* stringToCpl (char* s)
  \brief Function which translates according to a grammar a character a sequence into a complete cleavage rule.
  \param s a correct character chain according to the grammar.
  \result The complete cleavage rule.*/
cpl_t *stringToCpl (char *s);

/*!
  \fn int cpl_isCleavage (cpl_t * cpl, char c)
  \brief Function which indicates if letter can be a cleveage point according to the cleavage rules.
  \param cpl The rules.
  \param c The considered letter.
  \result TRUE or FALSE (see util.h).*/
int cpl_isCleavage (cpl_t * cpl, char c);

/*!
  \fn int cpl_isCleavage2 (cpl_t * cpl, char cprev, char c, char cnext)
  \brief Function which indicates if we are in a good cleavage situation according to the cleavage rules.
  \param cpl The rules.
  \param cprev The letter(s) before the current one.
  \param c The current letter.
  \param cnext The letter(s) after the current one.
  \result TRUE or FALSE (see util.h).*/
int cpl_isCleavage2 (cpl_t * cpl, char cprev, char c, char cnext);

/*!
  \fn void cpl_fprint (FILE * f, cpl_t * cpl)
  \brief Procedure which prints the rules in a file in an understanding style.
  \param f The file in which we want to print the rules.
  \param cpl The rules.*/
void cpl_fprint (FILE * f, cpl_t * cpl);

/*!
  \fn enztable_t * enzym_load(const char * fileToLoad)
  \brief Procedure which initialized the enztable_t structure from a file
  \param fileToLoad The file used to make the initialisation.
  \result The enzyme table.*/
enztable_t * enzym_load(const char * fileToLoad);

/*!
  \fn int get_enzyme_number(char * enztofind, enztable_t *enzt)
  \brief Function which returns the place of an enzym in the enzyme list.
  \param enztofind The enzym we want to find.
  \param enzt The enzyme table.
  \result The place of the enzyme in the enzyme list.*/
int get_enzyme_number(char * enztofind, enztable_t *enzt);

/*!
  \fn void print_enzyme_table(enztable_t *enzt)
  \brief Procedure which prints the enzyme table on the screen.
  \param enzt The enzyme table.*/
void print_enzyme_table(enztable_t *enzt);

/*!
  \fn void free_cpt(cp_t* cpt)
  \brief Procedure which frees the content of a cpt structure.
  \param cpt The cpt structure we want to free.*/
void free_cpt(cp_t* cpt);

/*!
  \fn void free_cplt(cpl_t* cplt)
  \brief Procedure which frees the content of a cplt structure.
  \param cplt The cplt structure we want to free.*/
void free_cplt(cpl_t* cplt);
  
/*!
  \fn void free_enzt(enz_t* enzt)
  \brief Procedure which frees the content of a enzt structure.
  \param enzt The enzyme table we want to free.*/
void free_enzt(enz_t* enzt);

/*!
  \fn void free_enzym_table(enztable_t* enzyme_table)
  \brief Procedure which frees an enzyme table.
  \param enzyme_table The enzym table to free.*/
void free_enzym_table(enztable_t* enzyme_table);
#endif
