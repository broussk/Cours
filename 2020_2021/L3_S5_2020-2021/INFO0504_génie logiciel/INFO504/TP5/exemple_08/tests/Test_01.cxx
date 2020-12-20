#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <myStrlen.h>

int
main(int argc, char** argv)
{
  std::string message("Hello World 14");
  if(mystrlen(message.c_str())==14)
    {
      return EXIT_SUCCESS;
    }
  
  return EXIT_FAILURE;
}
