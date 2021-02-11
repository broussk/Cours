#include "fct1.h"

void fct1(char txt[]){
    int i;
	for (i = 0; i < 5; i++){
	  if ((txt[i] >= 'a') && (txt[i] <= 'z')){
		txt[i] = 'a' + ((txt[i] - 'a') + 11) % 26;
	  }
	  else if ((txt[i] >= 'A') && (txt[i] <= 'Z')){
		txt[i] = 'A' + ((txt[i] - 'A') + 11) % 26;
	  }
	  else{
		txt[i] = '?';
	  }
}
}