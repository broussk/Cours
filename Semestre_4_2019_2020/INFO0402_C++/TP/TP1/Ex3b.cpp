#include <cstdio>
#include <utility>

// int fun(int *x)             { printf("call fun(int *x)\n"); return *x; }
int fun(const int *x)       { printf("call fun(const int *x)\n"); return *x; }
// int fun(int const *x)       { printf("call fun(int const *x)\n"); return *x; }
// int fun(const int* const x) { printf("call fun(const int* const x)\n"); return *x; }

int main() {
	// pointeur
	int  				a=3;
	int*         		A = &a;
	const int*   		B = A;
	int* const  	  	C = A;
	const int* const  	D = A;

	printf("calling fun with %-11s => ","int*");
	fun(A);
	printf("calling fun with %-11s => ","const int*");
	fun(B);
	printf("calling fun with %-11s => ","int* const");
	fun(C);
	printf("calling fun with %-11s => ","const int* const");
	fun(D);
	
}
