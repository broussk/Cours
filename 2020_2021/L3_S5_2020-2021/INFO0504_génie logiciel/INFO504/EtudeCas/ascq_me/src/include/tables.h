/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s) : 
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
  \file tables.h
  \author Jean-Charles BOISSON (2005-2008).
  \brief Description of methods that allows to manipulate amino acids easier.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _tables_h
#define _tables_h

#include "aa.h"

/*! 
  \def ELEMENT_TABLE
  \brief Default location of the element table.*/
#define ELEMENT_TABLE "./internal/atom_weight.a_prot.txt"

/*! 
  \def AMINO_ACID_TABLE
  \brief Default location of the amino acid table.*/
#define AMINO_ACID_TABLE "./internal/aaisotable"

/*! 
  \def AMINO_ACID_NUMBER
  \brief Number of existing amino acid.*/
#define AMINO_ACID_NUMBER 22

/*!
  \fn void tables_initialisation()
  \brief Procedure which initialises all the useful data : element table, amino acid table, ...*/
void tables_initialisation();

/*!
  \fn void free_tables()
  \brief Procedure which frees the memory allocated for all the useful data : element table, amino acid table ,...*/
void free_tables();

/*!
  \fn element_t* get_element_table()
  \brief Function which allows to get the element table.
  \result The element table.*/
element_t* get_element_table();

/*!
  \fn int get_element_table_size()
  \brief Function which returns the size of the element table.
  \result The element table size.*/
int get_element_table_size();

/*!
  \fn aa_CF_t get_amino_acid(char aa)
  \brief Function which returns the amino acid structure associated to a given char.
  \param aa The char which corresponding to an amino acid.
  \result The amino acid structure associated (aa_CF_t).*/
aa_CF_t get_amino_acid(char aa);

/*!
  \fn aa_CF_t* get_amino_acid_table()
  \brief Function which allows to get the amino acid table.
  \result The amino acid table.*/
aa_CF_t* get_amino_acid_table();

/*!
  \fn formula_t* get_formula_from_sequence(char* sequence)
  \brief Function which allows to get the formula of the proteic sequence given.
  \result The formula.*/
formula_t* get_formula_from_sequence(char* sequence);

/*!
  \fn char get_amino_acid_at_index(int index)
  \brief Function wich returns the amino acid structure associated to an index, it uses the array that contains the amino acids in an increasing order (according to the mass).
  \param index The index.
  \return a char representing an amino acid.*/
char get_amino_acid_at_index(int index);

#endif
