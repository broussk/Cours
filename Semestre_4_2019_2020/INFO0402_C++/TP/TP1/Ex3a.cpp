#include <cstdio>
#include <utility>
 
// int fun(int  x)             { printf("call fun(int x)\n"); return x; }
// int fun(const int  x)       { printf("call fun(const int x)\n"); return x; }

// int fun(int &x)             { printf("call fun(int &x)\n"); return x; }
int fun(const int &x)       { printf("call fun(const int &x)\n"); return x; }

// int fun(int &&x)            { printf("call fun(int &&x)\n"); return x; }
int fun(const int &&x)      { printf("call fun(const int &&x)\n"); return x; }

int main() {
	int  		a=3, &b=a;
	const int	&c=a;
	const int   &&d = std::move(a+3); // en pratique inutile si ce n'est pas avoir le bon type
	
	printf("calling fun with %-11s => ","int");
	fun(a);
	printf("calling fun with %-11s => ","const int");
	fun(3);
	printf("calling fun with %-11s => ","int&");
	fun(b);
	printf("calling fun with %-11s => ","const int&");
	fun(c);
	printf("calling fun with %-11s => ","int&&");
	fun(3+a);
	printf("calling fun with %-11s => ","const int&&");
	fun(d);
}
