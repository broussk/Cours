#include <iostream>
#include "Set.h"
#include "classA.h"

bool funA(const A& a1, const A& a2) { return a1>a2; }

int main() {

    Set<int> s = Set<int>();

    std::cout << "Size :  " << s.size() << std::endl;

    if(s.empty()){
        std::cout << "Le set est vide" << std::endl;
    } else {
        std::cout << "Le set n'est pas vide" << std::endl;
    }

    s.insert(9);

    if(s.empty()){
        std::cout << "Le set est vide" << std::endl;
    } else {
        std::cout << "Le set n'est pas vide" << std::endl;
    }


//    using compA = bool (*)(const A&, const A&);
//    // constructions
//    set<A,compA>            set0a( funA );        // défaut
////    set<A,std::greater<>>   set0b;
//    set<A>   set1;                                // défaut
//    set<A>   set2( {1,2,3,4,5,6});            // ilist
//    set<A>   set3( set1.begin(), set1.end() );    // itérateur
//    set<A>   set4( set2 );                        // par copie
//    set<A>   set5( set<A>({7,8,9,10}) );            // par déplacement
//
//    // assignation
//    set1 = set5;
//    set2 = std::move(set1);
//    set0a = { 4,5,6,7 };
////    set0b = { 8,9,10,11 };
////
//    // empty/size
//    std::cout
//            << set1.empty() << ", "
//            << set1.size()  << ", "
//            << set1.count(3) << ", "
//            << set1.contains(3) << std::endl;
//
//    // clear
//    set1.clear();
//
//    // tests
//    std::cout
//            << (set4 == set5) << ", "
//            << (set4 != set5) << ", "
//            << (set4 <  set5) << ", "
//            << (set4 <= set5) << ", "
//            << (set4 >  set5) << ", "
//            << (set4 == set5) << std::endl;
//
//    // iterateur
//    for(auto it=set4.begin(); it!=set4.end(); ++it) std::cout << *it << ",";
//    std::cout << std::endl;
//
//    // iterateur constant
//    for(auto it=set4.cbegin(); it!=set4.cend(); ++it) std::cout << *it << ",";
//    std::cout << std::endl;
//
//    // méthode avec itérateurs
//    std::pair<set<A>::iterator,bool>  r1 = set1.insertNode(7);
//    std::pair<set<A>::iterator,bool>  r7 = set1.insertNode( std::move( A(7) ) );
//    set1.insertNode( set2.begin(), set2.end() );
//    set1.insertNode( {10,11,12} );
//
//
//    set<A>::iterator r2 = set1.erase( r1.first );
//    set2.erase(set2.begin(),set2.end());
//    size_t n = set3.erase(5);
//
//    set<A>::iterator r3= set3.find(4);
//    std::pair<set<A>::iterator,set<A>::iterator>  r4 = set3.equal_range(4);
//    set<A>::iterator r5 = set3.lower_bound(9);
//    set<A>::iterator r6 = set3.upper_bound(9);
//
//    // swap
//    set4.swap(set5);
//    swap(set1,set2);
//
//    // enlève des warnings
//    r6 = r5 = r4.first = r3 = r2 = r1.first = r7.first;
//    ++n;
    return 0;
}

