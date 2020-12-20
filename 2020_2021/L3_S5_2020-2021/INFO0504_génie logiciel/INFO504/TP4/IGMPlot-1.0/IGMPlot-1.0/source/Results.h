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

#ifndef _RESULTS_H_
#define _RESULTS_H_


//#include"general.h"
#include"LocalData.h"

#ifndef No_OpenMP
#include<omp.h>
#endif


/**
 * \file Results.h
 * \brief Class designed to store all results that can be used as output by the program
 * \author Emmanuel
*/
class Results{
	
	private :
		
		/* Non delta related values */
		int nbAtom; 				/* Number of atom focused 						*/
		int fullSize;					/* Full number of iteration in the main loop	*/
		
		/* Cube values */
		PREC * cubedeltaGIntra;		
		PREC * cubedeltaGInter;
		//PREC * cubedeltaKIntra;
		//PREC * cubedeltaKInter;
		PREC * cubeRho;
		PREC * cubeRDG;
		
		/* NCI plot handling */
		bool * intermolecularCheck;
		
		/* Single atom related values */
		threadDuplication_t * sumDeltaGInterAtom;
		//threadDuplication_t * sumDeltaKInterAtom;
		
	public :
	
		/**
		 * \fn inline Results(int nbAtomFocusedParam, int nbStepsParam)
		 * \brief Basic constructor
		 * \param nbAtomParam : The number of focused atom.
		 * \param nbStepsParam : the number of steps for the grid crossing in each axis
		*/
		inline Results(int nbAtomParam, int nbStepsParam) : nbAtom(nbAtomParam), fullSize(nbStepsParam){
			
			/* Allocating values */
			cubedeltaGIntra 		= new PREC[fullSize];
			cubedeltaGInter 		= new PREC[fullSize];
			//cubedeltaKIntra		= new PREC[fullSize];
			//cubedeltaKInter 		= new PREC[fullSize];
			cubeRho					= new PREC[fullSize];
			cubeRDG 				= new PREC[fullSize];
			intermolecularCheck		= new bool[fullSize];
			sumDeltaGInterAtom 		= new threadDuplication_t[nbAtom];
			//sumDeltaKInterAtom 		= new threadDuplication_t[nbAtom];
			
			/* Initialization */
			for( int i(0) ; i < nbAtom ; ++i ){
				
				for( int j(0) ; j < MAX_THREAD ; ++j ){
					
					sumDeltaGInterAtom[i][j] = 0.f;
					//sumDeltaKInterAtom[i][j] = 0.f;				
				
				}
				
			}
		}
		 
		/**
		 * \fn inline ~Results()
		 * \brief Destructor 
		*/
		inline ~Results(){
			
			/* Memory deallocation */
			delete [] cubedeltaGIntra;
			delete [] cubedeltaGInter;
			//delete [] cubedeltaKIntra;
			//delete [] cubedeltaKInter;
			delete [] cubeRho;
			delete [] cubeRDG;
			delete [] intermolecularCheck;
			delete [] sumDeltaGInterAtom;
			//delete [] sumDeltaKInterAtom;	
			
		}
		
		/**
		 * \fn inline int getNbAtomFocused()
		 * \brief Returns the number of atom
		 * \return the number of atom
		*/
		inline int getNbAtom(){
			
			return nbAtom;
		
		}
		
		
		/**
		 * \fn inline void updateCube( const int index, const GRADIENT & gradVals, const PREC & rho, const PREC & lambda)
		 * \brief Function used to update the cube values using index and the vectors' norms
		 * \param i : grid index value
		 * \param data : the Gradients
		 * \param rho : the previously calculated value of rho
		 * \param lambda : second lambda value
		*/
		inline void updateCube( int index, LocalData & data, PREC & rho, PREC & lambda){
			
			/* Processing delta G value for both inter and intra molecular interactions */
			cubedeltaGIntra[index]		= 	( data.getNormGradIGM() 			-	data.getNormGradIGMInter() 	);
			cubedeltaGInter[index]		= 	( data.getNormGradIGMInter() 		-	data.getNormGrad() 			);
				
			
			/* Processing delta K value for both inter and intra molecular interactions */
			/*
			cubedeltaKIntra[index]		= 	( data.getNormGradIGM()				* 	data.getNormGradIGM() 		
										- 	  data.getNormGradIGMInter() 		* 	data.getNormGradIGMInter() 	) / rho;
			cubedeltaKInter[index]		= 	( data.getNormGradIGMInter() 		* 	data.getNormGradIGMInter() 	
										- 	  data.getNormGrad()				*	data.getNormGrad() 			) / rho;
			*/
									
									
			/* Updating rho and RDG's values */
			cubeRho[index]				=	lambda < 0 ? -rho : rho;
			cubeRDG[index] 				=	ALPHA 	* 	data.getNormGrad()		/	std::pow(rho, FOUR_THIRD);
		
		}
		
		/**
		 * \fn inline void updateAtom( int i, const norms_t & norm, PREC rho)
		 * \brief Function used to update the atom values using index and the vectors' norms
		 * \param i : Atom index value
		 * \param data : the previously calculated norms (cf Gradient)
		 * \param rho : the previously calculated value of rho
		*/
		inline void updateAtom( int i, LocalData & data/*, PREC rho*/)
		  {	
		    /* Summing up the delta G and K values for the atoms' interactions */
                  #ifndef No_OpenMP
		    sumDeltaGInterAtom[i][omp_get_thread_num()]	+=	( data.getNormGradIGMAbsIn() 	-	data.getNormGradIGMAbsOut() );
		  #else
		    sumDeltaGInterAtom[i][0]	+=	( data.getNormGradIGMAbsIn() 	-	data.getNormGradIGMAbsOut() );
		  #endif
		  /*
		    sumDeltaKInterAtom[i][omp_get_thread_num()]	+=	( data.getNormGradIGMAbsIn() 	* 	data.getNormGradIGMAbsIn()	
		    -	  data.getNormGradIGMAbsOut()	*	data.getNormGradIGMAbsOut() ) / rho;
			*/
		}
		
		/**
		 * \fn inline void update( int index, PREC i = 0.f )
		 * \brief Function used to update the values using a given value
		 * \param index : index value
		 * \param rho : the previously calculated value of rho
		 * \param val : value
		*/
		inline void update( int index, PREC rho, PREC value = 0.f ){
			
			/* Setting delta G value for both inter and intra molecular interactions 	*/
			cubedeltaGIntra[index]		= 	value;
			cubedeltaGInter[index]		= 	value;
			
			/* Setting delta K value for both inter and intra molecular interactions 	*/
			//cubedeltaKIntra[index]		= 	value;
			//cubedeltaKInter[index]		= 	value;
			
			/* Setting cubeRho and cubeRDG's values 									*/
			cubeRho[index] 				= 	rho;
			cubeRDG[index] 				= 	100;
			
		}
		
		/**
		 * \fn inline void sum(int nbAtom)
		 * \brief Function used to threads values together
		*/
		inline void sum(){
			
			PREC sumTmp;
			//PREC sumTmp2;
			
			/* Looping through atoms' indexes */
			for( int i(0) ; i < nbAtom ; ++i ){
			
			
				sumTmp = 0.f;
				//sumTmp2= 0.f;
				
				int j;
				/* Looping through threads' indexes (except 0 : sum position) */

                                #ifndef No_OpenMP
                                #pragma omp parallel for private(j) reduction(+: sumTmp)
				#endif
				
				for( j = 1 ; j < MAX_THREAD ; ++j ){
		
					sumTmp += sumDeltaGInterAtom[i][j];
					//sumTmp2+= sumDeltaKInterAtom[i][j];
		
				}
				
				sumDeltaGInterAtom[i][0] += sumTmp;
				//sumDeltaKInterAtom[i][0] += sumTmp2;
				
			}
			
		}
		
		/**
		 * \fn inline void intermolecular(bool check, int pos)
		 * \brief Function used to threads values together
		*/
		inline void intermolecular(bool check, int pos){
			
			intermolecularCheck[pos] = check;
			
		}
		
		
		
		/********************************************************************/
		/**************************OUTPUT UTILITIES**************************/
		/********************************************************************/
		
		
		static const int DGSIE=16;
		static const int DKSIE=17;
		
		/**
		 * \fn inline PREC get(int index, int type)
		 * \brief Gets the indicated value and given index
		 * \param index : index of the value
		 * \param type : the type of value
		 * \return the current type of value
		*/
		inline PREC get(int index, int type){
			
			
			switch(type){
				
				case TYPE_DELTA_G_INTRA :
					return cubedeltaGIntra[index];
				break;
				
				case TYPE_DELTA_G_INTER :
					return cubedeltaGInter[index];
				break;
				
				/*case TYPE_DELTA_K_INTRA : 
					return cubedeltaKIntra[index];
				break;
				
				case TYPE_DELTA_K_INTER : 
					return cubedeltaKInter[index];
				break;*/
				
				case DGSIE :
					return sumDeltaGInterAtom[index][0];
				break;
				
				/*case DKSIE :
					return sumDeltaKInterAtom[index][0];
				break;*/
				
				case TYPE_RHO :
					return cubeRho[index];
				break;
				
				case TYPE_RDG :
					return cubeRDG[index];
				break;
				
				default :
					return -1.f;
					
			}
			
		}
		
		/**
		 * \fn inline PREC* get(int type)
		 * \brief Gets the indicated value
		 * \param type : the type of value
		 * \return the current type of value
		*/
		inline PREC* get(int type){
			
			
			switch(type){
				
				case TYPE_DELTA_G_INTRA :
					return cubedeltaGIntra;
				break;
				
				case TYPE_DELTA_G_INTER :
					return cubedeltaGInter;
				break;
				
				/*case TYPE_DELTA_K_INTRA : 
					return cubedeltaKIntra;
				break;
				
				case TYPE_DELTA_K_INTER : 
					return cubedeltaKInter;
				break;*/
				
				case TYPE_RHO :
					return cubeRho;
				break;
				
				case TYPE_RDG :
					return cubeRDG;
				break;
				
				default :
					return NULL;
					
			}
			
		}
		
		/**
		 * \fn inline bool* getShouldPrint()
		 * \brief Gets the indicated values of intermolecular checking
		 * \return the current the values array
		*/
		inline bool* getShouldPrint(){
			
			return intermolecularCheck;
		
		}
	
};

#endif
