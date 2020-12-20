#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <myStrlen.h>

int
main(int argc, char** argv)
{
  std::string message("Hello World (what a marvelous message for a perfect example :-) )");
  std::cout << message << std::endl;
  std::cout << "Size of the message = " << mystrlen(message.c_str()) << std::endl;
  return EXIT_SUCCESS;
}
