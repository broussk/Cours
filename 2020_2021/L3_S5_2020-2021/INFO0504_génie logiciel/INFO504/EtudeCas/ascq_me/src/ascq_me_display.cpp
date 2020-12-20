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
  \file ascq_me_display.cpp
  \author Jean-Charles BOISSON (2006-2008).
  \brief Implementation of the methods defined in ascq_me_display.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "ascq_me_display.h"

/*!
  \def PROGRAM_LIMITATION
  \brief Maximum number of points that the spreadsheet program used to read the ASCQ_ME table result files can be read in one shot.*/
#define PROGRAM_LIMITATION 32000

/*!
  \var int nb_saved_proteins
  \brief Number of proteins currently saved.*/
int nb_saved_proteins=0;

/*!
  \var char** protein_descriptions
  \brief Descriptions of all the saved proteins.*/
char** protein_descriptions=NULL;

/*!
  \var char** protein_sequences
  \brief Sequences of all the saved proteins.*/
char** protein_sequences=NULL;

/*!
  \var complex_t** protein_spectra
  \brief Spectra of all the saved proteins.*/
complex_t** protein_spectra=NULL;

/*!
  \var double* protein_scores
  \brief Scores of all the saved proteins.*/
double* protein_scores=NULL;

/*!
  \var double** peptide_scores
  \brief For each saved proteins, scores of all of its peptides.*/
double** peptide_scores=NULL;

/*!
  \var char*** peptides.
  \brief Sequence of each peptide of each saved protein.*/
char*** peptides=NULL;

/*!
  \var formula_t** peptide_formulae
  \brief Formula of each peptide of each saved protein.*/
formula_t** peptide_formulae=NULL;

/*!
  \var int* peptide_number
  \brief Peptide number of each protein.*/
int* peptide_number=NULL;

/*!
  \var int* link_between_score_and_others
  \brief Array that allows to work on the indexes for making sorts.*/
int* link_between_score_and_others=NULL;

/*!
  \var char** current_peptides
  \brief Sequence of each peptide of the current analysed protein.*/
char** current_peptides=NULL;

/*!
  \var formula_t* current_peptide_formulae
  \brief Formula of each peptide of the current analysed protein.*/
formula_t* current_peptide_formulae=NULL;

/*!
  \var double* current_peptide_scores
  \brief Score of each peptide of the current analysed protein.*/
double* current_peptide_scores=NULL;

/*!
  \var int* link_between_score_and_peptides
  \brief Array that allows to work on the indexes to make sorts for the current analysed protein.*/
int* link_between_score_and_peptides=NULL;

/*!
  \var int nb_current_peptides
  \brief Peptide number of current analysed protein.*/
int nb_current_peptides=0;

void
init_ascq_me_display()
{
  int i;

  protein_descriptions=(char**)malloc(get_nb_displayed_proteins()*sizeof(char*));
  if(protein_descriptions==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PROTEIN DESCRIPTION ARRAY",
	    "PROTEIN_DESCRIPTION IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }
  
  protein_sequences=(char**)malloc(get_nb_displayed_proteins()*sizeof(char*));
  if(protein_sequences==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PROTEIN SEQUENCE ARRAY",
	    "PROTEIN_SEQUENCE IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }
    
  protein_spectra=(complex_t**)malloc(get_nb_displayed_proteins()*sizeof(complex_t*));
  if(protein_spectra==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PROTEIN SPECTRA ARRAY",
	    "PROTEIN_SPECTRA IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }
  
  protein_scores=(double*)malloc(get_nb_displayed_proteins()*sizeof(double));
  if(protein_scores==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PROTEIN SCORE ARRAY",
	    "PROTEIN_SCORE IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }

  peptide_scores=(double**)malloc(get_nb_displayed_proteins()*sizeof(double));
  if(peptide_scores==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE SCORING ARRAY",
	    "PEPTIDES_SCORING IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }
  
  peptides=(char***)malloc(get_nb_displayed_proteins()*sizeof(char**));
  if(peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PROTEIN PEPTIDE LIST",
	    "PEPTIDES IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }

  peptide_formulae=(formula_t**)malloc(get_nb_displayed_proteins()*sizeof(formula_t*));
  if(peptide_formulae==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE FORMULA ARRAY",
	    "PEPTIDES_FORMULA IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }

  link_between_score_and_others=(int*)malloc(get_nb_displayed_proteins()*sizeof(int));
  if(link_between_score_and_others==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE LINK BETWEEN SCORE AND THE OTHERS ARRAY ARRAY",
	    "LINK_BETWEEN_SCORE_AND_OTHERS IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }

  for(i=0;i<get_nb_displayed_proteins();i++)
    {
      link_between_score_and_others[i]=i;
    }

  peptide_number=(int*)malloc(get_nb_displayed_proteins()*sizeof(int));
  if(peptide_number==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDES NUMBER ARRAY",
	    "PEPTIDES_NUMBER IS NULL IN INIT_ASCQ_ME_DISPLAY IN ASCQ_ME_DISPLAY.CPP");
    }
}

void
add_protein(char* description,char* sequence,complex_t* spectrum,double score)
{
  int i,j,place,buffer,swap;
  double score_swap,score_buffer;
  formula_t* formula_buffer;

  if((description==NULL)||(sequence==NULL))
    {
      error(USAGE_ERROR,"THE PROTEIN DESCRIPTION OR/AND THE PROTEIN SEQUENCE IS EMPTY",
	    "DESCRIPTION OR/AND SEQUENCE IS/ARE NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
    }
  
  swap=0;
  score_swap=0.0;

  i=0;
  while((i<nb_saved_proteins)&&(protein_scores[i]>score))
    {
      i++;
    }
  place=i;

  if(i<nb_saved_proteins)
    {
      score_swap=protein_scores[i];
      protein_scores[i]=score;
      swap=link_between_score_and_others[i];
      i++;
    }

  while(i<nb_saved_proteins)
    {
      score_buffer=protein_scores[i];
      protein_scores[i]=score_swap;
      score_swap=score_buffer;
      buffer=link_between_score_and_others[i];
      link_between_score_and_others[i]=swap;
      swap=buffer;
      i++;
    }

  if(nb_saved_proteins<get_nb_displayed_proteins())
    {
      protein_descriptions[i]=(char*)malloc((strlen(description)+1)*sizeof(char));
      if(protein_descriptions[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PROTEIN DESCRIPTION",
		"PROTEIN_DESCRIPTION[i] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	}
      strcpy(protein_descriptions[i],description);
      
      protein_sequences[i]=(char*)malloc((strlen(sequence)+1)*sizeof(char));
      if(protein_sequences[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PROTEIN SEQUENCE",
		"PROTEIN_SEQUENCE[i] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	}
      strcpy(protein_sequences[i],sequence);
      
      protein_spectra[i]=copy_spectrum(spectrum);
      
      peptide_number[i]=nb_current_peptides;
      
      peptide_scores[i]=(double*)malloc(nb_current_peptides*sizeof(double));
      if(peptide_scores[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SCORE ARRAY",
		"PEPTIDES_SCORING[i] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	}
      
      peptides[i]=(char**)malloc(nb_current_peptides*sizeof(char*));
      if(peptides[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SEQUENCE ARRAY",
		"PEPTIDES[i] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	} 
      
      peptide_formulae[i]=(formula_t*)malloc(nb_current_peptides*sizeof(formula_t));
      if(peptide_formulae[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE FORMULA ARRAY",
		"PEPTIDES_FORMULA[i] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	} 

      sort_and_init_with_peptide_scoring();
      
      for(j=0;j<nb_current_peptides;j++)
	{
	  peptide_scores[i][j]=current_peptide_scores[j];
	  peptides[i][j]=(char*)malloc((strlen(current_peptides[j])+1)*sizeof(char));
	  if(peptides[i][j]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SEQUENCE",
		    "PEPTIDES[i][j] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    } 
	  strcpy(peptides[i][j],current_peptides[j]);
	  	
	  formula_buffer=copy_formula(&current_peptide_formulae[j]);
	  peptide_formulae[i][j]=*formula_buffer;
	  free(formula_buffer);
	}
      
      protein_scores[i]=score;
      
      if(i!=place)
	{
	  link_between_score_and_others[place]=i;
	  link_between_score_and_others[i]=swap;

	  protein_scores[place]=score;
	  protein_scores[i]=score_swap;
	}
      
      nb_saved_proteins++;
    }
  else
    {
      if(i!=place)
	{
	  free(protein_descriptions[swap]);
	  protein_descriptions[swap]=(char*)malloc((strlen(description)+1)*sizeof(char));
	  if(protein_descriptions[swap]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PROTEIN DESCRIPTION",
		    "PROTEINS_DESCRIPTION[swap] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    }
	  strcpy(protein_descriptions[swap],description);
	  
	  free(protein_sequences[swap]);
	  protein_sequences[swap]=(char*)malloc((strlen(sequence)+1)*sizeof(char));
	  if(protein_sequences[swap]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PROTEIN SEQUENCE",
		    "PROTEINS_SEQUENCE[swap] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    }
	  strcpy(protein_sequences[swap],sequence);

	  free(protein_spectra[swap]);
	  protein_spectra[swap]=copy_spectrum(spectrum);

	  free(peptide_scores[swap]);
	  peptide_scores[swap]=(double*)malloc(nb_current_peptides*sizeof(double));
	  if(peptide_scores[swap]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SCORING ARRAY",
		    "PROTEINS_SCORING[swap] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    }
	  
	  for(j=0;j<peptide_number[swap];j++)
	    {
	      free(peptides[swap][j]);
	    }
	  free(peptides[swap]);
	  free_n_formula(peptide_formulae[swap],peptide_number[swap]);
	  
	  peptide_number[swap]=nb_current_peptides;
	  
	  peptides[swap]=(char**)malloc(nb_current_peptides*sizeof(char*));
	  if(peptides[swap]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SEQUENCE ARRAY",
		    "PEPTIDES[swap] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    } 
	  
	  peptide_formulae[swap]=(formula_t*)malloc(nb_current_peptides*sizeof(formula_t));
	  if(peptide_formulae[swap]==NULL)
	    {
	      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE FORMULA ARRAY",
		    "PEPTIDES_FORMULA[swap] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
	    } 
	  
	  sort_and_init_with_peptide_scoring();

	  for(j=0;j<nb_current_peptides;j++)
	    {
	      peptide_scores[swap][j]=current_peptide_scores[j];
	      peptides[swap][j]=(char*)malloc((strlen(current_peptides[j])+1)*sizeof(char));
	      if(peptides[swap][j]==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE SEQUENCE",
			"PEPTIDES[swap][j] IS NULL IN ADD_PROTEIN IN ISODISTRIB.CPP");
		} 
	      strcpy(peptides[swap][j],current_peptides[j]);
	      
	      formula_buffer=copy_formula(&current_peptide_formulae[j]);
	      peptide_formulae[swap][j]=*formula_buffer;
	      free(formula_buffer);
	    }
	  
	  link_between_score_and_others[place]=swap;
	  protein_scores[place]=score;
	}
    }

  if(current_peptides!=NULL)
    {
      for(i=0;i<nb_current_peptides;i++)
	{
	  free(current_peptides[i]);
	}
      free(current_peptides);
      current_peptides=NULL;
    }
  if(current_peptide_formulae!=NULL)
    {
      free_n_formula(current_peptide_formulae,nb_current_peptides);
      current_peptide_formulae=NULL;
    }
}

void
printf_ascq_me_results()
{
  int i;
  formula_t* formula;
  
  if(is_decoy_mode_activated()==TRUE)
    {
      printf("Decoy score = %f\n\n",get_decoy_score());
    }

  for(i=0;i<nb_saved_proteins;i++)
    {
      printf("Protein %d :\n",i+1);
      printf("\tDescription = %s\n",protein_descriptions[link_between_score_and_others[i]]);
      printf("\tSequence = %s\n",protein_sequences[link_between_score_and_others[i]]);
      formula=get_formula_from_sequence(protein_sequences[link_between_score_and_others[i]]);
      printf("\tMass = %f\n",get_weight(formula));
      free_formula(formula);
      printf("\tScore = %f\n\n",protein_scores[i]);
    }
}

void
fprintf_ascq_me_results(FILE* file)
{
  int i,j;
  formula_t* formula;
  double good_peptide_score;

  if(is_decoy_mode_activated()==TRUE)
    {
      fprintf(file,"Decoy score = %f\n\n",get_decoy_score());
    }

  for(i=0;i<nb_saved_proteins;i++)
    {
      fprintf(file,"Protein %d :\n",i+1);
      fprintf(file,"\tDescription = %s\n",protein_descriptions[link_between_score_and_others[i]]);
      fprintf(file,"\tSequence = %s\n",protein_sequences[link_between_score_and_others[i]]);
      formula=get_formula_from_sequence(protein_sequences[link_between_score_and_others[i]]);
      fprintf(file,"\tMass = %f\n",get_weight(formula));
      free_formula(formula);
      fprintf(file,"\tScore = %f\n",protein_scores[i]);
      fprintf(file,"\tNumber of peptides = %d\n",peptide_number[link_between_score_and_others[i]]);
      good_peptide_score=0.0;
      j=0;
      while((j<peptide_number[link_between_score_and_others[i]]) && 
	    (peptide_scores[link_between_score_and_others[i]][j]>=get_peptide_score_threshold()))
	{
	  good_peptide_score+=peptide_scores[link_between_score_and_others[i]][j];
	  j++;
	}
      fprintf(file,"\tScore of \"good\" peptides = %f\n",(float)good_peptide_score);
      for(j=0;j<peptide_number[link_between_score_and_others[i]];j++)
	{
	  fprintf(file,"\t\tPeptide %d = %s of mass %f has a score of %f\n",j+1,peptides[link_between_score_and_others[i]][j],
		  (float)get_weight(&peptide_formulae[link_between_score_and_others[i]][j]),
		  peptide_scores[link_between_score_and_others[i]][j]);
	}
      fprintf(file,"\n\n");
    }
}

void
ascq_me_cleaning()
{
  int i,j;

  for(i=0;i<nb_saved_proteins;i++)
    {
      free(protein_descriptions[i]);
      free(protein_sequences[i]);
      free(protein_spectra[i]);
      free(peptide_scores[i]);
      for(j=0;j<peptide_number[i];j++)
	{
	  free(peptides[i][j]);
	}
      free(peptides[i]);
      free_n_formula(peptide_formulae[i],peptide_number[i]);
    }

  free(peptide_scores);
  free(protein_descriptions);
  free(protein_sequences);
  free(protein_spectra);
  free(protein_scores);
  free(link_between_score_and_others);
  free(peptide_number);
  free(peptides);
  free(peptide_formulae);

  if(nb_current_peptides!=0)
    {
      free(current_peptide_scores);
      free(link_between_score_and_peptides);
    }
}

void
fprintf_ascq_me_results_table_form(FILE* file)
{
  int begin,end,i,j,factor,difference;
  formula_t* formula;
  complex_t* experimental_spectrum;
  double correlation;
  
  begin=(int)(get_minimum_mass()/get_step());
  end=(int)(get_maximum_mass()/get_step());
  difference=end-begin;

  factor=difference/PROGRAM_LIMITATION;
  
  if(difference%PROGRAM_LIMITATION!=0)
    {
      factor++;
    }
  
  experimental_spectrum=get_exp_spectrum();
  
  fprintf(file,"Proteins");
  fprintf(file,"\tProtein exp");
  for(i=0;i<nb_saved_proteins;i++)
    {
      fprintf(file,"\tprotein_%d",i+1);
      fprintf(file,"\tcorrelation_%d",i+1);
    }
  fprintf(file,"\nDescription");
  fprintf(file,"\tNone");
  for(i=0;i<nb_saved_proteins;i++)
    {
      fprintf(file,"\t%s",protein_descriptions[link_between_score_and_others[i]]);
      fprintf(file,"\tnone");
    }
  fprintf(file,"\nMass");
  fprintf(file,"\tunknown");
  for(i=0;i<nb_saved_proteins;i++)
    {
      formula=get_formula_from_sequence(protein_sequences[link_between_score_and_others[i]]);
      fprintf(file,"\t%f",get_weight(formula));
      free_formula(formula);
      fprintf(file,"\tnone");
    }
  fprintf(file,"\nScore");
  fprintf(file,"\tNone");
  for(i=0;i<nb_saved_proteins;i++)
    {
      fprintf(file,"\t%f",protein_scores[i]);
      fprintf(file,"\tnone");
    }
  
  for(i=begin;i<end;i++)
    {
      //with this, all the spectrum can be visualize with for example excel (limited at 32 000
      //points) or other program ===> specify PROGRAM_LIMITATION according to the program used 
      if(i%factor==0)
	{
	  fprintf(file,"\n%f",(float)i*get_step());
	  fprintf(file,"\t%0.7f",experimental_spectrum[i].Re);
	  for(j=0;j<nb_saved_proteins;j++)
	    {
	      fprintf(file,"\t%0.7f",-protein_spectra[link_between_score_and_others[j]][i].Re);
	      correlation=compute_correlation(i,protein_spectra[link_between_score_and_others[j]]);
	      if(correlation<0.0)
		{
		  correlation=0.0;
		}
	      fprintf(file,"\t%0.7f",correlation);
	    }
	}
    }
  fprintf(file,"\n");
}

void
save_partial_peptide_scoring(double* peptide_scoring,int nb_peptides)
{
  int i;
  if(nb_current_peptides!=0)
    {
      free(current_peptide_scores);
      free(link_between_score_and_peptides);
    }
  
  nb_current_peptides=nb_peptides;
  current_peptide_scores=(double*)malloc(nb_peptides*sizeof(double));
  if(current_peptide_scores==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CURRENT PEPTIDE SCORING ARRAY",
	    "CURRENT_PEPTIDES_SCORING IS NULL IN SAVE_PARTIAL_PEPTIDE_SCORING");
    }
  link_between_score_and_peptides=(int*)malloc(nb_peptides*sizeof(int));
  if(link_between_score_and_peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE LINK BETWEEN SCORE AND PEPTIDES ARRAY",
	    "LINK_BETWEEN_SCORE_AND_PEPTIDES IS NULL IN SAVE_PARTIAL_PEPTIDE_SCORING");
    }
  for(i=0;i<nb_peptides;i++)
    {
      current_peptide_scores[i]=peptide_scoring[i];
      link_between_score_and_peptides[i]=i;
    }
}

int
compare_peptide_scores(const void* first,const void* second)
{
  double score1,score2;
  if(current_peptide_scores==NULL)
    {
      error(USAGE_ERROR,"COMPARISON IMPOSSIBLE, THE CURRENT PEPTIDE SCORING ARRAY IS EMPTY",
	    "CURRENT_PEPTIDES_SCORING IS NULL IN COMPARE_PEPTIDES_SCORE IN ASCQ_ME_DISPLAY.CPP");
    }

  score1=*(double*)first;
  score2=*(double*)second;

  if(score1>score2)
    {
      return -1;
    }
  else if(score1==score2)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

int
compare_peptide_score_from_indices(const void* first,const void* second)
{
  int i,j;
  if(current_peptide_scores==NULL)
    {
      error(USAGE_ERROR,"COMPARISON IMPOSSIBLE, THE CURRENT PEPTIDE SCORING ARRAY IS EMPTY",
	    "CURRENT_PEPTIDES_SCORING IS NULL IN COMPARE_PEPTIDES_SCORE_FROM_INDICES IN ASCQ_ME_DISPLAY.CPP");
    }

  i=*(int*)first;
  j=*(int*)second;

  if(current_peptide_scores[i]>current_peptide_scores[j])
    {
      return -1;
    }
  else if(current_peptide_scores[i]==current_peptide_scores[j])
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

void
sort_and_init_with_peptide_scoring()
{
  int i;
  char* buffer;
  formula_t* formula_buffer;
 
  qsort(link_between_score_and_peptides,nb_current_peptides,sizeof(int),compare_peptide_score_from_indices);
  qsort(current_peptide_scores,nb_current_peptides,sizeof(double),compare_peptide_scores);
  
  current_peptides=(char**)malloc(nb_current_peptides*sizeof(char*));
  if(current_peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CURRENT PEPTIDE SEQUENCE ARRAY",
	    "CURRENT_PEPTIDES IS NULL IN SORT_AND_INIT_WITH_PEPTIDE_SCORING IN ASCQ_ME_DISPLAY.CPP");
    }
  for(i=0;i<nb_current_peptides;i++)
    {
      buffer=get_peptide_sequence(link_between_score_and_peptides[i]);
      current_peptides[i]=(char*)malloc((strlen(buffer)+1)*sizeof(char));
      if(current_peptides[i]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A CURRENT PEPTIDE SEQUENCE",
		"CURRENT_PEPTIDES[i] IS NULL IN SORT_AND_INIT_WITH_PEPTIDE_SCORING IN ASCQ_ME_DISPLAY.CPP");
	}
      strcpy(current_peptides[i],buffer);
      free(buffer);
    }
  
  current_peptide_formulae=(formula_t*)malloc(nb_current_peptides*sizeof(formula_t));
  if(current_peptide_formulae==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CURRENT PEPTIDE FORMULA ARRAY",
	    "CURRENT_PEPTIDES_FORMULA IS NULL IN SORT_AND_INIT_WITH_PEPTIDE_SCORING IN ASCQ_ME_DISPLAY.CPP");
    }
  for(i=0;i<nb_current_peptides;i++)
    {
      formula_buffer=get_peptide_formula_from_index(link_between_score_and_peptides[i]);
      current_peptide_formulae[i]=*formula_buffer;
      free(formula_buffer);
    }
}

void
fprintf_ascq_me_peptide_scoring(FILE* file)
{
  int i,j,cpt;
  fprintf(file,"Rank\tscore\tnormalized score\tmass\tsequence\n\n");
  
  for(i=0;i<nb_saved_proteins;i++)
    {
      cpt=peptide_number[link_between_score_and_others[i]];
      
      if(peptide_scores[link_between_score_and_others[i]][peptide_number[link_between_score_and_others[i]]-1]<0.0)
	{
	  j=peptide_number[link_between_score_and_others[i]]-1;
	  while((j>0)&&(peptide_scores[link_between_score_and_others[i]][j]==peptide_scores[link_between_score_and_others[i]][peptide_number[link_between_score_and_others[i]]-1]))
	    {
	      j--;
	    }
	  
	  cpt=j+1;

	  if(j==peptide_number[link_between_score_and_others[i]]-2)
	    {
	      cpt=peptide_number[link_between_score_and_others[i]];
	    }
	  
	  for(j=0;j<cpt;j++)
	    {
	      peptide_scores[link_between_score_and_others[i]][j]+=fabs(peptide_scores[link_between_score_and_others[i]][cpt-1]);
	    }
	}  
      fprintf(file,"Protein %d: %d peptides\n\n",i+1,peptide_number[link_between_score_and_others[i]]);
      j=0;
      while((j<cpt)&&(peptide_scores[link_between_score_and_others[i]][j] > 0.0))
	{
	  fprintf(file,"%d\t%f\t%f\t%f\t%s\n",j+1,(float)peptide_scores[link_between_score_and_others[i]][j],
		  (float)(peptide_scores[link_between_score_and_others[i]][j]/peptide_scores[link_between_score_and_others[i]][0]),
		  (float)get_weight(&peptide_formulae[link_between_score_and_others[i]][j]),
		  peptides[link_between_score_and_others[i]][j]);
	  j++;
	}
      fprintf(file,"\n%d peptides have not been used for the scoring\n\n\n",peptide_number[link_between_score_and_others[i]]-j);
    }
}

void
fprintf_ascq_me_results_xml(FILE* file)
{
  int i,j,k,len;
  formula_t* formula;
  fprintf(file,"<decoy_score>%f</decoy_score>\n",get_decoy_score());
  for(i=0;i<nb_saved_proteins;i++)
    {
      fprintf(file,"<protein>\n");
      
      fprintf(file,"\t<id>%d</id>\n",i+1);
      fprintf(file,"\t<description>%s</description>\n",protein_descriptions[link_between_score_and_others[i]]);
      char * seq_line = protein_sequences[link_between_score_and_others[i]];
      len = strlen(seq_line);

      fprintf(file,"\t<seq>");
      for (k = 0;k < len;k++)
	{
	  if (k % 60 == 0 && k!=0)
	    fprintf(file,"\n");
	  fprintf(file,"%c",toupper(seq_line[k]));
	}
      fprintf(file,"\n</seq>\n");
      
      formula=get_formula_from_sequence(protein_sequences[link_between_score_and_others[i]]);
      fprintf(file,"\t<mass>%f</mass>\n",get_weight(formula));
      free_formula(formula);
      fprintf(file,"\t<score>%f</score>\n",protein_scores[i]);
      fprintf(file,"\t<peptides_nb>%d</peptides_nb>\n",peptide_number[link_between_score_and_others[i]]);
      for(j=0;j<peptide_number[link_between_score_and_others[i]];j++)
	{
	  fprintf(file,"\t\t<pep><id>%d</id><seq>%s</seq><score>%f</score></pep>\n",j+1,peptides[link_between_score_and_others[i]][j],peptide_scores[link_between_score_and_others[i]][j]);
	}
      
      fprintf(file,"</protein>\n");
    }
}
