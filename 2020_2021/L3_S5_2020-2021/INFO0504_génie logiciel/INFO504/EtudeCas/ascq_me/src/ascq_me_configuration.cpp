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
  \file ascq_me_configuration.cpp
  \author Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in ascq_me_configuration.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "ascq_me_configuration.h"

/*!
  \var char* base_name
  \brief Base name for the ASCQ_ME result files.*/
char* base_name=NULL;

/*!
  \var char* configuration_file_name
  \brief Name of the configuration file used.*/
char* configuration_file_name=NULL;

/*!
  \var int fasta_format
  \brief Variable that indicates if the chosen format is FASTA (TRUE) or spectrum (FALSE).*/
int fasta_format=TRUE;

/*!
  \var int decoy_mode_activation
  \brief Variable that indicates if the decoy mode is activated or not.*/
int decoy_mode_activation=FALSE;

/*!
  \var double decoy_score
  \brief Variable that contains the mean of the decoy score of the analyzed proteins.*/
double decoy_score=0.0;

/*!
  \var int nb_displayed_proteins
  \brief Number of displayed proteins.*/
int nb_displayed_proteins=10;

/*!
  \fn void load_int_keyword(FILE* file,char* buffer)
  \brief Procedure which reads the value of a parameter that requires an int value.
  \param file The file to read.
  \param buffer The name of the keyword*/
void load_int_keyword(FILE* file, char* buffer);

/*!
  \fn void load_unsigned_int_keyword(FILE* file,char* buffer)
  \brief Procedure which reads the value of a parameter that requires an unsigned int value.
  \param file The file to read.
  \param buffer The name of the keyword*/
void load_unsigned_int_keyword(FILE* file, char* buffer);

/*!
  \fn void load_boolean_keyword(FILE* file,char* buffer)
  \brief Procedure which reads the value of a parameter that requires a boolean value (in reality it is a char*, not really a boolean).
  \param file The file to read.
  \param buffer The name of the keyword*/
void load_boolean_keyword(FILE* file, char* buffer);

/*!
  \fn void load_string_keyword(FILE* file, const char* buffer)
  \brief Procedure which reads the value of a parameter that requires a string value (it is a char* value).
  \param file The file to read.
  \param buffer The name of the keyword*/
void load_string_keyword(FILE* file, const char* buffer);

/*!
  \fn void load_float_keyword(FILE* file,char* buffer)
  \brief Procedure which reads the value of a parameter that requires a float value (or a double value).
  \param file The file to read.
  \param buffer The name of the keyword*/
void load_float_keyword(FILE* file, char* buffer);

char* 
get_configuration_file_name()
{
  if(configuration_file_name==NULL)
    {
      error(USAGE_ERROR,"THE CONFIGURATION FILE HAS NOT ALREADY BE LOADED OR THE EXECUTION IS ALREADY FINISHED",
	    "CONFIGURATION_FILE_NAME IS NULL IN GET_CONFIGURATION_FILE_NAME IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  return configuration_file_name;
}

void
load_configuration(char* configuration_file)
{
  int read;
  char buffer[50];
  char keyword[50];

  FILE* file;

  configuration_file_name=(char*)malloc((strlen(configuration_file)+1)*sizeof(char));
  if(configuration_file_name==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMERY ALLOCATION HAS FAILED THE CONFIGURATION FILE NAME",
	    "CONFIGURATION_FILE_NAME IS NULL IN LOAD_CONFIGURATION IN ASCQ_ME_CONFIGURATION.CPP");
    }
  strcpy(configuration_file_name,configuration_file);

  read=0;
  file=NULL;

  tables_initialisation();

  init_util_digestion();

  load_modifications(MODIFICATION_FILENAME);

  file=fopen(configuration_file,"r");
  if(file==NULL)
    {
      error(IO_ERROR,"THE CONFIGURATION FILE DOES NOT EXIST OR IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_CONFIGURATION IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  do
    {
      jump_commentaries(file,'#');
      read=fscanf(file,"%s",buffer);
      if(read!=EOF)
	{
	  strcpy(keyword,buffer);
	}
      read=fscanf(file,"%s",buffer);

      if(read!=EOF)
	{
	  if(strcmp(buffer,"=")!=0)
	    {
	      error(USAGE_ERROR,"SYMBOL = WAITED AFTER THE KEYWORD IN THE CONFIGURATION FILE BUT NOT FOUND",
		    "BUFFER IS DIFFERENT FROM = IN LOAD_CONFIGURATION IN ASCQ_ME_CONFIGURATION.CPP");
	    }
	  
	  if((strcmp(keyword,"MIN_PEPTIDE_NB")==0)||
	     (strcmp(keyword,"MIN_MATCHED_PEPTIDE_NB")==0))
	    {
	      load_unsigned_int_keyword(file,keyword);
	    }
	  else if((strcmp(keyword,"MISSED_CLEAVAGES")==0)||
		  (strcmp(keyword,"ENZYME")==0)||
		  (strcmp(keyword,"NB_RESULTS")==0)||
		  (strcmp(keyword,"MAX_MASS")==0)||
		  (strcmp(keyword,"PEPTIDE_MAX_MASS")==0)||
		  (strcmp(keyword,"PEPTIDE_PRECISION")==0)||
		  (strcmp(keyword,"NB_C_ATOM")==0)||
		  (strcmp(keyword,"MAX_PEPTIDE_LENGTH")==0)||
		  (strcmp(keyword,"PRECISION")==0))
	    {
	      load_int_keyword(file,keyword);
	    }
	  else if((strcmp(keyword,"FULL_DIGEST")==0)||
		  (strcmp(keyword,"DECOY")==0)||
		  (strcmp(keyword,"FILE_TYPE")==0))
	    {
	      load_boolean_keyword(file,keyword);
	    }
	  else if((strcmp(keyword,"PEPTIDE_CHARGE")==0)||
		  (strcmp(keyword,"AMINO_ACID_B")==0)||
		  (strcmp(keyword,"AMINO_ACID_X")==0)||
		  (strcmp(keyword,"AMINO_ACID_Z")==0)||
		  (strcmp(keyword,"MODIFICATIONS")==0)||
		  (strcmp(keyword,"SPECIE")==0)||
		  (strcmp(keyword,"FASTA_FILE")==0)||
		  (strcmp(keyword,"SPECTRA_FILE")==0)||
		  (strcmp(keyword,"BASE_NAME")==0)||
		  (strcmp(keyword,"EXPERIMENTAL_SPECTRUM")==0))
	    {
	      load_string_keyword(file,keyword);
	    }
	  else if((strcmp(keyword,"GAUSSIAN")==0)||
		  (strcmp(keyword,"SENSITIVITY")==0)||
		  (strcmp(keyword,"EXP_MASS")==0)||
		  (strcmp(keyword,"MIN_EXP_MASS")==0)||
		  (strcmp(keyword,"MAX_EXP_MASS")==0)||
		  (strcmp(keyword,"THRESHOLD")==0))
	    {
	      load_float_keyword(file,keyword);
	    }
	  else
	    {
	      printf("%s = %d\n",keyword,(int)strlen(keyword));
	      error(USAGE_ERROR,"ONE OF THE KEYWORDS IN THE CONFIGURATION FILE IS NOT CORRECT",
		    "BUFFER HAS AN ODD VALUE IN LOAD_CONFIGURATION IN ASCQ_ME_CONFIGURATION.CPP");
	    }
	}
    }
  while(read!=EOF);

  fclose(file);

  if(get_distribution_activation()==FALSE)
    {
      error(USAGE_ERROR,"NO EXPERIMENTAL SPECTRUM HAS BEEN LOADED",
	    "IS_DISTRIBUTION_INITIALISED IS FALSE IN LOAD_CONFIGURATION IN ASCQ_ME_CONFIGURATION.CPP");
    }
}

void
load_int_keyword(FILE* file, char* buffer)
{
  char* unlimited_buffer;
  
  unlimited_buffer=NULL;
  
  if(file==NULL)
    {
      error(EXECUTION_ERROR,"THE CONFIGURATION FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  if(buffer==NULL)
    {
      error(EXECUTION_ERROR,"A KEYWORD HAS NOT BEEN CORRECTLY READ",
	    "BUFFER IS NULL IN LOAD_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }

  unlimited_buffer=read_line(file);

  if(unlimited_buffer!=NULL)
    {
      if(strcmp(buffer,"MISSED_CLEAVAGES")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_nb_missed_cleavages(atoi(unlimited_buffer));
	    }
	}
      else if(strcmp(buffer,"ENZYME")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_used_enzyme(atoi(unlimited_buffer));
	    }
	}
      else if(strcmp(buffer,"NB_RESULTS")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      nb_displayed_proteins=(atoi(unlimited_buffer));
	    }
	}
      else if(strcmp(buffer,"MAX_MASS")==0)
	{
	   if(get_distribution_activation()==TRUE)
	     {
	        error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE MAXIMUM MASS IS NOT MODIFIED",
		      "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	     }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_spectrum_maximum_mass(atoi(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"PEPTIDE_MAX_MASS")==0)
	{
	   if(get_distribution_activation()==TRUE)
	     {
	       error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE PEPTIDE MAXIMUM MASS IS NOT MODIFIED",
		      "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	     }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_peptide_maximum_mass(atoi(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"PEPTIDE_PRECISION")==0)
	{
	  if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE PEPTIDE PRECISION IS NOT MODIFIED",
		     "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	  else
	    {
	      if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		{
		  set_peptide_precision(atoi(unlimited_buffer));
		}
	    }
	}
      else if(strcmp(buffer,"NB_C_ATOM")==0)
	{
	  if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE NUMBER OF C ATOM IS NOT MODIFIED",
		    "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	  else
	    {
	      if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		{
		  set_C_atom_quantity(atoi(unlimited_buffer));
		}
	    }
	}
      else if(strcmp(buffer,"PRECISION")==0)
	{
	  if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE PRECISION IS NOT MODIFIED",
		    "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	  else
	    {
	      if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		{
		  set_precision(atoi(unlimited_buffer));
		}
	    }
	}
      else if(strcmp(buffer,"MAX_PEPTIDE_LENGTH")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_maximum_peptide_length(atoi(unlimited_buffer));
	    }
	}
      else
	{
	  error(USAGE_ERROR,"THE KEYWORD GIVEN DOES NOT REQUIRE AN INT VALUE",
		"BUFFER DOES NOT CORRESPOND TO A KEYWORD THAT HAS AN INT VALUE");
	}

      // BOUH !!!!
      free(unlimited_buffer);
    }
}

void
load_unsigned_int_keyword(FILE* file, char* buffer)
{
  int value;
  char* unlimited_buffer;
  
  unlimited_buffer=NULL;
  
  if(file==NULL)
    {
      error(EXECUTION_ERROR,"THE CONFIGURATION FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_UNSIGNED_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  if(buffer==NULL)
    {
      error(EXECUTION_ERROR,"A KEYWORD HAS NOT BEEN CORRECTLY READ",
	    "BUFFER IS NULL IN LOAD_UNSIGNED_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }

  unlimited_buffer=read_line(file);

  if(unlimited_buffer!=NULL)
    {
      value=atoi(unlimited_buffer);
      if(value<0)
	{
	  printf("%s = %d\n",buffer, value);
	  error(WARNING,"THE NEW VALUE FOR AN UNSIGNED INT PARAMETER IS NEGATIVE IN THE CONFIGURATION FILE, IT IS NOT CONSIDERED.",
		"VALUE IS NEGATIVE IN LOAD_UNSIGNED_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP"); 
	}

      if(strcmp(buffer,"MIN_PEPTIDE_NB")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_minimum_peptide_number((unsigned int)value);
	    }
	}
      else if(strcmp(buffer,"MIN_MATCHED_PEPTIDE_NB")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_minimum_matched_peptide_number((unsigned int)value);
	    }
	}
      else
	{
	  error(USAGE_ERROR,"THE KEYWORD GIVEN DOES NOT REQUIRE AN UNSIGNED INT VALUE",
		"BUFFER DOES NOT CORRESPOND TO A KEYWORD THAT REQUIRES AN UNSIGNED INT VALUE IN LOAD_UNSIGNED_INT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
	}
      
      free(unlimited_buffer);
    }
}

void
load_boolean_keyword(FILE* file, char* buffer)
{
  char* unlimited_buffer;
  
  int value;

  unlimited_buffer=NULL;
  value=-1;
  
  if(file==NULL)
    {
      error(EXECUTION_ERROR,"THE CONFIGURATION FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_BOOLEAN_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  if(buffer==NULL)
    {
      error(EXECUTION_ERROR,"A KEYWORD HAS NOT BEEN CORRECTLY READ",
	    "BUFFER IS NULL IN LOAD_BOOLEAN_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }

  unlimited_buffer=read_line(file);

  if(unlimited_buffer!=NULL)
    {
      if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	{
	  if(strncmp(unlimited_buffer,"YES",strlen("YES"))==0)
	    {
	      value=TRUE;
	    }
	  else if(strncmp(unlimited_buffer,"NO",strlen("FALSE"))==0)
	    {
	      value=FALSE;
	    }
	  else
	    {
	      error(USAGE_ERROR,"THE KEYWORD VALUE IS ODD IN THE CONFIGURATION FILE",
		    "UNLIMITED_BUFFER MUST BE TRUE OR FALSE IN LOAD_BOOLEAN_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
	    }
	}
      
      if(strcmp(buffer,"FULL_DIGEST")==0)
	{
	  
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      activate_full_digestion(value);
	    }
	}
      else if(strcmp(buffer,"DECOY")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      if(strncmp(unlimited_buffer,"NO",strlen("NO"))!=0)
		{
		  activate_decoy_mode();
		}
	    }
	}
      else if(strcmp(buffer,"FILE_TYPE")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      fasta_format=value;
	    }
	}
      else
	{
	  error(USAGE_ERROR,"THE KEYWORD GIVEN DOES NOT REQUIRE A BOOLEAN VALUE",
		"BUFFER DOES NOT CORRESPOND TO A KEYWORD THAT HAS A BOOLEAN VALUE");
	}
      
      free(unlimited_buffer);
    }
}

void
load_string_keyword(FILE* file, const char* buffer)
{
  char* unlimited_buffer;
  long offset_max;
  
  unlimited_buffer=NULL;
  offset_max=0;

  if(file==NULL)
    {
      error(EXECUTION_ERROR,"THE CONFIGURATION FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_STRING_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  if(buffer==NULL)
    {
      error(EXECUTION_ERROR,"A KEYWORD HAS NOT BEEN CORRECTLY READ",
	    "BUFFER IS NULL IN LOAD_STRING_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }

  unlimited_buffer=read_line(file);

  if(unlimited_buffer!=NULL)
    {
      if(strcmp(buffer,"PEPTIDE_CHARGE")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_peptide_charge(unlimited_buffer);
	    }
	}
      else if(strcmp(buffer,"AMINO_ACID_B")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_B(unlimited_buffer[0]);
	    }
	}
      else if(strcmp(buffer,"AMINO_ACID_X")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_X(unlimited_buffer[0]);
	    }
	}
      else if(strcmp(buffer,"AMINO_ACID_Z")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_Z(unlimited_buffer[0]);
	    }
	}
      else if(strcmp(buffer,"MODIFICATIONS")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      load_modification_configuration(unlimited_buffer);
	    }
	}
      else if(strcmp(buffer,"SPECIE")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_specie(unlimited_buffer);
	    }
	}
      else if(strcmp(buffer,"FASTA_FILE")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      //printf("%s %d\n", unlimited_buffer, (int)strlen(unlimited_buffer));
	      fastafopen(unlimited_buffer,&offset_max);
	    }
	  else
	    {
	      fastafopen("_fasta/albumin.fas",&offset_max);
	    }
	}
      else if(strcmp(buffer,"SPECTRA_FILE")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      read_simulated_spectrum(unlimited_buffer);
	    }
	  else
	    {
	      if(fasta_format==FALSE)
		{
		  read_simulated_spectrum("_simulated_spectra/simulated_spectra.txt");
		}
	    }
	}
      else if(strcmp(buffer,"BASE_NAME")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))==0)
	    {
	      base_name=(char*)malloc((strlen("default")+1)*sizeof(char));
	      if(base_name==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE DEFAULT BASE NAME",
			"BASE_NAME IS NULL IN LOAD_STRING_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
		}
	      strcpy(base_name,"default");
	    }
	  else
	    {
	      base_name=(char*)malloc((strlen(unlimited_buffer)+1)*sizeof(char));
	      if(base_name==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED FOR THE BASE NAME",
			"BASE_NAME IS NULL IN LOAD_STRING_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
		}
	      strcpy(base_name,unlimited_buffer);
	    }
	}
      else if(strcmp(buffer,"EXPERIMENTAL_SPECTRUM")==0)
	{
	  /*If the procedure is a success, distribution_activation will be called*/
	  init_distrib();
	  
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      read_spectrum(unlimited_buffer);
	    }
	  else
	    {
	      read_spectrum("_spectrum_data/Caro.txt");
	    }
	}
      else
	{
	  error(USAGE_ERROR,"THE KEYWORD GIVEN DOES NOT REQUIRE A STRING VALUE",
		"BUFFER DOES NOT CORRESPOND TO A KEYWORD THAT HAS A STRING VALUE");
	}
      free(unlimited_buffer);
    }
}

void
load_float_keyword(FILE* file, char* buffer)
{
  char* unlimited_buffer;
    
  unlimited_buffer=NULL;

  if(file==NULL)
    {
      error(EXECUTION_ERROR,"THE CONFIGURATION FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN LOAD_FLOAT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  if(buffer==NULL)
    {
      error(EXECUTION_ERROR,"A KEYWORD HAS NOT BEEN CORRECTLY READ",
	    "BUFFER IS NULL IN LOAD_FLOAT_KEYWORD IN ASCQ_ME_CONFIGURATION.CPP");
    }
  
  unlimited_buffer=read_line(file);
  
  if(unlimited_buffer!=NULL)
    {
      if(strcmp(buffer,"EXP_MASS")==0)
	{
	  if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
	    {
	      set_exp_protein_mass(atof(unlimited_buffer));
	    }
	}
      else if(strcmp(buffer,"GAUSSIAN")==0)
	{
	   if(get_distribution_activation()==TRUE)
	     {
	       error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE GAUSSIAN VALUE IS NOT MODIFIED",
		     "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	     }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_gaussian_value(atof(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"MIN_EXP_MASS")==0)
	{
	   if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE MINIMUM EXPERIMENTAL MASS IS NOT MODIFIED",
		     "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_minimum_mass((double)atof(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"MAX_EXP_MASS")==0)
	{
	   if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE MAXIMUM EXPERIMENTAL MASS IS NOT MODIFIED",
		    "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_maximum_mass((double)atof(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"SENSITIVITY")==0)
	{
	   if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE SENSITIVITY IS NOT MODIFIED",
		    "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_scoring_sensitivity((double)atof(unlimited_buffer));
		 }
	     }
	}
      else if(strcmp(buffer,"THRESHOLD")==0)
	{
	   if(get_distribution_activation()==TRUE)
	    {
	      error(WARNING,"THE EXPERIMENTAL SPECTRUM HAS BEEN ALREADY LOADED, FOR SECURITY, THE THRESHOLD IS NOT MODIFIED",
		    "THE VALUE OF UNLIMITED_BUFFER IS NOT USED");
	    }
	   else
	     {
	       if(strncmp(unlimited_buffer,"DEFAULT",strlen("DEFAULT"))!=0)
		 {
		   set_threshold((double)atof(unlimited_buffer));
		}
	     }
	}
      else
	{
	  error(USAGE_ERROR,"THE KEYWORD GIVEN DOES NOT REQUIRE A FLOAT/DOUBLE VALUE",
		"BUFFER DOES NOT CORRESPOND TO A KEYWORD THAT HAS A FLOAT/DOUBLE VALUE");
	}
      
      free(unlimited_buffer);
    }
  
}

void
ascq_me_configuration_cleaning()
{
  if(configuration_file_name!=NULL)
    {
      free(configuration_file_name);
    }

  if(base_name!=NULL)
    {
      free(base_name);
    }

  //printf("%s\n",(fasta_format==TRUE?"TRUE":"FALSE"));

  if(fasta_format==TRUE)
    {
      fastafclose();
    }
  
  free_activated_modification();
  free_all_modifications();
  free_isodistrib();
  free_util_digestion();
  free_tables();
}

int
is_fasta_chosen()
{
  return fasta_format;
}

void
print_configuration()
{
  printf("%s VERSION %s\n",PROGRAM_NAME, PROGRAM_VERSION);
  printf("CURRENT CONFIGURATION :\n\n");

  printf("Loaded from the configuration file : %s\n\n",configuration_file_name);

  printf("\tDigestion Section:\n");
  printf("\t\tNumber of miss cleavage = %d\n",get_nb_missed_cleavages());
  printf("\t\tActivation of full digestion = %s\n",get_activation_full_digest()==TRUE?"YES":"NO");
  printf("\t\tActivation of decoy mode = %s\n",is_decoy_mode_activated()==TRUE?"YES":"NO");
  printf("\t\tFormula of the peptid charge = %s\n",formula_tochar(get_peptide_charge_formula()));
  printf("\t\tEnzym used = %s\n",get_used_enzyme());
  if(get_number_of_activated_modifications()!=0)
    {
      print_modification_configuration();
    }
  if(get_maximum_peptide_length()==0)
    {
      printf("\t\tMaximum peptide length = no limit\n");
    }
  else
    {
      printf("\t\tMaximum peptide length = %d\n",get_maximum_peptide_length());
    }

  printf("\n\tI/O Section:\n");
  printf("\t\tDoes the fasta format have been chosen ? %s\n",is_fasta_chosen()==TRUE?"YES":"NO");
  if(is_fasta_chosen()==TRUE)
    {
      printf("\t\tFasta file name = %s\n",get_fasta_filename());
    }
  else
    {
      printf("\t\tSimulated spectra name = %s\n",get_simulated_spectra_filename());
    }
  printf("\t\tWanted specie (filter) = %s\n",get_specie()==NULL?"None":get_specie());
  printf("\t\tDoes an experimental mass have been given? %s ",is_exp_protein_mass_activated()==TRUE?"YES":"NO");
  if(is_exp_protein_mass_activated()==TRUE)
    {
      printf("==> %f",(float)get_exp_protein_mass());
    }
  printf("\n");
  printf("\t\tNumber of proteins results displayed = %d\n\n",get_nb_displayed_proteins());

  printf("\tSpectra Scoring Section:\n");
  printf("\t\tFourier Precision = %d\n",get_spectrum_precision());
  printf("\t\tSpectrum maximum mass = %d\n",get_spectrum_maximum_mass());
  printf("\t\tPeptide Precision = %d\n",get_peptide_precision());
  printf("\t\tPeptide maximum mass = %d\n",get_peptide_maximum_mass());
  printf("\t\tGaussian chosen = %f\n",(float)get_gaussian_value());
  printf("\t\tC quantity = %d\n",get_atom_quantity("C"));
  printf("\t\tH quantity = %d\n",get_atom_quantity("H"));
  printf("\t\tO quantity = %d\n",get_atom_quantity("O"));
  printf("\t\tN quantity = %d\n",get_atom_quantity("N"));
  printf("\t\tS quantity = %d\n",get_atom_quantity("S"));
  printf("\t\tSe quantity = %d\n",get_atom_quantity("Se"));
  printf("\t\tExperimental file name = %s\n",get_experimental_filename());
  printf("\t\tMinimal experimental mass = %f\n",get_minimum_mass());
  printf("\t\tMaximal experimental mass = %f\n",get_maximum_mass());
  printf("\t\tSensitivity = %0.2f\n",get_scoring_sensitivity());
  printf("\t\tThreshold = %0.9f\n",get_threshold());
  printf("\t\tMinimum peptide number to consider = %d\n",(int)get_minimum_peptide_number());
  printf("\t\tMinimum matched peptide number to consider = %d\n\n",(int)get_minimum_matched_peptide_number());
}

void
fprint_configuration(FILE* file)
{
  fprintf(file,"%s VERSION %s\n",PROGRAM_NAME, PROGRAM_VERSION);
  fprintf(file,"CURRENT CONFIGURATION :\n\n");

  fprintf(file,"Loaded from the configuration file : %s\n\n",configuration_file_name);

  fprintf(file,"\tDigestion Section:\n");
  fprintf(file,"\t\tNumber of miss cleavage = %d\n",get_nb_missed_cleavages());
  fprintf(file,"\t\tActivation of full digestion = %s\n",get_activation_full_digest()==TRUE?"YES":"NO");
  fprintf(file,"\t\tActivation of decoy mode = %s\n",is_decoy_mode_activated()==TRUE?"YES":"NO");
  char* formula=formula_tochar(get_peptide_charge_formula());
  fprintf(file,"\t\tFormula of the peptid charge = %s\n",formula);
  free(formula);
  fprintf(file,"\t\tEnzym used = %s\n",get_used_enzyme());
  
  if(get_number_of_activated_modifications()!=0)
    {
      fprint_modification_configuration(file);
    }
  
  if(get_maximum_peptide_length()==0)
    {
      fprintf(file,"\t\tMaximum peptide length = no limit\n");
    }
  else
    {
      fprintf(file,"\t\tMaximum peptide length = %d\n",get_maximum_peptide_length());
    }
  
  fprintf(file,"\n\tI/O Section:\n");
  fprintf(file,"\t\tDoes the fasta format have been chosen ? %s\n",is_fasta_chosen()==TRUE?"YES":"NO");
  
  if(is_fasta_chosen()==TRUE)
    {
      fprintf(file,"\t\tFasta file name = %s\n",get_fasta_filename());
    }
  else
    {
      fprintf(file,"\t\tSimulated spectra name = %s\n",get_simulated_spectra_filename());
    }
  
  fprintf(file,"\t\tWanted specie (filter) = %s\n",get_specie()==NULL?"None":get_specie());
  fprintf(file,"\t\tDoes an experimental mass have been given? %s ",is_exp_protein_mass_activated()==TRUE?"YES":"NO");
  
  if(is_exp_protein_mass_activated()==TRUE)
    {
      fprintf(file,"==> %f",(float)get_exp_protein_mass());
    }
  
  fprintf(file,"\n");
  fprintf(file,"\t\tNumber of proteins results displayed = %d\n\n",get_nb_displayed_proteins());

  fprintf(file,"\tSpectra Scoring Section:\n");
  fprintf(file,"\t\tFourier Precision = %d\n",get_spectrum_precision());
  fprintf(file,"\t\tSpectrum maximum mass = %d\n",get_spectrum_maximum_mass());
  fprintf(file,"\t\tPeptide Precision = %d\n",get_peptide_precision());
  fprintf(file,"\t\tPeptide maximum mass = %d\n",get_peptide_maximum_mass());
  fprintf(file,"\t\tGaussian chosen = %f\n",(float)get_gaussian_value());
  fprintf(file,"\t\tC quantity = %d\n",get_atom_quantity("C"));
  fprintf(file,"\t\tH quantity = %d\n",get_atom_quantity("H"));
  fprintf(file,"\t\tO quantity = %d\n",get_atom_quantity("O"));
  fprintf(file,"\t\tN quantity = %d\n",get_atom_quantity("N"));
  fprintf(file,"\t\tS quantity = %d\n",get_atom_quantity("S"));
  fprintf(file,"\t\tSe quantity = %d\n",get_atom_quantity("Se"));
  fprintf(file,"\t\tExperimental file name = %s\n",get_experimental_filename());
  fprintf(file,"\t\tMinimal experimental mass = %f\n",get_minimum_mass());
  fprintf(file,"\t\tMaximal experimental mass = %f\n",get_maximum_mass());
  fprintf(file,"\t\tSensitivity = %0.2f\n",get_scoring_sensitivity());
  fprintf(file,"\t\tThreshold = %0.9f\n",get_threshold());
  fprintf(file,"\t\tMinimum peptide number to consider = %d\n",(int)get_minimum_peptide_number());
  fprintf(file,"\t\tMinimum matched peptide number to consider = %d\n\n",(int)get_minimum_matched_peptide_number());
}

void
fprint_configuration_xml(FILE* file)
{
  fprintf(file,"<version>%s</version>\n",PROGRAM_VERSION);
  fprintf(file,"<configuration>\n");

  fprintf(file,"\t<configuration_file_name>%s</configuration_file_name>\n",configuration_file_name);

  fprintf(file,"\t<digestion_section>\n");
  fprintf(file,"\t\t<missed_cleavages>%d</missed_cleavages>\n",get_nb_missed_cleavages());
  fprintf(file,"\t\t<full_digestion>%s</full_digestion>\n",get_activation_full_digest()==TRUE?"YES":"NO");
  fprintf(file,"\t\t<decoy_mode>%s</decoy_mode>\n",is_decoy_mode_activated()==TRUE?"YES":"NO");
  fprintf(file,"\t\t<peptide_charge_formula>%s</peptide_charge_formula>\n",formula_tochar(get_peptide_charge_formula()));
  fprintf(file,"\t\t<enzyme>%s</enzyme>\n",get_used_enzyme());
  fprintf(file,"\t\t<modification_number>%d</modification_number>\n",get_number_of_activated_modifications());
  if(get_number_of_activated_modifications()!=0)
    {
      fprint_xml_modification_configuration(file);
    }
  fprintf(file,"\t\t<maximum_peptide_length>%d</maximum_peptide_length>\n",get_maximum_peptide_length());
  fprintf(file,"\t</digestion_section>\n");

  fprintf(file,"\t<io_section>\n");
  fprintf(file,"\t\t<fasta>%s</fasta>\n",is_fasta_chosen()==TRUE?"YES":"NO");
  if(is_fasta_chosen()==TRUE)
    {
      fprintf(file,"\t\t<filename>%s</filename>\n",get_fasta_filename());
    }
  else
    {
      fprintf(file,"\t\t<filename>%s</filename>\n",get_simulated_spectra_filename());
    }
  fprintf(file,"\t\t<specie_filter>%s</specie_filter>\n",get_specie()==NULL?"None":get_specie());
  fprintf(file,"\t\t<protein_nb>%d</protein_nb>\n",get_nb_displayed_proteins());
  fprintf(file,"\t</io_section>\n");
  
  fprintf(file,"\t<spectra_scoring_section>\n");
  fprintf(file,"\t\t<fourier_precision>%d</fourier_precision>\n",get_spectrum_precision());
  fprintf(file,"\t\t<spectrum_maximum_mass>%d</spectrum_maximum_mass>\n",get_spectrum_maximum_mass());
  fprintf(file,"\t\t<peptide_precision>%d</peptide_precision>\n",get_peptide_precision());
  fprintf(file,"\t\t<peptide_maximum_mass>%d</peptide_maximum_mass>\n",get_peptide_maximum_mass());
  fprintf(file,"\t\t<gaussian>%f</gaussian>\n",(float)get_gaussian_value());
  fprintf(file,"\t\t<C_quantity>%d</C_quantity>\n",get_atom_quantity("C"));
  fprintf(file,"\t\t<H_quantity>%d</H_quantity>\n",get_atom_quantity("H"));
  fprintf(file,"\t\t<O_quantity>%d</O_quantity>\n",get_atom_quantity("O"));
  fprintf(file,"\t\t<N_quantity>%d</N_quantity>\n",get_atom_quantity("N"));
  fprintf(file,"\t\t<S_quantity>%d</S_quantity>\n",get_atom_quantity("S"));
  fprintf(file,"\t\t<Se_quantity>%d</Se_quantity>\n",get_atom_quantity("Se"));
  fprintf(file,"\t\t<experimental_filename>%s</experimental_filename>\n",get_experimental_filename());
  fprintf(file,"\t\t<minimal_experimental_mass>%f</minimal_experimental_mass>\n",get_minimum_mass());
  fprintf(file,"\t\t<maximal_experimental_mass>%f</maximal_experimental_mass>\n",get_maximum_mass());
  fprintf(file,"\t\t<sensitivity>%0.2f</sensitivity>\n",get_scoring_sensitivity());
  fprintf(file,"\t\t<threshold>%0.9f</threshold>\n",get_threshold());
  fprintf(file,"\t\t<minimum_peptide_number>%d</minimum_peptide_number>\n",(int)get_minimum_peptide_number());
  fprintf(file,"\t\t<minimum_matched_peptide_number>%d</minimum_matched_peptide_number>\n",(int)get_minimum_matched_peptide_number());
  fprintf(file,"\t</spectra_scoring_section>\n");

  fprintf(file,"</configuration>\n");
}



void
activate_decoy_mode()
{
  decoy_mode_activation=TRUE;
}

int
is_decoy_mode_activated()
{
  return decoy_mode_activation;
}

void
set_decoy_score(double score)
{
  decoy_score=score;
}

double
get_decoy_score()
{
  return decoy_score;
}

int
get_nb_displayed_proteins()
{
  return nb_displayed_proteins;
}

const char*
get_base_name()
{
  return base_name;
}
