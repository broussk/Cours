/*
  Copyright USTL (Universit� des Sciences et Technologies de Lille, FRANCE)
  Developer(s) : 
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
  \file isodistrib.cpp
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON and Christian ROLANDO (2005-2008).
  \brief Implementation of the methods defined in isodistrib.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "isodistrib.h"

/*!
  \var int is_distribution_initialised=FALSE
  \brief Flag that indicates if the distribution is already initialised or not.*/
int is_distribution_initialised=FALSE;

/*!
  \var complex_t* t_atom
  \brief Complex array for the atom spectrum.*/
complex_t* t_atom; 

/*!
  \var complex_t* result
  \brief  Complex array for the theoretical spectrum.*/
complex_t* result;

/*!
  \var complex_t* gauss
  \brief  Complex array for the gaussian convolution.*/
complex_t* gauss;

/*!
  \var complex_t* t_peptide
  \brief  Complex array for one peptide spectrum.*/
complex_t* t_peptide;

/*!
  \var complex_t* t_shifted_peptide
  \brief  Complex array for one peptide spectrum with a shifted mass.*/
complex_t* t_shifted_peptide;

/*!
  \var complex_t* t_exp_spec
  \brief  Complex array for the experimental spectrum.*/
complex_t* t_exp_spec;

/*!
  \var double gaussian
  \brief The gaussian value.*/
double gaussian=0.30;

/*!
  \var int N_SPEC
  \brief The spectrum precision.*/
int N_SPEC=65536;

/*!
  \var int N_PEPT
  \brief The peptide spectrum precision.*/
int N_PEPT=0;

/*!
  \var int spectrum_maximum_mass
  \brief The spectrum maximum mass.*/
int spectrum_maximum_mass=4096;

/*!
  \var int peptide_maximum_mass
  \brief The peptide spectrum maximum mass.*/
int peptide_maximum_mass=16;

/*!
  \var int peptide_precision
  \brief The peptide precision.*/
int peptide_precision=8;

/*!
  \var unsigned int minimum_peptide_number
  \brief The minimum number of peptides that the digestion has to produced for a protein to be considered.*/
unsigned int minimum_peptide_number=5;

/*!
  \var unsigned int minimum_matched_peptide_number
  \brief The minimum number of peptides belonging to the "good" peptides for a protein to be considered.*/
unsigned int minimum_matched_peptide_number=3;

/*!
  \var double min_experimental_mass
  \brief The minimum authorized peptide mass.*/
double min_experimental_mass=700;

/*!
  \var double max_experimental_mass
  \brief The maximum authorized peptide mass.*/
double max_experimental_mass=2500;

/*!
  \var double threshold
  \brief The spectrum threshold.*/
double threshold=0.0000001;

/*!
  \var double sensitivity
  \brief The sensitivity.*/
double sensitivity=0.5;

/*!
  \var double variation_threshold
  \brief The varation threshold.*/
double variation_threshold=-1.0;

/*!
  \var char* experimental_file
  \brief The experimental spectrum fime.*/
char* experimental_file=NULL;

/*!
  \var char* spectrum_original_description
  \brief The theoretical spectrum description (from FASTA database).*/
char* spectrum_original_description=NULL;

/*!
  \var char* spectrum_original_sequence
  \brief The theoretical spectrum original sequence (from FASTA database).*/
char* spectrum_original_sequence=NULL;

/*!
  \var char* simulated_spectra_file
  \brief The name of the file that contains the spectum database.*/
char* simulated_spectra_file=NULL;

/*!
  \var FILE* simulated_spectra
  \brief The file that contains the simulated spectrum database.*/
FILE* simulated_spectra=NULL;

/*!
  \var int step
  \brief The step between two points in a complete spectrum.*/
double step;

/*!
  \var double atom_step
  \brief The step between two points in the atom spectrum.*/
double atom_step;

/*!
  \var double gauss_param
  \brief The gaussian parameter.*/
double gauss_param;

/*!
  \var int nb_data_amu
  \brief Number of points between each mass unit of a complete spectrum.*/
int nb_data_amu;

/*!
  \var int atom_nb_data_amu
  \brief Number of points between each mass unit in the atom spectrum.*/
int atom_nb_data_amu;

/*!
  \var double peptide_score_threshold
  \brief The score threshold for consider a peptide has a good peptide or a bad peptide.*/ 
double peptide_score_threshold=0.0;

/*!
  \var int* ip
  \brief A first variable needed for the fast fourier transform process.*/
int* ip=NULL;

/*!
  \var double* w
  \brief A second variable needed for the fast fourier transform process.*/
double* w=NULL;

/*!
  \var int C_atom_quantity
  \brief Maximum quantity of C atoms, the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int C_atom_quantity=1000;

/*!
  \var int H_atom_quantity
  \brief Maximum quantity of H atoms, the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int H_atom_quantity=4000;

/*!
  \var int O_atom_quantity
  \brief Maximum quantity of O atoms, the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int O_atom_quantity=250;

/*!
  \var int S_atom_quantity
  \brief Maximum quantity of S atoms, the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int S_atom_quantity=125;

/*!
  \var int N_atom_quantity
  \brief Maximum quantity of N atoms, the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int N_atom_quantity=500;

/*!
  \var int Se_atom_quantity
  \brief Maximum quantity of Se atoms (due to the U amino acid), the corresponding distributions from 1 to this value will be computed during the distribution initialisation.*/ 
int Se_atom_quantity=100;

/*!
  \var complex_t** C_atom
  \brief All the saved distribution of the C atom.*/
complex_t** C_atom=NULL;

/*!
  \var complex_t** H_atom
  \brief All the saved distribution of the H atom.*/
complex_t** H_atom=NULL;

/*!
  \var complex_t** O_atom
  \brief All the saved distribution of the O atom.*/
complex_t** O_atom=NULL;

/*!
  \var complex_t** S_atom
  \brief All the saved distribution of the S atom.*/
complex_t** S_atom=NULL;

/*!
  \var complex_t** N_atom
  \brief All the saved distribution of the N atom.*/
complex_t** N_atom=NULL;

/*!
  \var complex_t** Se_atom
  \brief All the saved distribution of the Se atom.*/
complex_t** Se_atom=NULL;

/*!
  \var complex_t* t_C_atom
  \brief The distribution of C1.*/
complex_t* t_C_atom=NULL;

/*!
  \var complex_t* t_H_atom
  \brief The distribution of H1.*/
complex_t* t_H_atom=NULL;

/*!
  \var complex_t* t_O_atom
  \brief The distribution of O1.*/
complex_t* t_O_atom=NULL;

/*!
  \var complex_t* t_S_atom
  \brief The distribution of S1.*/
complex_t* t_S_atom=NULL;

/*!
  \var complex_t* t_N_atom
  \brief The distribution of N1.*/
complex_t* t_N_atom=NULL;

/*!
  \var complex_t* t_Se_atom
  \brief The distribution of Se1.*/
complex_t* t_Se_atom=NULL;

/*!
  \var double* current_peptide_score_save
  \brief The score of the peptide of the last protein considered.*/
double* current_peptide_score_save=NULL;

/*!
  \var unsigned int current_peptide_score_size
  \brief Size the of the current_peptide_score_save array.*/
unsigned int current_peptide_score_size=0;

/*!
  \fn complex_t** get_X_atom(char* symbol)
  \brief Tool function which returns the complex_t** X_atom associated to a symbol or NULL if the symbol has not an associated X_atom.
  \param symbol The symbol.
  \result The associated X_atom or NULL.*/
complex_t** get_X_atom(char* symbol);

/*!
  \fn complex_t* get_t_X_atom(char* symbol)
  \brief Tool function which returns the complex_t* t_X_atom associated to a symbol or NULL if the symbol has not a associated t_X_atom.
  \param symbol The symbol.
  \result The associated t_X_atom or NULL.*/
complex_t* get_t_X_atom(char* symbol);

void cdft(int, int, double *, int *, double *);

void
init_distrib()
{
  int j,i,index;
  double main_isotop_mass;
  formula_t *C_formula, *H_formula, *O_formula, *S_formula, *N_formula, *Se_formula;

  main_isotop_mass=0.0;

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Initialisation :\n");
      printf("\tC quantity = %d\n",C_atom_quantity);
      printf("\tH quantity = %d (4*C quantity)\n",H_atom_quantity);
      printf("\tO quantity = %d (C quantity /4)\n",O_atom_quantity);
      printf("\tN quantity = %d (C quantity /2)\n",N_atom_quantity);
      printf("\tS quantity = %d (C quantity /8)\n",S_atom_quantity);
      printf("\tSe quantity = %d (C quantity /10)\n",Se_atom_quantity);
      printf("\tFormulae loading  ");
    }
  C_formula=read_formula("C",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  H_formula=read_formula("H",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  O_formula=read_formula("O",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  S_formula=read_formula("S",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  N_formula=read_formula("N",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  Se_formula=read_formula("Se",get_element_table(),get_element_table_size());
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }
  
  N_PEPT= (peptide_maximum_mass*N_SPEC*peptide_precision)/spectrum_maximum_mass;
  nb_data_amu= N_SPEC/spectrum_maximum_mass;
  atom_nb_data_amu= nb_data_amu*peptide_precision; 

  ////////////////////////////fft4g/////////////////////////////
  ip=(int*)malloc((2+(int)sqrt(N_PEPT/2))*sizeof(int));
  if(ip==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE IP ARRAY USEFUL FOR FFT",
	    "IP IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }

  ip[0]=0;
  
  w=(double*)malloc((N_PEPT/2)*sizeof(double));
  if(w==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE W ARRAY USEFUL FOR FFT",
	    "W IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  ////////////////////////////fft4g/////////////////////////////
  
  /* step for array index */
  step=(double)spectrum_maximum_mass/(double) N_SPEC;
  /*CR nouvelle definition */
  atom_step = step/(double)peptide_precision;

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tC_atom allocation  ");
    }
  C_atom=(complex_t**)malloc(C_atom_quantity*sizeof(complex_t*));
  if(C_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE C SPECTRA ARRAY",
	    "C_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<C_atom_quantity;i++)
    {
      C_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(C_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A C SPECTRUM",
		"C_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tH_atom allocation  ");
    }
  H_atom=(complex_t**)malloc(H_atom_quantity*sizeof(complex_t*));
  if(H_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE H SPECTRA ARRAY",
	    "H_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<H_atom_quantity;i++)
    {
      H_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(H_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A H SPECTRUM",
		"H_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tO_atom allocation  ");
    }
  O_atom=(complex_t**)malloc(O_atom_quantity*sizeof(complex_t*));
  if(O_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE O SPECTRA ARRAY",
	    "O_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<O_atom_quantity;i++)
    {
      O_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(O_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A O SPECTRUM",
		"O_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tS_atom allocation  ");
    }
  S_atom=(complex_t**)malloc(S_atom_quantity*sizeof(complex_t*));
  if(S_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE S SPECTRA ARRAY",
	    "S_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<S_atom_quantity;i++)
    {
      S_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(S_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A S SPECTRUM",
		"S_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tN_atom allocation  ");
    }
  N_atom=(complex_t**)malloc(N_atom_quantity*sizeof(complex_t*));
  if(N_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE N SPECTRA ARRAY",
	    "N_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<N_atom_quantity;i++)
    {
      N_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(N_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A N SPECTRUM",
		"N_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tN_atom allocation  ");
    }
  Se_atom=(complex_t**)malloc(Se_atom_quantity*sizeof(complex_t*));
  if(Se_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE Se SPECTRA ARRAY",
	    "Se_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  for(i=0;i<Se_atom_quantity;i++)
    {
      Se_atom[i]=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
      if(Se_atom[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A Se SPECTRUM",
		"Se_ATOM[i] IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tt_X_atom allocation  ");
    }
  t_C_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_C_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE C_ATOM SPECTRUM",
	    "T_C_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  
  t_H_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_H_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE H_ATOM SPECTRUM",
	    "T_H_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  
  t_O_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_O_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE O_ATOM SPECTRUM",
	    "T_O_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  
  t_S_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_S_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE S_ATOM SPECTRUM",
	    "T_S_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  
  t_N_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_N_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE N_ATOM SPECTRUM",
	    "T_N_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  t_Se_atom=(complex_t*)malloc(N_PEPT*sizeof(complex_t));
  if(t_Se_atom==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE Se_ATOM SPECTRUM",
	    "T_Se_ATOM IS NULL IN INIT_DISTRIB IN ISODISTRIB.CPP");
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tt_X_atom and X_atom initialisation  ");
    }
  for(j=0;j<N_PEPT;j++)
    {
      t_C_atom[j].Re=t_C_atom[j].Im=0.0;
      C_atom[0][j].Re=1.0;
      C_atom[0][j].Im=0.0;
      
      t_H_atom[j].Re=t_H_atom[j].Im=0.0;
      H_atom[0][j].Re=1.0;
      H_atom[0][j].Im=0.0;
      
      t_O_atom[j].Re=t_O_atom[j].Im=0.0;
      O_atom[0][j].Re=1.0;
      O_atom[0][j].Im=0.0;

      t_S_atom[j].Re=t_S_atom[j].Im=0.0;
      S_atom[0][j].Re=1.0;
      S_atom[0][j].Im=0.0;

      t_N_atom[j].Re=t_N_atom[j].Im=0.0;
      N_atom[0][j].Re=1.0;
      N_atom[0][j].Im=0.0;

      t_Se_atom[j].Re=t_Se_atom[j].Im=0.0;
      Se_atom[0][j].Re=1.0;
      Se_atom[0][j].Im=0.0;
      
      if((j%1000==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tt_X_atom calculation  ");
      printf(".");
    }
  main_isotop_mass = C_formula->comps->element->isotops->relative_mass;
  for(j=0;j<C_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((C_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_C_atom[index].Re=C_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }
  
  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_C_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////
  
  free_formula(C_formula);

  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  main_isotop_mass = H_formula->comps->element->isotops->relative_mass;
  for(j=0;j<H_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((H_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_H_atom[index].Re=H_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }

  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_H_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////

  free_formula(H_formula);

  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  main_isotop_mass = O_formula->comps->element->isotops->relative_mass;
  for(j=0;j<O_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((O_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_O_atom[index].Re=O_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }
  
  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_O_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////

  free_formula(O_formula);
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  main_isotop_mass = S_formula->comps->element->isotops->relative_mass;
  for(j=0;j<S_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((S_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_S_atom[index].Re=S_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }

  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_S_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////

  free_formula(S_formula);

  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  main_isotop_mass = N_formula->comps->element->isotops->relative_mass;
  for(j=0;j<N_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((N_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_N_atom[index].Re=N_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }

  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_N_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////

  free_formula(N_formula);
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  main_isotop_mass = Se_formula->comps->element->isotops->relative_mass;
  for(j=0;j<Se_formula->comps->element->nb_isotops;j++)
    {
      index = (int)((Se_formula->comps->element->isotops[j].relative_mass-main_isotop_mass)/atom_step);
      t_Se_atom[index].Re=Se_formula->comps->element->isotops[j].isotopic_composition/100.0;
    }

  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)t_Se_atom,ip,w);
  ////////////////////////////fft4g/////////////////////////////

  free_formula(Se_formula);
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tX_atom initial calculation  ");
    }

  for(j=0;j<N_PEPT;j++)
    {
      C_atom[0][j]=complex_multiplication(C_atom[0][j],t_C_atom[j]);
      H_atom[0][j]=complex_multiplication(H_atom[0][j],t_H_atom[j]);
      O_atom[0][j]=complex_multiplication(O_atom[0][j],t_O_atom[j]);
      S_atom[0][j]=complex_multiplication(S_atom[0][j],t_S_atom[j]);
      N_atom[0][j]=complex_multiplication(N_atom[0][j],t_N_atom[j]);
      Se_atom[0][j]=complex_multiplication(Se_atom[0][j],t_Se_atom[j]);
      if((j%1000==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tX_atom total calculation:\n");
      printf("\t\tSe_atom  ");
    }
  
  for(i=0;i<Se_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  C_atom[i+1][j]=complex_multiplication(C_atom[i][j],t_C_atom[j]);
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	  O_atom[i+1][j]=complex_multiplication(O_atom[i][j],t_O_atom[j]);
	  S_atom[i+1][j]=complex_multiplication(S_atom[i][j],t_S_atom[j]);
	  N_atom[i+1][j]=complex_multiplication(N_atom[i][j],t_N_atom[j]);
	  Se_atom[i+1][j]=complex_multiplication(Se_atom[i][j],t_Se_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
      printf("\t\tS_atom  ");
    }

  for(;i<S_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  C_atom[i+1][j]=complex_multiplication(C_atom[i][j],t_C_atom[j]);
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	  O_atom[i+1][j]=complex_multiplication(O_atom[i][j],t_O_atom[j]);
	  S_atom[i+1][j]=complex_multiplication(S_atom[i][j],t_S_atom[j]);
	  N_atom[i+1][j]=complex_multiplication(N_atom[i][j],t_N_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\t\tO_atom  ");
    }
  for(;i<O_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  C_atom[i+1][j]=complex_multiplication(C_atom[i][j],t_C_atom[j]);
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	  O_atom[i+1][j]=complex_multiplication(O_atom[i][j],t_O_atom[j]);
	  N_atom[i+1][j]=complex_multiplication(N_atom[i][j],t_N_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\t\tN_atom  ");  
    }

  for(;i<N_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  C_atom[i+1][j]=complex_multiplication(C_atom[i][j],t_C_atom[j]);
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	  N_atom[i+1][j]=complex_multiplication(N_atom[i][j],t_N_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\t\tC_atom  ");
    }
  
  for(;i<C_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  C_atom[i+1][j]=complex_multiplication(C_atom[i][j],t_C_atom[j]);
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\t\tH_atom  ");
    }
  
  for(;i<H_atom_quantity-1;i++)
    {
      for(j=0;j<N_PEPT;j++)
	{
	  H_atom[i+1][j]=complex_multiplication(H_atom[i][j],t_H_atom[j]);
	}
      if(((i%100)==0)&&(is_verbose_mode_activated()==TRUE))
	{
	  printf(".");
	}
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Ok\n");
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\tFinal initialisation  ");
    }

  t_exp_spec=(complex_t *) malloc(sizeof(complex_t)*N_SPEC);
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  result=(complex_t *) malloc(sizeof(complex_t)*N_SPEC);
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  t_peptide=(complex_t *) malloc(sizeof(complex_t)*N_SPEC);
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  gauss=(complex_t *) malloc(sizeof(complex_t)*N_PEPT);
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  t_atom=(complex_t *) malloc(sizeof(complex_t)*N_PEPT);  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  t_shifted_peptide=(complex_t *) malloc(sizeof(complex_t)*N_PEPT);  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }
  
  /*loading gaussian e-(x�/2*s�) with 2*s2 gauss_param which is proprotionnal to the peak width	*/
  gauss_param= (double)2.0*(gaussian/(double)2.3548)*(gaussian/(double)2.3548);
  
  for(j=0;j<N_PEPT/2;j++)
    {
      gauss[j].Re=gauss[N_PEPT-1-j].Re=exp(-(((double)j*atom_step)*((double)j*atom_step)/ gauss_param ));
      gauss[j].Im=gauss[N_PEPT-1-j].Im=0.0;
    }
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".");
    }

  ////////////////////////////fft4g/////////////////////////////
  cdft(N_PEPT,1,(double*)gauss,ip,w);
  ////////////////////////////fft4g/////////////////////////////
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf(".Ok\n");
    }
  
  is_distribution_initialised=TRUE;
}

double
optimized_isotopic_distribution(formula_t *peptides,int nb_peptides)
{
  
  int i,j,peptide_index,atom_index,idx_peptid,index,atom_quantity,begin,end,step_until_end,back,nb_equivalent;
  int nb_good_peptides,nb_bad_peptides,nb_null_peptides;
  composition_t *comp;
  double main_isotop_mass,shift,sum,evolution,maximum_score,sum_of_good,sum_of_bad;/*,penalization;*/
  complex_t** X_atom;
  complex_t* t_X_atom;

  /*penalization=0.0;*/

  X_atom=NULL;

  nb_equivalent=0;

  maximum_score=((max_experimental_mass/step)-(min_experimental_mass/step));

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\nPossible peptide maximum score = %f\n",maximum_score);
    }

  if(current_peptide_score_save!=NULL)
    {
      free(current_peptide_score_save);
    }

  current_peptide_score_size=nb_peptides;

  current_peptide_score_save=(double*)malloc(nb_peptides*sizeof(double));
  if(current_peptide_score_save==NULL)
  {
    error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE SCORE ARRAY",
	  "CURRENT_PEPTIDE_SCORES IS NULL IN OPTIMIZED_ISOTOPIC_DISTRIBUTION IN ISODISTRIB.CPP");
  }
  for(i=0;i<nb_peptides;i++)
    {
      current_peptide_score_save[i]=-maximum_score; 
    }
  
  for(i=0;i<N_SPEC;i++)
    {
      result[i].Re=result[i].Im=0.0;
    }

  nb_good_peptides=nb_bad_peptides=0;

  if((unsigned int)nb_peptides >= minimum_peptide_number)
    {
      for(peptide_index=0;peptide_index<nb_peptides;peptide_index++)
	{
	  if(is_equivalent_to_another(peptide_index)==TRUE)
	    {
	      nb_equivalent++;
	    }
	  else
	    {
	      comp=copy_composition(peptides[peptide_index].comps,peptides[peptide_index].nb_comp);
	  
	      shift=get_weight(&peptides[peptide_index]);
	  
	      if ((((int)shift)>min_experimental_mass)&&(((int)shift)<max_experimental_mass))
		{
		  for(j=0;j<N_SPEC;j++) /* init t_peptide with 1 for power calculation : C2=C*C */ 
		    {
		      t_peptide[j].Re=0.0;
		      t_peptide[j].Im=0.0;
		  
		    }
	      
		  for(j=0;j<N_PEPT;j++) /* init t_shifted_peptide with 1 for power calculation : C2=C*C */ 
		    {
		      t_shifted_peptide[j].Re=1.0;
		      t_shifted_peptide[j].Im=0.0;
		    }
	      
		  ////////// BEGIN for atoms of 1 peptide ///////
		  for(atom_index=0;atom_index<peptides[peptide_index].nb_comp;atom_index++)
		    {
		      main_isotop_mass = comp[atom_index].element->isotops[0].relative_mass;
	      
		      atom_quantity=get_atom_quantity(comp[atom_index].element->symbol);
	      	      
		      if(atom_quantity==-1)
			{
			  printf("Another element : %s\n",comp[atom_index].element->symbol);
			  for(i=0;i<N_PEPT;i++)
			    {
			      t_atom[i].Re=t_atom[i].Im=0.0;
			    }
		  
			  for(i=0;i<comp[atom_index].element->nb_isotops;i++)
			    {
			      index = (int)((comp[atom_index].element->isotops[i].relative_mass-main_isotop_mass)/atom_step);
			      t_atom[index].Re=comp[atom_index].element->isotops[i].isotopic_composition/100.0;
			    }
		  
			  ////////////////////////////fft4g/////////////////////////////
			  cdft(N_PEPT,1,(double*)t_atom,ip,w);
			  ////////////////////////////fft4g/////////////////////////////
		  
			  for(i=0;i<comp[atom_index].quantity;i++)
			    {
			      for(j=0;j<N_PEPT;j++)
				{
				  t_shifted_peptide[j]=complex_multiplication(t_shifted_peptide[j],t_atom[j]);
				}
			    }
			}
		      else
			{
			  X_atom=get_X_atom(comp[atom_index].element->symbol);
			  if(X_atom==NULL)
			    {
			      error(EXECUTION_ERROR,"THE WANTED ELEMENT IS GOOD BUT THE SPECTRUM ASSOCIATED IS EMPTY",
				    "X_ATOM IS NULL IN OPTIMIZED_ISOTOPIC_DISTRIBUTION.CPP");
			    }
		  
			  if(atom_quantity<comp[atom_index].quantity)
			    {
			      if(atom_index==0)
				{
				  for(j=0;j<N_PEPT;j++)
				    {
				      t_shifted_peptide[j]=X_atom[atom_quantity-1][j];
				    }
				}
			      else
				{
				  for(j=0;j<N_PEPT;j++)
				    {
				      t_shifted_peptide[j]=complex_multiplication(t_shifted_peptide[j],X_atom[atom_quantity-1][j]);
				    }
				}
			      t_X_atom=get_t_X_atom(comp[atom_index].element->symbol);
			      if(t_X_atom==NULL)
				{
				  error(EXECUTION_ERROR,"THE WANTED ELEMENT IS GOOD BUT THE T_SPECTRUM ASSOCIATED IS EMPTY",
					"T_X_ATOM IS NULL IN OPTIMIZED_ISOTOPIC_DISTRIBUTION.CPP");
				}
			      for(i=atom_quantity;i<comp[atom_index].quantity;i++)
				{
				  t_shifted_peptide[j]=complex_multiplication(t_shifted_peptide[j],t_X_atom[j]);
				}
			    }
			  else
			    {
			      if(atom_index==0)
				{
				  for(j=0;j<N_PEPT;j++)
				    {
				      t_shifted_peptide[j]=X_atom[comp[atom_index].quantity-1][j];
				    }
				}
			      else
				{
				  for(j=0;j<N_PEPT;j++)
				    {
				      t_shifted_peptide[j]=complex_multiplication(t_shifted_peptide[j],X_atom[comp[atom_index].quantity-1][j]);
				    }
				}
			    }
			}
		    } /* END FOR atoms of 1 peptid */

		  for(j=0;j<N_PEPT;j++)
		    {
		      t_shifted_peptide[j]=complex_multiplication(t_shifted_peptide[j],gauss[j]);
		    }
    
		  ////////////////////////////fft4g/////////////////////////////
		  cdft(N_PEPT,-1,(double*)t_shifted_peptide,ip,w);
		  ////////////////////////////fft4g/////////////////////////////

		  /* put the spectrum of t_shifted_peptidee into t_peptide with the correct mass offset and interpolation */
		  /*!!!! The 2 last mass are thought to belong the main isotopic peak !!!! */
	  
		  idx_peptid=0;
		  for(j=(int)(shift*(double)nb_data_amu); j< (int)(shift*(double)nb_data_amu) + (peptide_maximum_mass-2)*nb_data_amu ;j++)
		    {
		      /*interpolation start*/
		      sum=0.0;
		      for(i=idx_peptid;i<idx_peptid+peptide_precision;i++)
			{
			  sum+=t_shifted_peptide[i].Re;
			}
		      /*interpolation end */
		      t_peptide[j].Re=sum/peptide_precision;
		      idx_peptid+=peptide_precision;
		    }
	  
	  
		  /* Interpolate the end of atom spectrum (t_shifed_peptid) with the begining mass -1 shifted of t_peptide*/
		  /* this is due to gaussian convolution (the 1st peak is divided in 2 half gaussian)  */
		  /*!!!! The 2 last mass are thought to belong the main isotopic peak !!!! */
		  idx_peptid= N_PEPT - 2*nb_data_amu*peptide_precision;
	  
		  for(j=(int)(shift*(double)nb_data_amu) - 2*nb_data_amu;j<(int)(shift*(double)nb_data_amu);j++)
		    {
		      sum=0.0;
		      for(i=idx_peptid;i<(idx_peptid+peptide_precision);i++)
			{
			  sum+=t_shifted_peptide[i].Re;
			}
	      
		      t_peptide[j].Re=sum/peptide_precision;
		      idx_peptid+=peptide_precision;
	      
		    }
	  
		  integral_normalization((double)1.0, N_SPEC, t_peptide);
	  
		  sum=0.0;
	  
		  //search the beginning of the first peak
		  j=(int)(shift/step);
		  while(t_peptide[j].Re>threshold)
		    {
		      j--;
		    }

		  begin=j;
		  evolution=1.0;
		  step_until_end=(int)(1/step);
	  
		  while(((j*step)<max_experimental_mass)&&(step_until_end!=0))
		    {
		      sum+=compute_correlation(j,t_peptide);
		      j++;
		      //we climb the peak
		      while(((j*step)<max_experimental_mass)&&(evolution>0.0))
			{
			  evolution=t_peptide[j].Re-t_peptide[j-1].Re;
			  sum+=compute_correlation(j,t_peptide);
			  j++;
			}
		      //we descend the peak
		      while(((j*step)<max_experimental_mass)&&(evolution<0.0))
			{
			  evolution=t_peptide[j].Re-t_peptide[j-1].Re;
			  sum+=compute_correlation(j,t_peptide);
			  j++;
			}
		      back=j;
		      //there is another peak ?
		      //check the next masses in an interval of one Da
		      while((step_until_end!=0)&&((j*step)<max_experimental_mass)&&(t_peptide[j].Re<threshold))
			{
			  j++;
			  step_until_end--;
			}
		      if((j*step)<max_experimental_mass)
			{
			  if(t_peptide[j].Re>=threshold)
			    {
			      step_until_end=(int)(1/step);
			      j=back;
			    }
			}
		    }
		  end=j;
	  
		  current_peptide_score_save[peptide_index]=sum;
	      
		  if(sum>peptide_score_threshold)
		    {
		      nb_good_peptides++;
		    }
		  else
		    {
		      nb_bad_peptides++;
		    }
	  
		  j=begin;
		  while((j<N_SPEC)&&(j<end))
		    {
		      result[j].Re+= t_peptide[j].Re;
		      result[j].Im=0.0;
		      j++;
		    }
		}
	      free_composition(comp,peptides[peptide_index].nb_comp);
	    }
	}
    }
  
  
  
  sum=sum_of_good=sum_of_bad=0.0;
  nb_null_peptides=nb_peptides-(nb_good_peptides+nb_bad_peptides+nb_equivalent);
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\nnbtotal= %d",nb_peptides);
      printf(", without equivalent = %d",nb_peptides-nb_equivalent);
      printf(", without equivalent and null = %d\n",nb_peptides-nb_equivalent-nb_null_peptides);
      printf("nbG = %d, nbB = %d, nbN= %d\n",nb_good_peptides,nb_bad_peptides,nb_null_peptides);
      printf("%%G = %f%%, %%B = %f%%, %%N= %f%%\n\n",((float)(nb_good_peptides*100)/(nb_peptides-nb_equivalent)),
	     ((float)(nb_bad_peptides*100)/(nb_peptides-nb_equivalent)),((float)(nb_null_peptides*100)/(nb_peptides-nb_equivalent)));
    }
  
  if((unsigned int)nb_good_peptides>=minimum_matched_peptide_number)
    {
      sum=((float)(nb_good_peptides)/(nb_peptides-nb_equivalent-nb_null_peptides))*100;
    }

  //In this version, no penalization
  //sum+=penalization;

  integral_normalization((double)1.0, N_SPEC, result);

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("score = %f\n",sum);
    }

  return sum;
}

int 
get_atom_quantity(const char* symbol)
{
  if(strcmp(symbol,"C")==0)
    {
      return C_atom_quantity;
    }
  else if(strcmp(symbol,"H")==0)
    {
      return H_atom_quantity;
    }
  else if(strcmp(symbol,"O")==0)
    {
      return O_atom_quantity;
    }
  else if(strcmp(symbol,"N")==0)
    {
      return N_atom_quantity;
    }
  else if(strcmp(symbol,"S")==0)
    {
      return S_atom_quantity;
    }
  else if(strcmp(symbol,"Se")==0)
    {
      return Se_atom_quantity;
    }
  else
    {
      return -1;
    }
}

complex_t**
get_X_atom(char* symbol)
{
 if(strcmp(symbol,"C")==0)
    {
      return C_atom;
    }
  else if(strcmp(symbol,"H")==0)
    {
      return H_atom;
    }
  else if(strcmp(symbol,"O")==0)
    {
      return O_atom;
    }
  else if(strcmp(symbol,"N")==0)
    {
      return N_atom;
    }
  else if(strcmp(symbol,"S")==0)
    {
      return S_atom;
    }
  else if(strcmp(symbol,"Se")==0)
    {
      return Se_atom;
    }
  else
    {
      return NULL;
    }
} 

complex_t*
get_t_X_atom(char* symbol)
{
  if(strcmp(symbol,"C")==0)
    {
      return t_C_atom;
    }
  else if(strcmp(symbol,"H")==0)
    {
      return t_H_atom;
    }
  else if(strcmp(symbol,"O")==0)
    {
      return t_O_atom;
    }
  else if(strcmp(symbol,"N")==0)
    {
      return t_N_atom;
    }
  else if(strcmp(symbol,"S")==0)
    {
      return t_S_atom;
    }
  else if(strcmp(symbol,"Se")==0)
    {
      return t_Se_atom;
    }
  else
    {
      return NULL;
    }
}

void
integral_normalization(double integral_value,int size,complex_t *t_complex)
{ 
  int j;
  double sum,coef,max;
  /* integral calculation  for normalization*/
  sum=0.0;
  max=0.0;
  
  for(j=1;j<size;j++)                 //for(j=0;j<size;j++)
    {
      if(t_complex[j].Re<0.0)           //if(t_complex[j].Re<0.0)
	    {
	      t_complex[j].Re=0.0;            //t_complex[j].Re=0.0;
	    }
      else if (t_complex[j].Re>max)     //sum+=t_complex[j].Re;
      {                                 //if(t_complex[j].Re>max)
	    max=t_complex[j].Re;              //{
	    }                                 //max=t_complex[j].Re;
	    sum+=t_complex[j].Re;             //}
    }

  /*normalization for integral=integral_value*/
  if (max < 1e-18) 
    {
      max=1e-18;
    }
  
  coef=integral_value/max;
  for(j=0;j<size;j++)
    {
      t_complex[j].Re*=coef;
    }
}

/*!
  \fn void write_spectrum_cplx(FILE* f,complex_t* t_complex,char* entry)
  \brief Procedure which writes a module of data in a complex spectrum file.
  \param f The file.
  \param t_complex The spectrum.
  \param entry The spectrum name.*/
void
write_spectrum_cplx(FILE* f,complex_t* t_complex,char* entry)
{
  int i;
  
  fprintf(f,"$ \n! %s\n",entry);
  for(i=0;i<N_SPEC;i++)
    {
      fprintf(f,"%f %f\n",((double)i*step),sqrt(t_complex[i].Re*t_complex[i].Re+t_complex[i].Im*t_complex[i].Im));      
    }
}

void
write_spectrum(FILE *f,complex_t *t_complex,char *entry)
{
  int i;

  fprintf(f,"$ \n! %s\n",entry);
  for(i=0;i<N_SPEC;i++)
    {
      fprintf(f,"%f\t%0.21f\n",((double)i*step),t_complex[i].Re);      
    }
}

void
read_spectrum(const char *spectrum_file)
{
  int cur,prev,i,j,index,loaded;
  FILE *f;
  double interpolation,value,mass,intensity;
  
  char buffer[128];
  int read=0;
  char c;

  loaded=FALSE;
  intensity=0.0;
  
  for(i=0;i<N_SPEC;i++)
    {
      t_exp_spec[i].Re=-1.0; /* init with -1 flag for futur interpolation */
      // Pourquoi pas ?
      t_exp_spec[i].Im=0.0; //t_exp_spec[i+1].Im=0.0; 
    }

  index=0;
  cur=prev=-1;
  f=fopen(spectrum_file,"r");
  if(f==NULL)
    {
      error(IO_ERROR,"THE SPECTRUM FILE IS NOT CORRECTLY OPENED",
	    "F IS NULL IN READ_SPECTRUM IN READ_SPECTRUM.CPP");
    }
  
  experimental_file=(char*)malloc((strlen(spectrum_file)+1)*sizeof(char));
  if(experimental_file==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE EXPERIMENTAL SPECTRUM FILE",
	    "EXPERIMENTAL_FILE IS NULL IN READ_SPECTRUM IN READ_SPECTRUM.CPP");
    }
  strcpy(experimental_file,spectrum_file);

  jump_commentaries(f,'#');

  while((read!=EOF)&&(index!=N_SPEC))
    {
      do
	{
	  read=fscanf(f,"%c",&c);
	}
      while((read!=EOF)&&(!isdigit(c)));
      if(read!=EOF)
	{
	  ungetc(c,f);
	  read=fscanf(f,"%s",buffer);
	  mass=(double)atof(buffer);
	  if(read!=EOF)
	    {
	      read=fscanf(f,"%s",buffer);
	      intensity=(double)atof(buffer);
	    }
	  
	  while((read!=EOF)&&(c!='\n'))
	    {
	      read=fscanf(f,"%c",&c);
	    }
	
	  index=(int)((double) mass/step); /* store intensity at good index of array according to step */
	  
	  if ( mass < (double)0.0) 
	    {
	      error(WARNING,"A INTENSITY VALUE ON THE EXPERIMENTAL SPECTRUM IS NEGATIVE, STRANGE",
		    "MASS IS NEGATIVE, SO 0.0 IS PUT IN READ_SPECTRUM IN ISODISTRIB.CPP");
	    }
	  
	  if(index<N_SPEC)
	    {
	      loaded=TRUE;

	      if(t_exp_spec[index].Re==-1)
		{
		  t_exp_spec[index].Re=(double) intensity;
		}
	      else
		{
		  t_exp_spec[index].Re=(t_exp_spec[index].Re+(double) intensity)/2;
		}
	      
	      if(prev==-1) 
		{
		  prev=index;
		  for(j=0;j<prev;j++)
		    {
		      t_exp_spec[j].Re=0.0;
		    }
		}
	      else
		{
		  cur=index;
		}
	      
	      if((cur!=-1)&&(cur!=prev))
		{
		  interpolation=(t_exp_spec[cur].Re-t_exp_spec[prev].Re)/((double)(cur-prev));
		  value=t_exp_spec[prev].Re+interpolation;
		  
		  for(j=prev+1;j<cur;j++)
		    {	 
		      t_exp_spec[j].Re=value;
		      value+=interpolation;
		    }
		  prev=cur;
		}
	    }
	}    
    }

  if(loaded==FALSE)
    {
      error(USAGE_ERROR,"THE EXPERIMENTAL SPECTRUM IS ODD, NO VALUE IN IT",
	    "THE SPECTRUM IS ODD, MAYBE THE FILE IS NOT A SPECTRUM FILE IN READ_SPECTRUM IN ISODISTRIB.CPP");
    }

  integral_normalization(1.0,N_SPEC,t_exp_spec);
  
  variation_threshold=0.0;

  for(i=0;i<N_SPEC;i++)
    {
      variation_threshold+=t_exp_spec[i].Re;
    }

  variation_threshold/=((max_experimental_mass/step)-(min_experimental_mass/step));
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("Variation threshold = %f\n",variation_threshold);
    }
  
  fclose(f);
}

void
free_isodistrib()
{
  int i;
  
  free(t_exp_spec);
  free(t_shifted_peptide);
  free(t_atom);
  free(result);
  free(t_peptide);
  free(gauss);
  free(experimental_file);
  if(spectrum_original_description!=NULL)
    {
      free(spectrum_original_description);
      free(spectrum_original_sequence);
    }
  if(simulated_spectra_file!=NULL)
    {
      free(simulated_spectra_file);
    }

  for(i=0;i<C_atom_quantity;i++)
    {
      free(C_atom[i]);
    }
  free(C_atom);

  for(i=0;i<H_atom_quantity;i++)
    {
      free(H_atom[i]);
    }
  free(H_atom);

  for(i=0;i<O_atom_quantity;i++)
    {
      free(O_atom[i]);
    }
  free(O_atom);
  
  for(i=0;i<S_atom_quantity;i++)
    {
      free(S_atom[i]);
    }
  free(S_atom);
  
  for(i=0;i<N_atom_quantity;i++)
    {
      free(N_atom[i]);
    }
  free(N_atom);

  for(i=0;i<Se_atom_quantity;i++)
    {
      free(Se_atom[i]);
    }
  free(Se_atom);
  
  free(t_C_atom);
  free(t_H_atom);
  free(t_O_atom);
  free(t_S_atom);
  free(t_N_atom);
  free(t_Se_atom);

  if(current_peptide_score_save!=NULL)
    {
      free(current_peptide_score_save);
      current_peptide_score_size=0;
    }
  
  ////////////////////////////fft4g/////////////////////////////
  if(ip!=NULL)
    {
      free(ip);
    }
  if(w!=NULL)
    {
      free(w);
    }
  ////////////////////////////fft4g/////////////////////////////

}

complex_t*
get_exp_spectrum()
{
  return t_exp_spec;
}

complex_t* 
copy_spectrum(complex_t* spectrum)
{
  int i;
  complex_t* copie;
  if(spectrum==NULL)
    {
      error(USAGE_ERROR,"THE SPECTRUM TO COPY IS EMPTY",
	    "SPECTRUM IS NULL IN COPY_SPECTRUM IN ISODISTRIB.CPP");
    }
  copie=(complex_t *) malloc(sizeof(complex_t)*N_SPEC);
  if(copie==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE SPECTRUM COPIE",
	    "COPIE IS NULL IN COPY_SPECTRUM IN ISODISTRIB.CPP");
    }
  for(i=0;i<N_SPEC;i++)
    {
      copie[i].Re=spectrum[i].Re;
      copie[i].Im=spectrum[i].Im; 
    }
  return copie;
}

void
set_exp_spectrum(complex_t* spectrum)
{
  int i;
  if(spectrum==NULL)
    {
      error(USAGE_ERROR,"THE GIVEN SPECTRUM IS EMPTY",
	    "SPECTRUM IS NULL IN SET_EXP_SPECTRUM IN ISODISTRIB.CPP");
    }
  for(i=0;i<N_SPEC;i++)
    {
      t_exp_spec[i].Re=spectrum[i].Re;
      t_exp_spec[i].Im=spectrum[i].Im;
    }
}

void
write_spectrum_peak_only(FILE* file, complex_t* spectrum, char* name)
{
  int i;
  fprintf(file,"$ \n! %s\n",name);
  for(i=0;i<N_SPEC;i++)
    {
      if(spectrum[i].Re>=threshold)
	{
	  fprintf(file,"%f %0.21f\n",((double)i*step),spectrum[i].Re);      
	}
    }
}

void
read_simulated_spectrum(const char *spectrum_file)
{
  simulated_spectra=fopen(spectrum_file,"r");
  if(simulated_spectra==NULL)
    {
      error(IO_ERROR,"THE SIMULATED SPECTRUM FILE IS NOT CORRECTLY OPENED",
	    "SIMULATED_SPECTRA IS NULL IN READ_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
    }
  simulated_spectra_file=(char*)malloc((strlen(spectrum_file)+1)*sizeof(char));
  if(simulated_spectra_file==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE NAME OF THE SIMULATED SPECTRUM",
	    "SIMULATED_SPECTRA_FILE IS NULL IN READ_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
    }
  strcpy(simulated_spectra_file,spectrum_file);
}

int
next_simulated_spectrum()
{
  int read,i,previous,current;
  char c;
  char buffer[4096];
  /*double intensity;*/
  if(simulated_spectra==NULL)
    {
      return FALSE;
    }
  
  /*intensity=0.0;*/
  previous=-1;
  current=0;
  read=0;
  c=' ';
  
  read=fscanf(simulated_spectra,"%c",&c);
  if(read==EOF)
    {
      fclose(simulated_spectra);
      simulated_spectra=NULL;
      return FALSE;
    }
  if(c!='#')
    {
      error(USAGE_ERROR,"THE FIRST SYMBOL OF THE FIRST LINE OF THE SIMULATED SPECTRUM MUST BE #",
	    "C!=# IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
    }
  do
    {
      read=fscanf(simulated_spectra,"%c",&c);
    }
  while((read!=EOF)&&(c!='\n'));
  if(read!=EOF)
    {
      read=fscanf(simulated_spectra,"%c",&c);
      if(c!='#')
	{
	  error(USAGE_ERROR,"THE FIRST SYMBOL OF THE SECOND LINE OF THE SIMULATED SPECTRUM MUST BE #",
		"C!=# IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
	}
      do
	{
	  read=fscanf(simulated_spectra,"%c",&c);
	}
      while((read!=EOF)&&(c!=':'));
      if(read!=EOF)
	{
	  i=0;
	  while((read!=EOF)&&(c!='\n'))
	    {
	      read=fscanf(simulated_spectra,"%c",&c);
	      if(read!=EOF)
		{
		  buffer[i]=c;
		}
	      i++;
	    }
	  if(read!=EOF)
	    {
	      buffer[i-1]='\0';
	      if(spectrum_original_description==NULL)
		{
		  spectrum_original_description=(char*)malloc((strlen(buffer)+1)*sizeof(char));
		  if(spectrum_original_description==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE ORIGINAL SPECTRUM DESCRIPTION",
			    "SPECTRUM_ORIGINAL_DESCRIPTION IS NULL IN NEXT_SIMULATED_SPECTRUM");
		    }
		}
	      else
		{
		  spectrum_original_description=(char*)realloc(spectrum_original_description,(strlen(buffer)+1)*sizeof(char));
		  if(spectrum_original_description==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE ORIGINAL SPECTRUM DESCRIPTION",
			    "SPECTRUM_ORIGINAL_DESCRIPTION IS NULL IN NEXT_SIMULATED_SPECTRUM");
		    }
		}
	      strcpy(spectrum_original_description,buffer);
	    }
	}
    }
  if(read!=EOF)
    {
      read=fscanf(simulated_spectra,"%c",&c);
      if(c!='#')
	{
	  error(USAGE_ERROR,"THE FIRST SYMBOL OF THE THIRD LINE OF THE SIMULATED SPECTRUM MUST BE #",
		"C!=# IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
	}
      do
	{
	  read=fscanf(simulated_spectra,"%c",&c);
	}
      while((read!=EOF)&&(c!=':'));
      if(read!=EOF)
	{
	  read=fscanf(simulated_spectra,"%s",buffer);
	  if(read!=EOF)
	    {
	      if(spectrum_original_sequence==NULL)
		{
		  spectrum_original_sequence=(char*)malloc((strlen(buffer)+1)*sizeof(char));
		  if(spectrum_original_sequence==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE ORIGINAL SPECTRUM SEQUENCE",
			    "SPECTRUM_ORIGINAL_SEQUENCE IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
		    }
		}
	      else
		{
		  spectrum_original_sequence=(char*)realloc(spectrum_original_sequence,(strlen(buffer)+1)*sizeof(char));
		  if(spectrum_original_sequence==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE ORIGINAL SPECTRUM SEQUENCE",
			    "SPECTRUM_ORIGINAL_SEQUENCE IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
		    }
		}
	      strcpy(spectrum_original_sequence,buffer);
	      do
		{
		  read=fscanf(simulated_spectra,"%c",&c);
		}
	      while((read!=EOF)&&(c!='\n'));
	    }
	}
    }
  if(read!=EOF)
    {
      read=fscanf(simulated_spectra,"%c",&c);
      if(c!='$')
	{
	  error(USAGE_ERROR,"THE FIRST SYMBOL OF THE FOURTH LINE OF THE SIMULATED SPECTRUM MUST BE $",
		"C!=$ IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
	}
      do
	{
	  read=fscanf(simulated_spectra,"%c",&c);
	}
      while((read!=EOF)&&(c!='\n'));
    }
  if(read!=EOF)
    {
      read=fscanf(simulated_spectra,"%c",&c);
      if(c!='!')
	{
	  error(USAGE_ERROR,"THE FIRST SYMBOL OF THE FOURTH LINE OF THE SIMULATED SPECTRUM MUST BE !",
		"C!=! IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
	}
      do
	{
	  read=fscanf(simulated_spectra,"%c",&c);
	}
      while((read!=EOF)&&(c!='\n'));
    }
  if(read==EOF)
    {
      error(IO_ERROR,"THE SIMULATED SPECTRUM FILE IS ENDED WITHOUT VALUE LOADED",
	    "UNWANTED EOF GAINED IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
    }
  read=fscanf(simulated_spectra,"%c",&c);
  while((read!=EOF)&&(c!='#'))
    {
      ungetc(c,simulated_spectra);
      read=fscanf(simulated_spectra,"%s",buffer);
      if(read!=EOF)
	{
	  current=(int)(((double)atof(buffer))/step);
	  for(i=previous+1;i<current;i++)
	    {
	      result[i].Re=result[i].Im=0.0;
	    }
	}
      read=fscanf(simulated_spectra,"%s",buffer);
      if(read!=EOF)
	{
	  result[current].Re=(double)atof(buffer);
	  result[current].Im=0.0;
	  do
	    {
	      read=fscanf(simulated_spectra,"%c",&c);
	    }
	  while((read!=EOF)&&(c!='\n'));
	}
      if(read==EOF)
	{
	  error(IO_ERROR,"THE SIMULATED SPECTRUM FILE IS NOT ENDED PROPERLY",
		"UNWANTED EOF GAINED IN NEXT_SIMULATED_SPECTRUM IN ISODISTRIB.CPP");
	}
      read=fscanf(simulated_spectra,"%c",&c);
      previous=current;
    }
  for(i=previous+1;i<N_SPEC;i++)
    {
      result[i].Re=result[i].Im=0.0;
    }
  if(c=='#')
    {
      ungetc(c,simulated_spectra);
    }
  return TRUE;
}


complex_t*
get_theo_spectrum()
{
  return result;
}

void
set_threshold(double new_value)
{
  threshold=new_value;
}

double
get_threshold()
{
  return threshold;
}

int
get_spectrum_size()
{
  return N_SPEC;
}

double
get_step()
{
  return step;
}

char*
get_spectrum_original_description()
{
  return spectrum_original_description;
}

char*
get_spectrum_original_sequence()
{
  return spectrum_original_sequence;
}

void 
set_C_atom_quantity(int new_quantity)
{
  if(C_atom!=NULL)
    {
      error(USAGE_ERROR,"THE C ATOM QUANTITY CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_C_ATOM_QUANTITY IN ISODISTRIB.CPP");
    }
  if(new_quantity<=0)
    {
      error(USAGE_ERROR,"THE WANTED C_ATOM QUANTITY IS STRANGE",
	    "NEW_QUANTITY HAS AN ODD VALUE");
    }
  C_atom_quantity=new_quantity;
  H_atom_quantity=4*C_atom_quantity;
  N_atom_quantity=(int)(C_atom_quantity/2);
  if(N_atom_quantity==0)
    {
      error(USAGE_ERROR,"THE WANTED C ATOM QUANTITY IS NOT POSSIBLE BECAUSE N ATOM QUANTITY IS 0",
	    "C_ATOM_QUANTITY/2 EQUALS 0 IN SET_C_ATOM_QUANTITY IN ISODISTRIB.CPP");
    }
  O_atom_quantity=(int)(C_atom_quantity/4);
  if(O_atom_quantity==0)
    {
      error(USAGE_ERROR,"THE WANTED C ATOM QUANTITY IS NOT POSSIBLE BECAUSE O ATOM QUANTITY IS 0",
	    "C_ATOM_QUANTITY/4 EQUALS 0 IN SET_C_ATOM_QUANTITY IN ISODISTRIB.CPP");
    }
  S_atom_quantity=(int)(C_atom_quantity/8);
  if(S_atom_quantity==0)
    {
      error(USAGE_ERROR,"THE WANTED C ATOM QUANTITY IS NOT POSSIBLE BECAUSE S ATOM QUANTITY IS 0",
	    "C_ATOM_QUANTITY/8 EQUALS 0 IN SET_C_ATOM_QUANTITY IN ISODISTRIB.CPP");
    }

  Se_atom_quantity=(int)(C_atom_quantity/10);
  if(Se_atom_quantity==0)
    {
      error(USAGE_ERROR,"THE WANTED C ATOM QUANTITY IS NOT POSSIBLE BECAUSE Se ATOM QUANTITY IS 0",
	    "C_ATOM_QUANTITY/10 EQUALS 0 IN SET_C_ATOM_QUANTITY IN ISODISTRIB.CPP");
    }
}

void
set_spectrum_maximum_mass(int new_value)
{
  if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE SPECTRUM MAXIMUM MASS CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_SPECTRUM_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  if(new_value<=0)
    {
      error(USAGE_ERROR,"THE NEW SPECTRUM MAXIMUM MASS VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_SPECTRUM_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  spectrum_maximum_mass=new_value;
}

void
set_gaussian_value(double new_value)
{
  if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE GAUSSIAN VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_GAUSSIAN_VALUE IN ISODISTRIB.CPP");
    }
  if((new_value<=0.0)||(new_value>=1.0))
    {
      error(USAGE_ERROR,"THE NEW GAUSSIAN VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_GAUSSIAN_VALUE IN ISODISTRIB.CPP");
    }
  gaussian=new_value;
}

void
set_precision(int new_value)
{
  if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE PRECISION VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_PRECISION IN ISODISTRIB.CPP");
    }
  if(new_value<=1.0)
    {
      error(USAGE_ERROR,"THE NEW PRECISION VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_PRECISION IN ISODISTRIB.CPP");
    }
  N_SPEC=new_value;
}

char*
get_simulated_spectra_filename()
{
  return simulated_spectra_file;
}

int
get_spectrum_maximum_mass()
{
  return spectrum_maximum_mass;
}

double
get_gaussian_value()
{
  return gaussian;
}

int
get_spectrum_precision()
{
  return N_SPEC;
}

char*
get_experimental_filename()
{
  return experimental_file;
}

int 
is_simulated_wanted_protein()
{
  if(spectrum_original_description==NULL)
    {
      error(USAGE_ERROR,"NO SIMULATED SPECTRUM LOADED",
	    "SPECTRUM_ORIGINAL_DESCRIPTION IS NULL IN IS_SIMULATED_WANTED_PROTEIN IN ISODISTRIB.CPP");
    }
  if(get_specie()==NULL)
    {
      return TRUE;
    }
  return strstr(spectrum_original_description,get_specie())!=NULL;
}


void
set_scoring_sensitivity(double new_value)
{
   if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE SCORING SENSITIVITY VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_PRECISION IN ISODISTRIB.CPP");
    }
   if((new_value<=0.0)||(new_value>=1.0))
    {
      error(USAGE_ERROR,"THE SCORING SENSITIVITY VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_SCORING_SENSITIVITY IN ISODISTRIB.CPP");
    }
  sensitivity=new_value;
}

double
get_scoring_sensitivity()
{
  return sensitivity;
}

void
set_minimum_mass(double new_value)
{
   if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE MINIMUM MASS VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_MINIMUM_MASS IN ISODISTRIB.CPP");
    }
  if(new_value<=0.0)
    {
      error(USAGE_ERROR,"THE MINIMUM MASS VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_MINIMUM_MASS IN ISODISTRIB.CPP");
    }
  min_experimental_mass=new_value;
}

double
get_minimum_mass()
{
  return min_experimental_mass;
}

void
set_maximum_mass(double new_value)
{
 if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE MAXIMUM MASS VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  if(new_value<=0.0)
    {
      error(USAGE_ERROR,"THE MAXIMUM MASS VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  if(((int)new_value)>spectrum_maximum_mass)
    {
      new_value=spectrum_maximum_mass-1.0;
    }
  max_experimental_mass=new_value;
} 

double
get_maximum_mass()
{
  return max_experimental_mass;
}

void
set_peptide_maximum_mass(int new_value)
{
  if(N_PEPT!=0)
    {
      error(USAGE_ERROR,"THE PEPTIDE MAXIMUM MASS VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_PEPTIDE_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  if(new_value<=0)
    {
      error(USAGE_ERROR,"THE PEPTIDE MAXIMUM MASS VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_PEPTIDE_MAXIMUM_MASS IN ISODISTRIB.CPP");
    }
  peptide_maximum_mass=new_value;
}

void
set_peptide_precision(int new_value)
{
  if(N_PEPT!=0)
    {
      error(WARNING,"THE PEPTIDE PRECISION VALUE CAN NOT BE SET, IT HAS BEEN ALREADY INITIALIZED",
	    "INIT_DISTRIB ALREADY CALLED IN SET_PEPTIDE_PRECISION IN ISODISTRIB.CPP");
    }
  else if(new_value<=0)
    {
      error(USAGE_ERROR,"THE PEPTIDE PRECISION VALUE IS STRANGE",
	    "NEW_VALUE IS ODD IN SET_PEPTIDE_PRECISION IN ISODISTRIB.CPP");
    }
  else
    {
      peptide_precision=new_value;
    }
}

int
get_peptide_maximum_mass()
{
  return peptide_maximum_mass;
}

int
get_peptide_precision()
{
  return peptide_precision;
}

double
compute_correlation(int index,complex_t* spectrum)
{
  double exp_evolution,spec_evolution;
  
  if((index==0)||(index==N_SPEC-1))
    {
      return 0.0;
    }
  
  if(t_exp_spec[index].Re<variation_threshold)
    {
      return -spectrum[index].Re;
    }
  
  if((t_exp_spec[index-1].Re<variation_threshold)&&(t_exp_spec[index+1].Re<variation_threshold))
    {
      return -spectrum[index].Re;
    }
  
  if(spectrum[index].Re<threshold)
    {
      return -t_exp_spec[index].Re;
    }
  
  exp_evolution=t_exp_spec[index].Re-t_exp_spec[index-1].Re;
  spec_evolution=spectrum[index].Re-spectrum[index-1].Re;
  
  if(((exp_evolution>0.0)&&(spec_evolution<0.0))||((exp_evolution<0.0)&&(spec_evolution>0.0)))
    {
      return t_exp_spec[index].Re;
    }
  
  return t_exp_spec[index].Re*1.5;
}

double
penalization_factor()
{
  int i,begin,end;
  double penalization;

  penalization=0.0;
  begin=(int)(min_experimental_mass/step);
  end=(int)(max_experimental_mass/step);
  
  for(i=begin;i<end;i++)
    {
      if((t_exp_spec[i].Re>variation_threshold)&& (result[i].Re<threshold))
	{
	  penalization-=(t_exp_spec[i].Re*1.5);
	}
    }
  return penalization;
}
  
void 
set_minimum_peptide_number(unsigned int new_value)
{
  if(is_parsing_started()==TRUE)
    {
      error(WARNING,"THE MINIMUM PEPTIDE NUMBER VALUE CAN NOT BE SET, PARSING OF THE DATABASE IS ALREADY STARTED",
	    "IS_PARSING_STARTED RETURN TRUE IN SET_MINIMUM_PEPTIDE_NUMBER IN ISODISTRIB.CPP");
    }
  else
    {
      minimum_peptide_number=new_value;
    }
  
}

unsigned int
get_minimum_peptide_number()
{
  return minimum_peptide_number;
}

void 
set_minimum_matched_peptide_number(unsigned int new_value)
{
  if(is_parsing_started()==TRUE)
    {
      error(WARNING,"THE MINIMUM MATCHED PEPTIDE NUMBER VALUE CAN NOT BE SET, PARSING OF THE DATABASE IS ALREADY STARTED",
	    "IS_PARSING_STARTED RETURN TRUE IN SET_MINIMUM_MATCHED_PEPTIDE_NUMBER IN ISODISTRIB.CPP");
    }
  else
    {
      minimum_matched_peptide_number=new_value;
    }
  
}

unsigned int
get_minimum_matched_peptide_number()
{
  return minimum_matched_peptide_number;
}

double
get_peptide_score_threshold()
{
  return peptide_score_threshold;
}

int 
get_distribution_activation()
{
  return is_distribution_initialised;
}

double*
get_current_peptide_score_save()
{
  return current_peptide_score_save;
}

unsigned int
get_current_peptide_score_size()
{
  return current_peptide_score_size;
}
