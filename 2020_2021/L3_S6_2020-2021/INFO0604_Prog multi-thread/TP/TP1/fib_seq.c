#include <stdlib.h>
#include <stdio.h>

unsigned int fib(int n) {
	unsigned int x, y;
	
	if (n <= 1)
		return n;
	else {
		x = fib(n - 1);
		y = fib(n - 2);
		return x + y;
	}
}

int main(int argc, char *argv[]) {
	unsigned int f;
	int n, diffTemps;
	time_t temps1, temps2;

	n = atoi(argv[1]);	
	temps1 = time(NULL);
	f = fib(n);
	temps2 = time(NULL);
	diffTemps = (int) temps2 - (int) temps1;
	printf("Valeur du %d-ieme nombre de Fibonacci : %u\n", n, f);
	printf("Temps : %d secondes\n", diffTemps);
	
	return 0;
}
