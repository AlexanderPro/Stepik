/*
ѕо данной строке определите, €вл€етс€ ли она палиндромом (то есть, читаетс€ одинаково как слева-направо, так и справа-налево).

¬ходные данные
Ќа вход подаетс€ 1 строка без пробелов.

¬ыходные данные
Ќеобходимо вывести yes, если строка €вл€етс€ палиндромом, и no в противном случае.
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