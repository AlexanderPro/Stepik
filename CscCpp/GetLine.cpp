#include <iostream>
using namespace std;

char* resize(const char* str, unsigned size, unsigned new_size)
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

char *getline()
{
	char ch;
	unsigned size = 0;
	unsigned new_size = 0;
	char * s = new char[size];
	while (cin.get(ch))
	{
		new_size = size + 1;
		s = resize(s, size, new_size);
		if (ch == '\n') break;
		*(s + size) = ch;
		size = new_size;
	}
	*(s + size) = '\0';
	return s;
}

int main()
{
	char* s = getline();
	cout << s << endl;
	return 0;
}