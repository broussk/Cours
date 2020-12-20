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
  \file complex.cpp
  \author Jean-Charles BOISSON (2006-2008).
  \brief Implementation of the methods defined in complex.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "complex.h"

complex_t
complex_multiplication(complex_t z1, complex_t z2)
{
  complex_t z3;
  
  z3.Re= z1.Re*z2.Re - z1.Im*z2.Im;
  z3.Im= z1.Im*z2.Re + z1.Re*z2.Im;
  
  return z3;
}

complex_t
complex_addition(complex_t z1, complex_t z2)
{
  complex_t z3;
  
  z3.Re= z1.Re+z2.Re;
  z3.Im= z1.Im+z2.Im;
  
  return z3;
}

complex_t
complex_subtraction(complex_t z1, complex_t z2)
{
  complex_t z3;

  z3.Re= z1.Re-z2.Re;
  z3.Im= z1.Im-z2.Im;

  return z3;
}

complex_t
complex_power(complex_t z, int n)
{
  int i;
  complex_t z2;
  
  i=0;
  z2.Re=1;
  z2.Im=0;

  while(i!=n) 
    {
      z2 = complex_multiplication(z2,z);
      i++;
    }
  return z2;
}


complex_t
complex_conjugate(complex_t z)
{
  complex_t z2;
  
  z2.Re= z.Re;
  z2.Im = -z.Im;
  
  return z2;
}
