/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s) : 
     Jean-Charles BOISSON
     Nicolas DOLET
     Nicolas GRUSZCZYNSKA
     
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
  \file aa.cpp
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in aa.h.
   \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "aa.h"

/*all the useful formulae, initialised by call to init_peptide_link once et use all the time*/

/*! 
  \var formula_t* H
  \brief Variable that corresponds to the H formula.*/
formula_t *H=NULL;

/*! 
  \var formula_t* OH
  \brief Variable that corresponds to the OH formula.*/
formula_t *OH=NULL;

/*! 
  \var formula_t* NHCHCO
  \brief Variable that corresponds to the NHCHCO formula.*/
formula_t *NHCHCO=NULL;

/*! 
  \var formula_t* H2O
  \brief Variable that corresponds to the H2O formula.*/
formula_t *H2O=NULL;

/*! 
  \var formula_t* CO
  \brief Variable that corresponds to the CO formula.*/
formula_t *CO=NULL;

/*! 
  \var formula_t* NH
  \brief Variable that corresponds to the NH formula.*/
formula_t *NH=NULL;

/*! 
  \var formula_t* NH3
  \brief Variable that corresponds to the NH3 formula.*/
formula_t *NH3=NULL;

/*! 
  \var formula_t* NH2
  \brief Variable that corresponds to the NH2 formula.*/
formula_t *NH2=NULL;

/*! 
  \var formula_t* CH
  \brief Variable that corresponds to the CH formula.*/
formula_t *CH=NULL;

/*! 
  \var formula_t* CO2H
  \brief Variable that corresponds to the CO2H formula.*/
formula_t *CO2H=NULL;

/*amino acid assigned by default to the amino acid X, B et Z ==> due to fasta format*/

/*! 
  \var char X
  \brief Variable that corresponds to the value of the amino acid X read in a fasta file.*/
char X='G'; 

/*! 
  \var char Z
  \brief Variable that corresponds to the value of the amino acid Z read in a fasta file.*/
char Z='E';

/*! 
  \var char B
  \brief Variable that corresponds to the value of the amino acid B read in a fasta file.*/
char B='D';

void
init_peptid_link(element_t *elem_table,int elem_table_size)
{
  H=read_formula("H",elem_table,elem_table_size);
  OH=read_formula("OH",elem_table,elem_table_size);
  NHCHCO=read_formula("NH2C2O",elem_table,elem_table_size);
  H2O=read_formula("H2O",elem_table,elem_table_size);
  CO=read_formula("CO",elem_table,elem_table_size);
  NH=read_formula("NH",elem_table,elem_table_size);
  NH3=read_formula("NH3",elem_table,elem_table_size);
  NH2=read_formula("NH2",elem_table,elem_table_size);
  CH=read_formula("CH",elem_table,elem_table_size);
  CO2H=read_formula("CO2H",elem_table,elem_table_size);
}

aa_CF_t*
get_amino_acid_table(const char *filename,element_t *elem_table,int elem_table_size)
{
  FILE *f; 
  char buffer[64];
  int place;
  
  aa_CF_t *aa_table;
  int i;
  
  int read;
  
  /* Allocate the table */
  aa_table = (aa_CF_t *)malloc(sizeof(aa_CF_t)*26);
  if(aa_table==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE AMINO ACID TABLE",
	    "AA_TABLE IS NULL IN GET_AMINO_ACID_TABLLE IN AA.CPP");
    }
  for(i=0;i<26;i++)
    {
      aa_table[i].form=NULL;
      aa_table[i].add_modif=NULL;
      aa_table[i].sub_modif=NULL;    
    }

  f = fopen (filename, "r");

  if (f==NULL)
    {
      error(IO_ERROR,"THE AMINO ACID FILE CAN NOT BE CORRECTLY OPENED",
	    "FILE IS NULL IN GET_AMINO_ACID_TABLLE IN AA.CPP");
    }
  else
    {
      /*------------------------------------------------------------------------------------*/
      /*for the unix version */
      read=fscanf(f,"%s",buffer);
      while(read!=-1)
	{
	  place=(int)(toupper(buffer[0]-'A'));
	  read=fscanf(f,"%s",buffer);
	  if(read!=-1)
	    {
	      aa_table[place].form=read_formula(buffer,elem_table,elem_table_size);
	      read=fscanf(f,"%s",buffer);
	    }
	  if(read!=-1)
	    {
	      aa_table[place].add_modif=read_formula(buffer,elem_table,elem_table_size);
	      read=fscanf(f,"%s",buffer);
	    }
	   if(read!=-1)
	    {
	      aa_table[place].add_modif=read_formula(buffer,elem_table,elem_table_size);
	      read=fscanf(f,"%s",buffer);
	    }
	}
    }
  fclose(f);
  
  place=(int)('X'-'A');
  aa_table[place].form=copy_formula(aa_table[X-'A'].form);
  place=(int)('Z'-'A');
  aa_table[place].form=copy_formula(aa_table[Z-'A'].form);
  place=(int)('B'-'A');
  aa_table[place].form=copy_formula(aa_table[B-'A'].form);
  return aa_table;
}

void
free_amino_acid_table(aa_CF_t *aa_table)
{
  int i;
  if(aa_table==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE AMINO ACID TABLE IS EMPTY",
	    "AA_TABLE IS NULL IN FREE_AMINO_ACID_TABLE IN AA.CPP");
    }
  for(i=0;i<26;i++)
    {
      if(aa_table[i].form!=NULL)
	{
	  free_formula(aa_table[i].form);
	  if(aa_table[i].add_modif!=NULL)
	    {
	      free_formula(aa_table[i].add_modif);
	    }
	  if(aa_table[i].sub_modif!=NULL)
	    {
	      free_formula(aa_table[i].sub_modif);
	    }
	}
    }
  free(aa_table);
}

formula_t* 
get_util_formula(const char* name)
{
  if(strcmp(name,"H")==0)
    {
      if(H!=NULL)
	{
	  return H;
	}
    }
  else if(strcmp(name,"OH")==0)
    {
      if(OH!=NULL)
	{
	  return OH;
	}
    }
  else if(strcmp(name,"NHCHCO")==0)
    {
      if(NHCHCO!=NULL)
	{
	  return NHCHCO;
	}
    }
  else if(strcmp(name,"H2O")==0)
    {
      if(H2O!=NULL)
	{
	  return H2O;
	}
    }
  else if(strcmp(name,"CO")==0)
     {
      if(CO!=NULL)
	{
	  return CO;
	}
    }
  else if(strcmp(name,"NH")==0)
    {
      if(NH!=NULL)
	{
	  return NH;
	}
    }
  else if(strcmp(name,"NH3")==0)
   {
      if(NH3!=NULL)
	{
	  return NH3;
	}
    }
  else if(strcmp(name,"NH2")==0)
   {
      if(NH2!=NULL)
	{
	  return NH2;
	}
    }
  else if(strcmp(name,"CH")==0)
   {
      if(CH!=NULL)
	{
	  return CH;
	}
    }
  else if(strcmp(name,"CO2H")==0)
   {
      if(CO2H!=NULL)
	{
	  return CO2H;
	}
    }
  else
    {
      error(USAGE_ERROR,"THE WANTED FORMULA DOES NOT EXIST IN THE ALREADY COMPUTED FORMULA",
	    "THE WANTED FORMULA HAS ALREADY COMPUTED, MAKE SUR THAT INIT_PEPTIDE_LINK HAS BEEN ALREADY CALLED");
    }
  /*for the compilation, this case doesn't exist*/
  return NULL;
}

void 
free_peptide_link()
{
  if(H!=NULL)
    {
      free_formula(H);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE H FORMULA IS EMPTY",
	    "H IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(OH!=NULL)
    {
      free_formula(OH);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE OH FORMULA IS EMPTY",
	    "OH IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(NHCHCO!=NULL)
    {
      free_formula(NHCHCO);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE C2H2NO FORMULA IS EMPTY",
	    "C2H2NO IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(H2O!=NULL)
    {
      free_formula(H2O);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE H2O FORMULA IS EMPTY",
	    "H2O IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(CO!=NULL)
    {
      free_formula(CO);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE CO FORMULA IS EMPTY",
	    "CO IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(NH!=NULL)
    {
      free_formula(NH);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE NH FORMULA IS EMPTY",
	    "NH IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(NH3!=NULL)
    {
      free_formula(NH3);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE NH3 FORMULA IS EMPTY",
	    "NH3 IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(NH2!=NULL)
    {
      free_formula(NH2);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE NH2 FORMULA IS EMPTY",
	    "NH2 IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(CH!=NULL)
    {
      free_formula(CH);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE CH FORMULA IS EMPTY",
	    "CH IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
  if(CO2H!=NULL)
    {
      free_formula(CO2H);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE CO2H FORMULA IS EMPTY",
	    "CO2H IS NULL IN FREE_PEPTIDE_LINK IN AA.CPP");
    }
} 

void 
print_amino_acid_table(aa_CF_t* aa_table)
{
  int i;
  for(i=0;i<26;i++)
    {
      if (aa_table[i].form!=NULL)
	{
	  printf("%c %s ",(char)(i+'A'),formula_tochar(aa_table[i].form));
	  if(aa_table[i].add_modif!=NULL)
	    {
	      printf("%s",formula_tochar(aa_table[i].add_modif));
	    }
	  if(aa_table[i].sub_modif!=NULL)
	    {
	      printf("%s",formula_tochar(aa_table[i].sub_modif));
	    }
	  printf("\n");
	}
    }
}

void
fprint_amino_acid_table(FILE* file,aa_CF_t* aa_table)
{
  int i;
  for(i=0;i<26;i++)
    {
      if (aa_table[i].form!=NULL)
	{
	  fprintf(file,"%c %s %f",(char)(i+'A'),formula_tochar(aa_table[i].form),get_weight(aa_table[i].form));
	  if(aa_table[i].add_modif!=NULL)
	    {
	      fprintf(file,"%s",formula_tochar(aa_table[i].add_modif));
	    }
	  if(aa_table[i].sub_modif!=NULL)
	    {
	      fprintf(file,"%s",formula_tochar(aa_table[i].sub_modif));
	    }
	  fprintf(file,"\n");
	}
    }
}

void
set_X(char amino_acid)
{
  X=amino_acid;
}

void
set_Z(char amino_acid)
{
  Z=amino_acid;
}

void
set_B(char amino_acid)
{
  B=amino_acid;
}

char
get_X()
{
  return X;
}

char
get_Z()
{
  return Z;
}

char
get_B()
{
  return B;
}
