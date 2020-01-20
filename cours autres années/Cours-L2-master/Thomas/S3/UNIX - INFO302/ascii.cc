#include <iostream>

main(int a, char **b, char **c){

  int i=0;
//  while(c[i++])
//  {
//    std::cout << c[i] <<'\n';
//  }
   int t = atoi(b[1]);
   for(int i=33 ; i<99 ; i++){
     std::cout << i << "-" << char(i) << '\t';
     if(i%t==0){
       std::cout << '\n';
     }
   }

std::cout << "\n";


}
