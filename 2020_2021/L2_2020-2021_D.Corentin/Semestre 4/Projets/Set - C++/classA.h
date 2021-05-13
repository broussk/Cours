#ifndef CLASS_A
#define CLASS_A
#include <iostream>
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
    friend bool operator>(const A& a1, const A& a2) { return (a1.a > a2.a); }
    friend bool operator<(const A& a1, const A& a2) { return (a1.a > a2.a); }
    friend std::ostream& operator<<(std::ostream& os, const A& obj) { return os << obj.a; }
};

#endif // CLASS_A
