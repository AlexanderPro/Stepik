#include <iostream>
using namespace std;

void _strcat(char *to, const char *from)
{
	int i, j;
	for (i = 0; to[i] != '\0'; i++);
	for (j = 0; from[j] != '\0'; j++)
		to[i + j] = from[j];
	to[i + j] = '\0';
}

int main()
{
	char s1[13] = "Hello";
	char s2[8] = " world!";
	_strcat(s1, s2);
	std::cout << s1 << std::endl;

	return 0;
}