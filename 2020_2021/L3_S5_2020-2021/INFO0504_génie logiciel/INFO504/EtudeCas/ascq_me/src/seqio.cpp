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
  \file seqio.cpp
  \author Pierre LAURENCE and David BOENS for ASCQ-PROT (2003).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in seqio.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "seqio.h"

/*! 
  \def MALLOC_STEP_SEQ
  \brief Standard size of allocation.*/
#define MALLOC_STEP_SEQ 10000

/*! 
  \var char* SeqBuffer
  \brief Variable that corresponds to the buffer holding the current protein sequence.*/
char* SeqBuffer=NULL;

/*! 
  \var char* DescBuffer
  \brief Variable that corresponds to the buffer holding the current protein description.*/
char* DescBuffer=NULL;

/*! 
  \var FILE* DbFile
  \brief Variable that corresponds to the opened FASTA file.*/
FILE* DbFile=NULL;

/*! 
  \var long Offset
  \brief Variable that corresponds to the offset in the FASTA file.*/
long Offset = (long) 0;

/*!
  \var char* specie
  \brief Variable that corresponds to the wanted specie.*/
char* specie=NULL;

/*!
  \var char* fasta_file_name
  \brief Variable that corresponds to the name of the opened FASTA file.*/
char* fasta_file_name=NULL;

/*!
  \var double protein_mass
  \brief Variable that corresponds to the experimental protein mass.*/
double protein_mass=0.0;

/*!
  \var int protein_mass_given
  \brief Variable that indicates if the a experimental protein mass has been given.*/
int protein_mass_given=FALSE;

/*!
  \var double mass_tolerance
  \brief Variable that indicates the according tolerance around the experimental protein mass.*/
double mass_tolerance=10.0;

/*!
  \var unsigned int parsing_is_started
  \brief Variable that indicates if the parsing of the database has started or not.*/
unsigned parsing_is_started=FALSE;

char*
getSeq ()
{
  return SeqBuffer;
}

char*
get_reversed_sequence()
{
  unsigned int i, size;
  char* result;

  //printf("Sequence = %s of size %d\n", SeqBuffer, strlen(SeqBuffer));

  size=strlen(SeqBuffer);

  result=(char*)malloc((size+1)*sizeof(char));
  if(result==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"AN ALLOCATION HAS FAILED FOR THE CURRENT PROTEIN REVERSED SEQUENCE",
	    "RESULT IS NULL IN GET_REVERSED_SEQUENCE IN SEQIO.CPP");
    }

  for(i=0;i<size;i++)
    {
      result[i]=SeqBuffer[(size-1)-i];
    }
    
  result[size]='\0';

  //printf("Reverse sequence = %s of size %d\n", result, strlen(result));

  return result;
}

char*
getDesc ()
{
  return DescBuffer;
}

unsigned int
is_parsing_started()
{
  return parsing_is_started;
}

int
nextEntry (long *offset)
{
  char c = ' ';
  char last = ' ';
  int nbMalloc = 1;
  int count = -1;
  long length = (long) 0;

  if(parsing_is_started==FALSE)
    {
      parsing_is_started=TRUE;
    }

  c = getc (DbFile);
  length = length + sizeof (c);
  
  if (c == EOF)
    {
      return FALSE;
    }
  if (c != '>')
    {
      fclose (DbFile);
      error(EXECUTION_ERROR,"THE FASTA FILE DOES NOT RESPECT THE FASTA FORMAT",
	    "SYMBOL > WAITED BUT NOT FOUND IN NEXTENTRY IN SEQIO.CPP");
    }
  
  free (SeqBuffer);
  free (DescBuffer);
  
  SeqBuffer = (char *) malloc (sizeof (char) * MALLOC_STEP_SEQ);
  DescBuffer = (char *) malloc (sizeof (char) * MALLOC_STEP_SEQ);

  /* fill description buffer */
  while (c != EOF && (c != '\n'))
    {
      c = getc (DbFile);
      length = length + sizeof (c);
      if (c != '\n')
	{
	  count++;
	  if (count >= (nbMalloc * MALLOC_STEP_SEQ - 1))	/* -1 for final \0 */
	    {
	      nbMalloc++;
	      DescBuffer = (char *)
		realloc (DescBuffer,
			 nbMalloc * MALLOC_STEP_SEQ * sizeof (char));
	    }
	  DescBuffer[count] = c;
	}
    }
  DescBuffer[count + 1] = '\0';

  c = getc (DbFile);
  length = length + sizeof (c);
  count = -1;
  nbMalloc = 1;
  /* fill sequence buffer */
  while (c != EOF)
    {
      if (!(c == '>' && (last == '\n')))
	{
	  /*if (c != '\n' && c != '\0') */
	  if (isalpha (c))
	    {
	      count++;
	      if (count >= (nbMalloc * MALLOC_STEP_SEQ - 1))	/* -1 for final \0 */
		{
		  nbMalloc++;
		  SeqBuffer = (char *)
		    realloc (SeqBuffer,
			     nbMalloc * MALLOC_STEP_SEQ * sizeof (char));

		}
	      if (isalpha (c))
		{
		  if (islower (c))
		    {
		      //SeqBuffer[count] = c;
		      SeqBuffer[count] = c + ('A'-'a');
		    }
		  else
		    {
		      //SeqBuffer[count] = c + 'a' - 'A';
		      SeqBuffer[count] = c;
		    }
		  //printf("%c", SeqBuffer[count]);
		}
	    }
	  last = c;
	  c = getc (DbFile);
	  length = length + sizeof (char);
	}
      else
	{
	  break;
	}
    }

  ungetc (c, DbFile);
  length = length - sizeof (c);
  *offset = Offset;
  Offset += length;
  SeqBuffer[count + 1] = '\0';

  return TRUE;
}

void
fastafclose ()
{
  if(fasta_file_name!=NULL)
    {
      free(fasta_file_name);
    }

  // C'est pas bien !!!
  if(SeqBuffer!=NULL)
    {
      free(SeqBuffer);
      }

  if(DescBuffer!=NULL)
    {
      free(DescBuffer);
    }

  if(specie!=NULL)
    {
      free(specie);
    }

  if(DbFile!=NULL)
    {
      fclose(DbFile);
    }
}

void
fastafopen(const char *filename, long *size)
{
  DbFile = fopen(filename, "rb"); 
  if(DbFile==NULL)
    {
      error(IO_ERROR,"THE FASTA FILE IS NOT CORRECTLY OPENED",
	    "DBFILE IS NULL IN FASTAFOPEN IN SEQIO.CPP");
    }
  fseek (DbFile, 0, SEEK_END);
  /*compute the size*/
  *size = ftell (DbFile);
  fseek (DbFile, 0, SEEK_SET);
  Offset = 0;
  
  fasta_file_name=(char*)malloc((strlen(filename)+1)*sizeof(char));
  if(fasta_file_name==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR SAVED THE FASTA FILE NAME",
	    "FASTA_FILE_NAME IS NULL IN FASTAFOPEN IN SEQIO.CPP");
    }
  strcpy(fasta_file_name,filename);
  
  //return DbFile;
}

void
fastafwrite (FILE * f, char *desc, char *seq)
{
  int k,i;
  char *tmp;

  i=0;
  tmp=(char *) malloc (sizeof (char) * (strlen (seq) + strlen (seq) / 60 + 2));
  if(tmp==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE TEMPORY BUFFER",
	    "TMP IS NULL IN FASTAFWRITE IN SEQIO.CPP");
    }

  for (k = 0; k < (int) strlen (seq); k++)
    {
      if (((k % 60) == 0))
	{
	  tmp[i] = '\n';
	  i++;
	}
      tmp[i] = toupper (seq[k]);
      i++;
    }
  tmp[i] = '\0';
  
  if (ftell (f) != 0)
    {
      putc ('\n', f);
    }

  fprintf (f, ">%s", desc);
  fprintf (f, "%s", tmp);
  
  free (tmp);
}

void
fastafwrite_way (FILE * f, char *desc, char *seq, int way)
{
  int k;
  int i = 0;
  char *tmp;
  const char *read_way[6] = { "lr0", "lr1", "lr2", "rl0", "rl1", "rl2" };

  tmp=NULL;

  tmp = (char *) malloc (sizeof (char) * (strlen (seq) + strlen (seq) / 60 + 2));
  if(tmp==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE TEMPORY BUFFER",
	    "TMP IS NULL IN FASTAFWRITE_WAY IN SEQIO.CPP");
    }
  
  for (k = 0; k < (int) strlen (seq); k++)
    {
      if (((k % 60) == 0))
	{
	  tmp[i] = '\n';
	  i++;
	}
      tmp[i] = toupper (seq[k]);
      i++;
    }
  tmp[i] = '\0';

  if (ftell (f) != 0)
    {
      putc ('\n', f);
    }
  
  fprintf (f, ">(%s)%s", read_way[way], desc);
  fprintf (f, "%s", tmp);
  
  free (tmp);
}

int
getEntry (long *offset)
{
  fseek (DbFile, *offset, SEEK_SET);
  Offset = *offset;
  return nextEntry (offset);
}

void
set_specie(const char* wanted_specie)
{
  int i,size;
  if(DbFile!=NULL)
    {
      error(USAGE_ERROR,"FASTA ALREADY OPENED, SPECIE CAN NOT BE SET",
	    "DBFILE!=NULL IN SET_SPECIE IN SEQIO.CPP");
    }
  if(specie!=NULL)
    {
      error(WARNING,"A SPECIE HAS BEEN ALREADY DEFINED, OLD VALUE IS REMPLACED",
	    "THE NEW VALUE ERASES THE OLD VALUE IN SET_SPECIE IN SEQIO.CPP");
    }
  specie=(char*)malloc((strlen(wanted_specie)+1)*sizeof(char));
  if(specie==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE SPECIE FILTER",
	    "SPECIE IS NULL IN SET_SPECIE IN SEQIO.CPP");
    }
  strcpy(specie,wanted_specie);
  size=strlen(specie);
  for(i=0;i<size;i++)
    {
      specie[i]=toupper(specie[i]);
    }
}
	     
int
is_a_wanted_protein()
{
  double min,max,mass;
  formula_t* formula;

  min=max=0.0;

  if(DescBuffer==NULL)
    {
      error(USAGE_ERROR,"NO PROTEIN LOADED IN MEMORY, NO INFORMATION CAN BE DEDUCED",
	    "NO PROTEIN LOADED IN IS_A_WANTED_PROTEIN IN SEQIO.CPP, FASTAFOPEN AND NEXTENTRY HAVE TO BE CALLED BEFORE");
    }
    
  if(protein_mass_given==TRUE)
    {
      min=protein_mass-((mass_tolerance*protein_mass)/100.0);
      max=protein_mass+((mass_tolerance*protein_mass)/100.0);
    }

  if(specie==NULL)
    {
      if(protein_mass_given==FALSE)
	{
	  return TRUE;
	}
      else
	{
	  formula=get_formula_from_sequence(SeqBuffer);
	  mass=get_weight(formula);
	  free_formula(formula);
	  return ((mass>min)&&(mass<max));
	}
    }
  
  if(protein_mass_given==FALSE)
    {
      return strstr(DescBuffer,specie)!=NULL;
    }
 
  formula=get_formula_from_sequence(SeqBuffer);
  mass=get_weight(formula);
  free_formula(formula);
  return (mass>min)&&(mass<max)&&(strstr(DescBuffer,specie)!=NULL);
}

char* 
get_fasta_filename()
{
  return fasta_file_name;
}

char*
get_specie()
{
  return specie;
}

void
set_exp_protein_mass(double mass)
{
  protein_mass=mass;
  protein_mass_given=TRUE;
}

double 
get_exp_protein_mass()
{
  if(protein_mass_given==FALSE)
    {
      error(USAGE_ERROR,"THE PROTEIN EXPERIMENTAL MASS IS NOT ALREADY SET",
	    "PROTEIN EXPERIMENTAL MASS IS NOT SET IN GET_EXP_PROTEIN_MASS IN SEQIO.CPP,SET_EXP_PROTEIN_MASS MUST BE CALLEd BEFORE");
    }

  return protein_mass;
}

int
is_exp_protein_mass_activated()
{
  return protein_mass_given;
}

