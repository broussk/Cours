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
	fun1a(4);
	fun1b(4);
	fun1c(4);
	fun1d(&4);
	
	// variable sans modificateur
	int i = 4;
	fun1a(i);
	fun1b(i);
	fun1c(i);
	fun1d(&i);
	
	// variable non modifiée
	const int j = 4;
	fun1a(j);
	fun1b(j);
	fun1c(j);
	fun1d(&j);
	
	// référence sur une lvalue
	int &k = i;
	fun1a(k);
	fun1b(k);
	fun1c(k);
	fun1d(&k);
	
	// référence sur une lvalue
	const int &m = i;
	fun1a(m);
	fun1b(m);
	fun1c(m);
	fun1d(&m);

	// référence sur une rvalue
	fun1a(i+4);
	fun1b(i+4);
	fun1c(i+4);
	fun1d(&(i+4));	
}
