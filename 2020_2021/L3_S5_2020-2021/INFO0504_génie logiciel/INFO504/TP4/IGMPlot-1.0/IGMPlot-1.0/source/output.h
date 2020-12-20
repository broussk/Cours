/*
 * Copyright University of Reims Champagne-Ardenne
 * Authors: Emmanuel PLUOT, Gaetan RUBEZ, Jean-Charles-BOISSON and Eric HENON
 * Contributors: Hassan Khartabil, Corentin Lefebvre, Julia Contreras-Garcia
 * (24/07/2017)
 *
 * jean-charles.boisson@univ-reims.fr, eric.henon@univ-reims.fr
 *
 * This software is a computer program whose purpose is to 
 * detect and prepare the plot of molecular interactions
 * from electron density and IGM reference using promolecular
 * electron density.
 *
 * This software is governed by the CeCILL-C license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL-C
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info". 
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-C license and that you accept its terms.
 *
 * */

/**
* \file output.h
* \brief output's header.
* \author Gaetan & Emmanuel 
*/


#ifndef _OUTPUT_H_
#define _OUTPUT_H_

//#include"general.h"
#include"ProgData.h"
#include"Results.h"

#include "vmdFileGenerator.h"

/* The cubes' names */
const std::string CUBE_NAMES [] = {
	"dgIntra",
	"dgInter",
	"dkIntra",
	"dkInter"
};


/* The VMD script's intern keywords */
const std::string KEYWORDS [] = {
	"XX_DGINTER_XX",				/**< Path to Delta G inter cube file	*/
	"XX_DGINTRA_XX",				/**< Path to Delta G intra cube file	*/
	"XX_DENS_XX",					/**< Path to rho cube file 				*/
        "XX_RDG_XX",                                    /**< Path to RDG cube file  */
	"XX_PERCENT_XX",				/**< Path to percent data file	 		*/
	"XX_COMPLEX_XX",				/**< Path to the complex file created	*/
	"XX_CUTPLOT1_XX",				/**< cutplot[0] value					*/
	"XX_CUTPLOT2_XX",				/**< cutplot[1] value					*/
        "XX_CUTPLOTIGM1_XX",                            /**< cutplotIGM[0] value                                */
        "XX_CUTPLOTIGM2_XX",                            /**< cutplotIGM[1] value                                */
        "XX_VMDCOLRANGIGM1_XX",                         /**< vmdcolrangIGM[0] value                                */
        "XX_VMDCOLRANGIGM2_XX",                         /**< vmdcolrangIGM[1] value                                */
	"XX_CUTOFFS1_XX",				/**< cutoffs[0] value					*/
	"XX_CUTOFFS2_XX",				/**< cutoffs[1] value					*/
	"XX_FIRST_PROT_INDEX_XX",		/**< Index of first atom of molecule B	*/
	"XX_LAST_COMPLEX_INDEX_XX",		/**< Index of last atom of all complex	*/
	"XX_LAST_LIG_INDEX_XX",			/**< Index of last atom in molecule A	*/
	"XX_MAX_PERCENT_XX"				/**< Maximum percentage found 			*/
};




/* The VMD script's type names */
const int SCRIPT_NAMES_LENGTH = 3;
const std::string SCRIPT_NAMES [] = { /** add extension .tvmd on disk */
	"atContr",
        "nci",
        "igm"
};


void outCube	(int, 		param_t*, 	ProgData*, 	PREC*,	PREC*	);
void outCubeRDG	(param_t*, 	ProgData*, 	PREC*,		PREC*,	bool*	);
void outCubeRho	(param_t*, 	ProgData*, 	PREC*						);
void outDat		(param_t*, 	ProgData*, 	Results&					);
void outPercent	(param_t*,	Results&,	PREC						);
void outVMD		(param_t*, 	ProgData*, 	PREC						);

std::string getWorkPath();
std::string getExecPath();


#endif 

