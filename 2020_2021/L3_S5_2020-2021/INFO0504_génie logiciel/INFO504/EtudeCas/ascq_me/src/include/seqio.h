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
  \file seqio.h
  \author Pierre LAURENCE and David BOENS (2003).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Description of methods allowing the using of FASTA files and other useful things linked to them.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _seqio_h
#define _seqio_h

#include "tables.h"

/*!
  \fn char* getSeq ()
  \brief Function which returns the sequence of the current protein in the FASTA file.
  \result The protein sequence.*/
char* getSeq ();

/*!
  \fn char* get_reversed_sequence()
  \brief Function which returns the reverse of the current protein sequence.
  \result The protein sequence reversed.*/
char* get_reversed_sequence();

/*!
  \fn char* getDesc ()
  \brief Function which returns the description of the current protein in the FASTA file.
  \result The description.*/
char *getDesc ();

/*!
  \fn unsigned int is_parsing_started()
  \brief Function that indicates if the parsing of the database is started or not i.e. nextEntry has been called at least one time.
  \result TRUE or FALSE according to util.h.*/
unsigned int is_parsing_started();

/*! 
  \fn int nextEntry (long* offset)
  \brief Function which allows to move until the next entry.
  \param offset The current position.
  \result int that indicates if the function has worked correctly or not.*/
int nextEntry (long* offset);

/*!
  \fn int getEntry (long* offset);
  \brief Function to position the cursor on the nearest entry from the offset position.
  \param offset The position.
  \result Int that indicates if the function has worked or not.*/
int getEntry (long *offset);

//\fn FILE* fastafopen (const char* filename, long* size);
//  \result The FILE* on the file opened.

/*!
  \fn void fastafopen (const char* filename, long* size);
  \brief Function which opens a FASTA file.
  \param filename The name of the file to open.
  \param size The variable what will contain the FASTA file size.*/
void fastafopen (const char* filename, long* size);

/*!
  \fn void fastafwrite (FILE* f, char* desc, char* seq)
  \brief Procedure which writes in a file the description and the sequence of a protein.
  \param f The file where the result will be write.
  \param desc The protein description.
  \param seq The protein sequence.*/
void fastafwrite (FILE * f, char *desc, char *seq);

/*!
  \fn void fastafwrite_way (FILE * f, char *desc, char *seq, int way)
  \brief Procedure which writes in a file the description and the sequence of a protein in a reading phase particulary.
  \param f The file where the result will be written.
  \param desc The protein description.
  \param seq The protein sequence.
  \param way The way to make the translation.*/
void fastafwrite_way (FILE * f, char *desc, char *seq, int way);

//\fn int fastafclose ()
//\result Int that indicates if the function has worked or not.
/*!
  \fn void fastafclose ()
  \brief Function to close the FASTA file currently opened.*/
  
void fastafclose ();

/*!
  \fn void set_specie(const char* wanted_specie)
  \brief Procedure which allows to specifie the wanted specie to study.
  \param wanted_specie The wanted specie.
  \warning This call will be refused if a fasta file is already opened.*/
void set_specie(const char* wanted_specie);

/*!
  \fn char* get_specie()
  \brief Function which allows to get the current specie wanted from the fasta file.
  \result The current specie.*/
char* get_specie();

/*!
  \fn int is_a_wanted_protein()
  \brief Function which indicates if the current protein is wanted or not.
  \result TRUE or FALSE (according to util.h).*/
int is_a_wanted_protein();

/*!
  \fn char* get_fasta_filename()
  \brief Function which allows to get the name of the opened file.
  \result The name of opened fasta file.*/
char* get_fasta_filename();

/*!
  \fn void set_exp_protein_mass(double mass)
  \brief Procedure to set a for the experimental protein mass.
  \param mass The weight.
  \warning The mass tolerance is by defaut 10%.*/
void set_exp_protein_mass(double mass);

/*!
  \fn int is_exp_protein_mass_activated()
  \brief Function which allows to know if a experimental protein mass has been already set.
  \result TRUE or FALSE (according to util.h).*/
int is_exp_protein_mass_activated();

/*!
  \fn double get_exp_protein_mass()
  \brief Function which allows to get the mass given for the protein mass.
  \result The mass.*/
double get_exp_protein_mass();

#endif
