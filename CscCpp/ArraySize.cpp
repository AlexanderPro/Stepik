#include <cstddef>
#include <iostream>
using namespace std;

template < typename T, size_t N >
size_t array_size(T(&obj)[N])
{
	return sizeof(obj) / sizeof(obj[0]);
};


int main()
{
	int ints[] = { 1, 2, 3, 4 };
	int *iptr = ints;
	double doubles[] = { 3.14 };
	size_t s1 = array_size(ints);
	size_t s2 = array_size(doubles);
	//size_t s3 = array_size(iptr);
	return 0;
}