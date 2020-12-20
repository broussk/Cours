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
  \file digest.h
  \author Pierre LAURENCE and David BOENS (2003).\n Modified and updated by Jean-Charles BOISSON 2005-2008.
  \brief Description of methods allowing to make the digestion of proteins.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#ifndef _digest_h
#define _digest_h

#include "cleavage.h"
#include "modifications_for_digestion.h"

/*!
  \def ENZFILENAME 
  \brief Default location of the enzyme file definition.*/
#define ENZFILENAME "./internal/enztable.aprot"

/*!
  \struct peptide
  \brief Structure that describes a peptide.*/
typedef struct peptide
{
  //! Start index of a peptide (according to the protein sequence).
  long startOff;
  //! End index of a peptide (according to the protein sequence).
  long endOff;
  //! The peptide mass.
  double weight;
  //! The number of missed cleavage of the peptide.
  int nb_missed_cleavages;
  //! The number of post-transltional modification for each amino acid.
  int* nb_modif;
  //! All the post-translational modifications of the peptide.
  int** modifications;
  //! Value that indicates if this peptide is equivalent to another one due to post-translational modifications.
  int equivalent_to_another;
}
peptide_t;

/*!
  \fn void digest ()
  \brief Procedure which realises the digestion with 0 miss-cleavage.*/
void digest ();

/*!
  \fn peptide_t* get_result_of_digestion(int * nb_peptides)
  \brief Function which returns the peptides resulting of the digestion.
  \warning get_result_of_digestion gives a original pointer so if you want to keep this result 
  and make other digestion, use the next function called get_copie_of_digestion_result (don't forget to 
  free the pointer after using it)
  \param nb_peptides The number of peptides, initialised by the function.
  \result The peptide list obtained after the digestion.*/
peptide_t* get_result_of_digestion(int * nb_peptides);

/*!
  \fn peptide_t* get_copie_of_digestion_result(int* nb_peptides)
  \brief Function which allows to gain a copie of the result of the digestion.
  \param nb_peptides The number of peptides, initialised by the function.
  \result The peptide list obtained after the digestion.*/
peptide_t* get_copie_of_digestion_result(int* nb_peptides);

/*!
  \fn void print_result_of_digestion(peptide_t* peptides,int nb_peptides)
  \brief Procedure which prints on stdout the result of the digestion.*/
void print_result_of_digestion(peptide_t* peptides,int nb_peptides); 

/*!
  \fn void fprint_result_of_digestion(FILE* file,peptide_t* peptides,int nb_peptides)
  \brief Procedure which prints in a file the result of the digestion.
  \param file The file where the result have to be put.
  \param peptides The peptide_t* we want to view to print.
  \param nb_peptides The peptide number.*/
void fprint_result_of_digestion(FILE* file,peptide_t* peptides,int nb_peptides);

/*!
  \fn void fprint_result_of_digestion_table_format(FILE* file,peptide_t* peptides,int nb_peptides)
  \brief Procedure which prints in a file a result of the digestion in a format useful for speadsheet programs.
  \param file The file where the result have to be put.
  \param peptides The peptide_t* we want to print.
  \param nb_peptides The peptide number.*/
void fprint_result_of_digestion_table_format(FILE* file,peptide_t* peptides,int nb_peptides); 

/*!
  \fn peptide_t* copy_peptide(peptide_t* original)
  \brief Function which makes a copy of a peptide.
  \param original The peptide we want to copy.
  \result The copy.*/
peptide_t* copy_peptide(peptide_t* original);

/*!
  \fn peptide_t* fusion_peptide(peptide_t* first,peptide_t* second)
  \brief Function which makes the fusion of two CONTIGUOUS (!!!) peptides.
  \param first The first peptide.
  \param second The second peptide.
  \warning The two peptides must be contiguous. They are fusionned in this order (first is really before second in the peptidic sequence).
  \result The new peptide result of the fusion.*/
peptide_t* fusion_peptide(peptide_t* first,peptide_t* second);

/*!
  \fn void new_peptides_by_missed_cleavage(int nb_missed_cleavages,int* nb_new_peptides)
  \brief Function which calculates the new peptides obtained with a missed cleavage number based of the digestion without missed cleavages.
  \param nb_missed_cleavages The number of missed cleavages.
  \param nb_new_peptides The number of the peptide calculated by this function.
  \result The new peptides gained.*/
void new_peptides_by_missed_cleavage(int nb_missed_cleavages,int* nb_new_peptides);

/*!
  \fn void real_digest (char *seq)
  \brief Procedure which realises the real digestion according the number of missed cleavages.
  \param seq The sequence to digest.*/
void real_digest (char *seq);

/*!
  \fn void activate_full_digestion(int activation)
  \brief Procedure which allows to activate or desactivate the full-digest process i.e. when it
  is activated, the digestion do not use the missed cleavage parameter and makes the digestion
  with all the possible missed cleavages (from 1 to n-1 missed cleavages with n the number of peptides
  gained without missed cleavages).
  \param activation The parameter which activates (TRUE) or not (FALSE) the full digestion.
*/ 
void activate_full_digestion(int activation);

/*!
  \fn int compare_peptides(const void* first,const void* second)
  \brief Procedure which compares two peptides ==> useful for qsort
  \param first a void pointer that is in reality a peptide.
  \param second a void pointer that is also a peptide.
  \result -1, 0 or 1 <=> the first is inferior,equal or superior to the second.*/
int compare_peptides(const void* first,const void* second);

/*!
  \fn void sort_peptides()
  \brief Procedure which sorts the current experimental peptides.
  
  It is simply a call of qsort with the function compare_peptides.*/
void sort_peptides();

/*!
  \fn void set_peptide_charge(const char* formula)
  \brief Procedure which allows to set the value of the atom charge.
  \param formula The formula (in char* format).*/
void set_peptide_charge(const char* formula);

/*!
  \fn double peptide_charge_weight()
  \brief Function which allows to get the weight of the atom charge.
  \result The weight of the atom charge.*/
double peptide_charge_weight();

/*!
  \fn formula_t* get_peptide_charge_formula()
  \brief Function which returns the formula of the atom charge.
  \result The formula of the atom charge (in formula_t* format).*/
formula_t* get_peptide_charge_formula();

/*!
  \fn void default_peptide_charge()
  \brief Procedure which sets the atom charge with the default value <=> H formula.*/
void default_peptide_charge();

/*!
  \fn void init_util_digestion()
  \brief Procedure which initialises all the data useful for digestion (enzyme table for the moment).*/
void init_util_digestion();

/*!
  \fn void set_used_enzyme(int chosen_enzyme)
  \brief Procedure which sets the chosen enzyme (default is 0 for trypsine see others in enztable.aprot).
  \param chosen_enzyme The chosen_enzyme.*/
void set_used_enzyme(int chosen_enzyme);

/*!
  \fn void free_util_digestion()
  \brief Procedure which frees all the data useful for the digestion (enzym table for the moment).*/
void free_util_digestion();

/*!
  \fn void set_nb_missed_cleavages(int missed_cleavage);
  \brief Procedure which allows to set the number of authorized missed cleavage.
  \param missed_cleavage The number of missed cleavages.*/
void set_nb_missed_cleavages(int missed_cleavage);

/*!
  \fn formula_t* get_formulae_of_peptides(int* nb_peptides)
  \brief Function which allows to obtain the result of the digestion in a formulae format.
  \param nb_peptides The peptide number (initialised by the function).
  \result The peptides in a formulae format.*/
formula_t* get_formulae_of_peptides(int* nb_peptides);

/*!
  \fn int get_nb_missed_cleavages()
  \brief Function which allows to get the number of authorized missed cleavages.*/
int get_nb_missed_cleavages();

/*!
  \fn int get_activation_full_digest()
  \brief Function which allows to get the state of the activation of full digestion.*/
int get_activation_full_digest();

/*!
  \fn char* get_used_enzyme()
  \brief Function which allows to get the name of the used enzyme.*/
char* get_used_enzyme();

/*!
  \fn void free_peptide(peptide_t* peptide)
  \brief Procedure which free the memory allocated for the post-translational modifications of a peptide
  \param peptide The peptide we want to free the memory.*/
void free_peptide(peptide_t* peptide);

/*!
  \fn void add_peptide_modification(peptide_t* peptide, int amino_acid, int modif)
  \brief Procedure which adds a modification on an amino acid of a peptide.
  \param peptide The peptide.
  \param amino_acid The amino acid (its index).
  \param modif The wanted modification (its index).*/
void add_peptide_modification(peptide_t* peptide, int amino_acid, int modif);

/*!
  \fn void compute_post_traductional_modifications_global()
  \brief Procedure which computes peptides gained with post-translational modifications.*/
void compute_post_traductional_modifications_global();

/*!
  \fn peptide_t* compute_post_traductional_modifications_one_peptide(peptide_t* peptide, int* nb_new)
  \brief Function which computes the peptides gained with post-translational modifications from one peptide.
  \param peptide The peptide.
  \param nb_new The number of new peptides generated (initialised by the function).
  \result The new peptides.*/
peptide_t* compute_post_traductional_modifications_one_peptide(peptide_t* peptide, int* nb_new);

/*!
  \fn char* get_peptide_sequence(int index)
  \brief Function which returns the sequence of the wanted peptide, this sequence is only for making saves for printing 
  because it can contains modifications name.
  \param index The index of the wanted peptide.
  \result The sequence.*/
char* get_peptide_sequence(int index);

/*!
  \fn void print_peptide(peptide_t* peptide)
  \brief Procedure which allows to print directly a peptide on the stdout.
  \param peptide The peptide we want to print.*/
void print_peptide(peptide_t* peptide);

/*!
  \fn void print_peptide_index(int index)
  \brief Procedure which prints directly on the screen a peptide of the current digestion (thanks to an index).
  \param index The index of the peptide.*/
void print_peptide_index(int index);

/*!
  \fn void fprint_peptide(FILE* file,peptide_t* peptide)
  \brief Procedure which allows to print a peptide in a file.
  \param file The file.
  \param peptide The peptide we want to print.*/
void fprint_peptide(FILE* file,peptide_t* peptide);

/*!
  \fn void fprint_peptide_index(FILE* file,int index)
  \brief Procedure which prints in a file a peptide of the current digestion (thanks to an index).
  \param file The file.
  \param index The index.*/
void fprint_peptide_index(FILE* file,int index);

/*!
  \fn formula_t* get_peptide_formula_from_index(int index)
  \brief Function which returns a formula corresponding to a peptide according to its place in the current digestion.
  \param index The index of the peptide in the current digestion.
  \result The peptide formula.*/
formula_t* get_peptide_formula_from_index(int index);

/*!
  \fn formula_t* get_peptide_formula(peptide_t* peptide)
  \brief Function which returns a formula corresponding to a wanted peptide of the current digested protein.
  \param peptide The peptide.
  \result The corresponding formula.*/
formula_t* get_peptide_formula(peptide_t* peptide);

/*!
  \fn formula_t* get_peptide_formula_from_another_protein(peptide_t* peptide,char* protein_sequence)
  \brief Function which returns a formula corresponding to a wanted peptide that not belongs to the current digested protein.
  \param peptide The peptide.
  \param protein_sequence The corresponding complete protein sequence.
  \result The peptide formula.*/
formula_t* get_peptide_formula_from_another_protein(peptide_t* peptide,char* protein_sequence);

/*!
  \fn int get_peptide_length_at_index(int index)
  \brief Function which returns the sequence length of a wanted peptide.
  \param index The index of the wanted peptide.
  \result The peptide length.*/
int get_peptide_length_at_index(int index);

/*!
  \fn int is_equivalent_to_another(int index)
  \brief Function which indicates if a peptide is equivalent to another one due to variable post-translational modifications
  \param index The index of the wanted peptide.
  \result TRUE or FALSE (see util.h).*/
int is_equivalent_to_another(int index);

/*!
  \fn void set_maximum_peptide_length(int new_value)
  \brief Procedure which sets the maximum allowed length in amino acids for a peptide. 
  \param new_value The new value.
  If a peptide has a longer length, it will be not considered during the post-translational modification computation.*/
void set_maximum_peptide_length(int new_value);

/*!
  \fn int get_maximum_peptide_length()
  \brief Function which returns the maximum allowed length in amino acids for a peptide.
  \result The maximum allowed length.*/
int get_maximum_peptide_length();

/*!
  \fn void compute_equivalent_peptides()
  \brief Procedure which computes for the current digestion, the peptides which has to be marked has equivalent to another one.*/
void compute_equivalent_peptides();

#endif
