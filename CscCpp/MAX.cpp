#include <iostream>

#define MAX(a, b, c) { \
	int x = (a); \
	int y = (b); \
	int z = (c); \
	c = x > y ? x : y; \
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	MAX(a, b, c); // теперь c равно 20
	std::cout << "c = " << c << std::endl;
	MAX(a += b, b, c); // теперь a = c = 30
	std::cout << "a = c = " << c << std::endl;
	return 0;
}