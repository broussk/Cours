#include <cstdio>
#include <cmath>
#include <iostream>

struct Complex {
	float r, i;
	Complex() : r(0), i(0) { printf("Cd ");  }
	Complex(float x) : r(x), i(x) { printf("Cf "); }
	Complex(float u, float v) : r(u), i(v) { printf("C2f "); }
	Complex(const Complex &z) : r(z.r), i(z.i) { printf("Cc "); }
	~Complex() { printf("D "); }
	void set(float u, float v) { r = u; i = v; }
	Complex& operator=(const Complex &z) { 
		printf("O=(%p,%p)\n", this, &z);  
		if (&z != this) set(z.r,z.i);
		return *this;
	}
	void view() { printf("%.1f+%.1fi", r, i); }
};

float Norm(Complex z) {
	return std::sqrt(z.r*z.r + z.i*z.i);
}

Complex sqr(const Complex &z) {
	return Complex(z.r*z.r - z.i*z.i, 2 * z.r*z.i);
}

Complex operator+(const Complex &a, const Complex &b) {
	return Complex(a.r + b.r, a.i + b.i);
}

Complex operator+(const Complex &a, const float b) {
	return Complex(a.r + b, a.i);
}



int main() {
	printf("Start\n");
	Complex z1, z2 = 3.f, z3(2.4f, 5.7f);
	Complex z4 = z1;
	printf("\nCode 1\n");
	float v = Norm(z3);
	printf("Norm = %f\n",v);
	z1 = z3;
	z1.view();
	z4 = z4;
	printf("\nCode 2\n");
	Complex z5 = sqr(z1);
	printf("\nCode 3\n");
	z4 = sqr(z1);
	printf("\nCode 4\n");
	Complex zz1 = sqr(3.f);
	printf("\nCode 5\n");
	Complex zz2 = sqr(Complex(3.f));
	printf("\nCode 6\n");
	Complex zz3 = zz2 + 3.f;
	printf("\nEnd\n");
}
