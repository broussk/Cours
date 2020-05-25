#include <cstdio>
#include <iostream>

// Les fonctions sont écrites pour utiliser
// les spécificités du type de retour
int    		fun3a(int x)  { return x; }
int&		fun3b(int &x) { return x; }
int&&		fun3c(int x)  { return std::move(x+3); }
const int 	fun3d() 	  { return 4; }
const int&	fun3e(int &x) { return x; }
const int&& fun3f(int x)  { return std::move(x+3); }

int*			 fun3A(int *x) { return x; }
const int*  	 fun3B(int *x) { return x; }
int* const		 fun3C(int *x) { return x; }
const int* const fun3D(int *x) { return x; }

int main() {
	int  a = 1;

		const int &&b3 = fun3c(a);	
}
