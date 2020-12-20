#include <iostream>
#include <cstdlib>
#include <string.h>

int
main(int argc, char** argv)
{
  double* values=NULL;

  srand(time(NULL));

  for(int i=0;i<10;i++)
    {
      values=(double*)malloc(1000*sizeof(double));
      for(int j=0;j<1000;j++)
	{
	  values[j] = rand();
	}

      double mean=0;
      for(int j=0;j<1000;j++)
	{
	  mean+=values[j];
	}

      mean/=1000;

      std::cout << "mean " << i << " is " << mean << std::endl;
      
      
      free(values);
    }

  return EXIT_SUCCESS;
}
