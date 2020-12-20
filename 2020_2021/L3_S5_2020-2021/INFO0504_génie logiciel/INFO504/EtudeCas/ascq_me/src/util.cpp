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
  \file util.cpp
  \author Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in util.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "util.h"

/*! 
  \var int verbose_activation
  \brief Variable that indicates if the verbose mode is activated or not.*/
int verbose_activation=FALSE;

int
jump_commentaries(FILE* file,char commentary)
{
  int read;
  char c;
  
  read=fscanf(file,"%c",&c);
  if(read!=EOF)
    {
      while((read!=EOF)&&((c==commentary)||(c==' ')||(c=='\n')||(c=='\r')))
	{
	  ungetc(c,file);
	  read=jump_a_line(file);
	  if(read!=EOF)
	    {
	      read=fscanf(file,"%c",&c);
	    }
	}
    }
  if(read!=EOF)
    {
      ungetc(c,file);
    }
  return read;
}

int
jump_a_line(FILE* file)
{
  int read;
  char c;
  do
    {
      read=fscanf(file,"%c",&c);
    }
  while((read!=EOF)&&(c!='\n'));
  return read;
}

int 
jump_blanks(FILE* file)
{
  int read;
  char c;

  if(file==NULL)
    {
      error(USAGE_ERROR,"A USED FILE IS NOT CORRECTLY OPENED", "FILE IS NULL IN JUMP_BLANK IN UTIL.CPP");
    }

  do
    {
      read=fscanf(file,"%c",&c);
    }
  while((read!=EOF)&&(c==' '));
  if(read!=EOF)
    {
      ungetc(c,file);
    }
  return read;
}

char*
read_line(FILE* file)
{
  return read_until(file,'\n');
}

char* read_until(FILE* file,char separator)
{
  char* buffer;
  char c;
  int read,size;
  
  if(file==NULL)
    {
      error(USAGE_ERROR,"A USED FILE IS NOT CORRECTLY OPENED", "FILE IS NULL IN READ_UNTIL IN UTIL.CPP");
    }
  
  buffer=NULL;
  
  size=0;
  
  read=jump_blanks(file);

  if(read!=EOF)
    {
      read=fscanf(file,"%c",&c);
    }

  while((read!=EOF)&&(c!=separator)&&(c!='\n'))
    {
      if(c!='\r')
	{
	  size++;
	  if(size==1)
	    {
	      buffer=(char*)malloc(sizeof(char));
	      if(buffer==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,
			"A MEMORY ALLOCATION FAILED DURING THE READING OF A FILE",
			"BUFFER IS NULL IN READ_LINE IN UTIL.CPP");
		}
	    }
	  else
	    {
	      buffer=(char*)realloc(buffer,size*sizeof(char));
	      if(buffer==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,
			"A MEMORY REALLOCATION FAILED DURING THE READING OF A FILE",
			"BUFFER IS NULL IN READ_LINE IN UTIL.CPP");
		}
	    }
	  buffer[size-1]=c;
	}
      read=fscanf(file,"%c",&c);
    }
  
  if(size!=0)
    {
      buffer=(char*)realloc(buffer,(size+1)*sizeof(char));
      if(buffer==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,
		"A MEMORY REALLOCATION FAILED DURING THE READING OF A FILE",
		"BUFFER IS NULL IN READ_LINE IN UTIL.CPP");
	}
      buffer[size]='\0';
    }

  if((read!=EOF)&&(separator!='\n'))
    {
      ungetc(c,file);
    }
  return buffer;
}

void
delete_final_blanks(char* buffer)     
{
  int size,i;
  
  if(buffer==NULL)
    {
      error(USAGE_ERROR,"A BUFFER IS NOT INITIALIZED","BUFFER IS NULL IN DELETE_FINAL_BLANKS IN UTIL.CPP"); 
    }

  size=strlen(buffer);
  i=size-1;
  while(buffer[i]==' ')
    {
      size--;
      buffer=(char*)realloc(buffer,(size+1)*sizeof(char));
      if(buffer==NULL)
	{
	  error(MEMORY_ALLOCATION_ERROR,
		"A MEMORY REALLOCATION FAILED DURING THE PARSING OF A STRING",
		"BUFFER IS NULL IN DELETE_FINAL_BLANKS IN UTIL.CPP");
	}
      i--;
    }
  buffer[size]='\0';
}

void
activate_verbose_mode()
{
  verbose_activation=TRUE;
}

int
is_verbose_mode_activated()
{
  return verbose_activation;
}

char*
add_chains(const char* first, const char* second)
{
  char* result;
  
  if(first==NULL)
    {
      error(USAGE_ERROR,"TWO STRING HAVE TO BE MIXED BUT THE FIRST HAS NO VALUE",
	    "FIRST IS NULL IN ADD_CHAINS IN UTIL.CPP");
    }
  
  if(second==NULL)
    {
      error(USAGE_ERROR,"TWO STRING HAVE TO BE ADDED TOGETHER BUT THE SECOND HAS NO VALUE",
	    "SECOND IS NULL IN ADD_CHAINS IN UTIL.CPP");
    }

  //printf("size of the first = %d\n",strlen(first));
  //printf("size of the second = %d\n",strlen(second));

  result=(char*)malloc((strlen(first)+strlen(second)+1)*sizeof(char));
  if(result==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION FAILED FOR THE RESULT OF THE ADDITION OF TWO STRINGS",
	    "RESULT IS NULL IN ADD_CHAINS IN UTIL.CPP");
    }

  strncpy(result,first,strlen(first));
  strcpy(result+strlen(first),second);

  //printf("size of the result = %d\n",strlen(result));
  //printf("result = %s\n",result);

  //error(USAGE_ERROR,"TEST","TEST");

  return result;
}

int
equals(double value1, double value2, double delta)
{
  return ((value1>=(value2-delta))&&(value1<=(value2+delta)))?TRUE:FALSE;
}

double*
copy_double_array(double* src, int src_size)
{
  int i;
  double* copie;

  copie=NULL;

  if(src==NULL)
    {
      error(USAGE_ERROR,"THE ORIGINAL DOUBLE ARRAY IS NOT CORRECTLY INITIALIZED",
	    "SRC IS NULL IN COPY_DOUBLE_ARRAY IN UTIL.CPP");
    }
  
  if(src_size<=0)
    {
      error(USAGE_ERROR,"THE ORIGINAL ARRAY SIZE IS NOT CORRECT",
	    "SRC_SIZE IS NEGATIVE OR EQUAL TO ZERO IN COPY_DOUBLE_ARRAY IN UTIL.CPP");
    }
  
  copie=(double*)malloc(src_size*sizeof(double));
  if(copie==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE COPIE OF THE ORIGINAL DOUBLE ARRAY",
	    "COPIE IS NULL IN COPY_DOUBLE_ARRAY IN UTIL.CPP");
    }
  
  for(i=0;i<src_size;i++)
    {
      copie[i]=src[i];
    }
  
  return copie;
}

int
compare_doubles(const void* first,const void* second)
{
  double score1,score2;
  
  score1=*(double*)first;
  score2=*(double*)second;

  if(score1<score2)
    {
      return -1;
    }
  else if(score1>score2)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
