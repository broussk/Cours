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
  \file modifications_for_digestion.cpp
  \author Jean-Charles BOISSON (2006-2008).
  \brief Implementation of the methods defined in modifications_for_digestion.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "modifications_for_digestion.h"

/*!
  \var int nb_modifications
  \brief The total number of activated modifications.*/
int nb_modifications=0;

/*!
  \var post_translational_modification_t* modifications
  \brief The activated post-translational modifications.*/
post_translational_modification_t* modifications=NULL;


void
print_modification_configuration()
{
  int i;
  printf("\t\tModifications configuration:\n");
  for(i=0;i<nb_modifications;i++)
    {
      printf("\t\t\t%s ==> %s\n",get_modification_name(modifications[i].modification),
	     modifications[i].type==FIXED?"FIXED":"VARIABLE");
    }
}

void
fprint_modification_configuration(FILE* file)
{
  int i;
  fprintf(file,"\t\tModifications configuration:\n");
  for(i=0;i<nb_modifications;i++)
    {
      fprintf(file,"\t\t\t%s ==> %s\n",get_modification_name(modifications[i].modification),
	     modifications[i].type==FIXED?"FIXED":"VARIABLE");
    }
}

void
fprint_xml_modification_configuration(FILE* file)
{
  int i;
  for(i=0;i<nb_modifications;i++)
    {
      fprintf(file,"\t\t\t<modification%d>%s ==> %s</modification%d>\n",i+1,get_modification_name(modifications[i].modification),
	      modifications[i].type==FIXED?"FIXED":"VARIABLE",i+1);
    }
}


void
load_modification_configuration(char* configuration)
{
  int lenght,i,j;
  char* modif;
  
  lenght=strlen(configuration);
  modif=NULL;
  j=0;
  
  for(i=0;i<lenght;i++)
    {
      if(isalpha(configuration[i])!=FALSE)
	{
	  if(modif==NULL)
	    {
	      error(USAGE_ERROR,"THE CONFIGURATION FOR THE MODIFICATIONS HAS A BAD FORMAT",
		    "MODIF IS NULL IN LOAD_MODIFICATION_CONFIGURATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
	    }
	  else
	    {
	      modif=(char*)realloc(modif,(j+1)*sizeof(char));
	      if(modif==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR CURRENT MODIFICATION",
			"MODIF IS NULL LOAD_MODIFICATION_CONFIGURATION IN MODIFICATION_FOR_DIGESTION.CPP");
		}
	      modif[j]='\0';
	      j=0;

	      if((configuration[i]=='F')||(configuration[i]=='f'))
		{
		  add_modification(FIXED,atoi(modif));
		}
	      else  if((configuration[i]=='V')||(configuration[i]=='v'))
		{
		  add_modification(VARIABLE,atoi(modif));
		}
	      else
		{
		  error(USAGE_ERROR,"THE CONFIGURATION FOR THE MODIFICATIONS HAS A BAD FORMAT",
			"THE MODIF HAVE TO 'F' FOR FIXED OR 'V' for VARIABLE IN LOAD_MODIFICATION_CONFIGURATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
		}
	      free(modif);
	      modif=NULL;
	    }
	}
      else
	{
	  if(isdigit(configuration[i])==FALSE)
	    {
	      error(USAGE_ERROR,"THE CONFIGURATION FOR THE MODIFICATIONS HAS A BAD FORMAT",
		    "DIGIT WAITED BUT NOT GAINED IN LOAD_MODIFICATION_CONFIGURATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
	    }
	  else
	    {
	      if(j==0)
		{
		  modif=(char*)malloc(sizeof(char));
		  if(modif==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR CURRENT MODIFICATION",
			    "MODIF IS NULL LOAD_MODIFICATION_CONFIGURATION IN MODIFICATION_FOR_DIGESTION.CPP");
		    }
		}
	      else
		{
		  modif=(char*)realloc(modif,(j+1)*sizeof(char));
		  if(modif==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR CURRENT MODIFICATION",
			    "MODIF IS NULL LOAD_MODIFICATION_CONFIGURATION IN MODIFICATION_FOR_DIGESTION.CPP");
		    }
		}
	      modif[j]=configuration[i];
	      j++;
	    }
	}
    }
  
  if(modif!=NULL)
    {
      error(USAGE_ERROR,"THE CONFIGURATION FOR THE MODIFICATIONS HAS A BAD FORMAT",
	    "MODIFICATION TYPE (F OR V) MISSED IN LOAD_MODIFICATION_CONFIGURATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
}


void
add_modification(int type,int id)
{
  int i,already_added;/*,value;*/
  
  if((type!=FIXED)&&(type!=VARIABLE))
    {
      error(USAGE_ERROR,"THE TYPE OF THE WANTED MODIFICATION IS NOT CORRECT",
	    "TYPE MUST BE FIXE OR VARIABLE IN ADD_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  
  //because id is a natural value, 1 for the first, etc...
  id--;

  if((id<0)&&(id>=get_total_number_of_modifications()))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN ADD_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  
  already_added=FALSE;
  i=0;
  while((i<nb_modifications)&&(already_added==FALSE))
    {
      if(modifications[i].modification==id)
	{
	  already_added=TRUE;
	  /*value=modifications[i].type;*/
	}
      i++;
    }
  
  if(already_added==TRUE)
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION HAS BEEN ALREADY ADDED",
	    "A MODIFICATION CAN NOT BE ADDED TWO TIMES IN ADD_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  
  if(nb_modifications==0)
    {
      modifications=(post_translational_modification_t*)malloc(sizeof(post_translational_modification_t));
      if(modifications==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATON TABLE",
		"MODIFICATIONS IS NULL IN ADD_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
	}
    }
  else
    {
      modifications=(post_translational_modification_t*)realloc(modifications,
							       (nb_modifications+1)*sizeof(post_translational_modification_t));
      if(modifications==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE MODIFICATON TABLE",
		"MODIFICATIONS IS NULL IN ADD_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
	}
    }
  
  modifications[nb_modifications].type=type;
  modifications[nb_modifications].modification=id;
  
  nb_modifications++;
}
  
void
free_activated_modification()
{
  if(nb_modifications!=0)
    {
      free(modifications);
    }
}

int
get_number_of_activated_modifications()
{
  return nb_modifications;
}

int
can_be_used_on_for_digestion(int modif,char amino_acid,int place,int size,int first)
{
  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN CAN_BE_USED_ON_FOR_DIGESTION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  return can_be_used_on(modifications[modif].modification,amino_acid,place,size,first);
}

formula_t*
get_formula_to_add(int modif)
{
  formula_t* formula;
  
  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN GET_FORMULA_TO_ADD IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }

  formula=get_modification_formula_to_add(modifications[modif].modification);
  
  if(formula->nb_comp!=0)
    {
      return formula;
    }
  
  return NULL;
}

formula_t*
get_formula_to_sub(int modif)
{
  formula_t* formula;
  
  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN GET_FORMULA_TO_SUB IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  
  formula=get_modification_formula_to_sub(modifications[modif].modification);

  if(formula->nb_comp!=0)
    {
      return formula;
    }
  
  return NULL;
} 

int
get_modification_type(int modif)
{
  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN GET_MODIFICATION_TYPE IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  return modifications[modif].type;
}

void
apply_modification(formula_t* formula,int modif)
{
  formula_t* modification_formula;

  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN APPLY_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }

  modification_formula=get_formula_to_add(modif);
  if(modification_formula!=NULL)
    {
      add_formula(formula,modification_formula);
    }

  modification_formula=get_formula_to_sub(modif);
  if(modification_formula!=NULL)
    {
      if((sub_formula(formula,modification_formula))==FALSE)
	{
	  error(EXECUTION_ERROR,"SUB THE MODIFICATION OF THE FORMULA IS IMPOSSIBLE",
		"THE CALL TO SUB_FORMULA HAS FAILED IN APPLY_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION");
	}
    }

}

char* 
get_activated_modification_symbol(int modif)
{
   if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN GET_ACTIVATED_MODIFICATION_SYMBOL IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
   return get_modification_symbol(modifications[modif].modification);
}

char*
get_activated_modification_name(int modif)
{
  if((modif<0)||(modif>=nb_modifications))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN GET_ACTIVATED_MODIFICATION_NAME IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }
  return get_modification_name(modifications[modif].modification);
}

void
digestion_modification_initialization(const char* configuration)
{
  int lenght,i,j;
  char* modif;
  
  modif=NULL;
  j=0;

  if(configuration==NULL)
    {
      error(USAGE_ERROR,"THE GIVEN CONFIGURATION FOR THE MODIFICATION FOR THE DIGESTIONT IS EMPTY",
	    "CONFIGURATION IS NULL IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }

  if(strcmp(configuration,"NONE")!=0)
    {
      lenght=strlen(configuration);
      
      for(i=0;i<lenght;i++)
	{
	  if((configuration[i]=='V')||(configuration[i]=='F'))
	    {
	      if(modif==NULL)
		{
		  error(USAGE_ERROR,"THE GIVEN CONFIGURATION FOR THE MODIFICATION FOR THE DIGESTIONT IS NOT CORRECT",
			"MODIF IS NULL IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
		}
	      else
		{
		  modif=(char*)realloc(modif,(j+1)*sizeof(char));
		  if(modif==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILRED FOR THE MODIFICATION INDEX",
			"MODIF IS NULL IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
		    }
		  modif[j]='\0';
		  
		  j=0;
		  
		  if(configuration[i]=='V')
		    {
		      add_modification(VARIABLE,atoi(modif));
		    }
		  else
		    {
		      add_modification(FIXED,atoi(modif));
		    }
		  
		  free(modif);
		  modif=NULL;
		}
	    }
	  else
	    {
	      if(isdigit(configuration[i])==FALSE)
		{
		  error(USAGE_ERROR,"THE GIVEN CONFIGURATION FOR THE MODIFICATION FOR THE DIGESTIONT IS NOT CORRECT",
			"ISDIGIT(CONFIGURATION[I]) RETURNS FALSE IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
		}
	      else
		{
		  if(j==0)
		    {
		      modif=(char*)malloc(sizeof(char));
		      if(modif==NULL)
			{
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILRED FOR THE MODIFICATION INDEX",
				"MODIF IS NULL IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
			}
		    }
		  else
		    {
		      modif=(char*)realloc(modif,(j+1)*sizeof(char));
		      if(modif==NULL)
			{
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILRED FOR THE MODIFICATION INDEX",
				"MODIF IS NULL IN DIGESTION_MODIFICATION_INTIALIZATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
			}
		    }
		  modif[j]=configuration[i];
		  j++;
		}
	    }
	}
    }
}

int
get_global_modification_index(int modif)
{
   if((modif<0)||(modif>=nb_modifications))
     {
       error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	     "THE MODIFICATION HAS AN ODD VALUE IN GET_GLOBAL_MODIFICATION_INDEX IN MODIFICATIONS_FOR_DIGESTION.CPP");
     }
   return modifications[modif].modification;
}

