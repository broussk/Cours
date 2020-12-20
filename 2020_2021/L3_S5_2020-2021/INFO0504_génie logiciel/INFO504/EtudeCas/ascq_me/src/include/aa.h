/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developers: 
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
  \file aa.h
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Definition of an amino acid.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _aa_h
#define _aa_h

#include "formula.h"


//! Structure representing an amino acid.
typedef struct amino_acid_CF
{
  //! The radical formula.
  formula_t *form;
  //! The removing atoms for modifications.
  formula_t *add_modif; 
  //! The added atoms for modifications.
  formula_t *sub_modif;
}
aa_CF_t;

/*!
  \fn void init_peptid_link(element_t *elem_table,int elem_table_size)
  \brief Procedure which initialises the formula of peptid liaison and the util formulae.
  \param elem_table The element table.
  \param elem_table_size The number of elements in the table.*/
void init_peptid_link(element_t* elem_table,int elem_table_size);

/*!
  \fn aa_CF_t *get_amino_acid_table(const char *filename,element_t *elem_table,int elem_table_size)
  \brief Function which initialise and return the amino acid formula table stored in a file.
  \param filename The file which contains the table.
  \param elem_table The element table.
  \param elem_table_size The number of elements in the table.
  \result The first aa_CF_t structure. */
aa_CF_t *get_amino_acid_table(const char* filename,element_t* elem_table,int elem_table_size);

/*!
  \fn void free_amino_acid_table(aa_CF_t *aa_table)
  \brief Procedure which frees the memory allocated for an amino acid table.
  \param aa_table The amino acid table. */
void free_amino_acid_table(aa_CF_t* aa_table);

/*!
  \fn formula_t* get_util_formula(const char* name)
  \brief Function which allows to get a already calculated formula.
  \param name The char* form of the wanted formula.
  \result The wanted forumla.*/
formula_t* get_util_formula(const char* name);

/*!
  \fn void free_peptide_link()
  \brief Procedure which frees the formula of the peptide link and the util formulae.*/
void free_peptide_link();

/*!
  \fn void print_amino_acid_table(aa_CF_t* aa_table)
  \brief Procedure which prints on the screen the amino acid table.
  \param aa_table The amino acid table.*/
void print_amino_acid_table(aa_CF_t* aa_table);

/*!
  \fn void fprint_amino_acid_table(FILE* file,aa_CF_t* aa_table)
  \brief Procedure which prints in a file the amino acid table.
  \param file The file where the amino acid table will be printed.
  \param aa_table The amino acid table to print.*/
void fprint_amino_acid_table(FILE* file,aa_CF_t* aa_table);

/*!
  \fn void set_X(char amino_acid)
  \brief Procedure which allows to set the amino acid that will be used when X is met in a FASTA file.
  \param amino_acid The amino acid corresponding to X.*/
void set_X(char amino_acid);

/*!
  \fn void set_Z(char amino_acid)
  \brief Procedure which allows to set the amino acid that will be used when Z is met in a FASTA file.
  \param amino_acid The amino acid corresponding to Z.*/
void set_Z(char amino_acid);

/*!
  \fn void set_B(char amino_acid)
  \brief Procedure which allows to set the amino acid that will be used when B is met in a FASTA file.
  \param amino_acid The amino acid corresponding to B.*/
void set_B(char amino_acid);

/*!
  \fn char get_X()
  \brief Function which allows to access to the amino acid used for X.
  \result The used amino acid used.*/
char get_X();

/*!
  \fn char get_Z()
  \brief Function which allows to access to the amino acid used for Z.
  \result The used amino acid used.*/
char get_Z();

/*!
  \fn char get_B()
  \brief Function which allows to access to the amino acid used for B.
  \result The used amino acid used.*/
char get_B();
#endif
