#include <myStrlen.h>

size_t
mystrlen(const char *s)
{
  size_t size=0;
  while(s[size]!='\0')
    {
      size++;
    }
  return size;
}
