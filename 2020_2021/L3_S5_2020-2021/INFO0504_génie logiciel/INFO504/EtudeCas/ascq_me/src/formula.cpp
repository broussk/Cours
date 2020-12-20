/*
  Copyright USTL (Université des Sciences et Technologies de Lille, FRANCE)
  Developer(s) : 
     Jean-Charles BOISSON
     Nicolas DOLET
     Nicolas GRUSZCZYNSKA
     
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
  \file formula.cpp
  \author Nicolas GRUSZCZYNSKA and Nicolas DOLET (2005).\n Modified and updated by Jean-Charles BOISSON (2005-2008).
  \brief Implementation of the methods defined in formula.h.
  \warning Copyright USTL\n This software is governed by the CeCILL-C license under French law and 
  abiding by the rules of distribution of free software.*/

#include "formula.h"

/*!
  \fn isotop_t* copy_isotop(isotop_t* isotop,int number)
  \brief Local function that allows to gain the copy of an isotop structure.
  \param isotop The isotop structure to copy.
  \param number The number of isotops.
  \result The copy.*/
isotop_t*
copy_isotop(isotop_t* isotop,int number);

/*!
  \fn element_t* copy_one_element(element_t* element)
  \brief Local function that allows to gain the copy of an element structure.
  \param element The element structure to copy.
  \result The copy.*/
element_t*
copy_one_element(element_t* element);

/*!
  \fn void free_element(element_t* element)
  \brief Local procedure that frees the memory allocated for an element structure.
  \param element The element structure to frees.*/
void
free_element(element_t* element);

/*!
  \fn void add_element(formula_t *f,composition_t *comp)
  \brief Procedure which adds an element in a formula.
  \param f The formula in which the elements will be added.
  \param comp the composition which the element to add.*/
void add_element(formula_t *f,composition_t *comp);

/*!
  \fn int closest_int(double mass)
  \brief Local tool function which returns the most close int of a double <=> rint function used because rint does not seem work on windows
  \param mass a double.
  \result the closest int.*/
int
closest_int(double mass)
{
  int up,down;
  down=(int)mass;
  up=down+1;

  if((mass-(double)down)<((double)up-mass))
    {
      return down;
    }
  return up;
}

/*!
  \fn int affect_atom(char *symbol,int quantity,int isotop,composition_t *comp,element_t *elem_table,int elem_table_size)
  \brief Local function that affects the quantity of atoms in a composition_t structure.
  \param symbol The atom symbol.
  \param quantity The atom quantity.
  \param isotop The wanted isotop : in the most case it is indicated the first isotop.
  \param comp The modified composition_t strucutre.
  \param elem_table The element table.
  \param elem_table_size The number of elements in the table.
  \result TRUE or FALSE the affectation has been realised.*/
int
affect_atom(char *symbol,int quantity,int isotop,composition_t *comp,element_t *elem_table,int elem_table_size)
{
  int i,wanted_isotop,mass_number;

  mass_number=0;
  /* Affect the quantity */
  comp->quantity = quantity;          
  
  /* and search the good element_t : */
  i=0;
  while((i<elem_table_size)&&(strcmp(symbol,elem_table[i].symbol)!=0)) 
    {
      i++;
    }
  if(i<elem_table_size)
    {
      comp->element=copy_one_element(&(elem_table[i]));
      if(isotop>0)
	{
	  i=0;
	  if(i<comp->element->nb_isotops)
	    {
	      mass_number=closest_int(comp->element->isotops[i].relative_mass);
	    }
	  while((i<comp->element->nb_isotops)&&(isotop!=mass_number))
	    {
	      i++;
	      if(i<comp->element->nb_isotops)
		{
		  mass_number=closest_int(comp->element->isotops[i].relative_mass);
		}
	      mass_number=closest_int(comp->element->isotops[i].relative_mass);
	      
	    }
	  if(i==comp->element->nb_isotops)
	    {
	      error(USAGE_ERROR,"PROBLEMS WITH THE WANTED ISOTOP OF A ELEMENT",
		    "THE ISOTOP DOES NOT CORRESPOND TO THE ELEMENT IN AFFECT_ATOM IN FORMULA.CPP");
	    }
	  else
	    {
	      wanted_isotop=i;
	      for(i=0;i<wanted_isotop;i++)
		{
		  comp->element->isotops[i].relative_mass=comp->element->isotops[i+1].relative_mass;
		  comp->element->isotops[i].isotopic_composition=comp->element->isotops[i+1].isotopic_composition;
		  comp->element->nb_isotops--;
		}
	      comp->element->isotops=(isotop_t*)realloc(comp->element->isotops,comp->element->nb_isotops*sizeof(isotop_t));
	      if(comp->element->isotops==NULL)
		{
		  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED",
			"COMP->ELEMENT->ISOTOPS IS NULL IN AFFECT_ATOM IN FORMULA.CPP");
		}
	    }
	}
      return TRUE;
    }
  return FALSE;
}

formula_t*
read_formula(const char *c,element_t *elem_table,int elem_table_size)
{
  int current_quantity,j,i,isotop,length;
  char atom_symbol[3];
  char quantity_buffer[16];
  formula_t *form;

  /*---------------------------------------------------*/
  /*unix version */
  /* for '*' case */
  if(c[0]=='*')
    {
      return NULL;
    }
  /*----------------------------------------------------*/
  

  /* allocate formulat structure */
  form = (formula_t *) malloc(sizeof(formula_t));
  if(form==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED DURING THE READING OF A FORMULA",
	    "FORM IS NULL IN READ_FORMULA IN FORMULA.CPP");
    }
  
  /* add 1 composition (ex : H1) */
  form->nb_comp = 1;
  form->comps = (composition_t *) malloc(sizeof(composition_t));
  if(form->comps==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED DURING A FORMULA READING",
	    "FORM->COMPS IS NULL IN READ_FORMULA IN FORMULA.CPP"); 
    }
  length=strlen(c);
  i=0;/* index on c */
  while(i<length)
    {              
      /* reading symbol */
      current_quantity=1;  /* for  implicite quantity  ex:CH3*/
      atom_symbol[1] =atom_symbol[2]='\0';
      atom_symbol[0] = c[i];
      i++;
      if(i<length)
	{
	  if(c[i]>='a' && c[i]<='z')
	    {
	      atom_symbol[1] = c[i];
	      i++;
	    }
	}
      isotop=-1;
      if(i<length)
	{
	  /* reading quantity */
	  if(c[i]=='(')
	    {
	      i++;
	      j=0;
	      while((i<length)&&(isdigit(c[i])))
		{
		  quantity_buffer[j]=c[i];
		  j++;
		  i++;
		}
	      quantity_buffer[j]='\0';
	      if(quantity_buffer[0]!='\0')
		{
		  isotop=atoi(quantity_buffer);      
		}
	      if(i<length)
		{
		  if(c[i]!=')')
		    {
		      error(USAGE_ERROR,"A READ FORMULA HAS NOT THE RIGHT FORM",
			    "ISOTOP WANTED BUT THE ')' MISSES IN READ_FORMULA IN FORMULA.CPP");
		    }
		  i++;
		}
	    }
	  j=0;
	  while((i<length)&&(isdigit(c[i])))
	    {
	      quantity_buffer[j]=c[i];
	      i++;
	      j++;
	    }
	  quantity_buffer[j]='\0';
	  if(quantity_buffer[0]!='\0')
	    {
	      current_quantity=atoi(quantity_buffer);      
	    }
	  
	  
	  /* Affect the element_t in the result */
	  if(affect_atom(atom_symbol,current_quantity,isotop,&form->comps[form->nb_comp-1],elem_table,elem_table_size)==FALSE)
	    {
	      return NULL;
	    }
	  
	  if(i<length) /* Read the next element in the formula, if exists */
	    {
	      form->nb_comp++; /* allocate new composition */
	      form->comps = (composition_t *) realloc(form->comps,sizeof(composition_t)*(form->nb_comp+1));
	    }
	}
      else
	{
	  if(affect_atom(atom_symbol,current_quantity,isotop,&form->comps[form->nb_comp-1],elem_table,elem_table_size)==FALSE)
	    {
	      return NULL;
	    }
	}
    }

  return form;
}

element_t*
get_element_table(const char * filename,int *nb_elements)
{
  FILE *f;
  int index;
  char* attribute;
  char* value;
  element_t *elem_table;
  char c;
  int i,read;

  /* Allocate the table */
  elem_table = (element_t *)malloc(sizeof(element_t));
  if(elem_table==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION FAILED DURING THE READING OF THE ELEMENT FILE",
	    "ELEM_TABLE IS NULL IN GET_ELEMENT_TABLE IN FORMULA.CPP");
    }
  
  index=-1; /* index on elem_table */

  /* Open the file */
  f = fopen (filename, "r");
  if (f==NULL)
    {
      error (IO_ERROR,"ELEMENT TABLE FILE READING IMPOSSIBLE", "F IS NULL IN GET_ELEMENT_TABLE IN FORMULA.CPP");
    }
  jump_commentaries(f,'/');
  attribute=read_until(f,'=');
  read=fscanf(f,"%c",&c);
  if(read!=EOF)
    {
      if(c!='=')
	{
	  error(EXECUTION_ERROR,"THE PARSING OF THE ELEMENT TABLE FILE HAS FAILED","READING UNTIL = BUT NEXT SYMBOL IS NOT =");
	}
    }
    
  while(attribute!=NULL)
    {
      if(strncmp(attribute,"Atomic Symbol",strlen("Atomic Symbol"))==0) /* match atomic symbol */
	{
	  value=read_line(f);
	  /*****************************************************/
	  /* new portion in order to delete parasite character 
	   * for example : due to dos text format ==> ^M       
	   * allow to give the atom weight file in unix or dos format
	   * if the file is in unix format ==> this portion do nothing */
	  i=0;
	  while((i<(int)strlen(value))&&(isalpha(value[i])))
	    {
	      i++;
	    }
	  if(i!=(int)strlen(value))
	    {
	      value[i]='\0';
	    }
	  /*****************************************************/
	  
	  /* new symbol */
	  if(index==-1 || strcmp(value,elem_table[index].symbol)!=0) 
	    {		  
	      index++;
	      if(index>0) /* realloc new elem_table*/
		{
		  elem_table= (element_t *) realloc(elem_table,sizeof(element_t)*(index+2));
		  if(elem_table==NULL)
		    {
		      error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION HAS FAILED DURING THE READING",
			    "ELEM_TABLE IS NULL IN GET_ELEMENT_TABLE IN FORMULA.CPP\n");
		    }
		}
	      
	      strcpy(elem_table[index].symbol,value);
	      
	      elem_table[index].nb_isotops=0;
	      elem_table[index].isotops=(isotop_t *) malloc(sizeof(isotop_t));
	    }
	  
	  free(value);
	}
      /* match relative .. */
      else if(strncmp(attribute,"Relative Atomic Mass",strlen("Relative Atomic Mass"))==0) 
	{
	  value=read_until(f,'(');
	  jump_a_line(f);
	  elem_table[index].nb_isotops++;
	  /* realloc new isotop */ 
	  if(elem_table[index].nb_isotops>1) 
	    {
	      elem_table[index].isotops = (isotop_t *) realloc(elem_table[index].isotops,sizeof(isotop_t)*(elem_table[index].nb_isotops));		   
	    }
	  
	  if(value!=NULL)
	    {
	      /* associate value */
	      elem_table[index].isotops[elem_table[index].nb_isotops-1].relative_mass=(double) atof(value); /* for precision */
	    }
	  else
	    {
	      elem_table[index].isotops[elem_table[index].nb_isotops-1].relative_mass=0.0; 
	    }
	  /////////////////////////////////////////////////////////////////////////////////////////////////////
	  elem_table[index].isotops[elem_table[index].nb_isotops-1].isotopic_composition = 0.0; /* by default*/
	  /////////////////////////////////////////////////////////////////////////////////////////////////////
	  
	  free(value);
	}
      
      else if(strncmp(attribute,"Isotopic Composition",strlen("Isotopic Composition"))==0) /* match isotopic.. */
	{
	  value=read_line(f);
	  /* associate value */
	  if(value!=NULL)
	    {
	      elem_table[index].isotops[elem_table[index].nb_isotops-1].isotopic_composition=(double) atof(value);/* for precision */
	    }
	  free(value);
	}
      else
	{
	  jump_a_line(f);
	}
      
      free(attribute);
      jump_commentaries(f,'/');
      attribute=read_until(f,'=');
      read=fscanf(f,"%c",&c);
      if(read!=EOF)
	{
	  if(c!='=')
	    {
	      error(EXECUTION_ERROR,"THE PARSING OF THE ELEMENT TABLE FILE HAS FAILED","READING UNTIL = BUT NEXT SYMBOL IS NOT =");
	    }
	}
    }
  (*nb_elements) = index+1;

  fclose(f);
  
  return elem_table;
}

void
add_element(formula_t *f,composition_t *comp)
{
  int i;
  /* Search if the element is already in the formula */
  for(i=0;i<f->nb_comp;i++)
    {
      if(strcmp(f->comps[i].element[0].symbol,comp->element[0].symbol)==0)
	{
	  f->comps[i].quantity+=comp->quantity;
	  return;
	}
    }
  /* Else, add a new element in a new composition */
  f->nb_comp++;
  if(f->nb_comp==1)
    {
      f->comps=(composition_t *) malloc(sizeof(composition_t));
    }
  else
    {
      f->comps=(composition_t *) realloc(f->comps,sizeof(composition_t)*f->nb_comp+1);
    }
  f->comps[f->nb_comp-1].element=copy_one_element(comp->element);
  f->comps[f->nb_comp-1].quantity=comp->quantity;     
}

element_t*
get_element(char *sym,element_t *elem_table,int elem_table_size)
{
  int i;
    
  for(i=0;i<elem_table_size;i++)
    {
      if(strcmp(elem_table[i].symbol,sym)==0)
	{
	  return &(elem_table[i]);
	}
    }
  error(USAGE_ERROR,"THE WANTED ELEMENT IS NOT IN THE ELEMENT TABLE",
	"SYM DOES NOT CORRESPOND TO AN ELEMENT IN GET_ELEMENT IN FORMULA.CPP");
  return NULL;
}
      
void
add_formula(formula_t *dest,formula_t *src)
{
  int i;
  if(src==NULL)
    {
      error(USAGE_ERROR,"THE FORMULA TO ADD IS NOT INITIALIZED", "SRC IS NULL IN ADD_FORMULA IN FORMULA.CPP");
    }
  for(i=0;i<src->nb_comp;i++)
    {
      add_element(dest,&(src->comps[i]));
    }
}

int
sub_formula(formula_t *dest,formula_t *src)
{
  int i,j,trouve;
  formula_t* copy;
  //composition_t* buffer;
  if(src==NULL)
    {
      error(USAGE_ERROR,"THE FORMULA TO SUB IS NOT INITIALIZED", "SRC IS NULL IN SUB_FORMULA IN FORMULA.CPP");
    }
  copy=copy_formula(dest);
  for(i=0;i<src->nb_comp;i++)
    {
      j=0;
      trouve=FALSE;
      while((trouve==FALSE)&&(j<copy->nb_comp))
	{
	  if(strcmp(src->comps[i].element->symbol,copy->comps[j].element->symbol)==0)
	    {
	      copy->comps[j].quantity-=src->comps[i].quantity;
	      if(copy->comps[j].quantity<0)
		{
		  free_formula(copy);
		  return FALSE;
	 	}
	      else
		{
		  if(copy->comps[j].quantity==0)
		    {
		      free_element(copy->comps[j].element);
		      		      
		      while((j+1)<copy->nb_comp)
			{
			  copy->comps[j].element=copy_one_element(copy->comps[j+1].element);
			  copy->comps[j].quantity=copy->comps[j+1].quantity;

			  free_element(copy->comps[j+1].element);
			  
			  j++;
			}
		      
		      copy->nb_comp--;
		      copy->comps=(composition_t*)realloc(copy->comps,copy->nb_comp*sizeof(composition_t));
		      if(copy->comps==NULL)
			{
			  error(MEMORY_ALLOCATION_ERROR,"A MEMORY REALLOCATION FAILED DURING THE OPERATION",
				"COPY->COMPS IS NULL IN SUB_FORMULA IN FORMULA.CPP");
			}
		    }
		  trouve=TRUE;
		}
	     }
	  j++;
	}
      if(trouve==FALSE)
	{
	  free_formula(copy);
	  return FALSE;
	}
    }

  free_composition(dest->comps,dest->nb_comp);
  *dest=*copy;
  free(copy);
  // Je suis un fou !!!
  //free(copy);
  return TRUE;
}

char*
formula_tochar(formula_t *f)
{
  char *buffer;
  char buffer2[8];
  int i;
  buffer=(char *)malloc(sizeof(char)*(f->nb_comp*8));
  memset(buffer,'\0',(f->nb_comp*8));
  for(i=0;i<f->nb_comp;i++)
    {
      sprintf(buffer2,"%s%d",f->comps[i].element->symbol,f->comps[i].quantity);
      strcat(buffer,buffer2);
    }
  return buffer;
}

void
free_element(element_t* element)
{
  if(element==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE USED ELEMENT IS EMPTY",
	    "ELEMENT IS NULL IN FREE_ELEMENT IN FORMULA.CPP");
    }
  if(element->isotops==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE USED ISOTOP IS EMPTY",
	    "ELEMENT->ISOTOPS IS NULL IN FREE_ELEMENT IN FORMULA.CPP");
      exit(EXIT_FAILURE);
    }
  free(element->isotops);
  free(element);
}

void
free_composition(composition_t* composition, int number)
{
  int i;
  if(composition==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE USED COMPOSITION IS EMPTY",
	    "COMPOSITION IS NULL IN FREE_COMPOSITION IN FORMULA.CPP");
    }
  for(i=0;i<number;i++)
    {
      free_element(composition[i].element);
    }
  free(composition);
}

void
free_formula(formula_t *f)
{
  if(f==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE USED FORMULA IS EMPTY",
	    "FORMULA IS NULL IN FREE_FORMULA IN FORMULA.CPP");
    }
  free_composition(f->comps,f->nb_comp);
  free(f);
}

void
free_n_formula(formula_t* formula,int number)
{
  int i;
  if(formula==NULL)
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE FORMULA LIST IS EMPTY",
	    "FORMULA IS NULL IN FREE_N_FORMULA IN FORMULA.CPP");
    }
  for(i=0;i<number;i++)
    {
      free_composition(formula[i].comps,formula[i].nb_comp);
    }
  free(formula);
}

void
free_element_table(element_t *e,int tsize)
{
  if(e!=NULL)
    {
      while(--tsize>-1)
	{
	  free(e[tsize].isotops);    
	}
      free(e);
    }
  else
    {
      error(FREE_MEMORY_ERROR,"THE MEMORY CAN NOT BE LIBERATED BECAUSE THE USED ELEMENT IS EMPTY",
	    "THE ELEMENt TABLE IS NULL IN FREE_ELEMENT_TABLE IN FORMULA.CPP");
    }
}

double
get_weight(formula_t *f)
{
  int i;
  double weight;
  if(f==NULL)
    {
      error(USAGE_ERROR,"THE WEIGHT CAN NOT BE COMPUTED FROM A EMPTY FORMULA","FORMULA IS NULL IN GET_WEIGHT IN FORMULA.CPP");
    }
  weight=0.0;
  for(i=0;i<f->nb_comp;i++)
    {
      weight+=f->comps[i].quantity * f->comps[i].element->isotops->relative_mass;
    }
  return weight;
}

isotop_t*
copy_isotop(isotop_t* isotop,int number)
{
  isotop_t* copy;
  int i;
  if(isotop==NULL)
    {
      error(USAGE_ERROR,"THE COPIE CAN NOT BE POSSIBLE BECAUSE THE USED ISOTOP IS EMPTY",
	    "THE ORIGINAL ISOTOP IS NULL IN COPY_INE_ISOTOP IN FORMULA.CPP");
    }
  copy=(isotop_t*)malloc(number*sizeof(isotop_t));
  if(copy==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION FAILED DURING THE COPY PROCESS",
	    "COPY IS NULL IN COPY_ONE_ISOTOP IN FORMULA.CPP");
    }
  for(i=0;i<number;i++)
    {
      copy[i].relative_mass=isotop[i].relative_mass;
      copy[i].isotopic_composition=isotop[i].isotopic_composition;
    }
  return copy;
}

element_t*
copy_one_element(element_t* element)
{
  element_t* copy;
  if(element==NULL)
    {
      error(USAGE_ERROR,"THE COPIE CAN NOT BE POSSIBLE BECAUSE THE USED ELEMENT IS EMPTY",
	    "THE ORIGINAL ELEMENT IS NULL IN COPY_ONE_ELEMENT IN FORMULA.CPP");
    }
  copy=(element_t*)malloc(sizeof(element_t));
  if(copy==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION FAILED DURING THE COPY PROCESS",
	    "COPY IS NULL IN COPY_ELEMENT_ISOTOP IN FORMULA.CPP");
    }
  strcpy(copy->symbol,element->symbol);
  copy->nb_isotops=element->nb_isotops;
  copy->isotops=copy_isotop(element->isotops,element->nb_isotops);
  return copy;
}

composition_t*
copy_composition(composition_t* composition,int number)
{
  composition_t* copy;
  int i;
  if(composition==NULL)
    {
      error(USAGE_ERROR,"THE COPIE CAN NOT BE POSSIBLE BECAUSE THE USED COMPOSITION IS EMPTY",
	    "THE ORIGINAL COMPOSITION IS NULL IN COPY_COMPOSITION IN FORMULA.CPP");
    }
  copy=(composition_t*)malloc(number*sizeof(composition_t));
  if(copy==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION FAILED DURING THE COPY PROCESS",
	    "COPY IS NULL IN COPY_COMPOSITION_ISOTOP IN FORMULA.CPP");
    }
  for(i=0;i<number;i++)
    {
      copy[i].element=copy_one_element(composition[i].element);
      copy[i].quantity=composition[i].quantity;
    }
  return copy;
}

formula_t*
copy_formula(formula_t* formula)
{
  formula_t* copy;
  if(formula==NULL)
    {
      error(USAGE_ERROR,"THE COPIE CAN NOT BE POSSIBLE BECAUSE THE USED FORMULA IS EMPTY",
	    "THE ORIGINAL FORMULA IS NULL IN COPY_FORMULA IN FORMULA.CPP");
    }
  copy=(formula_t*)malloc(sizeof(formula_t));
  if(copy==NULL)
    {
      error(MEMORY_ALLOCATION_ERROR,"A MEMORY ALLOCATION HAS FAILED THE COPY PROCESS",
	    "COPY IS NULL IN COPY_FORMULA IN COPY_FORMULA");
    }
  copy->nb_comp=formula->nb_comp;
  copy->comps=copy_composition(formula->comps,formula->nb_comp);
  return copy;
}

void 
print_formula(formula_t* formula, int number)
{
  int i;
  for(i=0;i<number;i++)
    {
      if(i%5==0)
	{
	  printf("\n\t");
	}
      printf("%s  ",formula_tochar(formula+i));
    }
  printf("\n\n");
}

void 
fprint_formula(FILE* file,formula_t* formula, int number)
{
  int i;
  for(i=0;i<number;i++)
    {
      if(i%5==0)
	{
	  fprintf(file,"\n\t");
	}
      fprintf(file,"%s  ",formula_tochar(&formula[i]));
    }
  fprintf(file,"\n\n");
}

void
print_element_table(element_t* element_table, int size)
{
  int i,j;
  for(i=0;i<size;i++)
    {
      printf("Element : %s\n",element_table[i].symbol);
      printf("Number of isotops: %d\n",element_table[i].nb_isotops);
      for(j=0;j<element_table[i].nb_isotops;j++)
	{
	  printf("\t Isotop %d : relative mass = %f , isotopic composition = %f\n",
		 j+1,(float)element_table[i].isotops[j].relative_mass,(float)element_table[i].isotops[j].isotopic_composition);
	}
      printf("\n");
    }
}

void
fprint_element_table(FILE* file,element_t* element_table, int size)
{
  int i,j;
  for(i=0;i<size;i++)
    {
      fprintf(file,"Element : %s\n",element_table[i].symbol);
      fprintf(file,"Number of isotops: %d\n",element_table[i].nb_isotops);
      for(j=0;j<element_table[i].nb_isotops;j++)
	{
	  fprintf(file,"\t Isotop %d : relative mass = %.14f , isotopic composition = %.4f\n",
		 j+1,(float)element_table[i].isotops[j].relative_mass,(float)element_table[i].isotops[j].isotopic_composition);
	}
      fprintf(file,"\n");
    }
}
