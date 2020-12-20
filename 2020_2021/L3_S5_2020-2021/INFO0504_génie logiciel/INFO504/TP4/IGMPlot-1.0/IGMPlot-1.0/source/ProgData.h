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

#ifndef _PROGDATA_H_
#define _PROGDATA_H_

#include"general.h"
#include<iostream>
#include<cmath>
#include<cstdlib>

/* Exponential precision
 * std::exp : only version right now
*/
#define EXP std::exp

/**
 * \file ProgData.h
 * \brief Class designed to store the program's main dataprovide some utilities concerning those
 * /!\ No copy constructor defined, careful when trying to pass this by value /!\
 * \author Emmanuel
*/
class ProgData{

	private :
		
	
	
		/* Program data */
		int nbAtomMolA;				/* Number of atom in molecule A 						*/
		int nbAtomMolB;				/* Number of atom in molecule B 						*/
		int numLigand;				/* Number of the ligand ; if none : -1 					*/
		int nbAtom;					/* Number of atom in both molecule (if two) 			*/
		PREC maxCoordinates[3];		/* Max coordinates 										*/
		PREC minCoordinates[3];		/* Min coordinates 										*/
		int nbSteps[3];				/* Number of steps in loop for all three axis 			*/
	
	public :
	
		int * atomTypes;			/* Each atom's type 									*/
		positions_t atomPositions;	/* Each atom's position 								*/
		
	private :
	
		/* Other utilities' variables */
		int cursor;					/* Used to iterate through the arrays 					*/
		bool boxSet;				/* Used to check whether CUBE option has been used 	*/
                bool radiusSet;                         /* Used to check whether RADIUS option has been used    */
		int cnt; /*tmp*/
		
	public :
	
		/**
		 * \fn inline ProgData(int nbAtomMolAParam, int nbAtomMolBParam, int numLigandParam)
		 * \brief Constructor
		 * \param nbAtomMolAParam : the number of atoms in molecule A
		 * \param nbAtomMalBParam : the number of atoms in molecule B
		 * \param numLigandParam : the molecule index corresponding to the ligand
		*/
		inline ProgData(int nbAtomMolAParam, int nbAtomMolBParam, int numLigandParam) : nbAtomMolA(nbAtomMolAParam), nbAtomMolB(nbAtomMolBParam), numLigand(numLigandParam), nbAtom(nbAtomMolAParam + nbAtomMolBParam) {
			
			
			/* Allocating memory */
			atomTypes 		= new int[nbAtom];
			//atomPositions 	= new position_t[nbAtom];	
			atomPositions.xValues = new PREC[nbAtom];	
			atomPositions.yValues = new PREC[nbAtom];	
			atomPositions.zValues = new PREC[nbAtom];
			
			/* Cursor instanciation */
			cursor 			= 0;
			cnt				= 0;
			boxSet 			= false;
                        radiusSet               = false;

			
		}
		
		/**
		 * \fn inline ~ProgData()
		 * \brief Destructor
		*/
		inline ~ProgData(){
			
			/* Deallocating memory */
			delete [] atomTypes;
			//delete [] atomPositions;
			delete [] atomPositions.xValues;
			delete [] atomPositions.yValues;
			delete [] atomPositions.zValues;
			
		}
		
		/**
		 * \fn inline void addAtom(int type, PREC posx, PREC posy, PREC posz)
		 * \brief Adds an atom with the given properties to the atom's array
		 * \param type : the type of the atom
		 * \param posx : the position of the atom on the x axis
		 * \param posy : the position of the atom on the y axis
		 * \param posz : the position of the atom on the z axis
		*/
		inline void addAtom(int type, PREC posx, PREC posy, PREC posz){

			
			if( cursor < nbAtom ){
			
				/* Setting type */
				atomTypes[cursor] = type;
				if(type < 0){
				        std::cerr << std::endl;
					std::cerr << "[ERROR] Atoms with invalid type (or beyond period 3) at " << cursor << "." << std::endl << "[ERROR] The program will now exit." << std::endl;
					exit(EXIT_FAILURE);
					
				}else{
				
					if(type > NB_KNW_ATMS){
				
                                                std::cerr << std::endl;	
						std::cerr << "[ERROR] Atom valid but no handled by this version at " << cursor << "(" << type << ")." << std::endl;
						std::cerr << "[INFO!] The maximum atomic number that can be handled in the current version is " << NB_KNW_ATMS << "." << std::endl;
						std::cerr << "[ERROR] The program will now exit." << std::endl;
					
					}
				
				}
			
				/* Setting position (converting from ansgtroms to Bohr) */
				atomPositions.xValues[cursor] = posx / BOHRTOA;
				atomPositions.yValues[cursor] = posy / BOHRTOA;
				atomPositions.zValues[cursor] = posz / BOHRTOA;
				
				/* If CUBE and RADIUS options have not been used */
                                /* then, coordinates read must be used to determine the NCI/IGM grid box */
				if(!boxSet && !radiusSet){

					
					/* If there is no ligand or if the cursor is iterating through the ligand */
					if( numLigand == -1 || ( numLigand == 0 && cursor < nbAtomMolA ) || ( numLigand == 1 && cursor > nbAtomMolA ) ){

					
						/* First addition */
						if( cursor == 0 ){

					
							/* Setting the first addition as max coordinates for all axis */
							maxCoordinates[0] = atomPositions.xValues[cursor];
							maxCoordinates[1] = atomPositions.yValues[cursor];
							maxCoordinates[2] = atomPositions.zValues[cursor];
						
							/* Setting the first addition as min coordinates for all axis */
							minCoordinates[0] = atomPositions.xValues[cursor];
							minCoordinates[1] = atomPositions.yValues[cursor];
							minCoordinates[2] = atomPositions.zValues[cursor];

					
						/* Addition other than the first */
						}else{
							
							/* Updating max coordinates */
							if( maxCoordinates[0] < atomPositions.xValues[cursor] )
								maxCoordinates[0] = atomPositions.xValues[cursor];
							if( maxCoordinates[1] < atomPositions.yValues[cursor] )
								maxCoordinates[1] = atomPositions.yValues[cursor];
							if( maxCoordinates[2] < atomPositions.zValues[cursor] )
								maxCoordinates[2] = atomPositions.zValues[cursor];
								
							/* Updating min coordinates */
							if( minCoordinates[0] > atomPositions.xValues[cursor] )
								minCoordinates[0] = atomPositions.xValues[cursor];
							if( minCoordinates[1] > atomPositions.yValues[cursor] )
								minCoordinates[1] = atomPositions.yValues[cursor];
							if( minCoordinates[2] > atomPositions.zValues[cursor] )
								minCoordinates[2] = atomPositions.zValues[cursor];

														
						} // end of else of if( cursor == 0 ){
					
					} // end of  if( numLigand == -1 || ( numLigand == 0 && cursor < nbAtomMolA ) || ( numLigand == 1 && cursor > nbAtomMolA ) )
					
				} // end of if(!boxSet && !radiusSet){
			
				/* Updating cursor */
				++cursor;
				
			}else{
				
                                std::cerr << std::endl;
				std::cerr << "[ERROR] More atoms than expected! ( " << cursor << " / " << nbAtom << " )" << std::endl;
				std::cerr << "[ERROR] The program will now exit." << std::endl;
				exit(EXIT_FAILURE);	
				
			}
			
		}
		
		/**
		 * \fn inline void validate(PREC * increments, PREC ligandRadius = -1)
		 * \brief Ends the atom adding and update the coordinates before reporting whether the values are consistent
		 * \param increments : the increments values
		 * \param ligandRadius : the radius around the ligand that has been provided ; will only be used if a ligand has been provided
		*/
		inline void validate(PREC * increments, PREC ligandRadius = -1){


                        /* convert increment from angstroms to Bohr */
                        increments[0] = increments[0] / BOHRTOA;
                        increments[1] = increments[1] / BOHRTOA;
                        increments[2] = increments[2] / BOHRTOA;

			
			/* If CUBE and RADIUS have not been used */
			if( !boxSet && !radiusSet){
			
				/* If a ligand has been provided */
				if( numLigand != -1 ){

			
					/* Updating max coordinates */
					maxCoordinates[0] += ligandRadius / BOHRTOA;
					maxCoordinates[1] += ligandRadius / BOHRTOA;
					maxCoordinates[2] += ligandRadius / BOHRTOA;
					
					/* Updating min coordinates */
					minCoordinates[0] -= ligandRadius / BOHRTOA;
					minCoordinates[1] -= ligandRadius / BOHRTOA;
					minCoordinates[2] -= ligandRadius / BOHRTOA;
				
				/* If no ligand has been provided */
				}else{


			
					/* Updating max coordinates */
					maxCoordinates[0] += 2.f;
					maxCoordinates[1] += 2.f;
					maxCoordinates[2] += 2.f;
					
					/* Updating min coordinates */
					minCoordinates[0] -= 2.f;
					minCoordinates[1] -= 2.f;
					minCoordinates[2] -= 2.f;
					
				} // end of else of if( numLigand != -1 ){
			
			} // end of  if( !boxSet && !radiusSet){
			
			/* Setting the steps */
			nbSteps[0] = static_cast<int>( std::ceil( (maxCoordinates[0] - minCoordinates[0]) / increments[0] ) );
			nbSteps[1] = static_cast<int>( std::ceil( (maxCoordinates[1] - minCoordinates[1]) / increments[1] ) );
			nbSteps[2] = static_cast<int>( std::ceil( (maxCoordinates[2] - minCoordinates[2]) / increments[2] ) );
		
			if(cursor != nbAtom){
				std::cerr << "The number of atom read is different from the number of atom that should have been read. Please verify the .xyz files." << std::endl;
				std::cerr << "The program will now exit." << std::endl;
				exit(EXIT_FAILURE);
			
			}
			
		}
		
		
		/**
		 * \fn inline void setCube( PREC * cubeParam )
		 * \brief Sets the given cube has the reference cube to the problem
		 * \param cubeParam : the cube
		*/
		inline void setCube( PREC * cubeParam ){
			
			this->boxSet = cubeParam != NULL;
			
			/* If the cube is not NULL */
			if( cubeParam ){

                                 
                                /* Check if P1 != P2 */
                                if( (cubeParam[0]==cubeParam[3]) && (cubeParam[1]==cubeParam[4]) && (cubeParam[2]==cubeParam[5]) ){

                                        /* cannot build cube */
                                        std::cerr << std::endl; 
                                        std::cerr << "[ERROR] Invalid coordinates given for cube creation; point P1 must differ from P2" << std::endl;
                                        std::cerr << "The program will now exit." << std::endl;
                                        exit(EXIT_FAILURE);
                        
                                     } // end of if( (cubeParam[0]==cubeParam[3]) && (cubeParam[1]==cubeParam[4]) && (cubeParam[2]==cubeParam[5]) ){


				
				/* Check if first coordinate is inferior to the second coordinate */
				if( (cubeParam[0]<cubeParam[3]) && (cubeParam[1]<cubeParam[4]) && (cubeParam[2]<cubeParam[5]) ){
				
					/* Setting min and max using the current cube */
					minCoordinates[0] = cubeParam[0] / BOHRTOA;
					minCoordinates[1] = cubeParam[1] / BOHRTOA;
					minCoordinates[2] = cubeParam[2] / BOHRTOA;
					maxCoordinates[0] = cubeParam[3] / BOHRTOA;
					maxCoordinates[1] = cubeParam[4] / BOHRTOA;
					maxCoordinates[2] = cubeParam[5] / BOHRTOA;
					
				}else{
					/* cannot build cube */
                                        std::cerr << std::endl;
			                std::cerr << "[ERROR] Invalid coordinates given for cube creation; point P1 must be the lower corner" << std::endl;
					std::cerr << "The program will now exit." << std::endl;
					exit(EXIT_FAILURE);
				
				     } // end of else of if(cubeParam[0]>cubeParam[3]&&cubeParam[1]>cubeParam[4]&&cubeParam[2]>cubeParam[5])
                                 



				
			} // end of if( cubeParam ){
			
		} // end of method setCube
		
		
		/**
		 * \fn inline void setRadius( PREC * radiusParam )
		 * \brief Sets the given radius has the reference cube to the problem
		 * \param radiusParam : the radius
		*/
		inline void setRadius( PREC * radiusParam ){
			
			this->radiusSet = radiusParam != NULL;
			
			/* If the cube is not NULL */
			if( radiusParam ){
				
				/* Setting min and max using the cube */
				minCoordinates[0] = (radiusParam[0] - radiusParam[3]) / BOHRTOA;
				minCoordinates[1] = (radiusParam[1] - radiusParam[3]) / BOHRTOA;
				minCoordinates[2] = (radiusParam[2] - radiusParam[3]) / BOHRTOA;
				maxCoordinates[0] = (radiusParam[0] + radiusParam[3]) / BOHRTOA;
				maxCoordinates[1] = (radiusParam[1] + radiusParam[3]) / BOHRTOA;
				maxCoordinates[2] = (radiusParam[2] + radiusParam[3]) / BOHRTOA;
				
			}
			
		} // end of method setRadius
		
		/**
		 * \fn inline int getNbAtom()
		 * \brief Gets the number of atom
		 * \return the number of atom
		*/
		inline int getNbAtom(){ return nbAtom; }
		
		/**
		 * \fn inline int getNbAtomMolA()
		 * \brief Gets the number of atom in molecule A
		 * \return the number of atom in molecule A
		*/
		inline int getNbAtomMolA(){ return nbAtomMolA; }
		
		/**
		 * \fn inline int getNbAtomMolB()
		 * \brief Gets the number of atom in molecule B
		 * \return the number of atom in molecule B
		*/
		inline int getNbAtomMolB(){ return nbAtomMolB; }
		
		/**
		 * \fn inline PREC getMaxCoord(int axis)
		 * \brief Gets the max coordinate for the given axis
		 * \param axis : the given axis
		 * \return the max coordinate for the given axis
		*/
		inline PREC getMaxCoord(int axis){ return maxCoordinates[axis]; }
		
		/**
		 * \fn inline PREC getMinCoord(int axis)
		 * \brief Gets the min coordinate for the given axis
		 * \param axis : the given axis
		 * \return the min coordinate for the given axis
		*/
		inline PREC getMinCoord(int axis){ return minCoordinates[axis]; }

		/**
		 * \fn inline int getNbSteps(int axis)
		 * \brief Gets the number of steps for the given axis
		 * \param axis : the given axis
		 * \return the number of steps for the given axis
		*/
		inline int getNbSteps(int axis){ return nbSteps[axis]; }

                /**
                * \fn inline string  getGridBoxDefinition()
                * \brief Gets the way the box was deinied by user
                * \param
                * \return the grid Box definition             
               */
                inline std::string getGridBoxDefinition(){ 
                std::string response; 

                if (boxSet)         {response = " CUBE ";}
                else if (radiusSet) {response = "RADIUS";}
                else                {response = "LIGAND";}

                return response; }

	
};

#endif
