#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
	int length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}
	return length;
}

int main()
{
	std::cout << "strlen(\"\") = " << strlen("") << std::endl;
	std::cout << "strlen(\"qwerty\") = " << strlen("qwerty") << std::endl;

	return 0;
}