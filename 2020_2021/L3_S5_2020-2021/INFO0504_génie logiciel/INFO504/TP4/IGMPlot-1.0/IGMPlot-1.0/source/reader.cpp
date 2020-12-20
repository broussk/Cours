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
  \file reader.c
 * \brief files reading functions.
*/

#include"reader.h"
#include<cstdlib>
#include<sstream>
#include<algorithm>

using namespace std;





/**
 * \fn int conversionAtom(string tmp)
 * \brief This function is used to convert a type of atom in char into a float. Note that the float corresponds to the atomic number of the atom minus one to fit easily with the C indexes.
 * \param tmp : the atomic symbole in char*.
*/
int conversionAtom(string &tmp){
	for( int i(0) ; i < SIZE_ATOM ; ++i ){
		if ( !tmp.compare(ATOM_NAMES[i]) ) {
		    /** the program only permits the 18 atoms of periods 1,2,3 to be treated for promolecular density **/
		    if (i<=17) {return i;}
		     else {return -1;}
		}
	}
	return -1;
}

/**
 * \fn int conversionParam(string param)
 * \brief This function is used to convert a type of parameter from string to int so it may be used in a switch case.
 * \param param : the parameter as a string.
 * \return the parameter as an integer.
*/
int conversionParam(string &param){

        transform(param.begin(), param.end(), param.begin(),::toupper);
	for( int i(0) ; i < SIZE_PARAM ; ++i ){
		if ( !param.compare(PARAM_NAMES[i]) ) return i;
	}
	return -1;
}

/**
 * \fn bool isANumber(const string &s)
 * \brief This function is used to check whether a string is a number or not.
 * \param s : the string to check.
 * \return true if the string was a number, false otherwise.
*/
bool isANumber(const string &s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


/**
 * \fn void readParam(const int argc, char ** argv, param_t *params)
 * \brief Read the file param.nci
 * \param argc argument count.
 * \param argv argument vector.
 * \param params the parameters.
*/
void readParam(const int argc, char ** argv, param_t *params){

	/* Arguments not found */
	if(argc < 2){
	
                cerr << " " << endl;	
		cerr << "Bad number of arguments." << endl << "Correct use : ./main [parameters' filename].nci" << endl << "The program will now exit." << endl;
		exit(EXIT_FAILURE);
		
	}

	//cout << "argv[1] = " << argv[1] << endl;
	
	
	/* Initialization (default values) */
	params->outputName		= "out";  // default filename prefix for every result file        
	params->outputType		= 5;    // default output (can be in the range [1-5])
	params->intermolecular 	        = 1.0f; // density threshold used to detect intermolecular situation 
                                                // (x% means: only points for which one molecule brings at most x% of the total
                                                // electron density will be considered)
	params->increments[0]           = 0.1f; // in angstroms
	params->increments[1]           = 0.1f; // in angstroms
	params->increments[2]           = 0.1f; // in angstroms
	params->cutoffs[0] 		= 0.3f; // density cutoff
	params->cutoffs[1] 		= 10.0f; // rdg cutoff
	params->cutplot[0] 		= 0.3f; // density cutoff to select points written in cube file
	params->cutplot[1] 		= 0.3f; // RDG isovalue to be used in nci.vmd file
        params->cutplotIGM[0]           = 0.3f; // density threshold to decide which points will be written to dgIntra cube file
        params->cutplotIGM[1]           = 0.3f; // density threshold to decide which points will be written to dgInter cube file
        params->vmdcolrangIGM[0]        = 0.3f; // ED color range that serves to vmd session to color dg_intra isosurfaces
        params->vmdcolrangIGM[1]        = 0.08f; // ED color range that serves to vmd session to color dg_inter isosurfaces
	params->numLigand		= 0;    // default file index for ligand
        params->radiusRoundLigand       = 3.0f; // default buffer radius around ligand to define gridBox (angstroms)
	params->cubeUsed		= false; // default is to use a box around the LIGAND
        params->radiusUsed              = false; // default is to use a box around the LIGAND


	
	/* Array used to know which parameters were given */
	bool paramFound[SIZE_PARAM];
	for(int i(0) ; i < SIZE_PARAM ; ++i){
		paramFound[i] = false;
	}
	
	/* Opening stream to read the file */
	ifstream reader(argv[1]);
	
	/* If the stream couldn't be open => exit */
	if( !reader.good() ){
	        cerr <<  endl;	
		cerr << "[ERROR] Could not open file " << argv[1] << endl << "[ERROR] The program will now exit." << endl;
		exit(EXIT_FAILURE);	
		
	}

	/* Reading number of files  */
	reader >> params->nbFiles;

	/* Reading the file's names */
	reader >> params->molAFileName;
	if(params->molAFileName.substr(params->molAFileName.find_last_of(".") + 1) != "xyz"){
                cerr <<  endl;
		cerr << "[ERROR] Expected a .xyz file, found: " << params->molAFileName << "." << endl;
		cerr << "[ERROR] The program will now exit." << endl;
		exit(EXIT_FAILURE);
	}
	if( params->nbFiles == 2 ){
	
		reader >> params->molBFileName;
		if(params->molBFileName.substr(params->molBFileName.find_last_of(".") + 1) != "xyz"){
                        cerr <<  endl;
			cerr << "[ERROR] Expected a .xyz file, found: " << params->molBFileName << "." << endl;
			cerr << "[ERROR] The program will now exit." << endl;
			exit(EXIT_FAILURE);
		}
		
	}else if( params->nbFiles == 1 ){
	
		params->molBFileName = "";
			
	}else{
	        cerr <<  endl;
		cerr << "[ERROR] This program can read one or two files, you asked for " << params->nbFiles << "." << endl;
		cerr << "[ERROR] The program will now exit." << endl;
		exit(EXIT_FAILURE);
		
	}
	
	/* Reading the parameters */
	string param;
	string line;
	getline(reader, line);
	while( getline(reader, line) ){
		
		
		/* Getting parameter's type */
		stringstream args(line);

           
		args >> param;
		int found(conversionParam(param));
		
		/* Parameter is unknown */
		if(found < 0 || found > SIZE_PARAM){
		
                        cerr <<  endl;
			cerr << "[ERROR] Unknown KEYWORD: " << param << endl << "Possible KEYWORDS are : " << endl;
			for(int j(0) ; j < SIZE_PARAM ; ++j){
			
				cerr << PARAM_NAMES[j] << ", ";
			
			}
			cerr << endl << "[ERROR] The program will now exit." << endl;
			exit(EXIT_FAILURE);
			
		
		}else{
			/* Parameter was already seen */
			if(paramFound[found]){
  
	                        cerr << " " << endl;	
				cerr << "[WARNING]\tKEYWORD \"" << param << "\" followed by a blank line or " << endl;
                                cerr << "         \tfound at least twice (first value will be considered)." << endl;
		
			}else{
				paramFound[found] = true;
				switch( found ){
			
					/* Increments parameter found => reading 3 floats */
					case TYPE_INCREMENTS :
		
						for ( int i(0) ; i < 3 ; ++i ){
							
							if( (args >> ws).peek() != char_traits<char>::eof() ){
								args >> params->increments[i];
								if( params->increments[i] <= 0.f ){
									cerr << endl;
									cerr << "[ERROR] Grid increment should be positive, found:" << params->increments[i] << endl;
									cerr << "[ERROR] The program will now exit." << endl;
									exit(EXIT_FAILURE);
								}	
							}else{
								cerr << endl;	
								cerr << "[ERROR] 3 grid increments expected, found: " << line << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
								
							}
							
						} // end of for ( int i(0) ; i < 3 ; ++i 

						if( (args >> ws).peek() != char_traits<char>::eof() ){
							cerr << endl;
							cerr << "[ERROR] 3 grid increments expected, found: " << line  << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
                        for ( int i(0) ; i < 3 ; ++i ){
                        }
				
					break;
			
					/* Intermolecular parameter found => reading a single float */
					case TYPE_INTERMOLECULAR :
			
						if( (args >> ws).peek() != char_traits<char>::eof() ){
							args >> params->intermolecular;
							if( (params->intermolecular < 0.f) || (params->intermolecular > 1.0) ){
								cerr << endl;
								cerr << "[ERROR] Density fraction threshold in the range [0 - 1.0], found:" << params->intermolecular  << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							}
							if( (args >> ws).peek() != char_traits<char>::eof() ){
								cerr << endl;	
								cerr << "[ERROR] Only one value expected after keyword INTERMOLECULAR, found: " << line << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							
							}
						}else{
							cerr << endl;	
							cerr << "[ERROR] Value omitted after keyword " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
						
						}
			
					break;
	
					/* Radius parameter found => reading four floats */
					case TYPE_RADIUS :
			
						if(paramFound[TYPE_CUBE] || paramFound[TYPE_LIGAND]){
						
							cerr << endl;
							cerr << "[ERROR] Only one of the following parameters can be given at a time : CUBE, LIGAND, RADIUS." << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						for ( int i(0) ; i < 4 ; ++i ){
					
							if( (args >> ws).peek() != char_traits<char>::eof() ){
								args >> params->radius[i];
							}else{
								cerr << endl;	
								cerr << "[ERROR] 4 values expected after keyword RADIUS, found:" << line << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							
							}
							
						}
						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
							cerr << endl;	
							cerr << "[ERROR] 4 values expected after keyword RADIUS, found:" << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
                        
                                                params->radiusUsed = true;
				
			
					break;
	
					/* Ouput name parameter found => reading a string */
					case TYPE_OUTPUT_NAME :
			
						if( (args >> ws).peek() != char_traits<char>::eof() ){
						
							args >> params->outputName;
						
						}else{
					                cerr << endl;               	
							cerr << "[ERROR] ONAME value omitted, found: " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr << endl;	
							cerr << "[ERROR] Only one value expected after keyword ONAME, found: << " << line << " >>." << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
						
						}
			
					break;
	
					/* Cube parameter found => reading 6 floats */
					case TYPE_CUBE :
			
						if(paramFound[TYPE_RADIUS] || paramFound[TYPE_LIGAND]){
						
							cerr << endl;
							cerr << "[ERROR] Only one of the following parameters can be given at a time : CUBE, LIGAND, RADIUS." << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
			
						for ( int i(0) ; i < 6 ; ++i ){
							
							if( (args >> ws).peek() != char_traits<char>::eof() ){
							
								args >> params->cube[i];
							
							}else{
						                cerr << endl;	
								cerr << "[ERROR] 6 values expected after keyword CUBE, found:" << line << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							
							}
					
						}
						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr << endl;        
							cerr << "[ERROR] 6 values expected after keyword CUBE, found:" << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
				
						params->cubeUsed = true;
			
					break;
	
					/* Cutoffs parameter found => reading 2 floats */
					case TYPE_CUTOFFS :
			
						for ( int i(0) ; i < 2 ; ++i ){
							
							if( (args >> ws).peek() != char_traits<char>::eof() ){
								PREC temp(0.f);
								args >> temp;
								if(temp > 0.f){ 
									params->cutoffs[i] = temp;
								}else{
                                                                        cerr << endl;
									cerr << "[ERROR] Density/RDG CUTOFFs values must be positive, found: " << temp << endl;
									cerr << "The program will now exit." << endl;
									exit(EXIT_FAILURE);
								}
							}else{
							        cerr <<  endl;
								cerr << "[ERROR] Two CUTOFFS values are expected, found: " << line  << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							
							}
					
						} // end of for ( int i(0) ; i < 2 ; ++i )
						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr <<  endl;	
							cerr << "[ERROR] Two CUTOFFS values are expected, found: " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
			
					break;
	
					/* Cutplot parameter found => reading 2 floats */
					case TYPE_CUTPLOT :
			
						for ( int i(0) ; i < 2 ; ++i ){
					
							if( (args >> ws).peek() != char_traits<char>::eof() ){
								PREC temp(0.f);
								args >> temp;
								if(temp > 0.f){ 
									params->cutplot[i] = temp;
								}else{
                                                                        cerr <<  endl;
									cerr << "[ERROR] VMD CUTPLOT values must be positive, found: " << temp << endl;
									cerr << "The program will now exit." << endl;
									exit(EXIT_FAILURE);
								}
							}else{
							        cerr <<  endl;
								cerr << "[ERROR] Two VMD CUTPLOT values are expected, found: " << line << endl;
								cerr << "[ERROR] The program will now exit." << endl;
								exit(EXIT_FAILURE);
							
							}
					
						} // for ( int i(0) ; i < 2 ; ++i )

						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr <<  endl;	
							cerr << "[ERROR] No more than two VMD CUTPLOT values are expected, found: " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
			
					break;

                                        /* CutplotIGM parameter found => reading 2 floats */
                                        case TYPE_CUTPLOT_IGM :

                                                for ( int i(0) ; i < 2 ; ++i ){

                                                        if( (args >> ws).peek() != char_traits<char>::eof() ){
                                                                PREC temp(0.f);
                                                                args >> temp;
                                                                if(temp > 0.f){
                                                                        params->cutplotIGM[i] = temp;
                                                                }else{
                                                                        cerr <<  endl;
                                                                        cerr << "[ERROR] VMD CUTPLOT_IGM values must be positive, found: " << temp << endl;
                                                                        cerr << "The program will now exit." << endl;
                                                                        exit(EXIT_FAILURE);
                                                                }
                                                        }else{
                                                                cerr <<  endl;
                                                                cerr << "[ERROR] Two VMD CUTPLOT_IGM values are expected, found: " << line << endl;
                                                                cerr << "[ERROR] The program will now exit." << endl;
                                                                exit(EXIT_FAILURE);

                                                        }

                                                } // for ( int i(0) ; i < 2 ; ++i )


                                                if( (args >> ws).peek() != char_traits<char>::eof() ){
                                                        cerr <<  endl;
                                                        cerr << "[ERROR] No more than two VMD CUTPLOT_IGM values are expected, found: " << line << endl;
                                                        cerr << "[ERROR] The program will now exit." << endl;
                                                        exit(EXIT_FAILURE);

                                                }

                                        break;


                                        /* vmdcolrangIGM parameter found => reading 2 floats */
                                        case TYPE_VMD_COLRANG_IGM:

                                                for ( int i(0) ; i < 2 ; ++i ){

                                                        if( (args >> ws).peek() != char_traits<char>::eof() ){
                                                                PREC temp(0.f);
                                                                args >> temp;
                                                                if(temp > 0.f){
                                                                        params->vmdcolrangIGM[i] = temp;
                                                                }else{
                                                                        cerr <<  endl;
                                                                        cerr << "[ERROR] VMD_COLRANG_IGM  values must be positive, found: " << temp << endl;
                                                                        cerr << "The program will now exit." << endl;
                                                                        exit(EXIT_FAILURE);
                                                                }
                                                        }else{
                                                                cerr <<  endl;
                                                                cerr << "[ERROR] Two VMD VMD_COLRANG_IGM values are expected, found: " << line << endl;
                                                                cerr << "[ERROR] The program will now exit." << endl;
                                                                exit(EXIT_FAILURE);

                                                        }

                                                } // for ( int i(0) ; i < 2 ; ++i )


                                                if( (args >> ws).peek() != char_traits<char>::eof() ){
                                                        cerr <<  endl;
                                                        cerr << "[ERROR] No more than two VMD_COLRANG_IGM values are expected, found: " << line << endl;
                                                        cerr << "[ERROR] The program will now exit." << endl;
                                                        exit(EXIT_FAILURE);

                                                }

                                        break;



					/* Ligand parameter found => reading two floats */
					case TYPE_LIGAND :

						if(paramFound[TYPE_CUBE] || paramFound[TYPE_RADIUS]){
						
							cerr << endl;
							cerr << "[ERROR] Only one of the following parameters can be given at a time : CUBE, LIGAND, RADIUS." << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
			
						int temp;
						PREC temp2;
						if( (args >> ws).peek() != char_traits<char>::eof() ){
							args >> temp;
						}else{
					                cerr <<  endl;	
							cerr << "[ERROR] LIGAND file index and/or buffer radius around LIGAND omitted: " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						if( (args >> ws).peek() != char_traits<char>::eof() ){
							args >> temp2;
						}else{
					                cerr <<  endl;	
							cerr << "[ERROR]  2 parameters are expected for LIGAND keyword, found: " << line <<  endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr <<  endl;	
							cerr << "[ERROR] 2 parameters are expected for LIGAND keyword, found: " << line << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						if(temp == 1 || temp == 2){

                                                        // ligand file index cannot be larger than the number of files read !
                                                        if (temp > params->nbFiles) {
                                                             cerr <<  endl;
                                                             cerr << "[ERROR]  LIGAND file index cannot be greater than the number of input files, found: " << line <<  endl;
                                                             cerr << "[ERROR] The program will now exit." << endl;
                                                             exit(EXIT_FAILURE);
                                                        }
							params->numLigand = temp-1;
							if(temp2 > 0){ 
								params->radiusRoundLigand = temp2;								
							}else{
                                                                cerr <<  endl;
								cerr << "[ERROR] Buffer radius around LIGAND must be positive, found: " << temp2 << endl;
								cerr << "The program will now exit." << endl;
								exit(EXIT_FAILURE);
							}
						}else{
                                                        cerr <<  endl;
							cerr << "[ERROR] LIGAND index must be in range [1-2], found : " << temp << endl;
							cerr << "The program will now exit." << endl;
							exit(EXIT_FAILURE);
						}
				
					break;
	
					/* Output parameter found => reading a single integer */
					case TYPE_OUTPUT :
					
						if( (args >> ws).peek() != char_traits<char>::eof() ){
							args >> params->outputType;
						}else{
					                cerr <<  endl;	
							cerr << "[ERROR] OUTPUT value omitted, found: " << line  << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
						if(params->outputType < 0 || params->outputType > 5){
                                                        cerr <<  endl;
							cerr << "[ERROR] OUPUT value must be in range [0-5]:" << endl;
							cerr << "0 : no output" << endl;
							cerr << "1 : outputs .dat files  (nciplot, igmplot)" << endl;
							cerr << "2 : outputs .cube files (rho, RDG)" << endl;
							cerr << "3 : outputs .cube files (dg-inter, dg-intra)" << endl;
							cerr << "4 : outputs .dat file (to colour atoms according to their contribution to gradient drops)" << endl;
							cerr << "5 : outputs all files" << endl;
							cerr << "Value found : " << params->outputType << endl;
							cerr << "The program will now exit." << endl;
                                                        exit(EXIT_FAILURE);
						}
						
						if( (args >> ws).peek() != char_traits<char>::eof() ){
					                cerr <<  endl;	
							cerr << "[ERROR] One single value expected for OUPUT keyword, found: " << line  << endl;
							cerr << "[ERROR] The program will now exit." << endl;
							exit(EXIT_FAILURE);
							
						}
				
					break;
			
					default : 
                                                cerr <<  endl;
						cerr << "[ERROR] Unknown KEYWORD: " << param << endl;
						cerr << "The program will now exit." << endl;
						exit(EXIT_FAILURE);
			
				} // end of switch( found ){
			}  // end of else of if(paramFound[found]){
		} // end of if(found < 0 || found > SIZE_PARAM){
	} // end of while( getline(reader, line) ){
	
	/* Closing reader */
	reader.close();

} // end of readParams


/**
 * \fn ProgData* readxyzMinMax(param_t * params)
 * \brief Reads files (.xyz) and find the Min (MinX,MinY,MinZ) and the Max (MinX,MinY,MinZ)
 * \param params : the read parameters.
 * \return the data to fill.
*/
ProgData* readxyzMinMax(param_t * params){

	string atomType;
	int nbAtomsMolA, nbAtomsMolB(0);
	PREC posx, posy, posz;
	ProgData *data;

	
	/* Opening stream to read files */
	ifstream readerOne(params->molAFileName.c_str());
	ifstream readerTwo(params->molBFileName.c_str());
	
	
	
	/* Checking correct file handling */
	if( !readerOne.good() ){
                cout << endl;
		cout << "[ERROR] Could not open the file at " << params->molAFileName.c_str() << endl << "The program will now exit." << endl;
		exit(EXIT_FAILURE);
	}
	
	if( !params->molBFileName.empty() && !readerTwo.good() ){
                cout << endl;
		cout << "[ERROR] Could not open the file at " << params->molBFileName << endl << "The program will now exit." << endl;
		exit( EXIT_FAILURE );
	}
	
	
	
	/* Gathering molecules' sizes */
	readerOne >> nbAtomsMolA;
	if( !params->molBFileName.empty() ) readerTwo >> nbAtomsMolB;
	
	/* Ignoring comment line */
	readerOne.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	readerOne.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if( !params->molBFileName.empty() ){
		readerTwo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		readerTwo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	/* Instanciating and allocating program's data */

        
	data = new ProgData(nbAtomsMolA, nbAtomsMolB, params->numLigand);
	
	/* If CUBE option has been used */
	if( params->cubeUsed ){
	
		/* Setting the min/max coordinates  according to the CUBE information */
		data->setCube( params->cube );
		
	}

        /* If RADIUS option has been used */
        if( params->radiusUsed ){

                /* Setting the min/max coordinates according to the RADIUS information */
                data->setRadius( params->radius );

        }

	
	
	/* Reading first atom type */
	readerOne >> atomType;
	
	/* Parsing first file */
	while( !readerOne.eof() ){
	
		/* Reading informations about an atom */
		readerOne >> posx;
		readerOne >> posy;
		readerOne >> posz;
		
		/* Adding atom */
		data->addAtom( conversionAtom(atomType), posx, posy, posz ); 
		
		/* Trying to read next atom type */
		readerOne >> atomType;
	
	}
	
	
	/* Reading first atom type */
	readerTwo >> atomType;
	
	
	/* If there is a second file */
	if( !params->molBFileName.empty() ){
		/* Parsing second file */
		while( !readerTwo.eof() ){
	
			/* Reading informations about an atom */
			readerTwo >> posx;
			readerTwo >> posy;
			readerTwo >> posz;
		
			/* Adding atom */
			data->addAtom( conversionAtom(atomType), posx, posy, posz );
			
			/* Trying to read next atom type */
			readerTwo >> atomType;
	
		}
		
		
	}
	
	/* Closing streams */
	readerOne.close();
	readerTwo.close();

	/* Check validity of data */
	data->validate( params->increments, params->radiusRoundLigand );
	
	return data;
}




