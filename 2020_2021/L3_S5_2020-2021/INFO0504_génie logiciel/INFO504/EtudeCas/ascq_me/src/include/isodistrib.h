/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s): 
     Jean-Charles BOISSON
     Nicolas DOLET
     Nicolas GRUSZCZYNSKA
     Christian ROLANDO
     
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
  \file isodistrib.h
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON and Christian ROLANDO (2005-2008).
  \brief Definition of the methods to make simulated spectrum computation.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _ISODISTRIB
#define _ISODISTRIB
 
#include "complex.h"
#include "digest.h"
#include "seqio.h"
//#include "ascq_me_configuration.h"

/*!
  \fn void init_distrib()
  \brief Procedure which initializes the parameters and allocates the useful structures.*/
void init_distrib();

/*!
  \fn void element_convolution(composition_t *comp)
  \brief Procedure which makes the convolution for one atom.
  \param comp The composition containing the atom and its quantity.*/
void element_convolution(composition_t *comp);

/*!
  \fn double optimized_isotopic_distribution(formula_t *peptides,int nb_peptides)
  \brief Function which calculates the isotopic distribution of a peptide list.
  \param peptides The peptide list.
  \param nb_peptides The peptide number.
  \return The total score of the protein corresponding to the peptide list.*/
double optimized_isotopic_distribution(formula_t *peptides,int nb_peptides);

/*!
  \fn void free_isodistrib();
  \brief Procedure which frees the memory allocated for all the structures useful for the isotopic distribution computation.*/
void free_isodistrib();

/*!
  \fn void integral_normalization(double integral_value,int size,complex_t* t_complex)
  \brief Procedure which makes a normalization of a data array.
  \param integral_value The used integral value.
  \param size The t_complex structure size.
  \param t_complex The data to normalize.*/
void integral_normalization(double integral_value,int size,complex_t* t_complex);

/*!
  \fn void write_spectrum(FILE* f,complex_t* t_complex,char* entry)
  \brief Procedure which writes a spectrum in a file.
  \param f The file where the spectrum will be write.
  \param t_complex The spectrum to save.
  \param entry The spectrum name.*/
void write_spectrum(FILE* f,complex_t* t_complex,char* entry);

/*!
  \fn void read_spectrum(const char* spectrum_file)
  \brief Procedure which loads a spectrum from a file.
  \param spectrum_file The spectrum file.*/
void read_spectrum(const char* spectrum_file);

/*!
  \fn complex_t* get_exp_spectrum()
  \brief Function which allows to gain access to the experimental spectrum.
  \result The experimental spectrum.*/
complex_t* get_exp_spectrum();

/*!
  \fn complex_t* get_theo_spectrum()
  \brief Function which allows to gain access to the simulated spectrum.
  \result The theoretical spectrum.*/
complex_t* get_theo_spectrum();

/*!
  \fn complex_t* copy_spectrum(complex_t* spectrum)
  \brief Function which makes the copie of a spectrum.
  \param spectrum The spectrum to copy.
  \result The copie.*/
complex_t* copy_spectrum(complex_t* spectrum);

/*!
  \fn void set_exp_spectrum(complex_t* spectrum)
  \brief Procedure which allows to set manually the experimental spectrum.
  \param spectrum The experimental spectrum.*/
void set_exp_spectrum(complex_t* spectrum);

/*!
  \fn void write_spectrum_peak_only(FILE* file, complex_t* spectrum, char* name)
  \brief Procedure which writes only the spectrum peaks in a file.
  \param file The file where the spectrum will be save.
  \param spectrum The spectrum.
  \param name The spectrum name.*/
void write_spectrum_peak_only(FILE* file, complex_t* spectrum, char* name);
  
/*!
  \fn void read_simulated_spectrum(const char* spectrum_file)
  \brief Procedure which allows to open the file which contains theoretical spectra.
  \warning This procedure opens only the file and don't load any data.
  \param spectrum_file The name of the file which contains simulated spectra.*/
void read_simulated_spectrum(const char* spectrum_file);

/*!
  \fn int next_simulated_spectrum()
  \brief Function which loads the next simulated spectrum.
  \warning This function must be called after read_simulated_spectrum, not before.
  \result TRUE or FALSE, Does a protein have been loaded ?*/
int next_simulated_spectrum();

/*!
  \fn void set_threshold(double new_value)
  \brief Procedure which allows to set the threshold useful for the procedure write_spectrum_peak_only and the scoring.
  \param new_value The new value.*/
void set_threshold(double new_value);

/*!
  \fn double get_threshold()
  \brief Function to obtain the threshold.
  \result The threshold.*/
double get_threshold();

/*!
  \fn int get_spectrum_size()
  \brief Function which returns the size of the array that contains the spectrum.
  \result The size.*/
int get_spectrum_size();

/*!
  \fn double get_step()
  \brief Function which returns the spectra array step (distance between two spectrum points).
  \result The step.*/
double get_step();

/*!
  \fn char* get_spectrum_original_description()
  \brief Function which returns the original description of the current spectrum.
  \result The original description.*/
char* get_spectrum_original_description();

/*!
  \fn char* get_spectrum_original_sequence()
  \brief Function which returns the original sequence of the current spectrum.
  \result The original sequence.*/
char* get_spectrum_original_sequence();


/*!
  \fn void set_C_atom_quantity(int new_quantity)
  \brief Procedure which allows to modify the quantity of C atom for the initialisation process.
  \warning The call to this procedure will change the H, O, N and S quantities with the corresponding factor *4, /4, /2 and /8.\n The call is refused if the distribution has already been initialised.
  \param new_quantity The new atom C quantity.*/
void set_C_atom_quantity(int new_quantity);

/*!
  \fn int get_atom_quantity(const char* symbol)
  \brief Tool function which returns the atom quantity linked to a symbol or -1 if the symbol has not an associated atom quantity.
  \param symbol The symbol.
  \result The associated atom quantity or -1.*/
int get_atom_quantity(const char* symbol);

/*!
  \fn void set_spectrum_maximum_mass(int new_value)
  \brief Procedure which allows to modify the spectrum maximum mass.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new maximum mass.*/
void set_spectrum_maximum_mass(int new_value);

/*!
  \fn int get_spectrum_maximum_mass()
  \brief Function which allows to get the maximum mass authorized for the spectrum.
  \result The maximum mass.*/
int get_spectrum_maximum_mass();

/*!
  \fn void set_gaussian_value(double new_value)
  \brief Procedure which allows to modify the gaussian value.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new gaussian value.*/
void set_gaussian_value(double new_value);

/*!
  \fn double get_gaussian_value()
  \brief Function which allows to get the gaussian value.
  \result The gaussian value.*/
double get_gaussian_value();

/*!
  \fn void set_precision(int new_value)
  \brief Procedure which allows to modify the spectrum precision.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new precision.*/
void set_precision(int new_value);

/*!
  \fn int get_spectrum_precision()
  \brief Function which allows to get the spetrum precision.
  \result The precision.*/
int get_spectrum_precision();

/*!
  \fn char* get_simulated_spectra_filename()
  \brief Function which returns the name of file containing the simulated spectra.
  \result The file name.*/
char* get_simulated_spectra_filename();

/*!
  \fn char* get_experimental_filename()
  \brief Function which returns the file name of the experimental spectrum.
  \result The file name.*/
char* get_experimental_filename();

/*!
  \fn int is_simulated_wanted_protein()
  \brief Function which indicates if the current loaded protein corresponding to the specie.
  \result TRUE or FALSE (see util.h).*/
int is_simulated_wanted_protein();

/*!
  \fn void set_scoring_sensitivity(double new_value)
  \brief Procedure which allows to modify the score sensitivity.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new sensitivity.*/
void set_scoring_sensitivity(double new_value);

/*!
  \fn double get_scoring_sensitivity()
  \brief Function which returns the score sensitivity.
  \result The sensitivity.*/
double get_scoring_sensitivity();

/*!
  \fn void set_minimum_mass(double new_value)
  \brief Procedure which allows to modify the minimum mass for the peptides.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new minimum mass.*/
void set_minimum_mass(double new_value);

/*!
  \fn double get_minimum_mass()
  \brief Function which returns the minimum mass authorized for the peptides.
  \result The minimum mass.*/
double get_minimum_mass();

/*!
  \fn void set_maximum_mass(double new_value)
  \brief Procedure which allows to modify the maximum mass for the peptides.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new maximum mass.*/
void set_maximum_mass(double new_value);
/*!
  \fn double get_maximum_mass()
  \brief Function which returns the maximum mass authorized for the peptides.
  \result The maximum mass.*/
double get_maximum_mass();

/*!
  \fn void set_peptide_maximum_mass(int new_value)
  \brief Procedure which allows to modify the peptide maximum mass.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new peptide maximum mass.*/
void set_peptide_maximum_mass(int new_value);

/*!
  \fn void set_peptide_precision(int new_value)
  \brief Procedure which allows to modify the peptide precision.
  \warning The call is refused if the procedure init_distrib has been already used.
  \param new_value The new peptide precision.*/
void set_peptide_precision(int new_value);

/*!
  \fn int get_peptide_maximum_mass()
  \brief Function which allows to get the peptide maximum mass.
  \result The peptide maximum mass.*/
int get_peptide_maximum_mass();

/*!
  \fn int get_peptide_precision()
  \brief Function which allows to get the peptide precision.
  \result The peptide precision.*/
int get_peptide_precision();

/*!
  \fn void set_minimum_peptide_number(unsigned int new_value)
  \brief Procedure which allows to modify the minimum peptide number needed to a protein to be considered.
  \warning The call is refused if the procedure is_parsing_started (see seqio.h/.cpp) return TRUE.
  \param new_value The new minimum peptide number.*/
void set_minimum_peptide_number(unsigned int new_value);

/*!
  \fn unsigned int get_minimum_peptide_number()
  \brief Function which allows to get the minimum peptide number for a protein to be considered.
  \result The minimum peptide number.*/
unsigned int get_minimum_peptide_number();

/*!
  \fn void set_minimum_matched_peptide_number(unsigned int new_value)
  \brief Procedure which allows to modify the minimum matched peptide number needed to a protein to be considered.
  \warning The call is refused if the procedure is_parsing_started (see seqio.h/.cpp) return TRUE.
  \param new_value The new minimum matched peptide number.*/
void set_minimum_matched_peptide_number(unsigned int new_value);

/*!
  \fn unsigned int get_minimum_matched_peptide_number()
  \brief Function which allows to get the minimum matched peptide number for a protein to be considered.
  \result The minimum matched peptide number.*/
unsigned int get_minimum_matched_peptide_number();

/*!
  \fn double compute_correlation(int index,complex_t* spectrum)
  \brief Function which gives the correlation between the two spectra (experimental and simulated) according to an index on a peptide (global = FALSE) or on the complete spectrum (global = TRUE).
  \param index The index.
  \param spectrum The spectrum to compare with the experimental spectrum.
  \result The correlation score between the two points.*/
double compute_correlation(int index,complex_t* spectrum);

/*!
  \fn double penalization_factor()
  \brief Function which gives a penalize factor corresponding to all the no need data from the simulated spectrum.
  \result The penalization score.*/
double penalization_factor();

/*!
  \fn double get_peptide_score_threshold()
  \brief Function which allows to get the peptide score threshold to make difference between "good" and "bad" peptides.
  \result The peptide score threshold.*/
double get_peptide_score_threshold();

/*!
  \fn double get_peptide_score_threshold()
  \brief Function which allows to get the peptide score threshold to make difference between "good" and "bad" peptides.*/
int get_distribution_activation();

/*!
  \fn double* get_current_peptide_score_save()
  \brief Function which allows to get the peptide scores of the last protein considered.
  \warning This function returns a direct pointer.*/
double* get_current_peptide_score_save();

/*!
  \fn unsigned int get_current_peptide_score_size();
  \brief Function which allows to get the peptide score array size of the last protein considered.*/
unsigned int get_current_peptide_score_size();

#endif
