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
  \file error.cpp
  \author Jean-Charles BOISSON (2006-2008).
  \brief Implementation of the methods defined in error.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "error.h"

void error(int error_code,const char* user_msg, const char* dev_msg)
{
  if(error_code==WARNING)
    {
      printf("!!!!!!!!!!WARNING!!!!!!!!!!\n");
    }

  printf("[%s version %s : INFORMATION FOR USER]\n\t%s\n",PROGRAM_NAME, PROGRAM_VERSION, user_msg);
  printf("[%s version %s : DEBUG INFORMATION   ]\n\t%s\n",PROGRAM_NAME, PROGRAM_VERSION, dev_msg);
  
  if(error_code==WARNING)
    {
      return;
    }

  if((error_code!=IO_ERROR)&&
     (error_code!=USAGE_ERROR)&&
     (error_code!=EXECUTION_ERROR)&&
     (error_code!=MEMORY_ALLOCATION_ERROR)&&
     (error_code!=FREE_MEMORY_ERROR))
    {
      error(USAGE_ERROR,"UNKNOWN ERROR CODE USED","IN ERROR IN ERROR.CPP");
    }
  exit(error_code);
}
