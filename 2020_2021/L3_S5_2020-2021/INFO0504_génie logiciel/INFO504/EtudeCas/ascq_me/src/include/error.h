/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s): 
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
  \file error.h
  \author Jean-Charles BOISSON (2006-2008).
  \brief Definition of the error management.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.
  
  Each type of error is associated to a value and 2 types of messages are used one for the user and the other for the developper.*/
#ifndef _error_h
#define _error_h

#include <stdio.h>
#include <stdlib.h>

/*! 
  \def PROGRAM_NAME
  \brief The name of the program.*/
#define PROGRAM_NAME "ASCQ_ME"

/*! 
  \def PROGRAM_VERSION
  \brief The current version of the program.*/
#define PROGRAM_VERSION "1.0.6"

/*! 
  \def IO_ERROR
  \brief The first type of error.
   
  Error corresponding to in/out errors (generally during the file using).*/
#define IO_ERROR 1

/*!
  \def USAGE_ERROR
  \brief The second type of error.
   
  Error corresponding to user errors (generally bad values for the method parameters).*/
#define USAGE_ERROR 2

/*!
  \def EXECUTION_ERROR
  \brief The third type of error.
   
  Error corresponding to unexpected error during the traitment.*/
#define EXECUTION_ERROR 3

/*! 
  \def MEMORY_ALLOCATION_ERROR
  \brief The fourth type of error.
  
  Error corresponding to the failure of a malloc or a equivalent method (NULL has been returned).*/
#define MEMORY_ALLOCATION_ERROR 4

/*!
  \def FREE_MEMORY_ERROR
  \brief The fifth type of error.
  
  Error corresponding to try to call the free method on a struct that is NULL.*/
#define FREE_MEMORY_ERROR 5

/*!
  \def WARNING
  \brief Definition that allows to indicate that something strange happens.
  
  This definition corresponds to something that is not a error (the program is not stopped) but it can be interesting to the
  user to know the detail.*/
#define WARNING 10

/*! 
  \fn void error(int error_code,const char* user_msg, const char* dev_msg)
  \brief procedure which allows to throw an error.
  \param error_code the error code.
  \param user_msg the message for the user.
  \param dev_msg the message for the developer.*/
void error(int error_code,const char* user_msg, const char* dev_msg);

#endif
