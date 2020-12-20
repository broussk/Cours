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
 * \file Node.h
 * \brief Class used to handle every node data storage and processing ; implemented for multiprocessing implementation ; therefore, thread proof
 * \author Emmanuel
*/

#ifndef _NODE_H_
#define _NODE_H_

//#include"general.h"
//#include"LocalData.h"
#include"Results.h"
#include"ProgData.h"

#define DEBUG if(index==269560)std::cout
#define ENDL std::endl

class Node{
	
	private :
	
		/* Variables relevant to the node itself																		*/
		
		int nbAtom;								/* The number of atom, both molecule combined							*/
		int nbAtomMolA;							/* The number of atom in molecule A										*/
		LocalData * data;						/* The local data' values												*/
		ProgData & pdata;						/* The program's data													*/
	
	
		/* Variables relevant in the computing of density and, therefore, gradiant and hessian values 					*/
	
		PREC * __restrict diffX;				/* Differences between node position and atom's position over x axis	*/
		PREC * __restrict diffY;				/* Differences between node position and atom's position over y axis	*/
		PREC * __restrict diffZ;				/* Differences between node position and atom's position over z axis	*/
		
		PREC * __restrict squareX;				/* Square of difference value "diffX" over the x axis					*/
		PREC * __restrict squareY;				/* Square of difference value "diffY" over the y axis					*/
		PREC * __restrict squareZ;				/* Square of difference value "diffZ" over the z axis					*/
		
		PREC * __restrict rhoX;					/* Rho value processed over the x axis 									*/
		PREC * __restrict rhoY;					/* Rho value processed over the y axis 									*/
		PREC * __restrict rhoZ;					/* Rho value processed over the z axis 									*/
		
		PREC * __restrict distance;				/* Distance value between the node position and the atom				*/
		
		PREC rho;								/* Rho value processed during density processing						*/
		PREC contribution;						/* Contribution value processed during density processing				*/
		PREC determinant;						/* Determilnant value 													*/
		
		bool shouldCompute;						/* Tells if the density matched the desired values						*/
		
		/* Variables relevant in the computing of the gradient and hessian values										*/
		
		PREC hess[6];							/* Six hessian values													*/
		PREC lambdas[3];						/* Three lambda's values												*/	
		axis_t partialGradient; 				/* Partial gradients added to process gradient values 					*/
		PREC sumBRho;							/* Sum multiplications of rhos' values and B values						*/
		PREC sumSquareBRho;						/* Sum multiplications of rhos' values and squares of B values			*/ 
		PREC multInvR;							/* Multiplicative inverse of the distance								*/
		PREC squareMultInvR;					/* Square of the multiplicative inverse of the distance					*/
		PREC a , b , c ,p ,q;					/* Lambda processing values 											*/ 
		PREC opti, opti2, opti3;				/* Optimization values													*/
		PREC tmp;								/* Temporary value														*/
		
		/* Miscealenous constants																						*/
		static const int X = 0;					/* Constant used for accessing x axis in three element's array			*/
		static const int Y = 1;					/* Constant used for accessing y axis in three element's array			*/
		static const int Z = 2;					/* Constant used for accessing z axis in three element's array			*/
		
		
		
		int lol2;
		
	
	public : 
	
	 
	
		/**
		 * \fn inline Node()
		 * \brief Main constructor
		 * \param nbAtomParam : number of atom counting both molecule
		 * \param nbAtomMolAParam : the number of atom in the first molecule
		 * \param pdataParam : the program's data
		*/
		inline Node(int nbAtomParam, int nbAtomMolAParam, ProgData &pdataParam):nbAtom(nbAtomParam), nbAtomMolA(nbAtomMolAParam), pdata(pdataParam){
			
			lol2=0;
			/* Memory allocation */
			diffX 			= new PREC[nbAtom];
			diffY 			= new PREC[nbAtom];
			diffZ 			= new PREC[nbAtom];
			
			squareX 		= new PREC[nbAtom];
			squareY 		= new PREC[nbAtom];
			squareZ		 	= new PREC[nbAtom];
			
			rhoX 			= new PREC[nbAtom];
			rhoY 			= new PREC[nbAtom];
			rhoZ			= new PREC[nbAtom];
		
			distance 		= new PREC[nbAtom];
			
			/* Local data instanciation */
			data = new LocalData( nbAtomMolA, nbAtom );
			
		}
		
		/**
		 * \fn inline ~Node()
		 * \brief Destructor
		*/
		inline ~Node(){
			
			/* Memory deallocation */	
			delete [] diffX;
			delete [] diffY;
			delete [] diffZ;
			
			delete [] squareX;
			delete [] squareY;
			delete [] squareZ;
			
			delete [] rhoX;
			delete [] rhoY;
			delete [] rhoZ;
		
			delete [] distance;
			
			/* Data destruction */
			delete data;
				
		}
	
	
		/**
		 * \fn float computeDensity(position_t &posGrid, param_t & params) 
		 * \brief Computes density
		 * \param posGrid : current position in the grid on all three axis
		 * \param params : the parameters initially read at the beginning of the program
		 * \return the value of rho
		*/
		void computeDensity(position_t & __restrict posGrid, param_t & __restrict params){
			
			
			/* Initilization */
			rho				=	0.f;
			contribution	=	0.f;

			
			/* Looping through the atoms in the first molecule */
			for( int j(0) ; j < nbAtomMolA ; ++j ){
				
				int atomType = pdata.atomTypes[j];
				PREC pos[3] = {pdata.atomPositions.xValues[j], pdata.atomPositions.yValues[j], pdata.atomPositions.zValues[j]};
				
				/* Setting differences */
				diffX[j]	= ( posGrid.x - pos[X] );
				diffY[j]	= ( posGrid.y - pos[Y] );
				diffZ[j]	= ( posGrid.z - pos[Z] );
				
				/* Processing differences' squares */
				squareX[j]	= ( diffX[j] * diffX[j] );
				squareY[j]	= ( diffY[j] * diffY[j] );
				squareZ[j]	= ( diffZ[j] * diffZ[j] );
				
				/* Distance processing */
				distance[j]	= std::sqrt( squareX[j] + squareY[j] + squareZ[j] );
	
				/* Setting R_TRESHOLD as minimum */
				distance[j] = ( distance[j] < R_TRESHOLD ? R_TRESHOLD : distance[j] );
	
				/* Rho processing */
				rhoX[j] 	= A1[ atomType ]	*	EXP( -B1[ atomType ] * distance[j] );
				rhoY[j]		= A2[ atomType ]	*	EXP( -B2[ atomType ] * distance[j] );
				rhoZ[j]		= A3[ atomType ]	*	EXP( -B3[ atomType ] * distance[j] );
				rho 		+= rhoX[j] + rhoY[j] + rhoZ[j]; 
				
			}
			
			/* Setting contribution as the rho for the first molecule */
			contribution = rho;

			
			/* Looping through the atoms in the first molecule */
			for( int j(nbAtomMolA) ; j < nbAtom ; ++j){
				
				int atomType = pdata.atomTypes[j];
				PREC pos[3] = {pdata.atomPositions.xValues[j], pdata.atomPositions.yValues[j], pdata.atomPositions.zValues[j]};
				
				/* Setting differences */
				diffX[j]	= ( posGrid.x - pos[X] );
				diffY[j]	= ( posGrid.y - pos[Y] );
				diffZ[j]	= ( posGrid.z - pos[Z] );
				
				/* Processing differenes' squares */
				squareX[j]	= ( diffX[j] * diffX[j] );
				squareY[j]	= ( diffY[j] * diffY[j] );
				squareZ[j]	= ( diffZ[j] * diffZ[j] );
				
				/* Distance processing */
				distance[j]	= std::sqrt( squareX[j] + squareY[j] + squareZ[j] );
	
				/* Setting R_TRESHOLD as minimum */
				distance[j] = ( distance[j] < R_TRESHOLD ? R_TRESHOLD : distance[j] );
	
				/* Rho processing */
				rhoX[j] 	= A1[ atomType ]	*	EXP( -B1[ atomType ] * distance[j] );
				rhoY[j]		= A2[ atomType ]	*	EXP( -B2[ atomType ] * distance[j] );
				rhoZ[j]		= A3[ atomType ]	*	EXP( -B3[ atomType ] * distance[j] );
				rho 		+= rhoX[j] + rhoY[j] + rhoZ[j];
	
			}
			
			/* Deciding whether the computing should continue or not depending on the contribution and rho */
			contribution /= rho;
			shouldCompute 	= (contribution <= params.intermolecular ) && (contribution >= (1-params.intermolecular));
			
		}

		/**
		 * \fn void computeGradHess()
		 * \brief Computes gradient and hessian's values
		*/
		void computeGradHess(){

	
			/*Initializing */
			data->init();
			hess[0]=0.f;
			hess[1]=0.f;
			hess[2]=0.f;
			hess[3]=0.f;
			hess[4]=0.f;
			hess[5]=0.f;

			for(int i = 0 ; i < nbAtom ; ++i){

				/* Computing the multiplicative inverse and its square */
				multInvR 			= 	CAST_PREC(1.0 / static_cast<double>(distance[i]));
				squareMultInvR 		= 	multInvR * multInvR;

				
				/* Summing rho * B */
				sumBRho				=  	B1[pdata.atomTypes[i]] * rhoX[i] + B2[pdata.atomTypes[i]] * rhoY[i] + B3[pdata.atomTypes[i]] * rhoZ[i];

				/* Summing rho * B * B */ 
				sumSquareBRho		= 	B1[pdata.atomTypes[i]] * B1[pdata.atomTypes[i]] * rhoX[i] 
									+	B2[pdata.atomTypes[i]] * B2[pdata.atomTypes[i]] * rhoY[i] 
									+	B3[pdata.atomTypes[i]] * B3[pdata.atomTypes[i]] * rhoZ[i];
				
				/* Operation used three times */
				opti = multInvR * sumBRho;
				
				/* Processing partial gradients */
				partialGradient.x 	= 	-diffX[i] * opti;
				partialGradient.y 	= 	-diffY[i] * opti;
				partialGradient.z 	=	-diffZ[i] * opti;

				/* Updating gradient values with current partial gradient values */
				data->update(i, partialGradient);
				
				/* Updating hessian values */
				hess[0]				+=	squareMultInvR * ( (squareX[i] * multInvR - distance[i]) * sumBRho + squareX[i] * sumSquareBRho);
				hess[3]				+=	squareMultInvR * ( (squareY[i] * multInvR - distance[i]) * sumBRho + squareY[i] * sumSquareBRho);
				hess[5]				+=	squareMultInvR * ( (squareZ[i] * multInvR - distance[i]) * sumBRho + squareZ[i] * sumSquareBRho);

				/* Operation used three times */
				opti += sumSquareBRho;
				opti *= squareMultInvR;
				
				hess[1]				+=	diffX[i] * diffY[i] * opti;
				hess[2]				+=	diffX[i] * diffZ[i] * opti;
				hess[4]				+=	diffY[i] * diffZ[i] * opti;
			}
		}		
		
		/**
		 * \fn inline void sortLambdas()
		 * \brief Sorting function used to sort lambdas' values
		*/
		inline void sortLambdas(){
			
			if( lambdas[0]<=lambdas[1] ){
			
				tmp	= lambdas[0];
				
				if( lambdas[1]<lambdas[2] ){
				
					lambdas[0]	= lambdas[2];
					lambdas[2]	= tmp;
					
				}else{
				
					lambdas[0]	= lambdas[1];
					lambdas[1]	= tmp;
					
				}
				
			}
			if( lambdas[1]<lambdas[2] ){
			
				tmp			= lambdas[1];
				lambdas[1] 	= lambdas[2];
				lambdas[2] 	= tmp;
				
			}                        
		}

		/**
		 * \fn void computeSortLambdas()
		 * \brief Function used to compute and sort lambdas' values
		*/
		void computeSortLambdas(){
			
			a = -(hess[0] + hess[3] +hess[5]);

			b = hess[0] * hess[3] + hess[0] * hess[5] + hess[3] * hess[5] - hess[1] * hess[1] - hess[2] * hess[2] - hess[4] * hess[4];

			c = hess[0] * hess[4] * hess[4] + hess[3] * hess[2] * hess[2] + hess[5] * hess[1] * hess[1] - hess[0] * hess[3] * hess[5] - 2 * hess[1] * hess[2] * hess[4];

			/* Keeping 1/3 * a as the value is used five times */
			opti = a * ONE_THIRD;

			p 			= 	b -	a * opti;
			q 			= 	a *	a *	a *	0.0740740740f -	b *	opti + c;

			determinant =	q * q + p * p * p * 0.148148148148148148f;

			if(determinant < 0.f){
			
				/* These values are used three times */
				opti2 = std::sqrt( -p * ONE_THIRD ) * 2.f;
				opti3 = std::acos(3*q/(2*p) * std::sqrt(-3 / p));
				
				lambdas[0] = CAST_PREC( opti2 * cos( opti3				* ONE_THIRD) 	- opti);
				lambdas[1] = CAST_PREC( opti2 * cos((opti3 + PI_2) 		* ONE_THIRD) 	- opti);
				lambdas[2] = CAST_PREC( opti2 * cos((opti3 + PI_4) 		* ONE_THIRD) 	- opti);

				/* Sorting lambdas */
				sortLambdas();
			}
		}
		
	
	
		/**
		 * \fn void process( PREC * posGrid, int index, Results &results, param_t & params )
		 * \brief Process all the information for an entire line of the grid
		 * \param posGrid : the current position in the grid
		 * \param index : index position in the grid
		 * \param results : objet containing the finale results
		 * \param params : parameters read at the beggining
		*/
		void process( position_t & posGrid, int index, Results &results, param_t & params ){
			
			/* Computing density */
			computeDensity(posGrid, params);

			/* Checks if the point is interesting */
			results.intermolecular(shouldCompute, index);
		
			/* Computing gradient and hessian values */
			computeGradHess();
			
			/* Computing and sorting lambdas */
			computeSortLambdas();
			

			/* Checks if determinant in inferior to 0 */
			if( determinant < 0.f ){
			
				/* Vectors' norms processing */
				data->processNormGrad();
				data->processNormGradIGM();
				data->processNormGradIGMInter();
				
				
				/* Updating cube values */
				results.updateCube(index, *data, rho, lambdas[1]);
				
				/* Looping through focused atoms */
				for( int j(0) ; j < nbAtom ; ++j ){
					
					/* Atom relevant vector's norms processing */
					data->processNormGradIGMAbsOut(j);
					data->processNormGradIGMAbsIn(j);
					
					/* Updating delta values */
					results.updateAtom(j, *data/*, rh0*/);
					
				
				}
			
			/* Determinant was not inferior to 0 */
			}else{
			
			//	if(++lol2>7000)std::cout << omp_get_thread_num() << " : "  << lol2 << " / " << std::scientific << determinant << " " << rho << std::endl;
				
				/* Setting values to default */
				results.update(index, rho);
				
			}
				
		}
};

#endif
