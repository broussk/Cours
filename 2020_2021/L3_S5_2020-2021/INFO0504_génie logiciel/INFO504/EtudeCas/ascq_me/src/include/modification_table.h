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
  \file modification_table.h
  \author Jean-Charles BOISSON (2005-2008)
  \brief Definition of a lot of things to use post-translational modifications.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _modifications_table_h
#define _modifications_table_h

#include "tables.h"

/*! 
  \def MODIFICATION_FILENAME
  \brief Default location of the modification file.*/
#define MODIFICATION_FILENAME "./internal/modification_file"

/*!
  \def C_TERM
  \brief The first type of modification location.

  This type corresponds to modification located on the C-terminal side of a protein or a peptide.*/
#define C_TERM 0

/*!
  \def N_TERM
  \brief The second type of modification location.

  This type corresponds to modification located on the N-terminal side of a protein or a peptide.*/
#define N_TERM 1

/*!
  \def BOTH_TERM
  \brief The third type of modification location.

  This type corresponds to modification located on the N-terminal side or the C-terminal of a protein or a peptide.*/
#define BOTH_TERM 2

/*!
  \def INDEPENDANT_TERM
  \brief The fourth type of modification location.

  This type corresponds to modification located anywhere on a protein or a peptide.*/
#define INDEPENDANT_TERM 3

/*!
  \def PROTEIN
  \brief The fifth type of modification location.

  This type corresponds to modification located anywhere on a protein.*/
#define PROTEIN 4

/*!
  \fn void free_all_modifications()
  \brief Procedure which allows to free the modification formulae.*/
void free_all_modifications();

/*!
  \fn formula_t* get_modification_formula_to_add(int modif)
  \brief Function which returns the formula to add when we want to apply a wanted modification.
  \param modif The wanted modification.
  \result The formula to add to apply the modification.
  \warning This function return directly a pointer on the formula, so do not modify it, 
  if you want this formula and make modification on it, call copy_formula(get_modification_formula_to_add(modif))
  in order to have a copy.*/
formula_t* get_modification_formula_to_add(int modif);

/*!
  \fn formula_t* get_modification_formula_to_sub(int modif)
  \brief Function which returns the formula to sub when we want to apply a wanted modification.
  \param modif The wanted modification.
  \result The formula to sub to apply the modification.
  \warning This function return directly a pointer on the formula, so do not modify it, 
  if you want this formula and make modification on it, call copy_formula(get_modification_formula_to_sub(modif))
  in order to have a copy.*/
formula_t* get_modification_formula_to_sub(int modif);

/*!
  \fn char* get_modification_symbol(int modif)
  \brief Function which allows to get the corresponding symbol according a wanted modification.
  \param modif The wanted modification.
  \result The corresponding char* */
char* get_modification_symbol(int modif);

/*!
  \fn char* get_modification_amino_acids(int modif)
  \brief Function which allows to return all the amino acids on which this modification can be used.
  \param modif The wanted modification.
  \result The amino acids.*/
char* get_modification_amino_acids(int modif);

/*!
  \fn int get_total_number_of_modifications();
  \brief Function which allows to get the total number of available modifications.
  \result the modification number.*/
int get_total_number_of_modifications();

/*!
  \fn void load_modifications(const char* file)
  \brief Procedure which loads the available modifications from a file.
  \param file The file for the loading.*/
void load_modifications(const char* file);

/*!
  \fn char* get_modification_name(int modif)
  \brief Function which allows to get the complete name of a modification.
  \param modif The wanted modification.
  \result The modification complete name.*/
char* get_modification_name(int modif);

/*!
  \fn int get_modification_side(int modif);
  \brief Function which returns the side corresponding to the modification.
  \param modif The wanted modif.
  \result The corresponding side.*/
int get_modification_side(int modif); 

/*!
  \fn int can_be_used_on(int modif,char amino_acid,int place,int size,int first)
  \brief Function which indicates if the amino acid given can have the indicated modification.
  \param modif The chosen modification.
  \param amino_acid The amino acid
  \param place Its place
  \param size The size of the protein/peptide.
  \param first This parameters indicates if the amino acid is an amino acid of a complete protein or the amino acid of the first peptide.
  \warning The first place <=> N-term, the last <=> C-term.
  \result TRUE or FALSE (see util.h).*/
int can_be_used_on(int modif,char amino_acid,int place,int size,int first);

/*!
  \fn void apply_global_modification(formula_t* formula,int modif)
  \brief Procedure which applies a modification on a formula.
  \param formula The formula to modify.
  \param modif The index of the modif to apply.*/
void apply_global_modification(formula_t* formula,int modif);

#endif
