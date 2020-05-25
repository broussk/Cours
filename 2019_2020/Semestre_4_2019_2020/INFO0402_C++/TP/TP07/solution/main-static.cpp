#include <ios>
#include "Array.h"
#include "classA.h"

const size_t   n=64;
Counters
    CountZero,
    CountCD(n,0,0,0,0,0,0),
    CountCC(n,0,0,0,n,0,0),
    CountCM(n,0,0,0,0,n,0),
    CountAC(0,0,0,0,n,0,0),
    CountAM(0,0,0,0,0,n,0),
    CountD(0,0,0,0,0,0,5*n);
#define Check(msg,ref) { counters_state = A::CounterDiff(counters_state,"\t" msg,&ref); }

Array::Static<A,n> RvalueArray() {
    Array::Static<A, n> t;
    return t;
}

int main() {

    Counters counters_state;
    {
        // objets pour déplacement avec le reset (hors comptage)
        Array::Static<A,n>
                &&tm1 = RvalueArray(),
                &&tm2 = RvalueArray();

        counters_state = A::CounterReset();

        Array::Static<A,n>  t1;
        Check("construction par défaut",CountCD);

        Array::Static<A,n>  t2(t1);
        Check("construction par copie",CountCC);

        Array::Static<A,n>  t3( std::move(tm1) );
        Check("construction par déplacement",CountCM);

        t1 = t2;
        Check("assignation par copie",CountAC);

        t3 = std::move(tm2);
        Check("assignation par déplacement",CountAM);
    }
    Check("destruction",CountD);

}