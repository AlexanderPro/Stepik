#include <iostream>
using namespace std;

char* resize(const char *str, unsigned size, unsigned new_size)
{
	char* pr = new char[new_size];
	unsigned sizer = size > new_size ? new_size : size;
	unsigned i = 0;
	for (; i < sizer; i++)
	{
		*(pr + i) = *(str + i);
	}
	delete[] str;
	return pr;
}

int main()
{
	char * s = new char[6];
	s[0] = 'H';
	s[1] = 'e';
	s[2] = 'l';
	s[3] = 'l';
	s[4] = 'o';
	s[5] = '\n';

	s = resize(s, 5, 2);

	return 0;
}