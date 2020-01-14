#include <cstdio>
#include <iostream>

int fun1a(int  x) {
	x++; 
	return x;
}

int fun1b(int &x) {
	x++;
	return x;
}

int fun1c(int &&x) { 
	x++;
	return x;
}

int fun1d(int *x) { 
	(*x)++;
	return *x;
}

int main() {
	// constante
	printf("\nfun1a(4)=%d",fun1a(4));
	//fun1a(4);
	//fun1b(4);
	printf("\nfun1c(4)=%d",fun1c(4));
	//fun1d(&4);
	
	// variable sans modificateur
	int i = 4;
	printf("\n\nfun1a(i=4)=%d (i=%d)",fun1a(i),i);
	printf("\nfun1b(i=4)=%d (i=%d)",fun1b(i),i);
	//fun1c(i);
	printf("\nfun1d(i=4)=%d (i=%d)",fun1d(&i),i);
	
	// variable non modifiée
	const int j = 4;
	printf("\n\nfun1a(j=4)=%d (j=%d)",fun1a(j),j);
	//fun1b(j);
	//fun1c(j);
	//fun1d(&j);
	
	// référence sur une lvalue
	int &k = i;
	printf("\n\nfun1a(k)=%d (k=%d)",fun1a(k),k);
	printf("\nfun1b(k)=%d (k=%d)",fun1b(k),k);
	//fun1c(k);
	printf("\nfun1d(k)=%d (k=%d)",fun1d(&k),k);
	
	// référence sur une lvalue
	const int &m = i;
	printf("\n\nfun1a(m)=%d (m=%d)",fun1a(m),m);
	//fun1b(m);
	//fun1c(m);
	//fun1d(&m);

	// référence sur une rvalue
	printf("\n\nfun1a(i+4)=%d (i=%d)",fun1a(i+4),i);
	//fun1b(i+4);
	printf("\nfun1c(i+4)=%d (i=%d)",fun1c(i+4),i);
	//fun1d(&(i+4));
}
