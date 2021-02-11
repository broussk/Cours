#include "StaticArray.h"


int main(){
    StaticArray<int> tab(4);

    tab[0] = 3;
    tab[1] = 8;
    tab[2] = 9;


    StaticArray<int> tab2(4);

    tab2[0] = 13;
    tab2[1] = 18;
    tab2[2] = 19;


    std::cout << "Tab 1: " << tab << "\n" << std::endl;
    std::cout << "Tab 2: " << tab2 << "\n" << std::endl;

    std::cout << "Egale: " << (tab == tab2) << std::endl;
    return 0;
}
