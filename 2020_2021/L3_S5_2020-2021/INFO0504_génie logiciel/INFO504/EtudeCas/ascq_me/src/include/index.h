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
  \file index.h
  \author Jean-Charles BOISSON (2006-2008).
  \brief Main page of the ASCQ_ME documentation.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

/** @mainpage Welcome to ASCQ_ME (Villeneuve d'ASCQ Mass Engine)

@section licence Licence

Copyright USTL (Universit&eacute; des Sciences et Technologies de Lille, FRANCE)
<BR>
Contributor(s):
<TABLE BORDER=0>
  <TR>
    <TD>
      <A HREF="http://www.lifl.fr/~boisson" TARGET=blank>Jean-Charles BOISSON</A>
    </TD>
  </TR>
  <TR>
    <TD>
      <A HREF="http://www.lifl.fr/~jourdan" TARGET=blank>Laetitia JOURDAN</A>
    </TD>
  </TR>
  <TR>
    <TD>
      <A HREF="http://www.lifl.fr/~talbi" TARGET=blank>El-Ghazali TALBI</A>
    </TD>
  </TR>
  <TR>
    <TD>
      Olivia GUERRE
    </TD>
  </TR>
  <TR>
    <TD>
      <A HREF="http://w2.ensc-lille.fr/recherche/lcom/lcom.html" TARGET=blank>Christian Rolando</A>
    </TD>
  </TR>
</TABLE>

<BR>

Developer(s):
<TABLE BORDER=0>
  <TR>
    <TD>
      Jean-Charles BOISSON
    </TD>
  </TR>
  <TR>
    <TD>
      Nicolas DOLET
    </TD>
  </TR>
  <TR>
    <TD>
      Nicolas GRUSZCZYNSKA
    </TD>
  </TR>
  <TR>
    <TD>
      Pierre LAURENCE
    </TD>
  </TR>
  <TR>
    <TD>
      Christian ROLANDO
    </TD>
  </TR>
  <TR>
    <TD>
      David BOENS
    </TD>
  </TR>
</TABLE>
     
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
<a href="http://www.cecill.info">"http://www.cecill.info"</a>. 
  
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

// coding: iso-8859-1
// mode: C
// c-file-style: "Stroustrup"
// fill-column: 80
// End:
