/*
Вам дан словарь, состоящий из пар слов. Каждое слово является синонимом к парному ему слову. Все слова в словаре различны. Для одного данного слова определите его синоним.

Входные данные
Программа получает на вход количество пар синонимов N. Далее следует N строк, каждая строка содержит ровно два слова-синонима. После этого следует одно слово.

Выходные данные
Программа должна вывести синоним к данному слову.

Sample Input:
3
Hello Hi
Bye Goodbye
List Array
Goodbye

Sample Output:
Bye
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n;
	string w, s, t;
	map<string, string> m;

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> w;
		cin >> s;
		m[w] = s;
	}

	cin >> t;

	for (auto p : m)
	{
		if (p.first == t)
		{
			cout << p.second;
			break;
		}

		if (p.second == t)
		{
			cout << p.first;
			break;
		}
	}

	return 0;
}