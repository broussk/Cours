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
 * \file general.h
 * \brief all data types and constant data needed by the rest of the program
 * \author Emmanuel
*/

#ifndef _GENERAL_H_
#define _GENERAL_H_


#include<string>


#define PREC float
#define CAST_PREC static_cast<PREC>

const int 	MAX_THREAD		= 32;
const int 	NB_KNW_ATMS		= 18;
#define NKA NB_KNW_ATMS
const PREC 	ALPHA 			= 0.16162045967f;
const PREC 	ONE_THIRD 		= 0.33333333333333f;
const PREC 	FOUR_THIRD 		= 1.33333333333333f;
const PREC 	BOHRTOA 		= 0.52917720859f;
const PREC 	R_TRESHOLD		= 0.0000001f;
const PREC 	DEFAULT_CUTOFF 	= 0.2f;    
const PREC 	LN_2			= 0.69314718056f;
const PREC 	NaN 			= 0.f;
const PREC 	PI				= 3.141592653589793f;
const PREC 	PI_2			= 6.28318530718f;
const PREC 	PI_4			= 12.5663706144f;
const PREC 	A1[NB_KNW_ATMS] = { 0.2815f, 2.437f, 11.84f, 31.34f, 67.82f, 120.2f, 190.9f, 289.5f, 406.3f, 561.3f, 760.8f, 1016.f, 1319.f, 1658.f, 2042.f, 2501.f, 3024.f, 3625.f };
const PREC 	A2[NB_KNW_ATMS] = { 0.0f, 0.0f, 0.06332f, 0.3694f, 0.8527f, 1.172f, 2.247f, 2.879f, 3.049f, 6.984f, 22.42f, 37.17f, 57.95f, 87.16f, 115.7f, 158.0f, 205.5f, 260.0f };
const PREC 	A3[NB_KNW_ATMS] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.06358f, 0.3331f, 0.8878f, 0.7888f, 1.465f, 2.170f, 3.369f, 5.211f };
const PREC 	B1[NB_KNW_ATMS] = { 1.8910741301059f, 2.95945546019532f, 5.23012552301255f, 7.19424460431655f, 9.44287063267233f, 11.3122171945701f, 
								13.0378096479791f, 14.9476831091181f, 16.4473684210526f, 18.2149362477231f, 20.1612903225806f, 22.271714922049f, 
								24.330900243309f, 26.1780104712042f, 27.9329608938547f, 29.8507462686567f, 31.7460317460318f, 33.7837837837838f };
const PREC 	B2[NB_KNW_ATMS] = { 1.000000f, 1.000000f, 1.00080064051241f, 1.43988480921526f, 1.88679245283019f, 1.82481751824818f, 2.20653133274492f, 
								2.51635631605435f, 2.50375563345018f, 2.90107339715695f, 3.98247710075667f, 4.65116279069767f, 5.33617929562433f, 
								6.0459492140266f, 6.62690523525514f, 7.30460189919649f, 7.9428117553614f, 8.56164383561644f };
const PREC 	B3[NB_KNW_ATMS] = { 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 1.000000f, 0.9769441187964f, 
								1.28982329420869f, 1.67728950016773f, 1.42959256611866f, 1.70910955392241f, 1.94212468440474f, 2.01045436268597f, 2.26654578422484f };
								
const PREC WDV_VALUES[NKA]	= { 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f };
								
/* Structure used for the storage of all vectors' norms for the gradients */
typedef struct{

	PREC grad;
	PREC gradIGM;
	PREC gradIGMInter;
	PREC gradIGMInter2;
	PREC gradIGMInter3;
	
}norms_t;

/* Structure used for the storage of the parameter read from the parameter file */
typedef struct{
	
	std::string molAFileName;		/* the name of the files of the molcule A 				*/
	std::string molBFileName;		/* the name of the files of the molcule B 				*/
	std::string outputName;			/* the output name 										*/
	PREC radiusRoundLigand;			/* the radius around the molecule (in angstrom) 		*/
	PREC intermolecular;			/* the intermolecular value 							*/
	int numLigand;					/* the number of the molecule 							*/
	int nbFiles;					/* the number of files 									*/
	int outputType;					/* the type of the option OUTPUT 						*/
	PREC radius[4];					/* the arguments of the option RADIUS */
	PREC cutoffs[2];				/* the arguments of the option CUTOFFS 					*/
	PREC cutplot[2];				/* the arguments of the option CUTPLOT */
        PREC cutplotIGM[2];                             /* the arguments of the option CUTPLOT_IGM */
        PREC vmdcolrangIGM[2];                          /* the arguments of the option VMD_COLRANG_IGM */
	PREC cube[6];					/* the arguments of the option CUBE 					*/
	PREC increments[3];				/* the increments for xyz dimensions 					*/
	bool cubeUsed;					/* true if CUBE option has been used 					*/
        bool radiusUsed;                                /* true if RADIUS option has been used                                    */
	
}param_t;



/* The cubes' types */
typedef enum CUBE_TYPES{
	TYPE_DELTA_G_INTRA,
	TYPE_DELTA_G_INTER,
	/*TYPE_DELTA_K_INTRA,
	TYPE_DELTA_K_INTER,*/
	SIZE_CUBE_DELTA,
	TYPE_RHO,
	TYPE_RDG
}cube_types_t;

/* The outputs' types */
typedef enum OUTPUT_TYPES{
	OUTPUT_NONE,
	OUTPUT_DAT,
	OUTPUT_RHO_RDG,
	OUTPUT_DELTA,
	OUTPUT_PERCENT,
	OUTPUT_ALL
}output_types_t;

typedef struct{
	
	PREC x;
	PREC y;
	PREC z;	
	
}position_t,axis_t;

typedef PREC threadDuplication_t[MAX_THREAD];

typedef struct{

	PREC * __restrict xValues;
	PREC * __restrict yValues;
	PREC * __restrict zValues;

}positions_t;

#endif
