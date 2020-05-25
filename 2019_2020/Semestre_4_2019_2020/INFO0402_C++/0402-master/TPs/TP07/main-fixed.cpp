#include <ios>
#include "Array.h"
#include "classA.h"

const size_t   n=64;
Counters
    CountZero,
    CountCD(n,0,0,0,0,0,0),
    CountCC(n,0,0,0,n,0,0),
    CountAC(0,0,0,0,n,0,0),
    CountD(0,0,0,0,0,0,4*n);
#define Check(msg,ref) { counters_state = A::CounterDiff(counters_state,"\t" msg,&ref); }

Array::Fixed<A> RvalueArray(size_t n) {
    Array::Fixed<A> t(n);
    return t;
}

int main() {
    Counters counters_state;
    {
        // objets pour déplacement avec le reset (hors comptage)
        Array::Fixed<A>
                &&tm1 = RvalueArray(n),
                &&tm2 = RvalueArray(n);

        counters_state = A::CounterReset();

        Array::Fixed<A>  t1(n);
        Check("construction par défaut",CountCD);

        Array::Fixed<A>  t2(t1);
        Check("construction par copie",CountCC);

        Array::Fixed<A>  t3( std::move(tm1) );
        Check("construction par déplacement",CountZero);

        t1 = t2;
        Check("assignation par copie",CountAC);


        t3 = std::move(tm2);
        Check("assignation par déplacement",CountZero);

    }
    Check("destruction",CountD);

}