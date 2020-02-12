/*
Дан массив. Выведите те его элементы, которые встречаются в массиве только один раз. Элементы нужно выводить в том порядке, в котором они встречаются в списке.

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
6
1 2 2 3 3 3

Sample Output 1:
1

Sample Input 2:
8
4 3 5 2 5 1 3 5

Sample Output 2:
4 2 1
*/

#include <iostream>
#include <vector>
using namespace std;

bool contains(vector<pair<long, long>> v, long a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].first == a) return true;
	}
	return false;
}

int main()
{
	long n, a;
	vector<long> v;
	vector<pair<long, long>> pv;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (!contains(pv, v[i]))
		{
			pv.push_back(pair<long, long>(v[i], 1));
		}

		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v[i] == v[j])
			{
				for (size_t k = 0; k < pv.size(); k++)
				{
					if (pv[k].first == v[i])
					{
						pv[k].second++;
					}
				}
			}
		}
	}

	for (auto e : pv)
	{
		if (e.second == 1)
		{
			cout << e.first << " ";
		}
	}

	return 0;
}