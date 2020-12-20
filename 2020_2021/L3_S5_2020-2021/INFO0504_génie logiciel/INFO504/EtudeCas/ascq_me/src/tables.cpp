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
  \file tables.cpp
  \author Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in tables.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "tables.h"

/*! 
  \var element_t* element_table
  \brief Variable that corresponds to the table which will contain all the chemical elements.*/
element_t* element_table=NULL;

/*! 
  \var int nb_elements
  \brief Variable that corresponds to the total number of chemical elements.*/
int nb_elements=0;

/*! 
  \var aa_CF_t* amino_acid_table
  \brief Variable that corresponds to the table which will contain all the amino acid formulae.*/
aa_CF_t* amino_acid_table=NULL;

char sorted_amino_acid_table[] = {'G','A','S','P','V','T','C','I','L','N','D','Q','K','E','M','H','U','F','R','Y','W', 'O'};

void
tables_initialisation()
{
  element_table=get_element_table(ELEMENT_TABLE,&nb_elements);
  amino_acid_table=get_amino_acid_table(AMINO_ACID_TABLE,element_table,nb_elements);
  init_peptid_link(get_element_table(),get_element_table_size());
}

void 
free_tables()
{
  free_element_table(element_table,nb_elements);
  free_amino_acid_table(amino_acid_table);
  free_peptide_link();
}

element_t*
get_element_table()
{
  return element_table;
}

int 
get_element_table_size()
{
  return nb_elements;
}

aa_CF_t 
get_amino_acid(char aa)
{
  aa_CF_t amino_acid;
  aa=toupper(aa);
  if((aa<'A')||(aa>'Z'))
    {
      error(USAGE_ERROR,"THE USED AMINO ACID IS NOT CORRECT",
	    "THE AMINO ACID IS NOT IN [A-Z] IN GET_AMINO_ACID IN TABLES.CPP");
    }
  amino_acid=amino_acid_table[aa-'A'];
  if(amino_acid.form==NULL)
    {
      printf("Wanted amino acid = %c\n",aa);
      error(EXECUTION_ERROR,"THE WANTED AMINO ACID HAS NO ASSOCIATED FORMULA",
	    "THE FORMULA ASSOCIATED TO THE WANTED AMINO ACID IS NULL IN GET_AMINO_ACID IN TABLES.CPP");
    }
  return amino_acid;
}

aa_CF_t*
get_amino_acid_table()
{
  return amino_acid_table;
}

formula_t*
get_formula_from_sequence(char* sequence)
{
  formula_t* formula;
  int size,i;
  aa_CF_t aa;

  if(sequence==NULL)
    {
      error(USAGE_ERROR,"THE INDICATED IS EMPTY, NO FORMULA AVAILABLE",
	    "SEQUENCE IS NULL IN GET_FORMULA_FROM_SEQUENCE IN TABLES.CPP");
    }

  size=strlen(sequence);
  formula=copy_formula(get_util_formula("H"));
  for(i=0;i<size;i++)
    {
      aa=get_amino_acid(sequence[i]);
      add_formula(formula,aa.form);
      add_formula(formula,get_util_formula("NHCHCO"));
    }
  add_formula(formula,get_util_formula("OH"));
  return formula;
}

char
get_amino_acid_at_index(int index)
{
  return sorted_amino_acid_table[index];
}
