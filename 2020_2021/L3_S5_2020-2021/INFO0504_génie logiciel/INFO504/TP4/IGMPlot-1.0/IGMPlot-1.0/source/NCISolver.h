/*
 * Copyright University of Reims Champagne-Ardenne
 * Authors: Emmanuel PLUOT, Gaetan RUBEZ, Jean-Charles-BOISSON and Eric HENON
 * Contributors: Hassan Khartabil, Corentin Lefebvre, Julia Contreras-Garcia
 *
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

#ifndef _NCI_SOLVER_H_
#define _NCI_SOLVER_H_

#include"output.h"
#include"reader.h"
#include"Node.h"
//#include"Results.h"
//#include<iostream>
//#include<iomanip>

/*#ifndef No_OpenMP
#include<omp.h>
#endif*/



#define LOG if(log)std::cout<<"[NCISOLVER::LOG]\t"
#define COUT std::cout
#define FLUSH std::flush
#define NL std::flush << std::endl
#define FOUR std::setw(4) << std::setfill(' ')
#define FIVE std::setw(5) << std::setfill(' ')
#define NINE std::setw(9) << std::setfill(' ')
#define SIX std::setw(6) << std::setfill(' ')


/**
 * \file NCISolver.h
 * \brief Class designed to manage the entire problem solving concerning the processing of molecular interactions
 * It reads the problem when created and solves it when asked for
 * /!\ No copy constructor, careful when trying to pass a Problem by value
 * \author Emmanuel
*/
class NCISolver{
	
	private : 

		/* ENTRY DATA */
		param_t params;				/* Problem's parameters 			*/
		ProgData * data;			/* Problem's data 					*/
		
		/* MAIN DATA */
		Results * results;			/* Results' values					*/
		Node * nodes[MAX_THREAD];	/* A program node used by threads	*/
		axis_t posGrid[MAX_THREAD];	/* Array with current grid position	*/
		
		/* MISCEALENOUS DATA */
		int zyAxisSize;				/* Number of row in the grid		*/
		int fullSize;				/* Number of node in the grid		*/
		int currentPercentage;		/* Current completion in %			*/
		bool log;					/* Activates logs					*/
		PREC total;					/* Total dg inter					*/
		PREC max;					/* Maximum percent value			*/
	
	public : 
	
		/**
		 * \fn inline Problem(int argc, char **argv, bool logParam = true)
		 * \brief Main constructor
		 * \param argc : arguments count
		 * \param argv : arguments values
		 * \param logParam : activation of the logs
		*/
		inline NCISolver(int argc, char **argv, bool logParam = true) : log(logParam){
				
			/* Read the file passed in argument of the function's call */
			readParam( argc, argv, &params );

			/* Read file(s) .xyz and find min and max*/
			data = readxyzMinMax( &params );
			
			/* Processing full size */
			fullSize 		= data->getNbSteps(0) * data->getNbSteps(1) * data->getNbSteps(2);
			
			/* Information box printing */
			
			/** HEAD **/
			COUT << "   ---------------------------------------------------------------------" << NL;
			COUT << "   *                                                                   *" << NL;
			COUT << "   *                        I G M    P L O T                           *" << NL;
			COUT << "   *      Detecting and plotting interactions from IGM reference       *" << NL; 
                        COUT << "   *                                                                   *" << NL;
                        COUT << "   *                        PROGRAM AUTHORS                            *" << NL;
                        COUT << "   *                   .     Pluot Emmanuel                            *" << NL;
                        COUT << "   *                   .     Rubez Gaetan                              *" << NL;
                        COUT << "   *                   .  Boisson Jean-Charles                         *" << NL;
                        COUT << "   *                   .       Henon Eric                              *" << NL;
                        COUT << "   *                                                                   *" << NL;
                        COUT << "   * ---------------  Champagne-Ardenne University  -----------------  *" << NL;
                        COUT << "   *                                                                   *" << NL;
                        COUT << "   *                          CONTRIBUTORS                             *" << NL;
                        COUT << "   *        H. Khartabil, C. Lefebvre, J. Contreras-Garcia             *" << NL;
                        COUT << "   *                                                                   *" << NL;
                        COUT << "   *                           Please cite                             *" << NL;
                        COUT << "   *           Phys Chem Chem Phys, 2017, 19(27), 17928-17936          *" << NL;
                        COUT << "   *                                                                   *" << NL;
			COUT << "   * ----------------------------------------------------------------  *" << NL; 
			COUT << "   *   Density type           : PROMOLECULAR                           *" << NL;
			/** NB FILE **/
			COUT << "   *   NbFiles                : " << params.nbFiles << "                                      *" << NL;
			
			/** MOLECULE A DESCRIPTION **/
			COUT << "   *   MoleculeFile [0]       : " << params.molAFileName;
			space(21 - static_cast<int>(params.molAFileName.length()));
			COUT << "/ " << FIVE << data->getNbAtomMolA() << " atoms     *" << NL;
			
			/** MOLECULE B DESCRIPTION **/
			if(params.nbFiles == 2){
				COUT << "   *   MoleculeFile [1]       : " << params.molBFileName;
				space(21 - static_cast<int>(params.molBFileName.length()));
				COUT << "/ " << FIVE << data->getNbAtomMolB() << " atoms     *" << NL;
			}
			
			/** SEPARATOR **/
			COUT << "   *                                                                   *" << NL;
			
                        /** BOX DEFINITION **/
                        COUT << "   *   gridBox Definition     : " << data->getGridBoxDefinition() << "                                 *" << NL;
			/** MINIMUM COORDINATE VALUES **/
			COUT << "   *   gridBox MIN (bohr)     : ";
			COUT << std::setprecision(2) << std::fixed;
			COUT << "   " << NINE << data->getMinCoord(0);
			COUT << "   " << NINE << data->getMinCoord(1);
			COUT << "   " << NINE << data->getMinCoord(2);
			COUT << "   *" << NL;
			
			/** MAXIMUM COORDINATE VALUES **/
			COUT << "   *   gridBox MAX (bohr)     : ";
			COUT << "   " << NINE << data->getMaxCoord(0);
			COUT << "   " << NINE << data->getMaxCoord(1);
			COUT << "   " << NINE << data->getMaxCoord(2);
			COUT << "   *" << NL;
			
			/** INCREMENTS **/
			COUT << "   *   Increments  (bohr)     : ";
			COUT << "   " << NINE << params.increments[0];
			COUT << "   " << NINE << params.increments[1];
			COUT << "   " << NINE << params.increments[2];
			COUT << "   *" << NL;
			
			/** NB STEPS **/
			COUT << "   *   NbSteps                : ";
			COUT << "   " << NINE << data->getNbSteps(0);
			COUT << "   " << NINE << data->getNbSteps(1);
			COUT << "   " << NINE << data->getNbSteps(2);
			COUT << "   *" << NL;

			/** SEPARATOR **/
			COUT << "   *                                                                   *" << NL;
			
			/** INTERMOLECULAR **/
			COUT << std::setprecision(2) << std::fixed;
			COUT << "   *   INTERMOLECULAR  (NCI)  : " << params.intermolecular << "                                   *" << NL;
			
			/** RHO RANGE (.dat) **/
			COUT << "   *   .dat  rho range (r1)   : [ " << SIX <<  -params.cutoffs[0] << "    " << SIX << params.cutoffs[0] << " ] ->  nci+igm dat   *" << NL; 
			
			/** RDG RANGE (.dat) **/
			COUT << "   *   .dat  rdg range (r2)   : [   0.00    " << SIX << params.cutoffs[1] << " ] ->  nci     dat   *" << NL; 
			
			/** RHO RANGE (.cube) **/
			COUT << "   *   .cube rho range (r3)   : [ " << SIX << -params.cutplot[0] << "    " << SIX << params.cutplot[0] << " ] ->  RDG     cube  *" << NL; 

                        /** RHO RANGE (.cube) **/
                        COUT << "   *   .cube rho range (r5)   : [ " << SIX << -params.cutplotIGM[0] << "    " << SIX << params.cutplotIGM[0] << " ] ->  dgIntra cube  *" << NL;


                        /** RHO RANGE (.cube) **/
                        COUT << "   *   .cube rho range (r6)   : [ " << SIX << -params.cutplotIGM[1] << "    " << SIX << params.cutplotIGM[1] << " ] ->  dgInter cube  *" << NL;

                        /** RDG isovalue (.vmd) **/
                        COUT << "   *   RDG isoval.     (r4)   : " << FOUR << params.cutplot[1] << "                 ->  vmd  RDG      *" << NL;

                        /** dg_intra isovalue (.vmd) **/
                        COUT << "   *   ED  color scale (r7)   : " << FOUR << params.vmdcolrangIGM[0] << "                 ->  vmd dgIntra   *" << NL;

                        /** dg_inter isovalue (.vmd) **/
                        COUT << "   *   ED  color scale (r8)   : " << FOUR << params.vmdcolrangIGM[1] << "                 ->  vmd dgInter   *" << NL;



  			
                        /** SEPARATOR **/
                        COUT << "   *                                                                   *" << NL;

                        /** OUTPUT OPTION **/
                        COUT << "   *   OUTPUT type            : " << params.outputType << "                                      *" << NL;

                        /** OUTPUT PREFIX **/
                        //COUT << "   *   OutPut fileName Prefix : " << params.outputName + "-";
                        //space(39 - static_cast<int>(params.outputName.length()) - 1);
                        //COUT << "*" << NL;

                        /** depending on outputtype, different files are generated : **/
                        if (params.outputType==1) {
                            COUT << "   *   File 1                 : " << params.outputName + "-nci.dat";
                            space(31 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;
                           
                            COUT << "   *   File 2                 : " << params.outputName + "-igm.dat";
                            space(31 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;
                        } 

                        if (params.outputType==2) {
                            COUT << "   *   File 1                 : " << params.outputName + "-dens.cube";
                            space(29 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;
     
                            COUT << "   *   File 2                 : " << params.outputName + "-RDG.cube";
                            space(30 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                        } 

                        if (params.outputType==3) {
                            COUT << "   *   File 1                 : " << params.outputName + "-dens.cube";
                            space(29 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 2                 : " << params.outputName + "-dgInter.cube";
                            space(26 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 3                 : " << params.outputName + "-dgIntra.cube";
                            space(26 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                        }

                        if (params.outputType==4) {
                            COUT << "   *   File 1                 : " << params.outputName + "-atContr.vmd";
                            space(27 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 2                 : " << params.outputName + "-complex.xyz";
                            space(27 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 3                 : " << params.outputName + "-percent.dat";
                            space(27 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                        }

                        if (params.outputType==5) {
                            COUT << "   *   File 1                 : " << params.outputName + "-nci.dat";
                            space(31 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 2                 : " << params.outputName + "-igm.dat";
                            space(31 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 3                 : " << params.outputName + "-dens.cube";
                            space(29 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 4                 : " << params.outputName + "-RDG.cube";
                            space(30 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 5                 : " << "nci.vmd";
                            space(32);
                            COUT << "*" << NL;

                            COUT << "   *   File 6                 : " << params.outputName + "-dgInter.cube";
                            space(26 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 7                 : " << params.outputName + "-dgIntra.cube";
                            space(26 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 8                 : " << "igm.vmd";
                            space(32);
                            COUT << "*" << NL;

                            COUT << "   *   File 9                 : " << "atContr.vmd";
                            space(28);
                            COUT << "*" << NL;

                            COUT << "   *   File 10                : " << params.outputName + "-complex.xyz";
                            space(27 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;

                            COUT << "   *   File 11                : " << params.outputName + "-percent.dat";
                            space(27 - static_cast<int>(params.outputName.length()));
                            COUT << "*" << NL;


                        }




                        /** ATOMIC CONTRIBS **/
                        //COUT << "   *   atomic contributions   : " << (params.outputType>=4?"ON ":"OFF") << " | percent.dat                      *" << NL;

  			
  			/** FOOT **/
  			COUT << "   *                                                                   *" << NL;
			COUT << "   *                                                                   *" << NL;
			COUT << "   ---------------------------------------------------------------------" << NL;
			
			/* Preparing storage for delta values */
			results 		= new Results( data->getNbAtom(), fullSize );

			/* Instanciation of the threads' nodes */
			for( int i(0) ; i < MAX_THREAD ; ++i ){
			
				nodes[i] = new Node( data->getNbAtom(), data->getNbAtomMolA(), *data );
			
			}

			
		}
		
		/**
		 * \fn inline ~Problem()
		 * \brief Destructor
		*/
		inline ~NCISolver(){
			
			/* Deleting objects */
			delete data;
			delete results;
			
			
			/* Destruction of the threads' nodes */
			for( int i(0) ; i < MAX_THREAD ; ++i ){
			
				delete nodes[i];
			
			}
				
		}
		
		/**
		 * \fn inline void solve()
		 * \brief Solves the problem
		*/
		inline void solve(){
			
			/* Processing full size (without last axis for percentage) */
			zyAxisSize = data->getNbSteps(1) * data->getNbSteps(2);
			currentPercentage = 0;
			
			
			/*  Z axis */
			int gridZAxis(0);

			#ifndef No_OpenMP
                        #pragma omp parallel for private(gridZAxis)
			#endif
			
			for ( gridZAxis=0; gridZAxis < data->getNbSteps(2); ++gridZAxis ){
			
				/* Y axis */
				int gridYAxis(0);
				for ( gridYAxis=0; gridYAxis < data->getNbSteps(1); ++gridYAxis ){
					
					
					/* Actuel process */
					lineProcessing( gridYAxis, gridZAxis, (gridYAxis*data->getNbSteps(0) + gridZAxis*data->getNbSteps(0) * data->getNbSteps(1)) );
					
					
				}
				
			}
		
                        /* A T O M  C O N T R I B U T I O N */	
			/* Results' sums' reduction */
                        /* --> the deltagInterAtom is summed over the grid and put in variable DGSIE */
			results->sum();
			
			total = 0.f;
			max = 0.f;
			
			for( int i(0) ; i < data->getNbAtom() ; ++i ){
			
				total += CAST_PREC(results->get(i, Results::DGSIE));
				if(max < CAST_PREC(results->get(i, Results::DGSIE))) max = CAST_PREC(results->get(i, Results::DGSIE));
				
			}
		
                        if (total !=0.0 ) {	
                           max = (max * 100.f)/total;
                        }
                        else { max = 0.0;}
		
			/* IF SUM WAS NULL */
			if(total < 0.001){
				COUT << "No interaction detected between fragments." << NL;
				COUT << "Possible causes : only one fragment defined, or two fragments too far" << NL;
                                COUT << "                  away from each other or bad gridBox definition." << NL;
				//if(params.outputType > 2) params.outputType = 2;
			}
			
		        // to be implemented in next future:
			//COUT << "Score : " << score() << std::endl;
			
			
		
		} // end of solve function
		
		
		/**
		 * \fn void lineProcessing(int posY, int posZ, int cubePosYZ)
		 * \brief Process all the information for an entire line of the grid
		 * \param posY : the current position in the Y axis
		 * \param posZ : the current position in the Z acis
		 * \param cubePosYZ : basic position for the index
		*/
		void lineProcessing(int posY, int posZ, int cubePosYZ){
			
			
		  /* Looping across X axis */
		  int i(0);
		  
                  #ifndef No_OpenMP
		  int index(omp_get_thread_num());
                  #else
		  int index(0);
                  #endif
			
		  for( i = 0 ; i < data->getNbSteps(0) ; ++i )
		    {
		      /* Updating axis grid positions */
		      posGrid[index].x		= CAST_PREC(i) 		* params.increments[0] + data->getMinCoord(0);
		      posGrid[index].y 	= CAST_PREC(posY) 	* params.increments[1] + data->getMinCoord(1);
		      posGrid[index].z 	= CAST_PREC(posZ) 	* params.increments[2] + data->getMinCoord(2);
		      
		      /* Processing */
		      nodes[index]->process(posGrid[index], i + cubePosYZ, *results, params);
		    } 
		}
		
		/**
		 * \fn inline void output()
		 * \brief Outputs according the output type given in the parameters
		*/
		inline void output(){
				
			switch( params.outputType ){
	
				/* OUTPUT NOTHING */
				case OUTPUT_NONE :
				
					// DOES NOTHING
				
				break;
	
				/* OUTPUT .DAT ONLY */
				case OUTPUT_DAT :
					
					/* Outputing rho and RDG's cubes as a .dat file */
					outDat(&params, data, *results);
				
				break;
				
				/* OUTPUT RHO AND RDG'S CUBES ONLY */
				case OUTPUT_RHO_RDG :
				
					/* Outputing rho's cube as a .cube file */
					outCubeRho(&params, data, results->get(TYPE_RHO));
					
					/* Outputing RDG's cube as a .cube file */
					outCubeRDG(&params, data, results->get(TYPE_RDG), results->get(TYPE_RHO), results->getShouldPrint());
					
				break;
				
				case OUTPUT_PERCENT :
				
					/* Outputing percents */
					outPercent(&params, *results,total);
					
					/* Outputing VMD script */
					outVMD(&params, data, max);
				
				break;
				
				/* OUTPUT EVERYTHING */
				case OUTPUT_ALL : 
				
					/* Outputing rho and RDG's cubes as a .dat file*/
					outDat(&params, data, *results);
					
					/* Outputing rho's cube as a .cube file */
					outCubeRho(&params, data, results->get(TYPE_RHO));
					
					/* Outputing RDG's cube as a .cube file */
					outCubeRDG(&params, data, results->get(TYPE_RDG), results->get(TYPE_RHO), results->getShouldPrint());

				
					/* Outputing all cube's types as .cube files */
					for( int i(0) ; i < SIZE_CUBE_DELTA ; ++i ){
						
						outCube( i, &params, data, results->get(TYPE_RHO), results->get(i) );
						
					}
				
					/* Outputing percents */
                                        outPercent(&params, *results,total);
				
					/* Outputing VMD script */
					outVMD(&params, data, max);

					
				break;
				
				/* OUTPUT DELTA'S CUBE ONLY */
				case OUTPUT_DELTA :
				
					/* Outputing all cube's types as .cube files */
					for( int i(0) ; i < SIZE_CUBE_DELTA ; ++i ){
						
						outCube( i, &params, data, results->get(TYPE_RHO), results->get(i) );
						
					}
					
					/* Outputing rho's cube as a .cube file */
					outCubeRho(&params, data, results->get(TYPE_RHO));
				
				break;
				
				default :
				
					LOG << " [WARNING] : Output type not understood : " << params.outputType << NL;
				
			}			
			
		}
		
		/**
		 * \fn inline void space(int nbSpace)
		 * \brief Print spaces characters
		 * \param nbSpace: thenumber of space to print
		*/
		inline void space(int nbSpace){
		
			for(int i(0); i < nbSpace ; ++i)
				COUT << " ";
			
		}
		
		
		
		/**
		 * \fn inline std::string score()
		 * \brief Return a string with the interaction's score
		 * \return the interaction's score as a string
		*/
		inline std::string score(){
		
			return "Not implemented yet";
			
		}
		
};

#endif
