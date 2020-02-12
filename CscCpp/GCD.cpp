#include <iostream>

unsigned gcd(unsigned a, unsigned b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main()
{
	std::cout << "gcd(100, 10) = " << gcd(100, 10) << std::endl;
	std::cout << "gcd(5, 2) = " << gcd(5, 2) << std::endl;
	return 0;
}