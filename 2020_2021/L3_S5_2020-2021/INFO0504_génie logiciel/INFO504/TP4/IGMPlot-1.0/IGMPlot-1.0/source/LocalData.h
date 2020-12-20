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
#ifndef _LOCAL_DATA_H_
#define _LOCAL_DATA_H_



#include<cstdlib>
#include<cmath>
#include<iomanip>
#include"general.h"



/**
 * \file LocalData.h
 * \brief Class designed to store Gradient related values and provide some utilities concerning those
 * /!\ No copy constructor defined, careful when trying to pass this by value /!\
 * \author Emmanuel
*/
class LocalData{
	
	private :
		
		/* Non Gradient related values 																		*/
		int nbAtomInMolA; 							/* Number of atom in the first molecule 				*/
		int nbAtom;									/* Number of atom 										*/
		
		/* Gradient values 																					*/
		PREC grad[3];								/* Gradient values 										*/
		PREC gradIGM[3];							/* Gradient IGM values									*/
		PREC contributionInsideMoleculeA[3];		/* Contribution gradient inside molecule A 				*/
		PREC contributionInsideMoleculeB[3];		/* Contribution gradient inside molecule B 				*/
		axis_t * contributionAtomicAlone;			/* Contribution gradient for focused atom alone or all 	*/
		
		/* Unique initialization gradient values 															*/
		PREC gradIGMInter[3];						/* Axis values for IGM Inter							*/
		PREC gradIGMAbsOut[3];						/* Axis values for IGM Inter ( | molA + Atom | )		*/
		PREC gradIGMAbsIn[3];						/* Axis values for IGM Inter ( | molA | + | atom | )	*/
		
		/* Vectors' norms' values 																			*/
		PREC normGrad;								/* Gradient's vector's norm								*/
		PREC normGradIGM;							/* Gradient IGM's vector's norm							*/
		PREC normGradIGMInter;						/* Gradient IGM inter's vector's norm					*/
		PREC normGradIGMInterAbsOut;				/* Gradient IGM inter's vector's norm (| molA + Atom |)	*/
		PREC normGradIGMInterAbsIn;					/* Gradient IGM inter's vector's norm (|molA| + |Atom|)	*/
		
	public :
	
		/**
		 * \fn inline LocalData(int nbAtomInMolAParam, int nbAtomParam, Focusor &focParam)
		 * \brief Constructor
		 * \param nbAtomInMolAParam : the number of atom in the first molecule
		 * \param nbAtomParam : the number of atom
		*/
		inline LocalData(int nbAtomInMolAParam, int nbAtomParam) : nbAtomInMolA(nbAtomInMolAParam), nbAtom(nbAtomParam){
			
			
			/* Allocating memory */
			contributionAtomicAlone = new axis_t[ nbAtom ];
			
			/* Initializing values */
			reinit();
			
		}
		
		/**
		 * \fn inline ~LocalData()
		 * \brief Destructor
		 * Free space for the atom's contribution
		*/
		inline ~LocalData(){
			
			delete [] contributionAtomicAlone;	
			
		}
		 
		/**
		 * \fn inline void init()
		 * \brief Function used to initialize values to 0 
		*/
		inline void init(){
			
			/* Looping through the arrays */
			for(int i(0); i < 3 ; ++i){
			
				/* Value setting */
				grad[i]								= 0.f;
				gradIGM[i] 							= 0.f;
				contributionInsideMoleculeA[i]		= 0.f;
				contributionInsideMoleculeB[i]		= 0.f;
				
			}	
			
			/* Looping through the atoms */
			for( int j(0) ; j < nbAtom ; ++j ){
				
				contributionAtomicAlone[j].x		= 0.f;
				contributionAtomicAlone[j].y		= 0.f;
				contributionAtomicAlone[j].z		= 0.f;
				
			}
			
		}
		 
		/**
		 * \fn inline void reinit()
		 * \brief Function used to reinitialize values to 0 
		*/
		inline void reinit(){
		
			/* Looping through the arrays */
			for(int i(0); i < 3 ; ++i){
			
				/* Value setting */
				grad[i]								= 0.f;
				gradIGM[i] 							= 0.f;
				contributionInsideMoleculeA[i]		= 0.f;
				contributionInsideMoleculeB[i]		= 0.f;
				
				/* One init values */
				gradIGMInter[i]						= 0.f;
				gradIGMAbsOut[i]					= 0.f;
				gradIGMAbsIn[i]						= 0.f;
				
				
			}	
				
			/* Looping through the atoms */
			for( int j(0) ; j < nbAtom ; ++j ){
				
				contributionAtomicAlone[j].x		= 0.f;
				contributionAtomicAlone[j].y		= 0.f;
				contributionAtomicAlone[j].z		= 0.f;
				
			}
			
		}
		
		/**
		 * \fn inline void update( int i, axis_t partialGrad )
		 * \brief Function used to update the values using index and partial gradients passed as arguments
		 * \param i : Index value
		 * \param partialGrad : Partial Gradient for all three axis
		*/
		inline void update( int i, axis_t partialGrad ){
			
			/* Gradient update */
			grad[0] += partialGrad.x;
			grad[1] += partialGrad.y;
			grad[2] += partialGrad.z;
			
			/* Gradient IGM update */
			gradIGM[0] -= std::abs(partialGrad.x);
			gradIGM[1] -= std::abs(partialGrad.y);
			gradIGM[2] -= std::abs(partialGrad.z);
			
			/* Atoms belong to the first molecule */
			if(i < nbAtomInMolA){
			
				/* Contribution inside molecule A update */
				contributionInsideMoleculeA[0] += partialGrad.x;
				contributionInsideMoleculeA[1] += partialGrad.y;
				contributionInsideMoleculeA[2] += partialGrad.z;
				
			/* Atoms belong to the second molcule */
			}else{
			
				/* Contribution inside molecule B update */
				contributionInsideMoleculeB[0] += partialGrad.x;
				contributionInsideMoleculeB[1] += partialGrad.y;
				contributionInsideMoleculeB[2] += partialGrad.z;
			}

			/* Updating values for the atoms */
			contributionAtomicAlone[i].x = partialGrad.x;
			contributionAtomicAlone[i].y = partialGrad.y;
			contributionAtomicAlone[i].z = partialGrad.z;
					
			
		}
		
		/**
		 * \fn inline void updateIGMInter()
		 * \brief Updates the IGM inter 
		*/
		inline void updateIGMInter(){
			
			gradIGMInter[0] = -std::abs(contributionInsideMoleculeA[0]) - std::abs(contributionInsideMoleculeB[0]);
			gradIGMInter[1] = -std::abs(contributionInsideMoleculeA[1]) - std::abs(contributionInsideMoleculeB[1]);
			gradIGMInter[2] = -std::abs(contributionInsideMoleculeA[2]) - std::abs(contributionInsideMoleculeB[2]);
			
		}
		
		/**
		 * \fn inline void updateIGMAbsOut(int atomIndex)
		 * \brief Updates the IGM with the absolute value of the interaction of molecule A and the atom alone summed up
		 * \param atomIndex : the index of the atom relevant to the update
		*/
		inline void updateIGMAbsOut(int atomIndex){
			
			/* If the atom is molecule B */
			if( atomIndex >= nbAtomInMolA ){
				
				/* Updating gradient values */
				gradIGMAbsOut[0] = CAST_PREC(-std::abs(contributionInsideMoleculeA[0] + contributionAtomicAlone[atomIndex].x) - std::abs(contributionInsideMoleculeB[0] - contributionAtomicAlone[atomIndex].x));
				gradIGMAbsOut[1] = CAST_PREC(-std::abs(contributionInsideMoleculeA[1] + contributionAtomicAlone[atomIndex].y) - std::abs(contributionInsideMoleculeB[1] - contributionAtomicAlone[atomIndex].y));
				gradIGMAbsOut[2] = CAST_PREC(-std::abs(contributionInsideMoleculeA[2] + contributionAtomicAlone[atomIndex].z) - std::abs(contributionInsideMoleculeB[2] - contributionAtomicAlone[atomIndex].z));
			
			/* If the atom is molecule A */	
			}else{
				
				/* Updating gradient values */
				gradIGMAbsOut[0] = CAST_PREC(-std::abs(contributionInsideMoleculeB[0] + contributionAtomicAlone[atomIndex].x) - std::abs(contributionInsideMoleculeA[0] - contributionAtomicAlone[atomIndex].x));
				gradIGMAbsOut[1] = CAST_PREC(-std::abs(contributionInsideMoleculeB[1] + contributionAtomicAlone[atomIndex].y) - std::abs(contributionInsideMoleculeA[1] - contributionAtomicAlone[atomIndex].y));
				gradIGMAbsOut[2] = CAST_PREC(-std::abs(contributionInsideMoleculeB[2] + contributionAtomicAlone[atomIndex].z) - std::abs(contributionInsideMoleculeA[2] - contributionAtomicAlone[atomIndex].z));
				
			}
			
			
		}
		
		/**
		 * \fn inline void updateIGMAbsIn(int atomIndex)
		 * \brief Updates the IGM with the sum of the absolute value of the molecule A and the absolute value of the atom
		 * \param atomIndex : the index of the atom relevant to the update  
		*/
		inline void updateIGMAbsIn(int atomIndex){
			
			/* If the atom is molecule B */
			if( atomIndex >= nbAtomInMolA ){
				
				
				/* Updating gradient values */
				gradIGMAbsIn[0] = CAST_PREC(-std::abs(contributionInsideMoleculeA[0]) - std::abs(contributionInsideMoleculeB[0] - contributionAtomicAlone[atomIndex].x) -std::abs(contributionAtomicAlone[atomIndex].x));
				gradIGMAbsIn[1] = CAST_PREC(-std::abs(contributionInsideMoleculeA[1]) - std::abs(contributionInsideMoleculeB[1] - contributionAtomicAlone[atomIndex].y) -std::abs(contributionAtomicAlone[atomIndex].y));
				gradIGMAbsIn[2] = CAST_PREC(-std::abs(contributionInsideMoleculeA[2]) - std::abs(contributionInsideMoleculeB[2] - contributionAtomicAlone[atomIndex].z) -std::abs(contributionAtomicAlone[atomIndex].z));
				
				
			/* If the atom is molecule A */
			}else{
				
				/* Updating gradient values */
				gradIGMAbsIn[0] = CAST_PREC(-std::abs(contributionInsideMoleculeB[0]) - std::abs(contributionInsideMoleculeA[0] - contributionAtomicAlone[atomIndex].x) -std::abs(contributionAtomicAlone[atomIndex].x));
				gradIGMAbsIn[1] = CAST_PREC(-std::abs(contributionInsideMoleculeB[1]) - std::abs(contributionInsideMoleculeA[1] - contributionAtomicAlone[atomIndex].y) -std::abs(contributionAtomicAlone[atomIndex].y));
				gradIGMAbsIn[2] = CAST_PREC(-std::abs(contributionInsideMoleculeB[2]) - std::abs(contributionInsideMoleculeA[2] - contributionAtomicAlone[atomIndex].z) -std::abs(contributionAtomicAlone[atomIndex].z));
				
			}
			
		}
		
		/**
		 * \fn inline PREC getNormGrad()
		 * \brief GEts the vector's norm for gradient
		 * \return vector's norm
		*/
		inline PREC getNormGrad(){
			return normGrad;
		}
		
		/**
		 * \fn inline void processNormGrad()
		 * \brief Process the vector's norm for gradient
		*/
		inline void processNormGrad(){
			normGrad = std::sqrt( ( grad[0] * grad[0] ) + ( grad[1] * grad[1] ) + ( grad[2] * grad[2] ) );
		}
		
		/**
		 * \fn inline PREC getNormGradIGM()
		 * \brief Gets the vector's norm for gradient IGM
		 * \return vector's norm
		*/
		inline PREC getNormGradIGM(){
			return normGradIGM;
		}
		
		/**
		 * \fn inline void processNormGradIGM()
		 * \brief Process the vector's norm for gradient IGM
		*/
		inline void processNormGradIGM(){
			normGradIGM = std::sqrt( ( gradIGM[0] * gradIGM[0] ) + ( gradIGM[1] * gradIGM[1] ) + ( gradIGM[2] * gradIGM[2] ) );
		}
		
		/**
		 * \fn inline PREC getNormGradIGMInter()
		 * \brief Gets the vector's norm for gradient inter
		 * \return vector's norm
		*/
		inline PREC getNormGradIGMInter(){
			return normGradIGMInter;
		}
		
		/**
		 * \fn inline void processNormGradIGMInter()
		 * \brief Process the vector's norm for gradient inter
		*/
		inline void processNormGradIGMInter(){
			updateIGMInter();
			normGradIGMInter = std::sqrt( ( gradIGMInter[0] * gradIGMInter[0] ) + ( gradIGMInter[1] * gradIGMInter[1] ) + ( gradIGMInter[2] * gradIGMInter[2] ) );
		}
		
		/**
		 * \fn inline PREC getNormGradIGMAbsOut()
		 * \brief GEts the vector's norm for gradient inter with absolute value of the sum of molecule A's interactions and the atom alone's interactions
		 * Please note that this function directly depend on the atom given during the process
		 * \return vector's norm
		*/
		inline PREC getNormGradIGMAbsOut(){
			return normGradIGMInterAbsOut;
		}
		
		/**
		 * \fn inline void processNormGradIGMAbsOut(int i)
		 * \brief Process the vector's norm for gradient inter with absolute value of the sum of molecule A's interactions and the atom alone's interactions
		 * \param i : the atom's index
		*/
		inline void processNormGradIGMAbsOut(int i){
			updateIGMAbsOut(i);
			normGradIGMInterAbsOut = std::sqrt( ( gradIGMAbsOut[0] * gradIGMAbsOut[0] ) + ( gradIGMAbsOut[1] * gradIGMAbsOut[1] ) + ( gradIGMAbsOut[2] * gradIGMAbsOut[2] ) );
		}
		
		/**
		 * \fn inline PREC getNormGradIGMAbsIn()
		 * \brief Gets the vector's norm for gradient inter with the sum of the absolute value of molecule A's interactions and the absolute value of the atom alone's interactions
		 * Please note that this function directly depend on the atom given during the process
		 * \return vector's norm
		*/
		inline PREC getNormGradIGMAbsIn(){
			return normGradIGMInterAbsIn;
		}
		
		/**
		 * \fn inline void processNormGradIGMAbsIn(int i)
		 * \brief Process the vector's norm for gradient inter with the sum of the absolute value of molecule A's interactions and the absolute value of the atom alone's interactions
		 * \param i : the atom's index
		*/
		inline void processNormGradIGMAbsIn(int i){
			updateIGMAbsIn(i);
			normGradIGMInterAbsIn = std::sqrt( ( gradIGMAbsIn[0] * gradIGMAbsIn[0] ) + ( gradIGMAbsIn[1] * gradIGMAbsIn[1] ) + ( gradIGMAbsIn[2] * gradIGMAbsIn[2] ) );
		}
		
		
		
		
		/********************************************************************/
		/**************************OUTPUT UTILITIES**************************/
		/********************************************************************/
		
		/**
		 * \fn inline PREC getGradVal(int index)
		 * \brief Gets the gradient value at the index given
		 * \param index : the index value
		 * \return the current gradient value at the given index
		*/
		inline PREC getGradVal(int index){
			
			if(index >= 0 && index < 3){
				return grad[index];	
			}else{
				return -1;
			}
			
		}
		
		/**
		 * \fn inline void setGradNull()
		 * \brief Sets the gradient values to 0 
		*/
		inline void setGradNull(){
			
			grad[0] = 0.f;
			grad[1] = 0.f;
			grad[2] = 0.f;
			
		}
	
	
};

#endif
