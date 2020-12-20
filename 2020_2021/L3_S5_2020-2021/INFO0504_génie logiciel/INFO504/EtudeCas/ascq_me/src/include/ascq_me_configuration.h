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
  \file ascq_me_configuration.h
  \author Jean-Charles BOISSON (2005-2008).
  \brief Definition of the useful things to configure ASCQ_ME.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _ascq_me_configuration_h
#define _ascq_me_configuration_h

//#include "ascq_me_display.h"
#include "isodistrib.h"

/*!
  \fn char* get_configuration_file_name()
  \brief Function which returns the name of the configuration file used.
  \return The configuration file name.*/
char* get_configuration_file_name();

/*!
  \fn void load_configuration(char* configuration_file)
  \brief Procedure which allows to load the wanted configuration <=> set all the parameters of the application.
  \param configuration_file The configuration file.*/
void load_configuration(char* configuration_file);

/*!
  \fn int get_nb_displayed_proteins()
  \brief Function which returns the number of displayed proteins.
  \result The number.*/
int get_nb_displayed_proteins();


/*!
  \fn void ascq_me_configuration_cleaning()
  \brief Procedure which frees all the memory allocated for ascq_me configuration.*/
void ascq_me_configuration_cleaning();


/*!
  \fn int is_fasta_chosen()
  \brief Function which indicates if the chosen file type is fasta or spectra.
  \result TRUE or FALSE (see util.h).*/
int is_fasta_chosen();

/*!
  \fn void print_configuration()
  \brief Procedure which allows to print the current configuration on the stdout.*/
void print_configuration();

/*!
  \fn void fprint_configuration(FILE* file)
  \brief Procedure which allows to print the current configuration in a file.
  \param file The file where the current will be put.*/
void fprint_configuration(FILE* file);

/*!
  \fn void fprint_configuration_xml(FILE* file)
  \brief Procedure which allows to print in a xml format the current configuration in a file.
  \param file The file where the current configuration in a xml format will be put.*/
void fprint_configuration_xml(FILE* file);

/*!
  \fn void activate_decoy_mode()
  \brief Procedure which allows to activate the decoy mode.*/
void activate_decoy_mode();

/*!
  \fn int is_decoy_mode_activated()
  \brief Function which allows to know if the decoy mode has been activated or not.
  \result TRUE or FALSE (according to util.h).*/
int is_decoy_mode_activated();

/*!
  \fn void set_decoy_score(double score)
  \brief Procedure which allows to set the decoy_score.
  \param score The decoy score.*/
void set_decoy_score(double score);

/*!
  \fn double get_decoy_score()
  \brief Function which allows to get the decoy score.
  \return The decoy score.*/
double get_decoy_score();

/*!
  \fn char* get_base_name()
  \brief Function which allows to get the base name of the result file of ASCQ_ME.
  \result The base name.
  \warning This function directly returns a pointer (not a copy), do not modified it*/
const char* get_base_name();

#endif
