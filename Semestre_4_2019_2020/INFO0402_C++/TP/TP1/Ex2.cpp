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
	
	{
		int b1 = fun3a(a);
		int b2 = fun3b(a);
		int b3 = fun3c(a);
		int b4 = fun3d();
		int b5 = fun3e(a);
		int b6 = fun3f(a);
	}

	{
		int &b1 = fun3a(a);
		int &b2 = fun3b(a);
		int &b3 = fun3c(a);
		int &b4 = fun3d();
		int &b5 = fun3e(a);
		int &b6 = fun3f(a);
	}

	{
		int &&b1 = fun3a(a);
		int &&b2 = fun3b(a);
		int &&b3 = fun3c(a);
		int &&b4 = fun3d();
		int &&b5 = fun3e(a);
		int &&b6 = fun3f(a);
	}

	{
		const int b1 = fun3a(a);
		const int b2 = fun3b(a);
		const int b3 = fun3c(a);
		const int b4 = fun3d();
		const int b5 = fun3e(a);
		const int b6 = fun3f(a);
	}

	{
		const int &b1 = fun3a(a);
		const int &b2 = fun3b(a);
		const int &b3 = fun3c(a);
		const int &b4 = fun3d();
		const int &b5 = fun3e(a);
		const int &b6 = fun3f(a);
	}

	{
		const int &&b1 = fun3a(a);
		const int &&b2 = fun3b(a);
		const int &&b3 = fun3c(a);
		const int &&b4 = fun3d();
		const int &&b5 = fun3e(a);
		const int &&b6 = fun3f(a);
	}
	
	{
		int *b1 = fun3A(&a);
		int *b2 = fun3B(&a);
		int *b3 = fun3C(&a);
		int *b4 = fun3D(&a);
	}

	{
		const int *b1 = fun3A(&a);
		const int *b2 = fun3B(&a);
		const int *b3 = fun3C(&a);
		const int *b4 = fun3D(&a);
	}

	{
		int const *b1 = fun3A(&a);
		int const *b2 = fun3B(&a);
		int const *b3 = fun3C(&a);
		int const *b4 = fun3D(&a);
	}

	{
		const int* const b1 = fun3A(&a);
		const int* const b2 = fun3B(&a);
		const int* const b3 = fun3C(&a);
		const int* const b4 = fun3D(&a);
	}
	
}
