#include <ios>
#include "Array.h"
#include "classA.h"

// bonne valeur des compteurs pour validation
const int   alloc = 64;
const int   npush = 30, npush1 = 10, npush2 = 15;
Counters
    CountZero,
    CountEmpty1(0,npush,0,0,0,npush,npush),
    CountEmpty2(0,1,0,0,npush,0,0),
    CountEmpty3(0,0,0,0,npush,304,0),
    CountEmpty4(0,0,0,0,npush,3*npush,0),
    CountEmptyD(0,0,0,0,0,0,121),
    CountSame1(0,0,npush,0,0,0,0),
    CountSame2(0,0,0,0,npush,0,0),
    CountSameD(0,0,0,0,0,0,4*npush),
    CountDiff1(0,0,npush2-npush1,0,npush1,0,0),
    CountDiff2(0,0,0,0,npush1,0,npush2-npush1),
    CountDiffD(0,0,0,0,0,0,2*npush2 + 2*npush1)
    ;

#define ObjInfo(obj) { printf("[%ld/%ld]",obj.size(),obj.allocated()); }
#define Check(obj,msg,ref) { ObjInfo(obj); counters_state = A::CounterDiff(counters_state,"\t" msg,&ref); }
#define Check2(obj1,obj2,msg,ref) { ObjInfo(obj1); ObjInfo(obj2); counters_state = A::CounterDiff(counters_state,"\t" msg,&ref); }
#define CheckRef(msg,ref) { counters_state = A::CounterDiff(counters_state,"\t" msg,&ref); }


// retourne un tableau de n éléments comme une rvalue
void PushAinArray(Array::Dynamic<A> &array, int n) {
    static A a;
    for(int i=0;i<n;++i) array.push_back(a);
}

Array::Dynamic<A> RvalueArray(int n=0) {
    if (n<0) { // n<0 = allocation seule
        Array::Dynamic<A>  t(-n);
        return t;
    } else { // n>0 = ajout d'éléments
        Array::Dynamic<A>  t(n);
        PushAinArray(t,n);
        return t;
    }
}

int main() {


    // avec un tableau dans lequel on ne met pas d'élément
    printf("\n*** test tableau vide sans élément\n");
    Counters counters_state = A::CounterGet();
    {
        Array::Dynamic<A>  t1(alloc);
        Check(t1,"construction par défaut",CountZero);

        Array::Dynamic<A>  t2(t1);
        Check(t2,"construction par copie",CountZero);

        t1 = t2;
        Check(t1,"assignation par copie",CountZero);

        Array::Dynamic<A>  t3( RvalueArray(-alloc) );
        Check(t3,"construction par déplacement",CountZero);

        t3 = std::move( RvalueArray(-alloc) );
        Check(t3,"assignation par déplacement",CountZero);
    }
    CheckRef("après destruction",CountZero);

    // effets des pushs: avec un tableau dans lequel on mets des éléments
    printf("\n*** test tableau vide avec %d élément\n",alloc);
    counters_state = A::CounterReset();
    {
        Array::Dynamic<A>  t1(alloc);
        Check(t1,"construction par défaut",CountZero);

        for(int i=0;i<npush;++i) t1.push_back(i);
        Check(t1,"ajouts d'entiers 1",CountEmpty1);

        A  a(0);
        for(int i=0;i<npush;++i) t1.push_back(a);
        Check(t1,"ajouts d'entiers 2",CountEmpty2);

        for(int i=0;i<npush;++i) t1.push_back(a);
        Check(t1,"ajouts d'entiers 3",CountEmpty3);

        t1.reserve(130);
        for(int i=0;i<npush;++i) t1.push_back(a);
        Check(t1,"ajouts d'entiers 4",CountEmpty4);
    }
    CheckRef("après destruction",CountEmptyD);

    // construction/assignation avec listes de même taille
    printf("\n*** assignation avec des listes de même taille (%d)\n",npush);
    {
        // objets pour copie et déplacement
        Array::Dynamic<A>
                t1 = RvalueArray(npush),
                &&t3m = RvalueArray(npush),
                &&t4m = RvalueArray(npush);

        counters_state = A::CounterReset();

        Array::Dynamic<A> t2(t1);
        Check2(t1,t2,"construction par copie",CountSame1);

        t1 = t2;
        Check2(t1,t2,"assignation par copie",CountSame2);

        Array::Dynamic<A> t3(std::move(t3m));
        Check(t3,"construction par déplacement",CountZero);

        t3 = std::move(t4m);
        Check(t3,"assignation par déplacement",CountZero);
    }
    CheckRef("après destruction", CountSameD);

    // construction/assignation avec listes de tailles différentes
    printf("\n*** assignation avec des listes de tailles différentes (%d>%d et %d>%d)\n",npush2,npush1,npush1,npush2);
    {
        // objets pour copie et déplacement
        Array::Dynamic<A>   t1(alloc), t2(alloc);
        PushAinArray(t1,npush1);
        PushAinArray(t2,npush2);
        Array::Dynamic<A> t3(alloc), t4(alloc);
        t3 = t1;
        t4 = t2;

        // on compte à partir de maintenant
        counters_state = A::CounterReset();

        t3 = t2;
        Check2(t3,t4,"assignation: destination plus petite",CountDiff1);

        t4 = t1;
        Check2(t3,t4,"assignation: destination plus grande",CountDiff2);
    }
    CheckRef("après destruction", CountDiffD);
}