#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <HelloWorld.h>
#include <myStrlen.h>

int
main(int argc, char** argv)
{
  std::cout << "HelloWorld version " << HelloWorld_MAJOR_VERSION << "." <<  HelloWorld_MINOR_VERSION << std::endl;
  std::string message("Hello World (what a marvelous message for a perfect example :-) )");
  std::cout << message << std::endl;
  std::cout << "Size of the message = " << mystrlen(message.c_str()) << std::endl;
  return EXIT_SUCCESS;
}
