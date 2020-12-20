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
  \file modifications_for_digestion.h
  \author Jean-Charles BOISSON (2006-2008).
  \brief Definition of the specifications for the post-translation modifications in the digestion case.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _modifications_for_digestion_h
#define _modifications_for_digestion_h

#include "modification_table.h"

/*!
  \def FIXED
  \brief Definition that corresponds to a fixed modification.*/
#define FIXED 0

/*!
  \def VARIABLE
  \brief Definition that corresponds to a variable modification.*/
#define VARIABLE 1

/*!
  \struct post_translational_modification
  \brief Definition of a post-translationam modification.*/
typedef struct post_traductional_modification
{
  //! The modification type (FIXED or VARIABLE).
  int type;
  //! The associated modification index (see modification_table.h).*/
  int modification;
}
post_translational_modification_t;

/*!
  \fn void print_modification_configuration()
  \brief Procedure which prints the current configuration of activated modifications on the stdout.*/
void print_modification_configuration();

/*!
  \fn void fprint_modification_configuration(FILE* file)
  \brief Procedure which prints the current configuration of activated modifications in a file.
  \param file The file where we want to print the configuration.*/
void fprint_modification_configuration(FILE* file);

/*!
  \fn void fprint_xml_modification_configuration(FILE* file)
  \brief Procedure which prints the current configuration of activated modifications in a file in a XML format.
  \param file The file where we want to print the configuration.*/
void fprint_xml_modification_configuration(FILE* file);

/*!
  \fn void load_modification_configuration(char* configuration)
  \brief Procedure which loads the configuration for the modifications.
  \param configuration The current configuration to load.*/
void load_modification_configuration(char* configuration);

/*!
  \fn void add_modification(int type,int id)
  \brief Procedure which allows to activate a new modification.
  \param type It can be FIXED or VARIABLE.
  \param id The modification index (see modification_table.h).*/
void add_modification(int type,int id);

/*!
  \fn void free_activated_modification()
  \brief Procedure which allows to free all the initialised modifications.*/
void free_activated_modification();

/*!
  \fn int get_number_of_activated_modifications()
  \brief Function which returns the number of activated modifications.
  \result The number of activated modifications.*/
int get_number_of_activated_modifications();

/*!
  \fn int can_be_used_on_for_digestion(int modif,char amino_acid,int place,int size,int first)
  \brief Function which indicates if the given amino acid can have the indicated modification
  \param modif The chosen modification index.
  \param amino_acid An amino acid.
  \param place Its place.
  \param size The size of the protein/peptide.
  \param first The last parameter indicates if the amino acid is the first of the complete protein or the first peptide.
  \warning The first place <=> N-term, the last one <=> C-term.
  \result TRUE or FALSE (see util.h).*/
int can_be_used_on_for_digestion(int modif,char amino_acid,int place,int size,int first);

/*!
  \fn formula_t* get_formula_to_add(int modif)
  \brief Function which returns the formula to add according to the indicated modification.
  \param modif The modification index.
  \result The formula.
  \warning The result can be NULL if no formula is needed to add to apply the modification.*/
formula_t* get_formula_to_add(int modif);

/*!
  \fn formula_t* get_formula_to_sub(int modif)
  \brief Function which returns the formula to sub according the indicated modification.
  \param modif The modification index.
  \result The formula.
  \warning The result can be NULL if no formula is needed to sub to apply the modification.*/
formula_t* get_formula_to_sub(int modif);

/*!
  \fn int get_modification_type(int modif)
  \brief Function which returns the type of modification according the given index.
  \param modif The modification index.
  \result The corresponding type.*/
int get_modification_type(int modif);

/*!
  \fn void apply_modification(formula_t* formula,int modif)
  \brief Procedure which applies a modification on a formula.
  \param formula The formula where the modification have to be applied.
  \param modif The modification index.*/
void apply_modification(formula_t* formula,int modif);

/*!
  \fn char* get_activated_modification_symbol(int modif)
  \brief Function which returns the small name (symbol) of a modification
  \param modif The modification index.*/
char* get_activated_modification_symbol(int modif);

/*!
  \fn char* get_activated_modification_name(int modif)
  \brief Function which returns the full name of a modification.
  \param modif The modification index.*/
char* get_activated_modification_name(int modif);

/*!
  \fn void digestion_modification_initialization(const char* configuration)
  \brief Procedure that allows to initialize all the post translational modifications for the digestion.
  \param configuration The modification configuration.*/
void digestion_modification_initialization(const char* configuration);

/*!
  \fn int get_global_modification_index(int modif)
  \brief Function which returns the global index of the modification.
  \param modif The index for the digestion modification.
  \return The global index in order to use the functions of the modification table.*/
int get_global_modification_index(int modif);

#endif
