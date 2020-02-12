#include <iostream>
using namespace std;

int main()
{
	char ch = '\0';
	bool previousCharIsWhiteSpace = false;
	while (cin.get(ch))
	{
		if (ch != ' ' || !previousCharIsWhiteSpace)
		{
			cout << ch;
		}

		previousCharIsWhiteSpace = ch == ' ';
	}

	return 0;
}