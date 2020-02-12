/*
Известно, что на доске 8×8 можно расставить 8 ферзей так, чтобы они не били друг друга. Вам дана расстановка 8 ферзей на доске, определите, есть ли среди них пара бьющих друг друга.

Формат входных данных
Программа получает на вход восемь пар чисел, каждое число от 1 до 8 - координаты 8 ферзей.

Формат выходных данных
Если ферзи не бьют друг друга, выведите слово NO, иначе выведите YES.

Sample Input 1:
1 7
2 4
3 2
4 8
5 6
6 1
7 3
8 5

Sample Output 1:
NO

Sample Input 2:
1 8
2 7
3 6
4 5
5 4
6 3
7 2
8 1

Sample Output 2:
YES
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 8, a, b;
	vector<pair<int, int>> v;

	while (n--)
	{
		cin >> a;
		cin >> b;
		v.push_back(pair<int, int>(a, b));
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (((abs(v[i].first - v[j].first) > 0 && abs(v[i].second - v[j].second) > 0 && abs(v[i].first - v[j].first) == abs(v[i].second - v[j].second)) || (v[i].first == v[j].first || v[i].second == v[j].second)))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;
}
