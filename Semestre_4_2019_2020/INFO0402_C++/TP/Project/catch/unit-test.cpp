#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <exception>

// #define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <vector>
using namespace std;

std::random_device rd;  // seed
std::mt19937 gen(rd()); // mersenne_twister_engine
std::uniform_int_distribution<uint32_t> Value;

using uint = uint32_t;

#define CONTAINER      vector<int>
#define VALUE_TYPE          int

uint IncrementalPushBackFill(CONTAINER &a) {
    uint size = 2 + Value(gen) & 0x00ff;
    for (uint i = 1; i <= size; ++i) a.push_back( i );
    return size;
}

SCENARIO("conteneur par défaut","[default_constructor][empty][size]") {
    GIVEN("un conteneur construit par défaut") {
        CONTAINER  a;
        THEN("il est vide") REQUIRE( a.empty() == true );
        THEN( "sa taille est 0") REQUIRE( a.size() == 0 );
    }
}

SCENARIO("conteneur constant par défaut","[default_constructor][empty][size][const]") {
    GIVEN("un conteneur constant construit par défaut") {
        CONTAINER  a;
        const CONTAINER &const_a = a;
        THEN("il est vide") REQUIRE(const_a.empty() == true);
        THEN( "sa taille est 0") REQUIRE(const_a.size() == 0);
    }
}


SCENARIO("push_back() back()","[default_constructor][empty][size][push_back][back][back_const]") {
    GIVEN("avec un container vide") {
        CONTAINER        a;
        const CONTAINER  &const_a = a;
        uint   size = Value(gen) & 0x000000ff;
        for(uint i=1;i<=size;++i) {
            a.push_back( i );
            THEN("le container n'est plus vide") REQUIRE(a.empty() == false);
            THEN("la taille augment de 1") REQUIRE(a.size() == i);
            THEN("back() retourne le même élément") REQUIRE( a.back() == i );
            THEN("back() const aussi") REQUIRE( const_a.back() == i );
        }
    }
}

SCENARIO("pop_back","[default_constructor][push_back][pop_back][back][front]") {
    CONTAINER a;
    uint size = IncrementalPushBackFill(a);
    REQUIRE(a.front() == 1);
    REQUIRE(a.back() == size);
    for (uint i = 0; i <size; ++i) {
        REQUIRE( a.front() == 1 );
        REQUIRE( a.back() == (size-i) );
        REQUIRE( a.size() == (size-i) );
        a.pop_back();
    }
    REQUIRE( a.empty() == true );
}

SCENARIO("vector(count)","[size_constructor]") {
    SECTION("count=0") {
        CONTAINER a(0);
        REQUIRE( a.size() == 0 );
    }
    SECTION("count") {
        uint        size = 1 + Value(gen) & 0x00ff;
        VALUE_TYPE  val{};
        CONTAINER   a(size);
        REQUIRE( a.size() == size );
        for (uint i = 0; i <size; ++i) {
            REQUIRE( a.back() == val );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
}

SCENARIO("vector(count,value)","[size_constructor_with_value]") {
    VALUE_TYPE     val{1};
    SECTION("count=0") {
        CONTAINER a(0,val);
        REQUIRE( a.size() == 0 );
    }
    SECTION("count!=0") {
        uint  size = 1 + Value(gen) & 0x00ff;
        CONTAINER a(size,val);
        REQUIRE( a.size() == size );
        for (uint i = 0; i <size; ++i) {
            REQUIRE( a.back() == val );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
}


SCENARIO("resize(count)","[resize(count)]") {
    CONTAINER   a;
    uint        size = IncrementalPushBackFill(a), half = size/2;
    VALUE_TYPE        val(2*size), def{};
    SECTION("resize bigger") {
        a.resize(size+half);
        REQUIRE( a.size() == size+half );
        for (uint i = 0; i <half; ++i) {
            REQUIRE( a.back() == def );
            a.pop_back();
        }
        REQUIRE( a.size() == size );
    }
    SECTION("resize smaller") {
        a.resize(half);
        REQUIRE( a.size() == half );
        for (uint i = half; i > 0; --i) {
            REQUIRE( a.back() == i );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
    a.resize(half);
    SECTION("count=0") {
        a.resize(0);
        REQUIRE(a.size() == 0);
    }
}

SCENARIO("resize(count,val)","[resize(count,val)]") {
    CONTAINER   a;
    uint        size = IncrementalPushBackFill(a), half = size/2;
    VALUE_TYPE  val(2*size), def{};
    SECTION("resize bigger with value") {
        a.resize(size+half,val);
        REQUIRE( a.size() == size+half );
        for (uint i = 0; i <half; ++i) {
            REQUIRE( a.back() == val );
            a.pop_back();
        }
        REQUIRE( a.size() == size );
    }
    SECTION("resize smaller with value") {
        a.resize(half,val);
        REQUIRE( a.size() == half );
        for (uint i = half; i > 0; --i) {
            REQUIRE( a.back() == i );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
    a.resize(half);
    SECTION("count=0") {
        a.resize(0,val);
        REQUIRE(a.size() == 0);
    }
}

SCENARIO("clear()","[clear]") {
    CONTAINER a;
    uint size = IncrementalPushBackFill(a);
    a.clear();
    REQUIRE(a.size() == 0);
}


SCENARIO("vector(vector&)","[copy_constructor]") {
    CONTAINER a;
    uint size = IncrementalPushBackFill(a);
    CONTAINER b(a);
    SECTION("size does not change") {
        REQUIRE( a.size() == size );
        REQUIRE( a.size() == b.size() );
    }
    SECTION("values are the same") {
        for (uint i = size; i > 0; --i) {
            REQUIRE(a.back() == b.back());
            a.pop_back();
            b.pop_back();
        }
    }
    CONTAINER c(a);
    SECTION("values have different addresses") {
        for (uint i = size; i > 0; --i) {
            REQUIRE( &(a.back()) != &(b.back()) );
            a.pop_back();
            b.pop_back();
        }
    }
}

SCENARIO("vector(vector&&)","[move_constructor]") {
    CONTAINER a;
    uint size = IncrementalPushBackFill(a);
    VALUE_TYPE *FrontPtr = &(a.front()), *BackPtr = &(a.back());
    CONTAINER b( std::move(a) );
    SECTION("size after move") {
        REQUIRE( a.size() == 0 );
        REQUIRE( b.size() == size );
    }
    SECTION("pointers is same") {
        REQUIRE( &(b.front()) == FrontPtr );
        REQUIRE( &(b.back()) == BackPtr );
    }
}


SCENARIO("operator=(vector&)","[assignation_constructor]") {
    CONTAINER a,b;
    uint size_a = IncrementalPushBackFill(a);
    uint size_b = IncrementalPushBackFill(b);
    a = b;
    SECTION("size does not change") {
        REQUIRE( a.size() == size_b );
        REQUIRE( a.size() == b.size() );
    }
    SECTION("values are the same") {
        for (uint i = size_b; i > 0; --i) {
            REQUIRE(a.back() == b.back());
            a.pop_back();
            b.pop_back();
        }
        REQUIRE( a.size() == 0 );
        REQUIRE( b.size() == 0 );
    }
    
    CONTAINER c,d;
    uint size_c = IncrementalPushBackFill(c);
    uint size_d = IncrementalPushBackFill(d);
    c = d;
    SECTION("values have different addresses") {
        for (uint i = size_d; i > 0; --i) {
            REQUIRE( &(c.back()) != &(d.back()) );
            c.pop_back();
            d.pop_back();
        }
        REQUIRE( c.size() == 0 );
        REQUIRE( d.size() == 0 );
    }
}



SCENARIO("operator=(vector&&)","[move_assignation]") {
    CONTAINER a,b;
    uint size_a = IncrementalPushBackFill(a);
    uint size_b = IncrementalPushBackFill(b);
    VALUE_TYPE *FrontPtr = &(a.front()), *BackPtr = &(a.back());
    b = std::move(a);
    SECTION("size after move") {
        REQUIRE( a.size() == 0 );
        REQUIRE( b.size() == size_a );
    }
    SECTION("pointers is same") {
        REQUIRE( &(b.front()) == FrontPtr );
        REQUIRE( &(b.back()) == BackPtr );
    }
}


SCENARIO("assign(count,val)","[assign(count,val)]") {
    SECTION("assign zero") {
        CONTAINER a;
        uint size = IncrementalPushBackFill(a), half = size/2;
        VALUE_TYPE  val(2*size);
        a.assign(0,val);
        REQUIRE( a.size() == 0 );
    }
    SECTION("assign bigger size") {
        CONTAINER a;
        uint size = IncrementalPushBackFill(a), half = size/2;
        VALUE_TYPE  val(2*size);
        
        a.assign(size+half,val);
        REQUIRE( a.size() == size+half );
        for (uint i = 0; i <size+half; ++i) {
            REQUIRE( a.back() == val );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
    SECTION("assign smaller size") {
        CONTAINER a;
        uint size = IncrementalPushBackFill(a), half = size/2;
        VALUE_TYPE  val(2*size);
        a.assign(size-half,val);
        REQUIRE( a.size() == size-half );
        for (uint i = 0; i <size-half; ++i) {
            REQUIRE( a.back() == val );
            a.pop_back();
        }
        REQUIRE( a.size() == 0 );
    }
}

int main(int argc, char **argv) {
    auto result = Catch::Session().run(argc,argv);
    return (result < 0xff ? result : 0xff);
}




