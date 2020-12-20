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
  \file cleavage.cpp
  \author Pierre LAURENCE and David BOENS for ASCQ-PROT (2003).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in cleavage.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "cleavage.h"

/*!
  \fn void cp_fprint (FILE* f, cp_t* cp);
  \brief Tool procedure used in cplt_fprint.
  \param f The file where the cp will be printed.
  \param cp The cp structure to print.*/
void cp_fprint (FILE* f, cp_t* cp);

cpl_t *
stringToCpl (char *s)
{
  int i,nbm,except,before,first,size;
  cpl_t *cpl;

  i=nbm=size=0;
  except=before=FALSE;
  first=TRUE;
  
  cpl=(cpl_t*)malloc (sizeof (cpl_t));
  if(cpl==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
	    "CPL IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
    }
  
  size=strlen(s);
   
  for(i=0;i<size;i++)
    {
      if (s[i] == '+')
	{
	  except = TRUE;
	  before = FALSE;
	}
      else if (s[i] == '-')
	{
	  except = TRUE;
	  before = TRUE;
	}
      else if (s[i] == ';')
	{
	  except = FALSE;
	  before = FALSE;
	}
      else
	{
	  if (except == TRUE)
	    {
	      if (before == TRUE)
		{
		  cpl->cp[nbm-1].nbexceptbefore++;

		  if(cpl->cp[nbm-1].nbexceptbefore==1)
		    {
		      cpl->cp[nbm-1].exceptbefore=(char*)malloc(sizeof (char));
		      if (cpl->cp[nbm-1].exceptbefore==NULL)
			{   
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
				"CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
			}
		    }
		  else
		    { 
		      cpl->cp[nbm-1].exceptbefore=(char*)realloc(cpl->cp[nbm-1].exceptbefore,
								 cpl->cp[nbm-1].nbexceptbefore*sizeof (char));
		      if (cpl->cp[nbm-1].exceptbefore==NULL)
			{   
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
				"CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
			}
		    }
		  
		  cpl->cp[nbm-1].exceptbefore[cpl->cp[nbm-1].nbexceptbefore - 1] = s[i];
		  
		}
	      else
		{ 
		  cpl->cp[nbm-1].nbexceptafter++;

		  if(cpl->cp[nbm-1].nbexceptafter==1)
		    {
		      cpl->cp[nbm-1].exceptafter=(char*)malloc(sizeof (char));
		      if (cpl->cp[nbm-1].exceptafter==NULL)
			{   
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
				"CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
			}
		    }
		  else
		    { 
		      cpl->cp[nbm-1].exceptafter=(char*)realloc(cpl->cp[nbm-1].exceptafter,
								 cpl->cp[nbm-1].nbexceptafter*sizeof (char));
		      if (cpl->cp[nbm-1].exceptafter==NULL)
			{   
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
				"CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
			}
		    }
		  
		  cpl->cp[nbm-1].exceptafter[cpl->cp[nbm-1].nbexceptafter - 1] = s[i];
		}
	    }
	  else
	    {
	      if(first==TRUE)
		{
		  nbm++;
		  
		  cpl->cp = (cp_t*) malloc (sizeof (cp_t));
		  if(cpl->cp==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
			    "CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
		    }
		 
		  first=FALSE;

		  cpl->cp[nbm-1].nbexceptbefore = 0;
		  cpl->cp[nbm-1].nbexceptafter = 0;
		  cpl->cp[nbm-1].exceptafter = NULL;
		  cpl->cp[nbm-1].exceptbefore = NULL;
		  cpl->cp[nbm-1].letter = s[i]; 
		}
	      else if(cpl->cp[nbm-1].letter!=s[i])
		{
		  nbm++;
		  
		  cpl->cp = (cp_t *) realloc (cpl->cp, nbm * sizeof (cp_t));
		  if(cpl->cp==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED FOR THE CHOSEN ENZYME",
			    "CP IS NULL  IN STRINGTOCPL IN CLEAVAGE.CPP\n");
		    }
		
		  cpl->cp[nbm-1].nbexceptbefore = 0;
		  cpl->cp[nbm-1].nbexceptafter = 0;
		  cpl->cp[nbm-1].exceptafter = NULL;
		  cpl->cp[nbm-1].exceptbefore = NULL;
		  cpl->cp[nbm-1].letter = s[i]; 

		}
	      


	      
	    }
	}
    }

  cpl->size = nbm;
  //printf("%d\n",cpl->size);
  return cpl;
}

int
cpl_isCleavage (cpl_t* cpl, char c)
{
  int i = 0;
  for (i = 0; i <= cpl->size; i++)
    if (cpl->cp[i].letter == toupper(c))
      return TRUE;
  return FALSE;
}

int
cpl_isCleavage2 (cpl_t* cpl, char cprev, char c, char cnext)
{
  int i;
  int j;
  for (i = 0; i < cpl->size; i++)
  //for (i = 0; i <= cpl->size; i++)
    if (cpl->cp[i].letter == toupper(c))
      {
	if (cpl->cp[i].nbexceptafter > 0)
	  for (j = 0; j < cpl->cp[i].nbexceptafter; j++)
	    if (cpl->cp[i].exceptafter[j] == toupper(cnext))
	      return FALSE;
	if (cpl->cp[i].nbexceptbefore > 0)
	  for (j = 0; j < cpl->cp[i].nbexceptbefore; j++)
	    if (cpl->cp[i].exceptbefore[j] == toupper(cprev))
	      return FALSE;
	return TRUE;
      }
  return FALSE;
}

void
cp_fprint (FILE* f, cp_t* cp)
{
  int i = 0;
  fprintf (f, "\t  %c\n", toupper (cp->letter));
  if (cp->nbexceptafter > 0)
    {
      fprintf (f, "\t    not following of ");
      while (i < cp->nbexceptafter)
	{
	  fprintf (f, "\t%c,", toupper (cp->exceptafter[i]));
	  i++;
	}
      fprintf (f, "\t\b \n");
    }
  i = 0;
  if (cp->nbexceptbefore > 0)
    {
      fprintf (f, "\t    not preceding by ");
      while (i < toupper (cp->nbexceptbefore))
	{
	  fprintf (f, "\t%c,", toupper (cp->exceptbefore[i]));
	  i++;
	}
      fprintf (f, "\t\b \n");
    }
}

void
cpl_fprint (FILE* f, cpl_t* cpl)
{
  int i = 0;
  fprintf (f, "\t cleave on:\n");
  for (i = 0; i <= cpl->size; i++)
    cp_fprint (f, &(cpl->cp[i]));
}

enztable_t* 
enzym_load(const char* fileToLoad) 
{
  int i;
  int j;
  char c = ' ';
  char *s = (char *) malloc (sizeof (char)) ;
  char *desc;
  FILE *f;
  int size = 0;
  enztable_t * res = (enztable_t *) malloc(sizeof(enztable_t));
  enz_t * enzs = NULL;

  f = fopen (fileToLoad, "r");
  if (f==NULL)
    {
      error (IO_ERROR, "ENZYM FILE READING IMPOSSIBLE",
	    "F IS NULL IN ENZYM_LOAD IN CLEAVAGE.CPP");
    }
  else
    {
      while (c != EOF)
	{
	  i = 0;
	  c = fgetc (f);
	  s[0] = '\0';
	  /* get an enzyme line */
	  while (!EOL(c))
	    {
	      s = (char *) realloc (s, (strlen (s) + 2) * sizeof (char));
	      s[i] = c;
	      i++;
	      s[i] = '\0';
	      c = fgetc (f);
	    }
	  /* skip previous separator */
	  i = 0;
	  while ((i < (int) strlen (s)) && (SEPARATOR(s[i])))
	    {
	      i++;
	    }
	  if (s[0] != '#' && s[0] != '\0' && strlen(s+i) != 0)
	    {
	      j = i;
	      while ((j < (int) strlen (s)) && (!SEPARATOR(s[j]))) 
		{
		  j++;
		}
	      enzs = (enz_t *) realloc(enzs,sizeof(enz_t)*(size+1));
	      enzs[size].name = (char *) malloc(sizeof(char)*(j-i)+1);
	      memcpy(enzs[size].name,s+i,sizeof(char)*(j-i));
	      enzs[size].name[j-i] = '\0';
	      i = j;
	      while ((i < (int) strlen (s)) && (SEPARATOR(s[i])))
		{
		  i++;
		}
	      if (!strncmp (s + i, "C-side", 6))
		{
		  enzs[size].side = C_SIDE;
		}
	      else if (!strncmp (s + i, "N-side", 6))
		{
		  enzs[size].side = N_SIDE;
		}
	      else
		{
		  error(USAGE_ERROR, "NO SIDE SPECIFIED FOR THE ENZYM",
			"THE SIDE HAS AN ODD VALUE IN ENZYM_LOAD IN CLEAVAGE.CPP");
		}
	      i = i+7;
	      while ((i < (int) strlen (s)) && (SEPARATOR(s[i])))
		{
		  i++;
		}
	      j = i;
	      while ((j < (int) strlen (s)) && (!SEPARATOR(s[j]))) 
		{
		  j++;
		}
	      desc = (char *) malloc(sizeof(char)*(j-i)+1);
	      memcpy(desc,s+i,sizeof(char)*(j-i));
	      desc[j-i] = '\0';
	      enzs[size].cpl = stringToCpl (desc);
	      size++;
	      free(desc);
	    }
	} 
    }
  free(s);
  res->size = size;
  res->enz = enzs;
  if (size <= 0)
    {
      error(USAGE_ERROR,"NO ENZYM  LOADED",
	    "NUMBER OF ENZYM = 0 IN ENZYM_LOAD IN CLEAVAGE.CPP");
    }
  fclose(f);
  return res;
}

int 
get_enzyme_number(char* enztofind, enztable_t* enzt)
{
  int i = 0;
  if (enzt->size > 0)
    {
      while (i < enzt->size)
	{
	  if (!strcmp(enzt->enz[i].name,enztofind))
	    {
	      return i;
	    } 
	  i++;
	}
      return -1;
    }
  else
    {
      return -1;
    }
}

void
print_enzyme_table(enztable_t* enzt)
{
  int i;
  for (i = 0;i < enzt->size;i++)
    {
      printf("- %s\n",enzt->enz[i].name);
    }
}

void
free_cpt(cp_t* cpt)
{
  if(cpt==NULL)
    {
     error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CP_T",
	    "CPT IS NULL IN FREE_CPT IN CLEAVAGE.CPP");
    }

  if((cpt->nbexceptbefore!=0)&&(cpt->exceptbefore==NULL))
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CHARACTER LIST BEFORE CLEAVAGE POINT",
	    "CPT->EXCEPTBEFORE IS NULL IN FREE_CPT IN CLEAVAGE.CPP");
    }

  free(cpt->exceptbefore);

  if((cpt->nbexceptafter!=0)&&(cpt->exceptafter==NULL))
    {
        error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CHARACTER LIST AFTER CLEAVAGE POINT",
	    "CPT->EXCEPTAFTER IS NULL IN FREE_CPT IN CLEAVAGE.CPP");
    }
  
  free(cpt->exceptafter);

}

void
free_cplt(cpl_t* cplt)
{
  int i;
  if(cplt==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CPL_T",
	    "CPLT IS NULL IN FREE_CPLT IN CLEAVAGE.CPP");
    }
  if(cplt->cp==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CP_T",
	    "CPLT->CP IS NULL IN FREE_CPLT IN CLEAVAGE.CPP");
    }
  for(i=0;i<cplt->size;i++)
    {
      free_cpt(&(cplt->cp[i]));
    }
  free(cplt->cp);
}

void
free_enzt(enz_t* enzt)
{
  if(enzt==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY ENZ_T",
	    "ENZ IS NULL IN FREE_ENZT IN CLEAVAGE.CPP");
    }
  if(enzt->name==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY ENZYME NAME",
	    "ENZ->NAME IS NULL IN FREE_ENZT IN CLEAVAGE.CPP");
    }
  free(enzt->name);
  if(enzt->cpl==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE OF A EMPTY CPL_T",
	    "ENZ->CPL IS NULL IN FREE_ENZT IN CLEAVAGE.CPP");
    }
  free_cplt(enzt->cpl);
  free(enzt->cpl);
}

void
free_enzym_table(enztable_t* enzyme_table)
{
  if(enzyme_table==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE ENZYME TABLE IS EMPTY",
	    "ENZYM_TABLE IS NULL IN FREE_ENZYM_TABLE IN CLEAVAGE.CPP");
    }
  if(enzyme_table->enz==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE ENZYMES OF THE ENZYM TABLE ARE EMPTY",
	    "ENZYM_TABLE->ENZ IS NULL IN FREE_ENZYM_TABLE IN CLEAVAGE.CPP");
    }
  for(int i=0;i<enzyme_table->size;i++)
    {
      free_enzt(&enzyme_table->enz[i]);
    }
  free(enzyme_table->enz);
  free(enzyme_table);
}
