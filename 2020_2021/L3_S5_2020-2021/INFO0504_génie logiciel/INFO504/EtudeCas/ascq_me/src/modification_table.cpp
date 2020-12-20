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
  \file modification_table.cpp
  \author Jean-Charles BOISSON (2006-2008).
  \brief Implementation of the methods defined in modification_table.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "modification_table.h"

/*!
  \var int nb_total_modif
  \brief The total number of modifications.*/
int nb_total_modif=0;

/*!
  \var char** modifications_name
  \brief The names of all modifications.*/
char** modifications_name=NULL;

/*!
  \var char** symbol
  \brief The symbols of all modifications.*/
char** symbol=NULL;

/*!
  \var int* side
  \brief The application side of each modifications.*/
int* side=NULL; 

/*!
  \var char** modifications_on_amino_acids
  \brief The amino acids where the modifications can be put.*/
char** modifications_on_amino_acids=NULL;

/*!
  \var formula_t* formula_to_add
  \brief For each modification, formula to add to apply it.*/
formula_t* formula_to_add=NULL;

/*!
  \var formula_t* formula_to_sub
  \brief For each modification, formula to sub to apply it.*/
formula_t* formula_to_sub=NULL;

void
free_all_modifications()
{
  int i;
  
  for(i=0;i<nb_total_modif;i++)
    {
      free(modifications_name[i]);
      free(symbol[i]);
      free(modifications_on_amino_acids[i]);
            
      if(formula_to_add[i].nb_comp!=0)
	{
	  free_composition(formula_to_add[i].comps,formula_to_add[i].nb_comp);
	}
      
      if(formula_to_sub[i].nb_comp!=0)
	{
	  free_composition(formula_to_sub[i].comps,formula_to_sub[i].nb_comp);
	}
    }

  if(nb_total_modif!=0)
    {
      free(modifications_name);
      free(symbol);
      free(side);
      free(modifications_on_amino_acids);
      free(formula_to_sub);
      free(formula_to_add);
    }
}

formula_t*
get_modification_formula_to_add(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_FORMULA_TO_ADD IN MODIFICATIONS_TABLE.CPP");
    }
  return &formula_to_add[modif];
}


formula_t*
get_modification_formula_to_sub(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_FORMULA_TO_SUB IN MODIFICATIONS_TABLE.CPP");
    }
  return &formula_to_sub[modif];
}

char*
get_modification_symbol(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_SYMBOL IN MODIFICATIONS_TABLE.CPP");
    }
  return symbol[modif];
}

char*
get_modification_amino_acids(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_AMINO_ACIDS IN MODIFICATIONS_TABLE.CPP");
    }
  return modifications_on_amino_acids[modif];
}
  
int
get_total_number_of_modifications()
{
  return nb_total_modif;
}

char*
get_modification_name(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_NAME IN MODIFICATIONS_TABLE.CPP");
    }
  return modifications_name[modif];
}

int
get_modification_side(int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN GET_MODIFICATION_SIDE IN MODIFICATIONS_TABLE.CPP");
    }
  return side[modif];
}

int
can_be_used_on(int modif,char amino_acid,int place,int size,int first)
{
  int i,length,good_side;
  
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIF IS NOT CORRECT",
	    "MODIF HAS AN ODD VALUE IN CAN_BE_USED_ON IN MODIFICATIONS_TABLE.CPP");
    }
  
  if(modifications_on_amino_acids[modif]==NULL)
    {
      if(side[modif]==C_TERM)
	{
	  return place==(size-1)?TRUE:FALSE;
	}
      else if(side[modif]==N_TERM)
	{
	  return place==0?TRUE:FALSE;
	}
      else if(side[modif]==BOTH_TERM)
	{
	  return ((place==0)||(place==(size-1)))?TRUE:FALSE;
	}
      else if(side[modif]==PROTEIN)
	{
	  return ((place==0)&&(first==TRUE))?TRUE:FALSE;
	}
      else
	{
	  error(USAGE_ERROR,"THE WANTED MODIF CAN BE PUT ON ALL AMINO ACID, TOO DANGEROUS FOR THE EXECUTION TIME",
		"PROBLEM FOR THE DESCRIPTION OF THE MODIF IN CAN_BE_USED IN MODIFICATIONS_TABLE.CPP");
	  //only for the compilation, the error stops the program.
	  return EXIT_FAILURE;
	}
    }
  else
    {
      length=strlen(modifications_on_amino_acids[modif]);
      if(side[modif]==C_TERM)
	{
	  good_side=(place==(size-1)?TRUE:FALSE);
	}
      else if(side[modif]==N_TERM)
	{
	  good_side=(place==0?TRUE:FALSE);
	}
      else if(side[modif]==BOTH_TERM)
	{
	  good_side=(((place==0)||(place==(size-1)))?TRUE:FALSE);
	}
      else if(side[modif]==PROTEIN)
	{
	  good_side=(((place==0)&&(first==TRUE))?TRUE:FALSE);
	}
      else
	{
	  good_side=FALSE;
	} 

      if(side[modif]!=INDEPENDANT_TERM)
	{
	  if(good_side==FALSE)
	    {
	      return FALSE;
	    }
	}
	 
      i=-1;
      do
	{
	  i++;
	}
      while((i<length)&&(modifications_on_amino_acids[modif][i]!=amino_acid));
      
      return i==length?FALSE:TRUE;
    }
}

void
load_modifications(const char* file)
{
  FILE* read_file;
  int read,i;
  char buffer[50];
  char* special_buffer;
  formula_t* formula;
  
  read=1;
  i=0;
  
  read_file=fopen(file,"r");
  if(read_file==NULL)
    {
      error(IO_ERROR,"THE MODIFICATION FILE IS NOT CORRECTLY OPENED",
	    "READ_FILE IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
    }
  
  while(read!=EOF)
    {
      read=jump_commentaries(read_file,'#');
      if(read!=EOF)
	{
	  //reading of the index
	  read=fscanf(read_file,"%s",buffer);
	  //nothing to do
	}
      if(read!=EOF)
	{
	  //reading of the full modification name
	  special_buffer=read_until(read_file,' ');
	  
	  if(i==0)
	    {
	      modifications_name=(char**)malloc(sizeof(char*));
	      if(modifications_name==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION NAME TABLE",
			"MODIFICATIONS_NAME IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  else
	    {
	      modifications_name=(char**)realloc(modifications_name,(i+1)*sizeof(char*));
	      if(modifications_name==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE MODIFICATION NAME TABLE",
			"MODIFICATIONS_NAME IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  if(special_buffer!=NULL)
	    {
	      modifications_name[i]=(char*)malloc((strlen(special_buffer)+1)*sizeof(char));
	      if(modifications_name[i]==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION NAME",
			"MODIFICATIONS_NAME[i] IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	      strcpy(modifications_name[i],special_buffer);
	      free(special_buffer);
	    }
	  else
	    {
	      read=EOF;
	    }
	}

      if(read!=EOF)
	{
	  //reading of the small modification name
	  special_buffer=read_until(read_file,' ');
	  
	  if(i==0)
	    {
	      symbol=(char**)malloc(sizeof(char*));
	      if(symbol==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION SYMBOL TABLE",
			"SYMBOL IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		  printf("ALLOCATION ERROR IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP\n");
		  printf("SYMBOL IS NULL\n");
		  exit(EXIT_FAILURE);
		}
	    }
	  else
	    {
	      symbol=(char**)realloc(symbol,(i+1)*sizeof(char*));
	      if(symbol==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE MODIFICATION SYMBOL TABLE",
			"SYMBOL IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }

	  if(special_buffer!=NULL)
	    {
	      symbol[i]=(char*)malloc((strlen(special_buffer)+1)*sizeof(char));
	      if(symbol[i]==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION SYMBOL",
			"SYMBOL[i] IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	      strcpy(symbol[i],special_buffer);
	      free(special_buffer);
	    }
	  else
	    {
	      read=EOF;
	    }
	}
      
      if(read!=EOF)
	{
	  //reading of the amino acids on which the modification can be put.
	  read=fscanf(read_file,"%s",buffer);
	  
	  if(i==0)
	    {
	      modifications_on_amino_acids=(char**)malloc(sizeof(char*));
	      if(modifications_on_amino_acids==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION NAME TABLE",
			"MODIFICATIONS_ON_AMINO_ACIDS IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  else
	    {
	      modifications_on_amino_acids=(char**)realloc(modifications_on_amino_acids,(i+1)*sizeof(char*));
	      if(modifications_on_amino_acids==NULL)
		{
		  printf("REALLOCATION ERROR IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP\n");
		  printf("MODIFICATIONS_ON_AMINO_ACIDS IS NULL\n");
		  exit(EXIT_FAILURE);
		}
	    }

	  if(strcmp(buffer,"NONE")==0)
	    {
	      modifications_on_amino_acids[i]=NULL;
	    }
	  else
	    {
	      modifications_on_amino_acids[i]=(char*)malloc((strlen(buffer)+1)*sizeof(char));
	      if(modifications_on_amino_acids[i]==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION NAME",
			"MODIFICATION_ON_AMINO_ACIDS[i] IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	      strcpy(modifications_on_amino_acids[i],buffer);
	    }
	}
      
      if(read!=EOF)
	{
	  //reading the side for the modification.
	  read=fscanf(read_file,"%s",buffer);

	  if(i==0)
	    {
	      side=(int*)malloc(sizeof(int));
	      if(side==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE MODIFICATION SIDE",
			"SIDE IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  else
	    {
	      side=(int*)realloc(side,(i+1)*sizeof(int));
	      if(side==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE MODIFICATION SIDE",
			"SIDE IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }

	  if(strcmp(buffer,"C-term")==0)
	    {
	      side[i]=C_TERM;
	    }
	  else if(strcmp(buffer,"N-term")==0)
	    {
	      side[i]=N_TERM;
	    }
	  else if(strcmp(buffer,"Both")==0)
	    {
	      side[i]=BOTH_TERM;
	    }
	  else if(strcmp(buffer,"Independant")==0)
	    {
	      side[i]=INDEPENDANT_TERM;
	    }
	  else if(strcmp(buffer,"Protein")==0)
	    {
	      side[i]=PROTEIN;
	    }
	  else
	    {
	      error(USAGE_ERROR,"THE SIDE OF THE MODIF IS NOT CORRECT",
		    "MODIF_SIDE HAS AN ODD VALUE IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
	    }
	}


      if(read!=EOF)
	{
	  //reading of the formula to add.
	  special_buffer=read_until(read_file,' ');
	  
	  if(i==0)
	    {
	      formula_to_add=(formula_t*)malloc(sizeof(formula_t));
	      if(formula_to_add==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE FORMULA TO ADD",
			"FORMULA_TO_ADD IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  else
	    {
	      formula_to_add=(formula_t*)realloc(formula_to_add,(i+1)*sizeof(formula_t));
	      if(formula_to_add==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE FORMULA TO ADD",
			"FORMULA_TO_ADD IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  
	  if(special_buffer!=NULL)
	    {
	      if(strcmp(special_buffer,"NONE")!=0)
		{
		  formula=read_formula(special_buffer,get_element_table(),get_element_table_size());
		  formula_to_add[i]=*formula;
		  free(formula);
		}
	      else
		{
		  formula_to_add[i].nb_comp=0;
		  formula_to_add[i].comps=NULL;
		}
	      free(special_buffer);
	    }
	  else
	    {
	      read=EOF;
	    }

	}

      if(read!=EOF)
	{
	  //reading of the formula to sub.
	  read=fscanf(read_file,"%s",buffer);
	  
	   
	  if(i==0)
	    {
	      formula_to_sub=(formula_t*)malloc(sizeof(formula_t));
	      if(formula_to_sub==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE FORMULA TO SUB",
			"FORMULA_TO_SUB IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }
	  else
	    {
	      formula_to_sub=(formula_t*)realloc(formula_to_sub,(i+1)*sizeof(formula_t));
	      if(formula_to_sub==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE FORMULA TO SUB",
			"FORMULA_TO_SUB IS NULL IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP");
		}
	    }

	  if(strcmp(buffer,"NONE")!=0)
	    {
	      formula=read_formula(buffer,get_element_table(),get_element_table_size());
	      formula_to_sub[i]=*formula;
	      free(formula);
	    }
	  else
	    {
	      formula_to_sub[i].nb_comp=0;
	      formula_to_sub[i].comps=NULL;
	    }
	}

      if(read==EOF)
	{
	  printf("I/O ERROR IN LOAD_MODIFICATIONS IN MODIFICATIONS_TABLE.CPP\n");
	  printf("UNWANTED EOF GAINED\n");
	  exit(EXIT_FAILURE);
	}
      
      if(read!=EOF)
	{
	  //avoid any information on the rest of the line.
	  read=jump_a_line(read_file);
	}
      
      if(read!=EOF)
	{
	  //avoid commentaries between the modifications.
	  read=jump_commentaries(read_file,'#');
	}
      i++;
      nb_total_modif++;
    }
  
  fclose(read_file);
}

void
apply_global_modification(formula_t* formula,int modif)
{
  if((modif<0)||(modif>=nb_total_modif))
    {
      error(USAGE_ERROR,"THE WANTED MODIFICATION IS NOT CORRECT",
	    "THE MODIFICATION HAS AN ODD VALUE IN APPLY_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION.CPP");
    }

  if(formula_to_add[modif].nb_comp!=0)
    {
      add_formula(formula,&formula_to_add[modif]);
    }

  if(formula_to_sub[modif].nb_comp!=0)
    {
      if((sub_formula(formula,&formula_to_sub[modif]))==FALSE)
	{
	  error(EXECUTION_ERROR,"SUB THE MODIFICATION OF THE FORMULA IS IMPOSSIBLE",
		"THE CALL TO SUB_FORMULA HAS FAILED IN APPLY_MODIFICATION IN MODIFICATIONS_FOR_DIGESTION");
	}
    }
}

