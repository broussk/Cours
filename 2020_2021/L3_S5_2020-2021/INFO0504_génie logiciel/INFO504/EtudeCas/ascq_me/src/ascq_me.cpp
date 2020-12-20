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
  \file ascq_me.cpp
  \author Jean-Charles BOISSON (2005-2008).
  \brief ASCQ_ME main program.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

//#include "ascq_me_configuration.h"
#include "ascq_me_display.h"

/*! 
  \def ASCQ_ME_TABLE_RESULT
  \brief Default format of the table results of ASCQ_ME.*/
#define ASCQ_ME_TABLE_RESULT "_ascq_me_table_results.txt"

/*! 
  \def ASCQ_ME_RESULT
  \brief Default format of the text results of ASCQ_ME.*/
#define ASCQ_ME_RESULT "_ascq_me_results.txt"

/*! 
  \def ASCQ_ME_PEPTIDES_SCORING
  \brief Default format of the peptide scoring of ASCQ_ME.*/
#define ASCQ_ME_PEPTIDES_SCORING "_ascq_me_peptides_scoring.txt"

void print_ascq_me_usage();

/*!
  \fn int main(int argc, char* argv[])
  \brief ASCQ_ME main function.
  \param argc The number of parameters of the ASCQ_ME command including the ASCQ_ME command.
  \param argv The parameters.
  \result The return code of the ASCQ_ME command.*/
int 
main (int argc, char * argv []) 
{
  int protein_number,nb_peptides,xml;
  unsigned int i;
  long offset;
  time_t digestion_start, score_start, digestion_end, score_end;
  double score, decoy_score, digestion_duration, score_duration;

  formula_t *peptides;
  char *buffer , *xml_buffer, *sequence;

  FILE *table_file, *file, *peptide_scoring;

  protein_number=nb_peptides=0;
  xml=FALSE;
  peptides=NULL;
  offset=0;
  buffer=xml_buffer=sequence=NULL;
  file=table_file=peptide_scoring=NULL;

  score=decoy_score=digestion_duration=score_duration=0.0;

  if(argc<2 || argc>5)
    {
      printf("%s version %s\n",PROGRAM_NAME, PROGRAM_VERSION);
      print_ascq_me_usage();
      return(EXIT_FAILURE);
    }
  
  for(i=1;i<(unsigned int)(argc-1);i++)
    {
      if(strcmp(argv[i],"-xml")==0)
	{
	  xml=TRUE;
	}
      else if((strcmp(argv[i],"-v")==0)||(strcmp(argv[i],"--verbose")==0))
	{
	  activate_verbose_mode();
	}
      else if((strcmp(argv[i],"-h")==0)||(strcmp(argv[i],"--help")==0))
	{
	  print_ascq_me_usage();
	}
      else
	{
	  print_ascq_me_usage();
	  error(USAGE_ERROR,"MAYBE AN ADDITIONNAL UNKNOWN OPTION HAS BEEN GIVEN ON THE COMMAND LINE",
		"ERROR ON THE COMMAND LINE IN \"MAIN\" FUNCTION IN ASCQ_ME.CPP");
	}
    }

  if(is_verbose_mode_activated()==TRUE)
    {
      printf("%s version %s\n",PROGRAM_NAME, PROGRAM_VERSION);
      printf("With configuration file = %s\n\n",argv[argc-1]);
    }

  if((strcmp(argv[argc-1],"-h")==0)||(strcmp(argv[argc-1],"--help")==0))
    {
      print_ascq_me_usage();
      return EXIT_SUCCESS;
    }

  load_configuration(argv[argc-1]);

  init_ascq_me_display();

  buffer=add_chains(get_base_name(),ASCQ_ME_TABLE_RESULT);
  table_file=fopen(buffer,"w");
  if(table_file==NULL)
    {
      error(IO_ERROR,"THE ASCQ_ME TABLE FORMAT RESULT FILE IS NOT CORRECTLY OPENED",
	    "TABLE_FILE IS NULL IN MAIN IN ASCQ_ME.CPP");
    }
  
  free(buffer);
  buffer=add_chains(get_base_name(),ASCQ_ME_RESULT);

  if (!xml)
    {
      file=fopen(buffer,"w");
    }
  else
    {
      xml_buffer=add_chains(buffer,".xml");
      file=fopen(xml_buffer,"w");
      free(xml_buffer);
    }
  
  if(file==NULL)
    {
      error(IO_ERROR,"THE ASCQ_ME RESULT FILE IS NOT CORRECTLY OPENED",
	    "FILE IS NULL IN MAIN IN ASCQ_ME.CPP");
    }

  free(buffer);
  buffer=add_chains(get_base_name(),ASCQ_ME_PEPTIDES_SCORING);
  peptide_scoring=fopen(buffer,"w");
  free(buffer);
  if(peptide_scoring==NULL)
    {
      error(IO_ERROR,"THE ASCQ_ME PEPTIDES SCORING FILE IS NOT CORRECTLY OPENED",
	    "PEPTIDES_SCORING IS NULL IN MAIN IN ASCQ_ME.CPP");
    }

  if(is_fasta_chosen()==TRUE)
    {
      while (nextEntry (&(offset)))
	{
	  if(is_a_wanted_protein()==TRUE)
	    {
	      protein_number++;
	      sequence=getSeq();
	      
	      if(is_verbose_mode_activated()==TRUE)
		{
		  printf("Protein %d\n",protein_number);
		  printf("Description : %s\n",getDesc());
		}
	      
	      time(&digestion_start);
	      real_digest (sequence);
	      time(&digestion_end);

	      digestion_duration += difftime(digestion_end, digestion_start);

	      peptides=get_formulae_of_peptides(&nb_peptides);
	      
	      time(&score_start);
	      score=optimized_isotopic_distribution(peptides,nb_peptides);
	      time(&score_end);
	      
	      score_duration += difftime(score_end, score_start);

	      save_partial_peptide_scoring(get_current_peptide_score_save(),get_current_peptide_score_size());
	      
	      add_protein(getDesc(),sequence,get_theo_spectrum(),score);
	      

	      free_n_formula(peptides,nb_peptides);

	      if(is_decoy_mode_activated()==TRUE)
		{
		  sequence=get_reversed_sequence();
		  
		  time(&digestion_start);
		  real_digest (sequence);
		  time(&digestion_end);
		  
		  digestion_duration += difftime(digestion_end, digestion_start);
		  
		  peptides=get_formulae_of_peptides(&nb_peptides);
		  
		  time(&score_start);
		  decoy_score+=optimized_isotopic_distribution(peptides,nb_peptides);
		  time(&score_end);
		  
		  score_duration += difftime(score_end, score_start);

		  free_n_formula(peptides,nb_peptides);
		  free(sequence);
		}
	    }
	}
    }
  else
    {
      /*This part is not used for the moment... no score associated.*/
      while(next_simulated_spectrum()==TRUE)
	{
	  if(is_simulated_wanted_protein()==TRUE)
	    {
	      protein_number++;
	      
	      printf("Protein %d\n",protein_number);
	      printf("Description : %s\n",get_spectrum_original_description());
	      
	      //The score calculation is missing.
	      
	      add_protein(get_spectrum_original_description(),get_spectrum_original_sequence(),get_theo_spectrum(),score);
	    }
	}
    }

  if(is_decoy_mode_activated()==TRUE)
    {
      decoy_score/=protein_number;
      set_decoy_score(decoy_score);
    }

  if (xml)
    {
      fprintf(file,"<ascq_me_results>");
      fprint_configuration_xml(file);
      fprintf_ascq_me_results_xml(file);
      fprintf(file,"</ascq_me_results>");
    }
  else
    {
      fprint_configuration(file);
      fprintf_ascq_me_results(file);
    }
  
  if(is_verbose_mode_activated()==TRUE)
    {
      printf("\n\tDigestion = %f\n", digestion_duration); 
      printf("\tScoring = %f\n\n", score_duration); 
    }

  fprintf_ascq_me_results_table_form(table_file);

  fprintf_ascq_me_peptide_scoring(peptide_scoring);
  
  /*if(is_fasta_chosen()==TRUE)
    {
      fastafclose();
      }*/
  
  ascq_me_cleaning();

  ascq_me_configuration_cleaning();
  
  fclose(file);

  fclose(table_file);
  
  fclose(peptide_scoring);
  
  return EXIT_SUCCESS;
}

void
print_ascq_me_usage()
{
  printf("\nUSAGE : ascq_me [OPTION] configuration_file\n");
  printf("With OPTION (given separately) = \n");
  printf("\t-h (or --help) for printing this message.\n");
  printf("\t-v (or --verbose) for activating the verbose mode.\n");
  printf("\t-xml for activating the xml mode (basically for on-line version).\n\n");
}
