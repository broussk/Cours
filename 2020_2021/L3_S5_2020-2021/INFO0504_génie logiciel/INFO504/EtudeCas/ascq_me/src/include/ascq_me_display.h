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
  \file ascq_me_display.h
  \author Jean-Charles BOISSON (2006-2008).
  \brief Definition of the methods to use and display ASCQ_ME results.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _ascq_me_display_h
#define _ascq_me_display_h

#include <sstream>

//#include "isodistrib.h"
#include "ascq_me_configuration.h"

/*!
  \fn void init_ascq_me_display()
  \brief Procedure which inits all the useful structure for ASCQ_ME display.*/
void init_ascq_me_display();

/*!
  \fn void add_protein(char* description,char* sequence,complex_t* spectrum,double score)
  \brief Procedure which adds and manages a new saved protein.
  \param description The protein description.
  \param sequence The protein sequence.
  \param spectrum The protein simulated spectrum.
  \param score The protein score.*/
void add_protein(char* description,char* sequence,complex_t* spectrum,double score);

/*!
  \fn void printf_ascq_me_results()
  \brief Procedure which prints on the stdout the ASCQ_ME results.*/
void printf_ascq_me_results();

/*!
  \fn void fprintf_ascq_me_results(FILE* file)
  \brief Procedure which prints in a file the ASCQ_ME results.
  \param file The considered file.*/
void fprintf_ascq_me_results(FILE* file);

/*!
  \fn void ascq_me_cleaning()
  \brief Procedure which frees all the memory allocated for ascq_me (excepted the structures allocated in ascq_me.cpp).*/
void ascq_me_cleaning();

/*!
  \fn void free_ascq_me_display()
  \brief Procedure which frees all the structures useful for the ASCQ_ME display.*/
void free_ascq_me_display();

/*!
  \fn void fprintf_ascq_me_results_table_form(FILE* file)
  \brief Procedure which prints in a file the ASCQ_ME results in order to use them in spreadsheet programs.
  \param file The file where the results will be written.*/
void fprintf_ascq_me_results_table_form(FILE* file);

/*!
  \fn void save_partial_peptide_scoring(double* peptide_scoring,int nb_peptides)
  \brief Procedure which allows to save the partial peptide scoring of the current protein.
  \param peptide_scoring The current peptide scoring.
  \param nb_peptides The peptide number.*/
void save_partial_peptide_scoring(double* peptide_scoring,int nb_peptides);

/*!
  \fn int compare_peptide_scores(const void* first,const void* second)
  \brief Procedure which compares two partial_score ==> useful for qsort
  \param first a void pointer that is in reality a peptide score.
  \param second a void pointer which is also a peptide score.
  \result 1, 0 or -1 <=> the first is inferior,equal or superior to the second.
  \warning It is for a decreasing order.*/
int compare_peptide_scores(const void* first,const void* second);

/*!
  \fn int compare_peptide_score_from_indices(const void* first,const void* second)
  \brief Procedure which compares two partial scores from the score indexes in the current peptide scoring array
  ==> useful for qsort
  \param first a void pointer that is in reality an index to a peptide score.
  \param second a void pointer that is also an index to a peptide score.
  \result 1, 0 or -1 <=> the first is inferior,equal or superior to the second.
  \warning It's for a decreasing order.*/
int compare_peptide_score_from_indices(const void* first,const void* second);

/*!
  \fn void sort_and_init_with_peptide_scoring()
  \brief Procedure which allows to sort the peptides_scoring in a decreasing order and
  initialises the array of peptides sequences.

  qsort is used thanks to the methods compare_peptides_score and compare_peptides_score_from_indices.*/
void sort_and_init_with_peptide_scoring();

/*!
  \fn void fprintf_ascq_me_peptide_scoring(FILE* file)
  \brief Procedure which prints in a file the ASCQ_ME scoring for the peptides of each result protein in order to use them 
  in a spreadsheet program.
  \param file The file where the data will be written.*/
void fprintf_ascq_me_peptide_scoring(FILE* file);

/*!
  \fn void fprintf_ascq_me_results_xml(FILE* file).
  \brief Procedure which prints in a file the ASCQ_ME results in a xml format.
  \param file The file.*/
void fprintf_ascq_me_results_xml(FILE* file);
#endif
