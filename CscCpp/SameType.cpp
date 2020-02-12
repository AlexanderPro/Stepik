#include <iostream>
using namespace std;

struct Dummy { };
typedef int type;

template < typename T1, typename T2 >
struct SameType
{
	static const bool value = false;
};

template < typename T >
struct SameType<T, T>
{
	static const bool value = true;
};


int main()
{
	std::cout << SameType<int, int>::value << std::endl;
	std::cout << SameType<int, type>::value << std::endl;
	std::cout << SameType<int, int&>::value << std::endl;
	std::cout << SameType<Dummy, Dummy>::value << std::endl;
	std::cout << SameType<int, const int>::value << std::endl;
	return 0;
}