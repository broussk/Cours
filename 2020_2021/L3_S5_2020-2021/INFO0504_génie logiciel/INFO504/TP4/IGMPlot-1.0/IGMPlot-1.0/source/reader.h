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
* \file reader.h
* \brief reader's header.
* \author Gaetan & Emmanuel 
*/

#ifndef _READER_H_
#define _READER_H_

#include<fstream>
#include"ProgData.h"
#include"Results.h"




/* The parameters' types */
typedef enum PARAM_TYPES{
	TYPE_INCREMENTS,
	TYPE_INTERMOLECULAR,
	TYPE_RADIUS,
	TYPE_OUTPUT_NAME,
	TYPE_CUBE,
	TYPE_CUTOFFS,
	TYPE_CUTPLOT,
        TYPE_CUTPLOT_IGM,
        TYPE_VMD_COLRANG_IGM,
	TYPE_LIGAND,
	TYPE_OUTPUT,
	SIZE_PARAM
}param_types_t;

/* The parameters' names */
const std::string PARAM_NAMES [] = {
	"INCREMENTS",
	"INTERMOLECULAR",
	"RADIUS",
	"ONAME",
	"CUBE",
	"CUTOFFS",
	"CUTPLOT",
        "CUTPLOT_IGM",
        "VMD_COLRANG_IGM",
	"LIGAND",
	"OUTPUT"
};

/* The atoms' types */
typedef enum ATOM_TYPES{
	HYDROGEN, HELIUM, LITHIUM, BERYLLIUM, BORON, CARBON, NITROGEN, OXYGEN, FLUORINE, NEON, SODIUM, MAGNESIUM, ALUMINIUM, SILICON, PHOSPHORUS, SULFUR, CHLORINE, ARGON, POTASSIUM, CALCIUM, SCANDIUM,
	TITANIUM, VANADIUM, CHROMIUM, MANGANESE, IRON, COBALT, NICKEL, COPPER, ZINC, GALLIUM, GERMANIUM, ARSENIC, SELENIUM, BROMINE, KRYPTON, RUBIDIUM, STRONTIUM, YTTRIUM, ZIRCONIUM, NIOBIUM, MOLYBDENUM,
	TECHNETIUM, RUTHENIUM, RHODIUM, PALLADIUM, SILVER, CADMIUM, INDIUM, TIN, ANTIMONY, TELLURIUM, IODINE, XENON, CESIUM, BARIUM, LANTHANUM, CERIUM, PRASEODYMIUM, SIZE_ATOM
}atom_types_t;

/* The atoms' names */
const std::string ATOM_NAMES [] = {
	"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc"
	"Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr"
};

bool isANumber(const std::string&);

int conversionAtom(std::string&);

int conversionParam(std::string&);

void readParam(const int, char **argv, param_t*);

ProgData* readxyzMinMax(param_t *);

#endif 
