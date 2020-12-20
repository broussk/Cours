/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s) : 
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
  \file digest.cpp
  \author Pierre LAURENCE and David BOENS (2003).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in digest.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "digest.h"

/*!
  \var peptide_t* Peptides
  \brief Result of the current digestion.*/
peptide_t* Peptides = NULL;

/*!
  \var int NbPeptides
  \brief Current digestion peptide number.*/
int NbPeptides=0;

/*!
  \var int FULL_DIGESTION
  \brief Activation state of the full digest process, TRUE or FALSE (see util.h).*/
int FULL_DIGESTION=FALSE;

/*!
  \var formula_t* peptide_charge_formula
  \brief Formula to add for the peptide to be charged.*/
formula_t* peptide_charge_formula=NULL;

/*!
  \var enztable_t* enztable
  \brief Enzyme table.*/
enztable_t* enztable=NULL;

/*!
  \var int enzyme.
  \brief Index of the current chosen enzyme in the enzyme table.
  
  The default value corresponds to the trypsine enzyme, see enztable.aprot to understand.*/
int enzyme=0;

/*!
  \var int nb_missed_cleavages
  \brief Maximum number of missed cleavage.*/
int nb_missed_cleavages=0;

/*!
  \var char* sequence
  \brief Sequence of the protein that i currently digested.*/
char* sequence=NULL;

/*!
  \var int maximum_peptide_length
  \brief Maximum length in amino acids allowed for a peptide.*/
int maximum_peptide_length=30;

void
digest ()
{
  aa_CF_t amino_acid; 
  double weight;      
  int i,cleav,previ;
  //char prev;
  
  i=previ=0;
  /*prev=' ';*/

  /*if it is not the first digestion
   *we need to free the memory of the last one*/
  if(Peptides!=NULL)
    {
      for(i=0;i<NbPeptides;i++)
	{
	  free_peptide(&Peptides[i]);
	}
      free(Peptides);
    }
  
  /* initialize a new digestion */
  NbPeptides = 1;
  
  // C'est parti pour le grand n'importe quoi
  //Peptides = (peptide_t *) malloc (32 * sizeof (char));            Peptides = (peptide_t *) malloc (32 * sizeof (char));
  Peptides = (peptide_t *) malloc (NbPeptides * sizeof (peptide_t)); //Peptides = (peptide_t *) malloc (NbPeptides * sizeof (peptide_t));
  if(Peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDES OF THE DIGESTION",
	    "PEPTIDES IS NULL IN DIGEST IN DIGEST.CPP"); 
    }
  Peptides[0].weight = (double) 0;
  Peptides[0].startOff = (long) 0;
  Peptides[0].endOff = strlen (sequence);
  Peptides[0].nb_missed_cleavages=0;
  Peptides[0].nb_modif=NULL;
  Peptides[0].modifications=NULL;
  Peptides[0].equivalent_to_another=FALSE;
  
  /* fill Peptides, peptides of current digest */
  i = 0;
  while (sequence[i] != '\0')
    {
      if(i==0)
	{
	  cleav = cpl_isCleavage2 (enztable->enz[enzyme].cpl,' ',sequence[i], sequence[i + 1]);
	}
      else 
	{
	  if(i==(int)(strlen(sequence)-1))
	    {
	      cleav = cpl_isCleavage2 (enztable->enz[enzyme].cpl, sequence[i - 1], sequence[i], ' ');
	    }
	  else
	    {
	      cleav = cpl_isCleavage2 (enztable->enz[enzyme].cpl, sequence[i - 1], sequence[i], sequence[i+1]);
	    }
	}
      amino_acid=get_amino_acid(sequence[i]);
      weight=get_weight(amino_acid.form);/*amino acid weight <=> the residu*/
      weight+=get_weight(get_util_formula("NHCHCO"));/*amino acid weight completed in peptidic chain*/
      if (weight> 0)
	{
	  Peptides[NbPeptides - 1].weight +=  weight;
	  
	  /* end fragment ? */
	  if (cleav)
	    {
	      /* fill caracteristics of current fragment */
	      Peptides[NbPeptides - 1].weight += get_weight(get_util_formula("H2O")) + peptide_charge_weight();
	      Peptides[NbPeptides - 1].startOff = previ;
	      if (enztable->enz[enzyme].side == C_SIDE)
		{
		  Peptides[NbPeptides - 1].endOff = i;
		  previ = i + 1;
		}
	      else
		{
		  Peptides[NbPeptides - 1].weight -= weight;
		  Peptides[NbPeptides - 1].endOff = i-1;
		  previ = i;
		}
	      
	      NbPeptides++;
	      
	      Peptides=(peptide_t*)realloc(Peptides,NbPeptides*sizeof(peptide_t));
	      if(Peptides==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE PEPTIDES OF THE DIGESTION",
			"PEPTIDES IS NULL IN DIGEST IN DIGEST.CPP"); 
		}
	      /* inialize next fragment */
	      Peptides[NbPeptides - 1].weight = (double) 0;
	      Peptides[NbPeptides - 1].nb_missed_cleavages=0;
	      Peptides[NbPeptides-1].nb_modif=NULL;
	      Peptides[NbPeptides-1].modifications=NULL;
	      Peptides[NbPeptides-1].equivalent_to_another=FALSE;
	      
	      if (enztable->enz[enzyme].side == N_SIDE)
		{
		  Peptides[NbPeptides - 1].weight = weight;
		}
	    }
	}
      /*prev = sequence[i];*/
      i++;
    }

  if(previ==i)
    {
      NbPeptides--;
      Peptides=(peptide_t*)realloc(Peptides,NbPeptides*sizeof(peptide_t));
      if(Peptides==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE PEPTIDES OF THE DIGESTION",
	 	"PEPTIDES IS NULL IN DIGEST IN DIGEST.CPP"); 
	}
    }
  else
    {
      Peptides[NbPeptides - 1].weight += get_weight(get_util_formula("H2O")) + peptide_charge_weight();
      Peptides[NbPeptides - 1].startOff = previ;
      Peptides[NbPeptides - 1].endOff = i - 1;
      Peptides[NbPeptides-1].nb_modif=NULL;
      Peptides[NbPeptides-1].modifications=NULL;
      Peptides[NbPeptides-1].equivalent_to_another=FALSE;
    }
}

peptide_t*
get_result_of_digestion(int* nb_peptides)
{
  (*nb_peptides)=NbPeptides;
  return Peptides;
}

peptide_t*
get_copie_of_digestion_result(int* nb_peptides)
{
  int i;
  peptide_t* copie;
  peptide_t* buffer;
  (*nb_peptides)=NbPeptides;
  copie=(peptide_t*)malloc(NbPeptides*sizeof(peptide_t));
  if(copie==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE COPY OF PEPTIDES OF THE DIGESTION",
	 	"COPIE IS NULL IN GET_COPIE_OF_DIGESTION_RESULT IN DIGEST.CPP"); 
    }
  for(i=0;i<NbPeptides;i++)
    {
      buffer=copy_peptide(&Peptides[i]);
      copie[i]=*buffer;
      free(buffer);
    }
  return copie;
}

void 
print_result_of_digestion(peptide_t* peptides,int nb_peptides)
{
  int i,nb;
  char* char_formula;
  formula_t*  formula;
  
  formula=get_formulae_of_peptides(&nb);
  
  for(i=0;i<nb_peptides;i++)
    {
      printf("Peptide %d\n",i+1);
      printf("Sequence : ");
      print_peptide_index(i);
      printf("\n");
      char_formula=formula_tochar(&formula[i]);
      printf("Formula : %s\n",char_formula);
      free(char_formula);
      printf("Weight : %f\n",peptides[i].weight);
      printf("Number of miss cleavage in this peptide : %d\n",peptides[i].nb_missed_cleavages);
      printf("This peptide is equivalent to another one : %s\n",(peptides[i].equivalent_to_another==TRUE)?"YES":"NO");
      printf("\n");
    }
  free_n_formula(formula,nb);
  printf("\n");
}

void 
fprint_result_of_digestion(FILE* file,peptide_t* peptides,int nb_peptides)
{
  int i,nb;
  char* char_formula;
  formula_t*  formula;
  
  formula=get_formulae_of_peptides(&nb);
  
  for(i=0;i<nb_peptides;i++)
    {
      fprintf(file,"Peptide %d\n",i+1);
      fprintf(file,"Sequence : ");
      fprint_peptide_index(file,i);
      fprintf(file,"\n");
      char_formula=formula_tochar(&formula[i]);
      fprintf(file,"Formula : %s\n",char_formula);
      free(char_formula);
      fprintf(file,"Weight : %f\n",peptides[i].weight);
      fprintf(file,"Number of miss cleavage in this peptide : %d\n",peptides[i].nb_missed_cleavages);
      fprintf(file,"This peptide is equivalent to another one : %s\n",(peptides[i].equivalent_to_another==TRUE)?"YES":"NO");
      fprintf(file,"\n");
    }
  free_n_formula(formula,nb);
  fprintf(file,"\n");
}

void 
fprint_result_of_digestion_table_format(FILE* file,peptide_t* peptides,int nb_peptides)
{
  int i,nb;
  char* char_formula;
  formula_t*  formula;

  formula=get_formulae_of_peptides(&nb);
  
  for(i=0;i<nb_peptides;i++)
    {
      fprintf(file,"Peptide\t%d\t%d\tPosition\t%d\t%d\t",
	      i+1,peptides[i].nb_missed_cleavages,(int)peptides[i].startOff,(int)peptides[i].endOff);
      fprint_peptide_index(file,i);
      fprintf(file,"\t");
      char_formula=formula_tochar(&formula[i]);
      fprintf(file,"Formula\t%s\t",char_formula);
      free(char_formula);
      fprintf(file,"Weight\t%f\t",peptides[i].weight);
      fprintf(file,"Equivalent\t%s\n\n",(peptides[i].equivalent_to_another==TRUE)?"YES":"NO");
    }
  
  free_n_formula(formula,nb);
  fprintf(file,"\n");
}
  
peptide_t*
copy_peptide(peptide_t* original)
{
  peptide_t* copy;
  int length,i,j;
  
  if(original==NULL)
    {
      error(USAGE_ERROR,"THE ORIGINAL PEPTIDE IS EMPTY, NO COPY AVALAIBLE",
	    "ORIGINAL IS NULL IN COPY_PEPTIDE IN DIGESTION.CPP");
    }
  if(original->weight==0)
    {
      error(USAGE_ERROR,"THE WEIGTH OF THE ORIGINAL PEPTIDE IS 0, NO COPY ALLOWED",
	    "ORIGINAL->WEIGHT EQUALS 0 IN COPY_PEPTIDE IN DIGESTION.CPP");
    }
  
  copy=(peptide_t*)malloc(sizeof(peptide_t));
  if(copy==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE COPY OF THE WANTED PEPTIDE",
	    "COPY IS NULL IN COPY_PEPTIDE IN DIGEST.CPP");
    }
  
  copy->startOff=original->startOff;
  copy->endOff=original->endOff;
  copy->weight=original->weight;
  copy->nb_missed_cleavages=original->nb_missed_cleavages;
  copy->equivalent_to_another=original->equivalent_to_another;

  if(original->nb_modif==NULL)
    {
      copy->nb_modif=NULL;
      copy->modifications=NULL;
    }
  else
    {
      length=original->endOff-original->startOff+1;
      copy->nb_modif=(int*)malloc(length*sizeof(int));
      if(copy->nb_modif==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION NUMBER OF THE PEPTIDE COPIE",
		"COPY->NB_MODIF IS NULL IN COPY_PEPTIDE IN DIGEST.CPP");
	}

      copy->modifications=(int**)malloc(length*sizeof(int*));
      
      if(copy->modifications==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION LIST OF THE PEPTIDE COPIE",
		"COPY->MODIFICATIONS IS NULL IN COPY_PEPTIDE IN DIGEST.CPP");
	}
      
      for(i=0;i<length;i++)
	{
	  copy->nb_modif[i]=original->nb_modif[i];
	  if(original->nb_modif[i]==0)
	    {
	      copy->modifications[i]=NULL;
	    }
	  else
	    {
	      copy->modifications[i]=(int*)malloc(original->nb_modif[i]*sizeof(int));
	      if(copy->modifications[i]==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A MODIFICATION OF THE MODIFICATION LIST OF THE PEPTIDE COPIE",
			"COPY->MODIFICATIONS[i] IS NULL IN COPY_PEPTIDE IN DIGEST.CPP");
		}

	      for(j=0;j<original->nb_modif[i];j++)
		{
		  copy->modifications[i][j]=original->modifications[i][j];
		}
	    }
	}
    }
  return copy;
}

peptide_t*
fusion_peptide(peptide_t* first,peptide_t* second)
{
  int length,i,j;
  peptide_t* fusioned_peptide;
  
  if((first==NULL)&&(second==NULL))
    {
      error(USAGE_ERROR,"THE TWO PEPTIDES ARE EMPTY, NO FUSION",
	    "FIRST AND SECOND ARE NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
    }
  if((first->weight==0) || (second->weight==0))
    {
      error(USAGE_ERROR,"THE TWO PEPTIDE WEIGTH EQUAL 0, NO FUSION",
	    "FIRST->WEIGHT AND SECOND->WEIGHT ARE NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
    }
  if((first==NULL)||(second==NULL))
    {
      if(first==NULL)
	{
	  return copy_peptide(second);
	}
      else
	{
	  return copy_peptide(first);
	}
    }
  if((first->weight==0)||(second->weight==0))
    {
      if(first->weight==0)
	{
	  return copy_peptide(second);
	}
      else
	{
	  return copy_peptide(first);
	}
    }
  
  fusioned_peptide=(peptide_t*)malloc(sizeof(peptide_t));
  if(fusioned_peptide==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"THE NEW PEPTIDE RESULT OF THE FUSION IS EMPTY",
	    "FUSIONED_PEPTIDE IS NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
    }
  if(first->endOff!=second->startOff-1)
    {
      error(USAGE_ERROR,"THE TWO PEPTIDES USED FOR THE FUSION ARE NOT CONTIGUOUS",
	    "FIRST->ENDOFF!=SECOND->STARTOFF IN FUSION_PEPTIDE IN DIGEST.CPP");
    }
  fusioned_peptide->startOff=first->startOff;
  fusioned_peptide->endOff=second->endOff;
  fusioned_peptide->equivalent_to_another=FALSE;
  fusioned_peptide->weight=first->weight+second->weight;
  fusioned_peptide->weight-=get_weight(get_util_formula("H2O")) + peptide_charge_weight(); /*fusion ==> deletion of the
											  OH at the end of the first and deletion 
											  of the H at the end of the second <=> H2O*/
  fusioned_peptide->nb_missed_cleavages=first->nb_missed_cleavages+second->nb_missed_cleavages+1; /*due to the fusion*/
  
  /*in this version (december 2005) there is no need to verify post-translational modification
   *at this level, only the procedure new_peptides_by_miss_cleavage called this procedure
   *but in order to (maybe) be used in another conditions, the post-trasnlational modifications are computed
   *here too if it is needed.*/
  if((first->nb_modif==NULL)&&(second->nb_modif==NULL))
    {
      fusioned_peptide->nb_modif=NULL;
      fusioned_peptide->modifications=NULL;
    }
  else
    {
      length=fusioned_peptide->endOff-fusioned_peptide->startOff+1;
      fusioned_peptide->nb_modif=(int*)malloc(length*sizeof(int));
      
      if(fusioned_peptide->nb_modif==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR FUSION PEPTIDE NUMBER OF MODIFICATIONS",
		"FUSIONED_PEPTIDE->NB_MODIF IS NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
	}
      
      fusioned_peptide->modifications=(int**)malloc(length*sizeof(int*));
      if(fusioned_peptide->modifications==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR FUSION PEPTIDE MODIFICATIONS",
		"FUSIONED_PEPTIDE->MODIFICATIONS IS NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
	}

      for(i=0;i<length;i++)
	{
	  fusioned_peptide->nb_modif=0;
	  fusioned_peptide->modifications[i]=NULL;
	}
      
      if(first->nb_modif!=NULL)
	{
	  length=first->endOff-first->startOff+1;
	  	  
	  for(i=0;i<length;i++)
	    {
	      fusioned_peptide->nb_modif[i]=first->nb_modif[i];
	      if(first->nb_modif[i]!=0)
		{
		  fusioned_peptide->modifications[i]=(int*)malloc(first->nb_modif[i]*sizeof(int));
		  if(fusioned_peptide->modifications[i]==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A FUSION PEPTIDE MODIFICATION",
			    "FUSIONED_PEPTIDE->MODIFICATIONS[i] IS NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
		    }
		  for(j=0;j<first->nb_modif[i];j++)
		    {
		      fusioned_peptide->modifications[i][j]=first->modifications[i][j];
		    }
		}
	    }
	}
      
      if(second->nb_modif!=NULL)
	{
	  length=second->endOff-second->startOff+1;
	  	  
	  for(i=first->endOff;i<length;i++)
	    {
	      fusioned_peptide->nb_modif[i]=first->nb_modif[i];
	      if(first->nb_modif[i]!=0)
		{
		  fusioned_peptide->modifications[i]=(int*)malloc(first->nb_modif[i]*sizeof(int));
		  if(fusioned_peptide->modifications[i]==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A FUSION PEPTIDE MODIFICATION",
			    "FUSIONED_PEPTIDE->MODIFICATIONS[i] IS NULL IN FUSION_PEPTIDE IN DIGEST.CPP");
		    }
		  for(j=0;j<first->nb_modif[i];j++)
		    {
		      fusioned_peptide->modifications[i][j]=first->modifications[i][j];
		    }
		}
	    }
	}
    }
  
  return fusioned_peptide;
}

/*!
  \fn void new_peptides_with_missed_cleavages(int missed_cleavage,int* nb_new_peptides_total)
  \brief Procedure which allows to compute the new peptides gained due to missed cleavages.
  \param missed_cleavage The number of missed cleavage.
  \param nb_new_peptides_total The total number of new peptides (modified by the procedure).*/
void
new_peptides_with_missed_cleavages(int missed_cleavage,int* nb_new_peptides_total)
{
  peptide_t* peptides_window;
  int* nb_fusioned_peptides;
  int i,j,limit;
  peptide_t* buffer;
  peptide_t* Peptides;
  buffer=NULL;
  peptides_window=(peptide_t*)malloc((missed_cleavage+1)*sizeof(peptide_t)); /*peptides_windows size proportionnal 
									     with the number of miss-cleavage*/
  if(peptides_window==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR PEPTIDE WINDOW FOR NEW PEPTIDES",
	    "PEPTIDES_WINDOW IS NULL IN NEW_PEPTIDES_BY_MISS_CLEAVAGE IN DIGEST.CPP");
    }
  for(i=0;i<=missed_cleavage;i++)
    {
      peptides_window[i].weight=0;
      peptides_window[i].nb_modif=NULL;
      peptides_window[i].modifications=NULL;
    }

  nb_fusioned_peptides=(int*)malloc((missed_cleavage+1)*sizeof(int));
  if(nb_fusioned_peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE NUMBER OF FUSIONED PEPTIDES",
	    "NB_FUSIONED_PEPTIDES IS NULL IN NEW_PEPTIDES_BY_MISS_CLEAVAGE IN DIGEST.CPP");
    }
  
  for(i=0;i<=missed_cleavage;i++)
    {
      nb_fusioned_peptides[i]=0;
    }
  
  for(i=0;i<NbPeptides;i++)
    {
      /*at the beginning ==> the peptide window is filled partially*/
      if(i<missed_cleavage)
	{
	  limit=i;
	}
      else
	{
	  limit=missed_cleavage;
	}
      for(j=0;j<=limit;j++)
	{
	  buffer=fusion_peptide(&peptides_window[j],&Peptides[i]);
	  peptides_window[j]=*buffer;
	  free(buffer);
	  nb_fusioned_peptides[j]++;
	  if(nb_fusioned_peptides[j]==(missed_cleavage+1))
	    {
	      Peptides=(peptide_t*)realloc(Peptides,((NbPeptides+(*nb_new_peptides_total)+1))*sizeof(peptide_t));
	      if(Peptides==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR PEPTIDES RESULT OF THE DIGESTION",
			"PEPTIDES IS NULL IN NEW_PEPTIDES_BY_MISS_CLEAVAGE IN DIGEST.CPP");
		}
	      buffer=copy_peptide(&peptides_window[j]);
	      Peptides[NbPeptides+(*nb_new_peptides_total)]=*buffer;
	      free(buffer);
	      peptides_window[j].weight=0;
	      free_peptide(&peptides_window[j]);
	      (*nb_new_peptides_total)++;
	      nb_fusioned_peptides[j]=0;
	    }
	}
    }
  
  for(i=0;i<(missed_cleavage+1);i++)
    {
      free_peptide(&peptides_window[i]);
    }
  free(peptides_window);
  free(nb_fusioned_peptides);
}
	      
void
real_digest (char *seq)
{
  int nb_new_peptides_total,i,length;
  nb_new_peptides_total=0;
  if(sequence!=NULL)
    {
      free(sequence);
    }
  
  length=strlen(seq);

  sequence=(char*)malloc((length+1)*sizeof(char));
  if(sequence==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR SAVING THE PROTEIN SEQUENCE",
	    "SEQUENCE IS NULL IN NEW_PEPTIDES_BY_MISS_CLEAVAGE IN DIGEST.CPP");
    }
  
  for(i=0;i<length;i++)
    {
      sequence[i]=toupper(seq[i]);;
    }

  sequence[i]='\0';
  
  digest();
  
  if(FULL_DIGESTION==TRUE)
    {
      nb_missed_cleavages=NbPeptides-1;
    }
  for(i=0;i<nb_missed_cleavages;i++)
    {
      new_peptides_with_missed_cleavages(i+1,&nb_new_peptides_total);
    }
  
  NbPeptides+=nb_new_peptides_total;

  compute_equivalent_peptides();

  if(get_number_of_activated_modifications()!=0)
    {
      compute_post_traductional_modifications_global();
    }
}

void 
activate_full_digestion(int activation)
{
  if((activation==TRUE)||(activation==FALSE))
    {
      FULL_DIGESTION=activation;
    }
  else
    {
      error(USAGE_ERROR,"THE VALUE FOR THE ACTIVATION OF THE FULL DIGESTION IS ODD",
	    "ACTIVATION HAS AN VALUE IN ACTIVATE_FULL_DIGESTION IN DIGEST.CPP");
    }
}

int
compare_peptides(const void* first,const void* second)
{
  peptide_t* frag1;
  peptide_t* frag2;
  frag1=(peptide_t*)first;
  frag2=(peptide_t*)second;
  if(frag1->weight<frag2->weight)
    {
      return -1;
    }
  else
    {
      if(frag1->weight==frag2->weight)
	{
	  return 0;
	}
      return 1;
    }
}

void 
sort_peptides()
{
  qsort(Peptides,NbPeptides,sizeof(peptide_t),compare_peptides);
}

void 
set_peptide_charge(const char* formula)
{
  if(peptide_charge_formula!=NULL)
    {
      free_formula(peptide_charge_formula);
    }
  peptide_charge_formula=read_formula(formula,get_element_table(),get_element_table_size());
}

double
peptide_charge_weight()
{
  if(peptide_charge_formula==NULL)
    {
      error(USAGE_ERROR,"THE PEPTIDE CHARGE FORMULA SEEMS TO BE EMPTY",
	    "FORMULA_PEPTID_CHARGE IS NULL IN WEIGHT_PEPTID_CHARGE IN DIGEST.CPP");
    }
  return get_weight(peptide_charge_formula);
}

void
default_peptide_charge()
{
  set_peptide_charge("H");
}


formula_t*
get_peptide_charge_formula()
{
  return peptide_charge_formula;
}

void
init_util_digestion()
{
  enztable = enzym_load(ENZFILENAME);
  default_peptide_charge();
}

void
set_used_enzyme(int chosen_enzyme)
{
  enzyme=chosen_enzyme;
}

void
free_util_digestion()
{
  int i;
  
  if(sequence!=NULL)
    {
      free(sequence);
    }

  free_enzym_table(enztable);
  free_formula(peptide_charge_formula);
  
  for(i=0;i<NbPeptides;i++)
    {
      free_peptide(&Peptides[i]);
    }
  free(Peptides);
}

void
set_nb_missed_cleavages(int missed_cleavage)
{
  nb_missed_cleavages=missed_cleavage;
}

formula_t* 
get_formulae_of_peptides(int* nb_peptides)
{
  int i,j,k,length;
  formula_t* peptides;
  formula_t* formula;
  aa_CF_t amino_acid;
  
  (*nb_peptides)=NbPeptides;
  peptides=(formula_t*)malloc(NbPeptides*sizeof(formula_t));
  
  if(peptides==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR PEPTIDES FORMULAE",
	    "PEPTIDES IS NULL IN GET_FORMULAE_OF_PEPTIDES IN DIGEST.CPP");
    }
  
  for(i=0;i<NbPeptides;i++)
    {
      length=Peptides[i].endOff-Peptides[i].startOff+1;
      formula=copy_formula(get_util_formula("H"));
      for(j=0;j<length;j++)
	{
	  amino_acid=get_amino_acid(sequence[j+Peptides[i].startOff]);
	  add_formula(formula,amino_acid.form);
	  add_formula(formula,get_util_formula("NHCHCO"));
	  if(Peptides[i].nb_modif!=NULL)
	    {
	      for(k=0;k<Peptides[i].nb_modif[j];k++)
		{
		  apply_modification(formula,Peptides[i].modifications[j][k]);
		}
	    }
	}
      add_formula(formula,get_util_formula("OH"));
      add_formula(formula,get_peptide_charge_formula());
      peptides[i]=*formula;
      free(formula);
    }
  return peptides;
}

int
get_nb_missed_cleavages()
{
  return nb_missed_cleavages;
}

int
get_activation_full_digest()
{
  return FULL_DIGESTION;
}

char*
get_used_enzyme()
{
  return enztable->enz[enzyme].name;
}

formula_t*
get_peptide_formula_from_index(int index)
{
  int i,j,length;
  formula_t* formula;
  aa_CF_t amino_acid;
  
  if((index<0)||(index>=NbPeptides))
    {
      error(USAGE_ERROR,"THE INDEX OF THE WANTED PEPTIDE IS STRANGE",
	    "INDEX HAS AN ODD VALUE IN GET_PEPTIDE_FORMULA_FROM_INDEX");
    }
  
  if(Peptides==NULL)
    {
      error(USAGE_ERROR,"THE PEPTIDES RESULT OF THE DIGESTION ARE EMPTY",
	    "PEPTIDES IS NULL IN GET_PEPTIDE_FORMULA_FROM_INDEX");
    }
  
  length=Peptides[index].endOff-Peptides[index].startOff+1;
  
  formula=copy_formula(get_util_formula("H"));
  for(i=0;i<length;i++)
    {
      amino_acid=get_amino_acid(sequence[Peptides[index].startOff+i]);
      add_formula(formula,amino_acid.form);
      add_formula(formula,get_util_formula("NHCHCO"));
      
      if(i==length-1)
	{
	  add_formula(formula,get_util_formula("OH"));
	  add_formula(formula,get_peptide_charge_formula());
	}
      
      if(Peptides[index].nb_modif!=NULL)
	{
	  for(j=0;j<Peptides[index].nb_modif[i];j++)
	    {
	      apply_modification(formula,Peptides[index].modifications[i][j]);
	    }
	}
    }
  
  return formula;
}

formula_t*
get_peptide_formula(peptide_t* peptide)
{
  return get_peptide_formula_from_another_protein(peptide,sequence);
}

formula_t*
get_peptide_formula_from_another_protein(peptide_t* peptide,char* protein_sequence)
{
  int i,j,length,size;
  formula_t* formula;
  aa_CF_t amino_acid;
  
  if(protein_sequence==NULL)
    {
      error(USAGE_ERROR,"THE SEQUENCE OF THE PROTEIN IS EMPTY",
	    "PROTEIN_SEQUENCE IS NULL IN GET_PEPTIDE_FORMULA_FROM_ANOTHER_PROTEIN IN DIGEST.CPP");
    }
      
  size=strlen(protein_sequence);
  length=peptide->endOff-peptide->startOff+1;
  
  if(peptide->endOff>size)
    {
      error(USAGE_ERROR,"IT SEEMS THAT THE PEPTIDES DO NOT CORRESPOND TO THE PROTEIN",
	    "PEPTIDE->ENDOFF>SIZE IS NULL IN GET_PEPTIDE_FORMULA_FROM_ANOTHER_PROTEIN IN DIGEST.CPP");
    }

  formula=copy_formula(get_util_formula("H"));
  for(i=0;i<length;i++)
    {
      amino_acid=get_amino_acid(protein_sequence[peptide->startOff+i]);
      add_formula(formula,amino_acid.form);
      add_formula(formula,get_util_formula("NHCHCO"));
      
      if(i==length-1)
	{
	  add_formula(formula,get_util_formula("OH"));
	  add_formula(formula,get_peptide_charge_formula());
	}

      if(peptide->nb_modif!=NULL)
	{
	  for(j=0;j<peptide->nb_modif[i];j++)
	    {
	      apply_modification(formula,peptide->modifications[i][j]);
	    }
	}
    }
   
  return formula;
}

void
free_peptide(peptide_t* peptide)
{
  int i,length;
  
  length=peptide->endOff-peptide->startOff+1;
  
  if(peptide->nb_modif!=NULL)
    {
      if(peptide->modifications==NULL)
	{
	  error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATE BECAUSE THE PEPTIDE MODIFICATIONS LIST IS EMPTY",
		"PEPTIDE->MODIFICATIONS IS NULL IN FREE_PEPTIDE IN DIGEST.CPP");
	}
      
      for(i=0;i<length;i++)
	{
	  if(peptide->nb_modif[i]!=0)
	    {
	      if(peptide->modifications[i]==NULL)
		{
		  error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATE BECAUSE A PEPTIDE MODIFICATION IS EMPTY",
			"PEPTIDE->MODIFICATIONS[i] IS NULL IN FREE_PEPTIDE IN DIGEST.CPP");
		}
	      free(peptide->modifications[i]);
	    }
	}
      
      free(peptide->modifications);
      free(peptide->nb_modif);
    }
}

void
add_peptide_modification(peptide_t* peptide, int amino_acid, int modif)
{
  int length,i;
  formula_t* formula;
  
  if(peptide==NULL)
    {
      error(USAGE_ERROR,"THE GIVEN PEPTIDE WHERE WE WANT TO ADD A MODIFICATION IS EMPTY",
	    "PEPTIDE IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
    }
  
  length=peptide->endOff-peptide->startOff+1;
  i=0;

  if((amino_acid<0)||(amino_acid>=length))
    {
      error(USAGE_ERROR,"THE AMINO ACID INDEX HAS A STRANGE VALUE",
	    "AMINO_ACID HAS AN ODD VALUE IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
    } 

  if((modif<0)||(modif>=get_number_of_activated_modifications()))
    {
      error(USAGE_ERROR,"THE WANTED MODIF HAS A STRANGE VALUE",
	    "MODIF HAS AN ODD VALUE IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
    }
  
  if(peptide->nb_modif==NULL)
    {
      peptide->nb_modif=(int*)malloc(length*sizeof(int));
      if(peptide->nb_modif==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE NUMBER OF MODIFICATIONS",
		"PEPTIDE->NB_MODIF IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
	}
      
      peptide->modifications=(int**)malloc(length*sizeof(int*));
      if(peptide->modifications==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE MODIFICATIONS",
		"PEPTIDE->MODIFICATIONS IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
	}

      for(i=0;i<length;i++)
	{
	  peptide->nb_modif[i]=0;
	  peptide->modifications[i]=NULL;
	}
    }
  
  peptide->nb_modif[amino_acid]++;
  
  if(peptide->modifications[amino_acid]==NULL)
    {
      peptide->modifications[amino_acid]=(int*)malloc(sizeof(int));
      if(peptide->modifications[amino_acid]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR A PEPTIDE MODIFICATION",
		"PEPTIDE->MODIFICATIONS[AMINO_ACID]IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
	}
    }
  else
    {
      peptide->modifications[amino_acid]=(int*)realloc(peptide->modifications[amino_acid],peptide->nb_modif[amino_acid]*sizeof(int));
      if(peptide->modifications[amino_acid]==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR A PEPTIDE MODIFICATION",
		"PEPTIDE->MODIFICATIONS[AMINO_ACID]IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
	}
    }
  peptide->modifications[amino_acid][peptide->nb_modif[amino_acid]-1]=modif;
  
  formula=get_formula_to_add(modif);
  if(formula!=NULL)
    {
      peptide->weight+=get_weight(formula);
    }

  formula=get_formula_to_sub(modif);
  if(formula!=NULL)
    {
      peptide->weight-=get_weight(formula);
    }
}

void
compute_post_traductional_modifications_global()
{
  int i,j,nb_new_peptides_total,nb_new_peptides;
  peptide_t* new_peptides;
  peptide_t* new_peptides_total;
  peptide_t* buffer;
  
  nb_new_peptides=nb_new_peptides_total=0;
  new_peptides=NULL;
  new_peptides_total=NULL;

  for(i=0;i<NbPeptides;i++)
    {
      new_peptides=compute_post_traductional_modifications_one_peptide(&Peptides[i], &nb_new_peptides);
      
      if(new_peptides!=NULL)
	{
	  if(nb_new_peptides_total==0)
	    {
	      new_peptides_total=(peptide_t*)malloc(nb_new_peptides*sizeof(peptide_t));
	      if(new_peptides_total==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE NEW PEPTIDES",
			"NEW_PEPTIDES_TOTAL IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
		}
	    }
	  else
	    {
	      new_peptides_total=(peptide_t*)realloc(new_peptides_total,(nb_new_peptides_total+nb_new_peptides)*sizeof(peptide_t));
	      if(new_peptides_total==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE NEW PEPTIDES",
			"NEW_PEPTIDES_TOTAL IS NULL IN ADD_PEPTIDE_MODIFICATION IN DIGEST.CPP");
		}
	    }
	  
	  for(j=0;j<nb_new_peptides;j++)
	    {
	      buffer=copy_peptide(&new_peptides[j]);
	      new_peptides_total[nb_new_peptides_total+j]=*buffer;
	      free(buffer);
	      free_peptide(&new_peptides[j]);
	    }
	  free(new_peptides);
	  
	  nb_new_peptides_total+=nb_new_peptides;
	}
    }

  for(i=0;i<NbPeptides;i++)
    {
      free_peptide(&Peptides[i]);
    }
  free(Peptides);
  
  Peptides=new_peptides_total;
  NbPeptides=nb_new_peptides_total;
  
}

peptide_t*
compute_post_traductional_modifications_one_peptide(peptide_t* peptide, int* nb_new)
{
  int length,i,j,k,nb_modifications,partial_nb_new,variable_modifications;
  peptide_t* new_peptides;
  peptide_t* buffer;
  double previous_weight;
  
  previous_weight=-1.0;

  variable_modifications=FALSE;

  //security verification
  if(peptide==NULL)
    {
      error(USAGE_ERROR,"THE GIVEN PEPTIDE FOR THE POST-TRADUCTIONAL COMPUTATION IS EMPTY",
	    "PEPTIDE IS NULL IN COMPUTE_POST_TRADUTIONAL_MODIFICATIONS_ONE_PEPTIDE IN DIGEST.CPP");
    }

  //security verification
  if(sequence==NULL)
    {
      error(USAGE_ERROR,"THE PROTEIN SEQUENCE IS EMPTY",
	    "SEQUENCE IS NULL IN COMPUTE_POST_TRADUTIONAL_MODIFICATIONS_ONE_PEPTIDE IN DIGEST.CPP");
    }

  new_peptides=NULL;
  length=peptide->endOff-peptide->startOff+1;
  nb_modifications=get_number_of_activated_modifications();
  (*nb_new)=0;

  if(maximum_peptide_length!=0)
    {
      if(length>maximum_peptide_length)
	{
	  return new_peptides;
	}
    }

  //at the minimum, there is the original peptide
  (*nb_new)++;
  new_peptides=copy_peptide(peptide);

  //security verification
  if(nb_modifications<=0)
    {
      error(USAGE_ERROR,"THE NUMBER OF MODIFICATIONS IS STRANGE",
	    "NB_MODIFICATIONS HAS AN ODD VALUE IN COMPUTE_POST_TRADUTIONAL_MODIFICATIONS_ONE_PEPTIDE IN DIGEST.CPP");
    }
  
  //parsing of all the peptide sequence
  for(i=0;i<length;i++)
    {
      //parsing of all the activated modifications
      for(j=0;j<nb_modifications;j++)
	{
	  //the current amino acid (i) can have the current modification (j) ? 
	  if(can_be_used_on_for_digestion(j,toupper(sequence[i+peptide->startOff]),i,length,
					  (peptide->startOff==0)?TRUE:FALSE)==TRUE)
	    {
	      //first case : FIXE modification
	      if(get_modification_type(j)==FIXED)
		{
		  //all the new peptides must have the modification
		  for(k=0;k<(*nb_new);k++)
		    {
		      add_peptide_modification(&new_peptides[k],i,j);
		    }    
		}
	      else
		{
		  variable_modifications=TRUE;

		  //we have to parse all the current new peptides (without modify them !!!) and 
		  //add the copy of each of them with the modification
		  //from n new peptides, we arrive to 2n new peptides
		  partial_nb_new=0;
		  
		  //we add a new peptide at the end
		  //in total, we had (*nb_new) peptides ==> so the total number is *2
		  new_peptides=(peptide_t*)realloc(new_peptides,(2*(*nb_new))*sizeof(peptide_t));
		  if(new_peptides==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE NEW PEPTIDES",
			    "NEW_PEPTIDES IS NULL IN COMPUTE_POST_TRADUTIONAL_MODIFICATIONS_ONE_PEPTIDE IN DIGEST.CPP");
		    }

		  for(k=0;k<(*nb_new);k++)
		    {
		    
		      buffer=copy_peptide(&new_peptides[k]);
		      new_peptides[(*nb_new)+partial_nb_new]=*buffer;
		      free(buffer);
		      
		      add_peptide_modification(&new_peptides[(*nb_new)+partial_nb_new],i,j);
		      
		      partial_nb_new++;
		    }
		  
		  //security verification
		  if((partial_nb_new+(*nb_new))!=2*(*nb_new))
		    {
		      error(EXECUTION_ERROR,"THE NUMBER OF GAINED PEPTIDES IS INCORRECT, PROGRAM STOPS",
			    "PARTILA_NB_NEW + NEW PEPTIDES MUST BE EQUAL TO 2*NEW PEPTIDES IN COMPUTE_POST_TRADUTIONAL_MODIFICATIONS_ONE_PEPTIDE IN DIGEST.CPP");
		    }
		  
		  (*nb_new)+=partial_nb_new;
		}
	    }
	}
    }

  if(variable_modifications==TRUE)
    {
      qsort(new_peptides,(*nb_new),sizeof(peptide_t),compare_peptides);
      for(i=0;i<(*nb_new);i++)
	{
	  if(new_peptides[i].weight!=previous_weight)
	    {
	      previous_weight=new_peptides[i].weight;
	    }
	  else
	    {
	      new_peptides[i].equivalent_to_another=TRUE;
	    }
	}
    }
  return new_peptides;
}

char*
get_peptide_sequence(int index)
{
  int i,j,shift,length,modif_length;
  char* peptide;

  if((index<0)||(index>=NbPeptides))
    {
      error(USAGE_ERROR,"A WANTED PEPTIDE DOES NOT EXIST",
	    "INDEX HAS AN ODD VALUE IN GET_PEPTIDE_SEQUENCE IN DIGEST.CPP");
    }

  length=Peptides[index].endOff-Peptides[index].startOff+1;

  peptide=(char*)malloc(length*sizeof(char));
  if(peptide==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE PEPTIDE SEQUENCE",
	    "PEPTIDE IS NULL IN GET_PEPTIDE_SEQUENCE IN DIGEST.CPP");
    }
  
  shift=0;
  for(i=0;i<length;i++)
    {
      peptide[i+shift]=sequence[i+Peptides[index].startOff];
      if(Peptides[index].nb_modif!=NULL)
	{
	  for(j=0;j<Peptides[index].nb_modif[i];j++)
	    {
	      modif_length=strlen(get_activated_modification_symbol(Peptides[index].modifications[i][j]));

	      peptide=(char*)realloc(peptide,(length+shift+2+modif_length)*sizeof(char));
	      if(peptide==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE PEPTIDE SEQUENCE",
			"PEPTIDE IS NULL IN GET_PEPTIDE_SEQUENCE IN DIGEST.CPP");
		}
	      shift++;
	      peptide[i+shift]='(';
	      shift++;
	      strncpy(peptide+i+shift,get_activated_modification_symbol(Peptides[index].modifications[i][j]),modif_length);
	      shift+=modif_length;
	      peptide[i+shift]=')';
	    }
	}
    }
  peptide=(char*)realloc(peptide,(length+shift+1)*sizeof(char));
  if(peptide==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE PEPTIDE SEQUENCE",
	    "PEPTIDE IS NULL IN GET_PEPTIDE_SEQUENCE IN DIGEST.CPP");
    }
  peptide[length+shift]='\0';
  return peptide;
}

void
print_peptide(peptide_t* peptide)
{
  int i,j,length;
  
  if(peptide==NULL)
    {
      error(USAGE_ERROR,"THE PEPTIDE TO PRINT IS EMPTY",
	    "PEPTIDE IS NULL IN PRINT_PEPTIDE IN DIGEST.CPP");
    }

  length=peptide->endOff-peptide->startOff+1;

  for(i=0;i<length;i++)
    {
      printf("%c",sequence[i+peptide->startOff]);
      if(peptide->nb_modif!=NULL)
	{
	  for(j=0;j<peptide->nb_modif[i];j++)
	    {
	      printf("(%s)",get_activated_modification_symbol(peptide->modifications[i][j]));
	    }
	}
    }
}

void
print_peptide_index(int index)
{
  if((index<0)||(index>=NbPeptides))
    {
      error(USAGE_ERROR,"THE INDEX OF THE WANTED PEPTIDE TO PRINT IS STRANGE",
	    "INDEX HAS AN ODD VALUE IN PRINT_PEPTIDE_INDEX IN DIGEST.CPP");
    }
  print_peptide(&Peptides[index]);
}

void
fprint_peptide(FILE* file,peptide_t* peptide)
{
  int i,j,length;
  
  if(peptide==NULL)
    {
      error(USAGE_ERROR,"THE PEPTIDE TO PRINT IS EMPTY",
	    "PEPTIDE IS NULL IN FPRINT_PEPTIDE IN DIGEST.CPP");
    }

  length=peptide->endOff-peptide->startOff+1;

  for(i=0;i<length;i++)
    {
      fprintf(file,"%c",sequence[i+peptide->startOff]);
      if(peptide->nb_modif!=NULL)
	{
	  for(j=0;j<peptide->nb_modif[i];j++)
	    {
	      fprintf(file,"(%s)",get_activated_modification_symbol(peptide->modifications[i][j]));
	    }
	}
    }
}

void
fprint_peptide_index(FILE* file,int index)
{
  if((index<0)||(index>=NbPeptides))
    {
      error(USAGE_ERROR,"THE INDEX OF THE WANTED IS STRANGE",
	    "INDEX HAS AN ODD VALUE IN FPRINT_PEPTIDE_INDEX IN DIGEST.CPP");
    }
  fprint_peptide(file,&Peptides[index]);
}

int
get_peptide_length_at_index(int index)
{
  if((index<0)||(index>=NbPeptides))
    {
      printf("USAGE ERROR IN GET_PEPTIDE_LENGTH_AT_INDEX IN DIGEST.CPP\n");
      printf("INDEX HAS AN ODD VALUE %d\n",index);
      exit(EXIT_FAILURE);
    }
  return Peptides[index].endOff-Peptides[index].startOff+1;
}

int 
is_equivalent_to_another(int index)
{
  if((index<0)||(index>=NbPeptides))
    {
      printf("USAGE ERROR IN IS_EQUIVALENT_TO_ANOTHER IN DIGEST.CPP\n");
      printf("INDEX HAS AN ODD VALUE %d\n",index);
      exit(EXIT_FAILURE);
    }
  return Peptides[index].equivalent_to_another;
}

void 
set_maximum_peptide_length(int new_value)
{
  if(new_value<0)
    {
      error(USAGE_ERROR,"THE NEW VALUE IS ODD FOR THE PEPTIDE MAXIMUM LENGTH",
	    "NEW_VALUE HAS A NEGATIVE VALUE IN SET_MAXIMUM_PEPTIDE_LENGTH IN DIGEST.CPP");
    }
  
  maximum_peptide_length=new_value;
}

int
get_maximum_peptide_length()
{
  return maximum_peptide_length;
}

void
compute_equivalent_peptides()
{
  unsigned int peptide_content_1[26], peptide_content_2[26];
  unsigned int i, j, k, size, length, count;

  int equals;

  char *peptide_sequence_1, *peptide_sequence_2;

  if(Peptides==NULL)
    {
      error(USAGE_ERROR,"THE EQUIVALENT PEPTIDES CAN NOT COMPUTED, NO DIGESTION ALREADY COMPUTED",
	    "PEPTIDES IS NULL COMPUTE_EQUIVALENT_PEPTIDES IN DIGEST.CPP");
    }

  i=j=k=size=length=0;

  peptide_sequence_1=peptide_sequence_2=NULL;

  for(i=0;(int)i<NbPeptides-2;i++)
    {
      peptide_sequence_1=get_peptide_sequence(i);

      //printf("%d\n",i);

      //printf("%d of size %d = %s\n", i+1, strlen(peptide_sequence_1),peptide_sequence_1);

      if(Peptides[i].equivalent_to_another==FALSE)
	{
	  for(j=0;j<26;j++)
	    {
	      peptide_content_1[j]=0;
	    }

	  size=Peptides[i].endOff-Peptides[i].startOff+1;

	  if(size!=strlen(peptide_sequence_1))
	    {
	      error(EXECUTION_ERROR,"A PEPTIDE SEQUENCE SIZE DOES NOT CORRESPOND TO THE LOCATION BOUND DIFFERENCE",
		    "LENGTH IS NOT EQUAL TO PEPTIDE_SEQUENCE_1 IN COMPUTE_EQUIVALENT_PEPTIDES IN DIGEST.CPP");
	    }

	  for(j=0;j<size;j++)
	    {
	      //printf("%c %d\n",peptide_sequence_1[j],peptide_sequence_1[j]-'A');
	      peptide_content_1[peptide_sequence_1[j]-'A']++;
	    }
	  
	  for(j=i+1;(int)j<NbPeptides-1;j++)
	    {
	      //printf("\t%d\n",j);
	      length=Peptides[j].endOff-Peptides[j].startOff+1;
	      if( (Peptides[j].equivalent_to_another==FALSE) && (length==size ) )
		{
		  //printf("\t\tcomputation");
		  peptide_sequence_2=get_peptide_sequence(j);

		  if(length!=strlen(peptide_sequence_2))
		    {
		      error(EXECUTION_ERROR,"A PEPTIDE SEQUENCE SIZE DOES NOT CORRESPOND TO THE LOCATION BOUND DIFFERENCE",
			    "LENGTH IS NOT EQUAL TO PEPTIDE_SEQUENCE_2 IN COMPUTE_EQUIVALENT_PEPTIDES IN DIGEST.CPP");
		    }

		  for(k=0;k<26;k++)
		    {
		      //printf("%c %d\n",peptide_sequence_2[k], peptide_sequence_2[k]-'A');
		      peptide_content_2[k]=0;
		    }
		  
		  //printf("%d of size %d = %s\n", j+1, strlen(peptide_sequence_2),peptide_sequence_2);
		
		  for(k=0;k<length;k++)
		    {
		      //printf("%c %d\n",peptide_sequence_2[k], peptide_sequence_2[k]-'A');
		      peptide_content_2[peptide_sequence_2[k]-'A']++;
		    }
		  
		  k=count=0;
		  equals=TRUE;
		  while( (k<26) && (equals==TRUE) && (count<length) )
		    {
		      //printf("S2[%c] = %d, S1[%c] = %d\n",(char)(k+'A'),peptide_content_2[k], (char)(k+'A'),peptide_content_1[k]);
		      if(peptide_content_1[k]!=peptide_content_2[k])
			{
			  equals=FALSE;
			}
		      else
			{
			  count+=peptide_content_1[k];
			}
		      k++;
		    }

		  /*if(equals==TRUE)
		    {*/
		  Peptides[j].equivalent_to_another=equals;
		  /*}*/
		  
		  //printf("%s equivalent to %s = %s\n",peptide_sequence_2, peptide_sequence_1,Peptides[j].equivalent_to_another==TRUE?"TRUE":"FALSE");
		  
		  //printf("\n");
		  free(peptide_sequence_2);
		}
	    }
	}
      free(peptide_sequence_1);
    }
}
