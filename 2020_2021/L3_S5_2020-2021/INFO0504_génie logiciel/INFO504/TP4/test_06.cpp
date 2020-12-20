#include <iostream>
#include <cstdlib>
#include <string.h>

int
main(int argc, char** argv)
{
  char* phrase;

  if(argc != 2)
    {
      std::cout << "Donnez moi une (et une seule) chaine de caractere s'il vous plait" << std::endl;
      return EXIT_FAILURE;
    }

  phrase=(char*)malloc( strlen(argv[1])  *sizeof(char));
  strcpy(phrase,argv[1]);
  
  std::cout << "Phrase lue :" << phrase << std::endl;
  
  free(phrase);
  
  return EXIT_SUCCESS;
}
