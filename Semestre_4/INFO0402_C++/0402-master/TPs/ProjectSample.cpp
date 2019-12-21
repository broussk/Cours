#include <ctime>
#include <iostream>
#include <algorithm>
#include "ProjectSample.h"

int main() {
    BasicSet<int>   a;
    a.RandomFill(30);
    a.dump();
    a.view();

    // parcours de l'arbre avec un itérateur
    std::cout << "iterate: ";
    for(BasicSet<int>::iterator it=a.begin();it != a.end(); ++it) std::cout << *it << " ";
    std::cout << '\n';

    // multiplication par deux de tous les éléments avec un algorithme de la stl
    std::transform(a.begin(),a.end(),a.begin(),[](int x) { return 2*x; });

    // parcours de l'arbre avec un range-based for (idem itérateur en sous-jacent)
    std::cout << "range-for: ";
    for(auto x:a) std::cout << x << " ";
    std::cout << '\n';
}
