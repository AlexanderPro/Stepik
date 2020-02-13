/*
Циклически сдвиньте элементы списка вправо (A[0] переходит на место A[1], A[1] на место A[2], ..., последний элемент переходит на место A[0]).

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
5
1 2 3 4 5

Sample Output:
5 1 2 3 4
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long a, r = 0, t, prev;
	vector<long> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	prev = v[0];
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i < v.size() - 1)
		{
			t = v[i + 1];
			v[i + 1] = prev;
			prev = t;
		}
	}

	v[0] = prev;

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}