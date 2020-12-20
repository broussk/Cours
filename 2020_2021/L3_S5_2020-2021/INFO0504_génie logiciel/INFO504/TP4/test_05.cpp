#include <iostream>
#include <cstdlib>

int
main(int argc, char** argv)
{
  int* value=new int[10];

  value[10]=666;

  std::cout << "Valeur interdite " << value[10] << std::endl;
  
  delete[] value;
  
  return EXIT_SUCCESS;
}
