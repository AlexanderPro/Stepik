/*
По данной строке определите, является ли она палиндромом (то есть, читается одинаково как слева-направо, так и справа-налево).

Входные данные
На вход подается 1 строка без пробелов.

Выходные данные
Необходимо вывести yes, если строка является палиндромом, и no в противном случае.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "";
	bool result = true;
	getline(cin, s);

	for (size_t i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			result = false;
			break;
		}
	}

	cout << (result ? "yes" : "no");
	return 0;
}