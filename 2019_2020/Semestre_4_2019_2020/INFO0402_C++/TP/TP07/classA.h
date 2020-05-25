#ifndef CLASS_A
#define CLASS_A
#include "ObjectCounters.h"

class A : public ObjectCounters<A> {
private:
    int a{};
public:
    A() { ++count.iCD; }
    A(int x) : a(x) { ++count.iCI; }
    A(const A& other) : a(other.a) { ++count.iCC; }
    A(A&& other) : a(std::move(other.a)) { ++count.iCM; }
    A& operator=(const A&other) {
        a = other.a;
        if (this != &other) ++count.iAC;
        return *this;
    }
    A& operator=(A &&other) {
        a = std::move(other.a);
        ++count.iAM;
        return *this;
    }
    ~A() { ++count.iDD; }
};

#endif // CLASS_A
